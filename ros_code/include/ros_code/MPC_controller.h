//
// File: MPC_controller.h
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
#ifndef RTW_HEADER_MPC_controller_h_
#define RTW_HEADER_MPC_controller_h_
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "ros_code_types.h"

extern "C" {

#include "rtGetInf.h"

}
  extern "C"
{

#include "rt_nonfinite.h"

}

// Block signals for system '<Root>/MPC_controller'
struct B_MPC_controller_ros_code_T {
  sU7yup9HkfLOO3uVZruoOBF_ros_c_T WorkingSet;
  sxn76bLJrqJiWwjGl8YOqSB_ros_c_T QRManager;
  sIBsEwkwZMwV16lGx5frI7G_ros_c_T memspace;
  real_T A[21505];
  real_T B[21505];
  sFUo2n2eWek74Kh1Ligw2mE_ros_c_T CholRegManager;
  real_T A_all[11025];
  real_T A_all_data[10500];
  real_T A_all_data_m[10000];
  real_T Aueq[7056];                   // '<S4>/MPC//buildConstraintMatrix'
  real_T dv[7056];
  real_T B_all[4410];
  real_T B_all_data[4410];
  real_T in1_data[4410];
  real_T B_all_data_c[4200];
  real_T Q[3969];
  real_T Z[2646];                      // '<S4>/MPC//buildPredictionModel'
  real_T dv1[2646];
  real_T R[1764];
  real_T dv2[1764];
  real_T A_all_data_k[525];
  real_T tmp_data[500];
  sizV6IUWKAiWqwEIFf7P38E_ros_c_T solution;
  real_T a[315];
  real_T tmp_data_c[300];
  real_T work[253];
  real_T vn1[253];
  real_T vn2[253];
  real_T work_b[253];
  int8_T A_p[1764];
  int8_T E_2N[1764];
  smUUAx65r5SQ5CSZDAURIoG_ros_c_T QPObjective;
  int32_T jpvt[253];
  real_T tmp_data_cv[120];
  real_T work_f[85];
  real_T x[84];
  real_T Bueq[84];                     // '<S4>/MPC//buildConstraintMatrix'
  real_T lb[84];                       // '<S4>/MPC//buildConstraintMatrix'
  real_T ub[84];                       // '<S4>/MPC//buildConstraintMatrix'
  real_T dv3[84];
  real_T G[63];                        // '<S4>/MPC//buildPredictionModel'
  real_T a_g[63];
  real_T U_max[42];
  real_T U_min[42];
  real_T U_k[42];
  real_T A_21[25];
  real_T A2[25];
  sSOeZ9WO10chPn9Si6PKiCB_ros_c_T options;
  real_T dv4[15];
  real_T dv5[15];
  real_T B2[10];
  real_T dv6[9];
  real_T B1[6];
  real_T dv7[6];
  real_T rtu_current_state[5];
  real_T dv8[4];
  sL9bDKomAYkxZSVrG9w6En_ros_co_T expl_temp;
  int8_T iv[15];
  real_T B1_tmp;
  real_T rtb_diff_U_k_1_idx_0;
  real_T rtb_diff_U_k_1_idx_1;
  real_T rtb_u_ref_idx_0;
  real_T rtb_u_ref_idx_1;
  real_T B1_tmp_tmp;
  real_T A2_tmp;
  real_T colSum;
  real_T H_infnrm;
  real_T f_infnrm;
  real_T b_colSum;
  real_T ub_g;
  real_T maxConstr_new;
  real_T constrViolation;
  real_T tol;
  real_T qtb;
  real_T temp;
  real_T smax;
  real_T s;
  real_T xnorm;
  real_T a_m;
  real_T scale;
  real_T absxk;
  real_T t;
  real_T tolDelta;
  real_T normDelta;
  real_T s_n;
  real_T temp_p;
  real_T tempMaxConstr;
  real_T constrViolation_basicX;
  real_T c;
  real_T b_atmp;
  real_T c_l;
  real_T constrViolation_j;
  real_T tol_d;
  real_T qtb_g;
  real_T c_ld;
  real_T c_c;
  real_T b_s;
  real_T b_temp;
  real_T roe;
  real_T absa;
  real_T absb;
  real_T scale_d;
  real_T ads;
  real_T bds;
  real_T p_max;
  real_T denomTol;
  real_T alphaTemp;
  real_T phaseOneCorrectionX;
  real_T phaseOneCorrectionP;
  real_T pk_corrected;
  real_T ratio_tmp;
  real_T c_d;
  real_T b_SCALED_REG_PRIMAL;
  real_T temp_l;
  real_T denomTol_o;
  real_T alphaTemp_b;
  real_T phaseOneCorrectionX_n;
  real_T phaseOneCorrectionP_b;
  real_T pk_corrected_l;
  real_T scale_h;
  real_T tol_b;
  real_T alpha1;
  real_T temp_d;
  real_T smax_e;
  real_T s_b;
  real_T c_j;
  real_T c_f;
  real_T c_a;
  real_T c_ju;
  real_T c_jz;
  real_T c_o;
  int32_T A_all_size[2];
  int32_T tmp_size[2];
  int32_T A_all_size_n[2];
  int32_T B_all_size[2];
  int32_T tmp_size_i[2];
  int8_T E_2[4];
  int32_T j;
  int32_T b;
  int32_T c_oy;
  int32_T f;
  int32_T y;
  int32_T ab;
  int32_T ib;
  int32_T pb;
  int32_T qb;
  int32_T xb;
  int32_T yb;
  int32_T cc;
  int32_T pc;
  int32_T sc;
  int32_T tc;
  int32_T xc;
  int32_T i;
  int32_T loop_ub;
  int32_T loop_ub_n;
  int32_T vectorUB;
  int32_T E_2N_tmp;
  int32_T qc_tmp;
  int32_T rc_tmp;
  int32_T mUB;
  int32_T mFixed;
  int32_T k;
  int32_T idx;
  int32_T colPos;
  int32_T i_m;
  int32_T b_idx;
  int32_T i_c;
  int32_T b_m;
  int32_T nVar;
  int32_T mTotalWorkingEq;
  int32_T totalRank;
  int32_T ix;
  int32_T iy;
  int32_T b_k;
  int32_T b_idx_m;
  int32_T nfxd;
  int32_T ix_j;
  int32_T iy_h;
  int32_T k_c;
  int32_T u1;
  int32_T i_ct;
  int32_T minmn;
  int32_T ii;
  int32_T nmi;
  int32_T mmi;
  int32_T pvt;
  int32_T b_j;
  int32_T ix_p;
  int32_T iy_p;
  int32_T b_k_a;
  int32_T PROBTYPE_ORIG;
  int32_T nVar_e;
  int32_T mConstr;
  int32_T activeSetChangeID;
  int32_T nVar_a;
  int32_T globalActiveConstrIdx;
  int32_T TYPE;
  int32_T idx_a;
  int32_T iyend;
  int32_T b_ix;
  int32_T b_iy;
  int32_T c_iy;
  int32_T e;
  int32_T ia;
  int32_T b_k_i;
  int32_T nVar_tmp_tmp;
  int32_T ix_l;
  int32_T iy_o;
  int32_T d;
  int32_T ia_o;
  int32_T iAcol;
  int32_T b_ia;
  int32_T mWConstr_tmp_tmp;
  int32_T nVar_tmp_tmp_i;
  int32_T k_f;
  int32_T i_i;
  int32_T ix0_tmp;
  int32_T i_f;
  int32_T ii_g;
  int32_T mmi_c;
  int32_T i_o;
  int32_T lastv;
  int32_T lastc;
  int32_T b_l;
  int32_T mWorkingFixed;
  int32_T totalRank_m;
  int32_T ix_m;
  int32_T iy_c;
  int32_T b_k_f;
  int32_T i_p;
  int32_T idx_e;
  int32_T itau;
  int32_T iaii;
  int32_T lastv_o;
  int32_T lastc_h;
  int32_T ix_l5;
  int32_T nVar_h;
  int32_T i_me;
  int32_T i_mc;
  int32_T k_h;
  int32_T k_cs;
  int32_T ix_k;
  int32_T b_iy_p;
  int32_T nVar_p;
  int32_T mNull;
  int32_T nullStartIdx;
  int32_T b_A_maxDiag_idx;
  int32_T ix_p4;
  int32_T ia_a;
  int32_T b_ix_j;
  int32_T b_jjA;
  int32_T c_ix;
  int32_T nVars;
  int32_T mNull_e;
  int32_T nullStart;
  int32_T lastColC;
  int32_T br;
  int32_T ar;
  int32_T nFixedConstr;
  int32_T nVar_o;
  int32_T idx_b;
  int32_T nDepIneq;
  int32_T k_a;
  int32_T i1;
  int32_T i_g;
  int32_T LD_diagOffset;
  int32_T subMatrixDim;
  int32_T lastDiag;
  int32_T mLB;
  int32_T mLB_e;
  int32_T mLB_f;
  int32_T b_ixlast;
  int32_T b_k_h;
  int32_T k_e;
  int32_T totalEq;
};

extern void ros_code_MPC_controller(real_T rtu_get_local_path, const real_T
  rtu_predict_state[126], const real_T rtu_current_state[5], real_T *rty_v,
  real_T *rty_w, B_MPC_controller_ros_code_T *localB);

#endif                                 // RTW_HEADER_MPC_controller_h_

//
// File trailer for generated code.
//
// [EOF]
//
