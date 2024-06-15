//
// File: Lattice_planner.cpp
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
#include "Lattice_planner.h"
#include "rtwtypes.h"
#include <cstring>
#include <cmath>
#include <emmintrin.h>
#include "ros_code_private.h"
#include "ros_code.h"

// Forward declaration for local functions
static void ros_code_power(const real_T a_data[], const int32_T *a_size, real_T
  y_data[], int32_T *y_size, B_Lattice_planner_ros_code_T *localB);
static void ros_code_binary_expand_op_fho(real_T in1_data[], int32_T *in1_size,
  real_T in2, const real_T in3[10000], int32_T in4, int32_T in5, const real_T
  in6[5], real_T in7, int32_T in8, int32_T in9, B_Lattice_planner_ros_code_T
  *localB);
static void ros_code_wrapToPi(real_T *lambda, B_Lattice_planner_ros_code_T
  *localB);
static boolean_T ros_code_sortLE(const real_T v_data[], const int32_T v_size[2],
  int32_T idx1, int32_T idx2, B_Lattice_planner_ros_code_T *localB);
static void ros_code_sortrows(real_T y_data[], const int32_T y_size[2],
  B_Lattice_planner_ros_code_T *localB);
static void ros_code_linspace_n(real_T d2, real_T n, real_T y_data[], int32_T
  y_size[2], B_Lattice_planner_ros_code_T *localB);
static void ros_code_binary_expand_op_fhook(real_T in1_data[], int32_T in1_size
  [2], const real_T in2_data[], const int32_T in2_size[2], const real_T in3[6],
  int32_T in4, B_Lattice_planner_ros_code_T *localB);
static void ros_code_polyval(const real_T p[6], const real_T x_data[], const
  int32_T x_size[2], real_T y_data[], int32_T y_size[2],
  B_Lattice_planner_ros_code_T *localB);
static real_T ros_code_findNearestIndexInF(const real_T
  preprocess_global_path_array[10000], real_T current_s, real_T probably_index,
  real_T s_max, B_Lattice_planner_ros_code_T *localB);
static boolean_T ros_code_anyNonFinite(const real_T x_data[], const int32_T
  x_size[2]);
static real_T ros_code_rt_hypotd_snf(real_T u0, real_T u1,
  B_Lattice_planner_ros_code_T *localB);
static void ros_code_rdivide(creal_T in1_data[], int32_T *in1_size, const
  creal_T in2_data[], const int32_T *in2_size, B_Lattice_planner_ros_code_T
  *localB);
static void ros_code_xzlartg_h(const creal_T f, const creal_T g, real_T *cs,
  creal_T *sn, B_Lattice_planner_ros_code_T *localB);
static void ros_code_xzlartg(const creal_T f, const creal_T g, real_T *cs,
  creal_T *sn, creal_T *r, B_Lattice_planner_ros_code_T *localB);
static void ros_code_sqrt(creal_T *x, B_Lattice_planner_ros_code_T *localB);
static void ros_code_xzhgeqz(const creal_T A_data[], const int32_T A_size[2],
  int32_T ilo, int32_T ihi, int32_T *info, creal_T alpha1_data[], int32_T
  *alpha1_size, creal_T beta1_data[], int32_T *beta1_size,
  B_Lattice_planner_ros_code_T *localB);
static void ros_code_eigStandard(const real_T A_data[], const int32_T A_size[2],
  creal_T V_data[], int32_T *V_size, B_Lattice_planner_ros_code_T *localB);
static void ros_code_xgehrd(real_T a_data[], int32_T a_size[2],
  B_Lattice_planner_ros_code_T *localB);
static void ros_code_xdlanv2(real_T *a, real_T *b, real_T *c, real_T *d, real_T *
  rt1r, real_T *rt1i, real_T *rt2r, real_T *rt2i, real_T *cs, real_T *sn,
  B_Lattice_planner_ros_code_T *localB);
static real_T ros_code_xnrm2(int32_T n, const real_T x[3],
  B_Lattice_planner_ros_code_T *localB);
static real_T ros_code_xzlarfg(int32_T n, real_T *alpha1, real_T x[3],
  B_Lattice_planner_ros_code_T *localB);
static int32_T ros_code_xhseqr(real_T h_data[], const int32_T h_size[2],
  B_Lattice_planner_ros_code_T *localB);
static void ros_code_schur(real_T A_data[], int32_T A_size[2], real_T V_data[],
  int32_T V_size[2], B_Lattice_planner_ros_code_T *localB);
static void ros_code_eig(const real_T A_data[], const int32_T A_size[2], creal_T
  V_data[], int32_T *V_size, B_Lattice_planner_ros_code_T *localB);
static void ros_code_roots(const real_T c[3], creal_T r_data[], int32_T *r_size,
  B_Lattice_planner_ros_code_T *localB);
static void ros_code_power_i(const real_T a_data[], const int32_T a_size[2],
  real_T y_data[], int32_T y_size[2], B_Lattice_planner_ros_code_T *localB);
static void ros_code_binary_expand_op_f(real_T in1_data[], int32_T in1_size[2],
  const real_T in2[30], int32_T in3, const real_T in4_data[], const int32_T
  in4_size[2], const real_T in5_data[], const int32_T in5_size[2],
  B_Lattice_planner_ros_code_T *localB);
static void ros_cod_binary_expand_op_fhook5(real_T in1_data[], int32_T *in1_size,
  const real_T in2_data[], const int32_T *in2_size, const real_T in3[4], int32_T
  in4, B_Lattice_planner_ros_code_T *localB);
static void ros_code_polyval_d(const real_T p[4], const real_T x_data[], const
  int32_T *x_size, real_T y_data[], int32_T *y_size,
  B_Lattice_planner_ros_code_T *localB);
static void ros_code_abs(const real_T x_data[], const int32_T *x_size, real_T
  y_data[], int32_T *y_size);
static real_T ros_code_maximum(const real_T x_data[], const int32_T *x_size);
static void ros_code_minimum(const real_T x_data[], const int32_T *x_size,
  real_T *ex, int32_T *idx);
static real_T ros_code_findNearestIndexInF_k(const real_T
  preprocess_global_path_array[10000], real_T current_s, real_T probably_index,
  real_T s_min, real_T s_max, B_Lattice_planner_ros_code_T *localB);
static void ros_code_wrapToPi_o(real_T *lambda, B_Lattice_planner_ros_code_T
  *localB);
static void ros_cod_calculateVehicleCorners(real_T x, real_T y, real_T theta,
  real_T length, real_T width, real_T rotated_corners_x[4], real_T
  rotated_corners_y[4], B_Lattice_planner_ros_code_T *localB);
static real_T ros_code_detectCollision(const real_T ego_corners_x[4], const
  real_T ego_corners_y[4], const real_T object_corners_x[4], const real_T
  object_corners_y[4], real_T s_object, B_Lattice_planner_ros_code_T *localB);
static void ros_code_roots_n(const real_T c[4], creal_T r_data[], int32_T
  *r_size, B_Lattice_planner_ros_code_T *localB);
static real_T ros_code_minimum_o(const real_T x[3]);
static void ros_co_binary_expand_op_fhook5j(real_T in1_data[], int32_T *in1_size,
  const real_T in2_data[], const int32_T *in2_size, const real_T in3[5], int32_T
  in4, B_Lattice_planner_ros_code_T *localB);
static void ros_code_polyval_d0(const real_T p[5], const real_T x_data[], const
  int32_T *x_size, real_T y_data[], int32_T *y_size,
  B_Lattice_planner_ros_code_T *localB);

// Function for MATLAB Function: '<S3>/currentStateConvert'
static void ros_code_power(const real_T a_data[], const int32_T *a_size, real_T
  y_data[], int32_T *y_size, B_Lattice_planner_ros_code_T *localB)
{
  *y_size = *a_size;
  localB->k_n = 0;
  while (localB->k_n <= *a_size - 1) {
    y_data[localB->k_n] = a_data[localB->k_n] * a_data[localB->k_n];
    localB->k_n++;
  }
}

static void ros_code_binary_expand_op_fho(real_T in1_data[], int32_T *in1_size,
  real_T in2, const real_T in3[10000], int32_T in4, int32_T in5, const real_T
  in6[5], real_T in7, int32_T in8, int32_T in9, B_Lattice_planner_ros_code_T
  *localB)
{
  __m128d tmp;

  // MATLAB Function: '<S3>/currentStateConvert'
  localB->in6 = in6[0];
  localB->loop_ub_fo = in5 - in4;
  localB->in3_size = localB->loop_ub_fo + 1;
  localB->scalarLB_m = ((localB->loop_ub_fo + 1) / 2) << 1;
  localB->vectorUB_j = localB->scalarLB_m - 2;

  // MATLAB Function: '<S3>/currentStateConvert'
  for (localB->i11 = 0; localB->i11 <= localB->vectorUB_j; localB->i11 += 2) {
    tmp = _mm_loadu_pd(&in3[in4 + localB->i11]);
    _mm_storeu_pd(&localB->in3_data[localB->i11], _mm_sub_pd(tmp, _mm_set1_pd
      (localB->in6)));
  }

  for (localB->i11 = localB->scalarLB_m; localB->i11 <= localB->loop_ub_fo;
       localB->i11++) {
    localB->in3_data[localB->i11] = in3[in4 + localB->i11] - localB->in6;
  }

  ros_code_power(localB->in3_data, &localB->in3_size, localB->tmp_data_b,
                 &localB->tmp_size_a, localB);
  localB->in6 = in6[1];
  localB->loop_ub_fo = in9 - in8;
  localB->in3_size = localB->loop_ub_fo + 1;
  localB->scalarLB_m = ((localB->loop_ub_fo + 1) / 2) << 1;
  localB->vectorUB_j = localB->scalarLB_m - 2;

  // MATLAB Function: '<S3>/currentStateConvert'
  for (localB->i11 = 0; localB->i11 <= localB->vectorUB_j; localB->i11 += 2) {
    tmp = _mm_loadu_pd(&in3[(in8 + localB->i11) + 2000]);
    _mm_storeu_pd(&localB->in3_data[localB->i11], _mm_sub_pd(tmp, _mm_set1_pd
      (localB->in6)));
  }

  for (localB->i11 = localB->scalarLB_m; localB->i11 <= localB->loop_ub_fo;
       localB->i11++) {
    localB->in3_data[localB->i11] = in3[(in8 + localB->i11) + 2000] -
      localB->in6;
  }

  ros_code_power(localB->in3_data, &localB->in3_size, localB->tmp_data_p,
                 &localB->tmp_size_g, localB);
  *in1_size = localB->tmp_size_g == 1 ? localB->tmp_size_a : localB->tmp_size_g;
  localB->scalarLB_m = (localB->tmp_size_a != 1);
  localB->vectorUB_j = (localB->tmp_size_g != 1);
  localB->loop_ub_fo = localB->tmp_size_g == 1 ? localB->tmp_size_a :
    localB->tmp_size_g;
  for (localB->i11 = 0; localB->i11 < localB->loop_ub_fo; localB->i11++) {
    in1_data[localB->i11] = localB->tmp_data_b[localB->i11 * localB->scalarLB_m]
      * in2 + localB->tmp_data_p[localB->i11 * localB->vectorUB_j] * in7;
  }
}

// Function for MATLAB Function: '<S3>/currentStateConvert'
static void ros_code_wrapToPi(real_T *lambda, B_Lattice_planner_ros_code_T
  *localB)
{
  int32_T trueCount;
  boolean_T c;
  boolean_T d;
  boolean_T positiveInput_data;
  c = (*lambda < -3.1415926535897931);
  d = (*lambda > 3.1415926535897931);
  trueCount = 0;
  if (c || d) {
    trueCount = 1;
  }

  if (trueCount - 1 >= 0) {
    localB->x_data_p = *lambda + 3.1415926535897931;
  }

  if (trueCount - 1 >= 0) {
    if (std::isnan(*lambda + 3.1415926535897931)) {
      localB->varargout_1_e = (rtNaN);
    } else if (std::isinf(*lambda + 3.1415926535897931)) {
      localB->varargout_1_e = (rtNaN);
    } else if (*lambda + 3.1415926535897931 == 0.0) {
      localB->varargout_1_e = 0.0;
    } else {
      boolean_T rEQ0;
      localB->varargout_1_e = std::fmod(*lambda + 3.1415926535897931,
        6.2831853071795862);
      rEQ0 = (localB->varargout_1_e == 0.0);
      if (!rEQ0) {
        localB->q_o = std::abs((*lambda + 3.1415926535897931) /
          6.2831853071795862);
        rEQ0 = !(std::abs(localB->q_o - std::floor(localB->q_o + 0.5)) >
                 2.2204460492503131E-16 * localB->q_o);
      }

      if (rEQ0) {
        localB->varargout_1_e = 0.0;
      } else if (*lambda + 3.1415926535897931 < 0.0) {
        localB->varargout_1_e += 6.2831853071795862;
      }
    }

    localB->x_data_p = localB->varargout_1_e;
  }

  if (trueCount - 1 >= 0) {
    positiveInput_data = ((localB->x_data_p == 0.0) && (*lambda +
      3.1415926535897931 > 0.0));
  }

  if ((trueCount - 1 >= 0) && positiveInput_data) {
    localB->x_data_p = 6.2831853071795862;
  }

  if (c || d) {
    *lambda = localB->x_data_p - 3.1415926535897931;
  }
}

// Function for MATLAB Function: '<S3>/pathConvert'
static boolean_T ros_code_sortLE(const real_T v_data[], const int32_T v_size[2],
  int32_T idx1, int32_T idx2, B_Lattice_planner_ros_code_T *localB)
{
  boolean_T p;
  p = true;
  localB->v1 = v_data[(v_size[0] * 13 + idx1) - 1];
  localB->v2 = v_data[(v_size[0] * 13 + idx2) - 1];
  if ((!(localB->v1 == localB->v2)) && (!(std::isnan(localB->v1) && std::isnan
        (localB->v2))) && (!(localB->v1 <= localB->v2)) && (!std::isnan
       (localB->v2))) {
    p = false;
  }

  return p;
}

// Function for MATLAB Function: '<S3>/pathConvert'
static void ros_code_sortrows(real_T y_data[], const int32_T y_size[2],
  B_Lattice_planner_ros_code_T *localB)
{
  localB->n_i = y_size[0] + 1;
  localB->c_i_m = y_size[0];
  if (localB->c_i_m - 1 >= 0) {
    std::memset(&localB->idx_data[0], 0, localB->c_i_m * sizeof(int32_T));
  }

  if (y_size[1] == 0) {
    localB->b_n = 0;
    while (localB->b_n <= localB->n_i - 2) {
      localB->idx_data[localB->b_n] = localB->b_n + 1;
      localB->b_n++;
    }
  } else {
    localB->b_n = 1;
    while (localB->b_n <= localB->n_i - 2) {
      if (ros_code_sortLE(y_data, y_size, localB->b_n, localB->b_n + 1, localB))
      {
        localB->idx_data[localB->b_n - 1] = localB->b_n;
        localB->idx_data[localB->b_n] = localB->b_n + 1;
      } else {
        localB->idx_data[localB->b_n - 1] = localB->b_n + 1;
        localB->idx_data[localB->b_n] = localB->b_n;
      }

      localB->b_n += 2;
    }

    if ((y_size[0] & 1U) != 0U) {
      localB->idx_data[y_size[0] - 1] = y_size[0];
    }

    localB->c_i_m = 2;
    while (localB->c_i_m < localB->n_i - 1) {
      localB->i2_j = localB->c_i_m << 1;
      localB->b_j = 1;
      localB->b_n = localB->c_i_m + 1;
      while (localB->b_n < localB->n_i) {
        int32_T kEnd;
        int32_T qEnd;
        localB->p_ev = localB->b_j;
        localB->q_m = localB->b_n;
        qEnd = localB->b_j + localB->i2_j;
        if (qEnd > localB->n_i) {
          qEnd = localB->n_i;
        }

        localB->b_k = 0;
        kEnd = qEnd - localB->b_j;
        while (localB->b_k + 1 <= kEnd) {
          int32_T b_n_tmp;
          int32_T tmp;
          b_n_tmp = localB->idx_data[localB->q_m - 1];
          tmp = localB->idx_data[localB->p_ev - 1];
          if (ros_code_sortLE(y_data, y_size, tmp, b_n_tmp, localB)) {
            localB->iwork_data[localB->b_k] = tmp;
            localB->p_ev++;
            if (localB->p_ev == localB->b_n) {
              while (localB->q_m < qEnd) {
                localB->b_k++;
                localB->iwork_data[localB->b_k] = localB->idx_data[localB->q_m -
                  1];
                localB->q_m++;
              }
            }
          } else {
            localB->iwork_data[localB->b_k] = b_n_tmp;
            localB->q_m++;
            if (localB->q_m == qEnd) {
              while (localB->p_ev < localB->b_n) {
                localB->b_k++;
                localB->iwork_data[localB->b_k] = localB->idx_data[localB->p_ev
                  - 1];
                localB->p_ev++;
              }
            }
          }

          localB->b_k++;
        }

        localB->b_n = 0;
        while (localB->b_n <= kEnd - 1) {
          localB->idx_data[(localB->b_j + localB->b_n) - 1] = localB->
            iwork_data[localB->b_n];
          localB->b_n++;
        }

        localB->b_j = qEnd;
        localB->b_n = qEnd + localB->c_i_m;
      }

      localB->c_i_m = localB->i2_j;
    }
  }

  localB->n_i = y_size[0] - 1;
  localB->b_n = y_size[1];
  localB->c_i_m = 0;
  while (localB->c_i_m <= localB->b_n - 1) {
    localB->i2_j = 0;
    while (localB->i2_j <= localB->n_i) {
      localB->ycol_data[localB->i2_j] = y_data[(y_size[0] * localB->c_i_m +
        localB->idx_data[localB->i2_j]) - 1];
      localB->i2_j++;
    }

    localB->i2_j = 0;
    while (localB->i2_j <= localB->n_i) {
      y_data[localB->i2_j + y_size[0] * localB->c_i_m] = localB->
        ycol_data[localB->i2_j];
      localB->i2_j++;
    }

    localB->c_i_m++;
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_linspace_n(real_T d2, real_T n, real_T y_data[], int32_T
  y_size[2], B_Lattice_planner_ros_code_T *localB)
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
        y_data[0] = 0.1;
        if (static_cast<int32_T>(n) >= 3) {
          if ((-d2 == 0.1) && (static_cast<int32_T>(n) > 2)) {
            localB->delta1 = d2 / (static_cast<real_T>(static_cast<int32_T>(n))
              - 1.0);
            for (int32_T c_k{2}; c_k < static_cast<int32_T>(n); c_k++) {
              y_data[c_k - 1] = (static_cast<real_T>((c_k << 1) -
                static_cast<int32_T>(n)) - 1.0) * localB->delta1;
            }

            if ((static_cast<int32_T>(n) & 1) == 1) {
              y_data[static_cast<int32_T>(n) >> 1] = 0.0;
            }
          } else if ((d2 < 0.0) && (std::abs(d2) > 8.9884656743115785E+307)) {
            real_T delta2;
            localB->delta1 = 0.1 / (static_cast<real_T>(static_cast<int32_T>(n))
              - 1.0);
            delta2 = d2 / (static_cast<real_T>(static_cast<int32_T>(n)) - 1.0);
            for (int32_T c_k{0}; c_k <= static_cast<int32_T>(n) - 3; c_k++) {
              y_data[c_k + 1] = ((static_cast<real_T>(c_k) + 1.0) * delta2 + 0.1)
                - (static_cast<real_T>(c_k) + 1.0) * localB->delta1;
            }
          } else {
            localB->delta1 = (d2 - 0.1) / (static_cast<real_T>
              (static_cast<int32_T>(n)) - 1.0);
            for (int32_T c_k{0}; c_k <= static_cast<int32_T>(n) - 3; c_k++) {
              y_data[c_k + 1] = (static_cast<real_T>(c_k) + 1.0) *
                localB->delta1 + 0.1;
            }
          }
        }
      }
    }
  }
}

static void ros_code_binary_expand_op_fhook(real_T in1_data[], int32_T in1_size
  [2], const real_T in2_data[], const int32_T in2_size[2], const real_T in3[6],
  int32_T in4, B_Lattice_planner_ros_code_T *localB)
{
  localB->in3 = in3[in4 + 1];
  localB->in2_size_idx_1 = in1_size[1] == 1 ? in2_size[1] : in1_size[1];
  localB->stride_0_1 = (in2_size[1] != 1);
  localB->stride_1_1 = (in1_size[1] != 1);
  localB->loop_ub_ex = in1_size[1] == 1 ? in2_size[1] : in1_size[1];
  for (localB->i5 = 0; localB->i5 < localB->loop_ub_ex; localB->i5++) {
    localB->in2_data_m[localB->i5] = in2_data[localB->i5 * localB->stride_0_1] *
      in1_data[localB->i5 * localB->stride_1_1] + localB->in3;
  }

  in1_size[0] = 1;
  in1_size[1] = localB->in2_size_idx_1;
  if (localB->in2_size_idx_1 - 1 >= 0) {
    std::memcpy(&in1_data[0], &localB->in2_data_m[0], localB->in2_size_idx_1 *
                sizeof(real_T));
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_polyval(const real_T p[6], const real_T x_data[], const
  int32_T x_size[2], real_T y_data[], int32_T y_size[2],
  B_Lattice_planner_ros_code_T *localB)
{
  y_size[0] = 1;
  y_size[1] = x_size[1];
  if (x_size[1] != 0) {
    localB->y_idx_1 = x_size[1];
    y_size[0] = 1;
    y_size[1] = x_size[1];
    for (localB->i3 = 0; localB->i3 < localB->y_idx_1; localB->i3++) {
      y_data[localB->i3] = p[0];
    }

    for (localB->y_idx_1 = 0; localB->y_idx_1 < 5; localB->y_idx_1++) {
      if (x_size[1] == y_size[1]) {
        localB->p_m = p[localB->y_idx_1 + 1];
        localB->loop_ub_b = x_size[1] - 1;
        y_size[0] = 1;
        y_size[1] = x_size[1];
        localB->scalarLB_a = (x_size[1] / 2) << 1;
        localB->vectorUB_g = localB->scalarLB_a - 2;
        for (localB->i3 = 0; localB->i3 <= localB->vectorUB_g; localB->i3 += 2)
        {
          __m128d tmp;
          localB->i4 = localB->i3;
          tmp = _mm_loadu_pd(&y_data[localB->i4]);
          _mm_storeu_pd(&y_data[localB->i4], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(
            &x_data[localB->i4]), tmp), _mm_set1_pd(localB->p_m)));
        }

        for (localB->i3 = localB->scalarLB_a; localB->i3 <= localB->loop_ub_b;
             localB->i3++) {
          localB->vectorUB_g = localB->i3;
          y_data[localB->vectorUB_g] = x_data[localB->vectorUB_g] *
            y_data[localB->vectorUB_g] + localB->p_m;
        }
      } else {
        ros_code_binary_expand_op_fhook(y_data, y_size, x_data, x_size, p,
          localB->y_idx_1, localB);
      }
    }
  }
}

// Function for MATLAB Function: '<S3>/pathConvert'
static real_T ros_code_findNearestIndexInF(const real_T
  preprocess_global_path_array[10000], real_T current_s, real_T probably_index,
  real_T s_max, B_Lattice_planner_ros_code_T *localB)
{
  int32_T last;
  int32_T scalarLB;
  int32_T vectorUB;
  localB->min_range_h = std::fmax(probably_index + -100.0, 1.0);
  localB->max_range_l = std::fmin(std::round(s_max * 100.0) + probably_index,
    preprocess_global_path_array[1999]);
  if (localB->min_range_h > localB->max_range_l) {
    last = 0;
    localB->b_na = 0;
  } else {
    last = static_cast<int32_T>(localB->min_range_h) - 1;
    localB->b_na = static_cast<int32_T>(localB->max_range_l);
  }

  localB->b_na -= last;
  scalarLB = (localB->b_na / 2) << 1;
  vectorUB = scalarLB - 2;
  for (int32_T i{0}; i <= vectorUB; i += 2) {
    _mm_storeu_pd(&localB->distances_data_c[i], _mm_sub_pd(_mm_loadu_pd
      (&preprocess_global_path_array[(last + i) + 8000]), _mm_set1_pd(current_s)));
  }

  for (int32_T i{scalarLB}; i < localB->b_na; i++) {
    localB->distances_data_c[i] = preprocess_global_path_array[(last + i) + 8000]
      - current_s;
  }

  for (last = 0; last < localB->b_na; last++) {
    localB->y_data[last] = localB->distances_data_c[last] *
      localB->distances_data_c[last];
  }

  vectorUB = localB->b_na;
  if (localB->b_na - 1 >= 0) {
    std::memcpy(&localB->distances_data_c[0], &localB->y_data[0], localB->b_na *
                sizeof(real_T));
  }

  for (last = 0; last < localB->b_na; last++) {
    localB->distances_data_c[last] = std::sqrt(localB->distances_data_c[last]);
  }

  if (vectorUB <= 2) {
    if (vectorUB == 1) {
      localB->b_na = 1;
    } else {
      localB->max_range_l = localB->distances_data_c[vectorUB - 1];
      if (localB->distances_data_c[0] > localB->max_range_l) {
      } else if (std::isnan(localB->distances_data_c[0])) {
        if (!std::isnan(localB->max_range_l)) {
        } else {
          localB->b_na = 1;
        }
      } else {
        localB->b_na = 1;
      }
    }
  } else {
    if (!std::isnan(localB->distances_data_c[0])) {
      localB->b_na = 1;
    } else {
      boolean_T exitg1;
      localB->b_na = 0;
      scalarLB = 2;
      exitg1 = false;
      while ((!exitg1) && (scalarLB <= vectorUB)) {
        if (!std::isnan(localB->distances_data_c[scalarLB - 1])) {
          localB->b_na = scalarLB;
          exitg1 = true;
        } else {
          scalarLB++;
        }
      }
    }

    if (localB->b_na == 0) {
      localB->b_na = 1;
    } else {
      localB->max_range_l = localB->distances_data_c[localB->b_na - 1];
      for (scalarLB = localB->b_na; scalarLB < vectorUB; scalarLB++) {
        if (localB->max_range_l > localB->distances_data_c[scalarLB]) {
          localB->max_range_l = localB->distances_data_c[scalarLB];
          localB->b_na = scalarLB + 1;
        }
      }
    }
  }

  return (localB->min_range_h + static_cast<real_T>(localB->b_na)) - 1.0;
}

// Function for MATLAB Function: '<S3>/reducePath'
static boolean_T ros_code_anyNonFinite(const real_T x_data[], const int32_T
  x_size[2])
{
  int32_T nx;
  boolean_T b_p;
  nx = x_size[0] * x_size[1];
  b_p = true;
  for (int32_T k{0}; k < nx; k++) {
    if (b_p && (std::isinf(x_data[k]) || std::isnan(x_data[k]))) {
      b_p = false;
    }
  }

  return !b_p;
}

static real_T ros_code_rt_hypotd_snf(real_T u0, real_T u1,
  B_Lattice_planner_ros_code_T *localB)
{
  real_T y;
  localB->a = std::abs(u0);
  y = std::abs(u1);
  if (localB->a < y) {
    localB->a /= y;
    y *= std::sqrt(localB->a * localB->a + 1.0);
  } else if (localB->a > y) {
    y /= localB->a;
    y = std::sqrt(y * y + 1.0) * localB->a;
  } else if (!std::isnan(y)) {
    y = localB->a * 1.4142135623730951;
  }

  return y;
}

