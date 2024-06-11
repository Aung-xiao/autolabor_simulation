//
// File: ros_code.h
//
// Code generated for Simulink model 'ros_code'.
//
// Model version                  : 1.5856
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Mon Jun 10 16:04:34 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ros_code_h_
#define RTW_HEADER_ros_code_h_
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "ros_code_types.h"

extern "C" {

#include "rt_nonfinite.h"

}
  extern "C"
{

#include "rtGetInf.h"

}

#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

// Block signals (default storage)
struct B_ros_code_T {
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
  real_T rest_path[62496];             // '<S3>/reducePath'
  real_T sort_all_trajecotry_data[54684];
  real_T local_path_F[54684];          // '<S3>/costCalculate'
  real_T Tau_sl[50778];                // '<S3>/sampleTrajectory'
  SL_Bus_ros_code_nav_msgs_Path b_varargout_2;
  real_T preprocess_global_path_array[10000];// '<S11>/getGlobalPathData'
  snBUc3P0iDgb4fuyQLszkYC_ros_c_T WorkingSet;
  siBmBjpOUwoybpuj9rEfGvD_ros_c_T QRManager;
  svUSr4TrK4x4Kz9rQJTxkkF_ros_c_T CholRegManager;
  sg8qKdtlZ7nXgcAC5MP2QHC_ros_c_T memspace;
  real_T B[5985];
  real_T ycol_data[3906];
  real_T A_all[3025];
  real_T A_all_data[2750];
  SL_Bus_ros_code_visualization_msgs_MarkerArray In1_i;// '<S13>/In1'
  SL_Bus_ros_code_visualization_msgs_MarkerArray b_varargout_2_m;
  real_T A_all_data_c[2500];
  real_T distances[2000];
  real_T accurate_distance_data[2000];
  real_T tmp_data_k[2000];
  real_T tmp_data_c[2000];
  real_T tmp_data_b[2000];
  real_T tmp_data_p[2000];
  real_T in3_data[2000];
  real_T tmp_data_cv[2000];
  real_T tmp_data_f[2000];
  int32_T idx_data[3906];
  int32_T iwork_data[3906];
  real_T Aueq[1936];                   // '<S4>/MPC//buildConstraintMatrix'
  real_T dv[1936];
  real_T B_all[1210];
  real_T B_all_data[1210];
  real_T in1_data[1210];
  real_T B_all_data_g[1100];
  real_T Q[1089];
  real_T Z[726];                       // '<S4>/MPC//buildPredictionModel'
  real_T dv1[726];
  real_T dv2[484];
  real_T A_all_data_g[275];
  real_T tmp_data_m[250];
  sEf9458k7RTCGn6XpAY3FSD_ros_c_T solution;
  real_T approximate_distances[200];
  real_T a[165];
  real_T tmp_data_n[150];
  real_T work[133];
  real_T vn1[133];
  real_T vn2[133];
  real_T work_p[133];
  SL_Bus_ros_code_nav_msgs_Odometry In1_a;// '<S26>/In1'
  SL_Bus_ros_code_nav_msgs_Odometry b_varargout_2_l;
  real_T predit_s_data[100];
  real_T predit_l_data[100];
  real_T sl_distance_data[100];
  real_T n_data[100];
  real_T rtb_object_array_F_data[100];
  real_T rtb_object_array_F_data_j[100];
  real_T tmp_data_d[100];
  real_T in2_data[100];
  real_T tmp_data_g[100];
  real_T tmp_data_l[100];
  real_T in2_data_d[100];
  scRVBsoAowahmPoAIYa5ea_ros_co_T QPObjective;
  real_T pp_coefs_data[76];
  real_T c_coefs_data[76];
  real_T predict_state[66];            // '<S3>/pathConvert'
  int8_T A[484];
  int8_T E_2N[484];
  real_T global_path_array[60];        // '<S11>/getGlobalPathData'
  real_T work_d[45];
  real_T x[44];
  real_T Bueq[44];                     // '<S4>/MPC//buildConstraintMatrix'
  real_T lb[44];                       // '<S4>/MPC//buildConstraintMatrix'
  real_T ub[44];                       // '<S4>/MPC//buildConstraintMatrix'
  real_T dv3[44];
  real_T object_array[40];             // '<S2>/getObjectData'
  real_T G[33];                        // '<S4>/MPC//buildPredictionModel'
  real_T a_l[33];
  real_T object_array_F[30];           // '<S2>/objectConvert'
  real_T A_21[25];
  real_T A2[25];
  real_T U_max[22];
  real_T U_min[22];
  real_T U_k[22];
  real_T tmp_data_o[20];
  real_T rtb_global_path_array_data[20];
  real_T y_data[20];
  real_T x_data[20];
  real_T y_data_b[20];
  real_T s_data[20];
  real_T md_data[20];
  real_T dvdf_data[19];
  real_T dx_data[19];
  sSOeZ9WO10chPn9Si6PKiCB_ros_c_T options;
  creal_T At_data[9];
  creal_T b_A_data[9];
  creal_T b_A_data_n[9];
  real_T dv4[15];
  real_T dv5[15];
  real_T t[11];
  real_T B2[10];
  real_T rtb_object_array_F_data_b[10];
  real_T rtb_object_array_F_data_l[10];
  real_T in2_data_h[10];
  real_T predict_state_F[9];           // '<S3>/predictState'
  real_T a_data[9];
  real_T T_data[9];
  real_T A_data[9];
  real_T b_a_data[9];
  real_T current_state_F[8];           // '<S3>/currentStateConvert'
  char_T b_zeroDelimTopic[52];
  creal_T roots_ddls_data[3];
  creal_T eiga_data[3];
  creal_T y_data_bn[3];
  creal_T f_data[3];
  creal_T in1_data_d[3];
  SL_Bus_ros_code_geometry_msgs_Twist BusAssignment2;// '<Root>/Bus Assignment2' 
  real_T B1[6];
  real_T sa5[6];
  real_T last_path_data[5];
  real_T current_state_C[5];           // '<S7>/MATLAB Function'
  real_T sa4[5];
  creal_T roots_ddds_data[2];
  real_T y[4];
  real_T ddls_coeffs[4];
  real_T object_corners_x[4];
  real_T object_corners_y[4];
  real_T b_coefs_data[4];
  real_T b_c_data[4];
  real_T ctmp[4];
  real_T a_data_e[4];
  real_T eulZYX[3];
  real_T real_roots_ddls_data[3];
  real_T predict_next_state[3];        // '<S3>/predictState'
  real_T tmp_data_bj[3];
  real_T b_V_data[3];
  real_T ctmp_j[3];
  real_T v[3];
  real_T work_data[3];
  real_T in2_data_f[3];
  sL9bDKomAYkxZSVrG9w6En_ros_co_T expl_temp;
  real_T real_roots_ddds_data[2];
  real_T tmp_data_a[2];
  real_T tau_data[2];
  real_T in2_data_j[2];
  creal_T atmp;
  creal_T ctemp;
  creal_T shift;
  creal_T ascale;
  int8_T iv[15];
  real_T get_global_pose;              // '<S11>/getGlobalPathData'
  real_T aSinInput;
  real_T d_data;
  real_T x_data_m;
  real_T object_num;
  real_T ds;
  real_T kappa_x;
  real_T angle_diff;
  real_T d_ls;
  real_T dd_ls;
  real_T dd_s;
  real_T mean_angle;
  real_T min_range;
  real_T max_range;
  real_T ex;
  real_T s;
  real_T sa_0;
  real_T ls_0;
  real_T lv_0;
  real_T la_0;
  real_T sa3;
  real_T sa4_c;
  real_T S_start;
  real_T S_end;
  real_T ls_1;
  real_T start_index;
  real_T global_path_num;
  real_T a_m;
  real_T predict_accurate_index;       // '<S3>/sampleTrajectory'
  real_T rtb_Tau_sl_tmp_tmp;
  real_T rtb_Tau_sl_tmp;
  real_T rtb_Tau_sl_tmp_m;
  real_T c_a_tmp;
  real_T rtb_Tau_sl_tmp_j;
  real_T rtb_Tau_sl_tmp_h;
  real_T rtb_Tau_sl_tmp_c;
  real_T rtb_Tau_sl_tmp_ct;
  real_T rtb_Tau_sl_tmp_tmp_p;
  real_T rtb_Tau_sl_tmp_p;
  real_T rtb_Tau_sl_tmp_a;
  real_T rtb_Tau_sl_tmp_e;
  real_T rtb_Tau_sl_tmp_ax;
  real_T rtb_Tau_sl_tmp_tmp_a;
  real_T rtb_Tau_sl_tmp_i;
  real_T rtb_Tau_sl_tmp_l;
  real_T rtb_Tau_sl_tmp_o;
  real_T rtb_Tau_sl_tmp_o2;
  real_T colSum;
  real_T H_infnrm;
  real_T f_infnrm;
  real_T b_colSum;
  real_T ub_i;
  real_T maxConstr_new;
  real_T constrViolation;
  real_T tol;
  real_T qtb;
  real_T smax;
  real_T s_f;
  real_T b_atmp;
  real_T xnorm;
  real_T a_i;
  real_T scale;
  real_T absxk;
  real_T t_f;
  real_T yit;
  real_T xloc;
  real_T d31;
  real_T dnnm2;
  real_T r;
  real_T divdifij;
  real_T b_c_data_tmp;
  real_T dnnm2_tmp;
  real_T d31_tmp;
  real_T in2;
  real_T y_data_tmp;
  real_T lambda;
  real_T anrm;
  real_T absxk_g;
  real_T cfromc;
  real_T ctoc;
  real_T cfrom1;
  real_T cto1;
  real_T stemp_im_tmp;
  real_T anorm;
  real_T scale_c;
  real_T ssq;
  real_T colscale;
  real_T absxk_o;
  real_T t_l;
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
  real_T x_m;
  real_T fs_re;
  real_T fs_im;
  real_T gs_re;
  real_T gs_im;
  real_T a_c;
  real_T p;
  real_T in3;
  real_T tolDelta;
  real_T normDelta;
  real_T s_fm;
  real_T temp;
  real_T tempMaxConstr;
  real_T constrViolation_basicX;
  real_T c;
  real_T c_p;
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
  real_T p_e;
  real_T bcmax;
  real_T bcmis;
  real_T scale_o;
  real_T z;
  real_T tau;
  real_T alpha1;
  real_T xnorm_h;
  real_T in4;
  real_T b_SCALED_REG_PRIMAL;
  real_T c_l;
  real_T u1;
  real_T temp_h;
  real_T ar_m;
  real_T ai_m;
  real_T br;
  real_T bi;
  real_T brm;
  real_T bim;
  real_T p_max;
  real_T denomTol;
  real_T alphaTemp;
  real_T phaseOneCorrectionX;
  real_T phaseOneCorrectionP;
  real_T pk_corrected;
  real_T ratio;
  real_T u1_h;
  real_T c_c;
  real_T c_c_k;
  real_T b_s;
  real_T b_temp;
  real_T roe;
  real_T absa;
  real_T absb;
  real_T scale_p;
  real_T ads;
  real_T bds;
  real_T p_p;
  real_T in3_p;
  real_T constrViolation_a;
  real_T tol_j;
  real_T qtb_e;
  real_T c_o;
  real_T aSinInput_b;
  real_T d_data_a;
  real_T x_data_g;
  real_T b_b;
  real_T eul_tmp;
  real_T eul_tmp_e;
  real_T eul_tmp_f;
  real_T eul_tmp_h;
  real_T p_ei;
  real_T in3_c;
  real_T g2_a;
  real_T d;
  real_T f2s_d;
  real_T scale_a;
  real_T x_p;
  real_T fs_re_m;
  real_T fs_im_o;
  real_T gs_re_n;
  real_T denomTol_l;
  real_T alphaTemp_p;
  real_T phaseOneCorrectionX_p;
  real_T phaseOneCorrectionP_f;
  real_T pk_corrected_i;
  real_T ratio_o;
  real_T scale_k;
  real_T absxk_i;
  real_T ego_x;
  real_T ego_y;
  real_T d_o;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  real_T v1;
  real_T v2;
  real_T xnorm_m;
  real_T a_cu;
  real_T scale_f;
  real_T absxk_h;
  real_T t_m;
  real_T alpha1_a;
  real_T temp_k;
  real_T in6;
  real_T tol_p;
  real_T x_data_b;
  real_T z1_data;
  real_T varargout_1;
  real_T q;
  real_T smax_c;
  real_T s_n;
  real_T c_i;
  real_T c_m;
  real_T c_j;
  real_T c_e;
  real_T c_mv;
  real_T x_data_m0;
  real_T varargout_1_j;
  real_T q_f;
  real_T c_a;
  real_T bkj;
  real_T s_g;
  real_T s_nr;
  real_T smax_d;
  real_T absxr;
  real_T delta1;
  int32_T g_size[2];
  int32_T n_size[2];
  int32_T sort_all_trajecotry_size[2];
  int32_T param_new_size[2];
  int32_T Y_interp_size[2];
  int32_T cos_interp_size[2];
  int32_T new_Theta_interp_size[2];
  int32_T tmp_size[2];
  int32_T rtb_object_array_F_size[2];
  int32_T rtb_object_array_F_size_j[2];
  int32_T tmp_size_o[2];
  int32_T A_all_size[2];
  int32_T A_all_size_n[2];
  int32_T B_all_size[2];
  int32_T x_size[2];
  int32_T pp_breaks_size[2];
  int32_T pp_coefs_size[2];
  int32_T y_size[2];
  int32_T in2_size[2];
  int32_T tmp_size_i[2];
  int32_T tmp_size_oy[2];
  int32_T a_size[2];
  int32_T T_size[2];
  int32_T A_size[2];
  int32_T At_size[2];
  int32_T a_size_n[2];
  int8_T E_2[4];
  int32_T c_cg;
  int32_T e;
  int32_T g;
  int32_T firstBlockLength;
  int32_T lastBlockLength;
  int32_T nblocks;
  int32_T nx;
  int32_T b;
  int32_T r_f;
  int32_T v_p;
  int32_T y_p;
  int32_T ab_n;
  int32_T ib;
  int32_T pb;
  int32_T qb;
  int32_T xb;
  int32_T yb;
  int32_T cc;
  int32_T xc;
  int32_T i;
  int32_T scalarLB;
  int32_T vectorUB;
  int32_T loop_ub;
  int32_T d_size;
  int32_T x_size_k;
  int32_T accurate_distance_size;
  int32_T b_y_size;
  int32_T sl_distance_size;
  int32_T cg_object_distance_size;
  int32_T real_roots_ddds_size;
  int32_T real_roots_ddls_size;
  int32_T tmp_size_n;
  int32_T rtb_object_array_F_size_o;
  int32_T rtb_object_array_F_size_g;
  int32_T rtb_global_path_array_size;
  int32_T scalarLB_tmp;
  int32_T mUB;
  int32_T mFixed;
  int32_T k;
  int32_T idx;
  int32_T colPos;
  int32_T i_c;
  int32_T b_idx;
  int32_T i_cj;
  int32_T b_m;
  int32_T nVar;
  int32_T mTotalWorkingEq;
  int32_T totalRank;
  int32_T ix;
  int32_T iy;
  int32_T b_k;
  int32_T b_idx_j;
  int32_T nfxd;
  int32_T ii;
  int32_T nmi;
  int32_T mmi;
  int32_T pvt;
  int32_T b_ix;
  int32_T b_iy;
  int32_T c_k;
  int32_T u1_k;
  int32_T i_m;
  int32_T ii_p;
  int32_T mmi_d;
  int32_T i_g;
  int32_T knt;
  int32_T b_k_c;
  int32_T nx_c;
  int32_T nd2;
  int32_T low_ip1;
  int32_T high_i;
  int32_T mid_i;
  int32_T y_size_idx_0;
  int32_T nx_i;
  int32_T yoffset;
  int32_T k_d;
  int32_T d31_tmp_g;
  int32_T s_data_tmp;
  int32_T dnnm2_tmp_l;
  int32_T i_f;
  int32_T loop_ub_d;
  int32_T scalarLB_j;
  int32_T vectorUB_i;
  int32_T i1;
  int32_T k_h;
  int32_T y_data_tmp_n;
  int32_T k1;
  int32_T k2;
  int32_T companDim;
  int32_T j;
  int32_T eiga_size;
  int32_T n;
  int32_T c_i_o;
  int32_T k_c;
  int32_T ii_b;
  int32_T nzcount;
  int32_T jj;
  int32_T n_e;
  int32_T At;
  int32_T y_size_d;
  int32_T b_A_size_idx_1;
  int32_T b_tmp;
  int32_T atmp_tmp;
  int32_T b_A_data_tmp;
  int32_T j_i;
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
  int32_T loop_ub_g;
  int32_T i2;
  int32_T y_idx_1;
  int32_T scalarLB_n;
  int32_T vectorUB_l;
  int32_T i3;
  int32_T i4;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T loop_ub_c;
  int32_T in2_size_idx_1;
  int32_T PROBTYPE_ORIG;
  int32_T nVar_n;
  int32_T mConstr;
  int32_T activeSetChangeID;
  int32_T nVar_p;
  int32_T globalActiveConstrIdx;
  int32_T TYPE;
  int32_T idx_d;
  int32_T iyend;
  int32_T b_ix_o;
  int32_T b_iy_j;
  int32_T c_iy;
  int32_T e_c;
  int32_T ia;
  int32_T b_k_h;
  int32_T nVar_tmp_tmp;
  int32_T ix_d;
  int32_T iy_c;
  int32_T d_p;
  int32_T ia_p;
  int32_T iAcol;
  int32_T b_ia;
  int32_T mWConstr_tmp_tmp;
  int32_T nVar_tmp_tmp_a;
  int32_T idx_o;
  int32_T itau;
  int32_T iaii;
  int32_T lastv;
  int32_T lastc;
  int32_T ix_j;
  int32_T iac;
  int32_T e_p;
  int32_T b_ia_o;
  int32_T k1_l;
  int32_T k2_k;
  int32_T companDim_j;
  int32_T j_f;
  int32_T f_size;
  int32_T istart;
  int32_T jend;
  int32_T i_cm;
  int32_T V;
  int32_T n_f;
  int32_T ldh;
  int32_T i_n;
  int32_T L;
  int32_T k_i;
  int32_T nr;
  int32_T hoffset;
  int32_T b_ix_l;
  int32_T tst_tmp;
  int32_T tst_tmp_i;
  int32_T n_k;
  int32_T in;
  int32_T knt_f;
  int32_T lastv_a;
  int32_T c_lastc;
  int32_T g_d;
  int32_T rowleft;
  int32_T b_ix_e;
  int32_T jy;
  int32_T c_ix;
  int32_T loop_ub_e;
  int32_T b_a_size_idx_0;
  int32_T b_a_size_idx_1;
  int32_T loop_ub_b;
  int32_T i5;
  int32_T scalarLB_a;
  int32_T vectorUB_il;
  int32_T in2_size_f;
  int32_T tmp_size_j;
  int32_T tmp_size_oo;
  int32_T in4_tmp;
  int32_T k_f;
  int32_T nVar_o;
  int32_T i_l;
  int32_T nVar_l;
  int32_T mNull;
  int32_T nullStartIdx;
  int32_T b_A_maxDiag_idx;
  int32_T ix_g;
  int32_T ia_d;
  int32_T b_ix_d;
  int32_T b_jjA;
  int32_T c_ix_j;
  int32_T nVars;
  int32_T mNull_f;
  int32_T nullStart;
  int32_T lastColC;
  int32_T br_j;
  int32_T ar_h;
  int32_T ia_c;
  int32_T cr;
  int32_T c_n;
  int32_T i6;
  int32_T stride_0_0;
  int32_T stride_1_0;
  int32_T k_k;
  int32_T ix_a;
  int32_T b_iy_f;
  int32_T b_j;
  int32_T ia_k;
  int32_T i_b;
  int32_T k_hm;
  int32_T idxRotGCol;
  int32_T QRk0;
  int32_T i7;
  int32_T loop_ub_eg;
  int32_T y_idx_0;
  int32_T scalarLB_h;
  int32_T vectorUB_k;
  int32_T i8;
  int32_T stride_0_0_j;
  int32_T stride_1_0_o;
  int32_T loop_ub_cs;
  int32_T in2_size_idx_0;
  int32_T b_h;
  int32_T mWorkingFixed;
  int32_T totalRank_i;
  int32_T ix_p;
  int32_T iy_f;
  int32_T b_k_e;
  int32_T i_nh;
  int32_T lastv_h;
  int32_T lastc_h;
  int32_T ix_f;
  int32_T iac_i;
  int32_T trueCount;
  int32_T k_f4;
  int32_T i9;
  int32_T loop_ub_cy;
  int32_T y_idx_0_n;
  int32_T scalarLB_he;
  int32_T vectorUB_kq;
  int32_T i10;
  int32_T stride_0_0_h;
  int32_T stride_1_0_b;
  int32_T loop_ub_o;
  int32_T in2_size_idx_0_n;
  int32_T m;
  int32_T n_m;
  int32_T k_ku;
  int32_T c_i_j;
  int32_T i2_h;
  int32_T b_j_f;
  int32_T p_d;
  int32_T q_l;
  int32_T LD_diagOffset;
  int32_T subMatrixDim;
  int32_T lastDiag;
  int32_T jA;
  int32_T jy_k;
  int32_T i11;
  int32_T scalarLB_i;
  int32_T vectorUB_h;
  int32_T loop_ub_m;
  int32_T in3_size;
  int32_T tmp_size_g;
  int32_T tmp_size_l;
  int32_T nFixedConstr;
  int32_T nVar_m;
  int32_T idx_n;
  int32_T nDepIneq;
  int32_T k_g;
  int32_T i12;
  int32_T ix_dj;
  int32_T iy_m;
  int32_T mLB;
  int32_T mUB_f;
  int32_T mFixed_g;
  int32_T k_j;
  int32_T mLB_c;
  int32_T mUB_e;
  int32_T mFixed_m;
  int32_T k_o;
  int32_T mLB_a;
  int32_T mUB_j;
  int32_T mFixed_ga;
  int32_T k_jk;
  int32_T idx_e;
  int32_T iy_j;
  int32_T ix_jb;
  int32_T k_gi;
  int32_T i_o;
  int32_T ix0_tmp;
  int32_T i13;
  int32_T d_h;
  int32_T ix_c;
  int32_T iac_a;
  int32_T d_l;
  int32_T b_ixlast;
  int32_T b_k_j;
  int32_T iy_i;
  int32_T ix_m;
  int32_T k_ft;
  int32_T totalEq;
  int32_T b_idx_o;
  int32_T d_idx;
  int32_T coffset;
  int32_T coffset_i;
  int32_T coffset_e;
  int32_T iy_j0;
  int32_T ix_o;
  int32_T i14;
  int32_T i15;
  boolean_T ddls_coeffs_n[4];
  boolean_T f_data_f[3];
  boolean_T g_data[3];
};

