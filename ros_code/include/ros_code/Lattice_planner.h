//
// File: Lattice_planner.h
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
#ifndef RTW_HEADER_Lattice_planner_h_
#define RTW_HEADER_Lattice_planner_h_
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "ros_code_types.h"

extern "C" {

#include "rt_nonfinite.h"

}
// Block signals for system '<Root>/Lattice_planner'
  struct B_Lattice_planner_ros_code_T
{
  real_T Tau_sl[1625000];              // '<S3>/sampleTrajectory'
  real_T rest_path[800000];            // '<S3>/reducePath'
  real_T sort_all_trajecotry_data[700000];
  real_T local_path_F[700000];         // '<S3>/costCalculate'
  real_T ycol_data[50000];
  int32_T idx_data[50000];
  int32_T iwork_data[50000];
  real_T accurate_distance_data[2000];
  real_T distances_data[2000];
  real_T rtu_preprocess_global_path_arra[2000];
  real_T tmp_data[2000];
  real_T distances_data_c[2000];
  real_T y_data[2000];
  real_T distances_data_k[2000];
  real_T y_data_c[2000];
  real_T in3_data[2000];
  real_T tmp_data_b[2000];
  real_T tmp_data_p[2000];
  real_T predit_s_data[500];
  real_T predit_l_data[500];
  real_T sl_distance_data[500];
  real_T f_data[500];
  real_T rtu_object_array_F_data[500];
  real_T rtu_object_array_F_data_c[500];
  real_T tmp_data_f[500];
  real_T in2_data[500];
  real_T tmp_data_g[500];
  real_T tmp_data_g1[500];
  real_T in2_data_m[500];
  real_T approximate_distances[200];
  real_T t[21];
  creal_T At_data[9];
  creal_T b_A_data[9];
  creal_T b_A_data_n[9];
  real_T predict_state_F[9];           // '<S3>/predictState'
  real_T a_data[9];
  real_T T_data[9];
  real_T A_data[9];
  real_T b_a_data[9];
  real_T current_state_F[8];           // '<S3>/currentStateConvert'
  real_T rotated_corners[8];
  real_T half_length[8];
  creal_T roots_ddls_data[3];
  creal_T eiga_data[3];
  creal_T y_data_p[3];
  creal_T f_data_l[3];
  creal_T in1_data[3];
  real_T p[6];
  real_T last_path_data[5];
  creal_T roots_ddds_data[2];
  real_T ddls_coeffs[4];
  real_T ego_corners_y[4];
  real_T object_corners_x[4];
  real_T object_corners_y[4];
  real_T ctmp[4];
  real_T a_data_j[4];
  real_T object_distance[3];
  real_T danger_flag[3];
  real_T real_roots_ddls_data[3];
  real_T tmp_data_d[3];
  real_T b_V_data[3];
  real_T ctmp_g[3];
  real_T v[3];
  real_T work_data[3];
  real_T in2_data_l[3];
  real_T real_roots_ddds_data[2];
  real_T tmp_data_dh[2];
  real_T tau_data[2];
  real_T in2_data_d[2];
  creal_T atmp;
  creal_T ctemp;
  creal_T shift;
  creal_T ascale;
  real_T s_end;
  real_T accurate_index;
  real_T ds;
  real_T angle_diff;
  real_T d_s;
  real_T d_ls;
  real_T dd_ls;
  real_T mean_angle;
  real_T min_range;
  real_T max_range;
  real_T theta;
  real_T x_data;
  real_T L_min;
  real_T l_step;
  real_T ds_min;
  real_T ds_step;
  real_T sv_0;
  real_T ls_0;
  real_T lv_0;
  real_T la_0;
  real_T sa2;
  real_T sl_index;
  real_T sa3;
  real_T sa4;
  real_T S_start;
  real_T S_end;
  real_T ls_1;
  real_T c_a_tmp;
  real_T x_tmp;
  real_T x_tmp_l;
  real_T rtb_Tau_sl_tmp;
  real_T rtb_Tau_sl_tmp_o;
  real_T rtb_Tau_sl_tmp_b;
  real_T rtb_Tau_sl_tmp_n;
  real_T rtb_Tau_sl_tmp_bs;
  real_T rtb_Tau_sl_tmp_l;
  real_T rtb_Tau_sl_tmp_h;
  real_T rtb_Tau_sl_tmp_bn;
  real_T rtb_Tau_sl_tmp_d;
  real_T rtb_Tau_sl_tmp_e;
  real_T rtb_Tau_sl_tmp_bj;
  real_T rtb_Tau_sl_tmp_tmp;
  real_T rtb_Tau_sl_tmp_j;
  real_T rtb_Tau_sl_tmp_tmp_f;
  real_T rtb_Tau_sl_tmp_a;
  real_T rtb_Tau_sl_tmp_ju;
  real_T rtb_Tau_sl_tmp_tmp_j;
  real_T rtb_Tau_sl_tmp_o4;
  real_T rtb_Tau_sl_tmp_ny;
  real_T min_range_tmp;
  real_T rtb_Tau_sl_tmp_i;
  real_T p_tmp;
  real_T p_tmp_o;
  real_T p_tmp_n;
  real_T in2;
  real_T y_data_tmp;
  real_T p_m;
  real_T in3;
  real_T lambda;
  real_T anrm;
  real_T absxk;
  real_T cfromc;
  real_T ctoc;
  real_T cfrom1;
  real_T cto1;
  real_T stemp_im_tmp;
  real_T anorm;
  real_T scale;
  real_T ssq;
  real_T colscale;
  real_T absxk_c;
  real_T t_m;
  real_T ar;
  real_T ai;
  real_T t1_re;
  real_T t1_im;
  real_T ad22_im;
  real_T shift_im;
  real_T eshift_re;
  real_T eshift_im;
  real_T shift_tmp;
  real_T g2;
  real_T f2s;
  real_T di;
  real_T scale_m;
  real_T x;
  real_T fs_re;
  real_T fs_im;
  real_T gs_re;
  real_T gs_im;
  real_T a;
  real_T SMLNUM;
  real_T tst;
  real_T htmp1;
  real_T ab;
  real_T ba;
  real_T aa;
  real_T h12;
  real_T h21s;
  real_T a__4;
  real_T v_tmp;
  real_T p_j;
  real_T bcmax;
  real_T bcmis;
  real_T scale_h;
  real_T z;
  real_T tau;
  real_T alpha1;
  real_T xnorm;
  real_T half_length_c;
  real_T half_width;
  real_T rotated_corners_tmp;
  real_T ar_c;
  real_T ai_p;
  real_T br;
  real_T bi;
  real_T brm;
  real_T bim;
  real_T p_p;
  real_T in3_a;
  real_T p_e;
  real_T in3_ax;
  real_T g2_a;
  real_T d;
  real_T f2s_i;
  real_T scale_l;
  real_T x_o;
  real_T fs_re_o;
  real_T fs_im_i;
  real_T gs_re_f;
  real_T gs_im_i;
  real_T ego_x;
  real_T ego_y;
  real_T d_f;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  real_T v1;
  real_T v2;
  real_T in6;
  real_T xnorm_g;
  real_T a_c;
  real_T scale_o;
  real_T absxk_l;
  real_T t_mv;
  real_T min_range_m;
  real_T max_range_c;
  real_T x_data_f;
  real_T z1_data;
  real_T varargout_1;
  real_T q;
  real_T x_data_p;
  real_T varargout_1_e;
  real_T q_o;
  real_T min_range_h;
  real_T max_range_l;
  real_T absxr;
  real_T delta1;
  int32_T predit_s_size[2];
  int32_T predit_l_size[2];
  int32_T f_size[2];
  int32_T sort_all_trajecotry_size[2];
  int32_T rtu_object_array_F_size[2];
  int32_T rtu_object_array_F_size_h[2];
  int32_T tmp_size[2];
  int32_T tmp_size_m[2];
  int32_T in2_size[2];
  int32_T tmp_size_mc[2];
  int32_T tmp_size_h[2];
  int32_T a_size[2];
  int32_T T_size[2];
  int32_T A_size[2];
  int32_T At_size[2];
  int32_T a_size_c[2];
  int32_T f;
  int32_T g;
  int32_T firstBlockLength;
  int32_T lastBlockLength;
  int32_T nblocks;
  int32_T g_k;
  int32_T last;
  int32_T max_Tau_sl_num;
  int32_T i;
  int32_T loop_ub;
  int32_T accurate_distance_size;
  int32_T distances_size;
  int32_T sl_distance_size;
  int32_T real_roots_ddds_size;
  int32_T real_roots_ddls_size;
  int32_T rtu_preprocess_global_path_ar_k;
  int32_T tmp_size_p;
  int32_T tmp_size_px;
  int32_T firstBlockLength_tmp;
  int32_T i_p;
  int32_T p_tmp_a;
  int32_T p_tmp_j;
  int32_T i1;
  int32_T loop_ub_e;
  int32_T scalarLB;
  int32_T vectorUB;
  int32_T i2;
  int32_T k;
  int32_T y_data_tmp_o;
  int32_T loop_ub_b;
  int32_T i3;
  int32_T y_idx_1;
  int32_T scalarLB_a;
  int32_T vectorUB_g;
  int32_T i4;
  int32_T i5;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T loop_ub_ex;
  int32_T in2_size_idx_1;
  int32_T k1;
  int32_T k2;
  int32_T companDim;
  int32_T j;
  int32_T eiga_size;
  int32_T n;
  int32_T c_i;
  int32_T k_f;
  int32_T ii;
  int32_T nzcount;
  int32_T jj;
  int32_T n_h;
  int32_T At;
  int32_T y_size;
  int32_T b_A_size_idx_1;
  int32_T b_tmp;
  int32_T atmp_tmp;
  int32_T b_A_data_tmp;
  int32_T j_e;
  int32_T ifirst;
  int32_T ilastm1;
  int32_T ilastm;
  int32_T iiter;
  int32_T jp1;
  int32_T jiter;
  int32_T nm1;
  int32_T col;
  int32_T b_A_size_idx_0;
  int32_T ctemp_tmp;
  int32_T ctemp_tmp_tmp;
  int32_T ad22_im_tmp;
  int32_T k1_c;
  int32_T k2_a;
  int32_T companDim_d;
  int32_T j_a;
  int32_T f_size_p;
  int32_T istart;
  int32_T jend;
  int32_T i_m;
  int32_T V;
  int32_T n_o;
  int32_T ldh;
  int32_T i_n;
  int32_T L;
  int32_T k_l;
  int32_T nr;
  int32_T hoffset;
  int32_T b_ix;
  int32_T tst_tmp;
  int32_T tst_tmp_p;
  int32_T n_p;
  int32_T in;
  int32_T knt;
  int32_T lastv;
  int32_T c_lastc;
  int32_T g_f;
  int32_T rowleft;
  int32_T b_ix_i;
  int32_T jy;
  int32_T c_ix;
  int32_T loop_ub_o;
  int32_T b_a_size_idx_0;
  int32_T i6;
  int32_T stride_0_0;
  int32_T stride_1_0;
  int32_T i7;
  int32_T loop_ub_k;
  int32_T y_idx_0;
  int32_T scalarLB_i;
  int32_T vectorUB_o;
  int32_T i8;
  int32_T stride_0_0_m;
  int32_T stride_1_0_c;
  int32_T loop_ub_f;
  int32_T in2_size_idx_0;
  int32_T i9;
  int32_T loop_ub_h;
  int32_T y_idx_0_m;
  int32_T scalarLB_ad;
  int32_T vectorUB_k;
  int32_T i10;
  int32_T stride_0_0_p;
  int32_T stride_1_0_b;
  int32_T loop_ub_c;
  int32_T in2_size_idx_0_n;
  int32_T n_i;
  int32_T b_n;
  int32_T b_k;
  int32_T c_i_m;
  int32_T i2_j;
  int32_T b_j;
  int32_T p_ev;
  int32_T q_m;
  int32_T i11;
  int32_T scalarLB_m;
  int32_T vectorUB_j;
  int32_T loop_ub_fo;
  int32_T in3_size;
  int32_T tmp_size_a;
  int32_T tmp_size_g;
  int32_T k_n;
  int32_T b;
  int32_T c;
  int32_T i12;
  int32_T scalarLB_d;
  int32_T b_na;
}