static void ros_code_rdivide(creal_T in1_data[], int32_T *in1_size, const
  creal_T in2_data[], const int32_T *in2_size, B_Lattice_planner_ros_code_T
  *localB)
{
  int32_T in1_size_idx_0;
  int32_T loop_ub;
  in1_size_idx_0 = *in2_size == 1 ? *in1_size : *in2_size;
  localB->stride_0_0 = (*in1_size != 1);
  localB->stride_1_0 = (*in2_size != 1);
  loop_ub = *in2_size == 1 ? *in1_size : *in2_size;
  for (localB->i6 = 0; localB->i6 < loop_ub; localB->i6++) {
    int32_T ar_tmp;
    ar_tmp = localB->i6 * localB->stride_0_0;
    localB->ar_c = in1_data[ar_tmp].re;
    localB->ai_p = in1_data[ar_tmp].im;
    ar_tmp = localB->i6 * localB->stride_1_0;
    localB->br = in2_data[ar_tmp].re;
    localB->bi = in2_data[ar_tmp].im;
    if (localB->bi == 0.0) {
      if (localB->ai_p == 0.0) {
        localB->in1_data[localB->i6].re = localB->ar_c / localB->br;
        localB->in1_data[localB->i6].im = 0.0;
      } else if (localB->ar_c == 0.0) {
        localB->in1_data[localB->i6].re = 0.0;
        localB->in1_data[localB->i6].im = localB->ai_p / localB->br;
      } else {
        localB->in1_data[localB->i6].re = localB->ar_c / localB->br;
        localB->in1_data[localB->i6].im = localB->ai_p / localB->br;
      }
    } else if (localB->br == 0.0) {
      if (localB->ar_c == 0.0) {
        localB->in1_data[localB->i6].re = localB->ai_p / localB->bi;
        localB->in1_data[localB->i6].im = 0.0;
      } else if (localB->ai_p == 0.0) {
        localB->in1_data[localB->i6].re = 0.0;
        localB->in1_data[localB->i6].im = -(localB->ar_c / localB->bi);
      } else {
        localB->in1_data[localB->i6].re = localB->ai_p / localB->bi;
        localB->in1_data[localB->i6].im = -(localB->ar_c / localB->bi);
      }
    } else {
      localB->brm = std::abs(localB->br);
      localB->bim = std::abs(localB->bi);
      if (localB->brm > localB->bim) {
        localB->brm = localB->bi / localB->br;
        localB->bi = localB->brm * localB->bi + localB->br;
        localB->in1_data[localB->i6].re = (localB->brm * localB->ai_p +
          localB->ar_c) / localB->bi;
        localB->in1_data[localB->i6].im = (localB->ai_p - localB->brm *
          localB->ar_c) / localB->bi;
      } else if (localB->bim == localB->brm) {
        localB->br = localB->br > 0.0 ? 0.5 : -0.5;
        localB->bi = localB->bi > 0.0 ? 0.5 : -0.5;
        localB->in1_data[localB->i6].re = (localB->ar_c * localB->br +
          localB->ai_p * localB->bi) / localB->brm;
        localB->in1_data[localB->i6].im = (localB->ai_p * localB->br -
          localB->ar_c * localB->bi) / localB->brm;
      } else {
        localB->brm = localB->br / localB->bi;
        localB->bi += localB->brm * localB->br;
        localB->in1_data[localB->i6].re = (localB->brm * localB->ar_c +
          localB->ai_p) / localB->bi;
        localB->in1_data[localB->i6].im = (localB->brm * localB->ai_p -
          localB->ar_c) / localB->bi;
      }
    }
  }

  *in1_size = in1_size_idx_0;
  if (in1_size_idx_0 - 1 >= 0) {
    std::memcpy(&in1_data[0], &localB->in1_data[0], in1_size_idx_0 * sizeof
                (creal_T));
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_xzlartg_h(const creal_T f, const creal_T g, real_T *cs,
  creal_T *sn, B_Lattice_planner_ros_code_T *localB)
{
  int32_T count;
  boolean_T guard1{ false };

  localB->d = std::abs(f.re);
  localB->scale_l = localB->d;
  localB->f2s_i = std::abs(f.im);
  if (localB->f2s_i > localB->d) {
    localB->scale_l = localB->f2s_i;
  }

  localB->gs_re_f = std::abs(g.re);
  localB->gs_im_i = std::abs(g.im);
  if (localB->gs_im_i > localB->gs_re_f) {
    localB->gs_re_f = localB->gs_im_i;
  }

  if (localB->gs_re_f > localB->scale_l) {
    localB->scale_l = localB->gs_re_f;
  }

  localB->fs_re_o = f.re;
  localB->fs_im_i = f.im;
  localB->gs_re_f = g.re;
  localB->gs_im_i = g.im;
  count = 0;
  guard1 = false;
  if (localB->scale_l >= 7.4428285367870146E+137) {
    do {
      count++;
      localB->fs_re_o *= 1.3435752215134178E-138;
      localB->fs_im_i *= 1.3435752215134178E-138;
      localB->gs_re_f *= 1.3435752215134178E-138;
      localB->gs_im_i *= 1.3435752215134178E-138;
      localB->scale_l *= 1.3435752215134178E-138;
    } while ((localB->scale_l >= 7.4428285367870146E+137) && (count < 20));

    guard1 = true;
  } else if (localB->scale_l <= 1.3435752215134178E-138) {
    if (((g.re == 0.0) && (g.im == 0.0)) || (std::isnan(g.re) || std::isnan(g.im)))
    {
      *cs = 1.0;
      sn->re = 0.0;
      sn->im = 0.0;
    } else {
      do {
        localB->fs_re_o *= 7.4428285367870146E+137;
        localB->fs_im_i *= 7.4428285367870146E+137;
        localB->gs_re_f *= 7.4428285367870146E+137;
        localB->gs_im_i *= 7.4428285367870146E+137;
        localB->scale_l *= 7.4428285367870146E+137;
      } while (localB->scale_l <= 1.3435752215134178E-138);

      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    localB->scale_l = localB->fs_re_o * localB->fs_re_o + localB->fs_im_i *
      localB->fs_im_i;
    localB->g2_a = localB->gs_re_f * localB->gs_re_f + localB->gs_im_i *
      localB->gs_im_i;
    localB->x_o = localB->g2_a;
    if (localB->g2_a < 1.0) {
      localB->x_o = 1.0;
    }

    if (localB->scale_l <= localB->x_o * 2.0041683600089728E-292) {
      if ((f.re == 0.0) && (f.im == 0.0)) {
        *cs = 0.0;
        localB->d = ros_code_rt_hypotd_snf(localB->gs_re_f, localB->gs_im_i,
          localB);
        sn->re = localB->gs_re_f / localB->d;
        sn->im = -localB->gs_im_i / localB->d;
      } else {
        localB->scale_l = std::sqrt(localB->g2_a);
        *cs = ros_code_rt_hypotd_snf(localB->fs_re_o, localB->fs_im_i, localB) /
          localB->scale_l;
        if (localB->f2s_i > localB->d) {
          localB->d = localB->f2s_i;
        }

        if (localB->d > 1.0) {
          localB->d = ros_code_rt_hypotd_snf(f.re, f.im, localB);
          localB->fs_re_o = f.re / localB->d;
          localB->fs_im_i = f.im / localB->d;
        } else {
          localB->fs_re_o = 7.4428285367870146E+137 * f.re;
          localB->f2s_i = 7.4428285367870146E+137 * f.im;
          localB->d = ros_code_rt_hypotd_snf(localB->fs_re_o, localB->f2s_i,
            localB);
          localB->fs_re_o /= localB->d;
          localB->fs_im_i = localB->f2s_i / localB->d;
        }

        localB->gs_re_f /= localB->scale_l;
        localB->gs_im_i = -localB->gs_im_i / localB->scale_l;
        sn->re = localB->fs_re_o * localB->gs_re_f - localB->fs_im_i *
          localB->gs_im_i;
        sn->im = localB->fs_re_o * localB->gs_im_i + localB->fs_im_i *
          localB->gs_re_f;
      }
    } else {
      localB->f2s_i = std::sqrt(localB->g2_a / localB->scale_l + 1.0);
      *cs = 1.0 / localB->f2s_i;
      localB->d = localB->scale_l + localB->g2_a;
      localB->fs_re_o = localB->f2s_i * localB->fs_re_o / localB->d;
      localB->fs_im_i = localB->f2s_i * localB->fs_im_i / localB->d;
      sn->re = localB->fs_re_o * localB->gs_re_f - localB->fs_im_i *
        -localB->gs_im_i;
      sn->im = localB->fs_re_o * -localB->gs_im_i + localB->fs_im_i *
        localB->gs_re_f;
    }
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_xzlartg(const creal_T f, const creal_T g, real_T *cs,
  creal_T *sn, creal_T *r, B_Lattice_planner_ros_code_T *localB)
{
  int32_T count;
  int8_T rescaledir;
  boolean_T guard1{ false };

  localB->f2s = std::abs(f.re);
  localB->scale_m = localB->f2s;
  localB->di = std::abs(f.im);
  if (localB->di > localB->f2s) {
    localB->scale_m = localB->di;
  }

  localB->gs_re = std::abs(g.re);
  localB->gs_im = std::abs(g.im);
  if (localB->gs_im > localB->gs_re) {
    localB->gs_re = localB->gs_im;
  }

  if (localB->gs_re > localB->scale_m) {
    localB->scale_m = localB->gs_re;
  }

  localB->fs_re = f.re;
  localB->fs_im = f.im;
  localB->gs_re = g.re;
  localB->gs_im = g.im;
  count = -1;
  rescaledir = 0;
  guard1 = false;
  if (localB->scale_m >= 7.4428285367870146E+137) {
    do {
      count++;
      localB->fs_re *= 1.3435752215134178E-138;
      localB->fs_im *= 1.3435752215134178E-138;
      localB->gs_re *= 1.3435752215134178E-138;
      localB->gs_im *= 1.3435752215134178E-138;
      localB->scale_m *= 1.3435752215134178E-138;
    } while ((localB->scale_m >= 7.4428285367870146E+137) && (count + 1 < 20));

    rescaledir = 1;
    guard1 = true;
  } else if (localB->scale_m <= 1.3435752215134178E-138) {
    if (((g.re == 0.0) && (g.im == 0.0)) || (std::isnan(g.re) || std::isnan(g.im)))
    {
      *cs = 1.0;
      sn->re = 0.0;
      sn->im = 0.0;
      *r = f;
    } else {
      do {
        count++;
        localB->fs_re *= 7.4428285367870146E+137;
        localB->fs_im *= 7.4428285367870146E+137;
        localB->gs_re *= 7.4428285367870146E+137;
        localB->gs_im *= 7.4428285367870146E+137;
        localB->scale_m *= 7.4428285367870146E+137;
      } while (localB->scale_m <= 1.3435752215134178E-138);

      rescaledir = -1;
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    localB->scale_m = localB->fs_re * localB->fs_re + localB->fs_im *
      localB->fs_im;
    localB->g2 = localB->gs_re * localB->gs_re + localB->gs_im * localB->gs_im;
    localB->x = localB->g2;
    if (localB->g2 < 1.0) {
      localB->x = 1.0;
    }

    if (localB->scale_m <= localB->x * 2.0041683600089728E-292) {
      if ((f.re == 0.0) && (f.im == 0.0)) {
        *cs = 0.0;
        r->re = ros_code_rt_hypotd_snf(g.re, g.im, localB);
        r->im = 0.0;
        localB->f2s = ros_code_rt_hypotd_snf(localB->gs_re, localB->gs_im,
          localB);
        sn->re = localB->gs_re / localB->f2s;
        sn->im = -localB->gs_im / localB->f2s;
      } else {
        localB->scale_m = std::sqrt(localB->g2);
        *cs = ros_code_rt_hypotd_snf(localB->fs_re, localB->fs_im, localB) /
          localB->scale_m;
        if (localB->di > localB->f2s) {
          localB->f2s = localB->di;
        }

        if (localB->f2s > 1.0) {
          localB->f2s = ros_code_rt_hypotd_snf(f.re, f.im, localB);
          localB->fs_re = f.re / localB->f2s;
          localB->fs_im = f.im / localB->f2s;
        } else {
          localB->fs_re = 7.4428285367870146E+137 * f.re;
          localB->di = 7.4428285367870146E+137 * f.im;
          localB->f2s = ros_code_rt_hypotd_snf(localB->fs_re, localB->di, localB);
          localB->fs_re /= localB->f2s;
          localB->fs_im = localB->di / localB->f2s;
        }

        localB->gs_re /= localB->scale_m;
        localB->gs_im = -localB->gs_im / localB->scale_m;
        sn->re = localB->fs_re * localB->gs_re - localB->fs_im * localB->gs_im;
        sn->im = localB->fs_re * localB->gs_im + localB->fs_im * localB->gs_re;
        r->re = (sn->re * g.re - sn->im * g.im) + *cs * f.re;
        r->im = (sn->re * g.im + sn->im * g.re) + *cs * f.im;
      }
    } else {
      localB->f2s = std::sqrt(localB->g2 / localB->scale_m + 1.0);
      r->re = localB->f2s * localB->fs_re;
      r->im = localB->f2s * localB->fs_im;
      *cs = 1.0 / localB->f2s;
      localB->f2s = localB->scale_m + localB->g2;
      localB->fs_re = r->re / localB->f2s;
      localB->f2s = r->im / localB->f2s;
      sn->re = localB->fs_re * localB->gs_re - localB->f2s * -localB->gs_im;
      sn->im = localB->fs_re * -localB->gs_im + localB->f2s * localB->gs_re;
      if (rescaledir > 0) {
        for (int32_T b_i{0}; b_i <= count; b_i++) {
          r->re *= 7.4428285367870146E+137;
          r->im *= 7.4428285367870146E+137;
        }
      } else if (rescaledir < 0) {
        for (int32_T b_i{0}; b_i <= count; b_i++) {
          r->re *= 1.3435752215134178E-138;
          r->im *= 1.3435752215134178E-138;
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_sqrt(creal_T *x, B_Lattice_planner_ros_code_T *localB)
{
  real_T absxi;
  if (x->im == 0.0) {
    if (x->re < 0.0) {
      localB->absxr = 0.0;
      absxi = std::sqrt(-x->re);
    } else {
      localB->absxr = std::sqrt(x->re);
      absxi = 0.0;
    }
  } else if (x->re == 0.0) {
    if (x->im < 0.0) {
      localB->absxr = std::sqrt(-x->im / 2.0);
      absxi = -localB->absxr;
    } else {
      localB->absxr = std::sqrt(x->im / 2.0);
      absxi = localB->absxr;
    }
  } else if (std::isnan(x->re)) {
    localB->absxr = x->re;
    absxi = x->re;
  } else if (std::isnan(x->im)) {
    localB->absxr = x->im;
    absxi = x->im;
  } else if (std::isinf(x->im)) {
    localB->absxr = std::abs(x->im);
    absxi = x->im;
  } else if (std::isinf(x->re)) {
    if (x->re < 0.0) {
      localB->absxr = 0.0;
      absxi = x->im * -x->re;
    } else {
      localB->absxr = x->re;
      absxi = 0.0;
    }
  } else {
    localB->absxr = std::abs(x->re);
    absxi = std::abs(x->im);
    if ((localB->absxr > 4.4942328371557893E+307) || (absxi >
         4.4942328371557893E+307)) {
      localB->absxr *= 0.5;
      absxi = ros_code_rt_hypotd_snf(localB->absxr, absxi * 0.5, localB);
      if (absxi > localB->absxr) {
        localB->absxr = std::sqrt(localB->absxr / absxi + 1.0) * std::sqrt(absxi);
      } else {
        localB->absxr = std::sqrt(absxi) * 1.4142135623730951;
      }
    } else {
      localB->absxr = std::sqrt((ros_code_rt_hypotd_snf(localB->absxr, absxi,
        localB) + localB->absxr) * 0.5);
    }

    if (x->re > 0.0) {
      absxi = x->im / localB->absxr * 0.5;
    } else {
      if (x->im < 0.0) {
        absxi = -localB->absxr;
      } else {
        absxi = localB->absxr;
      }

      localB->absxr = x->im / absxi * 0.5;
    }
  }

  x->re = localB->absxr;
  x->im = absxi;
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_xzhgeqz(const creal_T A_data[], const int32_T A_size[2],
  int32_T ilo, int32_T ihi, int32_T *info, creal_T alpha1_data[], int32_T
  *alpha1_size, creal_T beta1_data[], int32_T *beta1_size,
  B_Lattice_planner_ros_code_T *localB)
{
  boolean_T failed;
  boolean_T guard1{ false };

  boolean_T guard2{ false };

  localB->b_A_size_idx_0 = A_size[0];
  localB->ifirst = A_size[0] * A_size[1];
  if (localB->ifirst - 1 >= 0) {
    std::memcpy(&localB->b_A_data_n[0], &A_data[0], localB->ifirst * sizeof
                (creal_T));
  }

  *info = 0;
  if ((A_size[0] == 1) && (A_size[1] == 1)) {
    ihi = 1;
  }

  *alpha1_size = A_size[0];
  localB->ifirst = A_size[0];
  if (localB->ifirst - 1 >= 0) {
    std::memset(&alpha1_data[0], 0, localB->ifirst * sizeof(creal_T));
  }

  *beta1_size = A_size[0];
  localB->ifirst = A_size[0];
  for (localB->nm1 = 0; localB->nm1 < localB->ifirst; localB->nm1++) {
    beta1_data[localB->nm1].re = 1.0;
    beta1_data[localB->nm1].im = 0.0;
  }

  localB->eshift_re = 0.0;
  localB->eshift_im = 0.0;
  localB->ctemp.re = 0.0;
  localB->ctemp.im = 0.0;
  localB->anorm = 0.0;
  if (ilo <= ihi) {
    localB->scale = 3.3121686421112381E-170;
    localB->ssq = 0.0;
    localB->nm1 = ihi - ilo;
    localB->ifirst = -1;
    while (localB->ifirst + 1 <= localB->nm1) {
      localB->colscale = 3.3121686421112381E-170;
      localB->anorm = 0.0;
      localB->col = ilo + localB->ifirst;
      if (localB->ifirst + 2 <= localB->nm1) {
        localB->ilastm1 = localB->ifirst + 2;
      } else {
        localB->ilastm1 = localB->nm1;
      }

      localB->ilastm1 += ilo;
      localB->ilastm = ilo;
      while (localB->ilastm <= localB->ilastm1) {
        localB->ctemp_tmp_tmp = (A_size[0] * localB->col + localB->ilastm) - 1;
        localB->absxk_c = std::abs(A_data[localB->ctemp_tmp_tmp].re);
        if (localB->absxk_c > localB->colscale) {
          localB->t_m = localB->colscale / localB->absxk_c;
          localB->anorm = localB->anorm * localB->t_m * localB->t_m + 1.0;
          localB->colscale = localB->absxk_c;
        } else {
          localB->t_m = localB->absxk_c / localB->colscale;
          localB->anorm += localB->t_m * localB->t_m;
        }

        localB->absxk_c = std::abs(A_data[localB->ctemp_tmp_tmp].im);
        if (localB->absxk_c > localB->colscale) {
          localB->t_m = localB->colscale / localB->absxk_c;
          localB->anorm = localB->anorm * localB->t_m * localB->t_m + 1.0;
          localB->colscale = localB->absxk_c;
        } else {
          localB->t_m = localB->absxk_c / localB->colscale;
          localB->anorm += localB->t_m * localB->t_m;
        }

        localB->ilastm++;
      }

      if (localB->scale >= localB->colscale) {
        localB->colscale /= localB->scale;
        localB->ssq += localB->colscale * localB->colscale * localB->anorm;
      } else {
        localB->scale /= localB->colscale;
        localB->ssq = localB->scale * localB->scale * localB->ssq +
          localB->anorm;
        localB->scale = localB->colscale;
      }

      localB->ifirst++;
    }

    localB->anorm = localB->scale * std::sqrt(localB->ssq);
  }

  localB->ssq = 2.2250738585072014E-308;
  localB->scale = 2.2204460492503131E-16 * localB->anorm;
  if (localB->scale > 2.2250738585072014E-308) {
    localB->ssq = localB->scale;
  }

  localB->scale = 2.2250738585072014E-308;
  if (localB->anorm > 2.2250738585072014E-308) {
    localB->scale = localB->anorm;
  }

  localB->anorm = 1.0 / localB->scale;
  localB->scale = 1.0 / std::sqrt(static_cast<real_T>(A_size[0]));
  failed = true;
  localB->nm1 = ihi;
  while (localB->nm1 + 1 <= A_size[0]) {
    alpha1_data[localB->nm1] = A_data[A_size[0] * localB->nm1 + localB->nm1];
    localB->nm1++;
  }

  guard1 = false;
  guard2 = false;
  if (ihi >= ilo) {
    boolean_T goto60;
    boolean_T goto70;
    boolean_T goto90;
    localB->ifirst = ilo;
    localB->col = ilo;
    localB->nm1 = ihi - 1;
    localB->ilastm1 = ihi - 2;
    localB->ilastm = ihi;
    localB->iiter = 0;
    goto60 = false;
    goto70 = false;
    goto90 = false;
    localB->jiter = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (localB->jiter <= ((ihi - ilo) + 1) * 30 - 1) {
        boolean_T exitg2;
        if (localB->nm1 + 1 == ilo) {
          goto60 = true;
        } else {
          localB->jp1 = localB->b_A_size_idx_0 * localB->ilastm1 + localB->nm1;
          if (std::abs(localB->b_A_data_n[localB->jp1].re) + std::abs
              (localB->b_A_data_n[localB->jp1].im) <= localB->ssq) {
            localB->b_A_data_n[localB->jp1].re = 0.0;
            localB->b_A_data_n[localB->jp1].im = 0.0;
            goto60 = true;
          } else {
            boolean_T guard3{ false };

            localB->j_e = localB->ilastm1;
            guard3 = false;
            exitg2 = false;
            while ((!exitg2) && (localB->j_e + 1 >= ilo)) {
              if (localB->j_e + 1 == ilo) {
                guard3 = true;
                exitg2 = true;
              } else {
                localB->jp1 = (localB->j_e - 1) * localB->b_A_size_idx_0 +
                  localB->j_e;
                if (std::abs(localB->b_A_data_n[localB->jp1].re) + std::abs
                    (localB->b_A_data_n[localB->jp1].im) <= localB->ssq) {
                  localB->b_A_data_n[localB->jp1].re = 0.0;
                  localB->b_A_data_n[localB->jp1].im = 0.0;
                  guard3 = true;
                  exitg2 = true;
                } else {
                  localB->j_e--;
                  guard3 = false;
                }
              }
            }

            if (guard3) {
              localB->ifirst = localB->j_e + 1;
              goto70 = true;
            }
          }
        }

        if ((!goto60) && (!goto70)) {
          localB->ifirst = *alpha1_size;
          for (localB->nm1 = 0; localB->nm1 < localB->ifirst; localB->nm1++) {
            alpha1_data[localB->nm1].re = (rtNaN);
            alpha1_data[localB->nm1].im = 0.0;
          }

          localB->ifirst = *beta1_size;
          for (localB->nm1 = 0; localB->nm1 < localB->ifirst; localB->nm1++) {
            beta1_data[localB->nm1].re = (rtNaN);
            beta1_data[localB->nm1].im = 0.0;
          }

          *info = 1;
          exitg1 = 1;
        } else if (goto60) {
          goto60 = false;
          alpha1_data[localB->nm1] = localB->b_A_data_n[localB->b_A_size_idx_0 *
            localB->nm1 + localB->nm1];
          localB->nm1 = localB->ilastm1;
          localB->ilastm1--;
          if (localB->nm1 + 1 < ilo) {
            failed = false;
            guard2 = true;
            exitg1 = 1;
          } else {
            localB->iiter = 0;
            localB->eshift_re = 0.0;
            localB->eshift_im = 0.0;
            localB->ilastm = localB->nm1 + 1;
            localB->jiter++;
          }
        } else {
          if (goto70) {
            goto70 = false;
            localB->iiter++;
            if (localB->iiter - localB->iiter / 10 * 10 != 0) {
              localB->j_e = localB->b_A_size_idx_0 * localB->ilastm1 +
                localB->ilastm1;
              localB->ar = localB->anorm * localB->b_A_data_n[localB->j_e].re;
              localB->ai = localB->anorm * localB->b_A_data_n[localB->j_e].im;
              if (localB->ai == 0.0) {
                localB->shift.re = localB->ar / localB->scale;
                localB->shift.im = 0.0;
              } else if (localB->ar == 0.0) {
                localB->shift.re = 0.0;
                localB->shift.im = localB->ai / localB->scale;
              } else {
                localB->shift.re = localB->ar / localB->scale;
                localB->shift.im = localB->ai / localB->scale;
              }

              localB->j_e = localB->b_A_size_idx_0 * localB->nm1 + localB->nm1;
              localB->ar = localB->anorm * localB->b_A_data_n[localB->j_e].re;
              localB->ai = localB->anorm * localB->b_A_data_n[localB->j_e].im;
              if (localB->ai == 0.0) {
                localB->t_m = localB->ar / localB->scale;
                localB->ad22_im = 0.0;
              } else if (localB->ar == 0.0) {
                localB->t_m = 0.0;
                localB->ad22_im = localB->ai / localB->scale;
              } else {
                localB->t_m = localB->ar / localB->scale;
                localB->ad22_im = localB->ai / localB->scale;
              }

              localB->t1_re = (localB->shift.re + localB->t_m) * 0.5;
              localB->t1_im = (localB->shift.im + localB->ad22_im) * 0.5;
              localB->j_e = localB->b_A_size_idx_0 * localB->nm1 +
                localB->ilastm1;
              localB->ar = localB->anorm * localB->b_A_data_n[localB->j_e].re;
              localB->ai = localB->anorm * localB->b_A_data_n[localB->j_e].im;
              if (localB->ai == 0.0) {
                localB->colscale = localB->ar / localB->scale;
                localB->absxk_c = 0.0;
              } else if (localB->ar == 0.0) {
                localB->colscale = 0.0;
                localB->absxk_c = localB->ai / localB->scale;
              } else {
                localB->colscale = localB->ar / localB->scale;
                localB->absxk_c = localB->ai / localB->scale;
              }

              localB->j_e = localB->b_A_size_idx_0 * localB->ilastm1 +
                localB->nm1;
              localB->ar = localB->anorm * localB->b_A_data_n[localB->j_e].re;
              localB->ai = localB->anorm * localB->b_A_data_n[localB->j_e].im;
              if (localB->ai == 0.0) {
                localB->ar /= localB->scale;
                localB->ai = 0.0;
              } else if (localB->ar == 0.0) {
                localB->ar = 0.0;
                localB->ai /= localB->scale;
              } else {
                localB->ar /= localB->scale;
                localB->ai /= localB->scale;
              }

              localB->shift_im = localB->shift.re * localB->ad22_im +
                localB->shift.im * localB->t_m;
              localB->shift.re = ((localB->t1_re * localB->t1_re - localB->t1_im
                                   * localB->t1_im) + (localB->colscale *
                localB->ar - localB->absxk_c * localB->ai)) - (localB->shift.re *
                localB->t_m - localB->shift.im * localB->ad22_im);
              localB->shift_tmp = localB->t1_re * localB->t1_im;
              localB->shift.im = ((localB->colscale * localB->ai +
                                   localB->absxk_c * localB->ar) +
                                  (localB->shift_tmp + localB->shift_tmp)) -
                localB->shift_im;
              ros_code_sqrt(&localB->shift, localB);
              if ((localB->t1_re - localB->t_m) * localB->shift.re +
                  (localB->t1_im - localB->ad22_im) * localB->shift.im <= 0.0) {
                localB->shift.re += localB->t1_re;
                localB->shift.im += localB->t1_im;
              } else {
                localB->shift.re = localB->t1_re - localB->shift.re;
                localB->shift.im = localB->t1_im - localB->shift.im;
              }
            } else {
              localB->j_e = localB->b_A_size_idx_0 * localB->ilastm1 +
                localB->nm1;
              localB->ar = localB->anorm * localB->b_A_data_n[localB->j_e].re;
              localB->ai = localB->anorm * localB->b_A_data_n[localB->j_e].im;
              if (localB->ai == 0.0) {
                localB->colscale = localB->ar / localB->scale;
                localB->absxk_c = 0.0;
              } else if (localB->ar == 0.0) {
                localB->colscale = 0.0;
                localB->absxk_c = localB->ai / localB->scale;
              } else {
                localB->colscale = localB->ar / localB->scale;
                localB->absxk_c = localB->ai / localB->scale;
              }

              localB->eshift_re += localB->colscale;
              localB->eshift_im += localB->absxk_c;
              localB->shift.re = localB->eshift_re;
              localB->shift.im = localB->eshift_im;
            }

            localB->j_e = localB->ilastm1;
            localB->jp1 = localB->ilastm1 + 1;
            exitg2 = false;
            while ((!exitg2) && (localB->j_e + 1 > localB->ifirst)) {
              localB->col = localB->j_e + 1;
              localB->ctemp_tmp_tmp = localB->b_A_size_idx_0 * localB->j_e;
              localB->ctemp_tmp = localB->j_e + localB->ctemp_tmp_tmp;
              localB->ctemp.re = localB->anorm * localB->b_A_data_n
                [localB->ctemp_tmp].re - localB->shift.re * localB->scale;
              localB->ctemp.im = localB->anorm * localB->b_A_data_n
                [localB->ctemp_tmp].im - localB->shift.im * localB->scale;
              localB->colscale = std::abs(localB->ctemp.re) + std::abs
                (localB->ctemp.im);
              localB->ctemp_tmp_tmp += localB->jp1;
              localB->absxk_c = (std::abs(localB->b_A_data_n
                [localB->ctemp_tmp_tmp].re) + std::abs(localB->b_A_data_n
                [localB->ctemp_tmp_tmp].im)) * localB->anorm;
              localB->t_m = localB->colscale;
              if (localB->absxk_c > localB->colscale) {
                localB->t_m = localB->absxk_c;
              }

              if ((localB->t_m < 1.0) && (localB->t_m != 0.0)) {
                localB->colscale /= localB->t_m;
                localB->absxk_c /= localB->t_m;
              }

              localB->jp1 = (localB->j_e - 1) * localB->b_A_size_idx_0 +
                localB->j_e;
              if ((std::abs(localB->b_A_data_n[localB->jp1].re) + std::abs
                   (localB->b_A_data_n[localB->jp1].im)) * localB->absxk_c <=
                  localB->colscale * localB->ssq) {
                goto90 = true;
                exitg2 = true;
              } else {
                localB->jp1 = localB->j_e;
                localB->j_e--;
              }
            }

            if (!goto90) {
              localB->col = localB->ifirst;
              localB->ctemp_tmp = ((localB->ifirst - 1) * localB->b_A_size_idx_0
                                   + localB->ifirst) - 1;
              localB->ctemp.re = localB->b_A_data_n[localB->ctemp_tmp].re *
                localB->anorm - localB->shift.re * localB->scale;
              localB->ctemp.im = localB->b_A_data_n[localB->ctemp_tmp].im *
                localB->anorm - localB->shift.im * localB->scale;
            }

            goto90 = false;
            localB->j_e = (localB->col - 1) * localB->b_A_size_idx_0 +
              localB->col;
            localB->ascale.re = localB->b_A_data_n[localB->j_e].re *
              localB->anorm;
            localB->ascale.im = localB->b_A_data_n[localB->j_e].im *
              localB->anorm;
            ros_code_xzlartg_h(localB->ctemp, localB->ascale, &localB->colscale,
                               &localB->shift, localB);
            localB->j_e = localB->col;
            localB->jp1 = localB->col - 2;
            while (localB->j_e < localB->nm1 + 1) {
              if (localB->j_e > localB->col) {
                ros_code_xzlartg(localB->b_A_data_n[1 + localB->b_A_size_idx_0 *
                                 localB->jp1], localB->b_A_data_n[localB->j_e +
                                 localB->b_A_size_idx_0 * localB->jp1],
                                 &localB->colscale, &localB->shift,
                                 &localB->b_A_data_n[1 + localB->b_A_size_idx_0 *
                                 localB->jp1], localB);
                localB->jp1 = localB->b_A_size_idx_0 * localB->jp1 + localB->j_e;
                localB->b_A_data_n[localB->jp1].re = 0.0;
                localB->b_A_data_n[localB->jp1].im = 0.0;
              }

              localB->jp1 = localB->j_e - 1;
              while (localB->jp1 + 1 <= localB->ilastm) {
                localB->ctemp_tmp = localB->b_A_size_idx_0 * localB->jp1;
                localB->ctemp_tmp_tmp = localB->j_e + localB->ctemp_tmp;
                localB->absxk_c = localB->b_A_data_n[localB->ctemp_tmp_tmp].im;
                localB->t_m = localB->b_A_data_n[localB->ctemp_tmp_tmp].re;
                localB->ad22_im_tmp = (localB->j_e + localB->ctemp_tmp) - 1;
                localB->ad22_im = localB->b_A_data_n[localB->ad22_im_tmp].re;
                localB->t1_re = localB->b_A_data_n[localB->ad22_im_tmp].im;
                localB->b_A_data_n[localB->ctemp_tmp_tmp].re = localB->colscale *
                  localB->t_m - (localB->ad22_im * localB->shift.re +
                                 localB->t1_re * localB->shift.im);
                localB->b_A_data_n[localB->ctemp_tmp_tmp].im = localB->colscale *
                  localB->absxk_c - (localB->t1_re * localB->shift.re -
                                     localB->shift.im * localB->ad22_im);
                localB->b_A_data_n[localB->ad22_im_tmp].re = (localB->shift.re *
                  localB->t_m - localB->shift.im * localB->absxk_c) +
                  localB->ad22_im * localB->colscale;
                localB->b_A_data_n[localB->ad22_im_tmp].im = (localB->shift.re *
                  localB->absxk_c + localB->shift.im * localB->t_m) +
                  localB->t1_re * localB->colscale;
                localB->jp1++;
              }

              localB->shift.re = -localB->shift.re;
              localB->shift.im = -localB->shift.im;
              localB->jp1 = localB->j_e;
              if (localB->nm1 + 1 < localB->j_e + 2) {
                localB->jp1 = localB->nm1 - 1;
              }

              localB->ctemp_tmp = localB->ifirst - 1;
              while (localB->ctemp_tmp + 1 <= localB->jp1 + 2) {
                localB->ctemp_tmp_tmp = (localB->j_e - 1) *
                  localB->b_A_size_idx_0 + localB->ctemp_tmp;
                localB->absxk_c = localB->b_A_data_n[localB->ctemp_tmp_tmp].im;
                localB->t_m = localB->b_A_data_n[localB->ctemp_tmp_tmp].re;
                localB->ad22_im_tmp = localB->b_A_size_idx_0 * localB->j_e +
                  localB->ctemp_tmp;
                localB->ad22_im = localB->b_A_data_n[localB->ad22_im_tmp].re;
                localB->t1_re = localB->b_A_data_n[localB->ad22_im_tmp].im;
                localB->b_A_data_n[localB->ctemp_tmp_tmp].re = localB->t_m *
                  localB->colscale - (localB->shift.re * localB->ad22_im +
                                      localB->shift.im * localB->t1_re);
                localB->b_A_data_n[localB->ctemp_tmp_tmp].im = localB->absxk_c *
                  localB->colscale - (localB->shift.re * localB->t1_re -
                                      localB->shift.im * localB->ad22_im);
                localB->b_A_data_n[localB->ad22_im_tmp].re = (localB->t_m *
                  localB->shift.re - localB->absxk_c * localB->shift.im) +
                  localB->colscale * localB->ad22_im;
                localB->b_A_data_n[localB->ad22_im_tmp].im = (localB->absxk_c *
                  localB->shift.re + localB->t_m * localB->shift.im) +
                  localB->colscale * localB->t1_re;
                localB->ctemp_tmp++;
              }

              localB->jp1 = localB->j_e - 1;
              localB->j_e++;
            }
          }

          localB->jiter++;
        }
      } else {
        guard2 = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    guard1 = true;
  }

  if (guard2) {
    if (failed) {
      *info = localB->nm1 + 1;
      localB->ifirst = 0;
      while (localB->ifirst <= localB->nm1) {
        alpha1_data[localB->ifirst].re = (rtNaN);
        alpha1_data[localB->ifirst].im = 0.0;
        beta1_data[localB->ifirst].re = (rtNaN);
        beta1_data[localB->ifirst].im = 0.0;
        localB->ifirst++;
      }
    } else {
      guard1 = true;
    }
  }

  if (guard1) {
    localB->nm1 = 0;
    while (localB->nm1 <= ilo - 2) {
      alpha1_data[localB->nm1] = localB->b_A_data_n[localB->b_A_size_idx_0 *
        localB->nm1 + localB->nm1];
      localB->nm1++;
    }
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_eigStandard(const real_T A_data[], const int32_T A_size[2],
  creal_T V_data[], int32_T *V_size, B_Lattice_planner_ros_code_T *localB)
{
  boolean_T exitg1;
  localB->At_size[0] = A_size[0];
  localB->At_size[1] = A_size[1];
  localB->ii = A_size[0] * A_size[1];
  for (localB->nzcount = 0; localB->nzcount < localB->ii; localB->nzcount++) {
    localB->At_data[localB->nzcount].re = A_data[localB->nzcount];
    localB->At_data[localB->nzcount].im = 0.0;
  }

  localB->anrm = 0.0;
  localB->b_tmp = A_size[0] * A_size[1];
  localB->k_f = 0;
  exitg1 = false;
  while ((!exitg1) && (localB->k_f <= localB->b_tmp - 1)) {
    localB->absxk = ros_code_rt_hypotd_snf(localB->At_data[localB->k_f].re,
      localB->At_data[localB->k_f].im, localB);
    if (std::isnan(localB->absxk)) {
      localB->anrm = (rtNaN);
      exitg1 = true;
    } else {
      if (localB->absxk > localB->anrm) {
        localB->anrm = localB->absxk;
      }

      localB->k_f++;
    }
  }

  if (std::isinf(localB->anrm) || std::isnan(localB->anrm)) {
    *V_size = A_size[0];
    localB->ii = A_size[0];
    for (localB->nzcount = 0; localB->nzcount < localB->ii; localB->nzcount++) {
      V_data[localB->nzcount].re = (rtNaN);
      V_data[localB->nzcount].im = 0.0;
    }

    localB->y_size = A_size[0];
    localB->ii = A_size[0];
    for (localB->nzcount = 0; localB->nzcount < localB->ii; localB->nzcount++) {
      localB->y_data_p[localB->nzcount].re = (rtNaN);
      localB->y_data_p[localB->nzcount].im = 0.0;
    }
  } else {
    boolean_T guard1{ false };

    boolean_T ilascl;
    boolean_T notdone;
    ilascl = false;
    localB->absxk = localB->anrm;
    guard1 = false;
    if ((localB->anrm > 0.0) && (localB->anrm < 6.7178761075670888E-139)) {
      localB->absxk = 6.7178761075670888E-139;
      ilascl = true;
      guard1 = true;
    } else if (localB->anrm > 1.4885657073574029E+138) {
      localB->absxk = 1.4885657073574029E+138;
      ilascl = true;
      guard1 = true;
    }

    if (guard1) {
      localB->cfromc = localB->anrm;
      localB->ctoc = localB->absxk;
      notdone = true;
      while (notdone) {
        localB->cfrom1 = localB->cfromc * 2.0041683600089728E-292;
        localB->cto1 = localB->ctoc / 4.9896007738368E+291;
        if ((localB->cfrom1 > localB->ctoc) && (localB->ctoc != 0.0)) {
          localB->stemp_im_tmp = 2.0041683600089728E-292;
          localB->cfromc = localB->cfrom1;
        } else if (localB->cto1 > localB->cfromc) {
          localB->stemp_im_tmp = 4.9896007738368E+291;
          localB->ctoc = localB->cto1;
        } else {
          localB->stemp_im_tmp = localB->ctoc / localB->cfromc;
          notdone = false;
        }

        for (localB->nzcount = 0; localB->nzcount < localB->b_tmp;
             localB->nzcount++) {
          localB->At_data[localB->nzcount].re *= localB->stemp_im_tmp;
          localB->At_data[localB->nzcount].im *= localB->stemp_im_tmp;
        }
      }
    }

    localB->b_tmp = 1;
    localB->k_f = A_size[0];
    if (A_size[0] <= 1) {
      localB->k_f = 1;
    } else {
      int32_T exitg3;
      boolean_T exitg4;
      do {
        exitg3 = 0;
        localB->At = 0;
        localB->n_h = 0;
        notdone = false;
        localB->ii = localB->k_f;
        exitg1 = false;
        while ((!exitg1) && (localB->ii > 0)) {
          localB->nzcount = 0;
          localB->At = localB->ii;
          localB->n_h = localB->k_f;
          localB->jj = 0;
          exitg4 = false;
          while ((!exitg4) && (localB->jj <= localB->k_f - 1)) {
            localB->b_A_size_idx_1 = (localB->At_size[0] * localB->jj +
              localB->ii) - 1;
            if ((localB->At_data[localB->b_A_size_idx_1].re != 0.0) ||
                (localB->At_data[localB->b_A_size_idx_1].im != 0.0) ||
                (localB->jj + 1 == localB->ii)) {
              if (localB->nzcount == 0) {
                localB->n_h = localB->jj + 1;
                localB->nzcount = 1;
                localB->jj++;
              } else {
                localB->nzcount = 2;
                exitg4 = true;
              }
            } else {
              localB->jj++;
            }
          }

          if (localB->nzcount < 2) {
            notdone = true;
            exitg1 = true;
          } else {
            localB->ii--;
          }
        }

        if (!notdone) {
          exitg3 = 2;
        } else {
          localB->nzcount = localB->At_size[0];
          localB->b_A_size_idx_1 = localB->At_size[1];
          localB->ii = localB->At_size[0] * localB->At_size[1];
          if (localB->ii - 1 >= 0) {
            std::memcpy(&localB->b_A_data[0], &localB->At_data[0], localB->ii *
                        sizeof(creal_T));
          }

          if (localB->At != localB->k_f) {
            localB->ii = 0;
            while (localB->ii + 1 <= localB->At_size[0]) {
              localB->jj = localB->nzcount * localB->ii;
              localB->atmp_tmp = (localB->At + localB->jj) - 1;
              localB->atmp = localB->b_A_data[localB->atmp_tmp];
              localB->b_A_data_tmp = (localB->k_f + localB->jj) - 1;
              localB->b_A_data[localB->atmp_tmp] = localB->b_A_data
                [localB->b_A_data_tmp];
              localB->b_A_data[localB->b_A_data_tmp] = localB->atmp;
              localB->ii++;
            }
          }

          if (localB->n_h != localB->k_f) {
            localB->ii = 0;
            while (localB->ii <= localB->k_f - 1) {
              localB->jj = (localB->n_h - 1) * localB->nzcount + localB->ii;
              localB->atmp = localB->b_A_data[localB->jj];
              localB->b_A_data_tmp = (localB->k_f - 1) * localB->nzcount +
                localB->ii;
              localB->b_A_data[localB->jj] = localB->b_A_data
                [localB->b_A_data_tmp];
              localB->b_A_data[localB->b_A_data_tmp] = localB->atmp;
              localB->ii++;
            }
          }

          localB->ii = localB->nzcount * localB->b_A_size_idx_1;
          if (localB->ii - 1 >= 0) {
            std::memcpy(&localB->At_data[0], &localB->b_A_data[0], localB->ii *
                        sizeof(creal_T));
          }

          localB->k_f--;
          if (localB->k_f == 1) {
            exitg3 = 1;
          }
        }
      } while (exitg3 == 0);

      if (exitg3 == 1) {
      } else {
        int32_T exitg2;
        do {
          exitg2 = 0;
          localB->At = 0;
          localB->n_h = 0;
          notdone = false;
          localB->ii = localB->b_tmp;
          exitg1 = false;
          while ((!exitg1) && (localB->ii <= localB->k_f)) {
            localB->nzcount = 0;
            localB->At = localB->k_f;
            localB->n_h = localB->ii;
            localB->jj = localB->b_tmp;
            exitg4 = false;
            while ((!exitg4) && (localB->jj <= localB->k_f)) {
              localB->b_A_size_idx_1 = ((localB->ii - 1) * localB->At_size[0] +
                localB->jj) - 1;
              if ((localB->At_data[localB->b_A_size_idx_1].re != 0.0) ||
                  (localB->At_data[localB->b_A_size_idx_1].im != 0.0) ||
                  (localB->jj == localB->ii)) {
                if (localB->nzcount == 0) {
                  localB->At = localB->jj;
                  localB->nzcount = 1;
                  localB->jj++;
                } else {
                  localB->nzcount = 2;
                  exitg4 = true;
                }
              } else {
                localB->jj++;
              }
            }

            if (localB->nzcount < 2) {
              notdone = true;
              exitg1 = true;
            } else {
              localB->ii++;
            }
          }

          if (!notdone) {
            exitg2 = 1;
          } else {
            localB->nzcount = localB->At_size[0];
            localB->b_A_size_idx_1 = localB->At_size[1];
            localB->ii = localB->At_size[0] * localB->At_size[1];
            if (localB->ii - 1 >= 0) {
              std::memcpy(&localB->b_A_data[0], &localB->At_data[0], localB->ii *
                          sizeof(creal_T));
            }

            if (localB->At != localB->b_tmp) {
              localB->ii = localB->b_tmp - 1;
              while (localB->ii + 1 <= localB->At_size[0]) {
                localB->jj = localB->nzcount * localB->ii;
                localB->atmp_tmp = (localB->At + localB->jj) - 1;
                localB->atmp = localB->b_A_data[localB->atmp_tmp];
                localB->b_A_data_tmp = (localB->b_tmp + localB->jj) - 1;
                localB->b_A_data[localB->atmp_tmp] = localB->b_A_data
                  [localB->b_A_data_tmp];
                localB->b_A_data[localB->b_A_data_tmp] = localB->atmp;
                localB->ii++;
              }
            }

            if (localB->n_h != localB->b_tmp) {
              localB->ii = 0;
              while (localB->ii <= localB->k_f - 1) {
                localB->jj = (localB->n_h - 1) * localB->nzcount + localB->ii;
                localB->atmp = localB->b_A_data[localB->jj];
                localB->b_A_data_tmp = (localB->b_tmp - 1) * localB->nzcount +
                  localB->ii;
                localB->b_A_data[localB->jj] = localB->b_A_data
                  [localB->b_A_data_tmp];
                localB->b_A_data[localB->b_A_data_tmp] = localB->atmp;
                localB->ii++;
              }
            }

            localB->ii = localB->nzcount * localB->b_A_size_idx_1;
            if (localB->ii - 1 >= 0) {
              std::memcpy(&localB->At_data[0], &localB->b_A_data[0], localB->ii *
                          sizeof(creal_T));
            }

            localB->b_tmp++;
            if (localB->b_tmp == localB->k_f) {
              exitg2 = 1;
            }
          }
        } while (exitg2 == 0);
      }
    }

    localB->n_h = localB->At_size[0];
    if ((localB->At_size[0] > 1) && (localB->k_f >= localB->b_tmp + 2)) {
      localB->ii = localB->b_tmp;
      while (localB->ii < 2) {
        ros_code_xzlartg(localB->At_data[1], localB->At_data[2], &localB->cfromc,
                         &localB->atmp, &localB->At_data[1], localB);
        localB->b_A_size_idx_1 = 2;
        localB->At_data[localB->b_A_size_idx_1].re = 0.0;
        localB->At_data[localB->b_A_size_idx_1].im = 0.0;
        localB->ii = 1;
        while (localB->ii + 1 <= localB->n_h) {
          localB->At = localB->At_size[0] * localB->ii;
          localB->ctoc = localB->At_data[2 + localB->At].im;
          localB->cfrom1 = localB->At_data[2 + localB->At].re;
          localB->cto1 = localB->At_data[1 + localB->At].re;
          localB->stemp_im_tmp = localB->At_data[1 + localB->At].im;
          localB->At_data[2 + localB->At].re = localB->cfromc * localB->cfrom1 -
            (localB->atmp.re * localB->cto1 + localB->atmp.im *
             localB->stemp_im_tmp);
          localB->At_data[2 + localB->At].im = localB->cfromc * localB->ctoc -
            (localB->atmp.re * localB->stemp_im_tmp - localB->atmp.im *
             localB->cto1);
          localB->At_data[1 + localB->At].re = (localB->atmp.re * localB->cfrom1
            - localB->atmp.im * localB->ctoc) + localB->cfromc * localB->cto1;
          localB->At_data[1 + localB->At].im = (localB->atmp.re * localB->ctoc +
            localB->atmp.im * localB->cfrom1) + localB->cfromc *
            localB->stemp_im_tmp;
          localB->ii++;
        }

        localB->atmp.re = -localB->atmp.re;
        localB->atmp.im = -localB->atmp.im;
        localB->ii = localB->At_size[0];
        localB->ctoc = localB->At_data[localB->ii].im;
        localB->cfrom1 = localB->At_data[localB->ii].re;
        localB->b_A_size_idx_1 = localB->At_size[0] << 1;
        localB->cto1 = localB->At_data[localB->b_A_size_idx_1].im;
        localB->At_data[localB->ii].re = localB->cfromc * localB->cfrom1 -
          (localB->atmp.re * localB->At_data[localB->b_A_size_idx_1].re +
           localB->atmp.im * localB->cto1);
        localB->At_data[localB->ii].im = localB->cfromc * localB->ctoc -
          (localB->atmp.re * localB->cto1 - localB->atmp.im * localB->
           At_data[localB->b_A_size_idx_1].re);
        localB->At_data[localB->b_A_size_idx_1].re = (localB->atmp.re *
          localB->cfrom1 - localB->atmp.im * localB->ctoc) + localB->cfromc *
          localB->At_data[localB->b_A_size_idx_1].re;
        localB->At_data[localB->b_A_size_idx_1].im = (localB->atmp.re *
          localB->ctoc + localB->atmp.im * localB->cfrom1) + localB->cfromc *
          localB->At_data[localB->b_A_size_idx_1].im;
        localB->ii = 1 + localB->At_size[0];
        localB->ctoc = localB->At_data[localB->ii].im;
        localB->cfrom1 = localB->At_data[localB->ii].re;
        localB->b_A_size_idx_1 = (localB->At_size[0] << 1) + 1;
        localB->cto1 = localB->At_data[localB->b_A_size_idx_1].im;
        localB->At_data[localB->ii].re = localB->cfromc * localB->cfrom1 -
          (localB->atmp.re * localB->At_data[localB->b_A_size_idx_1].re +
           localB->atmp.im * localB->cto1);
        localB->At_data[localB->ii].im = localB->cfromc * localB->ctoc -
          (localB->atmp.re * localB->cto1 - localB->atmp.im * localB->
           At_data[localB->b_A_size_idx_1].re);
        localB->At_data[localB->b_A_size_idx_1].re = (localB->atmp.re *
          localB->cfrom1 - localB->atmp.im * localB->ctoc) + localB->cfromc *
          localB->At_data[localB->b_A_size_idx_1].re;
        localB->At_data[localB->b_A_size_idx_1].im = (localB->atmp.re *
          localB->ctoc + localB->atmp.im * localB->cfrom1) + localB->cfromc *
          localB->At_data[localB->b_A_size_idx_1].im;
        localB->ii = 2 + localB->At_size[0];
        localB->ctoc = localB->At_data[localB->ii].im;
        localB->cfrom1 = localB->At_data[localB->ii].re;
        localB->b_A_size_idx_1 = (localB->At_size[0] << 1) + 2;
        localB->cto1 = localB->At_data[localB->b_A_size_idx_1].im;
        localB->At_data[localB->ii].re = localB->cfromc * localB->cfrom1 -
          (localB->atmp.re * localB->At_data[localB->b_A_size_idx_1].re +
           localB->atmp.im * localB->cto1);
        localB->At_data[localB->ii].im = localB->cfromc * localB->ctoc -
          (localB->atmp.re * localB->cto1 - localB->atmp.im * localB->
           At_data[localB->b_A_size_idx_1].re);
        localB->At_data[localB->b_A_size_idx_1].re = (localB->atmp.re *
          localB->cfrom1 - localB->atmp.im * localB->ctoc) + localB->cfromc *
          localB->At_data[localB->b_A_size_idx_1].re;
        localB->At_data[localB->b_A_size_idx_1].im = (localB->atmp.re *
          localB->ctoc + localB->atmp.im * localB->cfrom1) + localB->cfromc *
          localB->At_data[localB->b_A_size_idx_1].im;
        localB->ii = 2;
      }
    }

    ros_code_xzhgeqz(localB->At_data, localB->At_size, localB->b_tmp,
                     localB->k_f, &localB->n_h, V_data, V_size, localB->y_data_p,
                     &localB->y_size, localB);
    if ((localB->n_h == 0) && ilascl) {
      ilascl = true;
      while (ilascl) {
        localB->cfromc = localB->absxk * 2.0041683600089728E-292;
        localB->ctoc = localB->anrm / 4.9896007738368E+291;
        if ((localB->cfromc > localB->anrm) && (localB->anrm != 0.0)) {
          localB->cfrom1 = 2.0041683600089728E-292;
          localB->absxk = localB->cfromc;
        } else if (localB->ctoc > localB->absxk) {
          localB->cfrom1 = 4.9896007738368E+291;
          localB->anrm = localB->ctoc;
        } else {
          localB->cfrom1 = localB->anrm / localB->absxk;
          ilascl = false;
        }

        localB->ii = *V_size;
        for (localB->nzcount = 0; localB->nzcount < localB->ii; localB->nzcount
             ++) {
          localB->atmp = V_data[localB->nzcount];
          localB->atmp.re *= localB->cfrom1;
          localB->atmp.im *= localB->cfrom1;
          V_data[localB->nzcount] = localB->atmp;
        }
      }
    }
  }

  if (*V_size == localB->y_size) {
    localB->ii = *V_size;
    for (localB->nzcount = 0; localB->nzcount < localB->ii; localB->nzcount++) {
      localB->atmp = V_data[localB->nzcount];
      localB->anrm = localB->atmp.re;
      localB->ctoc = localB->y_data_p[localB->nzcount].re;
      localB->absxk = localB->y_data_p[localB->nzcount].im;
      if (localB->absxk == 0.0) {
        if (localB->atmp.im == 0.0) {
          localB->atmp.re /= localB->ctoc;
          localB->atmp.im = 0.0;
        } else if (localB->atmp.re == 0.0) {
          localB->atmp.re = 0.0;
          localB->atmp.im /= localB->ctoc;
        } else {
          localB->atmp.re /= localB->ctoc;
          localB->atmp.im /= localB->ctoc;
        }
      } else if (localB->ctoc == 0.0) {
        if (localB->atmp.re == 0.0) {
          localB->atmp.re = localB->atmp.im / localB->absxk;
          localB->atmp.im = 0.0;
        } else if (localB->atmp.im == 0.0) {
          localB->atmp.re = 0.0;
          localB->atmp.im = -(localB->anrm / localB->absxk);
        } else {
          localB->atmp.re = localB->atmp.im / localB->absxk;
          localB->atmp.im = -(localB->anrm / localB->absxk);
        }
      } else {
        localB->cfromc = std::abs(localB->ctoc);
        localB->cfrom1 = std::abs(localB->absxk);
        if (localB->cfromc > localB->cfrom1) {
          localB->cfromc = localB->absxk / localB->ctoc;
          localB->absxk = localB->cfromc * localB->absxk + localB->ctoc;
          localB->atmp.re = (localB->cfromc * localB->atmp.im + localB->atmp.re)
            / localB->absxk;
          localB->atmp.im = (localB->atmp.im - localB->cfromc * localB->anrm) /
            localB->absxk;
        } else if (localB->cfrom1 == localB->cfromc) {
          localB->ctoc = localB->ctoc > 0.0 ? 0.5 : -0.5;
          localB->absxk = localB->absxk > 0.0 ? 0.5 : -0.5;
          localB->atmp.re = (localB->atmp.re * localB->ctoc + localB->atmp.im *
                             localB->absxk) / localB->cfromc;
          localB->atmp.im = (localB->atmp.im * localB->ctoc - localB->anrm *
                             localB->absxk) / localB->cfromc;
        } else {
          localB->cfromc = localB->ctoc / localB->absxk;
          localB->absxk += localB->cfromc * localB->ctoc;
          localB->atmp.re = (localB->cfromc * localB->atmp.re + localB->atmp.im)
            / localB->absxk;
          localB->atmp.im = (localB->cfromc * localB->atmp.im - localB->anrm) /
            localB->absxk;
        }
      }

      V_data[localB->nzcount] = localB->atmp;
    }
  } else {
    ros_code_rdivide(V_data, V_size, localB->y_data_p, &localB->y_size, localB);
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_xgehrd(real_T a_data[], int32_T a_size[2],
  B_Lattice_planner_ros_code_T *localB)
{
  int32_T b_a_size_idx_1;
  int32_T work_size_idx_0_tmp;
  localB->b_a_size_idx_0 = a_size[0];
  b_a_size_idx_1 = a_size[1];
  localB->loop_ub_o = a_size[0] * a_size[1];
  if (localB->loop_ub_o - 1 >= 0) {
    std::memcpy(&localB->b_a_data[0], &a_data[0], localB->loop_ub_o * sizeof
                (real_T));
  }

  localB->n_p = a_size[0];
  work_size_idx_0_tmp = static_cast<int8_T>(a_size[0]);
  if (work_size_idx_0_tmp - 1 >= 0) {
    std::memset(&localB->work_data[0], 0, work_size_idx_0_tmp * sizeof(real_T));
  }

  for (work_size_idx_0_tmp = 0; work_size_idx_0_tmp <= a_size[0] - 2;
       work_size_idx_0_tmp++) {
    int32_T alpha1_tmp;
    int32_T c_lastc_tmp;
    int32_T exitg1;
    boolean_T exitg2;
    localB->loop_ub_o = work_size_idx_0_tmp * localB->n_p;
    localB->in = (work_size_idx_0_tmp + 1) * localB->n_p;
    alpha1_tmp = (localB->b_a_size_idx_0 * work_size_idx_0_tmp +
                  work_size_idx_0_tmp) + 1;
    localB->alpha1 = localB->b_a_data[alpha1_tmp];
    localB->lastv = (localB->loop_ub_o + localB->n_p) - 1;
    c_lastc_tmp = localB->n_p - work_size_idx_0_tmp;
    localB->tau_data[work_size_idx_0_tmp] = 0.0;
    if (c_lastc_tmp - 1 > 0) {
      localB->xnorm = 0.0;
      if (c_lastc_tmp - 2 >= 1) {
        localB->xnorm = std::abs(localB->b_a_data[localB->lastv]);
      }

      if (localB->xnorm != 0.0) {
        localB->xnorm = ros_code_rt_hypotd_snf(localB->alpha1, localB->xnorm,
          localB);
        if (localB->alpha1 >= 0.0) {
          localB->xnorm = -localB->xnorm;
        }

        if (std::abs(localB->xnorm) < 1.0020841800044864E-292) {
          localB->knt = 0;
          localB->rowleft = (localB->lastv + c_lastc_tmp) - 2;
          do {
            localB->knt++;
            localB->jy = localB->lastv;
            while (localB->jy + 1 <= localB->rowleft) {
              localB->b_a_data[localB->jy] *= 9.9792015476736E+291;
              localB->jy++;
            }

            localB->xnorm *= 9.9792015476736E+291;
            localB->alpha1 *= 9.9792015476736E+291;
          } while ((std::abs(localB->xnorm) < 1.0020841800044864E-292) &&
                   (localB->knt < 20));

          localB->xnorm = 0.0;
          if (c_lastc_tmp - 2 >= 1) {
            localB->xnorm = std::abs(localB->b_a_data[localB->lastv]);
          }

          localB->xnorm = ros_code_rt_hypotd_snf(localB->alpha1, localB->xnorm,
            localB);
          if (localB->alpha1 >= 0.0) {
            localB->xnorm = -localB->xnorm;
          }

          localB->tau_data[work_size_idx_0_tmp] = (localB->xnorm -
            localB->alpha1) / localB->xnorm;
          localB->alpha1 = 1.0 / (localB->alpha1 - localB->xnorm);
          while (localB->lastv + 1 <= localB->rowleft) {
            localB->b_a_data[localB->lastv] *= localB->alpha1;
            localB->lastv++;
          }

          localB->lastv = 0;
          while (localB->lastv <= localB->knt - 1) {
            localB->xnorm *= 1.0020841800044864E-292;
            localB->lastv++;
          }

          localB->alpha1 = localB->xnorm;
        } else {
          localB->tau_data[work_size_idx_0_tmp] = (localB->xnorm -
            localB->alpha1) / localB->xnorm;
          localB->alpha1 = 1.0 / (localB->alpha1 - localB->xnorm);
          localB->knt = (localB->lastv + c_lastc_tmp) - 2;
          while (localB->lastv + 1 <= localB->knt) {
            localB->b_a_data[localB->lastv] *= localB->alpha1;
            localB->lastv++;
          }

          localB->alpha1 = localB->xnorm;
        }
      }
    }

    localB->b_a_data[alpha1_tmp] = 1.0;
    localB->loop_ub_o = (work_size_idx_0_tmp + localB->loop_ub_o) + 1;
    if (localB->tau_data[work_size_idx_0_tmp] != 0.0) {
      localB->lastv = c_lastc_tmp - 2;
      localB->knt = (localB->loop_ub_o + c_lastc_tmp) - 3;
      while ((localB->lastv + 1 > 0) && (localB->b_a_data[localB->knt + 1] ==
              0.0)) {
        localB->lastv--;
        localB->knt--;
      }

      localB->knt = localB->n_p;
      exitg2 = false;
      while ((!exitg2) && (localB->knt > 0)) {
        localB->rowleft = localB->in + localB->knt;
        localB->jy = localB->rowleft;
        do {
          exitg1 = 0;
          if ((localB->n_p > 0) && (localB->jy <= localB->lastv * localB->n_p +
               localB->rowleft)) {
            if (localB->b_a_data[localB->jy - 1] != 0.0) {
              exitg1 = 1;
            } else {
              localB->jy += localB->n_p;
            }
          } else {
            localB->knt--;
            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }
    } else {
      localB->lastv = -1;
      localB->knt = 0;
    }

    if (localB->lastv + 1 > 0) {
      if (localB->knt != 0) {
        localB->rowleft = 0;
        while (localB->rowleft <= localB->knt - 1) {
          localB->work_data[localB->rowleft] = 0.0;
          localB->rowleft++;
        }

        localB->rowleft = localB->loop_ub_o;
        localB->jy = (localB->n_p * localB->lastv + localB->in) + 1;
        localB->b_ix_i = localB->in + 1;
        while ((localB->n_p > 0) && (localB->b_ix_i <= localB->jy)) {
          localB->c_ix = 0;
          localB->g_f = (localB->b_ix_i + localB->knt) - 1;
          localB->c_lastc = localB->b_ix_i;
          while (localB->c_lastc <= localB->g_f) {
            localB->work_data[localB->c_ix] += localB->b_a_data[localB->c_lastc
              - 1] * localB->b_a_data[localB->rowleft];
            localB->c_ix++;
            localB->c_lastc++;
          }

          localB->rowleft++;
          localB->b_ix_i += localB->n_p;
        }
      }

      if (!(-localB->tau_data[work_size_idx_0_tmp] == 0.0)) {
        localB->rowleft = localB->in;
        localB->jy = localB->loop_ub_o;
        localB->b_ix_i = 0;
        while (localB->b_ix_i <= localB->lastv) {
          if (localB->b_a_data[localB->jy] != 0.0) {
            localB->xnorm = localB->b_a_data[localB->jy] * -localB->
              tau_data[work_size_idx_0_tmp];
            localB->c_ix = 0;
            localB->g_f = localB->rowleft;
            localB->c_lastc = localB->knt + localB->rowleft;
            while (localB->g_f + 1 <= localB->c_lastc) {
              localB->b_a_data[localB->g_f] += localB->work_data[localB->c_ix] *
                localB->xnorm;
              localB->c_ix++;
              localB->g_f++;
            }
          }

          localB->jy++;
          localB->rowleft += localB->n_p;
          localB->b_ix_i++;
        }
      }
    }

    localB->lastv = (work_size_idx_0_tmp + localB->in) + 2;
    if (localB->tau_data[work_size_idx_0_tmp] != 0.0) {
      localB->in = c_lastc_tmp - 1;
      localB->c_lastc = (localB->loop_ub_o + c_lastc_tmp) - 1;
      while ((localB->in > 0) && (localB->b_a_data[localB->c_lastc - 1] == 0.0))
      {
        localB->in--;
        localB->c_lastc--;
      }

      localB->c_lastc = c_lastc_tmp - 1;
      exitg2 = false;
      while ((!exitg2) && (localB->c_lastc > 0)) {
        localB->knt = (localB->c_lastc - 1) * localB->n_p + localB->lastv;
        localB->rowleft = localB->knt;
        do {
          exitg1 = 0;
          if (localB->rowleft <= (localB->knt + localB->in) - 1) {
            if (localB->b_a_data[localB->rowleft - 1] != 0.0) {
              exitg1 = 1;
            } else {
              localB->rowleft++;
            }
          } else {
            localB->c_lastc--;
            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }

      localB->c_lastc--;
    } else {
      localB->in = 0;
      localB->c_lastc = -1;
    }

    if (localB->in > 0) {
      if (localB->c_lastc + 1 != 0) {
        localB->knt = 0;
        while (localB->knt <= localB->c_lastc) {
          localB->work_data[localB->knt] = 0.0;
          localB->knt++;
        }

        localB->knt = 0;
        localB->rowleft = localB->n_p * localB->c_lastc + localB->lastv;
        localB->jy = localB->lastv;
        while ((localB->n_p > 0) && (localB->jy <= localB->rowleft)) {
          localB->b_ix_i = localB->loop_ub_o;
          localB->xnorm = 0.0;
          localB->c_ix = (localB->jy + localB->in) - 1;
          localB->g_f = localB->jy;
          while (localB->g_f <= localB->c_ix) {
            localB->xnorm += localB->b_a_data[localB->g_f - 1] *
              localB->b_a_data[localB->b_ix_i];
            localB->b_ix_i++;
            localB->g_f++;
          }

          localB->work_data[localB->knt] += localB->xnorm;
          localB->knt++;
          localB->jy += localB->n_p;
        }
      }

      if (!(-localB->tau_data[work_size_idx_0_tmp] == 0.0)) {
        localB->lastv--;
        localB->knt = 0;
        localB->rowleft = 0;
        while (localB->rowleft <= localB->c_lastc) {
          if (localB->work_data[localB->knt] != 0.0) {
            localB->xnorm = localB->work_data[localB->knt] * -localB->
              tau_data[work_size_idx_0_tmp];
            localB->jy = localB->loop_ub_o;
            localB->b_ix_i = localB->lastv;
            localB->c_ix = localB->in + localB->lastv;
            while (localB->b_ix_i + 1 <= localB->c_ix) {
              localB->b_a_data[localB->b_ix_i] += localB->b_a_data[localB->jy] *
                localB->xnorm;
              localB->jy++;
              localB->b_ix_i++;
            }
          }

          localB->knt++;
          localB->lastv += localB->n_p;
          localB->rowleft++;
        }
      }
    }

    localB->b_a_data[alpha1_tmp] = localB->alpha1;
  }

  a_size[1] = b_a_size_idx_1;
  for (work_size_idx_0_tmp = 0; work_size_idx_0_tmp < b_a_size_idx_1;
       work_size_idx_0_tmp++) {
    for (localB->n_p = 0; localB->n_p < localB->b_a_size_idx_0; localB->n_p++) {
      a_data[localB->n_p + a_size[0] * work_size_idx_0_tmp] = localB->
        b_a_data[localB->b_a_size_idx_0 * work_size_idx_0_tmp + localB->n_p];
    }
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_xdlanv2(real_T *a, real_T *b, real_T *c, real_T *d, real_T *
  rt1r, real_T *rt1i, real_T *rt2r, real_T *rt2i, real_T *cs, real_T *sn,
  B_Lattice_planner_ros_code_T *localB)
{
  if (*c == 0.0) {
    *cs = 1.0;
    *sn = 0.0;
  } else if (*b == 0.0) {
    *cs = 0.0;
    *sn = 1.0;
    localB->bcmax = *d;
    *d = *a;
    *a = localB->bcmax;
    *b = -*c;
    *c = 0.0;
  } else {
    localB->tau = *a - *d;
    if ((localB->tau == 0.0) && ((*b < 0.0) != (*c < 0.0))) {
      *cs = 1.0;
      *sn = 0.0;
    } else {
      int32_T b_0;
      int32_T c_0;
      localB->p_j = 0.5 * localB->tau;
      localB->bcmis = std::abs(*b);
      localB->z = std::abs(*c);
      localB->bcmax = std::fmax(localB->bcmis, localB->z);
      if (!(*b < 0.0)) {
        b_0 = 1;
      } else {
        b_0 = -1;
      }

      if (!(*c < 0.0)) {
        c_0 = 1;
      } else {
        c_0 = -1;
      }

      localB->bcmis = std::fmin(localB->bcmis, localB->z) * static_cast<real_T>
        (b_0) * static_cast<real_T>(c_0);
      localB->scale_h = std::fmax(std::abs(localB->p_j), localB->bcmax);
      localB->z = localB->p_j / localB->scale_h * localB->p_j + localB->bcmax /
        localB->scale_h * localB->bcmis;
      if (localB->z >= 8.8817841970012523E-16) {
        if (!(localB->p_j < 0.0)) {
          localB->tau = std::sqrt(localB->scale_h) * std::sqrt(localB->z);
        } else {
          localB->tau = -(std::sqrt(localB->scale_h) * std::sqrt(localB->z));
        }

        localB->z = localB->p_j + localB->tau;
        *a = *d + localB->z;
        *d -= localB->bcmax / localB->z * localB->bcmis;
        localB->tau = ros_code_rt_hypotd_snf(*c, localB->z, localB);
        *cs = localB->z / localB->tau;
        *sn = *c / localB->tau;
        *b -= *c;
        *c = 0.0;
      } else {
        localB->bcmax = *b + *c;
        localB->tau = ros_code_rt_hypotd_snf(localB->bcmax, localB->tau, localB);
        *cs = std::sqrt((std::abs(localB->bcmax) / localB->tau + 1.0) * 0.5);
        if (!(localB->bcmax < 0.0)) {
          b_0 = 1;
        } else {
          b_0 = -1;
        }

        *sn = -(localB->p_j / (localB->tau * *cs)) * static_cast<real_T>(b_0);
        localB->p_j = *a * *cs + *b * *sn;
        localB->tau = -*a * *sn + *b * *cs;
        localB->bcmax = *c * *cs + *d * *sn;
        localB->bcmis = -*c * *sn + *d * *cs;
        *b = localB->tau * *cs + localB->bcmis * *sn;
        *c = -localB->p_j * *sn + localB->bcmax * *cs;
        localB->bcmax = ((localB->p_j * *cs + localB->bcmax * *sn) +
                         (-localB->tau * *sn + localB->bcmis * *cs)) * 0.5;
        *a = localB->bcmax;
        *d = localB->bcmax;
        if (*c != 0.0) {
          if (*b != 0.0) {
            if ((*b < 0.0) == (*c < 0.0)) {
              localB->z = std::sqrt(std::abs(*b));
              localB->bcmis = std::sqrt(std::abs(*c));
              if (!(*c < 0.0)) {
                localB->p_j = localB->z * localB->bcmis;
              } else {
                localB->p_j = -(localB->z * localB->bcmis);
              }

              localB->tau = 1.0 / std::sqrt(std::abs(*b + *c));
              *a = localB->bcmax + localB->p_j;
              *d = localB->bcmax - localB->p_j;
              *b -= *c;
              *c = 0.0;
              localB->p_j = localB->z * localB->tau;
              localB->tau *= localB->bcmis;
              localB->bcmax = *cs * localB->p_j - *sn * localB->tau;
              *sn = *cs * localB->tau + *sn * localB->p_j;
              *cs = localB->bcmax;
            }
          } else {
            *b = -*c;
            *c = 0.0;
            localB->bcmax = *cs;
            *cs = -*sn;
            *sn = localB->bcmax;
          }
        }
      }
    }
  }

  *rt1r = *a;
  *rt2r = *d;
  if (*c == 0.0) {
    *rt1i = 0.0;
    *rt2i = 0.0;
  } else {
    *rt1i = std::sqrt(std::abs(*b)) * std::sqrt(std::abs(*c));
    *rt2i = -*rt1i;
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static real_T ros_code_xnrm2(int32_T n, const real_T x[3],
  B_Lattice_planner_ros_code_T *localB)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = std::abs(x[1]);
    } else {
      localB->scale_o = 3.3121686421112381E-170;
      localB->absxk_l = std::abs(x[1]);
      if (localB->absxk_l > 3.3121686421112381E-170) {
        y = 1.0;
        localB->scale_o = localB->absxk_l;
      } else {
        localB->t_mv = localB->absxk_l / 3.3121686421112381E-170;
        y = localB->t_mv * localB->t_mv;
      }

      localB->absxk_l = std::abs(x[2]);
      if (localB->absxk_l > localB->scale_o) {
        localB->t_mv = localB->scale_o / localB->absxk_l;
        y = y * localB->t_mv * localB->t_mv + 1.0;
        localB->scale_o = localB->absxk_l;
      } else {
        localB->t_mv = localB->absxk_l / localB->scale_o;
        y += localB->t_mv * localB->t_mv;
      }

      y = localB->scale_o * std::sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S3>/reducePath'
static real_T ros_code_xzlarfg(int32_T n, real_T *alpha1, real_T x[3],
  B_Lattice_planner_ros_code_T *localB)
{
  real_T tau;
  tau = 0.0;
  if (n > 0) {
    localB->xnorm_g = ros_code_xnrm2(n - 1, x, localB);
    if (localB->xnorm_g != 0.0) {
      localB->xnorm_g = ros_code_rt_hypotd_snf(*alpha1, localB->xnorm_g, localB);
      if (*alpha1 >= 0.0) {
        localB->xnorm_g = -localB->xnorm_g;
      }

      if (std::abs(localB->xnorm_g) < 1.0020841800044864E-292) {
        int32_T knt;
        knt = 0;
        do {
          knt++;
          for (int32_T c_k{1}; c_k < n; c_k++) {
            x[c_k] *= 9.9792015476736E+291;
          }

          localB->xnorm_g *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while ((std::abs(localB->xnorm_g) < 1.0020841800044864E-292) && (knt <
                  20));

        localB->xnorm_g = ros_code_rt_hypotd_snf(*alpha1, ros_code_xnrm2(n - 1,
          x, localB), localB);
        if (*alpha1 >= 0.0) {
          localB->xnorm_g = -localB->xnorm_g;
        }

        tau = (localB->xnorm_g - *alpha1) / localB->xnorm_g;
        localB->a_c = 1.0 / (*alpha1 - localB->xnorm_g);
        for (int32_T c_k{1}; c_k < n; c_k++) {
          x[c_k] *= localB->a_c;
        }

        for (int32_T c_k{0}; c_k < knt; c_k++) {
          localB->xnorm_g *= 1.0020841800044864E-292;
        }

        *alpha1 = localB->xnorm_g;
      } else {
        tau = (localB->xnorm_g - *alpha1) / localB->xnorm_g;
        localB->a_c = 1.0 / (*alpha1 - localB->xnorm_g);
        for (int32_T knt{1}; knt < n; knt++) {
          x[knt] *= localB->a_c;
        }

        *alpha1 = localB->xnorm_g;
      }
    }
  }

  return tau;
}

// Function for MATLAB Function: '<S3>/reducePath'
static int32_T ros_code_xhseqr(real_T h_data[], const int32_T h_size[2],
  B_Lattice_planner_ros_code_T *localB)
{
  int32_T info;
  localB->n_o = h_size[0];
  localB->ldh = h_size[0];
  info = 0;
  if (h_size[0] != 1) {
    boolean_T exitg1;
    localB->v[0] = 0.0;
    localB->v[1] = 0.0;
    localB->v[2] = 0.0;
    if (h_size[0] - 2 >= 1) {
      h_data[h_size[0] - 1] = 0.0;
    }

    localB->SMLNUM = static_cast<real_T>(h_size[0]) / 2.2204460492503131E-16 *
      2.2250738585072014E-308;
    localB->i_n = h_size[0] - 2;
    exitg1 = false;
    while ((!exitg1) && (localB->i_n + 2 >= 1)) {
      boolean_T exitg2;
      boolean_T goto150;
      localB->L = 1;
      goto150 = false;
      localB->b_ix = 0;
      exitg2 = false;
      while ((!exitg2) && (localB->b_ix < 301)) {
        boolean_T exitg3;
        localB->k_l = localB->i_n;
        exitg3 = false;
        while ((!exitg3) && (localB->k_l + 2 > 1)) {
          localB->tst_tmp_p = h_size[0] * localB->k_l;
          localB->L = (localB->k_l + localB->tst_tmp_p) + 1;
          if (std::abs(h_data[localB->L]) <= localB->SMLNUM) {
            exitg3 = true;
          } else {
            localB->nr = (localB->k_l + 1) * h_size[0];
            localB->tst_tmp = (localB->k_l + localB->nr) + 1;
            localB->tst_tmp_p += localB->k_l;
            localB->tst = std::abs(h_data[localB->tst_tmp]) + std::abs
              (h_data[localB->tst_tmp_p]);
            if (localB->tst == 0.0) {
              if (localB->k_l >= 1) {
                localB->tst = std::abs(h_data[(localB->k_l - 1) * h_size[0] +
                  localB->k_l]);
              }

              if (localB->k_l + 3 <= localB->n_o) {
                localB->tst += std::abs(h_data[(localB->k_l + localB->nr) + 2]);
              }
            }

            if (std::abs(h_data[localB->L]) <= 2.2204460492503131E-16 *
                localB->tst) {
              localB->htmp1 = std::abs(h_data[localB->L]);
              localB->tst = std::abs(h_data[localB->k_l + localB->nr]);
              if (localB->htmp1 > localB->tst) {
                localB->ab = localB->htmp1;
                localB->ba = localB->tst;
              } else {
                localB->ab = localB->tst;
                localB->ba = localB->htmp1;
              }

              localB->tst = h_data[localB->tst_tmp];
              localB->htmp1 = std::abs(localB->tst);
              localB->tst = std::abs(h_data[localB->tst_tmp_p] - localB->tst);
              if (localB->htmp1 > localB->tst) {
                localB->aa = localB->htmp1;
                localB->htmp1 = localB->tst;
              } else {
                localB->aa = localB->tst;
              }

              localB->tst = localB->aa + localB->ab;
              if (localB->ab / localB->tst * localB->ba <= std::fmax
                  (localB->SMLNUM, localB->aa / localB->tst * localB->htmp1 *
                   2.2204460492503131E-16)) {
                exitg3 = true;
              } else {
                localB->k_l--;
              }
            } else {
              localB->k_l--;
            }
          }
        }

        localB->L = localB->k_l + 2;
        if (localB->k_l + 2 > 1) {
          h_data[(localB->k_l + h_size[0] * localB->k_l) + 1] = 0.0;
        }

        if (localB->k_l + 2 >= localB->i_n + 1) {
          goto150 = true;
          exitg2 = true;
        } else {
          switch (localB->b_ix) {
           case 10:
            localB->tst = std::abs(h_data[2 + h_size[0]]) + std::abs(h_data[1]);
            localB->ab = 0.75 * localB->tst + h_data[0];
            localB->h12 = -0.4375 * localB->tst;
            localB->aa = localB->tst;
            localB->htmp1 = localB->ab;
            break;

           case 20:
            localB->tst = std::abs(h_data[(h_size[0] * localB->i_n + localB->i_n)
              + 1]) + std::abs(h_data[localB->i_n]);
            localB->ab = h_data[((localB->i_n + 1) * h_size[0] + localB->i_n) +
              1] + 0.75 * localB->tst;
            localB->h12 = -0.4375 * localB->tst;
            localB->aa = localB->tst;
            localB->htmp1 = localB->ab;
            break;

           default:
            localB->ab = h_data[h_size[0] * localB->i_n + localB->i_n];
            localB->aa = h_data[(h_size[0] * localB->i_n + localB->i_n) + 1];
            localB->h12 = h_data[(localB->i_n + 1) * h_size[0] + localB->i_n];
            localB->htmp1 = h_data[((localB->i_n + 1) * h_size[0] + localB->i_n)
              + 1];
            break;
          }

          localB->tst = ((std::abs(localB->ab) + std::abs(localB->h12)) + std::
                         abs(localB->aa)) + std::abs(localB->htmp1);
          if (localB->tst == 0.0) {
            localB->ab = 0.0;
            localB->htmp1 = 0.0;
            localB->ba = 0.0;
            localB->aa = 0.0;
          } else {
            localB->ab /= localB->tst;
            localB->htmp1 /= localB->tst;
            localB->ba = (localB->ab + localB->htmp1) / 2.0;
            localB->ab = (localB->ab - localB->ba) * (localB->htmp1 - localB->ba)
              - localB->h12 / localB->tst * (localB->aa / localB->tst);
            localB->aa = std::sqrt(std::abs(localB->ab));
            if (localB->ab >= 0.0) {
              localB->ab = localB->ba * localB->tst;
              localB->ba = localB->ab;
              localB->htmp1 = localB->aa * localB->tst;
              localB->aa = -localB->htmp1;
            } else {
              localB->ab = localB->ba + localB->aa;
              localB->ba -= localB->aa;
              if (std::abs(localB->ab - localB->htmp1) <= std::abs(localB->ba -
                   localB->htmp1)) {
                localB->ab *= localB->tst;
                localB->ba = localB->ab;
              } else {
                localB->ba *= localB->tst;
                localB->ab = localB->ba;
              }

              localB->htmp1 = 0.0;
              localB->aa = 0.0;
            }
          }

          if (localB->i_n >= 1) {
            localB->tst_tmp = 0;
            localB->h12 = h_data[localB->tst_tmp] - localB->ba;
            localB->nr = localB->i_n;
            localB->tst = (std::abs(localB->h12) + std::abs(localB->aa)) + std::
              abs(h_data[localB->nr]);
            localB->h21s = h_data[localB->nr] / localB->tst;
            localB->v_tmp = h_data[localB->tst_tmp];
            localB->v[0] = (localB->h12 / localB->tst * (localB->v_tmp -
              localB->ab) + h_data[h_size[0] * localB->i_n] * localB->h21s) -
              localB->aa / localB->tst * localB->htmp1;
            localB->v[1] = (((h_data[h_size[0] * localB->i_n + localB->i_n] +
                              localB->v_tmp) - localB->ab) - localB->ba) *
              localB->h21s;
            localB->v[2] = h_data[(h_size[0] * localB->i_n + localB->i_n) + 1] *
              localB->h21s;
            localB->tst = (std::abs(localB->v[0]) + std::abs(localB->v[1])) +
              std::abs(localB->v[2]);
            localB->v[0] /= localB->tst;
            localB->v[1] /= localB->tst;
            localB->v[2] /= localB->tst;
          }

          localB->k_l = localB->i_n;
          while (localB->k_l <= localB->i_n + 1) {
            localB->nr = (localB->i_n - localB->k_l) + 3;
            if (localB->nr >= 3) {
              localB->nr = 3;
            }

            if (localB->k_l > localB->i_n) {
              localB->hoffset = (localB->k_l - 2) * localB->ldh + localB->k_l;
              localB->tst_tmp = 0;
              while (localB->tst_tmp <= localB->nr - 1) {
                localB->v[localB->tst_tmp] = h_data[(localB->tst_tmp +
                  localB->hoffset) - 1];
                localB->tst_tmp++;
              }
            }

            localB->htmp1 = localB->v[0];
            localB->tst = ros_code_xzlarfg(localB->nr, &localB->htmp1, localB->v,
              localB);
            localB->v[0] = localB->htmp1;
            if (localB->k_l > localB->i_n) {
              h_data[localB->k_l - 1] = localB->htmp1;
              h_data[localB->k_l] = 0.0;
              if (localB->k_l < localB->i_n + 1) {
                h_data[2 - h_size[0]] = 0.0;
              }
            }

            localB->htmp1 = localB->v[1];
            localB->ab = localB->tst * localB->v[1];
            switch (localB->nr) {
             case 3:
              {
                int32_T h21s_tmp;
                localB->ba = localB->v[2];
                localB->aa = localB->tst * localB->v[2];
                localB->nr = localB->k_l - 1;
                while (localB->nr + 1 <= localB->n_o) {
                  localB->tst_tmp_p = h_size[0] * localB->nr;
                  h21s_tmp = (localB->k_l + localB->tst_tmp_p) - 1;
                  localB->tst_tmp = localB->k_l + localB->tst_tmp_p;
                  localB->h21s = (localB->htmp1 * h_data[localB->tst_tmp] +
                                  h_data[h21s_tmp]) + h_data[2 +
                    localB->tst_tmp_p] * localB->ba;
                  h_data[h21s_tmp] -= localB->h21s * localB->tst;
                  h_data[localB->tst_tmp] -= localB->h21s * localB->ab;
                  h_data[2 + localB->tst_tmp_p] -= localB->h21s * localB->aa;
                  localB->nr++;
                }

                if (localB->k_l + 3 <= localB->i_n + 2) {
                  localB->nr = localB->k_l + 3;
                } else {
                  localB->nr = localB->i_n + 2;
                }

                localB->hoffset = 0;
                while (localB->hoffset <= localB->nr - 1) {
                  localB->tst_tmp = (localB->k_l - 1) * h_size[0] +
                    localB->hoffset;
                  localB->h12 = h_data[localB->tst_tmp];
                  localB->tst_tmp_p = h_size[0] * localB->k_l + localB->hoffset;
                  h21s_tmp = (h_size[0] << 1) + localB->hoffset;
                  localB->h21s = (localB->htmp1 * h_data[localB->tst_tmp_p] +
                                  localB->h12) + localB->ba * h_data[h21s_tmp];
                  h_data[localB->tst_tmp] = localB->h12 - localB->h21s *
                    localB->tst;
                  h_data[localB->tst_tmp_p] -= localB->h21s * localB->ab;
                  h_data[h21s_tmp] -= localB->h21s * localB->aa;
                  localB->hoffset++;
                }
              }
              break;

             case 2:
              {
                localB->nr = localB->k_l - 1;
                while (localB->nr + 1 <= localB->n_o) {
                  localB->tst_tmp = h_size[0] * localB->nr;
                  localB->hoffset = (localB->k_l + localB->tst_tmp) - 1;
                  localB->h12 = h_data[localB->hoffset];
                  localB->tst_tmp_p = localB->k_l + localB->tst_tmp;
                  localB->h21s = localB->htmp1 * h_data[localB->tst_tmp_p] +
                    localB->h12;
                  h_data[localB->hoffset] = localB->h12 - localB->h21s *
                    localB->tst;
                  h_data[localB->tst_tmp_p] -= localB->h21s * localB->ab;
                  localB->nr++;
                }

                localB->nr = 0;
                while (localB->nr <= localB->i_n + 1) {
                  int32_T h21s_tmp;
                  localB->tst_tmp_p = (localB->k_l - 1) * h_size[0] + localB->nr;
                  h21s_tmp = h_size[0] * localB->k_l + localB->nr;
                  localB->h21s = localB->htmp1 * h_data[h21s_tmp] +
                    h_data[localB->tst_tmp_p];
                  h_data[localB->tst_tmp_p] -= localB->h21s * localB->tst;
                  h_data[h21s_tmp] -= localB->h21s * localB->ab;
                  localB->nr++;
                }
              }
              break;
            }

            localB->k_l++;
          }

          localB->b_ix++;
        }
      }

      if (!goto150) {
        info = localB->i_n + 2;
        exitg1 = true;
      } else {
        if ((localB->i_n + 2 != localB->L) && (localB->i_n + 1 == localB->L)) {
          localB->nr = (localB->i_n + 1) * h_size[0];
          localB->b_ix = localB->i_n + localB->nr;
          localB->ab = h_data[localB->b_ix];
          localB->k_l = (h_size[0] * localB->i_n + localB->i_n) + 1;
          localB->ba = h_data[localB->k_l];
          localB->nr = (localB->i_n + localB->nr) + 1;
          localB->aa = h_data[localB->nr];
          ros_code_xdlanv2(&h_data[localB->i_n + h_size[0] * localB->i_n],
                           &localB->ab, &localB->ba, &localB->aa, &localB->h12,
                           &localB->h21s, &localB->v_tmp, &localB->a__4,
                           &localB->tst, &localB->htmp1, localB);
          h_data[localB->b_ix] = localB->ab;
          h_data[localB->k_l] = localB->ba;
          h_data[localB->nr] = localB->aa;
          if (localB->n_o > localB->i_n + 2) {
            localB->b_ix = (localB->n_o - localB->i_n) - 3;
            if (localB->b_ix + 1 >= 1) {
              localB->k_l = (localB->i_n + 2) * localB->ldh + localB->i_n;
              localB->nr = localB->k_l + 1;
              localB->hoffset = 0;
              while (localB->hoffset <= localB->b_ix) {
                localB->ab = h_data[localB->k_l] * localB->tst + h_data
                  [localB->nr] * localB->htmp1;
                h_data[localB->nr] = h_data[localB->nr] * localB->tst -
                  h_data[localB->k_l] * localB->htmp1;
                h_data[localB->k_l] = localB->ab;
                localB->nr += localB->ldh;
                localB->k_l += localB->ldh;
                localB->hoffset++;
              }
            }
          }

          if (localB->i_n >= 1) {
            localB->b_ix = localB->i_n * localB->ldh;
            localB->i_n = (localB->i_n + 1) * localB->ldh;
            localB->ab = h_data[localB->b_ix] * localB->tst + h_data[localB->i_n]
              * localB->htmp1;
            h_data[localB->i_n] = h_data[localB->i_n] * localB->tst -
              h_data[localB->b_ix] * localB->htmp1;
            h_data[localB->b_ix] = localB->ab;
          }
        }

        localB->i_n = localB->L - 3;
      }
    }
  }

  return info;
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_schur(real_T A_data[], int32_T A_size[2], real_T V_data[],
  int32_T V_size[2], B_Lattice_planner_ros_code_T *localB)
{
  if (ros_code_anyNonFinite(A_data, A_size)) {
    int8_T b_idx_0;
    b_idx_0 = static_cast<int8_T>(A_size[0]);
    V_size[0] = static_cast<int8_T>(A_size[0]);
    V_size[1] = static_cast<int8_T>(A_size[1]);
    localB->istart = static_cast<int8_T>(A_size[0]) * static_cast<int8_T>
      (A_size[1]) - 1;
    for (localB->i_m = 0; localB->i_m <= localB->istart; localB->i_m++) {
      V_data[localB->i_m] = (rtNaN);
    }

    if (static_cast<int8_T>(A_size[0]) > 1) {
      localB->istart = 2;
      if (static_cast<int8_T>(A_size[0]) - 2 <= static_cast<int8_T>(A_size[1]) -
          1) {
        localB->jend = static_cast<int8_T>(A_size[0]) - 2;
      } else {
        localB->jend = static_cast<int8_T>(A_size[1]) - 1;
      }

      localB->V = 0;
      while (localB->V <= localB->jend) {
        localB->i_m = localB->istart;
        while (localB->i_m <= b_idx_0) {
          V_data[(localB->i_m + V_size[0] * localB->V) - 1] = 0.0;
          localB->i_m++;
        }

        localB->istart++;
        localB->V++;
      }
    }
  } else {
    ros_code_xgehrd(A_data, A_size, localB);
    V_size[0] = A_size[0];
    V_size[1] = A_size[1];
    localB->istart = A_size[0] * A_size[1];
    if (localB->istart - 1 >= 0) {
      std::memcpy(&V_data[0], &A_data[0], localB->istart * sizeof(real_T));
    }

    ros_code_xhseqr(V_data, V_size, localB);
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_eig(const real_T A_data[], const int32_T A_size[2], creal_T
  V_data[], int32_T *V_size, B_Lattice_planner_ros_code_T *localB)
{
  if (ros_code_anyNonFinite(A_data, A_size)) {
    localB->c_i = A_size[0];
    *V_size = A_size[0];
    for (localB->n = 0; localB->n < localB->c_i; localB->n++) {
      V_data[localB->n].re = (rtNaN);
      V_data[localB->n].im = 0.0;
    }
  } else {
    int32_T exitg1;
    boolean_T c_p;
    boolean_T exitg2;
    c_p = (A_size[0] == A_size[1]);
    if (c_p) {
      localB->n = 0;
      exitg2 = false;
      while ((!exitg2) && (localB->n <= A_size[1] - 1)) {
        localB->c_i = 0;
        do {
          exitg1 = 0;
          if (localB->c_i <= localB->n) {
            if (!(A_data[A_size[0] * localB->n + localB->c_i] == A_data[A_size[0]
                  * localB->c_i + localB->n])) {
              c_p = false;
              exitg1 = 1;
            } else {
              localB->c_i++;
            }
          } else {
            localB->n++;
            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }
    }

    if (c_p) {
      localB->A_size[0] = A_size[0];
      localB->A_size[1] = A_size[1];
      localB->n = A_size[0] * A_size[1] - 1;
      if (localB->n >= 0) {
        std::memcpy(&localB->A_data[0], &A_data[0], (localB->n + 1) * sizeof
                    (real_T));
      }

      ros_code_schur(localB->A_data, localB->A_size, localB->T_data,
                     localB->T_size, localB);
      localB->c_i = localB->T_size[0];
      localB->n = 0;
      while (localB->n <= localB->T_size[0] - 1) {
        localB->b_V_data[localB->n] = localB->T_data[localB->T_size[0] *
          localB->n + localB->n];
        localB->n++;
      }

      *V_size = localB->T_size[0];
      for (localB->n = 0; localB->n < localB->c_i; localB->n++) {
        V_data[localB->n].re = localB->b_V_data[localB->n];
        V_data[localB->n].im = 0.0;
      }
    } else {
      c_p = (A_size[0] == A_size[1]);
      if (c_p) {
        localB->n = 0;
        exitg2 = false;
        while ((!exitg2) && (localB->n <= A_size[1] - 1)) {
          localB->c_i = 0;
          do {
            exitg1 = 0;
            if (localB->c_i <= localB->n) {
              if (!(A_data[A_size[0] * localB->n + localB->c_i] ==
                    -A_data[A_size[0] * localB->c_i + localB->n])) {
                c_p = false;
                exitg1 = 1;
              } else {
                localB->c_i++;
              }
            } else {
              localB->n++;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      }

      if (c_p) {
        localB->A_size[0] = A_size[0];
        localB->A_size[1] = A_size[1];
        localB->n = A_size[0] * A_size[1] - 1;
        if (localB->n >= 0) {
          std::memcpy(&localB->A_data[0], &A_data[0], (localB->n + 1) * sizeof
                      (real_T));
        }

        ros_code_schur(localB->A_data, localB->A_size, localB->T_data,
                       localB->T_size, localB);
        localB->n = localB->T_size[0];
        *V_size = localB->T_size[0];
        localB->c_i = 1;
        do {
          exitg1 = 0;
          if (localB->c_i <= localB->n) {
            boolean_T guard1{ false };

            guard1 = false;
            if (localB->c_i != localB->n) {
              localB->lambda = localB->T_data[(localB->c_i - 1) * localB->
                T_size[0] + localB->c_i];
              if (localB->lambda != 0.0) {
                localB->lambda = std::abs(localB->lambda);
                V_data[localB->c_i - 1].re = 0.0;
                V_data[localB->c_i - 1].im = localB->lambda;
                V_data[localB->c_i].re = 0.0;
                V_data[localB->c_i].im = -localB->lambda;
                localB->c_i += 2;
              } else {
                guard1 = true;
              }
            } else {
              guard1 = true;
            }

            if (guard1) {
              V_data[localB->c_i - 1].re = 0.0;
              V_data[localB->c_i - 1].im = 0.0;
              localB->c_i++;
            }
          } else {
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      } else {
        ros_code_eigStandard(A_data, A_size, V_data, V_size, localB);
      }
    }
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_roots(const real_T c[3], creal_T r_data[], int32_T *r_size,
  B_Lattice_planner_ros_code_T *localB)
{
  r_data[0].re = 0.0;
  r_data[0].im = 0.0;
  r_data[1].re = 0.0;
  r_data[1].im = 0.0;
  localB->k1_c = 1;
  while ((localB->k1_c <= 3) && (!(c[localB->k1_c - 1] != 0.0))) {
    localB->k1_c++;
  }

  localB->k2_a = 3;
  while ((localB->k2_a >= localB->k1_c) && (!(c[localB->k2_a - 1] != 0.0))) {
    localB->k2_a--;
  }

  if (localB->k1_c < localB->k2_a) {
    boolean_T exitg1;
    localB->companDim_d = localB->k2_a - localB->k1_c;
    exitg1 = false;
    while ((!exitg1) && (localB->companDim_d > 0)) {
      boolean_T exitg2;
      localB->j_a = 0;
      exitg2 = false;
      while ((!exitg2) && (localB->j_a + 1 <= localB->companDim_d)) {
        localB->ctmp_g[localB->j_a] = c[localB->k1_c + localB->j_a] / c
          [localB->k1_c - 1];
        if (std::isinf(std::abs(localB->ctmp_g[localB->j_a]))) {
          exitg2 = true;
        } else {
          localB->j_a++;
        }
      }

      if (localB->j_a + 1 > localB->companDim_d) {
        exitg1 = true;
      } else {
        localB->k1_c++;
        localB->companDim_d--;
      }
    }

    if (localB->companDim_d < 1) {
      if (3 - localB->k2_a < 1) {
        *r_size = 0;
      } else {
        *r_size = 3 - localB->k2_a;
      }
    } else {
      localB->a_size_c[0] = localB->companDim_d;
      localB->a_size_c[1] = localB->companDim_d;
      localB->k1_c = localB->companDim_d * localB->companDim_d - 1;
      std::memset(&localB->a_data_j[0], 0, (localB->k1_c + 1) * sizeof(real_T));
      localB->k1_c = 0;
      while (localB->k1_c <= localB->companDim_d - 2) {
        localB->a_data_j[0] = -localB->ctmp_g[0];
        localB->a_data_j[1] = 1.0;
        localB->k1_c = 1;
      }

      localB->a_data_j[localB->companDim_d * (localB->companDim_d - 1)] =
        -localB->ctmp_g[localB->companDim_d - 1];
      if (2 - localB->k2_a >= 0) {
        r_data[0].re = 0.0;
        r_data[0].im = 0.0;
      }

      ros_code_eig(localB->a_data_j, localB->a_size_c, localB->f_data_l,
                   &localB->f_size_p, localB);
      localB->k1_c = 0;
      while (localB->k1_c <= localB->companDim_d - 1) {
        r_data[(localB->k1_c - localB->k2_a) + 3] = localB->f_data_l
          [localB->k1_c];
        localB->k1_c++;
      }

      *r_size = (localB->companDim_d - localB->k2_a) + 3;
    }
  } else if (3 - localB->k2_a < 1) {
    *r_size = 0;
  } else {
    *r_size = 3 - localB->k2_a;
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_power_i(const real_T a_data[], const int32_T a_size[2],
  real_T y_data[], int32_T y_size[2], B_Lattice_planner_ros_code_T *localB)
{
  y_size[0] = 1;
  y_size[1] = a_size[1];
  localB->k = 0;
  while (localB->k <= a_size[1] - 1) {
    localB->y_data_tmp_o = localB->k;
    localB->y_data_tmp = a_data[localB->y_data_tmp_o];
    y_data[localB->y_data_tmp_o] = localB->y_data_tmp * localB->y_data_tmp;
    localB->k++;
  }
}

static void ros_code_binary_expand_op_f(real_T in1_data[], int32_T in1_size[2],
  const real_T in2[30], int32_T in3, const real_T in4_data[], const int32_T
  in4_size[2], const real_T in5_data[], const int32_T in5_size[2],
  B_Lattice_planner_ros_code_T *localB)
{
  __m128d tmp;

  // MATLAB Function: '<S3>/reducePath'
  localB->in2 = in2[in3];
  localB->in2_size[0] = 1;
  localB->in2_size[1] = in4_size[1];
  localB->loop_ub_e = in4_size[1];
  localB->scalarLB = (in4_size[1] / 2) << 1;
  localB->vectorUB = localB->scalarLB - 2;

  // MATLAB Function: '<S3>/reducePath'
  for (localB->i1 = 0; localB->i1 <= localB->vectorUB; localB->i1 += 2) {
    localB->i2 = localB->i1;
    tmp = _mm_loadu_pd(&in4_data[localB->i2]);
    _mm_storeu_pd(&localB->in2_data[localB->i2], _mm_sub_pd(_mm_set1_pd
      (localB->in2), tmp));
  }

  for (localB->i1 = localB->scalarLB; localB->i1 < localB->loop_ub_e; localB->i1
       ++) {
    localB->vectorUB = localB->i1;
    localB->in2_data[localB->vectorUB] = localB->in2 - in4_data[localB->vectorUB];
  }

  ros_code_power_i(localB->in2_data, localB->in2_size, localB->tmp_data_g,
                   localB->tmp_size_mc, localB);
  localB->in2 = in2[in3 + 10];
  localB->in2_size[0] = 1;
  localB->in2_size[1] = in5_size[1];
  localB->loop_ub_e = in5_size[1];
  localB->scalarLB = (in5_size[1] / 2) << 1;
  localB->vectorUB = localB->scalarLB - 2;

  // MATLAB Function: '<S3>/reducePath'
  for (localB->i1 = 0; localB->i1 <= localB->vectorUB; localB->i1 += 2) {
    localB->i2 = localB->i1;
    tmp = _mm_loadu_pd(&in5_data[localB->i2]);
    _mm_storeu_pd(&localB->in2_data[localB->i2], _mm_sub_pd(_mm_set1_pd
      (localB->in2), tmp));
  }

  for (localB->i1 = localB->scalarLB; localB->i1 < localB->loop_ub_e; localB->i1
       ++) {
    localB->vectorUB = localB->i1;
    localB->in2_data[localB->vectorUB] = localB->in2 - in5_data[localB->vectorUB];
  }

  ros_code_power_i(localB->in2_data, localB->in2_size, localB->tmp_data_g1,
                   localB->tmp_size_h, localB);
  in1_size[0] = 1;
  in1_size[1] = localB->tmp_size_h[1] == 1 ? localB->tmp_size_mc[1] :
    localB->tmp_size_h[1];
  localB->scalarLB = (localB->tmp_size_mc[1] != 1);
  localB->vectorUB = (localB->tmp_size_h[1] != 1);
  localB->loop_ub_e = localB->tmp_size_h[1] == 1 ? localB->tmp_size_mc[1] :
    localB->tmp_size_h[1];
  for (localB->i1 = 0; localB->i1 < localB->loop_ub_e; localB->i1++) {
    in1_data[localB->i1] = localB->tmp_data_g[localB->i1 * localB->scalarLB] +
      localB->tmp_data_g1[localB->i1 * localB->vectorUB];
  }
}

static void ros_cod_binary_expand_op_fhook5(real_T in1_data[], int32_T *in1_size,
  const real_T in2_data[], const int32_T *in2_size, const real_T in3[4], int32_T
  in4, B_Lattice_planner_ros_code_T *localB)
{
  localB->in3_ax = in3[in4 + 1];
  localB->in2_size_idx_0_n = *in1_size == 1 ? *in2_size : *in1_size;
  localB->stride_0_0_p = (*in2_size != 1);
  localB->stride_1_0_b = (*in1_size != 1);
  localB->loop_ub_c = *in1_size == 1 ? *in2_size : *in1_size;
  for (localB->i10 = 0; localB->i10 < localB->loop_ub_c; localB->i10++) {
    localB->in2_data_d[localB->i10] = in2_data[localB->i10 *
      localB->stride_0_0_p] * in1_data[localB->i10 * localB->stride_1_0_b] +
      localB->in3_ax;
  }

  *in1_size = localB->in2_size_idx_0_n;
  if (localB->in2_size_idx_0_n - 1 >= 0) {
    std::memcpy(&in1_data[0], &localB->in2_data_d[0], localB->in2_size_idx_0_n *
                sizeof(real_T));
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_polyval_d(const real_T p[4], const real_T x_data[], const
  int32_T *x_size, real_T y_data[], int32_T *y_size,
  B_Lattice_planner_ros_code_T *localB)
{
  *y_size = *x_size;
  if (*x_size != 0) {
    localB->y_idx_0_m = *x_size;
    *y_size = *x_size;
    for (localB->i9 = 0; localB->i9 < localB->y_idx_0_m; localB->i9++) {
      y_data[localB->i9] = p[0];
    }

    for (localB->y_idx_0_m = 0; localB->y_idx_0_m < 3; localB->y_idx_0_m++) {
      if (*x_size == *y_size) {
        localB->p_e = p[localB->y_idx_0_m + 1];
        *y_size = *x_size;
        localB->loop_ub_h = *x_size;
        localB->scalarLB_ad = (*x_size / 2) << 1;
        localB->vectorUB_k = localB->scalarLB_ad - 2;
        for (localB->i9 = 0; localB->i9 <= localB->vectorUB_k; localB->i9 += 2)
        {
          __m128d tmp;
          tmp = _mm_loadu_pd(&y_data[localB->i9]);
          _mm_storeu_pd(&y_data[localB->i9], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(
            &x_data[localB->i9]), tmp), _mm_set1_pd(localB->p_e)));
        }

        for (localB->i9 = localB->scalarLB_ad; localB->i9 < localB->loop_ub_h;
             localB->i9++) {
          y_data[localB->i9] = x_data[localB->i9] * y_data[localB->i9] +
            localB->p_e;
        }
      } else {
        ros_cod_binary_expand_op_fhook5(y_data, y_size, x_data, x_size, p,
          localB->y_idx_0_m, localB);
      }
    }
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_abs(const real_T x_data[], const int32_T *x_size, real_T
  y_data[], int32_T *y_size)
{
  *y_size = *x_size;
  for (int32_T k{0}; k < *x_size; k++) {
    y_data[k] = std::abs(x_data[k]);
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static real_T ros_code_maximum(const real_T x_data[], const int32_T *x_size)
{
  real_T ex;
  if (*x_size <= 2) {
    if (*x_size == 1) {
      ex = x_data[0];
    } else {
      ex = x_data[*x_size - 1];
      if (x_data[0] < ex) {
      } else if (std::isnan(x_data[0])) {
        if (!std::isnan(ex)) {
        } else {
          ex = x_data[0];
        }
      } else {
        ex = x_data[0];
      }
    }
  } else {
    int32_T idx;
    if (!std::isnan(x_data[0])) {
      idx = 1;
    } else {
      int32_T k;
      boolean_T exitg1;
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= *x_size)) {
        if (!std::isnan(x_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      ex = x_data[0];
    } else {
      ex = x_data[idx - 1];
      while (idx + 1 <= *x_size) {
        if (ex < x_data[idx]) {
          ex = x_data[idx];
        }

        idx++;
      }
    }
  }

  return ex;
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_minimum(const real_T x_data[], const int32_T *x_size,
  real_T *ex, int32_T *idx)
{
  if (*x_size <= 2) {
    if (*x_size == 1) {
      *ex = x_data[0];
      *idx = 1;
    } else {
      *ex = x_data[*x_size - 1];
      if ((x_data[0] > *ex) || (std::isnan(x_data[0]) && (!std::isnan(*ex)))) {
        *idx = *x_size;
      } else {
        *ex = x_data[0];
        *idx = 1;
      }
    }
  } else {
    int32_T k;
    if (!std::isnan(x_data[0])) {
      *idx = 1;
    } else {
      boolean_T exitg1;
      *idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= *x_size)) {
        if (!std::isnan(x_data[k - 1])) {
          *idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (*idx == 0) {
      *ex = x_data[0];
      *idx = 1;
    } else {
      *ex = x_data[*idx - 1];
      for (k = *idx; k < *x_size; k++) {
        if (*ex > x_data[k]) {
          *ex = x_data[k];
          *idx = k + 1;
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static real_T ros_code_findNearestIndexInF_k(const real_T
  preprocess_global_path_array[10000], real_T current_s, real_T probably_index,
  real_T s_min, real_T s_max, B_Lattice_planner_ros_code_T *localB)
{
  real_T accurate_index;
  int32_T vectorUB;
  localB->min_range_m = std::fmax(std::round(s_min * 100.0) + probably_index,
    1.0);
  localB->max_range_c = std::fmin(std::round(s_max * 100.0) + probably_index,
    preprocess_global_path_array[1999]);
  if (localB->min_range_m > localB->max_range_c) {
    localB->c = 0;
    localB->b = 0;
  } else {
    localB->c = static_cast<int32_T>(localB->min_range_m) - 1;
    localB->b = static_cast<int32_T>(localB->max_range_c);
  }

  localB->b -= localB->c;
  localB->scalarLB_d = (localB->b / 2) << 1;
  vectorUB = localB->scalarLB_d - 2;
  for (localB->i12 = 0; localB->i12 <= vectorUB; localB->i12 += 2) {
    _mm_storeu_pd(&localB->distances_data_k[localB->i12], _mm_sub_pd
                  (_mm_loadu_pd(&preprocess_global_path_array[(localB->c +
      localB->i12) + 8000]), _mm_set1_pd(current_s)));
  }

  for (localB->i12 = localB->scalarLB_d; localB->i12 < localB->b; localB->i12++)
  {
    localB->distances_data_k[localB->i12] = preprocess_global_path_array
      [(localB->c + localB->i12) + 8000] - current_s;
  }

  localB->c = 0;
  while (localB->c <= localB->b - 1) {
    localB->y_data_c[localB->c] = localB->distances_data_k[localB->c] *
      localB->distances_data_k[localB->c];
    localB->c++;
  }

  vectorUB = localB->b;
  if (localB->b - 1 >= 0) {
    std::memcpy(&localB->distances_data_k[0], &localB->y_data_c[0], localB->b *
                sizeof(real_T));
  }

  localB->c = 0;
  while (localB->c <= localB->b - 1) {
    localB->distances_data_k[localB->c] = std::sqrt(localB->
      distances_data_k[localB->c]);
    localB->c++;
  }

  ros_code_minimum(localB->distances_data_k, &vectorUB, &localB->max_range_c,
                   &localB->c);
  accurate_index = (localB->min_range_m + static_cast<real_T>(localB->c)) - 1.0;
  return accurate_index;
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_wrapToPi_o(real_T *lambda, B_Lattice_planner_ros_code_T
  *localB)
{
  int32_T trueCount;
  boolean_T c;
  boolean_T d;
  boolean_T positiveInput_data;
  c = (*lambda < -3.1415926535897931);
  d = (*lambda > 3.1415926535897931);
  trueCount = 0;
  if (c || d) {
    trueCount = 1;
  }

  if (trueCount - 1 >= 0) {
    if (std::isnan(*lambda + 3.1415926535897931)) {
      localB->varargout_1 = (rtNaN);
    } else if (std::isinf(*lambda + 3.1415926535897931)) {
      localB->varargout_1 = (rtNaN);
    } else if (*lambda + 3.1415926535897931 == 0.0) {
      localB->varargout_1 = 0.0;
    } else {
      boolean_T rEQ0;
      localB->varargout_1 = std::fmod(*lambda + 3.1415926535897931,
        6.2831853071795862);
      rEQ0 = (localB->varargout_1 == 0.0);
      if (!rEQ0) {
        localB->q = std::abs((*lambda + 3.1415926535897931) / 6.2831853071795862);
        rEQ0 = !(std::abs(localB->q - std::floor(localB->q + 0.5)) >
                 2.2204460492503131E-16 * localB->q);
      }

      if (rEQ0) {
        localB->varargout_1 = 0.0;
      } else if (*lambda + 3.1415926535897931 < 0.0) {
        localB->varargout_1 += 6.2831853071795862;
      }
    }

    localB->z1_data = localB->varargout_1;
  }

  if (trueCount - 1 >= 0) {
    localB->x_data_f = localB->z1_data;
  }

  if (trueCount - 1 >= 0) {
    positiveInput_data = ((localB->z1_data == 0.0) && (*lambda +
      3.1415926535897931 > 0.0));
  }

  if ((trueCount - 1 >= 0) && positiveInput_data) {
    localB->x_data_f = 6.2831853071795862;
  }

  if (c || d) {
    *lambda = localB->x_data_f - 3.1415926535897931;
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_cod_calculateVehicleCorners(real_T x, real_T y, real_T theta,
  real_T length, real_T width, real_T rotated_corners_x[4], real_T
  rotated_corners_y[4], B_Lattice_planner_ros_code_T *localB)
{
  real_T rotated_corners_tmp;
  localB->half_length_c = length / 2.0;
  localB->half_width = width / 2.0;
  localB->rotated_corners_tmp = std::sin(theta);
  rotated_corners_tmp = std::cos(theta);
  localB->half_length[0] = localB->half_length_c;
  localB->half_length[2] = localB->half_length_c;
  localB->half_length[4] = -localB->half_length_c;
  localB->half_length[6] = -localB->half_length_c;
  localB->half_length[1] = localB->half_width;
  localB->half_length[3] = -localB->half_width;
  localB->half_length[5] = -localB->half_width;
  localB->half_length[7] = localB->half_width;
  for (int32_T i{0}; i < 4; i++) {
    int32_T rotated_corners_tmp_0;
    rotated_corners_tmp_0 = i << 1;
    localB->rotated_corners[rotated_corners_tmp_0] = 0.0;
    localB->half_length_c = localB->half_length[rotated_corners_tmp_0];
    localB->rotated_corners[rotated_corners_tmp_0] += localB->half_length_c *
      rotated_corners_tmp;
    localB->half_width = localB->half_length[rotated_corners_tmp_0 + 1];
    localB->rotated_corners[rotated_corners_tmp_0] += localB->half_width *
      -localB->rotated_corners_tmp;
    localB->rotated_corners[rotated_corners_tmp_0 + 1] = 0.0;
    localB->rotated_corners[rotated_corners_tmp_0 + 1] += localB->half_length_c *
      localB->rotated_corners_tmp;
    localB->rotated_corners[rotated_corners_tmp_0 + 1] += localB->half_width *
      rotated_corners_tmp;
  }

  rotated_corners_x[0] = localB->rotated_corners[0] + x;
  rotated_corners_y[0] = localB->rotated_corners[1] + y;
  rotated_corners_x[1] = localB->rotated_corners[2] + x;
  rotated_corners_y[1] = localB->rotated_corners[3] + y;
  rotated_corners_x[2] = localB->rotated_corners[4] + x;
  rotated_corners_y[2] = localB->rotated_corners[5] + y;
  rotated_corners_x[3] = localB->rotated_corners[6] + x;
  rotated_corners_y[3] = localB->rotated_corners[7] + y;
}

// Function for MATLAB Function: '<S3>/reducePath'
static real_T ros_code_detectCollision(const real_T ego_corners_x[4], const
  real_T ego_corners_y[4], const real_T object_corners_x[4], const real_T
  object_corners_y[4], real_T s_object, B_Lattice_planner_ros_code_T *localB)
{
  real_T danger_flag;
  danger_flag = 0.0;
  for (int32_T i{0}; i < 4; i++) {
    if (danger_flag == 0.0) {
      real_T tmp;
      localB->ego_x = ego_corners_x[i];
      localB->ego_y = ego_corners_y[i];
      localB->d_f = object_corners_x[1] - localB->ego_x;
      localB->d1 = object_corners_y[1] - localB->ego_y;
      localB->d2 = object_corners_x[2] - localB->ego_x;
      localB->d3 = object_corners_y[2] - localB->ego_y;
      localB->d4 = object_corners_x[3] - localB->ego_x;
      tmp = object_corners_y[0] - localB->ego_y;
      localB->ego_x = object_corners_x[0] - localB->ego_x;
      localB->ego_y = object_corners_y[3] - localB->ego_y;
      if (((std::abs(localB->ego_x * localB->d1 - localB->d_f * tmp) * 0.5 + std::
            abs(localB->d_f * localB->d3 - localB->d2 * localB->d1) * 0.5) + std::
           abs(localB->d2 * localB->ego_y - localB->d4 * localB->d3) * 0.5) +
          std::abs(localB->d4 * tmp - localB->ego_x * localB->ego_y) * 0.5 <=
          s_object + 0.05) {
        danger_flag = 1.0;
      }
    }
  }

  return danger_flag;
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_roots_n(const real_T c[4], creal_T r_data[], int32_T
  *r_size, B_Lattice_planner_ros_code_T *localB)
{
  r_data[0].re = 0.0;
  r_data[0].im = 0.0;
  r_data[1].re = 0.0;
  r_data[1].im = 0.0;
  r_data[2].re = 0.0;
  r_data[2].im = 0.0;
  localB->k1 = 1;
  while ((localB->k1 <= 4) && (!(c[localB->k1 - 1] != 0.0))) {
    localB->k1++;
  }

  localB->k2 = 4;
  while ((localB->k2 >= localB->k1) && (!(c[localB->k2 - 1] != 0.0))) {
    localB->k2--;
  }

  if (localB->k1 < localB->k2) {
    boolean_T exitg1;
    localB->companDim = localB->k2 - localB->k1;
    exitg1 = false;
    while ((!exitg1) && (localB->companDim > 0)) {
      boolean_T exitg2;
      localB->j = 0;
      exitg2 = false;
      while ((!exitg2) && (localB->j + 1 <= localB->companDim)) {
        localB->ctmp[localB->j] = c[localB->k1 + localB->j] / c[localB->k1 - 1];
        if (std::isinf(std::abs(localB->ctmp[localB->j]))) {
          exitg2 = true;
        } else {
          localB->j++;
        }
      }

      if (localB->j + 1 > localB->companDim) {
        exitg1 = true;
      } else {
        localB->k1++;
        localB->companDim--;
      }
    }

    if (localB->companDim < 1) {
      if (4 - localB->k2 < 1) {
        *r_size = 0;
      } else {
        *r_size = 4 - localB->k2;
      }
    } else {
      localB->a_size[0] = localB->companDim;
      localB->a_size[1] = localB->companDim;
      localB->k1 = localB->companDim * localB->companDim - 1;
      std::memset(&localB->a_data[0], 0, (localB->k1 + 1) * sizeof(real_T));
      localB->k1 = 0;
      while (localB->k1 <= localB->companDim - 2) {
        localB->j = localB->companDim * localB->k1;
        localB->a_data[localB->j] = -localB->ctmp[localB->k1];
        localB->a_data[(localB->k1 + localB->j) + 1] = 1.0;
        localB->k1++;
      }

      localB->a_data[localB->companDim * (localB->companDim - 1)] =
        -localB->ctmp[localB->companDim - 1];
      localB->k1 = 0;
      while (localB->k1 <= 3 - localB->k2) {
        r_data[localB->k1].re = 0.0;
        r_data[localB->k1].im = 0.0;
        localB->k1++;
      }

      ros_code_eig(localB->a_data, localB->a_size, localB->eiga_data,
                   &localB->eiga_size, localB);
      localB->k1 = 0;
      while (localB->k1 <= localB->companDim - 1) {
        r_data[(localB->k1 - localB->k2) + 4] = localB->eiga_data[localB->k1];
        localB->k1++;
      }

      *r_size = (localB->companDim - localB->k2) + 4;
    }
  } else if (4 - localB->k2 < 1) {
    *r_size = 0;
  } else {
    *r_size = 4 - localB->k2;
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static real_T ros_code_minimum_o(const real_T x[3])
{
  real_T ex;
  int32_T idx;
  if (!std::isnan(x[0])) {
    idx = 1;
  } else {
    int32_T k;
    boolean_T exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k <= 3)) {
      if (!std::isnan(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    while (idx + 1 <= 3) {
      if (ex > x[idx]) {
        ex = x[idx];
      }

      idx++;
    }
  }

  return ex;
}

static void ros_co_binary_expand_op_fhook5j(real_T in1_data[], int32_T *in1_size,
  const real_T in2_data[], const int32_T *in2_size, const real_T in3[5], int32_T
  in4, B_Lattice_planner_ros_code_T *localB)
{
  localB->in3_a = in3[in4 + 1];
  localB->in2_size_idx_0 = *in1_size == 1 ? *in2_size : *in1_size;
  localB->stride_0_0_m = (*in2_size != 1);
  localB->stride_1_0_c = (*in1_size != 1);
  localB->loop_ub_f = *in1_size == 1 ? *in2_size : *in1_size;
  for (localB->i8 = 0; localB->i8 < localB->loop_ub_f; localB->i8++) {
    localB->in2_data_l[localB->i8] = in2_data[localB->i8 * localB->stride_0_0_m]
      * in1_data[localB->i8 * localB->stride_1_0_c] + localB->in3_a;
  }

  *in1_size = localB->in2_size_idx_0;
  if (localB->in2_size_idx_0 - 1 >= 0) {
    std::memcpy(&in1_data[0], &localB->in2_data_l[0], localB->in2_size_idx_0 *
                sizeof(real_T));
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_polyval_d0(const real_T p[5], const real_T x_data[], const
  int32_T *x_size, real_T y_data[], int32_T *y_size,
  B_Lattice_planner_ros_code_T *localB)
{
  *y_size = *x_size;
  if (*x_size != 0) {
    localB->y_idx_0 = *x_size;
    *y_size = *x_size;
    for (localB->i7 = 0; localB->i7 < localB->y_idx_0; localB->i7++) {
      y_data[localB->i7] = p[0];
    }

    for (localB->y_idx_0 = 0; localB->y_idx_0 < 4; localB->y_idx_0++) {
      if (*x_size == *y_size) {
        localB->p_p = p[localB->y_idx_0 + 1];
        *y_size = *x_size;
        localB->loop_ub_k = *x_size;
        localB->scalarLB_i = (*x_size / 2) << 1;
        localB->vectorUB_o = localB->scalarLB_i - 2;
        for (localB->i7 = 0; localB->i7 <= localB->vectorUB_o; localB->i7 += 2)
        {
          __m128d tmp;
          tmp = _mm_loadu_pd(&y_data[localB->i7]);
          _mm_storeu_pd(&y_data[localB->i7], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(
            &x_data[localB->i7]), tmp), _mm_set1_pd(localB->p_p)));
        }

        for (localB->i7 = localB->scalarLB_i; localB->i7 < localB->loop_ub_k;
             localB->i7++) {
          y_data[localB->i7] = x_data[localB->i7] * y_data[localB->i7] +
            localB->p_p;
        }
      } else {
        ros_co_binary_expand_op_fhook5j(y_data, y_size, x_data, x_size, p,
          localB->y_idx_0, localB);
      }
    }
  }
}

// System initialize for atomic system: '<Root>/Lattice_planner'
void ros_code_Lattice_planner_Init(DW_Lattice_planner_ros_code_T *localDW,
  P_Lattice_planner_ros_code_T *localP)
{
  // InitializeConditions for Memory: '<S3>/Memory'
  for (int32_T i{0}; i < 5; i++) {
    localDW->Memory_PreviousInput[i] = localP->Memory_InitialCondition;
  }

  // End of InitializeConditions for Memory: '<S3>/Memory'

  // InitializeConditions for Memory: '<S3>/Memory1'
  std::memcpy(&localDW->Memory1_PreviousInput[0],
              &localP->Memory1_InitialCondition[0], 15U * sizeof(real_T));
}

// Output and update for atomic system: '<Root>/Lattice_planner'
void ros_code_Lattice_planner(const real_T rtu_state_C[5], real_T
  rtu_get_global_pose, const real_T rtu_preprocess_global_path_arra[10000],
  const real_T rtu_object_array_F[30], const real_T rtu_object_array_C[50],
  real_T rtu_clock, real_T *rty_get_local_path, real_T rty_predict_state[126],
  real_T rty_current_state_C[5], real_T rty_predict_next_state[3],
  B_Lattice_planner_ros_code_T *localB, DW_Lattice_planner_ros_code_T *localDW)
{
  __m128d tmp;
  __m128d tmp_0;
  boolean_T b_x[3];
  boolean_T e_data[3];
  boolean_T b_data[2];
  boolean_T c_data[2];
  boolean_T exitg1;
  boolean_T positiveInput_data;
  boolean_T y;

  // MATLAB Function: '<S3>/currentStateConvert' incorporates:
  //   Memory: '<S3>/Memory'

  std::memset(&localB->current_state_F[0], 0, sizeof(real_T) << 3U);
  localB->s_end = 0.0;
  localB->accurate_index = 0.0;
  localB->min_range = rtu_state_C[0] - localDW->Memory_PreviousInput[0];
  localB->angle_diff = rtu_state_C[1] - localDW->Memory_PreviousInput[1];
  localB->ds = std::sqrt(localB->min_range * localB->min_range +
    localB->angle_diff * localB->angle_diff);
  if (rtu_get_global_pose != 0.0) {
    localB->s_end = rtu_preprocess_global_path_arra[static_cast<int32_T>
      (rtu_preprocess_global_path_arra[1999]) + 7999];
    localB->S_end = rtu_preprocess_global_path_arra[4000];
    for (localB->last = 0; localB->last < 199; localB->last++) {
      localB->S_end += rtu_preprocess_global_path_arra[(localB->last + 1) * 10 +
        4000];
    }

    localB->mean_angle = localB->S_end / 200.0;
    localB->accurate_index = std::cos(localB->mean_angle);
    localB->d_ls = localB->accurate_index * localB->accurate_index;
    localB->accurate_index = rtu_state_C[0];
    localB->mean_angle = std::sin(localB->mean_angle);
    localB->mean_angle *= localB->mean_angle;
    localB->min_range = rtu_state_C[1];
    for (localB->last = 0; localB->last < 200; localB->last++) {
      localB->angle_diff = rtu_preprocess_global_path_arra[10 * localB->last] -
        localB->accurate_index;
      localB->max_range = rtu_preprocess_global_path_arra[10 * localB->last +
        2000] - localB->min_range;
      localB->approximate_distances[localB->last] = std::sqrt(localB->max_range *
        localB->max_range * localB->mean_angle + localB->angle_diff *
        localB->angle_diff * localB->d_ls);
    }

    if (!std::isnan(localB->approximate_distances[0])) {
      localB->i = 1;
    } else {
      localB->i = 0;
      localB->last = 2;
      exitg1 = false;
      while ((!exitg1) && (localB->last < 201)) {
        if (!std::isnan(localB->approximate_distances[localB->last - 1])) {
          localB->i = localB->last;
          exitg1 = true;
        } else {
          localB->last++;
        }
      }
    }

    if (localB->i == 0) {
      localB->last = 0;
    } else {
      localB->max_range = localB->approximate_distances[localB->i - 1];
      localB->last = localB->i - 1;
      while (localB->i + 1 < 201) {
        if (localB->max_range > localB->approximate_distances[localB->i]) {
          localB->max_range = localB->approximate_distances[localB->i];
          localB->last = localB->i;
        }

        localB->i++;
      }
    }

    localB->i = localB->last * 10 + 1;
    if (localB->last + 1 == 1) {
      localB->min_range = 1.0;
      localB->max_range = 10.0;
    } else if (localB->i >= rtu_preprocess_global_path_arra[1999] - 10.0) {
      localB->min_range = rtu_preprocess_global_path_arra[1999] - 10.0;
      localB->max_range = rtu_preprocess_global_path_arra[1999];
    } else {
      localB->min_range = static_cast<real_T>(localB->i) - 5.0;
      localB->max_range = static_cast<real_T>(localB->i) + 5.0;
    }

    if (localB->min_range > localB->max_range) {
      localB->i = -1;
      localB->last = -1;
    } else {
      localB->i = static_cast<int32_T>(localB->min_range) - 2;
      localB->last = static_cast<int32_T>(localB->max_range) - 1;
    }

    localB->last -= localB->i;
    if (localB->last == 0) {
      localB->accurate_index = 0.0;
    } else {
      if (localB->last <= 1024) {
        localB->firstBlockLength = localB->last;
        localB->lastBlockLength = 1024;
        localB->nblocks = 1;
      } else {
        localB->firstBlockLength = 1024;
        localB->lastBlockLength = localB->last;
        localB->nblocks = 2;
      }

      localB->accurate_index = rtu_preprocess_global_path_arra[localB->i + 4001];
      localB->g_k = 2;
      while (localB->g_k <= localB->firstBlockLength) {
        localB->accurate_index += rtu_preprocess_global_path_arra[(localB->i +
          localB->g_k) + 4000];
        localB->g_k++;
      }

      localB->firstBlockLength = 2;
      while (localB->firstBlockLength <= localB->nblocks) {
        localB->mean_angle = rtu_preprocess_global_path_arra[localB->i + 5025];
        localB->firstBlockLength = 2;
        while (localB->firstBlockLength <= localB->lastBlockLength - 1024) {
          localB->mean_angle += rtu_preprocess_global_path_arra[(localB->i +
            localB->firstBlockLength) + 5024];
          localB->firstBlockLength++;
        }

        localB->accurate_index += localB->mean_angle;
        localB->firstBlockLength = 3;
      }
    }

    localB->mean_angle = localB->accurate_index / static_cast<real_T>
      (localB->last);
    if (localB->min_range > localB->max_range) {
      localB->i = 0;
      localB->lastBlockLength = 0;
      localB->g = 0;
      localB->f = 0;
    } else {
      localB->i = static_cast<int32_T>(localB->min_range) - 1;
      localB->lastBlockLength = static_cast<int32_T>(localB->max_range);
      localB->g = static_cast<int32_T>(localB->min_range) - 1;
      localB->f = static_cast<int32_T>(localB->max_range);
    }

    localB->accurate_index = std::cos(localB->mean_angle);
    localB->d_ls = localB->accurate_index * localB->accurate_index;
    localB->accurate_index = std::sin(localB->mean_angle);
    localB->mean_angle = localB->accurate_index * localB->accurate_index;
    localB->accurate_index = rtu_state_C[0];
    localB->nblocks = localB->lastBlockLength - localB->i;
    localB->distances_size = localB->nblocks;
    localB->firstBlockLength = (localB->nblocks / 2) << 1;
    localB->g_k = localB->firstBlockLength - 2;
    for (localB->last = 0; localB->last <= localB->g_k; localB->last += 2) {
      tmp_0 = _mm_loadu_pd(&rtu_preprocess_global_path_arra[localB->i +
                           localB->last]);
      _mm_storeu_pd(&localB->distances_data[localB->last], _mm_sub_pd(tmp_0,
        _mm_set1_pd(localB->accurate_index)));
    }

    for (localB->last = localB->firstBlockLength; localB->last < localB->nblocks;
         localB->last++) {
      localB->distances_data[localB->last] =
        rtu_preprocess_global_path_arra[localB->i + localB->last] -
        localB->accurate_index;
    }

    localB->accurate_index = rtu_state_C[1];
    localB->loop_ub = localB->f - localB->g;
    localB->rtu_preprocess_global_path_ar_k = localB->loop_ub;
    localB->firstBlockLength_tmp = (localB->loop_ub / 2) << 1;
    localB->g_k = localB->firstBlockLength_tmp - 2;
    for (localB->last = 0; localB->last <= localB->g_k; localB->last += 2) {
      tmp_0 = _mm_loadu_pd(&rtu_preprocess_global_path_arra[(localB->g +
        localB->last) + 2000]);
      _mm_storeu_pd(&localB->rtu_preprocess_global_path_arra[localB->last],
                    _mm_sub_pd(tmp_0, _mm_set1_pd(localB->accurate_index)));
    }

    for (localB->last = localB->firstBlockLength_tmp; localB->last <
         localB->loop_ub; localB->last++) {
      localB->rtu_preprocess_global_path_arra[localB->last] =
        rtu_preprocess_global_path_arra[(localB->g + localB->last) + 2000] -
        localB->accurate_index;
    }

    ros_code_power(localB->distances_data, &localB->distances_size,
                   localB->tmp_data, &localB->tmp_size_p, localB);
    ros_code_power(localB->rtu_preprocess_global_path_arra,
                   &localB->rtu_preprocess_global_path_ar_k, localB->tmp_data,
                   &localB->tmp_size_px, localB);
    if (localB->tmp_size_p == localB->tmp_size_px) {
      localB->accurate_index = rtu_state_C[0];
      localB->distances_size = localB->nblocks;
      localB->firstBlockLength = (localB->nblocks / 2) << 1;
      localB->g_k = localB->firstBlockLength - 2;
      for (localB->last = 0; localB->last <= localB->g_k; localB->last += 2) {
        tmp_0 = _mm_loadu_pd(&rtu_preprocess_global_path_arra[localB->i +
                             localB->last]);
        _mm_storeu_pd(&localB->distances_data[localB->last], _mm_sub_pd(tmp_0,
          _mm_set1_pd(localB->accurate_index)));
      }

      for (localB->last = localB->firstBlockLength; localB->last <
           localB->nblocks; localB->last++) {
        localB->distances_data[localB->last] =
          rtu_preprocess_global_path_arra[localB->i + localB->last] -
          localB->accurate_index;
      }

      ros_code_power(localB->distances_data, &localB->distances_size,
                     localB->rtu_preprocess_global_path_arra,
                     &localB->rtu_preprocess_global_path_ar_k, localB);
      localB->accurate_index = rtu_state_C[1];
      localB->distances_size = localB->loop_ub;
      localB->g_k = localB->firstBlockLength_tmp - 2;
      for (localB->last = 0; localB->last <= localB->g_k; localB->last += 2) {
        tmp_0 = _mm_loadu_pd(&rtu_preprocess_global_path_arra[(localB->g +
          localB->last) + 2000]);
        _mm_storeu_pd(&localB->distances_data[localB->last], _mm_sub_pd(tmp_0,
          _mm_set1_pd(localB->accurate_index)));
      }

      for (localB->last = localB->firstBlockLength_tmp; localB->last <
           localB->loop_ub; localB->last++) {
        localB->distances_data[localB->last] = rtu_preprocess_global_path_arra
          [(localB->g + localB->last) + 2000] - localB->accurate_index;
      }

      ros_code_power(localB->distances_data, &localB->distances_size,
                     localB->tmp_data, &localB->tmp_size_p, localB);
      localB->accurate_distance_size = localB->rtu_preprocess_global_path_ar_k;
      localB->nblocks = localB->rtu_preprocess_global_path_ar_k;
      localB->firstBlockLength = (localB->rtu_preprocess_global_path_ar_k / 2) <<
        1;
      localB->g_k = localB->firstBlockLength - 2;
      for (localB->last = 0; localB->last <= localB->g_k; localB->last += 2) {
        tmp_0 = _mm_loadu_pd(&localB->rtu_preprocess_global_path_arra
                             [localB->last]);
        tmp = _mm_loadu_pd(&localB->tmp_data[localB->last]);
        _mm_storeu_pd(&localB->accurate_distance_data[localB->last], _mm_add_pd
                      (_mm_mul_pd(_mm_set1_pd(localB->d_ls), tmp_0), _mm_mul_pd
                       (_mm_set1_pd(localB->mean_angle), tmp)));
      }

      for (localB->last = localB->firstBlockLength; localB->last <
           localB->nblocks; localB->last++) {
        localB->accurate_distance_data[localB->last] = localB->d_ls *
          localB->rtu_preprocess_global_path_arra[localB->last] +
          localB->mean_angle * localB->tmp_data[localB->last];
      }
    } else {
      ros_code_binary_expand_op_fho(localB->accurate_distance_data,
        &localB->accurate_distance_size, localB->d_ls,
        rtu_preprocess_global_path_arra, localB->i, localB->lastBlockLength - 1,
        rtu_state_C, localB->mean_angle, localB->g, localB->f - 1, localB);
    }

    localB->firstBlockLength = localB->accurate_distance_size;
    localB->last = 0;
    while (localB->last <= localB->firstBlockLength - 1) {
      localB->accurate_distance_data[localB->last] = std::sqrt
        (localB->accurate_distance_data[localB->last]);
      localB->last++;
    }

    localB->last = localB->accurate_distance_size;
    if (localB->accurate_distance_size <= 2) {
      if (localB->accurate_distance_size == 1) {
        localB->i = 1;
      } else {
        localB->p_tmp_n = localB->accurate_distance_data
          [localB->accurate_distance_size - 1];
        if (localB->accurate_distance_data[0] > localB->p_tmp_n) {
          localB->i = localB->accurate_distance_size;
        } else if (std::isnan(localB->accurate_distance_data[0])) {
          if (!std::isnan(localB->p_tmp_n)) {
            localB->i = localB->accurate_distance_size;
          } else {
            localB->i = 1;
          }
        } else {
          localB->i = 1;
        }
      }
    } else {
      if (!std::isnan(localB->accurate_distance_data[0])) {
        localB->i = 1;
      } else {
        localB->i = 0;
        localB->lastBlockLength = 2;
        exitg1 = false;
        while ((!exitg1) && (localB->lastBlockLength <= localB->last)) {
          if (!std::isnan(localB->accurate_distance_data[localB->lastBlockLength
                          - 1])) {
            localB->i = localB->lastBlockLength;
            exitg1 = true;
          } else {
            localB->lastBlockLength++;
          }
        }
      }

      if (localB->i == 0) {
        localB->i = 1;
      } else {
        localB->accurate_index = localB->accurate_distance_data[localB->i - 1];
        localB->lastBlockLength = localB->i;
        while (localB->lastBlockLength + 1 <= localB->last) {
          if (localB->accurate_index > localB->accurate_distance_data
              [localB->lastBlockLength]) {
            localB->accurate_index = localB->accurate_distance_data
              [localB->lastBlockLength];
            localB->i = localB->lastBlockLength + 1;
          }

          localB->lastBlockLength++;
        }
      }
    }

    localB->accurate_index = (localB->min_range + static_cast<real_T>(localB->i))
      - 1.0;
    if (localB->accurate_index == 1.0) {
      for (localB->last = 0; localB->last < 5; localB->last++) {
        localB->last_path_data[localB->last] = rtu_preprocess_global_path_arra
          [2000 * localB->last];
      }
    } else {
      for (localB->last = 0; localB->last < 5; localB->last++) {
        localB->last_path_data[localB->last] = rtu_preprocess_global_path_arra[(
          static_cast<int32_T>(localB->accurate_index - 1.0) + 2000 *
          localB->last) - 1];
      }
    }

    if (localB->ds == 0.0) {
      localB->ds = 0.0;
    } else {
      localB->mean_angle = rtu_state_C[2] - localDW->Memory_PreviousInput[2];
      ros_code_wrapToPi(&localB->mean_angle, localB);
      localB->ds = localB->mean_angle / localB->ds;
    }

    localB->min_range_tmp = rtu_preprocess_global_path_arra[static_cast<int32_T>
      (localB->accurate_index) + 5999];
    localB->mean_angle = rtu_preprocess_global_path_arra[static_cast<int32_T>
      (localB->accurate_index) + 3999];
    localB->angle_diff = rtu_state_C[2] - localB->mean_angle;
    ros_code_wrapToPi(&localB->angle_diff, localB);
    localB->c_a_tmp = rtu_state_C[0] - rtu_preprocess_global_path_arra[
      static_cast<int32_T>(localB->accurate_index) - 1];
    localB->L_min = rtu_state_C[1] - rtu_preprocess_global_path_arra[
      static_cast<int32_T>(localB->accurate_index) + 1999];
    localB->mean_angle = localB->L_min * std::cos(localB->mean_angle) -
      localB->c_a_tmp * std::sin(localB->mean_angle);
    if (!std::isnan(localB->mean_angle)) {
      if (localB->mean_angle < 0.0) {
        localB->mean_angle = -1.0;
      } else {
        localB->mean_angle = (localB->mean_angle > 0.0);
      }
    }

    localB->mean_angle *= std::sqrt(localB->c_a_tmp * localB->c_a_tmp +
      localB->L_min * localB->L_min);
    localB->min_range = std::cos(localB->angle_diff);
    localB->theta = 1.0 - localB->min_range_tmp * localB->mean_angle;
    localB->d_s = rtu_state_C[3] * localB->min_range / localB->theta;
    localB->dd_ls = std::tan(localB->angle_diff);
    localB->d_ls = localB->theta * localB->dd_ls;
    localB->sv_0 = (localB->min_range_tmp - localB->last_path_data[3]) *
      localB->mean_angle + localB->min_range_tmp * localB->d_ls;
    localB->dd_ls = (localB->theta / localB->min_range * localB->ds -
                     localB->min_range_tmp) * (localB->theta /
      (localB->min_range * localB->min_range)) + -localB->sv_0 * localB->dd_ls;
    localB->ls_0 = localB->d_s * localB->d_s;
    localB->ds = ((rtu_state_C[3] - localDW->Memory_PreviousInput[3]) *
                  localB->min_range - (((1.0 - localB->min_range_tmp *
      localB->mean_angle) / localB->min_range - localB->min_range_tmp) *
      localB->ds - localB->sv_0) * localB->d_ls * localB->ls_0) / localB->theta;
    localB->current_state_F[0] = rtu_preprocess_global_path_arra
      [static_cast<int32_T>(localB->accurate_index) + 7999];
    localB->current_state_F[1] = localB->d_s;
    localB->current_state_F[2] = localB->ds;
    localB->current_state_F[3] = localB->mean_angle;
    localB->current_state_F[4] = localB->d_ls;
    localB->current_state_F[5] = localB->dd_ls;
    localB->current_state_F[6] = localB->d_s * localB->d_ls;
    localB->current_state_F[7] = localB->ls_0 * localB->dd_ls + localB->d_ls *
      localB->ds;
  }

  for (localB->i = 0; localB->i < 5; localB->i++) {
    rty_current_state_C[localB->i] = rtu_state_C[localB->i];
  }

  // MATLAB Function: '<S3>/predictState' incorporates:
  //   Memory: '<S3>/Memory1'

  std::memset(&localB->predict_state_F[0], 0, 9U * sizeof(real_T));
  rty_predict_next_state[0] = 0.0;
  rty_predict_next_state[1] = 0.0;
  rty_predict_next_state[2] = 0.0;
  std::memcpy(&localB->predict_state_F[0], &localB->current_state_F[0], sizeof
              (real_T) << 3U);
  rty_predict_next_state[0] = rty_current_state_C[0];
  rty_predict_next_state[1] = rty_current_state_C[1];
  rty_predict_next_state[2] = rty_current_state_C[2];
  y = true;
  localB->last = 0;
  exitg1 = false;
  while ((!exitg1) && (localB->last < 15)) {
    if (!(localDW->Memory1_PreviousInput[localB->last] == 0.0)) {
      y = false;
      exitg1 = true;
    } else {
      localB->last++;
    }
  }

  if (!y) {
    boolean_T f;
    localB->ds = rtu_clock - localDW->Memory1_PreviousInput[12];
    localB->p[0] = localDW->Memory1_PreviousInput[5];
    localB->p[1] = localDW->Memory1_PreviousInput[4];
    localB->p[2] = localDW->Memory1_PreviousInput[3];
    localB->p[3] = localDW->Memory1_PreviousInput[2];
    localB->p[4] = localDW->Memory1_PreviousInput[1];
    localB->p[5] = localDW->Memory1_PreviousInput[0];
    localB->angle_diff = localDW->Memory1_PreviousInput[5];
    for (localB->last = 0; localB->last < 5; localB->last++) {
      localB->angle_diff = localB->ds * localB->angle_diff + localB->p
        [localB->last + 1];
    }

    localB->p[0] = localDW->Memory1_PreviousInput[11];
    localB->p[1] = localDW->Memory1_PreviousInput[10];
    localB->p[2] = localDW->Memory1_PreviousInput[9];
    localB->p[3] = localDW->Memory1_PreviousInput[8];
    localB->p[4] = localDW->Memory1_PreviousInput[7];
    localB->p[5] = localDW->Memory1_PreviousInput[6];
    localB->mean_angle = localDW->Memory1_PreviousInput[11];
    for (localB->last = 0; localB->last < 5; localB->last++) {
      localB->mean_angle = localB->angle_diff * localB->mean_angle + localB->
        p[localB->last + 1];
    }

    localB->d_ls = (((5.0 * localDW->Memory1_PreviousInput[11] *
                      localB->angle_diff + 4.0 * localDW->Memory1_PreviousInput
                      [10]) * localB->angle_diff + 3.0 *
                     localDW->Memory1_PreviousInput[9]) * localB->angle_diff +
                    2.0 * localDW->Memory1_PreviousInput[8]) *
      localB->angle_diff + localDW->Memory1_PreviousInput[7];
    localB->min_range = std::fmax(localDW->Memory1_PreviousInput[13] - 50.0, 1.0);
    localB->max_range = std::fmin(localDW->Memory1_PreviousInput[14] + 10.0,
      rtu_preprocess_global_path_arra[1999]);
    if (localB->min_range > localB->max_range) {
      localB->i = 0;
      localB->last = 0;
    } else {
      localB->i = static_cast<int32_T>(localB->min_range) - 1;
      localB->last = static_cast<int32_T>(localB->max_range);
    }

    localB->nblocks = localB->last - localB->i;
    localB->firstBlockLength = (localB->nblocks / 2) << 1;
    localB->g_k = localB->firstBlockLength - 2;
    for (localB->last = 0; localB->last <= localB->g_k; localB->last += 2) {
      tmp_0 = _mm_loadu_pd(&rtu_preprocess_global_path_arra[(localB->i +
        localB->last) + 8000]);
      _mm_storeu_pd(&localB->distances_data[localB->last], _mm_sub_pd(tmp_0,
        _mm_set1_pd(localB->angle_diff)));
    }

    for (localB->last = localB->firstBlockLength; localB->last < localB->nblocks;
         localB->last++) {
      localB->distances_data[localB->last] = rtu_preprocess_global_path_arra
        [(localB->i + localB->last) + 8000] - localB->angle_diff;
    }

    localB->accurate_distance_size = localB->nblocks;
    localB->firstBlockLength = 0;
    while (localB->firstBlockLength <= localB->nblocks - 1) {
      localB->accurate_distance_data[localB->firstBlockLength] =
        localB->distances_data[localB->firstBlockLength] *
        localB->distances_data[localB->firstBlockLength];
      localB->firstBlockLength++;
    }

    if (localB->nblocks - 1 >= 0) {
      std::memcpy(&localB->distances_data[0], &localB->accurate_distance_data[0],
                  localB->nblocks * sizeof(real_T));
    }

    localB->last = 0;
    while (localB->last <= localB->accurate_distance_size - 1) {
      localB->distances_data[localB->last] = std::sqrt(localB->
        distances_data[localB->last]);
      localB->last++;
    }

    localB->last = localB->accurate_distance_size;
    if (localB->accurate_distance_size <= 2) {
      if (localB->accurate_distance_size == 1) {
        localB->i = 1;
      } else {
        localB->p_tmp_n = localB->distances_data[localB->accurate_distance_size
          - 1];
        if (localB->distances_data[0] > localB->p_tmp_n) {
          localB->i = localB->accurate_distance_size;
        } else if (std::isnan(localB->distances_data[0])) {
          if (!std::isnan(localB->p_tmp_n)) {
            localB->i = localB->accurate_distance_size;
          } else {
            localB->i = 1;
          }
        } else {
          localB->i = 1;
        }
      }
    } else {
      if (!std::isnan(localB->distances_data[0])) {
        localB->i = 1;
      } else {
        localB->i = 0;
        localB->lastBlockLength = 2;
        exitg1 = false;
        while ((!exitg1) && (localB->lastBlockLength <= localB->last)) {
          if (!std::isnan(localB->distances_data[localB->lastBlockLength - 1]))
          {
            localB->i = localB->lastBlockLength;
            exitg1 = true;
          } else {
            localB->lastBlockLength++;
          }
        }
      }

      if (localB->i == 0) {
        localB->i = 1;
      } else {
        localB->max_range = localB->distances_data[localB->i - 1];
        localB->lastBlockLength = localB->i;
        while (localB->lastBlockLength + 1 <= localB->last) {
          if (localB->max_range > localB->distances_data[localB->lastBlockLength])
          {
            localB->max_range = localB->distances_data[localB->lastBlockLength];
            localB->i = localB->lastBlockLength + 1;
          }

          localB->lastBlockLength++;
        }
      }
    }

    localB->min_range = (localB->min_range + static_cast<real_T>(localB->i)) -
      1.0;
    localB->sv_0 = rtu_preprocess_global_path_arra[static_cast<int32_T>
      (localB->min_range) + 3999];
    localB->theta = rt_atan2d_snf(localB->d_ls, 1.0 -
      rtu_preprocess_global_path_arra[static_cast<int32_T>(localB->min_range) +
      5999] * localB->mean_angle) + localB->sv_0;
    y = (localB->theta < -3.1415926535897931);
    f = (localB->theta > 3.1415926535897931);
    localB->last = 0;
    if (y || f) {
      localB->last = 1;
    }

    if (localB->last - 1 >= 0) {
      localB->x_data = localB->theta + 3.1415926535897931;
    }

    if (localB->last - 1 >= 0) {
      if (std::isnan(localB->theta + 3.1415926535897931)) {
        localB->max_range = (rtNaN);
      } else if (std::isinf(localB->theta + 3.1415926535897931)) {
        localB->max_range = (rtNaN);
      } else if (localB->theta + 3.1415926535897931 == 0.0) {
        localB->max_range = 0.0;
      } else {
        boolean_T rEQ0;
        localB->max_range = std::fmod(localB->theta + 3.1415926535897931,
          6.2831853071795862);
        rEQ0 = (localB->max_range == 0.0);
        if (!rEQ0) {
          localB->d_s = std::abs((localB->theta + 3.1415926535897931) /
            6.2831853071795862);
          rEQ0 = !(std::abs(localB->d_s - std::floor(localB->d_s + 0.5)) >
                   2.2204460492503131E-16 * localB->d_s);
        }

        if (rEQ0) {
          localB->max_range = 0.0;
        } else if (localB->theta + 3.1415926535897931 < 0.0) {
          localB->max_range += 6.2831853071795862;
        }
      }

      localB->x_data = localB->max_range;
    }

    if (localB->last - 1 >= 0) {
      localB->i = 0;
      positiveInput_data = ((localB->x_data == 0.0) && (localB->theta +
        3.1415926535897931 > 0.0));
    }

    if (localB->last - 1 >= 0) {
      localB->i_p = 0;
      if (positiveInput_data) {
        localB->x_data = 6.2831853071795862;
      }
    }

    if (y || f) {
      localB->theta = localB->x_data - 3.1415926535897931;
    }

    rty_predict_next_state[0] = rtu_preprocess_global_path_arra
      [static_cast<int32_T>(localB->min_range) - 1] - std::sin(localB->sv_0) *
      localB->mean_angle;
    rty_predict_next_state[1] = std::cos(localB->sv_0) * localB->mean_angle +
      rtu_preprocess_global_path_arra[static_cast<int32_T>(localB->min_range) +
      1999];
    rty_predict_next_state[2] = localB->theta;
    localB->predict_state_F[0] = localB->angle_diff;
    localB->predict_state_F[1] = (((5.0 * localDW->Memory1_PreviousInput[5] *
      localB->ds + 4.0 * localDW->Memory1_PreviousInput[4]) * localB->ds + 3.0 *
      localDW->Memory1_PreviousInput[3]) * localB->ds + 2.0 *
      localDW->Memory1_PreviousInput[2]) * localB->ds +
      localDW->Memory1_PreviousInput[1];
    localB->predict_state_F[2] = ((20.0 * localDW->Memory1_PreviousInput[5] *
      localB->ds + 12.0 * localDW->Memory1_PreviousInput[4]) * localB->ds + 6.0 *
      localDW->Memory1_PreviousInput[3]) * localB->ds + 2.0 *
      localDW->Memory1_PreviousInput[2];
    localB->predict_state_F[3] = localB->mean_angle;
    localB->predict_state_F[4] = localB->d_ls;
    localB->predict_state_F[5] = ((20.0 * localDW->Memory1_PreviousInput[11] *
      localB->angle_diff + 12.0 * localDW->Memory1_PreviousInput[10]) *
      localB->angle_diff + 6.0 * localDW->Memory1_PreviousInput[9]) *
      localB->angle_diff + 2.0 * localDW->Memory1_PreviousInput[8];
    localB->predict_state_F[6] = 0.0;
    localB->predict_state_F[7] = 0.0;
    localB->predict_state_F[8] = localB->min_range;
  }

  // End of MATLAB Function: '<S3>/predictState'

  // MATLAB Function: '<S3>/sampleTrajectory' incorporates:
  //   Constant: '<S3>/Constant'
  //   MATLAB Function: '<S3>/currentStateConvert'

  localB->max_range = ros_code_P.sample_param[1];
  localB->theta = ros_code_P.sample_param[2];
  localB->L_min = ros_code_P.sample_param[4];
  localB->l_step = ros_code_P.sample_param[5];
  localB->ds_min = ros_code_P.sample_param[7];
  localB->ds_step = ros_code_P.sample_param[8];
  localB->lastBlockLength = 0;
  localB->min_range = rty_current_state_C[0] - rty_predict_next_state[0];
  localB->angle_diff = rty_current_state_C[1] - rty_predict_next_state[1];
  if (std::sqrt(localB->min_range * localB->min_range + localB->angle_diff *
                localB->angle_diff) >= ros_code_P.sample_param[9]) {
    localB->mean_angle = rty_current_state_C[0];
    localB->d_ls = rty_current_state_C[1];
    localB->ds = rty_current_state_C[2];
  } else {
    std::memcpy(&localB->current_state_F[0], &localB->predict_state_F[0], sizeof
                (real_T) << 3U);
    localB->accurate_index = localB->predict_state_F[8];
    localB->mean_angle = rty_predict_next_state[0];
    localB->d_ls = rty_predict_next_state[1];
    localB->ds = rty_predict_next_state[2];
  }

  if (std::abs(localB->current_state_F[0] - localB->s_end) >=
      ros_code_P.sample_param[11]) {
    localB->lastBlockLength = 1;
  }

  localB->min_range = std::fmin(std::round((ros_code_P.sample_param[3] -
    ros_code_P.sample_param[4]) / ros_code_P.sample_param[5] + 1.0) * std::round
    ((ros_code_P.sample_param[6] - ros_code_P.sample_param[7]) /
     ros_code_P.sample_param[8] + 1.0) * std::round((ros_code_P.sample_param[0]
    - ros_code_P.sample_param[1]) / ros_code_P.sample_param[2] + 1.0), 25000.0);
  localDW->SFunction_DIMS4[0] = static_cast<int32_T>(localB->min_range);
  localDW->SFunction_DIMS4[1] = 13;
  localB->nblocks = static_cast<int32_T>(localB->min_range) * 13;
  if (localB->nblocks - 1 >= 0) {
    std::memset(&localB->Tau_sl[0], 0, localB->nblocks * sizeof(real_T));
  }

  localB->d_s = localB->current_state_F[0];
  localB->sv_0 = localB->current_state_F[1];
  localB->dd_ls = localB->current_state_F[2];
  localB->ls_0 = localB->current_state_F[3];
  localB->lv_0 = localB->current_state_F[4];
  localB->la_0 = localB->current_state_F[5];
  if (localB->s_end - localB->current_state_F[0] > ros_code_P.sample_param[10])
  {
    localB->sa2 = localB->current_state_F[2] / 2.0;
    localB->sl_index = 0.0;
    localB->last = static_cast<int32_T>(((ros_code_P.sample_param[2] -
      ros_code_P.sample_param[1]) + ros_code_P.sample_param[0]) /
      ros_code_P.sample_param[2]);
    localB->nblocks = 0;
    while (localB->nblocks <= localB->last - 1) {
      localB->angle_diff = static_cast<real_T>(localB->nblocks) * localB->theta
        + localB->max_range;
      localB->i = static_cast<int32_T>(((localB->ds_step - localB->ds_min) +
        ros_code_P.sample_param[6]) / localB->ds_step);
      if (localB->i - 1 >= 0) {
        localB->max_Tau_sl_num = static_cast<int32_T>(((localB->l_step -
          localB->L_min) + ros_code_P.sample_param[3]) / localB->l_step);
      }

      localB->firstBlockLength = 0;
      while (localB->firstBlockLength <= localB->i - 1) {
        localB->min_range = static_cast<real_T>(localB->firstBlockLength) *
          localB->ds_step + localB->ds_min;
        localB->sa3 = -(((3.0 * localB->sv_0 - 3.0 * localB->min_range) + 2.0 *
                         localB->angle_diff * localB->dd_ls) +
                        localB->angle_diff * 0.0) / (localB->angle_diff *
          localB->angle_diff * 3.0);
        localB->sa4 = (((2.0 * localB->sv_0 - 2.0 * localB->min_range) +
                        localB->angle_diff * localB->dd_ls) + localB->angle_diff
                       * 0.0) / (4.0 * rt_powd_snf(localB->angle_diff, 3.0));
        localB->S_start = (((0.0 * localB->sa4 + localB->sa3) * 0.0 +
                            localB->sa2) * 0.0 + localB->sv_0) * 0.0 +
          localB->d_s;
        localB->S_end = (((localB->angle_diff * localB->sa4 + localB->sa3) *
                          localB->angle_diff + localB->sa2) * localB->angle_diff
                         + localB->sv_0) * localB->angle_diff + localB->d_s;
        localB->g_k = 0;
        while (localB->g_k <= localB->max_Tau_sl_num - 1) {
          localB->ls_1 = static_cast<real_T>(localB->g_k) * localB->l_step +
            localB->L_min;
          localB->c_a_tmp = localB->S_end - localB->S_start;
          localB->sl_index++;
          localB->Tau_sl[static_cast<int32_T>(localB->sl_index) - 1] =
            localB->d_s;
          localB->Tau_sl[(static_cast<int32_T>(localB->sl_index) +
                          localDW->SFunction_DIMS4[0]) - 1] = localB->sv_0;
          localB->Tau_sl[(static_cast<int32_T>(localB->sl_index) +
                          (localDW->SFunction_DIMS4[0] << 1)) - 1] = localB->sa2;
          localB->Tau_sl[(static_cast<int32_T>(localB->sl_index) +
                          localDW->SFunction_DIMS4[0] * 3) - 1] = localB->sa3;
          localB->Tau_sl[(static_cast<int32_T>(localB->sl_index) +
                          (localDW->SFunction_DIMS4[0] << 2)) - 1] = localB->sa4;
          localB->Tau_sl[(static_cast<int32_T>(localB->sl_index) +
                          localDW->SFunction_DIMS4[0] * 5) - 1] = 0.0;
          localB->min_range = 2.0 * localB->S_end * rt_powd_snf(localB->S_start,
            5.0) * 0.0;
          localB->x_tmp = rt_powd_snf(localB->S_end, 3.0);
          localB->p_tmp_n = rt_powd_snf(localB->S_start, 3.0);
          localB->p_tmp = localB->S_start * localB->S_start;
          localB->p_tmp_o = localB->S_end * localB->S_end;
          localB->min_range_tmp = localB->p_tmp_o * 3.0;
          localB->x_tmp_l = ((localB->x_tmp - localB->min_range_tmp *
                              localB->S_start) + 3.0 * localB->S_end *
                             localB->p_tmp) - localB->p_tmp_n;
          localB->rtb_Tau_sl_tmp_i = rt_powd_snf(localB->S_end, 5.0);
          localB->rtb_Tau_sl_tmp = rt_powd_snf(localB->S_start, 5.0);
          localB->rtb_Tau_sl_tmp_o = rt_powd_snf(localB->S_start, 4.0);
          localB->rtb_Tau_sl_tmp_b = rt_powd_snf(localB->S_end, 4.0);
          localB->rtb_Tau_sl_tmp_tmp = 8.0 * localB->x_tmp;
          localB->rtb_Tau_sl_tmp_n = localB->rtb_Tau_sl_tmp_tmp *
            localB->p_tmp_n;
          localB->rtb_Tau_sl_tmp_bs = 10.0 * localB->rtb_Tau_sl_tmp_b;
          localB->rtb_Tau_sl_tmp_l = 2.0 * localB->rtb_Tau_sl_tmp_i;
          localB->rtb_Tau_sl_tmp_h = 2.0 * localB->rtb_Tau_sl_tmp;
          localB->rtb_Tau_sl_tmp_bn = localB->rtb_Tau_sl_tmp_l * localB->S_start;
          localB->rtb_Tau_sl_tmp_d = localB->rtb_Tau_sl_tmp_bs * localB->S_start;
          localB->rtb_Tau_sl_tmp_e = 10.0 * localB->S_end *
            localB->rtb_Tau_sl_tmp_o;
          localB->rtb_Tau_sl_tmp_bj = localB->c_a_tmp * localB->c_a_tmp * 2.0 *
            localB->x_tmp_l;
          localB->rtb_Tau_sl_tmp_ju = localB->p_tmp_o * 20.0;
          localB->rtb_Tau_sl_tmp_o4 = 2.0 * localB->x_tmp;
          localB->Tau_sl[(static_cast<int32_T>(localB->sl_index) +
                          localDW->SFunction_DIMS4[0] * 6) - 1] =
            (((((((((((((((((localB->rtb_Tau_sl_tmp_l * localB->ls_0 -
                             localB->rtb_Tau_sl_tmp_h * localB->ls_1) +
                            localB->x_tmp * localB->rtb_Tau_sl_tmp_o *
                            localB->la_0) - 2.0 * localB->rtb_Tau_sl_tmp_b *
                           localB->p_tmp_n * localB->la_0) + localB->p_tmp *
                          localB->rtb_Tau_sl_tmp_i * localB->la_0) -
                         localB->p_tmp_o * localB->rtb_Tau_sl_tmp * 0.0) +
                        localB->rtb_Tau_sl_tmp_o4 * localB->rtb_Tau_sl_tmp_o *
                        0.0) - localB->rtb_Tau_sl_tmp_b * localB->p_tmp_n * 0.0)
                      + 20.0 * localB->x_tmp * localB->p_tmp * localB->ls_0) -
                     localB->rtb_Tau_sl_tmp_ju * localB->p_tmp_n * localB->ls_1)
                    - localB->rtb_Tau_sl_tmp_n * localB->lv_0) +
                   localB->rtb_Tau_sl_tmp_bs * localB->p_tmp * localB->lv_0) -
                  localB->p_tmp_o * 10.0 * localB->rtb_Tau_sl_tmp_o * 0.0) +
                 localB->rtb_Tau_sl_tmp_n * 0.0) - localB->rtb_Tau_sl_tmp_d *
                localB->ls_0) + localB->rtb_Tau_sl_tmp_e * localB->ls_1) -
              localB->rtb_Tau_sl_tmp_bn * localB->lv_0) + localB->min_range) /
            localB->rtb_Tau_sl_tmp_bj;
          localB->rtb_Tau_sl_tmp_tmp_j = 4.0 * localB->x_tmp;
          localB->rtb_Tau_sl_tmp_n = localB->rtb_Tau_sl_tmp_tmp_j *
            localB->p_tmp_n;
          localB->rtb_Tau_sl_tmp_tmp_f = localB->p_tmp_o * 60.0;
          localB->rtb_Tau_sl_tmp_bs = localB->rtb_Tau_sl_tmp_tmp_f *
            localB->p_tmp;
          localB->rtb_Tau_sl_tmp_j = 3.0 * localB->rtb_Tau_sl_tmp_b;
          localB->rtb_Tau_sl_tmp_a = 24.0 * localB->x_tmp;
          localB->rtb_Tau_sl_tmp_ny = localB->p_tmp_o * 16.0;
          localB->Tau_sl[(static_cast<int32_T>(localB->sl_index) +
                          localDW->SFunction_DIMS4[0] * 7) - 1] =
            (((((((((((((((((localB->rtb_Tau_sl_tmp_l * localB->lv_0 -
                             localB->rtb_Tau_sl_tmp_h * 0.0) -
                            localB->min_range_tmp * localB->rtb_Tau_sl_tmp_o *
                            localB->la_0) + localB->rtb_Tau_sl_tmp_n *
                           localB->la_0) + localB->p_tmp *
                          localB->rtb_Tau_sl_tmp_b * localB->la_0) -
                         localB->p_tmp_o * localB->rtb_Tau_sl_tmp_o * 0.0) -
                        localB->rtb_Tau_sl_tmp_n * 0.0) +
                       localB->rtb_Tau_sl_tmp_j * localB->p_tmp * 0.0) -
                      localB->rtb_Tau_sl_tmp_bs * localB->ls_0) +
                     localB->rtb_Tau_sl_tmp_bs * localB->ls_1) + localB->p_tmp_o
                    * 24.0 * localB->p_tmp_n * localB->lv_0) - 16.0 *
                   localB->x_tmp * localB->p_tmp * localB->lv_0) +
                  localB->rtb_Tau_sl_tmp_ny * localB->p_tmp_n * 0.0) -
                 localB->rtb_Tau_sl_tmp_a * localB->p_tmp * 0.0) -
                localB->rtb_Tau_sl_tmp_bn * localB->la_0) + localB->min_range) -
              localB->rtb_Tau_sl_tmp_d * localB->lv_0) +
             localB->rtb_Tau_sl_tmp_e * 0.0) / localB->rtb_Tau_sl_tmp_bj;
          localB->rtb_Tau_sl_tmp_n = localB->p_tmp_o * 12.0 * localB->p_tmp;
          localB->rtb_Tau_sl_tmp_bs = 60.0 * localB->S_end * localB->p_tmp;
          localB->rtb_Tau_sl_tmp_l = localB->rtb_Tau_sl_tmp_tmp_f *
            localB->S_start;
          localB->rtb_Tau_sl_tmp_h = localB->p_tmp_o * 8.0;
          localB->rtb_Tau_sl_tmp_bn = localB->c_a_tmp * localB->c_a_tmp * 2.0 *
            localB->x_tmp_l;
          localB->Tau_sl[(static_cast<int32_T>(localB->sl_index) +
                          (localDW->SFunction_DIMS4[0] << 3)) - 1] =
            (((((((((((((((((localB->rtb_Tau_sl_tmp_i * localB->la_0 -
                             localB->rtb_Tau_sl_tmp * 0.0) -
                            localB->rtb_Tau_sl_tmp_tmp * localB->p_tmp *
                            localB->la_0) + localB->rtb_Tau_sl_tmp_h *
                           localB->p_tmp_n * 0.0) - localB->rtb_Tau_sl_tmp_n *
                          localB->lv_0) + localB->rtb_Tau_sl_tmp_n * 0.0) + 3.0 *
                        localB->S_end * localB->rtb_Tau_sl_tmp_o * localB->la_0)
                       + 4.0 * localB->rtb_Tau_sl_tmp_b * localB->S_start *
                       localB->la_0) - 4.0 * localB->S_end *
                      localB->rtb_Tau_sl_tmp_o * 0.0) - localB->rtb_Tau_sl_tmp_j
                     * localB->S_start * 0.0) + localB->rtb_Tau_sl_tmp_bs *
                    localB->ls_0) + localB->rtb_Tau_sl_tmp_l * localB->ls_0) -
                  localB->rtb_Tau_sl_tmp_bs * localB->ls_1) -
                 localB->rtb_Tau_sl_tmp_l * localB->ls_1) - 24.0 * localB->S_end
                * localB->p_tmp_n * localB->lv_0) + 36.0 * localB->x_tmp *
               localB->S_start * localB->lv_0) - 36.0 * localB->S_end *
              localB->p_tmp_n * 0.0) + localB->rtb_Tau_sl_tmp_a *
             localB->S_start * 0.0) / localB->rtb_Tau_sl_tmp_bn;
          localB->min_range_tmp = 2.0 * localB->S_end * localB->S_start;
          localB->min_range = ((localB->p_tmp_o - localB->min_range_tmp) +
                               localB->p_tmp) * 2.0 * localB->x_tmp_l;
          localB->rtb_Tau_sl_tmp_i = localB->p_tmp * 20.0;
          localB->rtb_Tau_sl_tmp = localB->rtb_Tau_sl_tmp_h * localB->p_tmp;
          localB->rtb_Tau_sl_tmp_n = 80.0 * localB->S_end * localB->S_start;
          localB->Tau_sl[(static_cast<int32_T>(localB->sl_index) +
                          localDW->SFunction_DIMS4[0] * 9) - 1] =
            -(((((((((((((((((((((localB->rtb_Tau_sl_tmp_j * localB->la_0 -
            localB->rtb_Tau_sl_tmp_b * 0.0) + localB->rtb_Tau_sl_tmp_o *
            localB->la_0) - 3.0 * localB->rtb_Tau_sl_tmp_o * 0.0) +
                               localB->rtb_Tau_sl_tmp_ju * localB->ls_0) -
                              localB->rtb_Tau_sl_tmp_ju * localB->ls_1) +
                             localB->rtb_Tau_sl_tmp_i * localB->ls_0) -
                            localB->rtb_Tau_sl_tmp_i * localB->ls_1) + 12.0 *
                           localB->x_tmp * localB->lv_0) +
                          localB->rtb_Tau_sl_tmp_tmp * 0.0) - 8.0 *
                         localB->p_tmp_n * localB->lv_0) - 12.0 *
                        localB->p_tmp_n * 0.0) - localB->rtb_Tau_sl_tmp *
                       localB->la_0) + localB->rtb_Tau_sl_tmp * 0.0) +
                     localB->rtb_Tau_sl_tmp_n * localB->ls_0) -
                    localB->rtb_Tau_sl_tmp_n * localB->ls_1) + 4.0 *
                   localB->S_end * localB->p_tmp_n * localB->la_0) -
                  localB->rtb_Tau_sl_tmp_tmp_j * localB->S_start * 0.0) - 32.0 *
                 localB->S_end * localB->p_tmp * localB->lv_0) + localB->p_tmp_o
                * 28.0 * localB->S_start * localB->lv_0) - 28.0 * localB->S_end *
               localB->p_tmp * 0.0) + localB->p_tmp_o * 32.0 * localB->S_start *
              0.0) / localB->min_range;
          localB->x_tmp_l = localB->min_range_tmp * 0.0;
          localB->Tau_sl[(static_cast<int32_T>(localB->sl_index) +
                          localDW->SFunction_DIMS4[0] * 10) - 1] =
            (((((((((((((((((30.0 * localB->S_end * localB->ls_0 - 30.0 *
                             localB->S_end * localB->ls_1) + 30.0 *
                            localB->S_start * localB->ls_0) - 30.0 *
                           localB->S_start * localB->ls_1) + 3.0 * localB->x_tmp
                          * localB->la_0) - localB->rtb_Tau_sl_tmp_o4 * 0.0) +
                        2.0 * localB->p_tmp_n * localB->la_0) - 3.0 *
                       localB->p_tmp_n * 0.0) + localB->rtb_Tau_sl_tmp_ny *
                      localB->lv_0) + localB->p_tmp_o * 14.0 * 0.0) -
                    localB->p_tmp * 14.0 * localB->lv_0) - localB->p_tmp * 16.0 *
                   0.0) - localB->min_range_tmp * localB->lv_0) +
                 localB->x_tmp_l) - localB->p_tmp * localB->S_end * localB->la_0)
               - localB->p_tmp_o * 4.0 * localB->S_start * localB->la_0) + 4.0 *
              localB->S_end * localB->p_tmp * 0.0) + localB->p_tmp_o *
             localB->S_start * 0.0) / localB->rtb_Tau_sl_tmp_bn;
          localB->Tau_sl[(static_cast<int32_T>(localB->sl_index) +
                          localDW->SFunction_DIMS4[0] * 11) - 1] =
            -(((((((((((12.0 * localB->ls_0 - 12.0 * localB->ls_1) + 6.0 *
                       localB->S_end * localB->lv_0) + 6.0 * localB->S_end * 0.0)
                     - 6.0 * localB->S_start * localB->lv_0) - 6.0 *
                    localB->S_start * 0.0) + localB->p_tmp_o * localB->la_0) -
                  localB->p_tmp_o * 0.0) + localB->p_tmp * localB->la_0) -
                localB->p_tmp * 0.0) - localB->min_range_tmp * localB->la_0) +
              localB->x_tmp_l) / localB->min_range;
          localB->Tau_sl[(static_cast<int32_T>(localB->sl_index) +
                          localDW->SFunction_DIMS4[0] * 12) - 1] =
            localB->angle_diff;
          localB->g_k++;
        }

        localB->firstBlockLength++;
      }

      localB->nblocks++;
    }

    localB->Tau_sl[localDW->SFunction_DIMS4[0] - 1] = localB->sl_index;
  } else {
    localB->sa2 = localB->current_state_F[2] / 2.0;
    localB->sl_index = 0.0;
    localB->i = static_cast<int32_T>(((ros_code_P.sample_param[2] -
      ros_code_P.sample_param[1]) + ros_code_P.sample_param[0]) /
      ros_code_P.sample_param[2]);
    if (localB->i - 1 >= 0) {
      localB->p[3] = localB->sa2;
      localB->p[4] = localB->current_state_F[1];
      localB->p[5] = localB->current_state_F[0];
    }

    localB->last = 0;
    while (localB->last <= localB->i - 1) {
      localB->angle_diff = static_cast<real_T>(localB->last) * localB->theta +
        localB->max_range;
      localB->min_range = localB->angle_diff * localB->angle_diff;
      localB->S_end = localB->min_range * 3.0 * localB->dd_ls;
      localB->S_start = localB->min_range * 0.0;
      localB->sa3 = -(((((20.0 * localB->d_s - 20.0 * localB->s_end) + 12.0 *
                         localB->angle_diff * localB->sv_0) + 8.0 *
                        localB->angle_diff * 0.0) + localB->S_end) -
                      localB->S_start) / (2.0 * rt_powd_snf(localB->angle_diff,
        3.0));
      localB->sa4 = (((((30.0 * localB->d_s - 30.0 * localB->s_end) + 16.0 *
                        localB->angle_diff * localB->sv_0) + 14.0 *
                       localB->angle_diff * 0.0) + localB->S_end) -
                     localB->min_range * 2.0 * 0.0) / (2.0 * rt_powd_snf
        (localB->angle_diff, 4.0));
      localB->min_range = -(((((12.0 * localB->d_s - 12.0 * localB->s_end) + 6.0
        * localB->angle_diff * localB->sv_0) + 6.0 * localB->angle_diff * 0.0) +
        localB->min_range * localB->dd_ls) - localB->S_start) / (2.0 *
        rt_powd_snf(localB->angle_diff, 5.0));
      localB->p[0] = localB->min_range;
      localB->p[1] = localB->sa4;
      localB->p[2] = localB->sa3;
      localB->S_start = localB->min_range;
      localB->S_end = localB->min_range;
      for (localB->max_Tau_sl_num = 0; localB->max_Tau_sl_num < 5;
           localB->max_Tau_sl_num++) {
        localB->L_min = localB->p[localB->max_Tau_sl_num + 1];
        localB->S_start = 0.0 * localB->S_start + localB->L_min;
        localB->S_end = localB->angle_diff * localB->S_end + localB->L_min;
      }

      localB->L_min = localB->S_end - localB->S_start;
      localB->sl_index++;
      localB->Tau_sl[static_cast<int32_T>(localB->sl_index) - 1] = localB->d_s;
      localB->Tau_sl[(static_cast<int32_T>(localB->sl_index) +
                      localDW->SFunction_DIMS4[0]) - 1] = localB->sv_0;
      localB->Tau_sl[(static_cast<int32_T>(localB->sl_index) +
                      (localDW->SFunction_DIMS4[0] << 1)) - 1] = localB->sa2;
      localB->Tau_sl[(static_cast<int32_T>(localB->sl_index) +
                      localDW->SFunction_DIMS4[0] * 3) - 1] = localB->sa3;
      localB->Tau_sl[(static_cast<int32_T>(localB->sl_index) +
                      (localDW->SFunction_DIMS4[0] << 2)) - 1] = localB->sa4;
      localB->Tau_sl[(static_cast<int32_T>(localB->sl_index) +
                      localDW->SFunction_DIMS4[0] * 5) - 1] = localB->min_range;
      localB->min_range = rt_powd_snf(localB->S_end, 5.0);
      localB->x_tmp = rt_powd_snf(localB->S_start, 5.0);
      localB->x_tmp_l = rt_powd_snf(localB->S_end, 3.0);
      localB->sa3 = rt_powd_snf(localB->S_start, 4.0);
      localB->c_a_tmp = rt_powd_snf(localB->S_end, 4.0);
      localB->sa4 = rt_powd_snf(localB->S_start, 3.0);
      localB->l_step = localB->S_start * localB->S_start;
      localB->ds_min = localB->S_end * localB->S_end;
      localB->ds_step = 8.0 * localB->x_tmp_l;
      localB->ls_1 = localB->ds_step * localB->sa4;
      localB->p_tmp_n = 10.0 * localB->c_a_tmp;
      localB->p_tmp = 2.0 * localB->min_range;
      localB->p_tmp_o = 2.0 * localB->x_tmp * 0.0;
      localB->rtb_Tau_sl_tmp_bn = localB->ds_min * 3.0;
      localB->rtb_Tau_sl_tmp_o4 = localB->p_tmp * localB->S_start;
      localB->rtb_Tau_sl_tmp_ny = 2.0 * localB->S_end * localB->x_tmp * 0.0;
      localB->rtb_Tau_sl_tmp = localB->p_tmp_n * localB->S_start;
      localB->rtb_Tau_sl_tmp_o = 10.0 * localB->S_end * localB->sa3 * 0.0;
      localB->rtb_Tau_sl_tmp_b = ((localB->x_tmp_l - localB->rtb_Tau_sl_tmp_bn *
        localB->S_start) + 3.0 * localB->S_end * localB->l_step) - localB->sa4;
      localB->rtb_Tau_sl_tmp_tmp = localB->ds_min * 20.0;
      localB->rtb_Tau_sl_tmp_n = 2.0 * localB->x_tmp_l;
      localB->rtb_Tau_sl_tmp_i = localB->L_min * localB->L_min * 2.0 *
        localB->rtb_Tau_sl_tmp_b;
      localB->Tau_sl[(static_cast<int32_T>(localB->sl_index) +
                      localDW->SFunction_DIMS4[0] * 6) - 1] =
        (((((((((((((((((localB->p_tmp * localB->ls_0 - localB->p_tmp_o) +
                        localB->x_tmp_l * localB->sa3 * localB->la_0) - 2.0 *
                       localB->c_a_tmp * localB->sa4 * localB->la_0) +
                      localB->l_step * localB->min_range * localB->la_0) -
                     localB->ds_min * localB->x_tmp * 0.0) +
                    localB->rtb_Tau_sl_tmp_n * localB->sa3 * 0.0) -
                   localB->c_a_tmp * localB->sa4 * 0.0) + 20.0 * localB->x_tmp_l
                  * localB->l_step * localB->ls_0) - localB->rtb_Tau_sl_tmp_tmp *
                 localB->sa4 * 0.0) - localB->ls_1 * localB->lv_0) +
               localB->p_tmp_n * localB->l_step * localB->lv_0) - localB->ds_min
              * 10.0 * localB->sa3 * 0.0) + localB->ls_1 * 0.0) -
            localB->rtb_Tau_sl_tmp * localB->ls_0) + localB->rtb_Tau_sl_tmp_o) -
          localB->rtb_Tau_sl_tmp_o4 * localB->lv_0) + localB->rtb_Tau_sl_tmp_ny)
        / localB->rtb_Tau_sl_tmp_i;
      localB->ls_1 = 4.0 * localB->x_tmp_l;
      localB->p_tmp_n = localB->ls_1 * localB->sa4;
      localB->L_min = localB->ds_min * 60.0;
      localB->rtb_Tau_sl_tmp_h = localB->L_min * localB->l_step;
      localB->rtb_Tau_sl_tmp_ju = 3.0 * localB->c_a_tmp;
      localB->rtb_Tau_sl_tmp_tmp_j = 24.0 * localB->x_tmp_l;
      localB->rtb_Tau_sl_tmp_j = localB->ds_min * 16.0;
      localB->Tau_sl[(static_cast<int32_T>(localB->sl_index) +
                      localDW->SFunction_DIMS4[0] * 7) - 1] =
        (((((((((((((((((localB->p_tmp * localB->lv_0 - localB->p_tmp_o) -
                        localB->rtb_Tau_sl_tmp_bn * localB->sa3 * localB->la_0)
                       + localB->p_tmp_n * localB->la_0) + localB->l_step *
                      localB->c_a_tmp * localB->la_0) - localB->ds_min *
                     localB->sa3 * 0.0) - localB->p_tmp_n * 0.0) +
                   localB->rtb_Tau_sl_tmp_ju * localB->l_step * 0.0) -
                  localB->rtb_Tau_sl_tmp_h * localB->ls_0) +
                 localB->rtb_Tau_sl_tmp_h * 0.0) + localB->ds_min * 24.0 *
                localB->sa4 * localB->lv_0) - 16.0 * localB->x_tmp_l *
               localB->l_step * localB->lv_0) + localB->rtb_Tau_sl_tmp_j *
              localB->sa4 * 0.0) - localB->rtb_Tau_sl_tmp_tmp_j * localB->l_step
             * 0.0) - localB->rtb_Tau_sl_tmp_o4 * localB->la_0) +
           localB->rtb_Tau_sl_tmp_ny) - localB->rtb_Tau_sl_tmp * localB->lv_0) +
         localB->rtb_Tau_sl_tmp_o) / localB->rtb_Tau_sl_tmp_i;
      localB->p_tmp_n = localB->ds_min * 12.0 * localB->l_step;
      localB->p_tmp = 60.0 * localB->S_end * localB->l_step;
      localB->p_tmp_o = localB->L_min * localB->S_start;
      localB->rtb_Tau_sl_tmp_bn = localB->ds_min * 8.0;
      localB->Tau_sl[(static_cast<int32_T>(localB->sl_index) +
                      (localDW->SFunction_DIMS4[0] << 3)) - 1] =
        (((((((((((((((((localB->min_range * localB->la_0 - localB->x_tmp * 0.0)
                        - localB->ds_step * localB->l_step * localB->la_0) +
                       localB->rtb_Tau_sl_tmp_bn * localB->sa4 * 0.0) -
                      localB->p_tmp_n * localB->lv_0) + localB->p_tmp_n * 0.0) +
                    3.0 * localB->S_end * localB->sa3 * localB->la_0) + 4.0 *
                   localB->c_a_tmp * localB->S_start * localB->la_0) - 4.0 *
                  localB->S_end * localB->sa3 * 0.0) - localB->rtb_Tau_sl_tmp_ju
                 * localB->S_start * 0.0) + localB->p_tmp * localB->ls_0) +
               localB->p_tmp_o * localB->ls_0) - localB->p_tmp * 0.0) -
             localB->p_tmp_o * 0.0) - 24.0 * localB->S_end * localB->sa4 *
            localB->lv_0) + 36.0 * localB->x_tmp_l * localB->S_start *
           localB->lv_0) - 36.0 * localB->S_end * localB->sa4 * 0.0) +
         localB->rtb_Tau_sl_tmp_tmp_j * localB->S_start * 0.0) /
        localB->rtb_Tau_sl_tmp_i;
      localB->min_range = localB->l_step * 20.0;
      localB->x_tmp = localB->rtb_Tau_sl_tmp_bn * localB->l_step;
      localB->p_tmp_n = 80.0 * localB->S_end * localB->S_start;
      localB->p_tmp = 2.0 * localB->S_end * localB->S_start;
      localB->p_tmp_o = ((localB->ds_min - localB->p_tmp) + localB->l_step) *
        2.0 * localB->rtb_Tau_sl_tmp_b;
      localB->Tau_sl[(static_cast<int32_T>(localB->sl_index) +
                      localDW->SFunction_DIMS4[0] * 9) - 1] =
        -(((((((((((((((((((((localB->rtb_Tau_sl_tmp_ju * localB->la_0 -
        localB->c_a_tmp * 0.0) + localB->sa3 * localB->la_0) - 3.0 * localB->sa3
                            * 0.0) + localB->rtb_Tau_sl_tmp_tmp * localB->ls_0)
                          - localB->rtb_Tau_sl_tmp_tmp * 0.0) +
                         localB->min_range * localB->ls_0) - localB->min_range *
                        0.0) + 12.0 * localB->x_tmp_l * localB->lv_0) +
                      localB->ds_step * 0.0) - 8.0 * localB->sa4 * localB->lv_0)
                    - 12.0 * localB->sa4 * 0.0) - localB->x_tmp * localB->la_0)
                  + localB->x_tmp * 0.0) + localB->p_tmp_n * localB->ls_0) -
                localB->p_tmp_n * 0.0) + 4.0 * localB->S_end * localB->sa4 *
               localB->la_0) - localB->ls_1 * localB->S_start * 0.0) - 32.0 *
             localB->S_end * localB->l_step * localB->lv_0) + localB->ds_min *
            28.0 * localB->S_start * localB->lv_0) - 28.0 * localB->S_end *
           localB->l_step * 0.0) + localB->ds_min * 32.0 * localB->S_start * 0.0)
        / localB->p_tmp_o;
      localB->min_range = localB->p_tmp * 0.0;
      localB->Tau_sl[(static_cast<int32_T>(localB->sl_index) +
                      localDW->SFunction_DIMS4[0] * 10) - 1] =
        (((((((((((((((((30.0 * localB->S_end * localB->ls_0 - 30.0 *
                         localB->S_end * 0.0) + 30.0 * localB->S_start *
                        localB->ls_0) - 30.0 * localB->S_start * 0.0) + 3.0 *
                      localB->x_tmp_l * localB->la_0) - localB->rtb_Tau_sl_tmp_n
                     * 0.0) + 2.0 * localB->sa4 * localB->la_0) - 3.0 *
                   localB->sa4 * 0.0) + localB->rtb_Tau_sl_tmp_j * localB->lv_0)
                 + localB->ds_min * 14.0 * 0.0) - localB->l_step * 14.0 *
                localB->lv_0) - localB->l_step * 16.0 * 0.0) - localB->p_tmp *
              localB->lv_0) + localB->min_range) - localB->l_step *
            localB->S_end * localB->la_0) - localB->ds_min * 4.0 *
           localB->S_start * localB->la_0) + 4.0 * localB->S_end *
          localB->l_step * 0.0) + localB->ds_min * localB->S_start * 0.0) /
        localB->rtb_Tau_sl_tmp_i;
      localB->Tau_sl[(static_cast<int32_T>(localB->sl_index) +
                      localDW->SFunction_DIMS4[0] * 11) - 1] = -((((((((((6.0 *
        localB->S_end * localB->lv_0 + 12.0 * localB->ls_0) + 6.0 *
        localB->S_end * 0.0) - 6.0 * localB->S_start * localB->lv_0) - 6.0 *
        localB->S_start * 0.0) + localB->ds_min * localB->la_0) - localB->ds_min
        * 0.0) + localB->l_step * localB->la_0) - localB->l_step * 0.0) -
        localB->p_tmp * localB->la_0) + localB->min_range) / localB->p_tmp_o;
      localB->Tau_sl[(static_cast<int32_T>(localB->sl_index) +
                      localDW->SFunction_DIMS4[0] * 12) - 1] =
        localB->angle_diff;
      localB->last++;
    }

    localB->Tau_sl[localDW->SFunction_DIMS4[0] - 1] = localB->sl_index;
  }

  localB->max_range = ros_code_P.sample_param[0] * ros_code_P.sample_param[6];

  // MATLAB Function: '<S3>/reducePath' incorporates:
  //   Constant: '<S3>/Constant1'
  //   MATLAB Function: '<S3>/sampleTrajectory'

  localB->d_s = ros_code_P.reduce_param[0];
  localB->sv_0 = ros_code_P.reduce_param[1];
  localB->dd_ls = ros_code_P.reduce_param[3];
  localB->ls_0 = ros_code_P.reduce_param[4];
  localB->max_Tau_sl_num = static_cast<int32_T>(std::fmin(static_cast<real_T>
    (localDW->SFunction_DIMS4[0]), 50000.0));
  localDW->SFunction_DIMS2[0] = localB->max_Tau_sl_num;
  localDW->SFunction_DIMS2[1] = 16;
  localB->nblocks = localB->max_Tau_sl_num << 4;
  if (localB->nblocks - 1 >= 0) {
    std::memset(&localB->rest_path[0], 0, localB->nblocks * sizeof(real_T));
  }

  localB->lv_0 = ros_code_P.reduce_param[0] * ros_code_P.reduce_param[5];
  localB->la_0 = ros_code_P.reduce_param[1] * ros_code_P.reduce_param[5];
  if (localB->lastBlockLength != 0) {
    localB->object_distance[0] = ros_code_P.reduce_param[4];
    localB->object_distance[1] = ros_code_P.reduce_param[4];
    localB->object_distance[2] = ros_code_P.reduce_param[4];
    localB->sa2 = 0.0;
    localB->sl_index = localB->Tau_sl[localDW->SFunction_DIMS4[0] - 1];
    localB->i = 0;
    while (localB->i <= static_cast<int32_T>(localB->sl_index) - 1) {
      localB->S_start = localB->Tau_sl[localDW->SFunction_DIMS4[0] * 12 +
        localB->i];
      localB->danger_flag[0] = 0.0;
      localB->danger_flag[1] = 0.0;
      localB->danger_flag[2] = 0.0;
      localB->L_min = std::fmin(std::round(localB->S_start * 10.0), 500.0);
      localB->sa3 = localB->Tau_sl[localDW->SFunction_DIMS4[0] * 5 + localB->i];
      localB->p[0] = localB->sa3;
      localB->sa4 = localB->Tau_sl[(localDW->SFunction_DIMS4[0] << 2) +
        localB->i];
      localB->p[1] = localB->sa4;
      localB->ls_1 = localB->Tau_sl[localDW->SFunction_DIMS4[0] * 3 + localB->i];
      localB->p[2] = localB->ls_1;
      localB->rtb_Tau_sl_tmp_i = localB->Tau_sl[(localDW->SFunction_DIMS4[0] <<
        1) + localB->i];
      localB->p[3] = localB->rtb_Tau_sl_tmp_i;
      localB->p_tmp = localB->Tau_sl[localB->i + localDW->SFunction_DIMS4[0]];
      localB->p[4] = localB->p_tmp;
      localB->p_tmp_o = localB->Tau_sl[localB->i];
      localB->p[5] = localB->p_tmp_o;
      ros_code_linspace_n(localB->S_start, localB->L_min, localB->tmp_data_f,
                          localB->tmp_size, localB);
      ros_code_polyval(localB->p, localB->tmp_data_f, localB->tmp_size,
                       localB->predit_s_data, localB->predit_s_size, localB);
      localB->g = localDW->SFunction_DIMS4[0] * 11 + localB->i;
      localB->c_a_tmp = localB->Tau_sl[localB->g];
      localB->p[0] = localB->c_a_tmp;
      localB->f = localDW->SFunction_DIMS4[0] * 10 + localB->i;
      localB->l_step = localB->Tau_sl[localB->f];
      localB->p[1] = localB->l_step;
      localB->p_tmp_a = localDW->SFunction_DIMS4[0] * 9 + localB->i;
      localB->ds_step = localB->Tau_sl[localB->p_tmp_a];
      localB->p[2] = localB->ds_step;
      localB->p_tmp_j = (localDW->SFunction_DIMS4[0] << 3) + localB->i;
      localB->p_tmp_n = localB->Tau_sl[localB->p_tmp_j];
      localB->p[3] = localB->p_tmp_n;
      localB->ds_min = localB->Tau_sl[localDW->SFunction_DIMS4[0] * 7 +
        localB->i];
      localB->p[4] = localB->ds_min;
      localB->p[5] = localB->Tau_sl[localDW->SFunction_DIMS4[0] * 6 + localB->i];
      ros_code_polyval(localB->p, localB->predit_s_data, localB->predit_s_size,
                       localB->predit_l_data, localB->predit_l_size, localB);
      if (rtu_object_array_F[9] != 0.0) {
        localB->max_Tau_sl_num = 0;
        while (localB->max_Tau_sl_num <= static_cast<int32_T>
               (rtu_object_array_F[9]) - 1) {
          localB->nblocks = static_cast<int32_T>(localB->L_min);
          localB->sl_distance_size = static_cast<int32_T>(localB->L_min);
          if (localB->nblocks - 1 >= 0) {
            std::memset(&localB->sl_distance_data[0], 0, localB->nblocks *
                        sizeof(real_T));
          }

          localB->min_range = rtu_object_array_F[localB->max_Tau_sl_num];
          localB->rtu_object_array_F_size[0] = 1;
          localB->rtu_object_array_F_size[1] = localB->predit_s_size[1];
          localB->loop_ub = localB->predit_s_size[1];
          localB->firstBlockLength_tmp = (localB->predit_s_size[1] / 2) << 1;
          localB->g_k = localB->firstBlockLength_tmp - 2;
          for (localB->last = 0; localB->last <= localB->g_k; localB->last += 2)
          {
            localB->i_p = localB->last;
            tmp_0 = _mm_loadu_pd(&localB->predit_s_data[localB->i_p]);
            _mm_storeu_pd(&localB->rtu_object_array_F_data[localB->i_p],
                          _mm_sub_pd(_mm_set1_pd(localB->min_range), tmp_0));
          }

          for (localB->last = localB->firstBlockLength_tmp; localB->last <
               localB->loop_ub; localB->last++) {
            localB->g_k = localB->last;
            localB->rtu_object_array_F_data[localB->g_k] = localB->min_range -
              localB->predit_s_data[localB->g_k];
          }

          localB->angle_diff = rtu_object_array_F[localB->max_Tau_sl_num + 10];
          localB->rtu_object_array_F_size_h[0] = 1;
          localB->rtu_object_array_F_size_h[1] = localB->predit_l_size[1];
          localB->loop_ub = localB->predit_l_size[1];
          localB->firstBlockLength = (localB->predit_l_size[1] / 2) << 1;
          localB->g_k = localB->firstBlockLength - 2;
          for (localB->last = 0; localB->last <= localB->g_k; localB->last += 2)
          {
            localB->i_p = localB->last;
            tmp_0 = _mm_loadu_pd(&localB->predit_l_data[localB->i_p]);
            _mm_storeu_pd(&localB->rtu_object_array_F_data_c[localB->i_p],
                          _mm_sub_pd(_mm_set1_pd(localB->angle_diff), tmp_0));
          }

          for (localB->last = localB->firstBlockLength; localB->last <
               localB->loop_ub; localB->last++) {
            localB->g_k = localB->last;
            localB->rtu_object_array_F_data_c[localB->g_k] = localB->angle_diff
              - localB->predit_l_data[localB->g_k];
          }

          ros_code_power_i(localB->rtu_object_array_F_data,
                           localB->rtu_object_array_F_size, localB->tmp_data_f,
                           localB->tmp_size, localB);
          ros_code_power_i(localB->rtu_object_array_F_data_c,
                           localB->rtu_object_array_F_size_h, localB->tmp_data_f,
                           localB->tmp_size_m, localB);
          if (localB->tmp_size[1] == localB->tmp_size_m[1]) {
            localB->min_range = rtu_object_array_F[localB->max_Tau_sl_num];
            localB->rtu_object_array_F_size[0] = 1;
            localB->rtu_object_array_F_size[1] = localB->predit_s_size[1];
            localB->loop_ub = localB->predit_s_size[1];
            localB->g_k = localB->firstBlockLength_tmp - 2;
            for (localB->last = 0; localB->last <= localB->g_k; localB->last +=
                 2) {
              localB->i_p = localB->last;
              tmp_0 = _mm_loadu_pd(&localB->predit_s_data[localB->i_p]);
              _mm_storeu_pd(&localB->rtu_object_array_F_data[localB->i_p],
                            _mm_sub_pd(_mm_set1_pd(localB->min_range), tmp_0));
            }

            for (localB->last = localB->firstBlockLength_tmp; localB->last <
                 localB->loop_ub; localB->last++) {
              localB->g_k = localB->last;
              localB->rtu_object_array_F_data[localB->g_k] = localB->min_range -
                localB->predit_s_data[localB->g_k];
            }

            ros_code_power_i(localB->rtu_object_array_F_data,
                             localB->rtu_object_array_F_size,
                             localB->rtu_object_array_F_data_c,
                             localB->rtu_object_array_F_size_h, localB);
            localB->rtu_object_array_F_size[0] = 1;
            localB->rtu_object_array_F_size[1] = localB->predit_l_size[1];
            localB->loop_ub = localB->predit_l_size[1];
            localB->g_k = localB->firstBlockLength - 2;
            for (localB->last = 0; localB->last <= localB->g_k; localB->last +=
                 2) {
              localB->i_p = localB->last;
              tmp_0 = _mm_loadu_pd(&localB->predit_l_data[localB->i_p]);
              _mm_storeu_pd(&localB->rtu_object_array_F_data[localB->i_p],
                            _mm_sub_pd(_mm_set1_pd(localB->angle_diff), tmp_0));
            }

            for (localB->last = localB->firstBlockLength; localB->last <
                 localB->loop_ub; localB->last++) {
              localB->g_k = localB->last;
              localB->rtu_object_array_F_data[localB->g_k] = localB->angle_diff
                - localB->predit_l_data[localB->g_k];
            }

            ros_code_power_i(localB->rtu_object_array_F_data,
                             localB->rtu_object_array_F_size, localB->tmp_data_f,
                             localB->tmp_size, localB);
            localB->f_size[0] = 1;
            localB->f_size[1] = localB->rtu_object_array_F_size_h[1];
            localB->loop_ub = localB->rtu_object_array_F_size_h[1];
            localB->firstBlockLength = (localB->rtu_object_array_F_size_h[1] / 2)
              << 1;
            localB->g_k = localB->firstBlockLength - 2;
            for (localB->last = 0; localB->last <= localB->g_k; localB->last +=
                 2) {
              localB->i_p = localB->last;
              tmp_0 = _mm_loadu_pd(&localB->rtu_object_array_F_data_c
                                   [localB->i_p]);
              tmp = _mm_loadu_pd(&localB->tmp_data_f[localB->i_p]);
              _mm_storeu_pd(&localB->f_data[localB->i_p], _mm_add_pd(tmp_0, tmp));
            }

            for (localB->last = localB->firstBlockLength; localB->last <
                 localB->loop_ub; localB->last++) {
              localB->firstBlockLength_tmp = localB->last;
              localB->f_data[localB->firstBlockLength_tmp] =
                localB->rtu_object_array_F_data_c[localB->firstBlockLength_tmp]
                + localB->tmp_data_f[localB->firstBlockLength_tmp];
            }
          } else {
            ros_code_binary_expand_op_f(localB->f_data, localB->f_size,
              rtu_object_array_F, localB->max_Tau_sl_num, localB->predit_s_data,
              localB->predit_s_size, localB->predit_l_data,
              localB->predit_l_size, localB);
          }

          localB->firstBlockLength = localB->f_size[1];
          localB->last = 0;
          while (localB->last <= localB->firstBlockLength - 1) {
            localB->firstBlockLength_tmp = localB->last;
            localB->f_data[localB->firstBlockLength_tmp] = std::sqrt
              (localB->f_data[localB->firstBlockLength_tmp]);
            localB->last++;
          }

          if (localB->nblocks - 1 >= 0) {
            std::memcpy(&localB->sl_distance_data[0], &localB->f_data[0],
                        localB->nblocks * sizeof(real_T));
          }

          ros_code_minimum(localB->sl_distance_data, &localB->sl_distance_size,
                           &localB->min_range, &localB->last);
          if (localB->min_range <= localB->ls_0) {
            localB->last--;
            localB->theta = localB->predit_s_data[localB->last];
            localB->min_range = ros_code_findNearestIndexInF_k
              (rtu_preprocess_global_path_arra, localB->theta,
               rtu_object_array_F[localB->max_Tau_sl_num + 20], -localB->ls_0,
               localB->ls_0, localB);
            localB->x_tmp = rtu_preprocess_global_path_arra[static_cast<int32_T>
              (localB->min_range) + 3999];
            localB->x_tmp_l = localB->predit_l_data[localB->last];
            localB->angle_diff = rtu_preprocess_global_path_arra
              [static_cast<int32_T>(localB->min_range) - 1] - localB->x_tmp_l *
              std::sin(localB->x_tmp);
            localB->S_end = localB->x_tmp_l * std::cos(localB->x_tmp) +
              rtu_preprocess_global_path_arra[static_cast<int32_T>
              (localB->min_range) + 1999];
            localB->theta = rt_atan2d_snf((((localB->c_a_tmp * 5.0 *
              localB->theta + localB->l_step * 4.0) * localB->theta +
              localB->ds_step * 3.0) * localB->theta + localB->p_tmp_n * 2.0) *
              localB->theta + localB->ds_min, 1.0 -
              rtu_preprocess_global_path_arra[static_cast<int32_T>
              (localB->min_range) + 5999] * localB->x_tmp_l) + localB->x_tmp;
            ros_code_wrapToPi_o(&localB->theta, localB);
            ros_cod_calculateVehicleCorners(localB->angle_diff, localB->S_end,
              localB->theta, localB->d_s, localB->sv_0, localB->ddls_coeffs,
              localB->ego_corners_y, localB);
            ros_cod_calculateVehicleCorners(rtu_object_array_C
              [localB->max_Tau_sl_num], rtu_object_array_C
              [localB->max_Tau_sl_num + 10], localB->theta, localB->d_s,
              localB->sv_0, localB->object_corners_x, localB->object_corners_y,
              localB);
            localB->danger_flag[localB->max_Tau_sl_num] = std::fmax
              (ros_code_detectCollision(localB->ddls_coeffs,
                localB->ego_corners_y, localB->object_corners_x,
                localB->object_corners_y, rtu_object_array_C
                [localB->max_Tau_sl_num + 30] * rtu_object_array_C
                [localB->max_Tau_sl_num + 40], localB), ros_code_detectCollision
               (localB->object_corners_x, localB->object_corners_y,
                localB->ddls_coeffs, localB->ego_corners_y, localB->d_s *
                localB->sv_0, localB));
            if (localB->danger_flag[localB->max_Tau_sl_num] == 0.0) {
              ros_cod_calculateVehicleCorners(localB->angle_diff, localB->S_end,
                localB->theta, localB->lv_0, localB->la_0, localB->ddls_coeffs,
                localB->ego_corners_y, localB);
              ros_cod_calculateVehicleCorners(rtu_object_array_C
                [localB->max_Tau_sl_num], rtu_object_array_C
                [localB->max_Tau_sl_num + 10], localB->theta, localB->lv_0,
                localB->la_0, localB->object_corners_x, localB->object_corners_y,
                localB);
              localB->min_range = localB->lv_0 * localB->la_0;
              if (std::fmax(ros_code_detectCollision(localB->ddls_coeffs,
                    localB->ego_corners_y, localB->object_corners_x,
                    localB->object_corners_y, localB->min_range, localB),
                            ros_code_detectCollision(localB->object_corners_x,
                    localB->ego_corners_y, localB->object_corners_y,
                    localB->ego_corners_y, localB->min_range, localB)) == 1.0) {
                localB->min_range = localB->angle_diff -
                  rtu_object_array_C[localB->max_Tau_sl_num];
                localB->angle_diff = localB->S_end - rtu_object_array_C
                  [localB->max_Tau_sl_num + 10];
                localB->object_distance[localB->max_Tau_sl_num] = std::sqrt
                  (localB->min_range * localB->min_range + localB->angle_diff *
                   localB->angle_diff);
              }
            }
          }

          localB->max_Tau_sl_num++;
        }
      }

      y = true;
      localB->last = 0;
      exitg1 = false;
      while ((!exitg1) && (localB->last < 3)) {
        if (!(localB->danger_flag[localB->last] == 0.0)) {
          y = false;
          exitg1 = true;
        } else {
          localB->last++;
        }
      }

      if (y) {
        localB->tmp_data_d[0] = localB->sa3 * 60.0;
        localB->tmp_data_d[1] = localB->sa4 * 24.0;
        localB->p_tmp_n = localB->ls_1 * 6.0;
        localB->tmp_data_d[2] = localB->p_tmp_n;
        ros_code_roots(localB->tmp_data_d, localB->roots_ddds_data,
                       &localB->distances_size, localB);
        localB->real_roots_ddds_size = localB->distances_size;
        localB->nblocks = localB->distances_size;
        for (localB->last = 0; localB->last < localB->nblocks; localB->last++) {
          localB->real_roots_ddds_data[localB->last] = localB->
            roots_ddds_data[localB->last].re;
        }

        localB->loop_ub = localB->distances_size;
        localB->nblocks = localB->distances_size;
        for (localB->last = 0; localB->last < localB->nblocks; localB->last++) {
          b_data[localB->last] = (localB->real_roots_ddds_data[localB->last] <
            0.0);
        }

        localB->nblocks = localB->distances_size;
        for (localB->last = 0; localB->last < localB->nblocks; localB->last++) {
          c_data[localB->last] = (localB->real_roots_ddds_data[localB->last] >
            localB->S_start);
        }

        localB->max_Tau_sl_num = 0;
        while (localB->max_Tau_sl_num <= localB->loop_ub - 1) {
          if (b_data[localB->max_Tau_sl_num] || c_data[localB->max_Tau_sl_num])
          {
            localB->real_roots_ddds_data[localB->max_Tau_sl_num] = 0.0;
          }

          localB->max_Tau_sl_num++;
        }

        localB->ddls_coeffs[0] = localB->sa3 * 20.0;
        localB->ddls_coeffs[1] = localB->sa4 * 12.0;
        localB->ddls_coeffs[2] = localB->p_tmp_n;
        localB->ddls_coeffs[3] = localB->rtb_Tau_sl_tmp_i * 2.0;
        ros_code_polyval_d(localB->ddls_coeffs, localB->real_roots_ddds_data,
                           &localB->real_roots_ddds_size, localB->tmp_data_dh,
                           &localB->tmp_size_p, localB);
        ros_code_abs(localB->tmp_data_dh, &localB->tmp_size_p,
                     localB->tmp_data_d, &localB->tmp_size_px);
        localB->min_range = ros_code_maximum(localB->tmp_data_d,
          &localB->tmp_size_px);
        if (localB->min_range > ros_code_P.reduce_param[2]) {
        } else {
          boolean_T guard1{ false };

          localB->p[0] = localB->sa3;
          localB->p[1] = localB->sa4;
          localB->p[2] = localB->ls_1;
          localB->p[3] = localB->rtb_Tau_sl_tmp_i;
          localB->p[4] = localB->p_tmp;
          localB->p[5] = localB->p_tmp_o;
          localB->angle_diff = localB->sa3;
          for (localB->max_Tau_sl_num = 0; localB->max_Tau_sl_num < 5;
               localB->max_Tau_sl_num++) {
            localB->angle_diff = 0.0 * localB->angle_diff + localB->p
              [localB->max_Tau_sl_num + 1];
          }

          localB->p[0] = localB->sa3;
          localB->p[1] = localB->sa4;
          localB->p[2] = localB->ls_1;
          localB->p[3] = localB->rtb_Tau_sl_tmp_i;
          localB->p[4] = localB->p_tmp;
          localB->p[5] = localB->p_tmp_o;
          localB->theta = localB->sa3;
          for (localB->max_Tau_sl_num = 0; localB->max_Tau_sl_num < 5;
               localB->max_Tau_sl_num++) {
            localB->theta = localB->S_start * localB->theta + localB->p
              [localB->max_Tau_sl_num + 1];
          }

          localB->last_path_data[0] = localB->Tau_sl[localB->g] * 5.0;
          localB->last_path_data[1] = localB->Tau_sl[localB->f] * 4.0;
          localB->last_path_data[2] = localB->Tau_sl[localB->p_tmp_a] * 3.0;
          localB->S_end = localB->Tau_sl[localB->p_tmp_j] * 2.0;
          localB->last_path_data[3] = localB->S_end;
          localB->last_path_data[4] = localB->ds_min;
          localB->ddls_coeffs[0] = localB->c_a_tmp * 20.0;
          localB->ddls_coeffs[1] = localB->l_step * 12.0;
          localB->S_start = localB->ds_step * 6.0;
          localB->ddls_coeffs[2] = localB->S_start;
          localB->ddls_coeffs[3] = localB->S_end;
          localB->danger_flag[0] = localB->c_a_tmp * 60.0;
          localB->danger_flag[1] = localB->l_step * 24.0;
          localB->danger_flag[2] = localB->S_start;
          b_x[0] = (localB->danger_flag[0] == 0.0);
          b_x[1] = (localB->danger_flag[1] == 0.0);
          b_x[2] = (localB->S_start == 0.0);
          y = true;
          localB->last = 0;
          exitg1 = false;
          while ((!exitg1) && (localB->last <= 2)) {
            if (!b_x[localB->last]) {
              y = false;
              exitg1 = true;
            } else {
              localB->last++;
            }
          }

          if (y) {
            localB->S_start = ((localB->angle_diff * localB->ddls_coeffs[0] +
                                localB->ddls_coeffs[1]) * localB->angle_diff +
                               localB->S_start) * localB->angle_diff +
              localB->S_end;
          } else {
            ros_code_roots(localB->danger_flag, localB->roots_ddds_data,
                           &localB->distances_size, localB);
            localB->real_roots_ddds_size = localB->distances_size;
            localB->nblocks = localB->distances_size;
            for (localB->last = 0; localB->last < localB->nblocks; localB->last
                 ++) {
              localB->real_roots_ddds_data[localB->last] =
                localB->roots_ddds_data[localB->last].re;
            }

            localB->loop_ub = localB->distances_size;
            localB->nblocks = localB->distances_size;
            for (localB->last = 0; localB->last < localB->nblocks; localB->last
                 ++) {
              b_data[localB->last] = (localB->real_roots_ddds_data[localB->last]
                < localB->angle_diff);
            }

            localB->nblocks = localB->distances_size;
            for (localB->last = 0; localB->last < localB->nblocks; localB->last
                 ++) {
              c_data[localB->last] = (localB->real_roots_ddds_data[localB->last]
                > localB->theta);
            }

            localB->max_Tau_sl_num = 0;
            while (localB->max_Tau_sl_num <= localB->loop_ub - 1) {
              if (b_data[localB->max_Tau_sl_num] || c_data
                  [localB->max_Tau_sl_num]) {
                localB->real_roots_ddds_data[localB->max_Tau_sl_num] =
                  localB->angle_diff;
              }

              localB->max_Tau_sl_num++;
            }

            ros_code_polyval_d(localB->ddls_coeffs, localB->real_roots_ddds_data,
                               &localB->real_roots_ddds_size,
                               localB->tmp_data_dh, &localB->tmp_size_p, localB);
            ros_code_abs(localB->tmp_data_dh, &localB->tmp_size_p,
                         localB->tmp_data_d, &localB->tmp_size_px);
            localB->S_start = ros_code_maximum(localB->tmp_data_d,
              &localB->tmp_size_px);
          }

          y = true;
          localB->firstBlockLength = 0;
          exitg1 = false;
          while ((!exitg1) && (localB->firstBlockLength <= 3)) {
            if (!(localB->ddls_coeffs[localB->firstBlockLength] == 0.0)) {
              y = false;
              exitg1 = true;
            } else {
              localB->firstBlockLength++;
            }
          }

          guard1 = false;
          if (y) {
            if ((((localB->angle_diff * localB->last_path_data[0] +
                   localB->last_path_data[1]) * localB->angle_diff +
                  localB->last_path_data[2]) * localB->angle_diff +
                 localB->S_end) * localB->angle_diff + localB->ds_min >
                localB->dd_ls) {
            } else {
              guard1 = true;
            }
          } else {
            ros_code_roots_n(localB->ddls_coeffs, localB->roots_ddls_data,
                             &localB->distances_size, localB);
            localB->real_roots_ddls_size = localB->distances_size;
            localB->nblocks = localB->distances_size;
            for (localB->last = 0; localB->last < localB->nblocks; localB->last
                 ++) {
              localB->real_roots_ddls_data[localB->last] =
                localB->roots_ddls_data[localB->last].re;
            }

            localB->loop_ub = localB->distances_size;
            localB->nblocks = localB->distances_size;
            for (localB->last = 0; localB->last < localB->nblocks; localB->last
                 ++) {
              b_x[localB->last] = (localB->real_roots_ddls_data[localB->last] <
                                   localB->angle_diff);
            }

            localB->nblocks = localB->distances_size;
            for (localB->last = 0; localB->last < localB->nblocks; localB->last
                 ++) {
              e_data[localB->last] = (localB->real_roots_ddls_data[localB->last]
                > localB->theta);
            }

            localB->max_Tau_sl_num = 0;
            while (localB->max_Tau_sl_num <= localB->loop_ub - 1) {
              if (b_x[localB->max_Tau_sl_num] || e_data[localB->max_Tau_sl_num])
              {
                localB->real_roots_ddls_data[localB->max_Tau_sl_num] =
                  localB->angle_diff;
              }

              localB->max_Tau_sl_num++;
            }

            ros_code_polyval_d0(localB->last_path_data,
                                localB->real_roots_ddls_data,
                                &localB->real_roots_ddls_size,
                                localB->tmp_data_d, &localB->tmp_size_p, localB);
            ros_code_abs(localB->tmp_data_d, &localB->tmp_size_p,
                         localB->real_roots_ddls_data, &localB->tmp_size_px);
            if (ros_code_maximum(localB->real_roots_ddls_data,
                                 &localB->tmp_size_px) > localB->dd_ls) {
            } else {
              guard1 = true;
            }
          }

          if (guard1) {
            localB->sa2++;
            for (localB->last = 0; localB->last < 13; localB->last++) {
              localB->rest_path[(static_cast<int32_T>(localB->sa2) +
                                 localDW->SFunction_DIMS2[0] * localB->last) - 1]
                = localB->Tau_sl[localDW->SFunction_DIMS4[0] * localB->last +
                localB->i];
            }

            localB->rest_path[(static_cast<int32_T>(localB->sa2) +
                               localDW->SFunction_DIMS2[0] * 13) - 1] =
              localB->min_range;
            localB->rest_path[(static_cast<int32_T>(localB->sa2) +
                               localDW->SFunction_DIMS2[0] * 14) - 1] =
              localB->S_start;
            localB->rest_path[(static_cast<int32_T>(localB->sa2) +
                               localDW->SFunction_DIMS2[0] * 15) - 1] =
              ros_code_minimum_o(localB->object_distance);
          }
        }
      }

      localB->i++;
    }

    localB->rest_path[localDW->SFunction_DIMS2[0] - 1] = localB->sa2;
  }

  // MATLAB Function: '<S3>/costCalculate' incorporates:
  //   Constant: '<S3>/Constant'
  //   Constant: '<S3>/Constant1'
  //   Constant: '<S3>/Constant2'
  //   MATLAB Function: '<S3>/reducePath'
  //   MATLAB Function: '<S3>/sampleTrajectory'

  localB->d_s = localB->rest_path[localDW->SFunction_DIMS2[0] - 1];
  localDW->SFunction_DIMS2_k[0] = localDW->SFunction_DIMS2[0];
  localDW->SFunction_DIMS2_k[1] = 14;
  localB->nblocks = localDW->SFunction_DIMS2[0] * 14;
  if (localB->nblocks - 1 >= 0) {
    std::memset(&localB->local_path_F[0], 0, localB->nblocks * sizeof(real_T));
  }

  localB->local_path_F[localDW->SFunction_DIMS2[0] - 1] = localB->d_s;
  localB->i = 0;
  while (localB->i <= static_cast<int32_T>(localB->d_s) - 1) {
    localB->angle_diff = localB->rest_path[localDW->SFunction_DIMS2[0] * 12 +
      localB->i];
    localB->sa3 = localB->rest_path[localDW->SFunction_DIMS2[0] * 5 + localB->i];
    localB->p[0] = localB->sa3;
    localB->sa4 = localB->rest_path[(localDW->SFunction_DIMS2[0] << 2) +
      localB->i];
    localB->p[1] = localB->sa4;
    localB->ls_1 = localB->rest_path[localDW->SFunction_DIMS2[0] * 3 + localB->i];
    localB->p[2] = localB->ls_1;
    localB->rtb_Tau_sl_tmp_i = localB->rest_path[(localDW->SFunction_DIMS2[0] <<
      1) + localB->i];
    localB->p[3] = localB->rtb_Tau_sl_tmp_i;
    localB->p_tmp = localB->rest_path[localB->i + localDW->SFunction_DIMS2[0]];
    localB->p[4] = localB->p_tmp;
    localB->p[5] = localB->rest_path[localB->i];
    localB->theta = localB->sa3;
    for (localB->last = 0; localB->last < 5; localB->last++) {
      localB->theta = localB->angle_diff * localB->theta + localB->p
        [localB->last + 1];
    }

    localB->min_range = ros_code_P.sample_param[6] - ((((localB->sa3 * 5.0 *
      localB->angle_diff + localB->sa4 * 4.0) * localB->angle_diff +
      localB->ls_1 * 3.0) * localB->angle_diff + localB->rtb_Tau_sl_tmp_i * 2.0)
      * localB->angle_diff + localB->p_tmp);
    localB->p[0] = localB->rest_path[localDW->SFunction_DIMS2[0] * 11 +
      localB->i];
    localB->p[1] = localB->rest_path[localDW->SFunction_DIMS2[0] * 10 +
      localB->i];
    localB->p[2] = localB->rest_path[localDW->SFunction_DIMS2[0] * 9 + localB->i];
    localB->p[3] = localB->rest_path[(localDW->SFunction_DIMS2[0] << 3) +
      localB->i];
    localB->p[4] = localB->rest_path[localDW->SFunction_DIMS2[0] * 7 + localB->i];
    localB->p[5] = localB->rest_path[localDW->SFunction_DIMS2[0] * 6 + localB->i];
    localB->S_end = localB->p[0];
    for (localB->max_Tau_sl_num = 0; localB->max_Tau_sl_num < 5;
         localB->max_Tau_sl_num++) {
      localB->S_end = localB->theta * localB->S_end + localB->p
        [localB->max_Tau_sl_num + 1];
    }

    for (localB->last = 0; localB->last < 6; localB->last++) {
      localB->local_path_F[localB->i + localDW->SFunction_DIMS2_k[0] *
        localB->last] = localB->rest_path[localDW->SFunction_DIMS2[0] *
        localB->last + localB->i];
    }

    for (localB->last = 0; localB->last < 6; localB->last++) {
      localB->local_path_F[localB->i + localDW->SFunction_DIMS2_k[0] *
        (localB->last + 6)] = localB->rest_path[(localB->last + 6) *
        localDW->SFunction_DIMS2[0] + localB->i];
    }

    localB->local_path_F[localB->i + localDW->SFunction_DIMS2_k[0] * 12] =
      localB->angle_diff;
    localB->local_path_F[localB->i + localDW->SFunction_DIMS2_k[0] * 13] =
      (((((ros_code_P.reduce_param[4] - localB->rest_path
           [localDW->SFunction_DIMS2[0] * 15 + localB->i]) *
          ros_code_P.path_cost_param[3] + std::sqrt(localB->min_range *
           localB->min_range) * ros_code_P.path_cost_param[0]) +
         localB->rest_path[localDW->SFunction_DIMS2[0] * 13 + localB->i] *
         ros_code_P.path_cost_param[4]) + localB->rest_path
        [localDW->SFunction_DIMS2[0] * 14 + localB->i] *
        ros_code_P.path_cost_param[5]) + ros_code_P.path_cost_param[1] * std::
       abs(localB->S_end)) + ros_code_P.path_cost_param[2] * localB->angle_diff;
    localB->i++;
  }

  // End of MATLAB Function: '<S3>/costCalculate'

  // Update for Memory: '<S3>/Memory1' incorporates:
  //   MATLAB Function: '<S3>/pathConvert'

  std::memset(&localDW->Memory1_PreviousInput[0], 0, 15U * sizeof(real_T));

  // MATLAB Function: '<S3>/pathConvert' incorporates:
  //   MATLAB Function: '<S3>/currentStateConvert'
  //   MATLAB Function: '<S3>/sampleTrajectory'

  localB->min_range = localB->local_path_F[localDW->SFunction_DIMS2_k[0] - 1];
  localB->nblocks = 0;
  if ((localB->lastBlockLength != 0) && (localB->min_range >= 1.0)) {
    localB->i = static_cast<int32_T>(localB->min_range);
    localB->sort_all_trajecotry_size[0] = static_cast<int32_T>(localB->min_range);
    localB->sort_all_trajecotry_size[1] = 14;
    for (localB->last = 0; localB->last < 14; localB->last++) {
      for (localB->max_Tau_sl_num = 0; localB->max_Tau_sl_num < localB->i;
           localB->max_Tau_sl_num++) {
        localB->sort_all_trajecotry_data[localB->max_Tau_sl_num +
          static_cast<int32_T>(localB->min_range) * localB->last] =
          localB->local_path_F[localDW->SFunction_DIMS2_k[0] * localB->last +
          localB->max_Tau_sl_num];
      }
    }

    ros_code_sortrows(localB->sort_all_trajecotry_data,
                      localB->sort_all_trajecotry_size, localB);
    localB->nblocks = 1;
    localB->dd_ls = localB->sort_all_trajecotry_data
      [localB->sort_all_trajecotry_size[0] * 12];
    localB->ls_0 = 0.0;
    localB->lv_0 = 0.0;
    localB->t[20] = 1.0;
    localB->t[0] = 0.0;
    for (localB->last = 0; localB->last < 19; localB->last++) {
      localB->t[localB->last + 1] = (static_cast<real_T>(localB->last) + 1.0) *
        0.05;
    }

    for (localB->i = 0; localB->i < 21; localB->i++) {
      if (localB->t[localB->i] >= localB->dd_ls) {
        localB->t[localB->i] = localB->dd_ls;
      }

      localB->sa3 = localB->sort_all_trajecotry_data
        [localB->sort_all_trajecotry_size[0] * 5];
      localB->p[0] = localB->sa3;
      localB->sa4 = localB->sort_all_trajecotry_data
        [localB->sort_all_trajecotry_size[0] << 2];
      localB->p[1] = localB->sa4;
      localB->ls_1 = localB->sort_all_trajecotry_data
        [localB->sort_all_trajecotry_size[0] * 3];
      localB->p[2] = localB->ls_1;
      localB->rtb_Tau_sl_tmp_i = localB->sort_all_trajecotry_data
        [localB->sort_all_trajecotry_size[0] << 1];
      localB->p[3] = localB->rtb_Tau_sl_tmp_i;
      localB->p_tmp = localB->sort_all_trajecotry_data
        [localB->sort_all_trajecotry_size[0]];
      localB->p[4] = localB->p_tmp;
      localB->p[5] = localB->sort_all_trajecotry_data[0];
      localB->angle_diff = localB->sa3;
      for (localB->last = 0; localB->last < 5; localB->last++) {
        localB->angle_diff = localB->t[localB->i] * localB->angle_diff +
          localB->p[localB->last + 1];
      }

      localB->d_s = (((5.0 * localB->sa3 * localB->t[localB->i] + 4.0 *
                       localB->sa4) * localB->t[localB->i] + 3.0 * localB->ls_1)
                     * localB->t[localB->i] + 2.0 * localB->rtb_Tau_sl_tmp_i) *
        localB->t[localB->i] + localB->p_tmp;
      if (localB->angle_diff >= localB->s_end) {
        localB->angle_diff = localB->s_end;
        localB->d_s = 0.0;
      }

      localB->min_range = ros_code_findNearestIndexInF
        (rtu_preprocess_global_path_arra, localB->angle_diff,
         localB->accurate_index, localB->max_range, localB);
      switch (localB->i + 1) {
       case 1:
        localB->ls_0 = localB->min_range;
        break;

       case 21:
        localB->lv_0 = localB->min_range;
        break;
      }

      localB->sa3 = localB->sort_all_trajecotry_data
        [localB->sort_all_trajecotry_size[0] * 11];
      localB->p[0] = localB->sa3;
      localB->sa4 = localB->sort_all_trajecotry_data
        [localB->sort_all_trajecotry_size[0] * 10];
      localB->p[1] = localB->sa4;
      localB->ls_1 = localB->sort_all_trajecotry_data
        [localB->sort_all_trajecotry_size[0] * 9];
      localB->p[2] = localB->ls_1;
      localB->rtb_Tau_sl_tmp_i = localB->sort_all_trajecotry_data
        [localB->sort_all_trajecotry_size[0] << 3];
      localB->p[3] = localB->rtb_Tau_sl_tmp_i;
      localB->p_tmp = localB->sort_all_trajecotry_data
        [localB->sort_all_trajecotry_size[0] * 7];
      localB->p[4] = localB->p_tmp;
      localB->p[5] = localB->sort_all_trajecotry_data
        [localB->sort_all_trajecotry_size[0] * 6];
      localB->mean_angle = localB->sa3;
      for (localB->max_Tau_sl_num = 0; localB->max_Tau_sl_num < 5;
           localB->max_Tau_sl_num++) {
        localB->mean_angle = localB->angle_diff * localB->mean_angle + localB->
          p[localB->max_Tau_sl_num + 1];
      }

      localB->d_ls = (((5.0 * localB->sa3 * localB->angle_diff + 4.0 *
                        localB->sa4) * localB->angle_diff + 3.0 * localB->ls_1) *
                      localB->angle_diff + 2.0 * localB->rtb_Tau_sl_tmp_i) *
        localB->angle_diff + localB->p_tmp;
      localB->angle_diff = localB->d_ls * localB->d_s;
      localB->sv_0 = 1.0 - rtu_preprocess_global_path_arra[static_cast<int32_T>
        (localB->min_range) + 5999] * localB->mean_angle;
      localB->la_0 = rtu_preprocess_global_path_arra[static_cast<int32_T>
        (localB->min_range) + 3999];
      localB->theta = rt_atan2d_snf(localB->d_ls, localB->sv_0) + localB->la_0;
      ros_code_wrapToPi(&localB->theta, localB);
      localB->d_ls = (localB->theta - localB->ds) / 0.05;
      localB->ds = localB->theta;
      rty_predict_state[localB->i] = rtu_preprocess_global_path_arra[
        static_cast<int32_T>(localB->min_range) - 1] - std::sin(localB->la_0) *
        localB->mean_angle;
      rty_predict_state[localB->i + 21] = std::cos(localB->la_0) *
        localB->mean_angle + rtu_preprocess_global_path_arra[static_cast<int32_T>
        (localB->min_range) + 1999];
      rty_predict_state[localB->i + 42] = localB->theta;
      rty_predict_state[localB->i + 63] = std::sqrt(localB->d_s * localB->d_s *
        (localB->sv_0 * localB->sv_0) + localB->angle_diff * localB->angle_diff);
      rty_predict_state[localB->i + 84] = localB->d_ls;
      rty_predict_state[localB->i + 105] = localB->t[localB->i];
    }

    // Update for Memory: '<S3>/Memory1' incorporates:
    //   MATLAB Function: '<S3>/currentStateConvert'

    for (localB->last = 0; localB->last < 6; localB->last++) {
      localDW->Memory1_PreviousInput[localB->last] =
        localB->sort_all_trajecotry_data[localB->sort_all_trajecotry_size[0] *
        localB->last];
      localDW->Memory1_PreviousInput[localB->last + 6] =
        localB->sort_all_trajecotry_data[(localB->last + 6) *
        localB->sort_all_trajecotry_size[0]];
    }

    localDW->Memory1_PreviousInput[12] = rtu_clock;
    localDW->Memory1_PreviousInput[13] = localB->ls_0;
    localDW->Memory1_PreviousInput[14] = localB->lv_0;
  } else {
    for (localB->i = 0; localB->i < 21; localB->i++) {
      rty_predict_state[localB->i] = localB->mean_angle;
      rty_predict_state[localB->i + 21] = localB->d_ls;
      rty_predict_state[localB->i + 42] = localB->ds;
      rty_predict_state[localB->i + 63] = 0.0;
      rty_predict_state[localB->i + 84] = 0.0;
      rty_predict_state[localB->i + 105] = 0.0;
    }
  }

  *rty_get_local_path = localB->nblocks;
  localDW->SFunction_DIMS3[0] = 51;
  localDW->SFunction_DIMS3[1] = 2;
  localDW->SFunction_DIMS3[2] = static_cast<int32_T>(std::fmin
    (static_cast<real_T>(localDW->SFunction_DIMS2_k[0]), 500.0));

  // Update for Memory: '<S3>/Memory'
  for (localB->i = 0; localB->i < 5; localB->i++) {
    localDW->Memory_PreviousInput[localB->i] = rtu_state_C[localB->i];
  }

  // End of Update for Memory: '<S3>/Memory'
}

//
// File trailer for generated code.
//
// [EOF]
//