// Block states (default storage) for system '<Root>'
struct DW_ros_code_T {
  ros_slroscpp_internal_block_S_T obj; // '<S6>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_m;// '<S9>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_c;// '<S8>/SourceBlock'
  ros_slroscpp_internal_block_P_T obj_g;// '<S5>/SinkBlock'
  real_T Memory_PreviousInput[5];      // '<S3>/Memory'
  real_T Memory1_PreviousInput[15];    // '<S3>/Memory1'
};

// Parameters (default storage)
struct P_ros_code_T_ {
  SL_Bus_ros_code_nav_msgs_Path Out1_Y0;// Computed Parameter: Out1_Y0
                                           //  Referenced by: '<S14>/Out1'

  SL_Bus_ros_code_nav_msgs_Path Constant_Value;// Computed Parameter: Constant_Value
                                                  //  Referenced by: '<S9>/Constant'

  SL_Bus_ros_code_visualization_msgs_MarkerArray Out1_Y0_p;// Computed Parameter: Out1_Y0_p
                                                              //  Referenced by: '<S13>/Out1'

  SL_Bus_ros_code_visualization_msgs_MarkerArray Constant_Value_n;// Computed Parameter: Constant_Value_n
                                                                     //  Referenced by: '<S8>/Constant'

  SL_Bus_ros_code_nav_msgs_Odometry Out1_Y0_n;// Computed Parameter: Out1_Y0_n
                                                 //  Referenced by: '<S26>/Out1'