;

// Block states (default storage) for system '<Root>/Lattice_planner'
struct DW_Lattice_planner_ros_code_T {
  real_T Memory_PreviousInput[5];      // '<S3>/Memory'
  real_T Memory1_PreviousInput[15];    // '<S3>/Memory1'
  int32_T SFunction_DIMS4[2];          // '<S3>/sampleTrajectory'
  int32_T SFunction_DIMS2[2];          // '<S3>/reducePath'
  int32_T SFunction_DIMS3[3];          // '<S3>/pathConvert'
  int32_T SFunction_DIMS2_k[2];        // '<S3>/costCalculate'
};

// Parameters for system: '<Root>/Lattice_planner'
struct P_Lattice_planner_ros_code_T_ {
  real_T Memory_InitialCondition;      // Expression: 0
                                          //  Referenced by: '<S3>/Memory'

  real_T Memory1_InitialCondition[15];
                                  // Expression: [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
                                     //  Referenced by: '<S3>/Memory1'

};

extern void ros_code_Lattice_planner_Init(DW_Lattice_planner_ros_code_T *localDW,
  P_Lattice_planner_ros_code_T *localP);
extern void ros_code_Lattice_planner(const real_T rtu_state_C[5], real_T
  rtu_get_global_pose, const real_T rtu_preprocess_global_path_arra[10000],
  const real_T rtu_object_array_F[30], const real_T rtu_object_array_C[50],
  real_T rtu_clock, real_T *rty_get_local_path, real_T rty_predict_state[126],
  real_T rty_current_state_C[5], real_T rty_predict_next_state[3],
  B_Lattice_planner_ros_code_T *localB, DW_Lattice_planner_ros_code_T *localDW);

#endif                                 // RTW_HEADER_Lattice_planner_h_

//
// File trailer for generated code.
//
// [EOF]
//
