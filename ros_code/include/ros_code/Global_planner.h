//
// File: Global_planner.h
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
#ifndef RTW_HEADER_Global_planner_h_
#define RTW_HEADER_Global_planner_h_
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "ros_code_types.h"

extern "C" {

#include "rt_nonfinite.h"

}
// Block signals for system '<Root>/Global_planner'
  struct B_Global_planner_ros_code_T
{
  real_T trigo_interp_data[199998];
  real_T tmp_data[199998];
  real_T param_new_data[99999];
  real_T X_interp_data[99999];
  real_T Y_interp_data[99999];
  real_T cos_interp_data[99999];
  real_T sin_interp_data[99999];
  real_T new_Theta_interp_data[99999];
  real_T curvature_data[99999];
  real_T ddy_data[99999];
  SL_Bus_ros_code_nav_msgs_Path b_varargout_2;
  SL_Bus_ros_code_visualization_msgs_MarkerArray In1_f;// '<S13>/In1'
  SL_Bus_ros_code_visualization_msgs_MarkerArray b_varargout_2_m;
  real_T distances[2000];
  real_T pp_coefs_data[76];
  real_T c_coefs_data[76];
  real_T tmp_data_c[20];
  real_T rty_global_path_array_data[20];
  real_T y_data[20];
  real_T x_data[20];
  real_T y_data_k[20];
  real_T s_data[20];
  real_T md_data[20];
  real_T dvdf_data[19];
  real_T dx_data[19];
  char_T b_zeroDelimTopic[52];
  real_T dv[4];
  real_T b_coefs_data[4];
  real_T b_c_data[4];
  real_T eulZYX[3];
  real_T aSinInput;
  real_T d_data;
  real_T x_data_c;
  real_T global_path_num;
  real_T new_point_num;
  real_T b_a;
  real_T matrix_idx_2;
  real_T matrix_idx_3;
  real_T eulZYX_tmp;
  real_T eulZYX_tmp_b;
  real_T eulZYX_tmp_p;
  real_T eulZYX_tmp_c;
  real_T yit;
  real_T xloc;
  real_T d31;
  real_T dnnm2;
  real_T r;
  real_T divdifij;
  real_T b_c_data_tmp;
  real_T dnnm2_tmp;
  real_T d31_tmp;
  real_T aSinInput_f;
  real_T d_data_g;
  real_T x_data_g;
  real_T b_b;
  real_T eul_tmp;
  real_T eul_tmp_m;
  real_T eul_tmp_n;
  real_T eul_tmp_p;
  int32_T param_new_size[2];
  int32_T X_interp_size[2];
  int32_T Y_interp_size[2];
  int32_T cos_interp_size[2];
  int32_T new_Theta_interp_size[2];
  int32_T tmp_size[2];
  int32_T tmp_size_l[2];
  int32_T x_size[2];
  int32_T pp_breaks_size[2];
  int32_T pp_coefs_size[2];
  int32_T y_size[2];
  int32_T g_data;
  int32_T h_data;
  int32_T i;
  int32_T loop_ub;
  int32_T d_size;
  int32_T x_size_j;
  int32_T rty_global_path_array_size;
  int32_T new_Theta_interp_size_tmp;
  int32_T loop_ub_tmp;
  int32_T nx;
  int32_T nd2;
  int32_T low_ip1;
  int32_T high_i;
  int32_T mid_i;
  int32_T y_size_idx_0;
  int32_T nx_d;
}

;

// Block states (default storage) for system '<Root>/Global_planner'
struct DW_Global_planner_ros_code_T {
  ros_slroscpp_internal_block_S_T obj; // '<S9>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_o;// '<S8>/SourceBlock'
};

// Parameters for system: '<Root>/Global_planner'
struct P_Global_planner_ros_code_T_ {
  SL_Bus_ros_code_nav_msgs_Path Out1_Y0;// Computed Parameter: Out1_Y0
                                           //  Referenced by: '<S14>/Out1'

  SL_Bus_ros_code_nav_msgs_Path Constant_Value;// Computed Parameter: Constant_Value
                                                  //  Referenced by: '<S9>/Constant'

  SL_Bus_ros_code_visualization_msgs_MarkerArray Out1_Y0_j;// Computed Parameter: Out1_Y0_j
                                                              //  Referenced by: '<S13>/Out1'

  SL_Bus_ros_code_visualization_msgs_MarkerArray Constant_Value_f;// Computed Parameter: Constant_Value_f
                                                                     //  Referenced by: '<S8>/Constant'

  real_T preprocess_global_path_array_Y0;
                          // Computed Parameter: preprocess_global_path_array_Y0
                             //  Referenced by: '<S11>/preprocess_global_path_array'

  real_T get_global_pose_Y0;           // Computed Parameter: get_global_pose_Y0
                                          //  Referenced by: '<S11>/get_global_pose'

  real_T global_path_array_Y0;       // Computed Parameter: global_path_array_Y0
                                        //  Referenced by: '<S11>/global_path_array'

};

extern void ros_code_Global_planner_Init(real_T *rty_get_global_pose, real_T
  rty_preprocess_global_path_arra[10000], real_T rty_global_path_array[60],
  B_Global_planner_ros_code_T *localB, DW_Global_planner_ros_code_T *localDW,
  P_Global_planner_ros_code_T *localP);
extern void ros_code_Global_planner(real_T *rty_get_global_pose, real_T
  rty_preprocess_global_path_arra[10000], real_T rty_global_path_array[60],
  real_T rty_object_array_F[30], real_T rty_object_array_C[50],
  B_Global_planner_ros_code_T *localB);
extern void ros_code_Global_planner_Term(DW_Global_planner_ros_code_T *localDW);

#endif                                 // RTW_HEADER_Global_planner_h_

//
// File trailer for generated code.
//
// [EOF]
//