  SL_Bus_ros_code_nav_msgs_Odometry Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                        //  Referenced by: '<S6>/Constant'

  SL_Bus_ros_code_geometry_msgs_Twist Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                          //  Referenced by: '<S1>/Constant'

  real_T preprocess_global_path_array_Y0;
                          // Computed Parameter: preprocess_global_path_array_Y0
                             //  Referenced by: '<S11>/preprocess_global_path_array'

  real_T get_global_pose_Y0;           // Computed Parameter: get_global_pose_Y0
                                          //  Referenced by: '<S11>/get_global_pose'

  real_T global_path_array_Y0;       // Computed Parameter: global_path_array_Y0
                                        //  Referenced by: '<S11>/global_path_array'

  real_T Memory_InitialCondition;      // Expression: 0
                                          //  Referenced by: '<S3>/Memory'

  real_T Memory1_InitialCondition[15];
                                  // Expression: [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
                                     //  Referenced by: '<S3>/Memory1'

};

// Real-time Model Data Structure
struct tag_RTM_ros_code_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_ros_code_T ros_code_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_ros_code_T ros_code_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern struct DW_ros_code_T ros_code_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void ros_code_initialize(void);
  extern void ros_code_step(void);
  extern void ros_code_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_ros_code_T *const ros_code_M;

#ifdef __cplusplus

}
#endif

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'ros_code'
//  '<S1>'   : 'ros_code/Blank Message2'
//  '<S2>'   : 'ros_code/Global_planner'
//  '<S3>'   : 'ros_code/Lattice_planner'
//  '<S4>'   : 'ros_code/MPC_controller'
//  '<S5>'   : 'ros_code/Publish2'
//  '<S6>'   : 'ros_code/Subscribe2'
//  '<S7>'   : 'ros_code/current_state_convert1'
//  '<S8>'   : 'ros_code/Global_planner/Subscribe'
//  '<S9>'   : 'ros_code/Global_planner/Subscribe1'
//  '<S10>'  : 'ros_code/Global_planner/getObjectData'
//  '<S11>'  : 'ros_code/Global_planner/get_global_path'
//  '<S12>'  : 'ros_code/Global_planner/objectConvert'
//  '<S13>'  : 'ros_code/Global_planner/Subscribe/Enabled Subsystem'
//  '<S14>'  : 'ros_code/Global_planner/Subscribe1/Enabled Subsystem'
//  '<S15>'  : 'ros_code/Global_planner/get_global_path/getGlobalPathData'
//  '<S16>'  : 'ros_code/Lattice_planner/MATLAB Function'
//  '<S17>'  : 'ros_code/Lattice_planner/costCalculate'
//  '<S18>'  : 'ros_code/Lattice_planner/currentStateConvert'
//  '<S19>'  : 'ros_code/Lattice_planner/pathConvert'
//  '<S20>'  : 'ros_code/Lattice_planner/predictState'
//  '<S21>'  : 'ros_code/Lattice_planner/reducePath'
//  '<S22>'  : 'ros_code/Lattice_planner/sampleTrajectory'
//  '<S23>'  : 'ros_code/MPC_controller/MPC//buildConstraintMatrix'
//  '<S24>'  : 'ros_code/MPC_controller/MPC//buildPredictionModel'
//  '<S25>'  : 'ros_code/MPC_controller/MPC//solveQuadraticProgramming'
//  '<S26>'  : 'ros_code/Subscribe2/Enabled Subsystem'
//  '<S27>'  : 'ros_code/current_state_convert1/MATLAB Function'

#endif                                 // RTW_HEADER_ros_code_h_

//
// File trailer for generated code.
//
// [EOF]
//
