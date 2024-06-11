//
// File: ros_code.cpp
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
#include "ros_code.h"
#include "rtwtypes.h"
#include "ros_code_types.h"
#include <string.h>
#include <math.h>

extern "C" {

#include "rt_nonfinite.h"

}
#include "ros_code_private.h"
#include <emmintrin.h>
#include "rt_defines.h"

// Block signals (default storage)
B_ros_code_T ros_code_B;

// Block states (default storage)
DW_ros_code_T ros_code_DW;

// Real-time model
RT_MODEL_ros_code_T ros_code_M_ = RT_MODEL_ros_code_T();
RT_MODEL_ros_code_T *const ros_code_M = &ros_code_M_;

// Forward declaration for local functions
static void ros_code_binary_expand_op_pijw3(real_T in1[3], const int8_T
  in2_data[], const real_T in3_data[], const int32_T *in3_size, const real_T
  in4_data[], const int32_T *in4_size);
static void ros_code_quat2eul(real_T q[4], real_T eul[3]);
static void ros_code_linspace(real_T d2, real_T n, real_T y_data[], int32_T
  y_size[2]);
static void ros_code_spline(const real_T x_data[], const int32_T x_size[2],
  const real_T y_data[], const int32_T y_size[2], real_T output_breaks_data[],
  int32_T output_breaks_size[2], real_T output_coefs_data[], int32_T
  output_coefs_size[2]);
static void ros_code_interp1(const real_T varargin_1_data[], const int32_T
  varargin_1_size[2], const real_T varargin_2_data[], const int32_T
  *varargin_2_size, const real_T varargin_3_data[], const int32_T
  varargin_3_size[2], real_T Vq_data[], int32_T Vq_size[2]);
static void ros_code_minimum2(const real_T y_data[], const int32_T y_size[2],
  real_T ex_data[], int32_T ex_size[2]);
static void ros_code_maximum2(const real_T y_data[], const int32_T y_size[2],
  real_T ex_data[], int32_T ex_size[2]);
static void ros_code_gradient(const real_T x_data[], const int32_T x_size[2],
  real_T varargout_1_data[], int32_T varargout_1_size[2]);
static void ros_code_power(const real_T a_data[], const int32_T *a_size, real_T
  y_data[], int32_T *y_size);
static void ros_code_binary_expand_op_pijw(real_T in1_data[], int32_T *in1_size,
  real_T in2, const real_T in3[10000], int32_T in4, int32_T in5, const real_T
  in6[5], real_T in7, int32_T in8, int32_T in9);
static void ros_code_wrapToPi(real_T *lambda);
static real_T ros_code_polyval_gh(const real_T p[6], real_T x);
static real_T ros_code_polyval_o(const real_T p[5], real_T x);
static boolean_T ros_code_sortLE(const real_T v_data[], const int32_T v_size[2],
  int32_T idx1, int32_T idx2);
static void ros_code_sortrows(real_T y_data[], const int32_T y_size[2]);
static void ros_code_eye(real_T b_I[3025]);
static void ros_code_binary_expand_op_pij(real_T in1[1210], int32_T in2, int32_T
  in4, int32_T in5, int32_T in6, int32_T in7);
static void ros_code_mtimes(const real_T A[25], const real_T B_data[], const
  int32_T B_size[2], real_T C_data[], int32_T C_size[2]);
static void ros_code_mtimes_d(const real_T B_data[], const int32_T B_size[2],
  real_T C_data[], int32_T C_size[2]);
static void ros_code_mtimes_du(const real_T A_data[], const int32_T A_size[2],
  const real_T B_data[], const int32_T B_size[2], real_T C_data[], int32_T
  C_size[2]);
static void ros_cod_modifyOverheadPhaseOne_(snBUc3P0iDgb4fuyQLszkYC_ros_c_T *obj);
static void ros_code_setProblemType(snBUc3P0iDgb4fuyQLszkYC_ros_c_T *obj,
  int32_T PROBLEM_TYPE);
static real_T ros_code_xnrm2_o(int32_T n, const real_T x[5985], int32_T ix0);
static real_T ros_code_rt_hypotd_snf(real_T u0, real_T u1);
static real_T ros_code_xzlarfg_p(int32_T n, real_T *alpha1, real_T x[5985],
  int32_T ix0);
static void ros_code_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau,
  real_T C[5985], int32_T ic0, real_T work[133]);
static void ros_code_qrf(real_T A[5985], int32_T m, int32_T n, int32_T nfxd,
  real_T tau[45]);
static void ros_code_factorQRE(siBmBjpOUwoybpuj9rEfGvD_ros_c_T *obj, int32_T
  mrows, int32_T ncols);
static void ros_code_computeQ_(siBmBjpOUwoybpuj9rEfGvD_ros_c_T *obj, int32_T
  nrows);
static void ros_code_IndexOfDependentEq_(int32_T depIdx[133], int32_T mFixed,
  int32_T nDep, siBmBjpOUwoybpuj9rEfGvD_ros_c_T *qrmanager, int32_T mRows,
  int32_T nCols);
static void ros_code_countsort(int32_T x[133], int32_T xLen, int32_T workspace
  [133], int32_T xMin, int32_T xMax);
static void ros_code_removeConstr(snBUc3P0iDgb4fuyQLszkYC_ros_c_T *obj, int32_T
  idx_global);
static void ros_code_removeEqConstr(snBUc3P0iDgb4fuyQLszkYC_ros_c_T *obj,
  int32_T idx_global);
static void ros_code_RemoveDependentEq_(sg8qKdtlZ7nXgcAC5MP2QHC_ros_c_T
  *memspace, snBUc3P0iDgb4fuyQLszkYC_ros_c_T *workingset, int32_T *nDepInd,
  siBmBjpOUwoybpuj9rEfGvD_ros_c_T *qrmanager);
static void ros_code_removeAllIneqConstr(snBUc3P0iDgb4fuyQLszkYC_ros_c_T *obj);
static void ros_code_RemoveDependentIneq_(snBUc3P0iDgb4fuyQLszkYC_ros_c_T
  *workingset, siBmBjpOUwoybpuj9rEfGvD_ros_c_T *qrmanager,
  sg8qKdtlZ7nXgcAC5MP2QHC_ros_c_T *memspace, real_T tolfactor);
static void ros_code_factorQR(siBmBjpOUwoybpuj9rEfGvD_ros_c_T *obj, const real_T
  A[5985], int32_T mrows, int32_T ncols);
static real_T ros_code_maxConstraintViolation(snBUc3P0iDgb4fuyQLszkYC_ros_c_T
  *obj, const real_T x[5985]);
static real_T ros_co_maxConstraintViolation_c(snBUc3P0iDgb4fuyQLszkYC_ros_c_T
  *obj, const real_T x[5985]);
static boolean_T ros_cod_feasibleX0ForWorkingSet(real_T workspace[5985], real_T
  xCurrent[45], snBUc3P0iDgb4fuyQLszkYC_ros_c_T *workingset,
  siBmBjpOUwoybpuj9rEfGvD_ros_c_T *qrmanager);
static real_T ros_c_maxConstraintViolation_c3(snBUc3P0iDgb4fuyQLszkYC_ros_c_T
  *obj, const real_T x[45]);
static void ros_code_PresolveWorkingSet(sEf9458k7RTCGn6XpAY3FSD_ros_c_T
  *solution, sg8qKdtlZ7nXgcAC5MP2QHC_ros_c_T *memspace,
  snBUc3P0iDgb4fuyQLszkYC_ros_c_T *workingset, siBmBjpOUwoybpuj9rEfGvD_ros_c_T
  *qrmanager);
static void ros_code_linearForm_(boolean_T obj_hasLinear, int32_T obj_nvar,
  real_T workspace[5985], const real_T H[1936], const real_T f[44], const real_T
  x[45]);
static real_T ros_code_computeFval(const scRVBsoAowahmPoAIYa5ea_ros_co_T *obj,
  real_T workspace[5985], const real_T H[1936], const real_T f[44], const real_T
  x[45]);
static void ros_code_xgemv(int32_T m, int32_T n, const real_T A[1936], int32_T
  lda, const real_T x[45], real_T y[44]);
static void ros_code_computeGrad_StoreHx(scRVBsoAowahmPoAIYa5ea_ros_co_T *obj,
  const real_T H[1936], const real_T f[44], const real_T x[45]);
static real_T ros_code_computeFval_ReuseHx(const scRVBsoAowahmPoAIYa5ea_ros_co_T
  *obj, real_T workspace[5985], const real_T f[44], const real_T x[45]);
static void ros_code_xrotg(real_T *a, real_T *b, real_T *c, real_T *s);
static void ros_code_deleteColMoveEnd(siBmBjpOUwoybpuj9rEfGvD_ros_c_T *obj,
  int32_T idx);
static void ros_cod_computeProjectedHessian(const real_T H[1936],
  svUSr4TrK4x4Kz9rQJTxkkF_ros_c_T *cholmanager, const
  siBmBjpOUwoybpuj9rEfGvD_ros_c_T *qrmanager, sg8qKdtlZ7nXgcAC5MP2QHC_ros_c_T
  *memspace);
static int32_T ros_code_ixamax(int32_T n, const real_T x[2025]);
static void ros_code_fullColLDL2_(svUSr4TrK4x4Kz9rQJTxkkF_ros_c_T *obj, int32_T
  NColsRemain, real_T REG_PRIMAL);
static void ros_code_xgemv_j(int32_T m, int32_T n, const real_T A[2025], int32_T
  ia0, const real_T x[5985], real_T y[45]);
static void ros_code_compute_deltax(const real_T H[1936],
  sEf9458k7RTCGn6XpAY3FSD_ros_c_T *solution, sg8qKdtlZ7nXgcAC5MP2QHC_ros_c_T
  *memspace, const siBmBjpOUwoybpuj9rEfGvD_ros_c_T *qrmanager,
  svUSr4TrK4x4Kz9rQJTxkkF_ros_c_T *cholmanager, const
  scRVBsoAowahmPoAIYa5ea_ros_co_T *objective);
static real_T ros_code_xnrm2_o2(int32_T n, const real_T x[45]);
static void ros_code_xgemv_ju(int32_T m, const real_T A[1980], const real_T x[45],
  real_T y[5985]);
static void ros_code_xgemv_ju2(int32_T m, const real_T A[1980], const real_T x
  [45], real_T y[5985]);
static void ros_code_ratiotest(const real_T solution_xstar[45], const real_T
  solution_searchDir[45], real_T workspace[5985], int32_T workingset_nVar, const
  real_T workingset_Aineq[1980], const real_T workingset_bineq[44], const real_T
  workingset_lb[45], const real_T workingset_ub[45], const int32_T
  workingset_indexLB[45], const int32_T workingset_indexUB[45], const int32_T
  workingset_sizes[5], const int32_T workingset_isActiveIdx[6], const boolean_T
  workingset_isActiveConstr[133], const int32_T workingset_nWConstr[5], real_T
  *toldelta, real_T *alpha, boolean_T *newBlocking, int32_T *constrType, int32_T
  *constrIdx);
static void ros_code_feasibleratiotest(const real_T solution_xstar[45], const
  real_T solution_searchDir[45], real_T workspace[5985], int32_T workingset_nVar,
  const real_T workingset_Aineq[1980], const real_T workingset_bineq[44], const
  real_T workingset_lb[45], const real_T workingset_ub[45], const int32_T
  workingset_indexLB[45], const int32_T workingset_indexUB[45], const int32_T
  workingset_sizes[5], const int32_T workingset_isActiveIdx[6], const boolean_T
  workingset_isActiveConstr[133], const int32_T workingset_nWConstr[5],
  boolean_T isPhaseOne, real_T *alpha, boolean_T *newBlocking, int32_T
  *constrType, int32_T *constrIdx);
static void ros__addBoundToActiveSetMatrix_(snBUc3P0iDgb4fuyQLszkYC_ros_c_T *obj,
  int32_T TYPE, int32_T idx_local);
static void ros_code_compute_lambda(real_T workspace[5985],
  sEf9458k7RTCGn6XpAY3FSD_ros_c_T *solution, const
  scRVBsoAowahmPoAIYa5ea_ros_co_T *objective, const
  siBmBjpOUwoybpuj9rEfGvD_ros_c_T *qrmanager);
static void ros__checkStoppingAndUpdateFval(int32_T *activeSetChangeID, const
  real_T f[44], sEf9458k7RTCGn6XpAY3FSD_ros_c_T *solution,
  sg8qKdtlZ7nXgcAC5MP2QHC_ros_c_T *memspace, const
  scRVBsoAowahmPoAIYa5ea_ros_co_T *objective, snBUc3P0iDgb4fuyQLszkYC_ros_c_T
  *workingset, siBmBjpOUwoybpuj9rEfGvD_ros_c_T *qrmanager, real_T
  options_ObjectiveLimit, int32_T runTimeOptions_MaxIterations, real_T
  runTimeOptions_ConstrRelTolFact, boolean_T updateFval);
static void ros_code_iterate(const real_T H[1936], const real_T f[44],
  sEf9458k7RTCGn6XpAY3FSD_ros_c_T *solution, sg8qKdtlZ7nXgcAC5MP2QHC_ros_c_T
  *memspace, snBUc3P0iDgb4fuyQLszkYC_ros_c_T *workingset,
  siBmBjpOUwoybpuj9rEfGvD_ros_c_T *qrmanager, svUSr4TrK4x4Kz9rQJTxkkF_ros_c_T
  *cholmanager, scRVBsoAowahmPoAIYa5ea_ros_co_T *objective, real_T
  options_ObjectiveLimit, real_T options_StepTolerance, int32_T
  runTimeOptions_MaxIterations, real_T runTimeOptions_ConstrRelTolFact, real_T
  runTimeOptions_ProbRelTolFactor, boolean_T runTimeOptions_RemainFeasible);
static void ros_code_phaseone(const real_T H[1936], const real_T f[44],
  sEf9458k7RTCGn6XpAY3FSD_ros_c_T *solution, sg8qKdtlZ7nXgcAC5MP2QHC_ros_c_T
  *memspace, snBUc3P0iDgb4fuyQLszkYC_ros_c_T *workingset,
  siBmBjpOUwoybpuj9rEfGvD_ros_c_T *qrmanager, svUSr4TrK4x4Kz9rQJTxkkF_ros_c_T
  *cholmanager, const sL9bDKomAYkxZSVrG9w6En_ros_co_T *runTimeOptions,
  scRVBsoAowahmPoAIYa5ea_ros_co_T *objective, sSOeZ9WO10chPn9Si6PKiCB_ros_c_T
  *options);
static int32_T ros_code_RemoveDependentEq__p(sg8qKdtlZ7nXgcAC5MP2QHC_ros_c_T
  *memspace, snBUc3P0iDgb4fuyQLszkYC_ros_c_T *workingset,
  siBmBjpOUwoybpuj9rEfGvD_ros_c_T *qrmanager);
static void ros_code_PresolveWorkingSet_a(sEf9458k7RTCGn6XpAY3FSD_ros_c_T
  *solution, sg8qKdtlZ7nXgcAC5MP2QHC_ros_c_T *memspace,
  snBUc3P0iDgb4fuyQLszkYC_ros_c_T *workingset, siBmBjpOUwoybpuj9rEfGvD_ros_c_T
  *qrmanager);
static boolean_T ros_code_strcmp(const char_T a[8]);
static void ros_code_computeFirstOrderOpt(sEf9458k7RTCGn6XpAY3FSD_ros_c_T
  *solution, const scRVBsoAowahmPoAIYa5ea_ros_co_T *objective, int32_T
  workingset_nVar, const real_T workingset_ATwset[5985], int32_T
  workingset_nActiveConstr, real_T workspace[5985]);
static void ros_code_phaseone_i(const real_T H[1936], const real_T f[44],
  sEf9458k7RTCGn6XpAY3FSD_ros_c_T *solution, sg8qKdtlZ7nXgcAC5MP2QHC_ros_c_T
  *memspace, snBUc3P0iDgb4fuyQLszkYC_ros_c_T *workingset,
  siBmBjpOUwoybpuj9rEfGvD_ros_c_T *qrmanager, svUSr4TrK4x4Kz9rQJTxkkF_ros_c_T
  *cholmanager, scRVBsoAowahmPoAIYa5ea_ros_co_T *objective,
  sSOeZ9WO10chPn9Si6PKiCB_ros_c_T *options, const
  sL9bDKomAYkxZSVrG9w6En_ros_co_T *runTimeOptions);
static void ros_code_driver(const real_T H[1936], const real_T f[44],
  sEf9458k7RTCGn6XpAY3FSD_ros_c_T *solution, sg8qKdtlZ7nXgcAC5MP2QHC_ros_c_T
  *memspace, snBUc3P0iDgb4fuyQLszkYC_ros_c_T *workingset,
  svUSr4TrK4x4Kz9rQJTxkkF_ros_c_T *cholmanager, sL9bDKomAYkxZSVrG9w6En_ros_co_T
  runTimeOptions, siBmBjpOUwoybpuj9rEfGvD_ros_c_T *qrmanager,
  scRVBsoAowahmPoAIYa5ea_ros_co_T *objective);
static void ros_code_quadprog(const real_T H[1936], const real_T f[44], const
  real_T Aineq[1936], const real_T bineq[44], const real_T lb[44], const real_T
  ub[44], real_T x[44], real_T *fval, real_T *exitflag);
static void ros_code_linspace_m(real_T d2, real_T n, real_T y_data[], int32_T
  y_size[2]);
static void ros_co_binary_expand_op_pijw35k(real_T in1_data[], int32_T in1_size
  [2], const real_T in2_data[], const int32_T in2_size[2], const real_T in3[6],
  int32_T in4);
static void ros_code_polyval(const real_T p[6], const real_T x_data[], const
  int32_T x_size[2], real_T y_data[], int32_T y_size[2]);
static void ros_code_binary_expand_op_p(real_T in1_data[], int32_T *in1_size,
  const real_T in2[30], real_T in3, const real_T in4_data[], real_T in5, const
  real_T in6_data[]);
static void ros_code_sqrt(real_T x_data[], const int32_T *x_size);
static void ros_code_minimum(const real_T x_data[], const int32_T *x_size,
  real_T *ex, int32_T *idx);
static void ros_code_power_en(const real_T a_data[], const int32_T a_size[2],
  real_T y_data[], int32_T y_size[2]);
static void ros_code_binary_expand_op(real_T in1_data[], int32_T in1_size[2],
  const real_T in2[30], int32_T in3, const real_T in4_data[], const int32_T
  in4_size[2], const real_T in5_data[], const int32_T in5_size[2]);
static void ros_code_wrapToPi_n(real_T *lambda);
static real_T ros_code_detectCollision(const real_T ego_corners_x[4], const
  real_T ego_corners_y[4], const real_T object_corners_x[4], const real_T
  object_corners_y[4], real_T s_object);
static boolean_T ros_code_anyNonFinite(const real_T x_data[], const int32_T
  x_size[2]);
static void ros_code_sqrt_g(creal_T *x);
static void ros_code_xzlartg_c(const creal_T f, const creal_T g, real_T *cs,
  creal_T *sn);
static void ros_code_xzlartg(const creal_T f, const creal_T g, real_T *cs,
  creal_T *sn, creal_T *r);
static void ros_code_xzhgeqz(const creal_T A_data[], const int32_T A_size[2],
  int32_T ilo, int32_T ihi, int32_T *info, creal_T alpha1_data[], int32_T
  *alpha1_size, creal_T beta1_data[], int32_T *beta1_size);
static void ros_code_rdivide(creal_T in1_data[], int32_T *in1_size, const
  creal_T in2_data[], const int32_T *in2_size);
static void ros_code_eigStandard(const real_T A_data[], const int32_T A_size[2],
  creal_T V_data[], int32_T *V_size);
static void ros_code_xgehrd(real_T a_data[], int32_T a_size[2]);
static real_T ros_code_xnrm2(int32_T n, const real_T x[3]);
static real_T ros_code_xzlarfg(int32_T n, real_T *alpha1, real_T x[3]);
static void ros_code_xdlanv2(real_T *a, real_T *b, real_T *c, real_T *d, real_T *
  rt1r, real_T *rt1i, real_T *rt2r, real_T *rt2i, real_T *cs, real_T *sn);
static int32_T ros_code_xhseqr(real_T h_data[], const int32_T h_size[2]);
static void ros_code_schur(real_T A_data[], int32_T A_size[2], real_T V_data[],
  int32_T V_size[2]);
static void ros_code_eig(const real_T A_data[], const int32_T A_size[2], creal_T
  V_data[], int32_T *V_size);
static void ros_code_roots(const real_T c[3], creal_T r_data[], int32_T *r_size);
static void ros_c_binary_expand_op_pijw35kx(real_T in1_data[], int32_T *in1_size,
  const real_T in2_data[], const int32_T *in2_size, const real_T in3[4], int32_T
  in4);
static void ros_code_polyval_on(const real_T p[4], const real_T x_data[], const
  int32_T *x_size, real_T y_data[], int32_T *y_size);
static void ros_code_abs(const real_T x_data[], const int32_T *x_size, real_T
  y_data[], int32_T *y_size);
static real_T ros_code_maximum(const real_T x_data[], const int32_T *x_size);
static boolean_T ros_code_all(const boolean_T x[4]);
static void ros_code_roots_n(const real_T c[4], creal_T r_data[], int32_T
  *r_size);
static void ros__binary_expand_op_pijw35kxv(real_T in1_data[], int32_T *in1_size,
  const real_T in2_data[], const int32_T *in2_size, const real_T in3[5], int32_T
  in4);
static void ros_code_polyval_ong(const real_T p[5], const real_T x_data[], const
  int32_T *x_size, real_T y_data[], int32_T *y_size);
static boolean_T ros_code_all_j(const boolean_T x[3]);
static void rate_scheduler(void);
int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  return (((numerator < 0) != (denominator < 0)) && (numerator % denominator !=
           0) ? -1 : 0) + numerator / denominator;
}

//
//         This function updates active task flag for each subrate.
//         The function is called at model base rate, hence the
//         generated code self-manages all its subrates.
//
static void rate_scheduler(void)
{
  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (ros_code_M->Timing.TaskCounters.TID[2])++;
  if ((ros_code_M->Timing.TaskCounters.TID[2]) > 4) {// Sample time: [0.1s, 0.0s] 
    ros_code_M->Timing.TaskCounters.TID[2] = 0;
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
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

    y = atan2(static_cast<real_T>(u0_0), static_cast<real_T>(u1_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

static void ros_code_binary_expand_op_pijw3(real_T in1[3], const int8_T
  in2_data[], const real_T in3_data[], const int32_T *in3_size, const real_T
  in4_data[], const int32_T *in4_size)
{
  int32_T loop_ub;

  // Outputs for Atomic SubSystem: '<Root>/current_state_convert1'
  // MATLAB Function: '<S7>/MATLAB Function'
  loop_ub = *in4_size == 1 ? *in3_size : *in4_size;
  for (int32_T i = 0; i < loop_ub; i++) {
    in1[in2_data[0] - 1] = -in3_data[0] * 2.0 * in4_data[0];
  }

  // End of MATLAB Function: '<S7>/MATLAB Function'
  // End of Outputs for SubSystem: '<Root>/current_state_convert1'
}

// Function for MATLAB Function: '<S11>/getGlobalPathData'
static void ros_code_quat2eul(real_T q[4], real_T eul[3])
{
  int32_T d_size;
  int32_T x_size;
  int8_T g_data;
  boolean_T mask1;
  boolean_T mask2;
  ros_code_B.b_b = 1.0 / sqrt(((q[0] * q[0] + q[1] * q[1]) + q[2] * q[2]) + q[3]
    * q[3]);
  q[0] *= ros_code_B.b_b;
  q[1] *= ros_code_B.b_b;
  q[2] *= ros_code_B.b_b;
  ros_code_B.b_b *= q[3];
  ros_code_B.aSinInput_b = (q[1] * ros_code_B.b_b - q[0] * q[2]) * -2.0;
  mask1 = (ros_code_B.aSinInput_b >= 0.99999999999999778);
  mask2 = (ros_code_B.aSinInput_b <= -0.99999999999999778);
  if (ros_code_B.aSinInput_b >= 0.99999999999999778) {
    ros_code_B.aSinInput_b = 1.0;
  }

  if (mask2) {
    ros_code_B.aSinInput_b = -1.0;
  }

  ros_code_B.eul_tmp = q[0] * q[0];
  ros_code_B.eul_tmp_e = q[1] * q[1];
  ros_code_B.eul_tmp_f = q[2] * q[2];
  ros_code_B.eul_tmp_h = ros_code_B.b_b * ros_code_B.b_b;
  eul[0] = rt_atan2d_snf((q[1] * q[2] + q[0] * ros_code_B.b_b) * 2.0,
    ((ros_code_B.eul_tmp + ros_code_B.eul_tmp_e) - ros_code_B.eul_tmp_f) -
    ros_code_B.eul_tmp_h);
  eul[1] = asin(ros_code_B.aSinInput_b);
  eul[2] = rt_atan2d_snf((q[2] * ros_code_B.b_b + q[0] * q[1]) * 2.0,
    ((ros_code_B.eul_tmp - ros_code_B.eul_tmp_e) - ros_code_B.eul_tmp_f) +
    ros_code_B.eul_tmp_h);
  ros_code_B.trueCount = 0;
  if (mask1 || mask2) {
    ros_code_B.trueCount = 1;
  }

  x_size = ros_code_B.trueCount;
  if (ros_code_B.trueCount - 1 >= 0) {
    ros_code_B.x_data_g = ros_code_B.aSinInput_b;
  }

  ros_code_B.k_f4 = 0;
  while (ros_code_B.k_f4 <= ros_code_B.trueCount - 1) {
    if (!rtIsNaN(ros_code_B.x_data_g)) {
      if (ros_code_B.x_data_g < 0.0) {
        ros_code_B.x_data_g = -1.0;
      } else {
        ros_code_B.x_data_g = (ros_code_B.x_data_g > 0.0);
      }
    }

    ros_code_B.k_f4 = 1;
  }

  ros_code_B.k_f4 = 0;
  if (mask1 || mask2) {
    ros_code_B.k_f4 = 1;
  }

  d_size = static_cast<int8_T>(ros_code_B.k_f4);
  if (static_cast<int8_T>(ros_code_B.k_f4) - 1 >= 0) {
    ros_code_B.d_data_a = rt_atan2d_snf(q[1], q[0]);
  }

  if (mask1 || mask2) {
    g_data = 1;
  }

  if (ros_code_B.trueCount == static_cast<int8_T>(ros_code_B.k_f4)) {
    if (ros_code_B.trueCount - 1 >= 0) {
      eul[0] = -ros_code_B.x_data_g * 2.0 * ros_code_B.d_data_a;
    }
  } else {
    ros_code_binary_expand_op_pijw3(eul, &g_data, &ros_code_B.x_data_g, &x_size,
      &ros_code_B.d_data_a, &d_size);
  }

  ros_code_B.trueCount = 0;
  if (mask1 || mask2) {
    ros_code_B.trueCount = 1;
  }

  if (ros_code_B.trueCount - 1 >= 0) {
    eul[2] = 0.0;
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

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
          for (int32_T k = 0; k <= static_cast<int32_T>(n) - 3; k++) {
            y_data[k + 1] = (static_cast<real_T>(k) + 1.0) * delta1 + 1.0;
          }
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S11>/getGlobalPathData'
static void ros_code_spline(const real_T x_data[], const int32_T x_size[2],
  const real_T y_data[], const int32_T y_size[2], real_T output_breaks_data[],
  int32_T output_breaks_size[2], real_T output_coefs_data[], int32_T
  output_coefs_size[2])
{
  boolean_T has_endslopes;
  ros_code_B.nx_i = x_size[1] - 1;
  has_endslopes = (x_size[1] + 2 == y_size[1]);
  if ((x_size[1] <= 2) || ((x_size[1] <= 3) && (!has_endslopes))) {
    if (x_size[1] <= 2) {
      if (x_size[1] + 2 == y_size[1]) {
        ros_code_B.d31_tmp_g = 0;
        ros_code_B.d31 = y_data[ros_code_B.d31_tmp_g];
        if (x_size[1] - 2 >= 0) {
          ros_code_B.k_d = 1;
          ros_code_B.dnnm2 = x_data[ros_code_B.k_d] -
            x_data[ros_code_B.d31_tmp_g];
          ros_code_B.divdifij = (y_data[2] - y_data[ros_code_B.k_d]) /
            ros_code_B.dnnm2;
          ros_code_B.r = (ros_code_B.divdifij - ros_code_B.d31) /
            ros_code_B.dnnm2;
          ros_code_B.divdifij = (y_data[y_size[1] - 1] - ros_code_B.divdifij) /
            ros_code_B.dnnm2;
          ros_code_B.b_coefs_data[0] = (ros_code_B.divdifij - ros_code_B.r) /
            ros_code_B.dnnm2;
          ros_code_B.b_coefs_data[1] = 2.0 * ros_code_B.r - ros_code_B.divdifij;
          ros_code_B.b_coefs_data[2] = ros_code_B.d31;
          ros_code_B.b_coefs_data[3] = y_data[ros_code_B.k_d];
        }

        ros_code_B.k_d = 4;
        for (ros_code_B.yoffset = 0; ros_code_B.yoffset < 4; ros_code_B.yoffset
             ++) {
          ros_code_B.b_c_data[ros_code_B.yoffset] =
            ros_code_B.b_coefs_data[ros_code_B.yoffset];
        }
      } else {
        ros_code_B.k_d = 2;
        ros_code_B.yoffset = 1;
        ros_code_B.nx_i = 0;
        ros_code_B.b_c_data[ros_code_B.nx_i] = (y_data[ros_code_B.yoffset] -
          y_data[ros_code_B.nx_i]) / (x_data[ros_code_B.yoffset] -
          x_data[ros_code_B.nx_i]);
        ros_code_B.b_c_data[ros_code_B.yoffset] = y_data[ros_code_B.nx_i];
      }

      ros_code_B.nx_i = ros_code_B.k_d - 1;
      memcpy(&ros_code_B.b_coefs_data[0], &ros_code_B.b_c_data[0],
             (ros_code_B.nx_i + 1) * sizeof(real_T));
      ros_code_B.nx_i = x_size[1];
      output_breaks_size[0] = 1;
      output_breaks_size[1] = x_size[1];
      if (ros_code_B.nx_i - 1 >= 0) {
        memcpy(&output_breaks_data[0], &x_data[0], ros_code_B.nx_i * sizeof
               (real_T));
      }
    } else {
      ros_code_B.d31_tmp_g = 1;
      ros_code_B.nx_i = 0;
      ros_code_B.divdifij = x_data[ros_code_B.d31_tmp_g];
      ros_code_B.r = x_data[ros_code_B.nx_i];
      ros_code_B.d31 = ros_code_B.divdifij - ros_code_B.r;
      ros_code_B.d31_tmp = y_data[ros_code_B.d31_tmp_g];
      ros_code_B.dnnm2_tmp = y_data[ros_code_B.nx_i];
      ros_code_B.dnnm2 = (ros_code_B.d31_tmp - ros_code_B.dnnm2_tmp) /
        ros_code_B.d31;
      ros_code_B.yoffset = 2;
      ros_code_B.b_c_data_tmp = x_data[ros_code_B.yoffset];
      ros_code_B.b_c_data[ros_code_B.nx_i] = ((y_data[ros_code_B.yoffset] -
        ros_code_B.d31_tmp) / (ros_code_B.b_c_data_tmp - ros_code_B.divdifij) -
        ros_code_B.dnnm2) / (ros_code_B.b_c_data_tmp - ros_code_B.r);
      ros_code_B.b_c_data[ros_code_B.d31_tmp_g] = ros_code_B.dnnm2 -
        ros_code_B.b_c_data[ros_code_B.nx_i] * ros_code_B.d31;
      ros_code_B.b_c_data[ros_code_B.yoffset] = ros_code_B.dnnm2_tmp;
      output_breaks_size[0] = 1;
      output_breaks_size[1] = 2;
      output_breaks_data[ros_code_B.nx_i] = ros_code_B.r;
      output_breaks_data[ros_code_B.d31_tmp_g] = ros_code_B.b_c_data_tmp;
      ros_code_B.k_d = 3;
      for (ros_code_B.yoffset = 0; ros_code_B.yoffset < 3; ros_code_B.yoffset++)
      {
        ros_code_B.nx_i = ros_code_B.yoffset;
        ros_code_B.b_coefs_data[ros_code_B.nx_i] =
          ros_code_B.b_c_data[ros_code_B.nx_i];
      }
    }

    output_coefs_size[0] = 1;
    output_coefs_size[1] = ros_code_B.k_d;
    ros_code_B.nx_i = ros_code_B.k_d - 1;
    memcpy(&output_coefs_data[0], &ros_code_B.b_coefs_data[0], (ros_code_B.nx_i
            + 1) * sizeof(real_T));
  } else {
    int32_T r_tmp;
    int8_T szs_idx_1;
    if (has_endslopes) {
      szs_idx_1 = static_cast<int8_T>(y_size[1] - 2);
      ros_code_B.yoffset = 0;
    } else {
      szs_idx_1 = static_cast<int8_T>(y_size[1]);
      ros_code_B.yoffset = -1;
    }

    ros_code_B.k_d = 0;
    while (ros_code_B.k_d <= ros_code_B.nx_i - 1) {
      ros_code_B.s_data_tmp = ros_code_B.k_d;
      ros_code_B.dx_data[ros_code_B.s_data_tmp] = x_data[ros_code_B.k_d + 1] -
        x_data[ros_code_B.s_data_tmp];
      ros_code_B.d31_tmp_g = ros_code_B.yoffset + ros_code_B.k_d;
      ros_code_B.dvdf_data[ros_code_B.s_data_tmp] = (y_data[ros_code_B.d31_tmp_g
        + 2] - y_data[ros_code_B.d31_tmp_g + 1]) /
        ros_code_B.dx_data[ros_code_B.s_data_tmp];
      ros_code_B.k_d++;
    }

    ros_code_B.k_d = 1;
    while (ros_code_B.k_d + 1 <= ros_code_B.nx_i) {
      ros_code_B.s_data_tmp = ros_code_B.k_d - 1;
      ros_code_B.d31_tmp_g = ros_code_B.k_d;
      ros_code_B.s_data[ros_code_B.d31_tmp_g] =
        (ros_code_B.dvdf_data[ros_code_B.s_data_tmp] *
         ros_code_B.dx_data[ros_code_B.d31_tmp_g] +
         ros_code_B.dx_data[ros_code_B.s_data_tmp] *
         ros_code_B.dvdf_data[ros_code_B.d31_tmp_g]) * 3.0;
      ros_code_B.k_d++;
    }

    if (has_endslopes) {
      ros_code_B.d31 = 0.0;
      ros_code_B.dnnm2 = 0.0;
      ros_code_B.s_data_tmp = 0;
      ros_code_B.s_data[ros_code_B.s_data_tmp] = y_data[ros_code_B.s_data_tmp] *
        ros_code_B.dx_data[1];
      ros_code_B.s_data[x_size[1] - 1] = ros_code_B.dx_data[x_size[1] - 3] *
        y_data[x_size[1] + 1];
    } else {
      ros_code_B.d31_tmp_g = 0;
      ros_code_B.d31 = x_data[2] - x_data[ros_code_B.d31_tmp_g];
      ros_code_B.k_d = x_size[1] - 3;
      ros_code_B.dnnm2_tmp_l = x_size[1] - 1;
      ros_code_B.dnnm2 = x_data[ros_code_B.dnnm2_tmp_l] - x_data[ros_code_B.k_d];
      ros_code_B.divdifij = ros_code_B.dx_data[ros_code_B.d31_tmp_g];
      ros_code_B.s_data_tmp = 1;
      ros_code_B.s_data[ros_code_B.d31_tmp_g] = ((2.0 * ros_code_B.d31 +
        ros_code_B.divdifij) * ros_code_B.dx_data[ros_code_B.s_data_tmp] *
        ros_code_B.dvdf_data[ros_code_B.d31_tmp_g] + ros_code_B.divdifij *
        ros_code_B.divdifij * ros_code_B.dvdf_data[ros_code_B.s_data_tmp]) /
        ros_code_B.d31;
      ros_code_B.s_data_tmp = x_size[1] - 2;
      ros_code_B.divdifij = ros_code_B.dx_data[ros_code_B.s_data_tmp];
      ros_code_B.s_data[ros_code_B.dnnm2_tmp_l] = ((2.0 * ros_code_B.dnnm2 +
        ros_code_B.divdifij) * ros_code_B.dx_data[ros_code_B.k_d] *
        ros_code_B.dvdf_data[ros_code_B.s_data_tmp] + ros_code_B.divdifij *
        ros_code_B.divdifij * ros_code_B.dvdf_data[ros_code_B.k_d]) /
        ros_code_B.dnnm2;
    }

    ros_code_B.d31_tmp_g = 1;
    ros_code_B.dnnm2_tmp_l = 0;
    ros_code_B.r = ros_code_B.dx_data[ros_code_B.d31_tmp_g];
    ros_code_B.md_data[ros_code_B.dnnm2_tmp_l] = ros_code_B.r;
    ros_code_B.s_data_tmp = x_size[1] - 1;
    ros_code_B.divdifij = ros_code_B.dx_data[x_size[1] - 3];
    ros_code_B.md_data[ros_code_B.s_data_tmp] = ros_code_B.divdifij;
    ros_code_B.k_d = 1;
    while (ros_code_B.k_d + 1 <= ros_code_B.nx_i) {
      r_tmp = ros_code_B.k_d;
      ros_code_B.md_data[r_tmp] = (ros_code_B.dx_data[ros_code_B.k_d - 1] +
        ros_code_B.dx_data[r_tmp]) * 2.0;
      ros_code_B.k_d++;
    }

    ros_code_B.r /= ros_code_B.md_data[ros_code_B.dnnm2_tmp_l];
    ros_code_B.md_data[ros_code_B.d31_tmp_g] -= ros_code_B.r * ros_code_B.d31;
    ros_code_B.s_data[ros_code_B.d31_tmp_g] -= ros_code_B.r *
      ros_code_B.s_data[ros_code_B.dnnm2_tmp_l];
    ros_code_B.k_d = 2;
    while (ros_code_B.k_d + 1 <= ros_code_B.nx_i) {
      int32_T r_tmp_0;
      r_tmp = ros_code_B.k_d;
      r_tmp_0 = ros_code_B.k_d - 1;
      ros_code_B.r = ros_code_B.dx_data[r_tmp] / ros_code_B.md_data[r_tmp_0];
      ros_code_B.md_data[r_tmp] -= ros_code_B.dx_data[ros_code_B.k_d - 2] *
        ros_code_B.r;
      ros_code_B.s_data[r_tmp] -= ros_code_B.s_data[r_tmp_0] * ros_code_B.r;
      ros_code_B.k_d++;
    }

    r_tmp = x_size[1] - 2;
    ros_code_B.r = ros_code_B.dnnm2 / ros_code_B.md_data[r_tmp];
    ros_code_B.md_data[ros_code_B.s_data_tmp] -= ros_code_B.divdifij *
      ros_code_B.r;
    ros_code_B.s_data[ros_code_B.s_data_tmp] -= ros_code_B.s_data[r_tmp] *
      ros_code_B.r;
    ros_code_B.s_data[ros_code_B.s_data_tmp] /=
      ros_code_B.md_data[ros_code_B.s_data_tmp];
    ros_code_B.nx_i = x_size[1] - 2;
    while (ros_code_B.nx_i + 1 > 1) {
      ros_code_B.s_data_tmp = ros_code_B.nx_i;
      ros_code_B.s_data[ros_code_B.s_data_tmp] =
        (ros_code_B.s_data[ros_code_B.s_data_tmp] -
         ros_code_B.dx_data[ros_code_B.nx_i - 1] *
         ros_code_B.s_data[ros_code_B.nx_i + 1]) /
        ros_code_B.md_data[ros_code_B.s_data_tmp];
      ros_code_B.nx_i--;
    }

    ros_code_B.s_data[ros_code_B.dnnm2_tmp_l] =
      (ros_code_B.s_data[ros_code_B.dnnm2_tmp_l] - ros_code_B.d31 *
       ros_code_B.s_data[ros_code_B.d31_tmp_g]) /
      ros_code_B.md_data[ros_code_B.dnnm2_tmp_l];
    ros_code_B.k_d = 0;
    while (ros_code_B.k_d <= x_size[1] - 2) {
      ros_code_B.d31_tmp_g = ros_code_B.k_d;
      ros_code_B.divdifij = ros_code_B.dvdf_data[ros_code_B.d31_tmp_g];
      ros_code_B.r = ros_code_B.dx_data[ros_code_B.d31_tmp_g];
      ros_code_B.d31_tmp = ros_code_B.s_data[ros_code_B.d31_tmp_g];
      ros_code_B.d31 = (ros_code_B.divdifij - ros_code_B.d31_tmp) / ros_code_B.r;
      ros_code_B.dnnm2 = (ros_code_B.s_data[ros_code_B.k_d + 1] -
                          ros_code_B.divdifij) / ros_code_B.r;
      ros_code_B.c_coefs_data[ros_code_B.k_d] = (ros_code_B.dnnm2 -
        ros_code_B.d31) / ros_code_B.r;
      ros_code_B.c_coefs_data[(szs_idx_1 + ros_code_B.k_d) - 1] = 2.0 *
        ros_code_B.d31 - ros_code_B.dnnm2;
      ros_code_B.c_coefs_data[((szs_idx_1 - 1) << 1) + ros_code_B.k_d] =
        ros_code_B.d31_tmp;
      ros_code_B.c_coefs_data[3 * (szs_idx_1 - 1) + ros_code_B.k_d] = y_data
        [(ros_code_B.yoffset + ros_code_B.k_d) + 1];
      ros_code_B.k_d++;
    }

    ros_code_B.nx_i = x_size[1];
    output_breaks_size[0] = 1;
    output_breaks_size[1] = x_size[1];
    memcpy(&output_breaks_data[0], &x_data[0], ros_code_B.nx_i * sizeof(real_T));
    output_coefs_size[0] = szs_idx_1 - 1;
    output_coefs_size[1] = 4;
    ros_code_B.nx_i = (szs_idx_1 - 1) << 2;
    if (ros_code_B.nx_i - 1 >= 0) {
      memcpy(&output_coefs_data[0], &ros_code_B.c_coefs_data[0], ros_code_B.nx_i
             * sizeof(real_T));
    }
  }
}

// Function for MATLAB Function: '<S11>/getGlobalPathData'
static void ros_code_interp1(const real_T varargin_1_data[], const int32_T
  varargin_1_size[2], const real_T varargin_2_data[], const int32_T
  *varargin_2_size, const real_T varargin_3_data[], const int32_T
  varargin_3_size[2], real_T Vq_data[], int32_T Vq_size[2])
{
  ros_code_B.y_size_idx_0 = *varargin_2_size;
  ros_code_B.nd2 = *varargin_2_size;
  if (ros_code_B.nd2 - 1 >= 0) {
    memcpy(&ros_code_B.y_data[0], &varargin_2_data[0], ros_code_B.nd2 * sizeof
           (real_T));
  }

  ros_code_B.x_size[0] = 1;
  ros_code_B.x_size[1] = varargin_1_size[1];
  ros_code_B.nd2 = varargin_1_size[1] - 1;
  if (ros_code_B.nd2 >= 0) {
    memcpy(&ros_code_B.x_data[0], &varargin_1_data[0], (ros_code_B.nd2 + 1) *
           sizeof(real_T));
  }

  ros_code_B.nx_c = varargin_1_size[1];
  Vq_size[0] = 1;
  Vq_size[1] = varargin_3_size[1];
  ros_code_B.nd2 = varargin_3_size[1] - 1;
  if (ros_code_B.nd2 >= 0) {
    memset(&Vq_data[0], 0, (ros_code_B.nd2 + 1) * sizeof(real_T));
  }

  if (varargin_3_size[1] != 0) {
    ros_code_B.nd2 = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (ros_code_B.nd2 <= ros_code_B.nx_c - 1) {
        if (rtIsNaN(varargin_1_data[ros_code_B.nd2])) {
          exitg1 = 1;
        } else {
          ros_code_B.nd2++;
        }
      } else {
        if (varargin_1_data[1] < varargin_1_data[0]) {
          ros_code_B.nd2 = ros_code_B.nx_c >> 1;
          ros_code_B.high_i = 0;
          while (ros_code_B.high_i <= ros_code_B.nd2 - 1) {
            ros_code_B.low_ip1 = ros_code_B.high_i;
            ros_code_B.xloc = ros_code_B.x_data[ros_code_B.low_ip1];
            ros_code_B.mid_i = (ros_code_B.nx_c - ros_code_B.high_i) - 1;
            ros_code_B.x_data[ros_code_B.low_ip1] =
              ros_code_B.x_data[ros_code_B.mid_i];
            ros_code_B.x_data[ros_code_B.mid_i] = ros_code_B.xloc;
            ros_code_B.high_i++;
          }

          if (*varargin_2_size > 1) {
            ros_code_B.nx_c = *varargin_2_size;
            ros_code_B.nd2 = *varargin_2_size >> 1;
            ros_code_B.high_i = 0;
            while (ros_code_B.high_i <= ros_code_B.nd2 - 1) {
              ros_code_B.xloc = ros_code_B.y_data[ros_code_B.high_i];
              ros_code_B.low_ip1 = (ros_code_B.nx_c - ros_code_B.high_i) - 1;
              ros_code_B.y_data[ros_code_B.high_i] =
                ros_code_B.y_data[ros_code_B.low_ip1];
              ros_code_B.y_data[ros_code_B.low_ip1] = ros_code_B.xloc;
              ros_code_B.high_i++;
            }
          }
        }

        ros_code_B.y_size[0] = 1;
        ros_code_B.y_size[1] = ros_code_B.y_size_idx_0;
        if (ros_code_B.y_size_idx_0 - 1 >= 0) {
          memcpy(&ros_code_B.y_data_b[0], &ros_code_B.y_data[0],
                 ros_code_B.y_size_idx_0 * sizeof(real_T));
        }

        ros_code_spline(ros_code_B.x_data, ros_code_B.x_size,
                        ros_code_B.y_data_b, ros_code_B.y_size,
                        ros_code_B.y_data, ros_code_B.pp_breaks_size,
                        ros_code_B.pp_coefs_data, ros_code_B.pp_coefs_size);
        ros_code_B.nx_c = 0;
        while (ros_code_B.nx_c <= varargin_3_size[1] - 1) {
          ros_code_B.y_size_idx_0 = ros_code_B.nx_c;
          ros_code_B.yit = varargin_3_data[ros_code_B.y_size_idx_0];
          if (rtIsNaN(ros_code_B.yit)) {
            Vq_data[ros_code_B.y_size_idx_0] = (rtNaN);
          } else {
            if (rtIsNaN(ros_code_B.yit)) {
            } else {
              ros_code_B.high_i = ros_code_B.pp_breaks_size[1];
              ros_code_B.nd2 = 1;
              ros_code_B.low_ip1 = 2;
              while (ros_code_B.high_i > ros_code_B.low_ip1) {
                ros_code_B.mid_i = (ros_code_B.nd2 >> 1) + (ros_code_B.high_i >>
                  1);
                if (((ros_code_B.nd2 & 1) == 1) && ((ros_code_B.high_i & 1) == 1))
                {
                  ros_code_B.mid_i++;
                }

                if (ros_code_B.yit >= ros_code_B.y_data[ros_code_B.mid_i - 1]) {
                  ros_code_B.nd2 = ros_code_B.mid_i;
                  ros_code_B.low_ip1 = ros_code_B.mid_i + 1;
                } else {
                  ros_code_B.high_i = ros_code_B.mid_i;
                }
              }

              ros_code_B.xloc = ros_code_B.yit -
                ros_code_B.y_data[ros_code_B.nd2 - 1];
              ros_code_B.yit = ros_code_B.pp_coefs_data[ros_code_B.nd2 - 1];
              ros_code_B.high_i = 2;
              while (ros_code_B.high_i <= ros_code_B.pp_coefs_size[1]) {
                ros_code_B.yit = ros_code_B.pp_coefs_data[((ros_code_B.high_i -
                  1) * (ros_code_B.pp_breaks_size[1] - 1) + ros_code_B.nd2) - 1]
                  + ros_code_B.xloc * ros_code_B.yit;
                ros_code_B.high_i++;
              }
            }

            Vq_data[ros_code_B.y_size_idx_0] = ros_code_B.yit;
          }

          ros_code_B.nx_c++;
        }

        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
}

// Function for MATLAB Function: '<S11>/getGlobalPathData'
static void ros_code_minimum2(const real_T y_data[], const int32_T y_size[2],
  real_T ex_data[], int32_T ex_size[2])
{
  int32_T nx;
  ex_size[0] = y_size[0];
  ex_size[1] = 2;
  nx = y_size[0] << 1;
  for (int32_T k = 0; k < nx; k++) {
    real_T u1;
    u1 = y_data[k];
    if ((u1 >= 1.0) || rtIsNaN(u1)) {
      ex_data[k] = 1.0;
    } else {
      ex_data[k] = u1;
    }
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
  for (int32_T k = 0; k < nx; k++) {
    real_T u1;
    u1 = y_data[k];
    if ((u1 <= -1.0) || rtIsNaN(u1)) {
      ex_data[k] = -1.0;
    } else {
      ex_data[k] = u1;
    }
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

// Function for MATLAB Function: '<S3>/currentStateConvert'
static void ros_code_power(const real_T a_data[], const int32_T *a_size, real_T
  y_data[], int32_T *y_size)
{
  *y_size = *a_size;
  ros_code_B.k_f = 0;
  while (ros_code_B.k_f <= *a_size - 1) {
    y_data[ros_code_B.k_f] = a_data[ros_code_B.k_f] * a_data[ros_code_B.k_f];
    ros_code_B.k_f++;
  }
}

static void ros_code_binary_expand_op_pijw(real_T in1_data[], int32_T *in1_size,
  real_T in2, const real_T in3[10000], int32_T in4, int32_T in5, const real_T
  in6[5], real_T in7, int32_T in8, int32_T in9)
{
  __m128d tmp;

  // Outputs for Atomic SubSystem: '<Root>/Lattice_planner'
  // MATLAB Function: '<S3>/currentStateConvert'
  ros_code_B.in6 = in6[0];
  ros_code_B.loop_ub_m = in5 - in4;
  ros_code_B.in3_size = ros_code_B.loop_ub_m + 1;
  ros_code_B.scalarLB_i = ((ros_code_B.loop_ub_m + 1) / 2) << 1;

  // End of Outputs for SubSystem: '<Root>/Lattice_planner'
  ros_code_B.vectorUB_h = ros_code_B.scalarLB_i - 2;

  // Outputs for Atomic SubSystem: '<Root>/Lattice_planner'
  // MATLAB Function: '<S3>/currentStateConvert'
  for (ros_code_B.i11 = 0; ros_code_B.i11 <= ros_code_B.vectorUB_h;
       ros_code_B.i11 += 2) {
    tmp = _mm_loadu_pd(&in3[in4 + ros_code_B.i11]);
    _mm_storeu_pd(&ros_code_B.in3_data[ros_code_B.i11], _mm_sub_pd(tmp,
      _mm_set1_pd(ros_code_B.in6)));
  }

  for (ros_code_B.i11 = ros_code_B.scalarLB_i; ros_code_B.i11 <=
       ros_code_B.loop_ub_m; ros_code_B.i11++) {
    ros_code_B.in3_data[ros_code_B.i11] = in3[in4 + ros_code_B.i11] -
      ros_code_B.in6;
  }

  ros_code_power(ros_code_B.in3_data, &ros_code_B.in3_size,
                 ros_code_B.tmp_data_cv, &ros_code_B.tmp_size_g);
  ros_code_B.in6 = in6[1];
  ros_code_B.loop_ub_m = in9 - in8;
  ros_code_B.in3_size = ros_code_B.loop_ub_m + 1;
  ros_code_B.scalarLB_i = ((ros_code_B.loop_ub_m + 1) / 2) << 1;

  // End of Outputs for SubSystem: '<Root>/Lattice_planner'
  ros_code_B.vectorUB_h = ros_code_B.scalarLB_i - 2;

  // Outputs for Atomic SubSystem: '<Root>/Lattice_planner'
  // MATLAB Function: '<S3>/currentStateConvert'
  for (ros_code_B.i11 = 0; ros_code_B.i11 <= ros_code_B.vectorUB_h;
       ros_code_B.i11 += 2) {
    tmp = _mm_loadu_pd(&in3[(in8 + ros_code_B.i11) + 2000]);
    _mm_storeu_pd(&ros_code_B.in3_data[ros_code_B.i11], _mm_sub_pd(tmp,
      _mm_set1_pd(ros_code_B.in6)));
  }

  for (ros_code_B.i11 = ros_code_B.scalarLB_i; ros_code_B.i11 <=
       ros_code_B.loop_ub_m; ros_code_B.i11++) {
    ros_code_B.in3_data[ros_code_B.i11] = in3[(in8 + ros_code_B.i11) + 2000] -
      ros_code_B.in6;
  }

  ros_code_power(ros_code_B.in3_data, &ros_code_B.in3_size,
                 ros_code_B.tmp_data_f, &ros_code_B.tmp_size_l);
  *in1_size = ros_code_B.tmp_size_l == 1 ? ros_code_B.tmp_size_g :
    ros_code_B.tmp_size_l;
  ros_code_B.scalarLB_i = (ros_code_B.tmp_size_g != 1);
  ros_code_B.vectorUB_h = (ros_code_B.tmp_size_l != 1);
  ros_code_B.loop_ub_m = ros_code_B.tmp_size_l == 1 ? ros_code_B.tmp_size_g :
    ros_code_B.tmp_size_l;
  for (ros_code_B.i11 = 0; ros_code_B.i11 < ros_code_B.loop_ub_m; ros_code_B.i11
       ++) {
    in1_data[ros_code_B.i11] = ros_code_B.tmp_data_cv[ros_code_B.i11 *
      ros_code_B.scalarLB_i] * in2 + ros_code_B.tmp_data_f[ros_code_B.i11 *
      ros_code_B.vectorUB_h] * in7;
  }

  // End of Outputs for SubSystem: '<Root>/Lattice_planner'
}

// Function for MATLAB Function: '<S3>/currentStateConvert'
static void ros_code_wrapToPi(real_T *lambda)
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
    ros_code_B.x_data_m0 = *lambda + 3.1415926535897931;
  }

  if (trueCount - 1 >= 0) {
    if (rtIsNaN(*lambda + 3.1415926535897931)) {
      ros_code_B.varargout_1_j = (rtNaN);
    } else if (rtIsInf(*lambda + 3.1415926535897931)) {
      ros_code_B.varargout_1_j = (rtNaN);
    } else if (*lambda + 3.1415926535897931 == 0.0) {
      ros_code_B.varargout_1_j = 0.0;
    } else {
      boolean_T rEQ0;
      ros_code_B.varargout_1_j = fmod(*lambda + 3.1415926535897931,
        6.2831853071795862);
      rEQ0 = (ros_code_B.varargout_1_j == 0.0);
      if (!rEQ0) {
        ros_code_B.q_f = fabs((*lambda + 3.1415926535897931) /
                              6.2831853071795862);
        rEQ0 = !(fabs(ros_code_B.q_f - floor(ros_code_B.q_f + 0.5)) >
                 2.2204460492503131E-16 * ros_code_B.q_f);
      }

      if (rEQ0) {
        ros_code_B.varargout_1_j = 0.0;
      } else if (*lambda + 3.1415926535897931 < 0.0) {
        ros_code_B.varargout_1_j += 6.2831853071795862;
      }
    }

    ros_code_B.x_data_m0 = ros_code_B.varargout_1_j;
  }

  if (trueCount - 1 >= 0) {
    positiveInput_data = ((ros_code_B.x_data_m0 == 0.0) && (*lambda +
      3.1415926535897931 > 0.0));
  }

  if ((trueCount - 1 >= 0) && positiveInput_data) {
    ros_code_B.x_data_m0 = 6.2831853071795862;
  }

  if (c || d) {
    *lambda = ros_code_B.x_data_m0 - 3.1415926535897931;
  }
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
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
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S3>/sampleTrajectory'
static real_T ros_code_polyval_gh(const real_T p[6], real_T x)
{
  real_T y;
  y = p[0];
  for (int32_T k = 0; k < 5; k++) {
    y = x * y + p[k + 1];
  }

  return y;
}

// Function for MATLAB Function: '<S3>/reducePath'
static real_T ros_code_polyval_o(const real_T p[5], real_T x)
{
  return (((x * p[0] + p[1]) * x + p[2]) * x + p[3]) * x + p[4];
}

// Function for MATLAB Function: '<S3>/pathConvert'
static boolean_T ros_code_sortLE(const real_T v_data[], const int32_T v_size[2],
  int32_T idx1, int32_T idx2)
{
  boolean_T p;
  p = true;
  ros_code_B.v1 = v_data[(v_size[0] * 13 + idx1) - 1];
  ros_code_B.v2 = v_data[(v_size[0] * 13 + idx2) - 1];
  if ((!(ros_code_B.v1 == ros_code_B.v2)) && (!(rtIsNaN(ros_code_B.v1) &&
        rtIsNaN(ros_code_B.v2))) && (!(ros_code_B.v1 <= ros_code_B.v2)) &&
      (!rtIsNaN(ros_code_B.v2))) {
    p = false;
  }

  return p;
}

// Function for MATLAB Function: '<S3>/pathConvert'
static void ros_code_sortrows(real_T y_data[], const int32_T y_size[2])
{
  ros_code_B.n_m = y_size[0] + 1;
  ros_code_B.c_i_j = y_size[0];
  if (ros_code_B.c_i_j - 1 >= 0) {
    memset(&ros_code_B.idx_data[0], 0, ros_code_B.c_i_j * sizeof(int32_T));
  }

  ros_code_B.m = 1;
  while (ros_code_B.m <= ros_code_B.n_m - 2) {
    if (ros_code_sortLE(y_data, y_size, ros_code_B.m, ros_code_B.m + 1)) {
      ros_code_B.idx_data[ros_code_B.m - 1] = ros_code_B.m;
      ros_code_B.idx_data[ros_code_B.m] = ros_code_B.m + 1;
    } else {
      ros_code_B.idx_data[ros_code_B.m - 1] = ros_code_B.m + 1;
      ros_code_B.idx_data[ros_code_B.m] = ros_code_B.m;
    }

    ros_code_B.m += 2;
  }

  if ((y_size[0] & 1U) != 0U) {
    ros_code_B.idx_data[y_size[0] - 1] = y_size[0];
  }

  ros_code_B.c_i_j = 2;
  while (ros_code_B.c_i_j < ros_code_B.n_m - 1) {
    ros_code_B.i2_h = ros_code_B.c_i_j << 1;
    ros_code_B.b_j_f = 1;
    ros_code_B.m = ros_code_B.c_i_j + 1;
    while (ros_code_B.m < ros_code_B.n_m) {
      int32_T kEnd;
      int32_T qEnd;
      ros_code_B.p_d = ros_code_B.b_j_f;
      ros_code_B.q_l = ros_code_B.m;
      qEnd = ros_code_B.b_j_f + ros_code_B.i2_h;
      if (qEnd > ros_code_B.n_m) {
        qEnd = ros_code_B.n_m;
      }

      ros_code_B.k_ku = 0;
      kEnd = qEnd - ros_code_B.b_j_f;
      while (ros_code_B.k_ku + 1 <= kEnd) {
        int32_T m_tmp;
        int32_T tmp;
        m_tmp = ros_code_B.idx_data[ros_code_B.q_l - 1];
        tmp = ros_code_B.idx_data[ros_code_B.p_d - 1];
        if (ros_code_sortLE(y_data, y_size, tmp, m_tmp)) {
          ros_code_B.iwork_data[ros_code_B.k_ku] = tmp;
          ros_code_B.p_d++;
          if (ros_code_B.p_d == ros_code_B.m) {
            while (ros_code_B.q_l < qEnd) {
              ros_code_B.k_ku++;
              ros_code_B.iwork_data[ros_code_B.k_ku] =
                ros_code_B.idx_data[ros_code_B.q_l - 1];
              ros_code_B.q_l++;
            }
          }
        } else {
          ros_code_B.iwork_data[ros_code_B.k_ku] = m_tmp;
          ros_code_B.q_l++;
          if (ros_code_B.q_l == qEnd) {
            while (ros_code_B.p_d < ros_code_B.m) {
              ros_code_B.k_ku++;
              ros_code_B.iwork_data[ros_code_B.k_ku] =
                ros_code_B.idx_data[ros_code_B.p_d - 1];
              ros_code_B.p_d++;
            }
          }
        }

        ros_code_B.k_ku++;
      }

      ros_code_B.m = 0;
      while (ros_code_B.m <= kEnd - 1) {
        ros_code_B.idx_data[(ros_code_B.b_j_f + ros_code_B.m) - 1] =
          ros_code_B.iwork_data[ros_code_B.m];
        ros_code_B.m++;
      }

      ros_code_B.b_j_f = qEnd;
      ros_code_B.m = qEnd + ros_code_B.c_i_j;
    }

    ros_code_B.c_i_j = ros_code_B.i2_h;
  }

  ros_code_B.m = y_size[0] - 1;
  for (ros_code_B.n_m = 0; ros_code_B.n_m < 14; ros_code_B.n_m++) {
    ros_code_B.c_i_j = 0;
    while (ros_code_B.c_i_j <= ros_code_B.m) {
      ros_code_B.ycol_data[ros_code_B.c_i_j] = y_data[(y_size[0] *
        ros_code_B.n_m + ros_code_B.idx_data[ros_code_B.c_i_j]) - 1];
      ros_code_B.c_i_j++;
    }

    ros_code_B.c_i_j = 0;
    while (ros_code_B.c_i_j <= ros_code_B.m) {
      y_data[ros_code_B.c_i_j + y_size[0] * ros_code_B.n_m] =
        ros_code_B.ycol_data[ros_code_B.c_i_j];
      ros_code_B.c_i_j++;
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//buildPredictionModel'
static void ros_code_eye(real_T b_I[3025])
{
  memset(&b_I[0], 0, 3025U * sizeof(real_T));
  for (int32_T k = 0; k < 55; k++) {
    b_I[k + 55 * k] = 1.0;
  }
}

static void ros_code_binary_expand_op_pij(real_T in1[1210], int32_T in2, int32_T
  in4, int32_T in5, int32_T in6, int32_T in7)
{
  int32_T in1_size_idx_0;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;

  // Outputs for Atomic SubSystem: '<Root>/MPC_controller'
  // MATLAB Function: '<S4>/MPC//buildPredictionModel'
  in1_size_idx_0 = (in7 - in6) + 1 == 1 ? (in5 - in4) + 1 : (in7 - in6) + 1;
  stride_0_0 = ((in5 - in4) + 1 != 1);
  stride_1_0 = ((in7 - in6) + 1 != 1);
  loop_ub = (in7 - in6) + 1 == 1 ? (in5 - in4) + 1 : (in7 - in6) + 1;
  for (ros_code_B.i15 = 0; ros_code_B.i15 < 22; ros_code_B.i15++) {
    for (ros_code_B.i14 = 0; ros_code_B.i14 < loop_ub; ros_code_B.i14++) {
      ros_code_B.in1_data[ros_code_B.i14 + in1_size_idx_0 * ros_code_B.i15] =
        in1[(ros_code_B.i14 * stride_0_0 + in4) + 55 * ros_code_B.i15] + in1
        [(ros_code_B.i14 * stride_1_0 + in6) + 55 * ros_code_B.i15];
    }
  }

  for (ros_code_B.i15 = 0; ros_code_B.i15 < 22; ros_code_B.i15++) {
    for (ros_code_B.i14 = 0; ros_code_B.i14 < in1_size_idx_0; ros_code_B.i14++)
    {
      in1[(in2 + ros_code_B.i14) + 55 * ros_code_B.i15] =
        ros_code_B.in1_data[in1_size_idx_0 * ros_code_B.i15 + ros_code_B.i14];
    }
  }

  // End of MATLAB Function: '<S4>/MPC//buildPredictionModel'
  // End of Outputs for SubSystem: '<Root>/MPC_controller'
}

// Function for MATLAB Function: '<S4>/MPC//buildPredictionModel'
static void ros_code_mtimes(const real_T A[25], const real_T B_data[], const
  int32_T B_size[2], real_T C_data[], int32_T C_size[2])
{
  C_size[0] = 5;
  C_size[1] = B_size[1];
  for (int32_T j = 0; j < B_size[1]; j++) {
    int32_T boffset;
    ros_code_B.coffset_e = j * 5;
    boffset = j * B_size[0];
    for (int32_T i = 0; i < 5; i++) {
      ros_code_B.s_nr = 0.0;
      for (int32_T k = 0; k < 5; k++) {
        ros_code_B.s_nr += A[k * 5 + i] * B_data[boffset + k];
      }

      C_data[ros_code_B.coffset_e + i] = ros_code_B.s_nr;
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//buildPredictionModel'
static void ros_code_mtimes_d(const real_T B_data[], const int32_T B_size[2],
  real_T C_data[], int32_T C_size[2])
{
  static const int8_T b[15] = { 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 };

  C_size[0] = 3;
  C_size[1] = B_size[1];
  for (int32_T j = 0; j < B_size[1]; j++) {
    int32_T boffset;
    ros_code_B.coffset_i = j * 3;
    boffset = j * B_size[0];
    for (int32_T i = 0; i < 3; i++) {
      ros_code_B.s_g = 0.0;
      for (int32_T k = 0; k < 5; k++) {
        ros_code_B.s_g += static_cast<real_T>(b[k * 3 + i]) * B_data[boffset + k];
      }

      C_data[ros_code_B.coffset_i + i] = ros_code_B.s_g;
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//buildPredictionModel'
static void ros_code_mtimes_du(const real_T A_data[], const int32_T A_size[2],
  const real_T B_data[], const int32_T B_size[2], real_T C_data[], int32_T
  C_size[2])
{
  C_size[0] = 3;
  C_size[1] = B_size[1];
  for (int32_T j = 0; j < B_size[1]; j++) {
    int32_T boffset;
    ros_code_B.coffset = j * 3;
    boffset = j * B_size[0];
    C_data[ros_code_B.coffset] = 0.0;
    C_data[ros_code_B.coffset + 1] = 0.0;
    C_data[ros_code_B.coffset + 2] = 0.0;
    for (int32_T k = 0; k < A_size[1]; k++) {
      int32_T aoffset;
      aoffset = k * 3;
      ros_code_B.bkj = B_data[boffset + k];
      C_data[ros_code_B.coffset] += A_data[aoffset] * ros_code_B.bkj;
      C_data[ros_code_B.coffset + 1] += A_data[aoffset + 1] * ros_code_B.bkj;
      C_data[ros_code_B.coffset + 2] += A_data[aoffset + 2] * ros_code_B.bkj;
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_cod_modifyOverheadPhaseOne_(snBUc3P0iDgb4fuyQLszkYC_ros_c_T *obj)
{
  for (int32_T idx = 0; idx < obj->sizes[0]; idx++) {
    obj->ATwset[45 * idx + 44] = 0.0;
  }

  for (int32_T idx = 0; idx < 44; idx++) {
    obj->Aineq[45 * idx + 44] = -1.0;
  }

  obj->indexLB[obj->sizes[3] - 1] = 45;
  obj->lb[44] = obj->SLACK0;
  for (int32_T idx = obj->isActiveIdx[2]; idx <= obj->nActiveConstr; idx++) {
    obj->ATwset[45 * (idx - 1) + 44] = -1.0;
  }

  if (obj->nWConstr[4] > 0) {
    for (int32_T idx = 0; idx <= obj->sizesNormal[4]; idx++) {
      obj->isActiveConstr[(obj->isActiveIdx[4] + idx) - 1] = false;
    }
  }

  obj->isActiveConstr[obj->isActiveIdx[4] - 2] = false;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_setProblemType(snBUc3P0iDgb4fuyQLszkYC_ros_c_T *obj,
  int32_T PROBLEM_TYPE)
{
  switch (PROBLEM_TYPE) {
   case 3:
    obj->nVar = 44;
    obj->mConstr = obj->mConstrOrig;
    if (obj->nWConstr[4] > 0) {
      for (int32_T idx_lb = -1; idx_lb < obj->sizesNormal[4] - 1; idx_lb++) {
        obj->isActiveConstr[obj->isActiveIdxNormal[4] + idx_lb] =
          obj->isActiveConstr[obj->isActiveIdx[4] + idx_lb];
      }
    }

    for (int32_T idx_lb = 0; idx_lb < 5; idx_lb++) {
      obj->sizes[idx_lb] = obj->sizesNormal[idx_lb];
    }

    for (int32_T idx_lb = 0; idx_lb < 6; idx_lb++) {
      obj->isActiveIdx[idx_lb] = obj->isActiveIdxNormal[idx_lb];
    }
    break;

   case 1:
    obj->nVar = 45;
    obj->mConstr = obj->mConstrOrig + 1;
    for (int32_T idx_lb = 0; idx_lb < 5; idx_lb++) {
      obj->sizes[idx_lb] = obj->sizesPhaseOne[idx_lb];
    }

    for (int32_T idx_lb = 0; idx_lb < 6; idx_lb++) {
      obj->isActiveIdx[idx_lb] = obj->isActiveIdxPhaseOne[idx_lb];
    }

    ros_cod_modifyOverheadPhaseOne_(obj);
    break;

   case 2:
    {
      int32_T idx_lb;
      obj->nVar = 44;
      obj->mConstr = 132;
      for (idx_lb = 0; idx_lb < 5; idx_lb++) {
        obj->sizes[idx_lb] = obj->sizesRegularized[idx_lb];
      }

      if (obj->probType != 4) {
        int32_T colOffsetAineq;
        for (idx_lb = 0; idx_lb < 44; idx_lb++) {
          colOffsetAineq = 45 * idx_lb;
          for (int32_T idx_row = 45; idx_row <= idx_lb + 44; idx_row++) {
            obj->Aineq[(idx_row + colOffsetAineq) - 1] = 0.0;
          }

          obj->Aineq[(idx_lb + colOffsetAineq) + 44] = -1.0;
        }

        idx_lb = 44;
        for (colOffsetAineq = obj->sizesNormal[3]; colOffsetAineq <
             obj->sizesRegularized[3]; colOffsetAineq++) {
          idx_lb++;
          obj->indexLB[colOffsetAineq] = idx_lb;
        }

        if (obj->nWConstr[4] > 0) {
          for (idx_lb = -1; idx_lb < obj->sizesRegularized[4] - 1; idx_lb++) {
            obj->isActiveConstr[(obj->isActiveIdxRegularized[4] + idx_lb) + 1] =
              obj->isActiveConstr[obj->isActiveIdx[4] + idx_lb];
          }
        }

        for (idx_lb = obj->isActiveIdx[4]; idx_lb < obj->isActiveIdxRegularized
             [4]; idx_lb++) {
          obj->isActiveConstr[idx_lb - 1] = false;
        }

        obj->lb[44] = 0.0;
        for (idx_lb = obj->isActiveIdx[2] - 1; idx_lb < obj->nActiveConstr;
             idx_lb++) {
          colOffsetAineq = 45 * idx_lb - 1;
          if (obj->Wid[idx_lb] == 3) {
            for (int32_T idx_row = 45; idx_row <= obj->Wlocalidx[idx_lb] + 43;
                 idx_row++) {
              obj->ATwset[idx_row + colOffsetAineq] = 0.0;
            }

            obj->ATwset[(obj->Wlocalidx[idx_lb] + colOffsetAineq) + 44] = -1.0;
            for (int32_T idx_row = obj->Wlocalidx[idx_lb] + 45; idx_row < 45;
                 idx_row++) {
              obj->ATwset[idx_row + colOffsetAineq] = 0.0;
            }
          }
        }
      }

      for (idx_lb = 0; idx_lb < 6; idx_lb++) {
        obj->isActiveIdx[idx_lb] = obj->isActiveIdxRegularized[idx_lb];
      }
    }
    break;

   default:
    obj->nVar = 45;
    obj->mConstr = 133;
    for (int32_T idx_lb = 0; idx_lb < 5; idx_lb++) {
      obj->sizes[idx_lb] = obj->sizesRegPhaseOne[idx_lb];
    }

    for (int32_T idx_lb = 0; idx_lb < 6; idx_lb++) {
      obj->isActiveIdx[idx_lb] = obj->isActiveIdxRegPhaseOne[idx_lb];
    }

    ros_cod_modifyOverheadPhaseOne_(obj);
    break;
  }

  obj->probType = PROBLEM_TYPE;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static real_T ros_code_xnrm2_o(int32_T n, const real_T x[5985], int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      int32_T kend;
      ros_code_B.scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (int32_T k = ix0; k <= kend; k++) {
        ros_code_B.absxk = fabs(x[k - 1]);
        if (ros_code_B.absxk > ros_code_B.scale) {
          ros_code_B.t_f = ros_code_B.scale / ros_code_B.absxk;
          y = y * ros_code_B.t_f * ros_code_B.t_f + 1.0;
          ros_code_B.scale = ros_code_B.absxk;
        } else {
          ros_code_B.t_f = ros_code_B.absxk / ros_code_B.scale;
          y += ros_code_B.t_f * ros_code_B.t_f;
        }
      }

      y = ros_code_B.scale * sqrt(y);
    }
  }

  return y;
}

static real_T ros_code_rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T y;
  ros_code_B.a_c = fabs(u0);
  y = fabs(u1);
  if (ros_code_B.a_c < y) {
    ros_code_B.a_c /= y;
    y *= sqrt(ros_code_B.a_c * ros_code_B.a_c + 1.0);
  } else if (ros_code_B.a_c > y) {
    y /= ros_code_B.a_c;
    y = sqrt(y * y + 1.0) * ros_code_B.a_c;
  } else if (!rtIsNaN(y)) {
    y = ros_code_B.a_c * 1.4142135623730951;
  }

  return y;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static real_T ros_code_xzlarfg_p(int32_T n, real_T *alpha1, real_T x[5985],
  int32_T ix0)
{
  real_T tau;
  tau = 0.0;
  if (n > 0) {
    ros_code_B.xnorm = ros_code_xnrm2_o(n - 1, x, ix0);
    if (ros_code_B.xnorm != 0.0) {
      ros_code_B.xnorm = ros_code_rt_hypotd_snf(*alpha1, ros_code_B.xnorm);
      if (*alpha1 >= 0.0) {
        ros_code_B.xnorm = -ros_code_B.xnorm;
      }

      if (fabs(ros_code_B.xnorm) < 1.0020841800044864E-292) {
        int32_T c_k;
        ros_code_B.knt = 0;
        c_k = (ix0 + n) - 2;
        do {
          ros_code_B.knt++;
          ros_code_B.b_k_c = ix0;
          while (ros_code_B.b_k_c <= c_k) {
            x[ros_code_B.b_k_c - 1] *= 9.9792015476736E+291;
            ros_code_B.b_k_c++;
          }

          ros_code_B.xnorm *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while ((fabs(ros_code_B.xnorm) < 1.0020841800044864E-292) &&
                 (ros_code_B.knt < 20));

        ros_code_B.xnorm = ros_code_rt_hypotd_snf(*alpha1, ros_code_xnrm2_o(n -
          1, x, ix0));
        if (*alpha1 >= 0.0) {
          ros_code_B.xnorm = -ros_code_B.xnorm;
        }

        tau = (ros_code_B.xnorm - *alpha1) / ros_code_B.xnorm;
        ros_code_B.a_i = 1.0 / (*alpha1 - ros_code_B.xnorm);
        ros_code_B.b_k_c = ix0;
        while (ros_code_B.b_k_c <= c_k) {
          x[ros_code_B.b_k_c - 1] *= ros_code_B.a_i;
          ros_code_B.b_k_c++;
        }

        for (c_k = 0; c_k < ros_code_B.knt; c_k++) {
          ros_code_B.xnorm *= 1.0020841800044864E-292;
        }

        *alpha1 = ros_code_B.xnorm;
      } else {
        tau = (ros_code_B.xnorm - *alpha1) / ros_code_B.xnorm;
        ros_code_B.a_i = 1.0 / (*alpha1 - ros_code_B.xnorm);
        ros_code_B.knt = (ix0 + n) - 2;
        for (int32_T c_k = ix0; c_k <= ros_code_B.knt; c_k++) {
          x[c_k - 1] *= ros_code_B.a_i;
        }

        *alpha1 = ros_code_B.xnorm;
      }
    }
  }

  return tau;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau,
  real_T C[5985], int32_T ic0, real_T work[133])
{
  int32_T coltop;
  int32_T jy;
  if (tau != 0.0) {
    boolean_T exitg2;
    ros_code_B.lastv_h = m;
    ros_code_B.lastc_h = iv0 + m;
    while ((ros_code_B.lastv_h > 0) && (C[ros_code_B.lastc_h - 2] == 0.0)) {
      ros_code_B.lastv_h--;
      ros_code_B.lastc_h--;
    }

    ros_code_B.lastc_h = n;
    exitg2 = false;
    while ((!exitg2) && (ros_code_B.lastc_h > 0)) {
      int32_T exitg1;
      coltop = (ros_code_B.lastc_h - 1) * 45 + ic0;
      jy = coltop;
      do {
        exitg1 = 0;
        if (jy <= (coltop + ros_code_B.lastv_h) - 1) {
          if (C[jy - 1] != 0.0) {
            exitg1 = 1;
          } else {
            jy++;
          }
        } else {
          ros_code_B.lastc_h--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }

    ros_code_B.lastc_h--;
  } else {
    ros_code_B.lastv_h = 0;
    ros_code_B.lastc_h = -1;
  }

  if (ros_code_B.lastv_h > 0) {
    int32_T ia;
    if (ros_code_B.lastc_h + 1 != 0) {
      for (coltop = 0; coltop <= ros_code_B.lastc_h; coltop++) {
        work[coltop] = 0.0;
      }

      coltop = 0;
      jy = 45 * ros_code_B.lastc_h + ic0;
      ros_code_B.iac_i = ic0;
      while (ros_code_B.iac_i <= jy) {
        ros_code_B.ix_f = iv0;
        ros_code_B.c_o = 0.0;
        ros_code_B.d_h = (ros_code_B.iac_i + ros_code_B.lastv_h) - 1;
        for (ia = ros_code_B.iac_i; ia <= ros_code_B.d_h; ia++) {
          ros_code_B.c_o += C[ia - 1] * C[ros_code_B.ix_f - 1];
          ros_code_B.ix_f++;
        }

        work[coltop] += ros_code_B.c_o;
        coltop++;
        ros_code_B.iac_i += 45;
      }
    }

    if (!(-tau == 0.0)) {
      coltop = ic0 - 1;
      jy = 0;
      ros_code_B.iac_i = 0;
      while (ros_code_B.iac_i <= ros_code_B.lastc_h) {
        if (work[jy] != 0.0) {
          ros_code_B.c_o = work[jy] * -tau;
          ros_code_B.ix_f = iv0;
          ros_code_B.d_h = coltop;
          ia = ros_code_B.lastv_h + coltop;
          while (ros_code_B.d_h + 1 <= ia) {
            C[ros_code_B.d_h] += C[ros_code_B.ix_f - 1] * ros_code_B.c_o;
            ros_code_B.ix_f++;
            ros_code_B.d_h++;
          }
        }

        jy++;
        coltop += 45;
        ros_code_B.iac_i++;
      }
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_qrf(real_T A[5985], int32_T m, int32_T n, int32_T nfxd,
  real_T tau[45])
{
  memset(&ros_code_B.work_p[0], 0, 133U * sizeof(real_T));
  ros_code_B.i_g = 0;
  while (ros_code_B.i_g <= nfxd - 1) {
    ros_code_B.ii_p = ros_code_B.i_g * 45 + ros_code_B.i_g;
    ros_code_B.mmi_d = m - ros_code_B.i_g;
    if (ros_code_B.i_g + 1 < m) {
      ros_code_B.b_atmp = A[ros_code_B.ii_p];
      tau[ros_code_B.i_g] = ros_code_xzlarfg_p(ros_code_B.mmi_d,
        &ros_code_B.b_atmp, A, ros_code_B.ii_p + 2);
      A[ros_code_B.ii_p] = ros_code_B.b_atmp;
    } else {
      tau[ros_code_B.i_g] = 0.0;
    }

    if (ros_code_B.i_g + 1 < n) {
      ros_code_B.b_atmp = A[ros_code_B.ii_p];
      A[ros_code_B.ii_p] = 1.0;
      ros_code_xzlarf(ros_code_B.mmi_d, (n - ros_code_B.i_g) - 1,
                      ros_code_B.ii_p + 1, tau[ros_code_B.i_g], A,
                      ros_code_B.ii_p + 46, ros_code_B.work_p);
      A[ros_code_B.ii_p] = ros_code_B.b_atmp;
    }

    ros_code_B.i_g++;
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_factorQRE(siBmBjpOUwoybpuj9rEfGvD_ros_c_T *obj, int32_T
  mrows, int32_T ncols)
{
  if (mrows * ncols == 0) {
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = 0;
  } else {
    obj->usedPivoting = true;
    obj->mrows = mrows;
    obj->ncols = ncols;
    if (mrows <= ncols) {
      ros_code_B.u1_k = mrows;
    } else {
      ros_code_B.u1_k = ncols;
    }

    obj->minRowCol = ros_code_B.u1_k;
    memset(&obj->tau[0], 0, 45U * sizeof(real_T));
    if (ros_code_B.u1_k < 1) {
      ros_code_B.u1_k = 0;
      while (ros_code_B.u1_k <= ncols - 1) {
        obj->jpvt[ros_code_B.u1_k] = ros_code_B.u1_k + 1;
        ros_code_B.u1_k++;
      }
    } else {
      ros_code_B.nfxd = -1;
      ros_code_B.i_m = 0;
      while (ros_code_B.i_m <= ncols - 1) {
        if (obj->jpvt[ros_code_B.i_m] != 0) {
          ros_code_B.nfxd++;
          if (ros_code_B.i_m + 1 != ros_code_B.nfxd + 1) {
            ros_code_B.mmi = ros_code_B.i_m * 45;
            ros_code_B.ii = ros_code_B.nfxd * 45;
            ros_code_B.nmi = 0;
            while (ros_code_B.nmi <= mrows - 1) {
              ros_code_B.smax = obj->QR[ros_code_B.mmi];
              obj->QR[ros_code_B.mmi] = obj->QR[ros_code_B.ii];
              obj->QR[ros_code_B.ii] = ros_code_B.smax;
              ros_code_B.mmi++;
              ros_code_B.ii++;
              ros_code_B.nmi++;
            }

            obj->jpvt[ros_code_B.i_m] = obj->jpvt[ros_code_B.nfxd];
            obj->jpvt[ros_code_B.nfxd] = ros_code_B.i_m + 1;
          } else {
            obj->jpvt[ros_code_B.i_m] = ros_code_B.i_m + 1;
          }
        } else {
          obj->jpvt[ros_code_B.i_m] = ros_code_B.i_m + 1;
        }

        ros_code_B.i_m++;
      }

      if (ros_code_B.nfxd + 1 <= ros_code_B.u1_k) {
        ros_code_B.nfxd++;
      } else {
        ros_code_B.nfxd = ros_code_B.u1_k;
      }

      memset(&obj->tau[0], 0, 45U * sizeof(real_T));
      ros_code_qrf(obj->QR, mrows, ncols, ros_code_B.nfxd, obj->tau);
      if (ros_code_B.nfxd < ros_code_B.u1_k) {
        memset(&ros_code_B.work[0], 0, 133U * sizeof(real_T));
        memset(&ros_code_B.vn1[0], 0, 133U * sizeof(real_T));
        memset(&ros_code_B.vn2[0], 0, 133U * sizeof(real_T));
        ros_code_B.i_m = ros_code_B.nfxd;
        while (ros_code_B.i_m + 1 <= ncols) {
          ros_code_B.vn1[ros_code_B.i_m] = ros_code_xnrm2_o(mrows -
            ros_code_B.nfxd, obj->QR, (ros_code_B.i_m * 45 + ros_code_B.nfxd) +
            1);
          ros_code_B.vn2[ros_code_B.i_m] = ros_code_B.vn1[ros_code_B.i_m];
          ros_code_B.i_m++;
        }

        while (ros_code_B.nfxd + 1 <= ros_code_B.u1_k) {
          ros_code_B.i_m = ros_code_B.nfxd + 1;
          ros_code_B.ii = ros_code_B.nfxd * 45 + ros_code_B.nfxd;
          ros_code_B.nmi = ncols - ros_code_B.nfxd;
          ros_code_B.mmi = mrows - ros_code_B.nfxd;
          if (ros_code_B.nmi < 1) {
            ros_code_B.pvt = -1;
          } else {
            ros_code_B.pvt = 0;
            if (ros_code_B.nmi > 1) {
              ros_code_B.b_ix = ros_code_B.nfxd;
              ros_code_B.smax = fabs(ros_code_B.vn1[ros_code_B.nfxd]);
              ros_code_B.b_iy = 2;
              while (ros_code_B.b_iy <= ros_code_B.nmi) {
                ros_code_B.b_ix++;
                ros_code_B.s_f = fabs(ros_code_B.vn1[ros_code_B.b_ix]);
                if (ros_code_B.s_f > ros_code_B.smax) {
                  ros_code_B.pvt = ros_code_B.b_iy - 1;
                  ros_code_B.smax = ros_code_B.s_f;
                }

                ros_code_B.b_iy++;
              }
            }
          }

          ros_code_B.pvt += ros_code_B.nfxd;
          if (ros_code_B.pvt + 1 != ros_code_B.nfxd + 1) {
            ros_code_B.b_ix = ros_code_B.pvt * 45;
            ros_code_B.b_iy = ros_code_B.nfxd * 45;
            ros_code_B.c_k = 0;
            while (ros_code_B.c_k <= mrows - 1) {
              ros_code_B.smax = obj->QR[ros_code_B.b_ix];
              obj->QR[ros_code_B.b_ix] = obj->QR[ros_code_B.b_iy];
              obj->QR[ros_code_B.b_iy] = ros_code_B.smax;
              ros_code_B.b_ix++;
              ros_code_B.b_iy++;
              ros_code_B.c_k++;
            }

            ros_code_B.b_ix = obj->jpvt[ros_code_B.pvt];
            obj->jpvt[ros_code_B.pvt] = obj->jpvt[ros_code_B.nfxd];
            obj->jpvt[ros_code_B.nfxd] = ros_code_B.b_ix;
            ros_code_B.vn1[ros_code_B.pvt] = ros_code_B.vn1[ros_code_B.nfxd];
            ros_code_B.vn2[ros_code_B.pvt] = ros_code_B.vn2[ros_code_B.nfxd];
          }

          if (ros_code_B.nfxd + 1 < mrows) {
            ros_code_B.smax = obj->QR[ros_code_B.ii];
            obj->tau[ros_code_B.nfxd] = ros_code_xzlarfg_p(ros_code_B.mmi,
              &ros_code_B.smax, obj->QR, ros_code_B.ii + 2);
            obj->QR[ros_code_B.ii] = ros_code_B.smax;
          } else {
            obj->tau[ros_code_B.nfxd] = 0.0;
          }

          if (ros_code_B.nfxd + 1 < ncols) {
            ros_code_B.smax = obj->QR[ros_code_B.ii];
            obj->QR[ros_code_B.ii] = 1.0;
            ros_code_xzlarf(ros_code_B.mmi, ros_code_B.nmi - 1, ros_code_B.ii +
                            1, obj->tau[ros_code_B.nfxd], obj->QR, ros_code_B.ii
                            + 46, ros_code_B.work);
            obj->QR[ros_code_B.ii] = ros_code_B.smax;
          }

          while (ros_code_B.i_m + 1 <= ncols) {
            ros_code_B.ii = ros_code_B.i_m * 45 + ros_code_B.nfxd;
            if (ros_code_B.vn1[ros_code_B.i_m] != 0.0) {
              ros_code_B.smax = fabs(obj->QR[ros_code_B.ii]) /
                ros_code_B.vn1[ros_code_B.i_m];
              ros_code_B.smax = 1.0 - ros_code_B.smax * ros_code_B.smax;
              if (ros_code_B.smax < 0.0) {
                ros_code_B.smax = 0.0;
              }

              ros_code_B.s_f = ros_code_B.vn1[ros_code_B.i_m] /
                ros_code_B.vn2[ros_code_B.i_m];
              ros_code_B.s_f = ros_code_B.s_f * ros_code_B.s_f * ros_code_B.smax;
              if (ros_code_B.s_f <= 1.4901161193847656E-8) {
                if (ros_code_B.nfxd + 1 < mrows) {
                  ros_code_B.vn1[ros_code_B.i_m] = ros_code_xnrm2_o
                    (ros_code_B.mmi - 1, obj->QR, ros_code_B.ii + 2);
                  ros_code_B.vn2[ros_code_B.i_m] = ros_code_B.vn1[ros_code_B.i_m];
                } else {
                  ros_code_B.vn1[ros_code_B.i_m] = 0.0;
                  ros_code_B.vn2[ros_code_B.i_m] = 0.0;
                }
              } else {
                ros_code_B.vn1[ros_code_B.i_m] *= sqrt(ros_code_B.smax);
              }
            }

            ros_code_B.i_m++;
          }

          ros_code_B.nfxd++;
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_computeQ_(siBmBjpOUwoybpuj9rEfGvD_ros_c_T *obj, int32_T
  nrows)
{
  int32_T i;
  ros_code_B.idx_o = 0;
  while (ros_code_B.idx_o <= obj->minRowCol - 1) {
    i = 45 * ros_code_B.idx_o + ros_code_B.idx_o;
    ros_code_B.itau = obj->mrows - ros_code_B.idx_o;
    ros_code_B.iaii = 1;
    while (ros_code_B.iaii - 1 <= ros_code_B.itau - 2) {
      ros_code_B.lastv = i + ros_code_B.iaii;
      obj->Q[ros_code_B.lastv] = obj->QR[ros_code_B.lastv];
      ros_code_B.iaii++;
    }

    ros_code_B.idx_o++;
  }

  ros_code_B.idx_o = obj->mrows;
  if (nrows >= 1) {
    for (i = obj->minRowCol; i < nrows; i++) {
      ros_code_B.itau = i * 45;
      ros_code_B.iaii = 0;
      while (ros_code_B.iaii <= ros_code_B.idx_o - 1) {
        obj->Q[ros_code_B.itau + ros_code_B.iaii] = 0.0;
        ros_code_B.iaii++;
      }

      obj->Q[ros_code_B.itau + i] = 1.0;
    }

    ros_code_B.itau = obj->minRowCol - 1;
    memset(&ros_code_B.work_d[0], 0, 45U * sizeof(real_T));
    for (i = obj->minRowCol; i >= 1; i--) {
      ros_code_B.iaii = (i - 1) * 45 + i;
      if (i < nrows) {
        int32_T coltop;
        int32_T jy;
        obj->Q[ros_code_B.iaii - 1] = 1.0;
        ros_code_B.lastv = ros_code_B.idx_o - i;
        if (obj->tau[ros_code_B.itau] != 0.0) {
          boolean_T exitg2;
          ros_code_B.lastc = ros_code_B.iaii + ros_code_B.lastv;
          while ((ros_code_B.lastv + 1 > 0) && (obj->Q[ros_code_B.lastc - 1] ==
                  0.0)) {
            ros_code_B.lastv--;
            ros_code_B.lastc--;
          }

          ros_code_B.lastc = nrows - i;
          exitg2 = false;
          while ((!exitg2) && (ros_code_B.lastc > 0)) {
            int32_T exitg1;
            coltop = ((ros_code_B.lastc - 1) * 45 + ros_code_B.iaii) + 45;
            jy = coltop;
            do {
              exitg1 = 0;
              if (jy <= coltop + ros_code_B.lastv) {
                if (obj->Q[jy - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  jy++;
                }
              } else {
                ros_code_B.lastc--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
              exitg2 = true;
            }
          }

          ros_code_B.lastc--;
        } else {
          ros_code_B.lastv = -1;
          ros_code_B.lastc = -1;
        }

        if (ros_code_B.lastv + 1 > 0) {
          if (ros_code_B.lastc + 1 != 0) {
            for (coltop = 0; coltop <= ros_code_B.lastc; coltop++) {
              ros_code_B.work_d[coltop] = 0.0;
            }

            coltop = 0;
            jy = (45 * ros_code_B.lastc + ros_code_B.iaii) + 45;
            ros_code_B.iac = ros_code_B.iaii + 45;
            while (ros_code_B.iac <= jy) {
              ros_code_B.ix_j = ros_code_B.iaii;
              ros_code_B.c_p = 0.0;
              ros_code_B.e_p = ros_code_B.iac + ros_code_B.lastv;
              ros_code_B.b_ia_o = ros_code_B.iac;
              while (ros_code_B.b_ia_o <= ros_code_B.e_p) {
                ros_code_B.c_p += obj->Q[ros_code_B.b_ia_o - 1] * obj->
                  Q[ros_code_B.ix_j - 1];
                ros_code_B.ix_j++;
                ros_code_B.b_ia_o++;
              }

              ros_code_B.work_d[coltop] += ros_code_B.c_p;
              coltop++;
              ros_code_B.iac += 45;
            }
          }

          if (!(-obj->tau[ros_code_B.itau] == 0.0)) {
            coltop = ros_code_B.iaii + 44;
            jy = 0;
            ros_code_B.iac = 0;
            while (ros_code_B.iac <= ros_code_B.lastc) {
              if (ros_code_B.work_d[jy] != 0.0) {
                ros_code_B.c_p = ros_code_B.work_d[jy] * -obj->
                  tau[ros_code_B.itau];
                ros_code_B.ix_j = ros_code_B.iaii;
                ros_code_B.e_p = coltop;
                ros_code_B.b_ia_o = ros_code_B.lastv + coltop;
                while (ros_code_B.e_p + 1 <= ros_code_B.b_ia_o + 1) {
                  obj->Q[ros_code_B.e_p] += obj->Q[ros_code_B.ix_j - 1] *
                    ros_code_B.c_p;
                  ros_code_B.ix_j++;
                  ros_code_B.e_p++;
                }
              }

              jy++;
              coltop += 45;
              ros_code_B.iac++;
            }
          }
        }
      }

      if (i < ros_code_B.idx_o) {
        ros_code_B.lastv = (ros_code_B.iaii + ros_code_B.idx_o) - i;
        ros_code_B.lastc = ros_code_B.iaii;
        while (ros_code_B.lastc + 1 <= ros_code_B.lastv) {
          obj->Q[ros_code_B.lastc] *= -obj->tau[ros_code_B.itau];
          ros_code_B.lastc++;
        }
      }

      obj->Q[ros_code_B.iaii - 1] = 1.0 - obj->tau[ros_code_B.itau];
      ros_code_B.lastv = 0;
      while (ros_code_B.lastv <= i - 2) {
        obj->Q[(ros_code_B.iaii - ros_code_B.lastv) - 2] = 0.0;
        ros_code_B.lastv++;
      }

      ros_code_B.itau--;
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_IndexOfDependentEq_(int32_T depIdx[133], int32_T mFixed,
  int32_T nDep, siBmBjpOUwoybpuj9rEfGvD_ros_c_T *qrmanager, int32_T mRows,
  int32_T nCols)
{
  ros_code_B.b_idx_j = 0;
  while (ros_code_B.b_idx_j <= mFixed - 1) {
    qrmanager->jpvt[ros_code_B.b_idx_j] = 1;
    ros_code_B.b_idx_j++;
  }

  ros_code_B.b_idx_j = mFixed;
  while (ros_code_B.b_idx_j + 1 <= nCols) {
    qrmanager->jpvt[ros_code_B.b_idx_j] = 0;
    ros_code_B.b_idx_j++;
  }

  ros_code_factorQRE(qrmanager, mRows, nCols);
  ros_code_B.b_idx_j = 0;
  while (ros_code_B.b_idx_j <= nDep - 1) {
    depIdx[ros_code_B.b_idx_j] = qrmanager->jpvt[(nCols - nDep) +
      ros_code_B.b_idx_j];
    ros_code_B.b_idx_j++;
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_countsort(int32_T x[133], int32_T xLen, int32_T workspace
  [133], int32_T xMin, int32_T xMax)
{
  if ((xLen > 1) && (xMax > xMin)) {
    int32_T b_tmp;
    int32_T idxEnd;
    int32_T idxStart;
    b_tmp = xMax - xMin;
    for (idxStart = 0; idxStart <= b_tmp; idxStart++) {
      workspace[idxStart] = 0;
    }

    for (idxStart = 0; idxStart < xLen; idxStart++) {
      idxEnd = x[idxStart] - xMin;
      workspace[idxEnd]++;
    }

    for (idxStart = 1; idxStart < b_tmp + 1; idxStart++) {
      workspace[idxStart] += workspace[idxStart - 1];
    }

    idxStart = 1;
    idxEnd = workspace[0];
    for (int32_T b_idxW = 0; b_idxW < b_tmp; b_idxW++) {
      while (idxStart <= idxEnd) {
        x[idxStart - 1] = b_idxW + xMin;
        idxStart++;
      }

      idxStart = workspace[b_idxW] + 1;
      idxEnd = workspace[b_idxW + 1];
    }

    while (idxStart <= idxEnd) {
      x[idxStart - 1] = xMax;
      idxStart++;
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_removeConstr(snBUc3P0iDgb4fuyQLszkYC_ros_c_T *obj, int32_T
  idx_global)
{
  int32_T TYPE_tmp;
  int32_T idx_global_start_tmp_tmp;
  TYPE_tmp = obj->Wid[idx_global - 1] - 1;
  obj->isActiveConstr[(obj->isActiveIdx[TYPE_tmp] + obj->Wlocalidx[idx_global -
                       1]) - 2] = false;
  idx_global_start_tmp_tmp = obj->nActiveConstr - 1;
  obj->Wid[idx_global - 1] = obj->Wid[obj->nActiveConstr - 1];
  obj->Wlocalidx[idx_global - 1] = obj->Wlocalidx[idx_global_start_tmp_tmp];
  for (int32_T b_idx = 0; b_idx < obj->nVar; b_idx++) {
    obj->ATwset[b_idx + 45 * (idx_global - 1)] = obj->ATwset[45 *
      idx_global_start_tmp_tmp + b_idx];
  }

  obj->bwset[idx_global - 1] = obj->bwset[idx_global_start_tmp_tmp];
  obj->nActiveConstr--;
  obj->nWConstr[TYPE_tmp]--;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_removeEqConstr(snBUc3P0iDgb4fuyQLszkYC_ros_c_T *obj,
  int32_T idx_global)
{
  ros_code_B.totalEq = (obj->nWConstr[0] + obj->nWConstr[1]) - 1;
  if ((ros_code_B.totalEq + 1 != 0) && (idx_global <= ros_code_B.totalEq + 1)) {
    if ((ros_code_B.totalEq + 1 == obj->nActiveConstr) || (ros_code_B.totalEq +
         1 == idx_global)) {
      obj->mEqRemoved++;
      ros_code_removeConstr(obj, idx_global);
    } else {
      int32_T TYPE_tmp_tmp;
      obj->mEqRemoved++;
      TYPE_tmp_tmp = obj->Wid[idx_global - 1] - 1;
      obj->isActiveConstr[(obj->isActiveIdx[TYPE_tmp_tmp] + obj->
                           Wlocalidx[idx_global - 1]) - 2] = false;
      obj->Wid[idx_global - 1] = obj->Wid[ros_code_B.totalEq];
      obj->Wlocalidx[idx_global - 1] = obj->Wlocalidx[ros_code_B.totalEq];
      ros_code_B.b_idx_o = 0;
      while (ros_code_B.b_idx_o <= obj->nVar - 1) {
        obj->ATwset[ros_code_B.b_idx_o + 45 * (idx_global - 1)] = obj->ATwset[45
          * ros_code_B.totalEq + ros_code_B.b_idx_o];
        ros_code_B.b_idx_o++;
      }

      obj->bwset[idx_global - 1] = obj->bwset[ros_code_B.totalEq];
      ros_code_B.b_idx_o = obj->nActiveConstr - 1;
      obj->Wid[ros_code_B.totalEq] = obj->Wid[obj->nActiveConstr - 1];
      obj->Wlocalidx[ros_code_B.totalEq] = obj->Wlocalidx[ros_code_B.b_idx_o];
      ros_code_B.d_idx = 0;
      while (ros_code_B.d_idx <= obj->nVar - 1) {
        obj->ATwset[ros_code_B.d_idx + 45 * ros_code_B.totalEq] = obj->ATwset[45
          * ros_code_B.b_idx_o + ros_code_B.d_idx];
        ros_code_B.d_idx++;
      }

      obj->bwset[ros_code_B.totalEq] = obj->bwset[ros_code_B.b_idx_o];
      obj->nActiveConstr--;
      obj->nWConstr[TYPE_tmp_tmp]--;
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_RemoveDependentEq_(sg8qKdtlZ7nXgcAC5MP2QHC_ros_c_T
  *memspace, snBUc3P0iDgb4fuyQLszkYC_ros_c_T *workingset, int32_T *nDepInd,
  siBmBjpOUwoybpuj9rEfGvD_ros_c_T *qrmanager)
{
  qrmanager->ldq = 45;
  memset(&qrmanager->QR[0], 0, 5985U * sizeof(real_T));
  memset(&qrmanager->Q[0], 0, 2025U * sizeof(real_T));
  memset(&qrmanager->jpvt[0], 0, 133U * sizeof(int32_T));
  qrmanager->mrows = 0;
  qrmanager->ncols = 0;
  memset(&qrmanager->tau[0], 0, 45U * sizeof(real_T));
  qrmanager->minRowCol = 0;
  qrmanager->usedPivoting = false;
  ros_code_B.i_nh = workingset->nVar - 1;
  ros_code_B.mWorkingFixed = workingset->nWConstr[0] - 1;
  *nDepInd = 0;
  if (workingset->nWConstr[0] > 0) {
    ros_code_B.totalRank_i = 0;
    while (ros_code_B.totalRank_i <= ros_code_B.mWorkingFixed) {
      ros_code_B.ix_p = 0;
      while (ros_code_B.ix_p <= ros_code_B.i_nh) {
        qrmanager->QR[ros_code_B.totalRank_i + 45 * ros_code_B.ix_p] =
          workingset->ATwset[45 * ros_code_B.totalRank_i + ros_code_B.ix_p];
        ros_code_B.ix_p++;
      }

      ros_code_B.totalRank_i++;
    }

    *nDepInd = workingset->nWConstr[0] - workingset->nVar;
    if (*nDepInd <= 0) {
      *nDepInd = 0;
    }

    ros_code_B.totalRank_i = 0;
    while (ros_code_B.totalRank_i <= ros_code_B.i_nh) {
      qrmanager->jpvt[ros_code_B.totalRank_i] = 0;
      ros_code_B.totalRank_i++;
    }

    ros_code_factorQRE(qrmanager, workingset->nWConstr[0], workingset->nVar);
    ros_code_B.tol_j = 100.0 * static_cast<real_T>(workingset->nVar) *
      2.2204460492503131E-16;
    if (workingset->nVar <= workingset->nWConstr[0]) {
      ros_code_B.totalRank_i = workingset->nVar;
    } else {
      ros_code_B.totalRank_i = workingset->nWConstr[0];
    }

    ros_code_B.totalRank_i += (ros_code_B.totalRank_i - 1) * 45;
    while ((ros_code_B.totalRank_i > 0) && (fabs(qrmanager->
             QR[ros_code_B.totalRank_i - 1]) < ros_code_B.tol_j)) {
      ros_code_B.totalRank_i -= 46;
      (*nDepInd)++;
    }

    if (*nDepInd > 0) {
      boolean_T exitg1;
      ros_code_computeQ_(qrmanager, qrmanager->mrows);
      ros_code_B.totalRank_i = 0;
      exitg1 = false;
      while ((!exitg1) && (ros_code_B.totalRank_i <= *nDepInd - 1)) {
        ros_code_B.ix_p = (ros_code_B.mWorkingFixed - ros_code_B.totalRank_i) *
          45;
        ros_code_B.qtb_e = 0.0;
        ros_code_B.iy_f = 0;
        ros_code_B.b_k_e = 0;
        while (ros_code_B.b_k_e <= ros_code_B.mWorkingFixed) {
          ros_code_B.qtb_e += qrmanager->Q[ros_code_B.ix_p] * workingset->
            bwset[ros_code_B.iy_f];
          ros_code_B.ix_p++;
          ros_code_B.iy_f++;
          ros_code_B.b_k_e++;
        }

        if (fabs(ros_code_B.qtb_e) >= ros_code_B.tol_j) {
          *nDepInd = -1;
          exitg1 = true;
        } else {
          ros_code_B.totalRank_i++;
        }
      }
    }

    if (*nDepInd > 0) {
      ros_code_B.totalRank_i = 0;
      while (ros_code_B.totalRank_i <= ros_code_B.mWorkingFixed) {
        ros_code_B.ix_p = 45 * ros_code_B.totalRank_i;
        ros_code_B.iy_f = 1;
        while (ros_code_B.iy_f - 1 <= ros_code_B.i_nh) {
          ros_code_B.b_k_e = (ros_code_B.ix_p + ros_code_B.iy_f) - 1;
          qrmanager->QR[ros_code_B.b_k_e] = workingset->ATwset[ros_code_B.b_k_e];
          ros_code_B.iy_f++;
        }

        ros_code_B.totalRank_i++;
      }

      ros_code_IndexOfDependentEq_(memspace->workspace_int, workingset->
        nWConstr[0], *nDepInd, qrmanager, workingset->nVar, workingset->
        nWConstr[0]);
      ros_code_countsort(memspace->workspace_int, *nDepInd,
                         memspace->workspace_sort, 1, workingset->nWConstr[0]);
      ros_code_B.i_nh = *nDepInd;
      while (ros_code_B.i_nh > 0) {
        ros_code_removeEqConstr(workingset, memspace->
          workspace_int[ros_code_B.i_nh - 1]);
        ros_code_B.i_nh--;
      }
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_removeAllIneqConstr(snBUc3P0iDgb4fuyQLszkYC_ros_c_T *obj)
{
  for (int32_T idx_global = obj->nWConstr[0] + obj->nWConstr[1]; idx_global <
       obj->nActiveConstr; idx_global++) {
    obj->isActiveConstr[(obj->isActiveIdx[obj->Wid[idx_global] - 1] +
                         obj->Wlocalidx[idx_global]) - 2] = false;
  }

  obj->nWConstr[2] = 0;
  obj->nWConstr[3] = 0;
  obj->nWConstr[4] = 0;
  obj->nActiveConstr = obj->nWConstr[0] + obj->nWConstr[1];
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_RemoveDependentIneq_(snBUc3P0iDgb4fuyQLszkYC_ros_c_T
  *workingset, siBmBjpOUwoybpuj9rEfGvD_ros_c_T *qrmanager,
  sg8qKdtlZ7nXgcAC5MP2QHC_ros_c_T *memspace, real_T tolfactor)
{
  ros_code_B.nFixedConstr = workingset->nWConstr[0] + workingset->nWConstr[1];
  ros_code_B.nVar_m = workingset->nVar;
  if ((workingset->nWConstr[2] + workingset->nWConstr[3]) + workingset->
      nWConstr[4] > 0) {
    ros_code_B.tol_p = tolfactor * static_cast<real_T>(workingset->nVar) *
      2.2204460492503131E-16;
    ros_code_B.nDepIneq = 0;
    while (ros_code_B.nDepIneq <= ros_code_B.nFixedConstr - 1) {
      qrmanager->jpvt[ros_code_B.nDepIneq] = 1;
      ros_code_B.nDepIneq++;
    }

    ros_code_B.nDepIneq = ros_code_B.nFixedConstr + 1;
    while (ros_code_B.nDepIneq <= workingset->nActiveConstr) {
      qrmanager->jpvt[ros_code_B.nDepIneq - 1] = 0;
      ros_code_B.nDepIneq++;
    }

    ros_code_B.nDepIneq = 0;
    while (ros_code_B.nDepIneq <= workingset->nActiveConstr - 1) {
      ros_code_B.idx_n = 45 * ros_code_B.nDepIneq;
      ros_code_B.k_g = 1;
      while (ros_code_B.k_g - 1 <= ros_code_B.nVar_m - 1) {
        ros_code_B.i12 = (ros_code_B.idx_n + ros_code_B.k_g) - 1;
        qrmanager->QR[ros_code_B.i12] = workingset->ATwset[ros_code_B.i12];
        ros_code_B.k_g++;
      }

      ros_code_B.nDepIneq++;
    }

    ros_code_factorQRE(qrmanager, workingset->nVar, workingset->nActiveConstr);
    ros_code_B.nDepIneq = 0;
    ros_code_B.idx_n = workingset->nActiveConstr - 1;
    while (ros_code_B.idx_n + 1 > ros_code_B.nVar_m) {
      ros_code_B.nDepIneq++;
      memspace->workspace_int[ros_code_B.nDepIneq - 1] = qrmanager->
        jpvt[ros_code_B.idx_n];
      ros_code_B.idx_n--;
    }

    if (ros_code_B.idx_n + 1 <= workingset->nVar) {
      ros_code_B.nVar_m = 45 * ros_code_B.idx_n + ros_code_B.idx_n;
      while ((ros_code_B.idx_n + 1 > ros_code_B.nFixedConstr) && (fabs
              (qrmanager->QR[ros_code_B.nVar_m]) < ros_code_B.tol_p)) {
        ros_code_B.nDepIneq++;
        memspace->workspace_int[ros_code_B.nDepIneq - 1] = qrmanager->
          jpvt[ros_code_B.idx_n];
        ros_code_B.idx_n--;
        ros_code_B.nVar_m -= 46;
      }
    }

    ros_code_countsort(memspace->workspace_int, ros_code_B.nDepIneq,
                       memspace->workspace_sort, ros_code_B.nFixedConstr + 1,
                       workingset->nActiveConstr);
    while (ros_code_B.nDepIneq > 0) {
      ros_code_removeConstr(workingset, memspace->
                            workspace_int[ros_code_B.nDepIneq - 1]);
      ros_code_B.nDepIneq--;
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_factorQR(siBmBjpOUwoybpuj9rEfGvD_ros_c_T *obj, const real_T
  A[5985], int32_T mrows, int32_T ncols)
{
  boolean_T guard1 = false;
  ros_code_B.ix0_tmp = mrows * ncols;
  guard1 = false;
  if (ros_code_B.ix0_tmp > 0) {
    ros_code_B.i_o = 0;
    while (ros_code_B.i_o <= ncols - 1) {
      ros_code_B.ix0_tmp = 45 * ros_code_B.i_o;
      ros_code_B.k_gi = 1;
      while (ros_code_B.k_gi - 1 <= mrows - 1) {
        ros_code_B.i13 = (ros_code_B.ix0_tmp + ros_code_B.k_gi) - 1;
        obj->QR[ros_code_B.i13] = A[ros_code_B.i13];
        ros_code_B.k_gi++;
      }

      ros_code_B.i_o++;
    }

    guard1 = true;
  } else if (ros_code_B.ix0_tmp == 0) {
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = 0;
  } else {
    guard1 = true;
  }

  if (guard1) {
    obj->usedPivoting = false;
    obj->mrows = mrows;
    obj->ncols = ncols;
    ros_code_B.i_o = 0;
    while (ros_code_B.i_o <= ncols - 1) {
      obj->jpvt[ros_code_B.i_o] = ros_code_B.i_o + 1;
      ros_code_B.i_o++;
    }

    if (mrows <= ncols) {
      ros_code_B.ix0_tmp = mrows;
    } else {
      ros_code_B.ix0_tmp = ncols;
    }

    obj->minRowCol = ros_code_B.ix0_tmp;
    memset(&obj->tau[0], 0, 45U * sizeof(real_T));
    if (ros_code_B.ix0_tmp >= 1) {
      memset(&obj->tau[0], 0, 45U * sizeof(real_T));
      ros_code_qrf(obj->QR, mrows, ncols, ros_code_B.ix0_tmp, obj->tau);
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static real_T ros_code_maxConstraintViolation(snBUc3P0iDgb4fuyQLszkYC_ros_c_T
  *obj, const real_T x[5985])
{
  real_T v;
  ros_code_B.mLB_a = obj->sizes[3];
  ros_code_B.mUB_j = obj->sizes[4];
  ros_code_B.mFixed_ga = obj->sizes[0];
  if (obj->probType == 2) {
    v = 0.0;
    for (ros_code_B.k_jk = 0; ros_code_B.k_jk < 44; ros_code_B.k_jk++) {
      obj->maxConstrWorkspace[ros_code_B.k_jk] = obj->bineq[ros_code_B.k_jk];
      obj->maxConstrWorkspace[ros_code_B.k_jk] = -obj->
        maxConstrWorkspace[ros_code_B.k_jk];
    }

    for (ros_code_B.k_jk = 0; ros_code_B.k_jk <= 1936; ros_code_B.k_jk += 45) {
      int32_T ix;
      ix = 0;
      ros_code_B.c_j = 0.0;
      for (int32_T b = ros_code_B.k_jk; b < ros_code_B.k_jk + 44; b++) {
        ros_code_B.c_j += obj->Aineq[b] * x[ix];
        ix++;
      }

      ix = div_nde_s32_floor(ros_code_B.k_jk, 45);
      obj->maxConstrWorkspace[ix] += ros_code_B.c_j;
    }

    for (ros_code_B.k_jk = 0; ros_code_B.k_jk < 44; ros_code_B.k_jk++) {
      obj->maxConstrWorkspace[ros_code_B.k_jk] -= x[ros_code_B.k_jk + 44];
      ros_code_B.c_j = obj->maxConstrWorkspace[ros_code_B.k_jk];
      if ((!(v >= ros_code_B.c_j)) && (!rtIsNaN(ros_code_B.c_j))) {
        v = ros_code_B.c_j;
      }
    }
  } else {
    v = 0.0;
    for (ros_code_B.k_jk = 0; ros_code_B.k_jk < 44; ros_code_B.k_jk++) {
      obj->maxConstrWorkspace[ros_code_B.k_jk] = obj->bineq[ros_code_B.k_jk];
      obj->maxConstrWorkspace[ros_code_B.k_jk] = -obj->
        maxConstrWorkspace[ros_code_B.k_jk];
    }

    for (ros_code_B.k_jk = 0; ros_code_B.k_jk <= 1936; ros_code_B.k_jk += 45) {
      int32_T b;
      int32_T ix;
      ix = 0;
      ros_code_B.c_j = 0.0;
      b = ros_code_B.k_jk + obj->nVar;
      for (int32_T ia = ros_code_B.k_jk; ia < b; ia++) {
        ros_code_B.c_j += obj->Aineq[ia] * x[ix];
        ix++;
      }

      ix = div_nde_s32_floor(ros_code_B.k_jk, 45);
      obj->maxConstrWorkspace[ix] += ros_code_B.c_j;
    }

    for (ros_code_B.k_jk = 0; ros_code_B.k_jk < 44; ros_code_B.k_jk++) {
      ros_code_B.c_j = obj->maxConstrWorkspace[ros_code_B.k_jk];
      if ((!(v >= ros_code_B.c_j)) && (!rtIsNaN(ros_code_B.c_j))) {
        v = ros_code_B.c_j;
      }
    }
  }

  if (ros_code_B.mLB_a > 0) {
    ros_code_B.k_jk = 0;
    while (ros_code_B.k_jk <= ros_code_B.mLB_a - 1) {
      ros_code_B.c_j = -x[obj->indexLB[ros_code_B.k_jk] - 1] - obj->lb
        [obj->indexLB[ros_code_B.k_jk] - 1];
      if ((!(v >= ros_code_B.c_j)) && (!rtIsNaN(ros_code_B.c_j))) {
        v = ros_code_B.c_j;
      }

      ros_code_B.k_jk++;
    }
  }

  if (ros_code_B.mUB_j > 0) {
    ros_code_B.mLB_a = 0;
    while (ros_code_B.mLB_a <= ros_code_B.mUB_j - 1) {
      ros_code_B.c_j = x[obj->indexUB[ros_code_B.mLB_a] - 1] - obj->ub
        [obj->indexUB[ros_code_B.mLB_a] - 1];
      if ((!(v >= ros_code_B.c_j)) && (!rtIsNaN(ros_code_B.c_j))) {
        v = ros_code_B.c_j;
      }

      ros_code_B.mLB_a++;
    }
  }

  if (ros_code_B.mFixed_ga > 0) {
    ros_code_B.mUB_j = 0;
    while (ros_code_B.mUB_j <= ros_code_B.mFixed_ga - 1) {
      ros_code_B.c_j = fabs(x[obj->indexFixed[ros_code_B.mUB_j] - 1] - obj->
                            ub[obj->indexFixed[ros_code_B.mUB_j] - 1]);
      if ((!(v >= ros_code_B.c_j)) && (!rtIsNaN(ros_code_B.c_j))) {
        v = ros_code_B.c_j;
      }

      ros_code_B.mUB_j++;
    }
  }

  return v;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static real_T ros_co_maxConstraintViolation_c(snBUc3P0iDgb4fuyQLszkYC_ros_c_T
  *obj, const real_T x[5985])
{
  real_T v;
  ros_code_B.mLB_c = obj->sizes[3];
  ros_code_B.mUB_e = obj->sizes[4];
  ros_code_B.mFixed_m = obj->sizes[0];
  if (obj->probType == 2) {
    v = 0.0;
    for (ros_code_B.k_o = 0; ros_code_B.k_o < 44; ros_code_B.k_o++) {
      obj->maxConstrWorkspace[ros_code_B.k_o] = obj->bineq[ros_code_B.k_o];
      obj->maxConstrWorkspace[ros_code_B.k_o] = -obj->
        maxConstrWorkspace[ros_code_B.k_o];
    }

    for (ros_code_B.k_o = 0; ros_code_B.k_o <= 1936; ros_code_B.k_o += 45) {
      int32_T ix;
      ix = 133;
      ros_code_B.c_m = 0.0;
      for (int32_T b = ros_code_B.k_o; b < ros_code_B.k_o + 44; b++) {
        ros_code_B.c_m += obj->Aineq[b] * x[ix];
        ix++;
      }

      ix = div_nde_s32_floor(ros_code_B.k_o, 45);
      obj->maxConstrWorkspace[ix] += ros_code_B.c_m;
    }

    for (ros_code_B.k_o = 0; ros_code_B.k_o < 44; ros_code_B.k_o++) {
      obj->maxConstrWorkspace[ros_code_B.k_o] -= x[ros_code_B.k_o + 177];
      ros_code_B.c_m = obj->maxConstrWorkspace[ros_code_B.k_o];
      if ((!(v >= ros_code_B.c_m)) && (!rtIsNaN(ros_code_B.c_m))) {
        v = ros_code_B.c_m;
      }
    }
  } else {
    v = 0.0;
    for (ros_code_B.k_o = 0; ros_code_B.k_o < 44; ros_code_B.k_o++) {
      obj->maxConstrWorkspace[ros_code_B.k_o] = obj->bineq[ros_code_B.k_o];
      obj->maxConstrWorkspace[ros_code_B.k_o] = -obj->
        maxConstrWorkspace[ros_code_B.k_o];
    }

    for (ros_code_B.k_o = 0; ros_code_B.k_o <= 1936; ros_code_B.k_o += 45) {
      int32_T b;
      int32_T ix;
      ix = 133;
      ros_code_B.c_m = 0.0;
      b = ros_code_B.k_o + obj->nVar;
      for (int32_T ia = ros_code_B.k_o; ia < b; ia++) {
        ros_code_B.c_m += obj->Aineq[ia] * x[ix];
        ix++;
      }

      ix = div_nde_s32_floor(ros_code_B.k_o, 45);
      obj->maxConstrWorkspace[ix] += ros_code_B.c_m;
    }

    for (ros_code_B.k_o = 0; ros_code_B.k_o < 44; ros_code_B.k_o++) {
      ros_code_B.c_m = obj->maxConstrWorkspace[ros_code_B.k_o];
      if ((!(v >= ros_code_B.c_m)) && (!rtIsNaN(ros_code_B.c_m))) {
        v = ros_code_B.c_m;
      }
    }
  }

  if (ros_code_B.mLB_c > 0) {
    ros_code_B.k_o = 0;
    while (ros_code_B.k_o <= ros_code_B.mLB_c - 1) {
      ros_code_B.c_m = -x[obj->indexLB[ros_code_B.k_o] + 132] - obj->lb
        [obj->indexLB[ros_code_B.k_o] - 1];
      if ((!(v >= ros_code_B.c_m)) && (!rtIsNaN(ros_code_B.c_m))) {
        v = ros_code_B.c_m;
      }

      ros_code_B.k_o++;
    }
  }

  if (ros_code_B.mUB_e > 0) {
    ros_code_B.mLB_c = 0;
    while (ros_code_B.mLB_c <= ros_code_B.mUB_e - 1) {
      ros_code_B.c_m = x[obj->indexUB[ros_code_B.mLB_c] + 132] - obj->ub
        [obj->indexUB[ros_code_B.mLB_c] - 1];
      if ((!(v >= ros_code_B.c_m)) && (!rtIsNaN(ros_code_B.c_m))) {
        v = ros_code_B.c_m;
      }

      ros_code_B.mLB_c++;
    }
  }

  if (ros_code_B.mFixed_m > 0) {
    ros_code_B.mUB_e = 0;
    while (ros_code_B.mUB_e <= ros_code_B.mFixed_m - 1) {
      ros_code_B.c_m = fabs(x[obj->indexFixed[ros_code_B.mUB_e] + 132] - obj->
                            ub[obj->indexFixed[ros_code_B.mUB_e] - 1]);
      if ((!(v >= ros_code_B.c_m)) && (!rtIsNaN(ros_code_B.c_m))) {
        v = ros_code_B.c_m;
      }

      ros_code_B.mUB_e++;
    }
  }

  return v;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static boolean_T ros_cod_feasibleX0ForWorkingSet(real_T workspace[5985], real_T
  xCurrent[45], snBUc3P0iDgb4fuyQLszkYC_ros_c_T *workingset,
  siBmBjpOUwoybpuj9rEfGvD_ros_c_T *qrmanager)
{
  boolean_T nonDegenerateWset;
  ros_code_B.mWConstr_tmp_tmp = workingset->nActiveConstr - 1;
  ros_code_B.nVar_tmp_tmp_a = workingset->nVar;
  nonDegenerateWset = true;
  if (workingset->nActiveConstr != 0) {
    ros_code_B.iy_c = 0;
    while (ros_code_B.iy_c <= ros_code_B.mWConstr_tmp_tmp) {
      workspace[ros_code_B.iy_c] = workingset->bwset[ros_code_B.iy_c];
      workspace[ros_code_B.iy_c + 133] = workingset->bwset[ros_code_B.iy_c];
      ros_code_B.iy_c++;
    }

    if (workingset->nActiveConstr != 0) {
      ros_code_B.iy_c = 0;
      ros_code_B.iAcol = (workingset->nActiveConstr - 1) * 45 + 1;
      ros_code_B.b_ia = 1;
      while (ros_code_B.b_ia <= ros_code_B.iAcol) {
        ros_code_B.ix_d = 0;
        ros_code_B.c = 0.0;
        ros_code_B.d_p = (ros_code_B.b_ia + ros_code_B.nVar_tmp_tmp_a) - 1;
        ros_code_B.ia_p = ros_code_B.b_ia;
        while (ros_code_B.ia_p <= ros_code_B.d_p) {
          ros_code_B.c += workingset->ATwset[ros_code_B.ia_p - 1] *
            xCurrent[ros_code_B.ix_d];
          ros_code_B.ix_d++;
          ros_code_B.ia_p++;
        }

        workspace[ros_code_B.iy_c] += -ros_code_B.c;
        ros_code_B.iy_c++;
        ros_code_B.b_ia += 45;
      }
    }

    if (workingset->nActiveConstr >= workingset->nVar) {
      ros_code_B.iy_c = 0;
      while (ros_code_B.iy_c <= ros_code_B.nVar_tmp_tmp_a - 1) {
        ros_code_B.iAcol = 45 * ros_code_B.iy_c;
        ros_code_B.b_ia = 0;
        while (ros_code_B.b_ia <= ros_code_B.mWConstr_tmp_tmp) {
          qrmanager->QR[ros_code_B.b_ia + ros_code_B.iAcol] = workingset->
            ATwset[45 * ros_code_B.b_ia + ros_code_B.iy_c];
          ros_code_B.b_ia++;
        }

        ros_code_B.iy_c++;
      }

      qrmanager->usedPivoting = false;
      qrmanager->mrows = workingset->nActiveConstr;
      qrmanager->ncols = workingset->nVar;
      ros_code_B.iy_c = 0;
      while (ros_code_B.iy_c <= ros_code_B.nVar_tmp_tmp_a - 1) {
        qrmanager->jpvt[ros_code_B.iy_c] = ros_code_B.iy_c + 1;
        ros_code_B.iy_c++;
      }

      if (workingset->nActiveConstr <= workingset->nVar) {
        ros_code_B.iAcol = workingset->nActiveConstr;
      } else {
        ros_code_B.iAcol = workingset->nVar;
      }

      qrmanager->minRowCol = ros_code_B.iAcol;
      memcpy(&ros_code_B.B[0], &qrmanager->QR[0], 5985U * sizeof(real_T));
      memset(&qrmanager->tau[0], 0, 45U * sizeof(real_T));
      if (ros_code_B.iAcol >= 1) {
        memset(&qrmanager->tau[0], 0, 45U * sizeof(real_T));
        ros_code_qrf(ros_code_B.B, workingset->nActiveConstr, workingset->nVar,
                     ros_code_B.iAcol, qrmanager->tau);
      }

      memcpy(&qrmanager->QR[0], &ros_code_B.B[0], 5985U * sizeof(real_T));
      ros_code_computeQ_(qrmanager, qrmanager->mrows);
      memcpy(&ros_code_B.B[0], &workspace[0], 5985U * sizeof(real_T));
      ros_code_B.iy_c = 0;
      while (ros_code_B.iy_c + 1 <= ros_code_B.nVar_tmp_tmp_a) {
        workspace[ros_code_B.iy_c] = 0.0;
        ros_code_B.iy_c++;
      }

      ros_code_B.iy_c = 133;
      while (ros_code_B.iy_c + 1 <= ros_code_B.nVar_tmp_tmp_a + 133) {
        workspace[ros_code_B.iy_c] = 0.0;
        ros_code_B.iy_c++;
      }

      ros_code_B.iy_c = -1;
      ros_code_B.iAcol = 0;
      while (ros_code_B.iAcol + 1 <= ros_code_B.nVar_tmp_tmp_a) {
        ros_code_B.c = 0.0;
        ros_code_B.b_ia = 1;
        while (ros_code_B.b_ia - 1 <= ros_code_B.mWConstr_tmp_tmp) {
          ros_code_B.c += qrmanager->Q[ros_code_B.b_ia + ros_code_B.iy_c] *
            ros_code_B.B[ros_code_B.b_ia + -1];
          ros_code_B.b_ia++;
        }

        workspace[ros_code_B.iAcol] += ros_code_B.c;
        ros_code_B.iy_c += 45;
        ros_code_B.iAcol++;
      }

      ros_code_B.iy_c = -1;
      ros_code_B.iAcol = 133;
      while (ros_code_B.iAcol + 1 <= ros_code_B.nVar_tmp_tmp_a + 133) {
        ros_code_B.c = 0.0;
        ros_code_B.b_ia = 1;
        while (ros_code_B.b_ia - 1 <= ros_code_B.mWConstr_tmp_tmp) {
          ros_code_B.c += qrmanager->Q[ros_code_B.b_ia + ros_code_B.iy_c] *
            ros_code_B.B[ros_code_B.b_ia + 132];
          ros_code_B.b_ia++;
        }

        workspace[ros_code_B.iAcol] += ros_code_B.c;
        ros_code_B.iy_c += 45;
        ros_code_B.iAcol++;
      }

      ros_code_B.mWConstr_tmp_tmp = workingset->nVar;
      while (ros_code_B.mWConstr_tmp_tmp > 0) {
        ros_code_B.iy_c = (ros_code_B.mWConstr_tmp_tmp - 1) * 45 - 1;
        if (workspace[ros_code_B.mWConstr_tmp_tmp + -1] != 0.0) {
          workspace[ros_code_B.mWConstr_tmp_tmp + -1] /= qrmanager->
            QR[ros_code_B.mWConstr_tmp_tmp + ros_code_B.iy_c];
          ros_code_B.iAcol = 1;
          while (ros_code_B.iAcol - 1 <= ros_code_B.mWConstr_tmp_tmp - 2) {
            workspace[ros_code_B.iAcol + -1] -=
              workspace[ros_code_B.mWConstr_tmp_tmp + -1] * qrmanager->
              QR[ros_code_B.iAcol + ros_code_B.iy_c];
            ros_code_B.iAcol++;
          }
        }

        ros_code_B.mWConstr_tmp_tmp--;
      }

      ros_code_B.mWConstr_tmp_tmp = workingset->nVar;
      while (ros_code_B.mWConstr_tmp_tmp > 0) {
        ros_code_B.iy_c = (ros_code_B.mWConstr_tmp_tmp - 1) * 45 - 1;
        ros_code_B.c = workspace[ros_code_B.mWConstr_tmp_tmp + 132];
        if (ros_code_B.c != 0.0) {
          workspace[ros_code_B.mWConstr_tmp_tmp + 132] = ros_code_B.c /
            qrmanager->QR[ros_code_B.mWConstr_tmp_tmp + ros_code_B.iy_c];
          ros_code_B.iAcol = 1;
          while (ros_code_B.iAcol - 1 <= ros_code_B.mWConstr_tmp_tmp - 2) {
            workspace[ros_code_B.iAcol + 132] -=
              workspace[ros_code_B.mWConstr_tmp_tmp + 132] * qrmanager->
              QR[ros_code_B.iAcol + ros_code_B.iy_c];
            ros_code_B.iAcol++;
          }
        }

        ros_code_B.mWConstr_tmp_tmp--;
      }
    } else {
      ros_code_factorQR(qrmanager, workingset->ATwset, workingset->nVar,
                        workingset->nActiveConstr);
      ros_code_computeQ_(qrmanager, qrmanager->minRowCol);
      ros_code_B.iy_c = 1;
      while (ros_code_B.iy_c - 1 <= ros_code_B.mWConstr_tmp_tmp) {
        ros_code_B.iAcol = (ros_code_B.iy_c - 1) * 45 - 1;
        ros_code_B.c = workspace[ros_code_B.iy_c + -1];
        ros_code_B.b_ia = 1;
        while (ros_code_B.b_ia - 1 <= ros_code_B.iy_c - 2) {
          ros_code_B.c -= qrmanager->QR[ros_code_B.b_ia + ros_code_B.iAcol] *
            workspace[ros_code_B.b_ia + -1];
          ros_code_B.b_ia++;
        }

        workspace[ros_code_B.iy_c + -1] = ros_code_B.c / qrmanager->
          QR[ros_code_B.iy_c + ros_code_B.iAcol];
        ros_code_B.iy_c++;
      }

      ros_code_B.iy_c = 1;
      while (ros_code_B.iy_c - 1 <= ros_code_B.mWConstr_tmp_tmp) {
        ros_code_B.iAcol = (ros_code_B.iy_c - 1) * 45 - 1;
        ros_code_B.c = workspace[ros_code_B.iy_c + 132];
        ros_code_B.b_ia = 1;
        while (ros_code_B.b_ia - 1 <= ros_code_B.iy_c - 2) {
          ros_code_B.c -= qrmanager->QR[ros_code_B.b_ia + ros_code_B.iAcol] *
            workspace[ros_code_B.b_ia + 132];
          ros_code_B.b_ia++;
        }

        workspace[ros_code_B.iy_c + 132] = ros_code_B.c / qrmanager->
          QR[ros_code_B.iy_c + ros_code_B.iAcol];
        ros_code_B.iy_c++;
      }

      memcpy(&ros_code_B.B[0], &workspace[0], 5985U * sizeof(real_T));
      ros_code_B.iy_c = 0;
      while (ros_code_B.iy_c + 1 <= ros_code_B.nVar_tmp_tmp_a) {
        workspace[ros_code_B.iy_c] = 0.0;
        ros_code_B.iy_c++;
      }

      ros_code_B.iy_c = 133;
      while (ros_code_B.iy_c + 1 <= ros_code_B.nVar_tmp_tmp_a + 133) {
        workspace[ros_code_B.iy_c] = 0.0;
        ros_code_B.iy_c++;
      }

      ros_code_B.iy_c = -1;
      ros_code_B.iAcol = 1;
      while (ros_code_B.iAcol <= ros_code_B.mWConstr_tmp_tmp + 1) {
        ros_code_B.b_ia = ros_code_B.iy_c;
        ros_code_B.ix_d = 0;
        while (ros_code_B.ix_d + 1 <= ros_code_B.nVar_tmp_tmp_a) {
          ros_code_B.b_ia++;
          workspace[ros_code_B.ix_d] += ros_code_B.B[ros_code_B.iAcol - 1] *
            qrmanager->Q[ros_code_B.b_ia];
          ros_code_B.ix_d++;
        }

        ros_code_B.iy_c += 45;
        ros_code_B.iAcol++;
      }

      ros_code_B.iy_c = -1;
      ros_code_B.iAcol = 134;
      while (ros_code_B.iAcol <= ros_code_B.mWConstr_tmp_tmp + 134) {
        ros_code_B.b_ia = ros_code_B.iy_c;
        ros_code_B.ix_d = 133;
        while (ros_code_B.ix_d + 1 <= ros_code_B.nVar_tmp_tmp_a + 133) {
          ros_code_B.b_ia++;
          workspace[ros_code_B.ix_d] += ros_code_B.B[ros_code_B.iAcol - 1] *
            qrmanager->Q[ros_code_B.b_ia];
          ros_code_B.ix_d++;
        }

        ros_code_B.iy_c += 45;
        ros_code_B.iAcol++;
      }
    }

    ros_code_B.mWConstr_tmp_tmp = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (ros_code_B.mWConstr_tmp_tmp <= ros_code_B.nVar_tmp_tmp_a - 1) {
        if (rtIsInf(workspace[ros_code_B.mWConstr_tmp_tmp]) || rtIsNaN
            (workspace[ros_code_B.mWConstr_tmp_tmp])) {
          nonDegenerateWset = false;
          exitg1 = 1;
        } else {
          ros_code_B.c = workspace[ros_code_B.mWConstr_tmp_tmp + 133];
          if (rtIsInf(ros_code_B.c) || rtIsNaN(ros_code_B.c)) {
            nonDegenerateWset = false;
            exitg1 = 1;
          } else {
            ros_code_B.mWConstr_tmp_tmp++;
          }
        }
      } else {
        ros_code_B.mWConstr_tmp_tmp = 0;
        while (ros_code_B.mWConstr_tmp_tmp <= ros_code_B.nVar_tmp_tmp_a - 1) {
          workspace[ros_code_B.mWConstr_tmp_tmp] +=
            xCurrent[ros_code_B.mWConstr_tmp_tmp];
          ros_code_B.mWConstr_tmp_tmp++;
        }

        ros_code_B.c = ros_code_maxConstraintViolation(workingset, workspace);
        ros_code_B.constrViolation_basicX = ros_co_maxConstraintViolation_c
          (workingset, workspace);
        if ((ros_code_B.c <= 2.2204460492503131E-16) || (ros_code_B.c <
             ros_code_B.constrViolation_basicX)) {
          ros_code_B.mWConstr_tmp_tmp = 0;
          while (ros_code_B.mWConstr_tmp_tmp <= ros_code_B.nVar_tmp_tmp_a - 1) {
            xCurrent[ros_code_B.mWConstr_tmp_tmp] =
              workspace[ros_code_B.mWConstr_tmp_tmp];
            ros_code_B.mWConstr_tmp_tmp++;
          }
        } else {
          ros_code_B.mWConstr_tmp_tmp = 0;
          while (ros_code_B.mWConstr_tmp_tmp <= ros_code_B.nVar_tmp_tmp_a - 1) {
            xCurrent[ros_code_B.mWConstr_tmp_tmp] =
              workspace[ros_code_B.mWConstr_tmp_tmp + 133];
            ros_code_B.mWConstr_tmp_tmp++;
          }
        }

        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return nonDegenerateWset;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static real_T ros_c_maxConstraintViolation_c3(snBUc3P0iDgb4fuyQLszkYC_ros_c_T
  *obj, const real_T x[45])
{
  real_T v;
  ros_code_B.mLB = obj->sizes[3];
  ros_code_B.mUB_f = obj->sizes[4];
  ros_code_B.mFixed_g = obj->sizes[0];
  if (obj->probType == 2) {
    v = 0.0;
    for (ros_code_B.k_j = 0; ros_code_B.k_j < 44; ros_code_B.k_j++) {
      obj->maxConstrWorkspace[ros_code_B.k_j] = obj->bineq[ros_code_B.k_j];
      obj->maxConstrWorkspace[ros_code_B.k_j] = -obj->
        maxConstrWorkspace[ros_code_B.k_j];
    }

    for (ros_code_B.k_j = 0; ros_code_B.k_j <= 1936; ros_code_B.k_j += 45) {
      int32_T ix;
      ix = 0;
      ros_code_B.c_i = 0.0;
      for (int32_T b = ros_code_B.k_j; b < ros_code_B.k_j + 44; b++) {
        ros_code_B.c_i += obj->Aineq[b] * x[ix];
        ix++;
      }

      ix = div_nde_s32_floor(ros_code_B.k_j, 45);
      obj->maxConstrWorkspace[ix] += ros_code_B.c_i;
    }

    for (ros_code_B.k_j = 0; ros_code_B.k_j < 44; ros_code_B.k_j++) {
      obj->maxConstrWorkspace[ros_code_B.k_j] -= x[44];
      ros_code_B.c_i = obj->maxConstrWorkspace[ros_code_B.k_j];
      if ((!(v >= ros_code_B.c_i)) && (!rtIsNaN(ros_code_B.c_i))) {
        v = ros_code_B.c_i;
      }
    }
  } else {
    v = 0.0;
    for (ros_code_B.k_j = 0; ros_code_B.k_j < 44; ros_code_B.k_j++) {
      obj->maxConstrWorkspace[ros_code_B.k_j] = obj->bineq[ros_code_B.k_j];
      obj->maxConstrWorkspace[ros_code_B.k_j] = -obj->
        maxConstrWorkspace[ros_code_B.k_j];
    }

    for (ros_code_B.k_j = 0; ros_code_B.k_j <= 1936; ros_code_B.k_j += 45) {
      int32_T b;
      int32_T ix;
      ix = 0;
      ros_code_B.c_i = 0.0;
      b = ros_code_B.k_j + obj->nVar;
      for (int32_T ia = ros_code_B.k_j; ia < b; ia++) {
        ros_code_B.c_i += obj->Aineq[ia] * x[ix];
        ix++;
      }

      ix = div_nde_s32_floor(ros_code_B.k_j, 45);
      obj->maxConstrWorkspace[ix] += ros_code_B.c_i;
    }

    for (ros_code_B.k_j = 0; ros_code_B.k_j < 44; ros_code_B.k_j++) {
      ros_code_B.c_i = obj->maxConstrWorkspace[ros_code_B.k_j];
      if ((!(v >= ros_code_B.c_i)) && (!rtIsNaN(ros_code_B.c_i))) {
        v = ros_code_B.c_i;
      }
    }
  }

  if (ros_code_B.mLB > 0) {
    ros_code_B.k_j = 0;
    while (ros_code_B.k_j <= ros_code_B.mLB - 1) {
      ros_code_B.c_i = -x[obj->indexLB[ros_code_B.k_j] - 1] - obj->lb
        [obj->indexLB[ros_code_B.k_j] - 1];
      if ((!(v >= ros_code_B.c_i)) && (!rtIsNaN(ros_code_B.c_i))) {
        v = ros_code_B.c_i;
      }

      ros_code_B.k_j++;
    }
  }

  if (ros_code_B.mUB_f > 0) {
    ros_code_B.mLB = 0;
    while (ros_code_B.mLB <= ros_code_B.mUB_f - 1) {
      ros_code_B.c_i = x[obj->indexUB[ros_code_B.mLB] - 1] - obj->ub
        [obj->indexUB[ros_code_B.mLB] - 1];
      if ((!(v >= ros_code_B.c_i)) && (!rtIsNaN(ros_code_B.c_i))) {
        v = ros_code_B.c_i;
      }

      ros_code_B.mLB++;
    }
  }

  if (ros_code_B.mFixed_g > 0) {
    ros_code_B.mUB_f = 0;
    while (ros_code_B.mUB_f <= ros_code_B.mFixed_g - 1) {
      ros_code_B.c_i = fabs(x[obj->indexFixed[ros_code_B.mUB_f] - 1] - obj->
                            ub[obj->indexFixed[ros_code_B.mUB_f] - 1]);
      if ((!(v >= ros_code_B.c_i)) && (!rtIsNaN(ros_code_B.c_i))) {
        v = ros_code_B.c_i;
      }

      ros_code_B.mUB_f++;
    }
  }

  return v;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_PresolveWorkingSet(sEf9458k7RTCGn6XpAY3FSD_ros_c_T
  *solution, sg8qKdtlZ7nXgcAC5MP2QHC_ros_c_T *memspace,
  snBUc3P0iDgb4fuyQLszkYC_ros_c_T *workingset, siBmBjpOUwoybpuj9rEfGvD_ros_c_T
  *qrmanager)
{
  solution->state = 82;
  ros_code_RemoveDependentEq_(memspace, workingset, &ros_code_B.b_h, qrmanager);
  if ((ros_code_B.b_h != -1) && (workingset->nActiveConstr <= 45)) {
    boolean_T guard1 = false;
    boolean_T okWorkingSet;
    ros_code_RemoveDependentIneq_(workingset, qrmanager, memspace, 100.0);
    okWorkingSet = ros_cod_feasibleX0ForWorkingSet(memspace->workspace_double,
      solution->xstar, workingset, qrmanager);
    guard1 = false;
    if (!okWorkingSet) {
      ros_code_RemoveDependentIneq_(workingset, qrmanager, memspace, 1000.0);
      okWorkingSet = ros_cod_feasibleX0ForWorkingSet(memspace->workspace_double,
        solution->xstar, workingset, qrmanager);
      if (!okWorkingSet) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (workingset->nWConstr[0] + workingset->nWConstr[1] == workingset->nVar)
      {
        ros_code_B.constrViolation_a = ros_c_maxConstraintViolation_c3
          (workingset, solution->xstar);
        if (ros_code_B.constrViolation_a > 1.0E-8) {
          solution->state = -2;
        }
      }
    }
  } else {
    solution->state = -3;
    ros_code_removeAllIneqConstr(workingset);
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_linearForm_(boolean_T obj_hasLinear, int32_T obj_nvar,
  real_T workspace[5985], const real_T H[1936], const real_T f[44], const real_T
  x[45])
{
  ros_code_B.ix_jb = 0;
  if (obj_hasLinear) {
    ros_code_B.ix_jb = 0;
    while (ros_code_B.ix_jb <= obj_nvar - 1) {
      workspace[ros_code_B.ix_jb] = f[ros_code_B.ix_jb];
      ros_code_B.ix_jb++;
    }

    ros_code_B.ix_jb = 1;
  }

  if (obj_nvar != 0) {
    int32_T b;
    int32_T iac;
    if (ros_code_B.ix_jb != 1) {
      ros_code_B.ix_jb = 0;
      while (ros_code_B.ix_jb <= obj_nvar - 1) {
        workspace[ros_code_B.ix_jb] = 0.0;
        ros_code_B.ix_jb++;
      }
    }

    ros_code_B.ix_jb = 0;
    b = (obj_nvar - 1) * obj_nvar + 1;
    iac = 1;
    while (((obj_nvar > 0) && (iac <= b)) || ((obj_nvar < 0) && (iac >= b))) {
      int32_T d;
      ros_code_B.c_e = 0.5 * x[ros_code_B.ix_jb];
      ros_code_B.iy_j = 0;
      d = (iac + obj_nvar) - 1;
      for (int32_T ia = iac; ia <= d; ia++) {
        workspace[ros_code_B.iy_j] += H[ia - 1] * ros_code_B.c_e;
        ros_code_B.iy_j++;
      }

      ros_code_B.ix_jb++;
      iac += obj_nvar;
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static real_T ros_code_computeFval(const scRVBsoAowahmPoAIYa5ea_ros_co_T *obj,
  real_T workspace[5985], const real_T H[1936], const real_T f[44], const real_T
  x[45])
{
  real_T val;
  switch (obj->objtype) {
   case 5:
    val = x[obj->nvar - 1] * obj->gammaScalar;
    break;

   case 3:
    ros_code_linearForm_(obj->hasLinear, obj->nvar, workspace, H, f, x);
    val = 0.0;
    if (obj->nvar >= 1) {
      ros_code_B.idx_e = 0;
      while (ros_code_B.idx_e <= obj->nvar - 1) {
        val += x[ros_code_B.idx_e] * workspace[ros_code_B.idx_e];
        ros_code_B.idx_e++;
      }
    }
    break;

   default:
    ros_code_linearForm_(obj->hasLinear, obj->nvar, workspace, H, f, x);
    ros_code_B.idx_e = obj->nvar;
    while (ros_code_B.idx_e + 1 < 45) {
      workspace[ros_code_B.idx_e] = 0.0 * x[ros_code_B.idx_e];
      ros_code_B.idx_e++;
    }

    val = 0.0;
    for (ros_code_B.idx_e = 0; ros_code_B.idx_e < 44; ros_code_B.idx_e++) {
      val += x[ros_code_B.idx_e] * workspace[ros_code_B.idx_e];
    }
    break;
  }

  return val;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_xgemv(int32_T m, int32_T n, const real_T A[1936], int32_T
  lda, const real_T x[45], real_T y[44])
{
  if ((m != 0) && (n != 0)) {
    int32_T b;
    int32_T iac;
    ros_code_B.ix_m = 0;
    while (ros_code_B.ix_m <= m - 1) {
      y[ros_code_B.ix_m] = 0.0;
      ros_code_B.ix_m++;
    }

    ros_code_B.ix_m = 0;
    b = (n - 1) * lda + 1;
    iac = 1;
    while (((lda > 0) && (iac <= b)) || ((lda < 0) && (iac >= b))) {
      int32_T c;
      ros_code_B.iy_i = 0;
      c = (iac + m) - 1;
      for (int32_T ia = iac; ia <= c; ia++) {
        y[ros_code_B.iy_i] += A[ia - 1] * x[ros_code_B.ix_m];
        ros_code_B.iy_i++;
      }

      ros_code_B.ix_m++;
      iac += lda;
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_computeGrad_StoreHx(scRVBsoAowahmPoAIYa5ea_ros_co_T *obj,
  const real_T H[1936], const real_T f[44], const real_T x[45])
{
  switch (obj->objtype) {
   case 5:
    ros_code_B.b_ixlast = 0;
    while (ros_code_B.b_ixlast <= obj->nvar - 2) {
      obj->grad[ros_code_B.b_ixlast] = 0.0;
      ros_code_B.b_ixlast++;
    }

    obj->grad[obj->nvar - 1] = obj->gammaScalar;
    break;

   case 3:
    ros_code_xgemv(obj->nvar, obj->nvar, H, obj->nvar, x, obj->Hx);
    ros_code_B.b_ixlast = 0;
    while (ros_code_B.b_ixlast <= obj->nvar - 1) {
      obj->grad[ros_code_B.b_ixlast] = obj->Hx[ros_code_B.b_ixlast];
      ros_code_B.b_ixlast++;
    }

    if (obj->hasLinear && (obj->nvar >= 1)) {
      ros_code_B.b_ixlast = obj->nvar - 1;
      ros_code_B.b_k_j = 0;
      while (ros_code_B.b_k_j <= ros_code_B.b_ixlast) {
        obj->grad[ros_code_B.b_k_j] += f[ros_code_B.b_k_j];
        ros_code_B.b_k_j++;
      }
    }
    break;

   default:
    ros_code_xgemv(obj->nvar, obj->nvar, H, obj->nvar, x, obj->Hx);
    ros_code_B.b_ixlast = obj->nvar;
    while (ros_code_B.b_ixlast + 1 < 45) {
      obj->Hx[ros_code_B.b_ixlast] = 0.0 * x[ros_code_B.b_ixlast];
      ros_code_B.b_ixlast++;
    }

    memcpy(&obj->grad[0], &obj->Hx[0], 44U * sizeof(real_T));
    if (obj->hasLinear && (obj->nvar >= 1)) {
      ros_code_B.b_ixlast = obj->nvar - 1;
      ros_code_B.b_k_j = 0;
      while (ros_code_B.b_k_j <= ros_code_B.b_ixlast) {
        obj->grad[ros_code_B.b_k_j] += f[ros_code_B.b_k_j];
        ros_code_B.b_k_j++;
      }
    }
    break;
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static real_T ros_code_computeFval_ReuseHx(const scRVBsoAowahmPoAIYa5ea_ros_co_T
  *obj, real_T workspace[5985], const real_T f[44], const real_T x[45])
{
  real_T val;
  switch (obj->objtype) {
   case 5:
    val = x[obj->nvar - 1] * obj->gammaScalar;
    break;

   case 3:
    if (obj->hasLinear) {
      for (int32_T k = 0; k < obj->nvar; k++) {
        workspace[k] = 0.5 * obj->Hx[k] + f[k];
      }

      val = 0.0;
      if (obj->nvar >= 1) {
        for (int32_T k = 0; k < obj->nvar; k++) {
          val += x[k] * workspace[k];
        }
      }
    } else {
      val = 0.0;
      if (obj->nvar >= 1) {
        for (int32_T k = 0; k < obj->nvar; k++) {
          val += x[k] * obj->Hx[k];
        }
      }

      val *= 0.5;
    }
    break;

   default:
    if (obj->hasLinear) {
      for (int32_T k = 0; k < obj->nvar; k++) {
        workspace[k] = f[k];
      }

      for (int32_T k = 0; k <= 43 - obj->nvar; k++) {
        workspace[obj->nvar + k] = 0.0;
      }

      val = 0.0;
      for (int32_T k = 0; k < 44; k++) {
        workspace[k] += 0.5 * obj->Hx[k];
        val += x[k] * workspace[k];
      }
    } else {
      val = 0.0;
      for (int32_T k = 0; k < 44; k++) {
        val += x[k] * obj->Hx[k];
      }

      val *= 0.5;
      for (int32_T k = obj->nvar; k + 1 < 45; k++) {
        val += x[k] * 0.0;
      }
    }
    break;
  }

  return val;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_xrotg(real_T *a, real_T *b, real_T *c, real_T *s)
{
  ros_code_B.roe = *b;
  ros_code_B.absa = fabs(*a);
  ros_code_B.absb = fabs(*b);
  if (ros_code_B.absa > ros_code_B.absb) {
    ros_code_B.roe = *a;
  }

  ros_code_B.scale_p = ros_code_B.absa + ros_code_B.absb;
  if (ros_code_B.scale_p == 0.0) {
    *s = 0.0;
    *c = 1.0;
    *a = 0.0;
    *b = 0.0;
  } else {
    ros_code_B.ads = ros_code_B.absa / ros_code_B.scale_p;
    ros_code_B.bds = ros_code_B.absb / ros_code_B.scale_p;
    ros_code_B.scale_p *= sqrt(ros_code_B.ads * ros_code_B.ads + ros_code_B.bds *
      ros_code_B.bds);
    if (ros_code_B.roe < 0.0) {
      ros_code_B.scale_p = -ros_code_B.scale_p;
    }

    *c = *a / ros_code_B.scale_p;
    *s = *b / ros_code_B.scale_p;
    if (ros_code_B.absa > ros_code_B.absb) {
      *b = *s;
    } else if (*c != 0.0) {
      *b = 1.0 / *c;
    } else {
      *b = 1.0;
    }

    *a = ros_code_B.scale_p;
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_deleteColMoveEnd(siBmBjpOUwoybpuj9rEfGvD_ros_c_T *obj,
  int32_T idx)
{
  if (obj->usedPivoting) {
    ros_code_B.i_b = 1;
    while ((ros_code_B.i_b <= obj->ncols) && (obj->jpvt[ros_code_B.i_b - 1] !=
            idx)) {
      ros_code_B.i_b++;
    }

    idx = ros_code_B.i_b;
  }

  if (idx >= obj->ncols) {
    obj->ncols--;
  } else {
    obj->jpvt[idx - 1] = obj->jpvt[obj->ncols - 1];
    ros_code_B.i_b = 0;
    while (ros_code_B.i_b <= obj->minRowCol - 1) {
      obj->QR[ros_code_B.i_b + 45 * (idx - 1)] = obj->QR[(obj->ncols - 1) * 45 +
        ros_code_B.i_b];
      ros_code_B.i_b++;
    }

    obj->ncols--;
    if (obj->mrows <= obj->ncols) {
      obj->minRowCol = obj->mrows;
    } else {
      obj->minRowCol = obj->ncols;
    }

    if (idx < obj->mrows) {
      int32_T b_ix;
      int32_T c_ix;
      int32_T ix;
      if (obj->mrows - 1 <= obj->ncols) {
        ros_code_B.i_b = obj->mrows - 1;
      } else {
        ros_code_B.i_b = obj->ncols;
      }

      ros_code_B.k_hm = ros_code_B.i_b;
      ros_code_B.idxRotGCol = (idx - 1) * 45;
      while (ros_code_B.k_hm >= idx) {
        ros_code_B.QRk0 = ros_code_B.k_hm + ros_code_B.idxRotGCol;
        ros_code_B.b_temp = obj->QR[ros_code_B.QRk0];
        ros_code_xrotg(&obj->QR[(ros_code_B.k_hm + ros_code_B.idxRotGCol) - 1],
                       &ros_code_B.b_temp, &ros_code_B.c_c_k, &ros_code_B.b_s);
        obj->QR[ros_code_B.QRk0] = ros_code_B.b_temp;
        c_ix = (ros_code_B.k_hm - 1) * 45;
        obj->QR[ros_code_B.k_hm + c_ix] = 0.0;
        ros_code_B.QRk0 = 45 * idx + ros_code_B.k_hm;
        b_ix = obj->ncols - idx;
        if (b_ix >= 1) {
          ix = ros_code_B.QRk0 - 1;
          for (int32_T d_k = 0; d_k < b_ix; d_k++) {
            ros_code_B.b_temp = ros_code_B.c_c_k * obj->QR[ix] + ros_code_B.b_s *
              obj->QR[ros_code_B.QRk0];
            obj->QR[ros_code_B.QRk0] = ros_code_B.c_c_k * obj->
              QR[ros_code_B.QRk0] - ros_code_B.b_s * obj->QR[ix];
            obj->QR[ix] = ros_code_B.b_temp;
            ros_code_B.QRk0 += 45;
            ix += 45;
          }
        }

        if (obj->mrows >= 1) {
          ros_code_B.QRk0 = c_ix + 45;
          for (b_ix = 0; b_ix < obj->mrows; b_ix++) {
            ros_code_B.b_temp = ros_code_B.c_c_k * obj->Q[c_ix] + ros_code_B.b_s
              * obj->Q[ros_code_B.QRk0];
            obj->Q[ros_code_B.QRk0] = ros_code_B.c_c_k * obj->Q[ros_code_B.QRk0]
              - ros_code_B.b_s * obj->Q[c_ix];
            obj->Q[c_ix] = ros_code_B.b_temp;
            ros_code_B.QRk0++;
            c_ix++;
          }
        }

        ros_code_B.k_hm--;
      }

      ros_code_B.k_hm = idx + 1;
      while (ros_code_B.k_hm <= ros_code_B.i_b) {
        ros_code_B.idxRotGCol = (ros_code_B.k_hm - 1) * 45;
        ros_code_B.QRk0 = ros_code_B.k_hm + ros_code_B.idxRotGCol;
        ros_code_B.b_temp = obj->QR[ros_code_B.QRk0];
        ros_code_xrotg(&obj->QR[(ros_code_B.k_hm + ros_code_B.idxRotGCol) - 1],
                       &ros_code_B.b_temp, &ros_code_B.c_c_k, &ros_code_B.b_s);
        obj->QR[ros_code_B.QRk0] = ros_code_B.b_temp;
        ros_code_B.QRk0 = ros_code_B.k_hm * 46;
        c_ix = obj->ncols - ros_code_B.k_hm;
        if (c_ix >= 1) {
          b_ix = ros_code_B.QRk0 - 1;
          for (ix = 0; ix < c_ix; ix++) {
            ros_code_B.b_temp = ros_code_B.c_c_k * obj->QR[b_ix] +
              ros_code_B.b_s * obj->QR[ros_code_B.QRk0];
            obj->QR[ros_code_B.QRk0] = ros_code_B.c_c_k * obj->
              QR[ros_code_B.QRk0] - ros_code_B.b_s * obj->QR[b_ix];
            obj->QR[b_ix] = ros_code_B.b_temp;
            ros_code_B.QRk0 += 45;
            b_ix += 45;
          }
        }

        if (obj->mrows >= 1) {
          ros_code_B.QRk0 = ros_code_B.idxRotGCol + 45;
          for (c_ix = 0; c_ix < obj->mrows; c_ix++) {
            ros_code_B.b_temp = ros_code_B.c_c_k * obj->Q[ros_code_B.idxRotGCol]
              + ros_code_B.b_s * obj->Q[ros_code_B.QRk0];
            obj->Q[ros_code_B.QRk0] = ros_code_B.c_c_k * obj->Q[ros_code_B.QRk0]
              - ros_code_B.b_s * obj->Q[ros_code_B.idxRotGCol];
            obj->Q[ros_code_B.idxRotGCol] = ros_code_B.b_temp;
            ros_code_B.QRk0++;
            ros_code_B.idxRotGCol++;
          }
        }

        ros_code_B.k_hm++;
      }
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_cod_computeProjectedHessian(const real_T H[1936],
  svUSr4TrK4x4Kz9rQJTxkkF_ros_c_T *cholmanager, const
  siBmBjpOUwoybpuj9rEfGvD_ros_c_T *qrmanager, sg8qKdtlZ7nXgcAC5MP2QHC_ros_c_T
  *memspace)
{
  int32_T ib;
  ros_code_B.nVars = qrmanager->mrows;
  ros_code_B.mNull_f = qrmanager->mrows - qrmanager->ncols;
  ros_code_B.nullStart = 45 * qrmanager->ncols;
  if ((qrmanager->mrows != 0) && (ros_code_B.mNull_f != 0)) {
    ros_code_B.br_j = ros_code_B.nullStart;
    ros_code_B.lastColC = (ros_code_B.mNull_f - 1) * 133;
    ros_code_B.cr = 0;
    while (ros_code_B.cr <= ros_code_B.lastColC) {
      ros_code_B.ar_h = ros_code_B.cr;
      ib = ros_code_B.cr + ros_code_B.nVars;
      while (ros_code_B.ar_h + 1 <= ib) {
        memspace->workspace_double[ros_code_B.ar_h] = 0.0;
        ros_code_B.ar_h++;
      }

      ros_code_B.cr += 133;
    }

    ros_code_B.cr = 0;
    while (ros_code_B.cr <= ros_code_B.lastColC) {
      ros_code_B.ar_h = -1;
      ib = ros_code_B.br_j;
      ros_code_B.c_n = ros_code_B.br_j + ros_code_B.nVars;
      while (ib + 1 <= ros_code_B.c_n) {
        int32_T b_ic;
        int32_T d;
        ros_code_B.ia_c = ros_code_B.ar_h;
        b_ic = ros_code_B.cr;
        d = ros_code_B.cr + ros_code_B.nVars;
        while (b_ic + 1 <= d) {
          ros_code_B.ia_c++;
          memspace->workspace_double[b_ic] += qrmanager->Q[ib] *
            H[ros_code_B.ia_c];
          b_ic++;
        }

        ros_code_B.ar_h += ros_code_B.nVars;
        ib++;
      }

      ros_code_B.br_j += 45;
      ros_code_B.cr += 133;
    }
  }

  if (ros_code_B.mNull_f != 0) {
    ros_code_B.br_j = (ros_code_B.mNull_f - 1) * 45;
    ros_code_B.lastColC = 0;
    while (ros_code_B.lastColC <= ros_code_B.br_j) {
      ros_code_B.cr = ros_code_B.lastColC;
      ros_code_B.ar_h = ros_code_B.lastColC + ros_code_B.mNull_f;
      while (ros_code_B.cr + 1 <= ros_code_B.ar_h) {
        cholmanager->FMat[ros_code_B.cr] = 0.0;
        ros_code_B.cr++;
      }

      ros_code_B.lastColC += 45;
    }

    ros_code_B.lastColC = -1;
    ros_code_B.cr = 0;
    while (ros_code_B.cr <= ros_code_B.br_j) {
      ros_code_B.ar_h = ros_code_B.nullStart;
      ib = ros_code_B.cr;
      ros_code_B.c_n = ros_code_B.cr + ros_code_B.mNull_f;
      while (ib + 1 <= ros_code_B.c_n) {
        ros_code_B.temp_h = 0.0;
        ros_code_B.ia_c = 1;
        while (ros_code_B.ia_c - 1 <= ros_code_B.nVars - 1) {
          ros_code_B.temp_h += qrmanager->Q[(ros_code_B.ia_c + ros_code_B.ar_h)
            - 1] * memspace->workspace_double[ros_code_B.ia_c +
            ros_code_B.lastColC];
          ros_code_B.ia_c++;
        }

        cholmanager->FMat[ib] += ros_code_B.temp_h;
        ros_code_B.ar_h += 45;
        ib++;
      }

      ros_code_B.lastColC += 133;
      ros_code_B.cr += 45;
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static int32_T ros_code_ixamax(int32_T n, const real_T x[2025])
{
  int32_T idxmax;
  if (n < 1) {
    idxmax = 0;
  } else {
    idxmax = 1;
    if (n > 1) {
      int32_T ix;
      ix = 0;
      ros_code_B.smax_d = fabs(x[0]);
      for (int32_T k = 2; k <= n; k++) {
        real_T s;
        ix += 46;
        s = fabs(x[ix]);
        if (s > ros_code_B.smax_d) {
          idxmax = k;
          ros_code_B.smax_d = s;
        }
      }
    }
  }

  return idxmax;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_fullColLDL2_(svUSr4TrK4x4Kz9rQJTxkkF_ros_c_T *obj, int32_T
  NColsRemain, real_T REG_PRIMAL)
{
  ros_code_B.lastDiag = 0;
  while (ros_code_B.lastDiag <= NColsRemain - 1) {
    ros_code_B.LD_diagOffset = 46 * ros_code_B.lastDiag;
    if (fabs(obj->FMat[ros_code_B.LD_diagOffset]) <= obj->regTol_) {
      obj->FMat[ros_code_B.LD_diagOffset] += REG_PRIMAL;
    }

    ros_code_B.alpha1_a = -1.0 / obj->FMat[ros_code_B.LD_diagOffset];
    ros_code_B.subMatrixDim = (NColsRemain - ros_code_B.lastDiag) - 2;
    ros_code_B.jA = 0;
    while (ros_code_B.jA <= ros_code_B.subMatrixDim) {
      obj->workspace_[ros_code_B.jA] = obj->FMat[(ros_code_B.LD_diagOffset +
        ros_code_B.jA) + 1];
      ros_code_B.jA++;
    }

    if (!(ros_code_B.alpha1_a == 0.0)) {
      ros_code_B.jA = ros_code_B.LD_diagOffset + 46;
      ros_code_B.jy_k = 0;
      for (int32_T j = 0; j <= ros_code_B.subMatrixDim; j++) {
        if (obj->workspace_[ros_code_B.jy_k] != 0.0) {
          int32_T b;
          int32_T ijA;
          int32_T ix;
          ros_code_B.temp_k = obj->workspace_[ros_code_B.jy_k] *
            ros_code_B.alpha1_a;
          ix = 0;
          ijA = ros_code_B.jA;
          b = ros_code_B.subMatrixDim + ros_code_B.jA;
          while (ijA + 1 <= b + 1) {
            obj->FMat[ijA] += obj->workspace_[ix] * ros_code_B.temp_k;
            ix++;
            ijA++;
          }
        }

        ros_code_B.jy_k++;
        ros_code_B.jA += 45;
      }
    }

    ros_code_B.jA = 1;
    while (ros_code_B.jA - 1 <= ros_code_B.subMatrixDim) {
      ros_code_B.jy_k = ros_code_B.LD_diagOffset + ros_code_B.jA;
      obj->FMat[ros_code_B.jy_k] /= obj->FMat[ros_code_B.LD_diagOffset];
      ros_code_B.jA++;
    }

    ros_code_B.lastDiag++;
  }

  ros_code_B.lastDiag = (NColsRemain - 1) * 46;
  if (fabs(obj->FMat[ros_code_B.lastDiag]) <= obj->regTol_) {
    obj->FMat[ros_code_B.lastDiag] += REG_PRIMAL;
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_xgemv_j(int32_T m, int32_T n, const real_T A[2025], int32_T
  ia0, const real_T x[5985], real_T y[45])
{
  if (m != 0) {
    int32_T b;
    ros_code_B.ix_o = 0;
    while (ros_code_B.ix_o <= m - 1) {
      y[ros_code_B.ix_o] = 0.0;
      ros_code_B.ix_o++;
    }

    ros_code_B.ix_o = 0;
    b = (n - 1) * 45 + ia0;
    for (int32_T iac = ia0; iac <= b; iac += 45) {
      int32_T c;
      ros_code_B.iy_j0 = 0;
      c = (iac + m) - 1;
      for (int32_T ia = iac; ia <= c; ia++) {
        y[ros_code_B.iy_j0] += A[ia - 1] * x[ros_code_B.ix_o];
        ros_code_B.iy_j0++;
      }

      ros_code_B.ix_o++;
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_compute_deltax(const real_T H[1936],
  sEf9458k7RTCGn6XpAY3FSD_ros_c_T *solution, sg8qKdtlZ7nXgcAC5MP2QHC_ros_c_T
  *memspace, const siBmBjpOUwoybpuj9rEfGvD_ros_c_T *qrmanager,
  svUSr4TrK4x4Kz9rQJTxkkF_ros_c_T *cholmanager, const
  scRVBsoAowahmPoAIYa5ea_ros_co_T *objective)
{
  ros_code_B.nVar_l = qrmanager->mrows - 1;
  ros_code_B.mNull = qrmanager->mrows - qrmanager->ncols;
  if (ros_code_B.mNull <= 0) {
    ros_code_B.mNull = 0;
    while (ros_code_B.mNull <= ros_code_B.nVar_l) {
      solution->searchDir[ros_code_B.mNull] = 0.0;
      ros_code_B.mNull++;
    }
  } else {
    ros_code_B.nullStartIdx = 0;
    while (ros_code_B.nullStartIdx <= ros_code_B.nVar_l) {
      solution->searchDir[ros_code_B.nullStartIdx] = -objective->
        grad[ros_code_B.nullStartIdx];
      ros_code_B.nullStartIdx++;
    }

    if (qrmanager->ncols <= 0) {
      if (objective->objtype == 3) {
        ros_code_B.b_SCALED_REG_PRIMAL = 1.4901161193847656E-6 *
          static_cast<real_T>(qrmanager->mrows);
        cholmanager->ndims = qrmanager->mrows;
        ros_code_B.mNull = 0;
        while (ros_code_B.mNull <= ros_code_B.nVar_l) {
          ros_code_B.nullStartIdx = (ros_code_B.nVar_l + 1) * ros_code_B.mNull;
          ros_code_B.b_A_maxDiag_idx = 45 * ros_code_B.mNull;
          ros_code_B.b_jjA = 1;
          while (ros_code_B.b_jjA - 1 <= ros_code_B.nVar_l) {
            cholmanager->FMat[(ros_code_B.b_A_maxDiag_idx + ros_code_B.b_jjA) -
              1] = H[(ros_code_B.nullStartIdx + ros_code_B.b_jjA) - 1];
            ros_code_B.b_jjA++;
          }

          ros_code_B.mNull++;
        }

        ros_code_B.mNull = ros_code_ixamax(qrmanager->mrows, cholmanager->FMat)
          - 1;
        ros_code_B.c_l = fabs(cholmanager->FMat[45 * ros_code_B.mNull +
                              ros_code_B.mNull]) * 2.2204460492503131E-16;
        ros_code_B.u1 = fabs(ros_code_B.b_SCALED_REG_PRIMAL);
        if (ros_code_B.c_l >= ros_code_B.u1) {
          cholmanager->regTol_ = ros_code_B.c_l;
        } else {
          cholmanager->regTol_ = ros_code_B.u1;
        }

        ros_code_fullColLDL2_(cholmanager, qrmanager->mrows,
                              ros_code_B.b_SCALED_REG_PRIMAL);
        if (cholmanager->ConvexCheck) {
          ros_code_B.mNull = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (ros_code_B.mNull <= ros_code_B.nVar_l) {
              if (cholmanager->FMat[45 * ros_code_B.mNull + ros_code_B.mNull] <=
                  0.0) {
                cholmanager->info = -ros_code_B.mNull - 1;
                exitg1 = 1;
              } else {
                ros_code_B.mNull++;
              }
            } else {
              cholmanager->ConvexCheck = false;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }

        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          ros_code_B.mNull = cholmanager->ndims - 1;
          if (cholmanager->ndims != 0) {
            ros_code_B.nullStartIdx = 0;
            while (ros_code_B.nullStartIdx <= ros_code_B.mNull) {
              ros_code_B.nVar_l = ros_code_B.nullStartIdx * 45 +
                ros_code_B.nullStartIdx;
              ros_code_B.b_A_maxDiag_idx = ros_code_B.mNull -
                ros_code_B.nullStartIdx;
              ros_code_B.b_jjA = 1;
              while (ros_code_B.b_jjA - 1 <= ros_code_B.b_A_maxDiag_idx - 1) {
                ros_code_B.b_ix_d = ros_code_B.nullStartIdx + ros_code_B.b_jjA;
                solution->searchDir[ros_code_B.b_ix_d] -= cholmanager->
                  FMat[ros_code_B.nVar_l + ros_code_B.b_jjA] *
                  solution->searchDir[ros_code_B.nullStartIdx];
                ros_code_B.b_jjA++;
              }

              ros_code_B.nullStartIdx++;
            }
          }

          ros_code_B.nullStartIdx = 0;
          while (ros_code_B.nullStartIdx <= ros_code_B.mNull) {
            solution->searchDir[ros_code_B.nullStartIdx] /= cholmanager->FMat[45
              * ros_code_B.nullStartIdx + ros_code_B.nullStartIdx];
            ros_code_B.nullStartIdx++;
          }

          if (cholmanager->ndims != 0) {
            ros_code_B.mNull = cholmanager->ndims - 1;
            while (ros_code_B.mNull + 1 > 0) {
              ros_code_B.nullStartIdx = ros_code_B.mNull * 45;
              ros_code_B.c_l = solution->searchDir[ros_code_B.mNull];
              ros_code_B.nVar_l = cholmanager->ndims;
              while (ros_code_B.nVar_l >= ros_code_B.mNull + 2) {
                ros_code_B.c_l -= cholmanager->FMat[(ros_code_B.nullStartIdx +
                  ros_code_B.nVar_l) - 1] * solution->
                  searchDir[ros_code_B.nVar_l - 1];
                ros_code_B.nVar_l--;
              }

              solution->searchDir[ros_code_B.mNull] = ros_code_B.c_l;
              ros_code_B.mNull--;
            }
          }
        }
      }
    } else {
      ros_code_B.nullStartIdx = 45 * qrmanager->ncols + 1;
      if (objective->objtype == 5) {
        ros_code_B.b_A_maxDiag_idx = 0;
        while (ros_code_B.b_A_maxDiag_idx <= ros_code_B.mNull - 1) {
          memspace->workspace_double[ros_code_B.b_A_maxDiag_idx] = -qrmanager->
            Q[(qrmanager->ncols + ros_code_B.b_A_maxDiag_idx) * 45 +
            ros_code_B.nVar_l];
          ros_code_B.b_A_maxDiag_idx++;
        }

        ros_code_xgemv_j(qrmanager->mrows, ros_code_B.mNull, qrmanager->Q,
                         ros_code_B.nullStartIdx, memspace->workspace_double,
                         solution->searchDir);
      } else {
        if (objective->objtype == 3) {
          ros_cod_computeProjectedHessian(H, cholmanager, qrmanager, memspace);
        }

        ros_code_B.b_SCALED_REG_PRIMAL = 1.4901161193847656E-6 *
          static_cast<real_T>(ros_code_B.mNull);
        cholmanager->ndims = ros_code_B.mNull;
        ros_code_B.b_A_maxDiag_idx = ros_code_ixamax(ros_code_B.mNull,
          cholmanager->FMat) - 1;
        ros_code_B.c_l = fabs(cholmanager->FMat[45 * ros_code_B.b_A_maxDiag_idx
                              + ros_code_B.b_A_maxDiag_idx]) *
          2.2204460492503131E-16;
        if (ros_code_B.c_l >= ros_code_B.b_SCALED_REG_PRIMAL) {
          cholmanager->regTol_ = ros_code_B.c_l;
        } else {
          cholmanager->regTol_ = ros_code_B.b_SCALED_REG_PRIMAL;
        }

        ros_code_fullColLDL2_(cholmanager, ros_code_B.mNull,
                              ros_code_B.b_SCALED_REG_PRIMAL);
        if (cholmanager->ConvexCheck) {
          ros_code_B.b_A_maxDiag_idx = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (ros_code_B.b_A_maxDiag_idx <= ros_code_B.mNull - 1) {
              if (cholmanager->FMat[45 * ros_code_B.b_A_maxDiag_idx +
                  ros_code_B.b_A_maxDiag_idx] <= 0.0) {
                cholmanager->info = -ros_code_B.b_A_maxDiag_idx - 1;
                exitg1 = 1;
              } else {
                ros_code_B.b_A_maxDiag_idx++;
              }
            } else {
              cholmanager->ConvexCheck = false;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }

        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          if (qrmanager->mrows != 0) {
            ros_code_B.b_A_maxDiag_idx = 0;
            while (ros_code_B.b_A_maxDiag_idx <= ros_code_B.mNull - 1) {
              memspace->workspace_double[ros_code_B.b_A_maxDiag_idx] = 0.0;
              ros_code_B.b_A_maxDiag_idx++;
            }

            ros_code_B.b_A_maxDiag_idx = 0;
            ros_code_B.b_jjA = (ros_code_B.mNull - 1) * 45 +
              ros_code_B.nullStartIdx;
            ros_code_B.b_ix_d = ros_code_B.nullStartIdx;
            while (ros_code_B.b_ix_d <= ros_code_B.b_jjA) {
              ros_code_B.ix_g = 0;
              ros_code_B.c_l = 0.0;
              ros_code_B.c_ix_j = ros_code_B.b_ix_d + ros_code_B.nVar_l;
              ros_code_B.ia_d = ros_code_B.b_ix_d;
              while (ros_code_B.ia_d <= ros_code_B.c_ix_j) {
                ros_code_B.c_l += qrmanager->Q[ros_code_B.ia_d - 1] *
                  objective->grad[ros_code_B.ix_g];
                ros_code_B.ix_g++;
                ros_code_B.ia_d++;
              }

              memspace->workspace_double[ros_code_B.b_A_maxDiag_idx] +=
                -ros_code_B.c_l;
              ros_code_B.b_A_maxDiag_idx++;
              ros_code_B.b_ix_d += 45;
            }
          }

          ros_code_B.nVar_l = cholmanager->ndims - 1;
          if (cholmanager->ndims != 0) {
            ros_code_B.b_A_maxDiag_idx = 0;
            while (ros_code_B.b_A_maxDiag_idx <= ros_code_B.nVar_l) {
              ros_code_B.b_jjA = ros_code_B.b_A_maxDiag_idx * 45 +
                ros_code_B.b_A_maxDiag_idx;
              ros_code_B.b_ix_d = ros_code_B.nVar_l - ros_code_B.b_A_maxDiag_idx;
              ros_code_B.ix_g = 1;
              while (ros_code_B.ix_g - 1 <= ros_code_B.b_ix_d - 1) {
                ros_code_B.c_ix_j = ros_code_B.b_A_maxDiag_idx + ros_code_B.ix_g;
                memspace->workspace_double[ros_code_B.c_ix_j] -=
                  cholmanager->FMat[ros_code_B.b_jjA + ros_code_B.ix_g] *
                  memspace->workspace_double[ros_code_B.b_A_maxDiag_idx];
                ros_code_B.ix_g++;
              }

              ros_code_B.b_A_maxDiag_idx++;
            }
          }

          ros_code_B.b_A_maxDiag_idx = 0;
          while (ros_code_B.b_A_maxDiag_idx <= ros_code_B.nVar_l) {
            memspace->workspace_double[ros_code_B.b_A_maxDiag_idx] /=
              cholmanager->FMat[45 * ros_code_B.b_A_maxDiag_idx +
              ros_code_B.b_A_maxDiag_idx];
            ros_code_B.b_A_maxDiag_idx++;
          }

          if (cholmanager->ndims != 0) {
            ros_code_B.nVar_l = cholmanager->ndims - 1;
            while (ros_code_B.nVar_l + 1 > 0) {
              ros_code_B.b_A_maxDiag_idx = ros_code_B.nVar_l * 45;
              ros_code_B.c_l = memspace->workspace_double[ros_code_B.nVar_l];
              ros_code_B.b_jjA = cholmanager->ndims;
              while (ros_code_B.b_jjA >= ros_code_B.nVar_l + 2) {
                ros_code_B.c_l -= cholmanager->FMat[(ros_code_B.b_A_maxDiag_idx
                  + ros_code_B.b_jjA) - 1] * memspace->
                  workspace_double[ros_code_B.b_jjA - 1];
                ros_code_B.b_jjA--;
              }

              memspace->workspace_double[ros_code_B.nVar_l] = ros_code_B.c_l;
              ros_code_B.nVar_l--;
            }
          }

          ros_code_xgemv_j(qrmanager->mrows, ros_code_B.mNull, qrmanager->Q,
                           ros_code_B.nullStartIdx, memspace->workspace_double,
                           solution->searchDir);
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static real_T ros_code_xnrm2_o2(int32_T n, const real_T x[45])
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[0]);
    } else {
      ros_code_B.scale_k = 3.3121686421112381E-170;
      for (int32_T k = 0; k < n; k++) {
        ros_code_B.absxk_i = fabs(x[k]);
        if (ros_code_B.absxk_i > ros_code_B.scale_k) {
          real_T t;
          t = ros_code_B.scale_k / ros_code_B.absxk_i;
          y = y * t * t + 1.0;
          ros_code_B.scale_k = ros_code_B.absxk_i;
        } else {
          real_T t;
          t = ros_code_B.absxk_i / ros_code_B.scale_k;
          y += t * t;
        }
      }

      y = ros_code_B.scale_k * sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_xgemv_ju(int32_T m, const real_T A[1980], const real_T x[45],
  real_T y[5985])
{
  for (ros_code_B.b_iy_f = 0; ros_code_B.b_iy_f <= 42; ros_code_B.b_iy_f += 2) {
    __m128d tmp;
    tmp = _mm_loadu_pd(&y[ros_code_B.b_iy_f]);
    _mm_storeu_pd(&y[ros_code_B.b_iy_f], _mm_mul_pd(tmp, _mm_set1_pd(-1.0)));
  }

  for (ros_code_B.b_iy_f = 0; ros_code_B.b_iy_f <= 1936; ros_code_B.b_iy_f += 45)
  {
    ros_code_B.ix_a = 0;
    ros_code_B.c_c = 0.0;
    ros_code_B.b_j = ros_code_B.b_iy_f + m;
    ros_code_B.ia_k = ros_code_B.b_iy_f;
    while (ros_code_B.ia_k + 1 <= ros_code_B.b_j) {
      ros_code_B.c_c += A[ros_code_B.ia_k] * x[ros_code_B.ix_a];
      ros_code_B.ix_a++;
      ros_code_B.ia_k++;
    }

    ros_code_B.ix_a = div_nde_s32_floor(ros_code_B.b_iy_f, 45);
    y[ros_code_B.ix_a] += ros_code_B.c_c;
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_xgemv_ju2(int32_T m, const real_T A[1980], const real_T x
  [45], real_T y[5985])
{
  memset(&y[133], 0, 44U * sizeof(real_T));
  for (int32_T b_iy = 0; b_iy <= 1936; b_iy += 45) {
    int32_T b;
    int32_T ix;
    ix = 0;
    ros_code_B.c_a = 0.0;
    b = b_iy + m;
    for (int32_T ia = b_iy; ia < b; ia++) {
      ros_code_B.c_a += A[ia] * x[ix];
      ix++;
    }

    ix = div_nde_s32_floor(b_iy, 45) + 133;
    y[ix] += ros_code_B.c_a;
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_ratiotest(const real_T solution_xstar[45], const real_T
  solution_searchDir[45], real_T workspace[5985], int32_T workingset_nVar, const
  real_T workingset_Aineq[1980], const real_T workingset_bineq[44], const real_T
  workingset_lb[45], const real_T workingset_ub[45], const int32_T
  workingset_indexLB[45], const int32_T workingset_indexUB[45], const int32_T
  workingset_sizes[5], const int32_T workingset_isActiveIdx[6], const boolean_T
  workingset_isActiveConstr[133], const int32_T workingset_nWConstr[5], real_T
  *toldelta, real_T *alpha, boolean_T *newBlocking, int32_T *constrType, int32_T
  *constrIdx)
{
  *alpha = 1.0E+30;
  *newBlocking = false;
  *constrType = 0;
  *constrIdx = 0;
  ros_code_B.p_max = 0.0;
  ros_code_B.denomTol = 2.2204460492503131E-13 * ros_code_xnrm2_o2
    (workingset_nVar, solution_searchDir);
  if (workingset_nWConstr[2] < 44) {
    memcpy(&workspace[0], &workingset_bineq[0], 44U * sizeof(real_T));
    ros_code_xgemv_ju(workingset_nVar, workingset_Aineq, solution_xstar,
                      workspace);
    ros_code_xgemv_ju2(workingset_nVar, workingset_Aineq, solution_searchDir,
                       workspace);
    for (ros_code_B.k_k = 0; ros_code_B.k_k < 44; ros_code_B.k_k++) {
      ros_code_B.phaseOneCorrectionX = workspace[ros_code_B.k_k + 133];
      if ((ros_code_B.phaseOneCorrectionX > ros_code_B.denomTol) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[2] +
            ros_code_B.k_k) - 1])) {
        ros_code_B.alphaTemp = fabs(workspace[ros_code_B.k_k] - *toldelta);
        ros_code_B.u1_h = (1.0E-8 - workspace[ros_code_B.k_k]) + *toldelta;
        if ((ros_code_B.alphaTemp <= ros_code_B.u1_h) || rtIsNaN(ros_code_B.u1_h))
        {
          ros_code_B.u1_h = ros_code_B.alphaTemp;
        }

        ros_code_B.alphaTemp = ros_code_B.u1_h / ros_code_B.phaseOneCorrectionX;
        if ((ros_code_B.alphaTemp <= *alpha) && (fabs
             (ros_code_B.phaseOneCorrectionX) > ros_code_B.p_max)) {
          *alpha = ros_code_B.alphaTemp;
          *constrType = 3;
          *constrIdx = ros_code_B.k_k + 1;
          *newBlocking = true;
        }

        ros_code_B.alphaTemp = fabs(workspace[ros_code_B.k_k]);
        ros_code_B.u1_h = 1.0E-8 - workspace[ros_code_B.k_k];
        if ((ros_code_B.alphaTemp <= ros_code_B.u1_h) || rtIsNaN(ros_code_B.u1_h))
        {
          ros_code_B.u1_h = ros_code_B.alphaTemp;
        }

        ros_code_B.alphaTemp = ros_code_B.u1_h / ros_code_B.phaseOneCorrectionX;
        if (ros_code_B.alphaTemp < *alpha) {
          *alpha = ros_code_B.alphaTemp;
          *constrType = 3;
          *constrIdx = ros_code_B.k_k + 1;
          *newBlocking = true;
          ros_code_B.p_max = fabs(ros_code_B.phaseOneCorrectionX);
        }
      }
    }
  }

  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    ros_code_B.phaseOneCorrectionX = solution_xstar[workingset_nVar - 1] * 0.0;
    ros_code_B.phaseOneCorrectionP = solution_searchDir[workingset_nVar - 1] *
      0.0;
    ros_code_B.k_k = 0;
    while (ros_code_B.k_k <= workingset_sizes[3] - 2) {
      ros_code_B.pk_corrected =
        -solution_searchDir[workingset_indexLB[ros_code_B.k_k] - 1] -
        ros_code_B.phaseOneCorrectionP;
      if ((ros_code_B.pk_corrected > ros_code_B.denomTol) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[3] +
            ros_code_B.k_k) - 1])) {
        ros_code_B.u1_h = -solution_xstar[workingset_indexLB[ros_code_B.k_k] - 1]
          - workingset_lb[workingset_indexLB[ros_code_B.k_k] - 1];
        ros_code_B.ratio = (ros_code_B.u1_h - *toldelta) -
          ros_code_B.phaseOneCorrectionX;
        ros_code_B.alphaTemp = fabs(ros_code_B.ratio);
        if ((!(ros_code_B.alphaTemp <= 1.0E-8 - ros_code_B.ratio)) && (!rtIsNaN
             (1.0E-8 - ros_code_B.ratio))) {
          ros_code_B.alphaTemp = 1.0E-8 - ros_code_B.ratio;
        }

        ros_code_B.alphaTemp /= ros_code_B.pk_corrected;
        if ((ros_code_B.alphaTemp <= *alpha) && (fabs(ros_code_B.pk_corrected) >
             ros_code_B.p_max)) {
          *alpha = ros_code_B.alphaTemp;
          *constrType = 4;
          *constrIdx = ros_code_B.k_k + 1;
          *newBlocking = true;
        }

        ros_code_B.ratio = ros_code_B.u1_h - ros_code_B.phaseOneCorrectionX;
        ros_code_B.alphaTemp = fabs(ros_code_B.ratio);
        if ((!(ros_code_B.alphaTemp <= 1.0E-8 - ros_code_B.ratio)) && (!rtIsNaN
             (1.0E-8 - ros_code_B.ratio))) {
          ros_code_B.alphaTemp = 1.0E-8 - ros_code_B.ratio;
        }

        ros_code_B.alphaTemp /= ros_code_B.pk_corrected;
        if (ros_code_B.alphaTemp < *alpha) {
          *alpha = ros_code_B.alphaTemp;
          *constrType = 4;
          *constrIdx = ros_code_B.k_k + 1;
          *newBlocking = true;
          ros_code_B.p_max = fabs(ros_code_B.pk_corrected);
        }
      }

      ros_code_B.k_k++;
    }

    ros_code_B.k_k = workingset_indexLB[workingset_sizes[3] - 1] - 1;
    ros_code_B.phaseOneCorrectionX = solution_searchDir[ros_code_B.k_k];
    if ((-ros_code_B.phaseOneCorrectionX > ros_code_B.denomTol) &&
        (!workingset_isActiveConstr[(workingset_isActiveIdx[3] +
          workingset_sizes[3]) - 2])) {
      ros_code_B.u1_h = -solution_xstar[ros_code_B.k_k] -
        workingset_lb[ros_code_B.k_k];
      ros_code_B.ratio = ros_code_B.u1_h - *toldelta;
      ros_code_B.alphaTemp = fabs(ros_code_B.ratio);
      if ((!(ros_code_B.alphaTemp <= 1.0E-8 - ros_code_B.ratio)) && (!rtIsNaN
           (1.0E-8 - ros_code_B.ratio))) {
        ros_code_B.alphaTemp = 1.0E-8 - ros_code_B.ratio;
      }

      ros_code_B.alphaTemp /= -ros_code_B.phaseOneCorrectionX;
      if ((ros_code_B.alphaTemp <= *alpha) && (fabs
           (ros_code_B.phaseOneCorrectionX) > ros_code_B.p_max)) {
        *alpha = ros_code_B.alphaTemp;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
      }

      ros_code_B.alphaTemp = fabs(ros_code_B.u1_h);
      if ((!(ros_code_B.alphaTemp <= 1.0E-8 - ros_code_B.u1_h)) && (!rtIsNaN
           (1.0E-8 - ros_code_B.u1_h))) {
        ros_code_B.alphaTemp = 1.0E-8 - ros_code_B.u1_h;
      }

      ros_code_B.alphaTemp /= -ros_code_B.phaseOneCorrectionX;
      if (ros_code_B.alphaTemp < *alpha) {
        *alpha = ros_code_B.alphaTemp;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
        ros_code_B.p_max = fabs(solution_searchDir[ros_code_B.k_k]);
      }
    }
  }

  if (workingset_nWConstr[4] < workingset_sizes[4]) {
    ros_code_B.phaseOneCorrectionX = solution_xstar[workingset_nVar - 1] * 0.0;
    ros_code_B.phaseOneCorrectionP = solution_searchDir[workingset_nVar - 1] *
      0.0;
    ros_code_B.k_k = 0;
    while (ros_code_B.k_k <= workingset_sizes[4] - 1) {
      ros_code_B.pk_corrected =
        solution_searchDir[workingset_indexUB[ros_code_B.k_k] - 1] -
        ros_code_B.phaseOneCorrectionP;
      if ((ros_code_B.pk_corrected > ros_code_B.denomTol) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[4] +
            ros_code_B.k_k) - 1])) {
        ros_code_B.u1_h = solution_xstar[workingset_indexUB[ros_code_B.k_k] - 1]
          - workingset_ub[workingset_indexUB[ros_code_B.k_k] - 1];
        ros_code_B.ratio = (ros_code_B.u1_h - *toldelta) -
          ros_code_B.phaseOneCorrectionX;
        ros_code_B.alphaTemp = fabs(ros_code_B.ratio);
        if ((!(ros_code_B.alphaTemp <= 1.0E-8 - ros_code_B.ratio)) && (!rtIsNaN
             (1.0E-8 - ros_code_B.ratio))) {
          ros_code_B.alphaTemp = 1.0E-8 - ros_code_B.ratio;
        }

        ros_code_B.alphaTemp /= ros_code_B.pk_corrected;
        if ((ros_code_B.alphaTemp <= *alpha) && (fabs(ros_code_B.pk_corrected) >
             ros_code_B.p_max)) {
          *alpha = ros_code_B.alphaTemp;
          *constrType = 5;
          *constrIdx = ros_code_B.k_k + 1;
          *newBlocking = true;
        }

        ros_code_B.ratio = ros_code_B.u1_h - ros_code_B.phaseOneCorrectionX;
        ros_code_B.alphaTemp = fabs(ros_code_B.ratio);
        if ((!(ros_code_B.alphaTemp <= 1.0E-8 - ros_code_B.ratio)) && (!rtIsNaN
             (1.0E-8 - ros_code_B.ratio))) {
          ros_code_B.alphaTemp = 1.0E-8 - ros_code_B.ratio;
        }

        ros_code_B.alphaTemp /= ros_code_B.pk_corrected;
        if (ros_code_B.alphaTemp < *alpha) {
          *alpha = ros_code_B.alphaTemp;
          *constrType = 5;
          *constrIdx = ros_code_B.k_k + 1;
          *newBlocking = true;
          ros_code_B.p_max = fabs(ros_code_B.pk_corrected);
        }
      }

      ros_code_B.k_k++;
    }
  }

  *toldelta += 6.608625846508183E-7;
  if (ros_code_B.p_max > 0.0) {
    ros_code_B.u1_h = 6.608625846508183E-7 / ros_code_B.p_max;
    if (!(*alpha >= ros_code_B.u1_h)) {
      *alpha = ros_code_B.u1_h;
    }
  }

  *newBlocking = (((!*newBlocking) || (!(*alpha > 1.0))) && (*newBlocking));
  if (!(*alpha <= 1.0)) {
    *alpha = 1.0;
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_feasibleratiotest(const real_T solution_xstar[45], const
  real_T solution_searchDir[45], real_T workspace[5985], int32_T workingset_nVar,
  const real_T workingset_Aineq[1980], const real_T workingset_bineq[44], const
  real_T workingset_lb[45], const real_T workingset_ub[45], const int32_T
  workingset_indexLB[45], const int32_T workingset_indexUB[45], const int32_T
  workingset_sizes[5], const int32_T workingset_isActiveIdx[6], const boolean_T
  workingset_isActiveConstr[133], const int32_T workingset_nWConstr[5],
  boolean_T isPhaseOne, real_T *alpha, boolean_T *newBlocking, int32_T
  *constrType, int32_T *constrIdx)
{
  *alpha = 1.0E+30;
  *newBlocking = false;
  *constrType = 0;
  *constrIdx = 0;
  ros_code_B.denomTol_l = 2.2204460492503131E-13 * ros_code_xnrm2_o2
    (workingset_nVar, solution_searchDir);
  if (workingset_nWConstr[2] < 44) {
    memcpy(&workspace[0], &workingset_bineq[0], 44U * sizeof(real_T));
    ros_code_xgemv_ju(workingset_nVar, workingset_Aineq, solution_xstar,
                      workspace);
    ros_code_xgemv_ju2(workingset_nVar, workingset_Aineq, solution_searchDir,
                       workspace);
    for (ros_code_B.k_ft = 0; ros_code_B.k_ft < 44; ros_code_B.k_ft++) {
      ros_code_B.phaseOneCorrectionX_p = workspace[ros_code_B.k_ft + 133];
      if ((ros_code_B.phaseOneCorrectionX_p > ros_code_B.denomTol_l) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[2] +
            ros_code_B.k_ft) - 1])) {
        ros_code_B.alphaTemp_p = fabs(workspace[ros_code_B.k_ft]);
        ros_code_B.phaseOneCorrectionP_f = 1.0E-8 - workspace[ros_code_B.k_ft];
        if ((ros_code_B.alphaTemp_p <= ros_code_B.phaseOneCorrectionP_f) ||
            rtIsNaN(ros_code_B.phaseOneCorrectionP_f)) {
          ros_code_B.phaseOneCorrectionP_f = ros_code_B.alphaTemp_p;
        }

        ros_code_B.alphaTemp_p = ros_code_B.phaseOneCorrectionP_f /
          ros_code_B.phaseOneCorrectionX_p;
        if (ros_code_B.alphaTemp_p < *alpha) {
          *alpha = ros_code_B.alphaTemp_p;
          *constrType = 3;
          *constrIdx = ros_code_B.k_ft + 1;
          *newBlocking = true;
        }
      }
    }
  }

  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    ros_code_B.phaseOneCorrectionX_p = solution_xstar[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    ros_code_B.phaseOneCorrectionP_f = solution_searchDir[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    ros_code_B.k_ft = 0;
    while (ros_code_B.k_ft <= workingset_sizes[3] - 2) {
      ros_code_B.pk_corrected_i =
        -solution_searchDir[workingset_indexLB[ros_code_B.k_ft] - 1] -
        ros_code_B.phaseOneCorrectionP_f;
      if ((ros_code_B.pk_corrected_i > ros_code_B.denomTol_l) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[3] +
            ros_code_B.k_ft) - 1])) {
        ros_code_B.ratio_o = (-solution_xstar[workingset_indexLB[ros_code_B.k_ft]
                              - 1] -
                              workingset_lb[workingset_indexLB[ros_code_B.k_ft]
                              - 1]) - ros_code_B.phaseOneCorrectionX_p;
        ros_code_B.alphaTemp_p = fabs(ros_code_B.ratio_o);
        if ((!(ros_code_B.alphaTemp_p <= 1.0E-8 - ros_code_B.ratio_o)) &&
            (!rtIsNaN(1.0E-8 - ros_code_B.ratio_o))) {
          ros_code_B.alphaTemp_p = 1.0E-8 - ros_code_B.ratio_o;
        }

        ros_code_B.alphaTemp_p /= ros_code_B.pk_corrected_i;
        if (ros_code_B.alphaTemp_p < *alpha) {
          *alpha = ros_code_B.alphaTemp_p;
          *constrType = 4;
          *constrIdx = ros_code_B.k_ft + 1;
          *newBlocking = true;
        }
      }

      ros_code_B.k_ft++;
    }

    ros_code_B.k_ft = workingset_indexLB[workingset_sizes[3] - 1] - 1;
    ros_code_B.phaseOneCorrectionX_p = -solution_searchDir[ros_code_B.k_ft];
    if ((ros_code_B.phaseOneCorrectionX_p > ros_code_B.denomTol_l) &&
        (!workingset_isActiveConstr[(workingset_isActiveIdx[3] +
          workingset_sizes[3]) - 2])) {
      ros_code_B.ratio_o = -solution_xstar[ros_code_B.k_ft] -
        workingset_lb[ros_code_B.k_ft];
      ros_code_B.alphaTemp_p = fabs(ros_code_B.ratio_o);
      if ((!(ros_code_B.alphaTemp_p <= 1.0E-8 - ros_code_B.ratio_o)) &&
          (!rtIsNaN(1.0E-8 - ros_code_B.ratio_o))) {
        ros_code_B.alphaTemp_p = 1.0E-8 - ros_code_B.ratio_o;
      }

      ros_code_B.alphaTemp_p /= ros_code_B.phaseOneCorrectionX_p;
      if (ros_code_B.alphaTemp_p < *alpha) {
        *alpha = ros_code_B.alphaTemp_p;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
      }
    }
  }

  if (workingset_nWConstr[4] < workingset_sizes[4]) {
    ros_code_B.phaseOneCorrectionX_p = solution_xstar[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    ros_code_B.phaseOneCorrectionP_f = solution_searchDir[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    ros_code_B.k_ft = 0;
    while (ros_code_B.k_ft <= workingset_sizes[4] - 1) {
      ros_code_B.pk_corrected_i =
        solution_searchDir[workingset_indexUB[ros_code_B.k_ft] - 1] -
        ros_code_B.phaseOneCorrectionP_f;
      if ((ros_code_B.pk_corrected_i > ros_code_B.denomTol_l) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[4] +
            ros_code_B.k_ft) - 1])) {
        ros_code_B.ratio_o = (solution_xstar[workingset_indexUB[ros_code_B.k_ft]
                              - 1] -
                              workingset_ub[workingset_indexUB[ros_code_B.k_ft]
                              - 1]) - ros_code_B.phaseOneCorrectionX_p;
        ros_code_B.alphaTemp_p = fabs(ros_code_B.ratio_o);
        if ((!(ros_code_B.alphaTemp_p <= 1.0E-8 - ros_code_B.ratio_o)) &&
            (!rtIsNaN(1.0E-8 - ros_code_B.ratio_o))) {
          ros_code_B.alphaTemp_p = 1.0E-8 - ros_code_B.ratio_o;
        }

        ros_code_B.alphaTemp_p /= ros_code_B.pk_corrected_i;
        if (ros_code_B.alphaTemp_p < *alpha) {
          *alpha = ros_code_B.alphaTemp_p;
          *constrType = 5;
          *constrIdx = ros_code_B.k_ft + 1;
          *newBlocking = true;
        }
      }

      ros_code_B.k_ft++;
    }
  }

  if (!isPhaseOne) {
    *newBlocking = (((!*newBlocking) || (!(*alpha > 1.0))) && (*newBlocking));
    if (!(*alpha <= 1.0)) {
      *alpha = 1.0;
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros__addBoundToActiveSetMatrix_(snBUc3P0iDgb4fuyQLszkYC_ros_c_T *obj,
  int32_T TYPE, int32_T idx_local)
{
  int32_T colOffset;
  int32_T idx_bnd_local;
  obj->nWConstr[TYPE - 1]++;
  obj->isActiveConstr[(obj->isActiveIdx[TYPE - 1] + idx_local) - 2] = true;
  obj->nActiveConstr++;
  obj->Wid[obj->nActiveConstr - 1] = TYPE;
  obj->Wlocalidx[obj->nActiveConstr - 1] = idx_local;
  colOffset = (obj->nActiveConstr - 1) * 45 - 1;
  if (TYPE == 5) {
    idx_bnd_local = obj->indexUB[idx_local - 1];
    obj->bwset[obj->nActiveConstr - 1] = obj->ub[idx_bnd_local - 1];
  } else {
    idx_bnd_local = obj->indexLB[idx_local - 1];
    obj->bwset[obj->nActiveConstr - 1] = obj->lb[idx_bnd_local - 1];
  }

  for (int32_T idx = 0; idx <= idx_bnd_local - 2; idx++) {
    obj->ATwset[(idx + colOffset) + 1] = 0.0;
  }

  obj->ATwset[idx_bnd_local + colOffset] = static_cast<real_T>(TYPE == 5) * 2.0
    - 1.0;
  for (idx_bnd_local++; idx_bnd_local <= obj->nVar; idx_bnd_local++) {
    obj->ATwset[idx_bnd_local + colOffset] = 0.0;
  }

  switch (obj->probType) {
   case 3:
   case 2:
    break;

   default:
    obj->ATwset[obj->nVar + colOffset] = -1.0;
    break;
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_compute_lambda(real_T workspace[5985],
  sEf9458k7RTCGn6XpAY3FSD_ros_c_T *solution, const
  scRVBsoAowahmPoAIYa5ea_ros_co_T *objective, const
  siBmBjpOUwoybpuj9rEfGvD_ros_c_T *qrmanager)
{
  if (qrmanager->ncols > 0) {
    int32_T c_idx;
    int32_T idxQR;
    boolean_T guard1 = false;
    guard1 = false;
    if (objective->objtype != 4) {
      boolean_T nonDegenerate;
      ros_code_B.c_mv = 100.0 * static_cast<real_T>(qrmanager->mrows) *
        2.2204460492503131E-16;
      nonDegenerate = ((qrmanager->mrows > 0) && (qrmanager->ncols > 0));
      if (nonDegenerate) {
        boolean_T guard2 = false;
        c_idx = qrmanager->ncols;
        guard2 = false;
        if (qrmanager->mrows < qrmanager->ncols) {
          idxQR = (qrmanager->ncols - 1) * 45 + qrmanager->mrows;
          while ((c_idx > qrmanager->mrows) && (fabs(qrmanager->QR[idxQR - 1]) >=
                  ros_code_B.c_mv)) {
            c_idx--;
            idxQR -= 45;
          }

          nonDegenerate = (c_idx == qrmanager->mrows);
          if (!nonDegenerate) {
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2) {
          idxQR = (c_idx - 1) * 45 + c_idx;
          while ((c_idx >= 1) && (fabs(qrmanager->QR[idxQR - 1]) >=
                                  ros_code_B.c_mv)) {
            c_idx--;
            idxQR -= 46;
          }

          nonDegenerate = (c_idx == 0);
        }
      }

      if (!nonDegenerate) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (qrmanager->mrows != 0) {
        for (c_idx = 0; c_idx < qrmanager->ncols; c_idx++) {
          workspace[c_idx] = 0.0;
        }

        c_idx = 0;
        idxQR = (qrmanager->ncols - 1) * 45 + 1;
        ros_code_B.iac_a = 1;
        while (ros_code_B.iac_a <= idxQR) {
          ros_code_B.ix_c = 0;
          ros_code_B.c_mv = 0.0;
          ros_code_B.d_l = (ros_code_B.iac_a + qrmanager->mrows) - 1;
          for (int32_T ia = ros_code_B.iac_a; ia <= ros_code_B.d_l; ia++) {
            ros_code_B.c_mv += qrmanager->Q[ia - 1] * objective->
              grad[ros_code_B.ix_c];
            ros_code_B.ix_c++;
          }

          workspace[c_idx] += ros_code_B.c_mv;
          c_idx++;
          ros_code_B.iac_a += 45;
        }
      }

      for (c_idx = qrmanager->ncols - 1; c_idx + 1 > 0; c_idx--) {
        idxQR = c_idx * 45 + c_idx;
        workspace[c_idx] /= qrmanager->QR[idxQR];
        ros_code_B.iac_a = 1;
        while (ros_code_B.iac_a - 1 <= c_idx - 1) {
          ros_code_B.ix_c = c_idx - ros_code_B.iac_a;
          workspace[ros_code_B.ix_c] -= qrmanager->QR[idxQR - ros_code_B.iac_a] *
            workspace[c_idx];
          ros_code_B.iac_a++;
        }
      }

      for (c_idx = 0; c_idx < qrmanager->ncols; c_idx++) {
        solution->lambda[c_idx] = -workspace[c_idx];
      }
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros__checkStoppingAndUpdateFval(int32_T *activeSetChangeID, const
  real_T f[44], sEf9458k7RTCGn6XpAY3FSD_ros_c_T *solution,
  sg8qKdtlZ7nXgcAC5MP2QHC_ros_c_T *memspace, const
  scRVBsoAowahmPoAIYa5ea_ros_co_T *objective, snBUc3P0iDgb4fuyQLszkYC_ros_c_T
  *workingset, siBmBjpOUwoybpuj9rEfGvD_ros_c_T *qrmanager, real_T
  options_ObjectiveLimit, int32_T runTimeOptions_MaxIterations, real_T
  runTimeOptions_ConstrRelTolFact, boolean_T updateFval)
{
  solution->iterations++;
  ros_code_B.nVar_tmp_tmp = objective->nvar - 1;
  if ((solution->iterations >= runTimeOptions_MaxIterations) &&
      ((solution->state != 1) || (objective->objtype == 5))) {
    solution->state = 0;
  }

  if (solution->iterations - solution->iterations / 50 * 50 == 0) {
    solution->maxConstr = ros_c_maxConstraintViolation_c3(workingset,
      solution->xstar);
    ros_code_B.tempMaxConstr = solution->maxConstr;
    if (objective->objtype == 5) {
      ros_code_B.tempMaxConstr = solution->maxConstr - solution->xstar
        [objective->nvar - 1];
    }

    if (ros_code_B.tempMaxConstr > 1.0E-8 * runTimeOptions_ConstrRelTolFact) {
      boolean_T nonDegenerateWset;
      ros_code_B.b_k_h = 0;
      while (ros_code_B.b_k_h <= ros_code_B.nVar_tmp_tmp) {
        solution->searchDir[ros_code_B.b_k_h] = solution->xstar[ros_code_B.b_k_h];
        ros_code_B.b_k_h++;
      }

      nonDegenerateWset = ros_cod_feasibleX0ForWorkingSet
        (memspace->workspace_double, solution->searchDir, workingset, qrmanager);
      if ((!nonDegenerateWset) && (solution->state != 0)) {
        solution->state = -2;
      }

      *activeSetChangeID = 0;
      ros_code_B.tempMaxConstr = ros_c_maxConstraintViolation_c3(workingset,
        solution->searchDir);
      if (ros_code_B.tempMaxConstr < solution->maxConstr) {
        ros_code_B.b_k_h = 0;
        while (ros_code_B.b_k_h <= ros_code_B.nVar_tmp_tmp) {
          solution->xstar[ros_code_B.b_k_h] = solution->
            searchDir[ros_code_B.b_k_h];
          ros_code_B.b_k_h++;
        }

        solution->maxConstr = ros_code_B.tempMaxConstr;
      }
    }
  }

  if (updateFval && (options_ObjectiveLimit > (rtMinusInf))) {
    solution->fstar = ros_code_computeFval_ReuseHx(objective,
      memspace->workspace_double, f, solution->xstar);
    if ((solution->fstar < options_ObjectiveLimit) && ((solution->state != 0) ||
         (objective->objtype != 5))) {
      solution->state = 2;
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_iterate(const real_T H[1936], const real_T f[44],
  sEf9458k7RTCGn6XpAY3FSD_ros_c_T *solution, sg8qKdtlZ7nXgcAC5MP2QHC_ros_c_T
  *memspace, snBUc3P0iDgb4fuyQLszkYC_ros_c_T *workingset,
  siBmBjpOUwoybpuj9rEfGvD_ros_c_T *qrmanager, svUSr4TrK4x4Kz9rQJTxkkF_ros_c_T
  *cholmanager, scRVBsoAowahmPoAIYa5ea_ros_co_T *objective, real_T
  options_ObjectiveLimit, real_T options_StepTolerance, int32_T
  runTimeOptions_MaxIterations, real_T runTimeOptions_ConstrRelTolFact, real_T
  runTimeOptions_ProbRelTolFactor, boolean_T runTimeOptions_RemainFeasible)
{
  boolean_T newBlocking;
  boolean_T subProblemChanged;
  boolean_T updateFval;
  subProblemChanged = true;
  updateFval = true;
  ros_code_B.activeSetChangeID = 0;
  ros_code_B.TYPE = objective->objtype;
  ros_code_B.tolDelta = 6.7434957617430445E-7;
  ros_code_B.nVar_p = workingset->nVar;
  ros_code_B.globalActiveConstrIdx = 0;
  ros_code_computeGrad_StoreHx(objective, H, f, solution->xstar);
  solution->fstar = ros_code_computeFval_ReuseHx(objective,
    memspace->workspace_double, f, solution->xstar);
  if (solution->iterations < runTimeOptions_MaxIterations) {
    solution->state = -5;
  } else {
    solution->state = 0;
  }

  memset(&solution->lambda[0], 0, 133U * sizeof(real_T));
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (solution->state == -5) {
      boolean_T guard1 = false;
      guard1 = false;
      if (subProblemChanged) {
        switch (ros_code_B.activeSetChangeID) {
         case 1:
          ros_code_B.idx_d = (workingset->nActiveConstr - 1) * 45;
          if (qrmanager->mrows <= qrmanager->ncols + 1) {
            qrmanager->minRowCol = qrmanager->mrows;
          } else {
            qrmanager->minRowCol = qrmanager->ncols + 1;
          }

          ros_code_B.b_iy_j = 45 * qrmanager->ncols;
          if (qrmanager->mrows != 0) {
            ros_code_B.iyend = ros_code_B.b_iy_j + qrmanager->mrows;
            ros_code_B.c_iy = ros_code_B.b_iy_j;
            while (ros_code_B.c_iy + 1 <= ros_code_B.iyend) {
              qrmanager->QR[ros_code_B.c_iy] = 0.0;
              ros_code_B.c_iy++;
            }

            ros_code_B.iyend = (qrmanager->mrows - 1) * 45 + 1;
            ros_code_B.c_iy = 1;
            while (ros_code_B.c_iy <= ros_code_B.iyend) {
              ros_code_B.b_ix_o = ros_code_B.idx_d;
              ros_code_B.normDelta = 0.0;
              ros_code_B.e_c = (ros_code_B.c_iy + qrmanager->mrows) - 1;
              ros_code_B.ia = ros_code_B.c_iy;
              while (ros_code_B.ia <= ros_code_B.e_c) {
                ros_code_B.normDelta += qrmanager->Q[ros_code_B.ia - 1] *
                  workingset->ATwset[ros_code_B.b_ix_o];
                ros_code_B.b_ix_o++;
                ros_code_B.ia++;
              }

              qrmanager->QR[ros_code_B.b_iy_j] += ros_code_B.normDelta;
              ros_code_B.b_iy_j++;
              ros_code_B.c_iy += 45;
            }
          }

          qrmanager->ncols++;
          qrmanager->jpvt[qrmanager->ncols - 1] = qrmanager->ncols;
          ros_code_B.idx_d = qrmanager->mrows - 2;
          while (ros_code_B.idx_d + 2 > qrmanager->ncols) {
            ros_code_B.b_iy_j = (qrmanager->ncols - 1) * 45;
            ros_code_B.iyend = (ros_code_B.idx_d + ros_code_B.b_iy_j) + 1;
            ros_code_B.temp = qrmanager->QR[ros_code_B.iyend];
            ros_code_xrotg(&qrmanager->QR[ros_code_B.idx_d + ros_code_B.b_iy_j],
                           &ros_code_B.temp, &ros_code_B.normDelta,
                           &ros_code_B.s_fm);
            qrmanager->QR[ros_code_B.iyend] = ros_code_B.temp;
            ros_code_B.b_iy_j = 45 * ros_code_B.idx_d;
            if (qrmanager->mrows >= 1) {
              ros_code_B.iyend = ros_code_B.b_iy_j + 45;
              ros_code_B.c_iy = 0;
              while (ros_code_B.c_iy <= qrmanager->mrows - 1) {
                ros_code_B.temp = ros_code_B.normDelta * qrmanager->
                  Q[ros_code_B.b_iy_j] + ros_code_B.s_fm * qrmanager->
                  Q[ros_code_B.iyend];
                qrmanager->Q[ros_code_B.iyend] = ros_code_B.normDelta *
                  qrmanager->Q[ros_code_B.iyend] - ros_code_B.s_fm *
                  qrmanager->Q[ros_code_B.b_iy_j];
                qrmanager->Q[ros_code_B.b_iy_j] = ros_code_B.temp;
                ros_code_B.iyend++;
                ros_code_B.b_iy_j++;
                ros_code_B.c_iy++;
              }
            }

            ros_code_B.idx_d--;
          }
          break;

         case -1:
          ros_code_deleteColMoveEnd(qrmanager, ros_code_B.globalActiveConstrIdx);
          break;

         default:
          ros_code_factorQR(qrmanager, workingset->ATwset, ros_code_B.nVar_p,
                            workingset->nActiveConstr);
          ros_code_computeQ_(qrmanager, qrmanager->mrows);
          break;
        }

        ros_code_compute_deltax(H, solution, memspace, qrmanager, cholmanager,
          objective);
        if (solution->state != -5) {
          exitg1 = 1;
        } else {
          ros_code_B.normDelta = ros_code_xnrm2_o2(ros_code_B.nVar_p,
            solution->searchDir);
          guard1 = true;
        }
      } else {
        ros_code_B.idx_d = 0;
        while (ros_code_B.idx_d <= ros_code_B.nVar_p - 1) {
          solution->searchDir[ros_code_B.idx_d] = 0.0;
          ros_code_B.idx_d++;
        }

        ros_code_B.normDelta = 0.0;
        guard1 = true;
      }

      if (guard1) {
        if ((!subProblemChanged) || (ros_code_B.normDelta <
             options_StepTolerance) || (workingset->nActiveConstr >=
             ros_code_B.nVar_p)) {
          ros_code_compute_lambda(memspace->workspace_double, solution,
            objective, qrmanager);
          if ((solution->state != -7) || (workingset->nActiveConstr >
               ros_code_B.nVar_p)) {
            ros_code_B.idx_d = 0;
            ros_code_B.normDelta = 0.0 * runTimeOptions_ProbRelTolFactor *
              static_cast<real_T>(ros_code_B.TYPE != 5);
            ros_code_B.b_iy_j = workingset->nWConstr[0] + workingset->nWConstr[1];
            while (ros_code_B.b_iy_j + 1 <= workingset->nActiveConstr) {
              if (solution->lambda[ros_code_B.b_iy_j] < ros_code_B.normDelta) {
                ros_code_B.normDelta = solution->lambda[ros_code_B.b_iy_j];
                ros_code_B.idx_d = ros_code_B.b_iy_j + 1;
              }

              ros_code_B.b_iy_j++;
            }

            if (ros_code_B.idx_d == 0) {
              solution->state = 1;
            } else {
              ros_code_B.activeSetChangeID = -1;
              ros_code_B.globalActiveConstrIdx = ros_code_B.idx_d;
              subProblemChanged = true;
              ros_code_removeConstr(workingset, ros_code_B.idx_d);
              solution->lambda[ros_code_B.idx_d - 1] = 0.0;
            }
          } else {
            ros_code_B.idx_d = workingset->nActiveConstr;
            ros_code_B.activeSetChangeID = 0;
            ros_code_B.globalActiveConstrIdx = workingset->nActiveConstr;
            subProblemChanged = true;
            ros_code_removeConstr(workingset, workingset->nActiveConstr);
            solution->lambda[ros_code_B.idx_d - 1] = 0.0;
          }

          updateFval = false;
        } else {
          updateFval = (ros_code_B.TYPE == 5);
          if (updateFval || runTimeOptions_RemainFeasible) {
            ros_code_feasibleratiotest(solution->xstar, solution->searchDir,
              memspace->workspace_double, workingset->nVar, workingset->Aineq,
              workingset->bineq, workingset->lb, workingset->ub,
              workingset->indexLB, workingset->indexUB, workingset->sizes,
              workingset->isActiveIdx, workingset->isActiveConstr,
              workingset->nWConstr, updateFval, &ros_code_B.normDelta,
              &newBlocking, &ros_code_B.b_iy_j, &ros_code_B.idx_d);
          } else {
            ros_code_ratiotest(solution->xstar, solution->searchDir,
                               memspace->workspace_double, workingset->nVar,
                               workingset->Aineq, workingset->bineq,
                               workingset->lb, workingset->ub,
                               workingset->indexLB, workingset->indexUB,
                               workingset->sizes, workingset->isActiveIdx,
                               workingset->isActiveConstr, workingset->nWConstr,
                               &ros_code_B.tolDelta, &ros_code_B.normDelta,
                               &newBlocking, &ros_code_B.b_iy_j,
                               &ros_code_B.idx_d);
          }

          if (newBlocking) {
            switch (ros_code_B.b_iy_j) {
             case 3:
              workingset->nWConstr[2]++;
              workingset->isActiveConstr[(workingset->isActiveIdx[2] +
                ros_code_B.idx_d) - 2] = true;
              workingset->nActiveConstr++;
              workingset->Wid[workingset->nActiveConstr - 1] = 3;
              workingset->Wlocalidx[workingset->nActiveConstr - 1] =
                ros_code_B.idx_d;
              ros_code_B.activeSetChangeID = (ros_code_B.idx_d - 1) * 45;
              ros_code_B.b_iy_j = (workingset->nActiveConstr - 1) * 45;
              ros_code_B.iyend = 0;
              while (ros_code_B.iyend <= workingset->nVar - 1) {
                workingset->ATwset[ros_code_B.b_iy_j + ros_code_B.iyend] =
                  workingset->Aineq[ros_code_B.activeSetChangeID +
                  ros_code_B.iyend];
                ros_code_B.iyend++;
              }

              workingset->bwset[workingset->nActiveConstr - 1] =
                workingset->bineq[ros_code_B.idx_d - 1];
              break;

             case 4:
              ros__addBoundToActiveSetMatrix_(workingset, 4, ros_code_B.idx_d);
              break;

             default:
              ros__addBoundToActiveSetMatrix_(workingset, 5, ros_code_B.idx_d);
              break;
            }

            ros_code_B.activeSetChangeID = 1;
          } else {
            if (objective->objtype == 5) {
              if (ros_code_xnrm2_o2(objective->nvar, solution->searchDir) >
                  100.0 * static_cast<real_T>(objective->nvar) *
                  1.4901161193847656E-8) {
                solution->state = 3;
              } else {
                solution->state = 4;
              }
            }

            subProblemChanged = false;
            if (workingset->nActiveConstr == 0) {
              solution->state = 1;
            }
          }

          if (!(ros_code_B.normDelta == 0.0)) {
            ros_code_B.idx_d = 0;
            while (ros_code_B.idx_d <= ros_code_B.nVar_p - 1) {
              solution->xstar[ros_code_B.idx_d] += ros_code_B.normDelta *
                solution->searchDir[ros_code_B.idx_d];
              ros_code_B.idx_d++;
            }
          }

          ros_code_computeGrad_StoreHx(objective, H, f, solution->xstar);
          updateFval = true;
        }

        ros__checkStoppingAndUpdateFval(&ros_code_B.activeSetChangeID, f,
          solution, memspace, objective, workingset, qrmanager,
          options_ObjectiveLimit, runTimeOptions_MaxIterations,
          runTimeOptions_ConstrRelTolFact, updateFval);
      }
    } else {
      if (!updateFval) {
        solution->fstar = ros_code_computeFval_ReuseHx(objective,
          memspace->workspace_double, f, solution->xstar);
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_phaseone(const real_T H[1936], const real_T f[44],
  sEf9458k7RTCGn6XpAY3FSD_ros_c_T *solution, sg8qKdtlZ7nXgcAC5MP2QHC_ros_c_T
  *memspace, snBUc3P0iDgb4fuyQLszkYC_ros_c_T *workingset,
  siBmBjpOUwoybpuj9rEfGvD_ros_c_T *qrmanager, svUSr4TrK4x4Kz9rQJTxkkF_ros_c_T
  *cholmanager, const sL9bDKomAYkxZSVrG9w6En_ros_co_T *runTimeOptions,
  scRVBsoAowahmPoAIYa5ea_ros_co_T *objective, sSOeZ9WO10chPn9Si6PKiCB_ros_c_T
  *options)
{
  static const char_T b_FiniteDifferenceType[7] = { 'f', 'o', 'r', 'w', 'a', 'r',
    'd' };

  static const char_T b_Algorithm[10] = { 'a', 'c', 't', 'i', 'v', 'e', '-', 's',
    'e', 't' };

  static const char_T b_SolverName[8] = { 'q', 'u', 'a', 'd', 'p', 'r', 'o', 'g'
  };

  static const char_T b_Display[5] = { 'f', 'i', 'n', 'a', 'l' };

  options->InitDamping = 0.01;
  for (ros_code_B.i_l = 0; ros_code_B.i_l < 7; ros_code_B.i_l++) {
    options->FiniteDifferenceType[ros_code_B.i_l] =
      b_FiniteDifferenceType[ros_code_B.i_l];
  }

  options->SpecifyObjectiveGradient = false;
  options->ScaleProblem = false;
  options->SpecifyConstraintGradient = false;
  options->NonFiniteSupport = true;
  options->IterDisplaySQP = false;
  options->FiniteDifferenceStepSize = -1.0;
  options->MaxFunctionEvaluations = -1.0;
  options->IterDisplayQP = false;
  options->PricingTolerance = 0.0;
  for (ros_code_B.i_l = 0; ros_code_B.i_l < 10; ros_code_B.i_l++) {
    options->Algorithm[ros_code_B.i_l] = b_Algorithm[ros_code_B.i_l];
  }

  options->ConstraintTolerance = 1.0E-8;
  options->OptimalityTolerance = 1.0E-8;
  options->MaxIterations = -1.0;
  options->FunctionTolerance = (rtInf);
  for (ros_code_B.i_l = 0; ros_code_B.i_l < 8; ros_code_B.i_l++) {
    options->SolverName[ros_code_B.i_l] = b_SolverName[ros_code_B.i_l];
  }

  options->CheckGradients = false;
  options->Diagnostics[0] = 'o';
  options->Diagnostics[1] = 'f';
  options->Diagnostics[2] = 'f';
  options->DiffMaxChange = (rtInf);
  options->DiffMinChange = 0.0;
  for (ros_code_B.i_l = 0; ros_code_B.i_l < 5; ros_code_B.i_l++) {
    options->Display[ros_code_B.i_l] = b_Display[ros_code_B.i_l];
  }

  options->FunValCheck[0] = 'o';
  options->FunValCheck[1] = 'f';
  options->FunValCheck[2] = 'f';
  options->UseParallel = false;
  options->LinearSolver[0] = 'a';
  options->LinearSolver[1] = 'u';
  options->LinearSolver[2] = 't';
  options->LinearSolver[3] = 'o';
  options->SubproblemAlgorithm[0] = 'c';
  options->SubproblemAlgorithm[1] = 'g';
  ros_code_B.nVar_o = workingset->nVar;
  solution->xstar[44] = solution->maxConstr + 1.0;
  ros_code_setProblemType(workingset, 1);
  ros_code_removeAllIneqConstr(workingset);
  memset(&objective->grad[0], 0, 45U * sizeof(real_T));
  memset(&objective->Hx[0], 0, 44U * sizeof(real_T));
  objective->maxVar = 45;
  objective->beta = 0.0;
  objective->rho = 0.0;
  objective->prev_objtype = 3;
  objective->prev_nvar = 44;
  objective->prev_hasLinear = true;
  objective->objtype = 5;
  objective->nvar = 45;
  objective->gammaScalar = 1.0;
  objective->hasLinear = true;
  options->ObjectiveLimit = 1.0E-8 * runTimeOptions->ConstrRelTolFactor;
  solution->fstar = ros_code_computeFval(objective, memspace->workspace_double,
    H, f, solution->xstar);
  solution->state = 5;
  ros_code_iterate(H, f, solution, memspace, workingset, qrmanager, cholmanager,
                   objective, options->ObjectiveLimit, 1.4901161193847657E-10,
                   runTimeOptions->MaxIterations,
                   runTimeOptions->ConstrRelTolFactor,
                   runTimeOptions->ProbRelTolFactor,
                   runTimeOptions->RemainFeasible);
  if (workingset->isActiveConstr[(workingset->isActiveIdx[3] + workingset->
       sizes[3]) - 2]) {
    boolean_T exitg1;
    ros_code_B.i_l = workingset->sizes[0];
    exitg1 = false;
    while ((!exitg1) && (ros_code_B.i_l + 1 <= workingset->nActiveConstr)) {
      if ((workingset->Wid[ros_code_B.i_l] == 4) && (workingset->
           Wlocalidx[ros_code_B.i_l] == workingset->sizes[3])) {
        ros_code_removeConstr(workingset, ros_code_B.i_l + 1);
        exitg1 = true;
      } else {
        ros_code_B.i_l++;
      }
    }
  }

  ros_code_B.i_l = workingset->nActiveConstr;
  while ((ros_code_B.i_l > workingset->sizes[0]) && (ros_code_B.i_l >
          ros_code_B.nVar_o)) {
    ros_code_removeConstr(workingset, ros_code_B.i_l);
    ros_code_B.i_l--;
  }

  solution->maxConstr = solution->xstar[44];
  ros_code_setProblemType(workingset, 3);
  objective->objtype = objective->prev_objtype;
  objective->nvar = objective->prev_nvar;
  objective->hasLinear = objective->prev_hasLinear;
  options->ObjectiveLimit = -1.0E+20;
  options->StepTolerance = 1.0E-8;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static int32_T ros_code_RemoveDependentEq__p(sg8qKdtlZ7nXgcAC5MP2QHC_ros_c_T
  *memspace, snBUc3P0iDgb4fuyQLszkYC_ros_c_T *workingset,
  siBmBjpOUwoybpuj9rEfGvD_ros_c_T *qrmanager)
{
  int32_T nDepInd;
  ros_code_B.nVar = workingset->nVar - 1;
  ros_code_B.mTotalWorkingEq = workingset->nWConstr[0] + workingset->nWConstr[1];
  nDepInd = 0;
  if (ros_code_B.mTotalWorkingEq > 0) {
    ros_code_B.totalRank = 0;
    while (ros_code_B.totalRank <= ros_code_B.mTotalWorkingEq - 1) {
      ros_code_B.ix = 0;
      while (ros_code_B.ix <= ros_code_B.nVar) {
        qrmanager->QR[ros_code_B.totalRank + 45 * ros_code_B.ix] =
          workingset->ATwset[45 * ros_code_B.totalRank + ros_code_B.ix];
        ros_code_B.ix++;
      }

      ros_code_B.totalRank++;
    }

    nDepInd = ros_code_B.mTotalWorkingEq - workingset->nVar;
    if (nDepInd <= 0) {
      nDepInd = 0;
    }

    ros_code_B.totalRank = 0;
    while (ros_code_B.totalRank <= ros_code_B.nVar) {
      qrmanager->jpvt[ros_code_B.totalRank] = 0;
      ros_code_B.totalRank++;
    }

    ros_code_factorQRE(qrmanager, ros_code_B.mTotalWorkingEq, workingset->nVar);
    ros_code_B.tol = 100.0 * static_cast<real_T>(workingset->nVar) *
      2.2204460492503131E-16;
    if (workingset->nVar <= ros_code_B.mTotalWorkingEq) {
      ros_code_B.totalRank = workingset->nVar;
    } else {
      ros_code_B.totalRank = ros_code_B.mTotalWorkingEq;
    }

    ros_code_B.totalRank += (ros_code_B.totalRank - 1) * 45;
    while ((ros_code_B.totalRank > 0) && (fabs(qrmanager->
             QR[ros_code_B.totalRank - 1]) < ros_code_B.tol)) {
      ros_code_B.totalRank -= 46;
      nDepInd++;
    }

    if (nDepInd > 0) {
      boolean_T exitg1;
      ros_code_computeQ_(qrmanager, qrmanager->mrows);
      ros_code_B.totalRank = 0;
      exitg1 = false;
      while ((!exitg1) && (ros_code_B.totalRank <= nDepInd - 1)) {
        ros_code_B.ix = ((ros_code_B.mTotalWorkingEq - ros_code_B.totalRank) - 1)
          * 45;
        ros_code_B.qtb = 0.0;
        ros_code_B.iy = 0;
        ros_code_B.b_k = 0;
        while (ros_code_B.b_k <= ros_code_B.mTotalWorkingEq - 1) {
          ros_code_B.qtb += qrmanager->Q[ros_code_B.ix] * workingset->
            bwset[ros_code_B.iy];
          ros_code_B.ix++;
          ros_code_B.iy++;
          ros_code_B.b_k++;
        }

        if (fabs(ros_code_B.qtb) >= ros_code_B.tol) {
          nDepInd = -1;
          exitg1 = true;
        } else {
          ros_code_B.totalRank++;
        }
      }
    }

    if (nDepInd > 0) {
      ros_code_B.totalRank = 0;
      while (ros_code_B.totalRank <= ros_code_B.mTotalWorkingEq - 1) {
        ros_code_B.ix = 45 * ros_code_B.totalRank;
        ros_code_B.iy = 1;
        while (ros_code_B.iy - 1 <= ros_code_B.nVar) {
          ros_code_B.b_k = (ros_code_B.ix + ros_code_B.iy) - 1;
          qrmanager->QR[ros_code_B.b_k] = workingset->ATwset[ros_code_B.b_k];
          ros_code_B.iy++;
        }

        ros_code_B.totalRank++;
      }

      ros_code_IndexOfDependentEq_(memspace->workspace_int, workingset->
        nWConstr[0], nDepInd, qrmanager, workingset->nVar,
        ros_code_B.mTotalWorkingEq);
      ros_code_countsort(memspace->workspace_int, nDepInd,
                         memspace->workspace_sort, 1, ros_code_B.mTotalWorkingEq);
      ros_code_B.nVar = nDepInd;
      while (ros_code_B.nVar > 0) {
        ros_code_removeEqConstr(workingset, memspace->
          workspace_int[ros_code_B.nVar - 1]);
        ros_code_B.nVar--;
      }
    }
  }

  return nDepInd;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_PresolveWorkingSet_a(sEf9458k7RTCGn6XpAY3FSD_ros_c_T
  *solution, sg8qKdtlZ7nXgcAC5MP2QHC_ros_c_T *memspace,
  snBUc3P0iDgb4fuyQLszkYC_ros_c_T *workingset, siBmBjpOUwoybpuj9rEfGvD_ros_c_T
  *qrmanager)
{
  solution->state = 82;
  ros_code_B.b_m = ros_code_RemoveDependentEq__p(memspace, workingset, qrmanager);
  if ((ros_code_B.b_m != -1) && (workingset->nActiveConstr <= 45)) {
    boolean_T guard1 = false;
    boolean_T okWorkingSet;
    ros_code_RemoveDependentIneq_(workingset, qrmanager, memspace, 100.0);
    okWorkingSet = ros_cod_feasibleX0ForWorkingSet(memspace->workspace_double,
      solution->xstar, workingset, qrmanager);
    guard1 = false;
    if (!okWorkingSet) {
      ros_code_RemoveDependentIneq_(workingset, qrmanager, memspace, 1000.0);
      okWorkingSet = ros_cod_feasibleX0ForWorkingSet(memspace->workspace_double,
        solution->xstar, workingset, qrmanager);
      if (!okWorkingSet) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (workingset->nWConstr[0] + workingset->nWConstr[1] == workingset->nVar)
      {
        ros_code_B.constrViolation = ros_c_maxConstraintViolation_c3(workingset,
          solution->xstar);
        if (ros_code_B.constrViolation > 1.0E-8) {
          solution->state = -2;
        }
      }
    }
  } else {
    solution->state = -3;
    ros_code_removeAllIneqConstr(workingset);
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static boolean_T ros_code_strcmp(const char_T a[8])
{
  int32_T kstr;
  boolean_T b_bool;
  static const char_T b[128] = { '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
    '\x06', '\x07', '\x08', '\x09', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e',
    '\x0f', '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17',
    '\x18', '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!',
    '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?',
    '@', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '[', '\\', ']',
    '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{',
    '|', '}', '~', '\x7f' };

  static const char_T c[8] = { 'q', 'u', 'a', 'd', 'p', 'r', 'o', 'g' };

  b_bool = false;
  kstr = 0;
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (kstr < 8) {
      if (b[static_cast<int32_T>(a[kstr])] != b[static_cast<int32_T>(c[kstr])])
      {
        exitg1 = 1;
      } else {
        kstr++;
      }
    } else {
      b_bool = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return b_bool;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_computeFirstOrderOpt(sEf9458k7RTCGn6XpAY3FSD_ros_c_T
  *solution, const scRVBsoAowahmPoAIYa5ea_ros_co_T *objective, int32_T
  workingset_nVar, const real_T workingset_ATwset[5985], int32_T
  workingset_nActiveConstr, real_T workspace[5985])
{
  int32_T b_ix;
  ros_code_B.ix_dj = 0;
  while (ros_code_B.ix_dj <= workingset_nVar - 1) {
    workspace[ros_code_B.ix_dj] = objective->grad[ros_code_B.ix_dj];
    ros_code_B.ix_dj++;
  }

  if (workingset_nActiveConstr != 0) {
    ros_code_B.ix_dj = 0;
    b_ix = (workingset_nActiveConstr - 1) * 45 + 1;
    for (int32_T iac = 1; iac <= b_ix; iac += 45) {
      int32_T c;
      ros_code_B.iy_m = 0;
      c = iac + workingset_nVar;
      for (int32_T ia = iac; ia < c; ia++) {
        workspace[ros_code_B.iy_m] += workingset_ATwset[ia - 1] *
          solution->lambda[ros_code_B.ix_dj];
        ros_code_B.iy_m++;
      }

      ros_code_B.ix_dj++;
    }
  }

  ros_code_B.ix_dj = 1;
  b_ix = 0;
  ros_code_B.smax_c = fabs(workspace[0]);
  for (int32_T iac = 2; iac <= workingset_nVar; iac++) {
    b_ix++;
    ros_code_B.s_n = fabs(workspace[b_ix]);
    if (ros_code_B.s_n > ros_code_B.smax_c) {
      ros_code_B.ix_dj = iac;
      ros_code_B.smax_c = ros_code_B.s_n;
    }
  }

  solution->firstorderopt = fabs(workspace[ros_code_B.ix_dj - 1]);
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_phaseone_i(const real_T H[1936], const real_T f[44],
  sEf9458k7RTCGn6XpAY3FSD_ros_c_T *solution, sg8qKdtlZ7nXgcAC5MP2QHC_ros_c_T
  *memspace, snBUc3P0iDgb4fuyQLszkYC_ros_c_T *workingset,
  siBmBjpOUwoybpuj9rEfGvD_ros_c_T *qrmanager, svUSr4TrK4x4Kz9rQJTxkkF_ros_c_T
  *cholmanager, scRVBsoAowahmPoAIYa5ea_ros_co_T *objective,
  sSOeZ9WO10chPn9Si6PKiCB_ros_c_T *options, const
  sL9bDKomAYkxZSVrG9w6En_ros_co_T *runTimeOptions)
{
  ros_code_B.PROBTYPE_ORIG = workingset->probType;
  ros_code_B.nVar_n = workingset->nVar;
  solution->xstar[44] = solution->maxConstr + 1.0;
  if (workingset->probType == 3) {
    ros_code_B.mConstr = 1;
  } else {
    ros_code_B.mConstr = 4;
  }

  ros_code_setProblemType(workingset, ros_code_B.mConstr);
  ros_code_removeAllIneqConstr(workingset);
  objective->prev_objtype = objective->objtype;
  objective->prev_nvar = objective->nvar;
  objective->prev_hasLinear = objective->hasLinear;
  objective->objtype = 5;
  objective->nvar = 45;
  objective->gammaScalar = 1.0;
  objective->hasLinear = true;
  options->ObjectiveLimit = 1.0E-8 * runTimeOptions->ConstrRelTolFactor;
  options->StepTolerance = 1.4901161193847657E-10;
  solution->fstar = ros_code_computeFval(objective, memspace->workspace_double,
    H, f, solution->xstar);
  solution->state = 5;
  ros_code_iterate(H, f, solution, memspace, workingset, qrmanager, cholmanager,
                   objective, options->ObjectiveLimit, options->StepTolerance,
                   runTimeOptions->MaxIterations,
                   runTimeOptions->ConstrRelTolFactor,
                   runTimeOptions->ProbRelTolFactor,
                   runTimeOptions->RemainFeasible);
  if (workingset->isActiveConstr[(workingset->isActiveIdx[3] + workingset->
       sizes[3]) - 2]) {
    boolean_T exitg1;
    ros_code_B.mConstr = workingset->sizes[0];
    exitg1 = false;
    while ((!exitg1) && (ros_code_B.mConstr + 1 <= workingset->nActiveConstr)) {
      if ((workingset->Wid[ros_code_B.mConstr] == 4) && (workingset->
           Wlocalidx[ros_code_B.mConstr] == workingset->sizes[3])) {
        ros_code_removeConstr(workingset, ros_code_B.mConstr + 1);
        exitg1 = true;
      } else {
        ros_code_B.mConstr++;
      }
    }
  }

  ros_code_B.mConstr = workingset->nActiveConstr;
  while ((ros_code_B.mConstr > workingset->sizes[0]) && (ros_code_B.mConstr >
          ros_code_B.nVar_n)) {
    ros_code_removeConstr(workingset, ros_code_B.mConstr);
    ros_code_B.mConstr--;
  }

  solution->maxConstr = solution->xstar[44];
  ros_code_setProblemType(workingset, ros_code_B.PROBTYPE_ORIG);
  objective->objtype = objective->prev_objtype;
  objective->nvar = objective->prev_nvar;
  objective->hasLinear = objective->prev_hasLinear;
  options->ObjectiveLimit = -1.0E+20;
  options->StepTolerance = 1.0E-8;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_driver(const real_T H[1936], const real_T f[44],
  sEf9458k7RTCGn6XpAY3FSD_ros_c_T *solution, sg8qKdtlZ7nXgcAC5MP2QHC_ros_c_T
  *memspace, snBUc3P0iDgb4fuyQLszkYC_ros_c_T *workingset,
  svUSr4TrK4x4Kz9rQJTxkkF_ros_c_T *cholmanager, sL9bDKomAYkxZSVrG9w6En_ros_co_T
  runTimeOptions, siBmBjpOUwoybpuj9rEfGvD_ros_c_T *qrmanager,
  scRVBsoAowahmPoAIYa5ea_ros_co_T *objective)
{
  static const char_T d_FiniteDifferenceType[7] = { 'f', 'o', 'r', 'w', 'a', 'r',
    'd' };

  static const char_T d_Algorithm[10] = { 'a', 'c', 't', 'i', 'v', 'e', '-', 's',
    'e', 't' };

  static const char_T d_SolverName[8] = { 'q', 'u', 'a', 'd', 'p', 'r', 'o', 'g'
  };

  static const char_T d_Display[5] = { 'f', 'i', 'n', 'a', 'l' };

  memset(&objective->grad[0], 0, 45U * sizeof(real_T));
  memset(&objective->Hx[0], 0, 44U * sizeof(real_T));
  objective->hasLinear = true;
  objective->nvar = 44;
  objective->maxVar = 45;
  objective->beta = 0.0;
  objective->rho = 0.0;
  objective->objtype = 3;
  objective->prev_objtype = 3;
  objective->prev_nvar = 0;
  objective->prev_hasLinear = false;
  objective->gammaScalar = 0.0;
  solution->iterations = 0;
  runTimeOptions.RemainFeasible = true;
  ros_code_B.i_cj = workingset->nVar - 1;
  ros_code_B.b_idx = 0;
  while (ros_code_B.b_idx <= workingset->sizes[0] - 1) {
    solution->xstar[workingset->indexFixed[ros_code_B.b_idx] - 1] =
      workingset->ub[workingset->indexFixed[ros_code_B.b_idx] - 1];
    ros_code_B.b_idx++;
  }

  ros_code_B.b_idx = 0;
  while (ros_code_B.b_idx <= workingset->sizes[3] - 1) {
    if (workingset->isActiveConstr[(workingset->isActiveIdx[3] +
         ros_code_B.b_idx) - 1]) {
      solution->xstar[workingset->indexLB[ros_code_B.b_idx] - 1] =
        -workingset->lb[workingset->indexLB[ros_code_B.b_idx] - 1];
    }

    ros_code_B.b_idx++;
  }

  ros_code_B.b_idx = 0;
  while (ros_code_B.b_idx <= workingset->sizes[4] - 1) {
    if (workingset->isActiveConstr[(workingset->isActiveIdx[4] +
         ros_code_B.b_idx) - 1]) {
      solution->xstar[workingset->indexUB[ros_code_B.b_idx] - 1] =
        workingset->ub[workingset->indexUB[ros_code_B.b_idx] - 1];
    }

    ros_code_B.b_idx++;
  }

  ros_code_PresolveWorkingSet(solution, memspace, workingset, qrmanager);
  ros_code_B.options.InitDamping = 0.01;
  for (ros_code_B.b_idx = 0; ros_code_B.b_idx < 7; ros_code_B.b_idx++) {
    ros_code_B.options.FiniteDifferenceType[ros_code_B.b_idx] =
      d_FiniteDifferenceType[ros_code_B.b_idx];
  }

  ros_code_B.options.SpecifyObjectiveGradient = false;
  ros_code_B.options.ScaleProblem = false;
  ros_code_B.options.SpecifyConstraintGradient = false;
  ros_code_B.options.NonFiniteSupport = true;
  ros_code_B.options.IterDisplaySQP = false;
  ros_code_B.options.FiniteDifferenceStepSize = -1.0;
  ros_code_B.options.MaxFunctionEvaluations = -1.0;
  ros_code_B.options.IterDisplayQP = false;
  ros_code_B.options.PricingTolerance = 0.0;
  for (ros_code_B.b_idx = 0; ros_code_B.b_idx < 10; ros_code_B.b_idx++) {
    ros_code_B.options.Algorithm[ros_code_B.b_idx] =
      d_Algorithm[ros_code_B.b_idx];
  }

  ros_code_B.options.ObjectiveLimit = -1.0E+20;
  ros_code_B.options.ConstraintTolerance = 1.0E-8;
  ros_code_B.options.OptimalityTolerance = 1.0E-8;
  ros_code_B.options.StepTolerance = 1.0E-8;
  ros_code_B.options.MaxIterations = -1.0;
  ros_code_B.options.FunctionTolerance = (rtInf);
  for (ros_code_B.b_idx = 0; ros_code_B.b_idx < 8; ros_code_B.b_idx++) {
    ros_code_B.options.SolverName[ros_code_B.b_idx] =
      d_SolverName[ros_code_B.b_idx];
  }

  ros_code_B.options.CheckGradients = false;
  ros_code_B.options.Diagnostics[0] = 'o';
  ros_code_B.options.Diagnostics[1] = 'f';
  ros_code_B.options.Diagnostics[2] = 'f';
  ros_code_B.options.DiffMaxChange = (rtInf);
  ros_code_B.options.DiffMinChange = 0.0;
  for (ros_code_B.b_idx = 0; ros_code_B.b_idx < 5; ros_code_B.b_idx++) {
    ros_code_B.options.Display[ros_code_B.b_idx] = d_Display[ros_code_B.b_idx];
  }

  ros_code_B.options.FunValCheck[0] = 'o';
  ros_code_B.options.FunValCheck[1] = 'f';
  ros_code_B.options.FunValCheck[2] = 'f';
  ros_code_B.options.UseParallel = false;
  ros_code_B.options.LinearSolver[0] = 'a';
  ros_code_B.options.LinearSolver[1] = 'u';
  ros_code_B.options.LinearSolver[2] = 't';
  ros_code_B.options.LinearSolver[3] = 'o';
  ros_code_B.options.SubproblemAlgorithm[0] = 'c';
  ros_code_B.options.SubproblemAlgorithm[1] = 'g';
  if (solution->state >= 0) {
    boolean_T guard1 = false;
    solution->iterations = 0;
    solution->maxConstr = ros_c_maxConstraintViolation_c3(workingset,
      solution->xstar);
    ros_code_B.maxConstr_new = 1.0E-8 * runTimeOptions.ConstrRelTolFactor;
    guard1 = false;
    if (solution->maxConstr > ros_code_B.maxConstr_new) {
      ros_code_phaseone(H, f, solution, memspace, workingset, qrmanager,
                        cholmanager, &runTimeOptions, objective,
                        &ros_code_B.options);
      if (solution->state == 0) {
      } else {
        solution->maxConstr = ros_c_maxConstraintViolation_c3(workingset,
          solution->xstar);
        if (solution->maxConstr > ros_code_B.maxConstr_new) {
          memset(&solution->lambda[0], 0, 133U * sizeof(real_T));
          solution->fstar = ros_code_computeFval(objective,
            memspace->workspace_double, H, f, solution->xstar);
          solution->state = -2;
        } else {
          if (solution->maxConstr > 0.0) {
            ros_code_B.b_idx = 0;
            while (ros_code_B.b_idx <= ros_code_B.i_cj) {
              solution->searchDir[ros_code_B.b_idx] = solution->
                xstar[ros_code_B.b_idx];
              ros_code_B.b_idx++;
            }

            ros_code_PresolveWorkingSet_a(solution, memspace, workingset,
              qrmanager);
            ros_code_B.maxConstr_new = ros_c_maxConstraintViolation_c3
              (workingset, solution->xstar);
            if (ros_code_B.maxConstr_new >= solution->maxConstr) {
              solution->maxConstr = ros_code_B.maxConstr_new;
              ros_code_B.b_idx = 0;
              while (ros_code_B.b_idx <= ros_code_B.i_cj) {
                solution->xstar[ros_code_B.b_idx] = solution->
                  searchDir[ros_code_B.b_idx];
                ros_code_B.b_idx++;
              }
            }
          }

          guard1 = true;
        }
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      ros_code_iterate(H, f, solution, memspace, workingset, qrmanager,
                       cholmanager, objective, ros_code_B.options.ObjectiveLimit,
                       ros_code_B.options.StepTolerance,
                       runTimeOptions.MaxIterations,
                       runTimeOptions.ConstrRelTolFactor,
                       runTimeOptions.ProbRelTolFactor, true);
      if (ros_code_strcmp(ros_code_B.options.SolverName) && (solution->state !=
           -6)) {
        solution->maxConstr = ros_c_maxConstraintViolation_c3(workingset,
          solution->xstar);
        ros_code_computeFirstOrderOpt(solution, objective, workingset->nVar,
          workingset->ATwset, workingset->nActiveConstr,
          memspace->workspace_double);
        runTimeOptions.RemainFeasible = false;
        while ((solution->iterations < runTimeOptions.MaxIterations) &&
               ((solution->state == -7) || ((solution->state == 1) &&
                 ((solution->maxConstr > 1.0E-8 *
                   runTimeOptions.ConstrRelTolFactor) ||
                  (solution->firstorderopt > 1.0E-8 *
                   runTimeOptions.ProbRelTolFactor))))) {
          ros_cod_feasibleX0ForWorkingSet(memspace->workspace_double,
            solution->xstar, workingset, qrmanager);
          ros_code_PresolveWorkingSet_a(solution, memspace, workingset,
            qrmanager);
          ros_code_phaseone_i(H, f, solution, memspace, workingset, qrmanager,
                              cholmanager, objective, &ros_code_B.options,
                              &runTimeOptions);
          ros_code_iterate(H, f, solution, memspace, workingset, qrmanager,
                           cholmanager, objective,
                           ros_code_B.options.ObjectiveLimit,
                           ros_code_B.options.StepTolerance,
                           runTimeOptions.MaxIterations,
                           runTimeOptions.ConstrRelTolFactor,
                           runTimeOptions.ProbRelTolFactor, false);
          solution->maxConstr = ros_c_maxConstraintViolation_c3(workingset,
            solution->xstar);
          ros_code_computeFirstOrderOpt(solution, objective, workingset->nVar,
            workingset->ATwset, workingset->nActiveConstr,
            memspace->workspace_double);
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_quadprog(const real_T H[1936], const real_T f[44], const
  real_T Aineq[1936], const real_T bineq[44], const real_T lb[44], const real_T
  ub[44], real_T x[44], real_T *fval, real_T *exitflag)
{
  ros_code_B.solution.fstar = 0.0;
  ros_code_B.solution.firstorderopt = 0.0;
  memset(&ros_code_B.solution.lambda[0], 0, 133U * sizeof(real_T));
  ros_code_B.solution.state = 0;
  ros_code_B.solution.maxConstr = 0.0;
  ros_code_B.solution.iterations = 0;
  memset(&ros_code_B.solution.searchDir[0], 0, 45U * sizeof(real_T));
  memset(&ros_code_B.solution.xstar[0], 0, 44U * sizeof(real_T));
  ros_code_B.CholRegManager.ldm = 45;
  ros_code_B.CholRegManager.ndims = 0;
  ros_code_B.CholRegManager.info = 0;
  ros_code_B.CholRegManager.ConvexCheck = true;
  ros_code_B.CholRegManager.regTol_ = 0.0;
  ros_code_B.CholRegManager.scaleFactor = 100.0;
  ros_code_B.WorkingSet.nVar = 44;
  ros_code_B.WorkingSet.nVarOrig = 44;
  ros_code_B.WorkingSet.nVarMax = 45;
  ros_code_B.WorkingSet.ldA = 45;
  memset(&ros_code_B.WorkingSet.Aineq[0], 0, 1980U * sizeof(real_T));
  memset(&ros_code_B.WorkingSet.bineq[0], 0, 44U * sizeof(real_T));
  memset(&ros_code_B.WorkingSet.lb[0], 0, 45U * sizeof(real_T));
  memset(&ros_code_B.WorkingSet.ub[0], 0, 45U * sizeof(real_T));
  ros_code_B.WorkingSet.mEqRemoved = 0;
  memset(&ros_code_B.WorkingSet.ATwset[0], 0, 5985U * sizeof(real_T));
  ros_code_B.WorkingSet.nActiveConstr = 0;
  memset(&ros_code_B.WorkingSet.bwset[0], 0, 133U * sizeof(real_T));
  memset(&ros_code_B.WorkingSet.maxConstrWorkspace[0], 0, 133U * sizeof(real_T));
  memset(&ros_code_B.WorkingSet.isActiveConstr[0], 0, 133U * sizeof(boolean_T));
  memset(&ros_code_B.WorkingSet.Wid[0], 0, 133U * sizeof(int32_T));
  memset(&ros_code_B.WorkingSet.Wlocalidx[0], 0, 133U * sizeof(int32_T));
  for (ros_code_B.i_c = 0; ros_code_B.i_c < 5; ros_code_B.i_c++) {
    ros_code_B.WorkingSet.nWConstr[ros_code_B.i_c] = 0;
  }

  ros_code_B.WorkingSet.probType = 3;
  ros_code_B.WorkingSet.SLACK0 = 1.0E-5;
  memset(&ros_code_B.WorkingSet.indexLB[0], 0, 45U * sizeof(int32_T));
  memset(&ros_code_B.WorkingSet.indexUB[0], 0, 45U * sizeof(int32_T));
  memset(&ros_code_B.WorkingSet.indexFixed[0], 0, 45U * sizeof(int32_T));
  ros_code_B.k = 44;
  ros_code_B.mUB = 0;
  ros_code_B.mFixed = 0;
  for (ros_code_B.idx = 0; ros_code_B.idx < 44; ros_code_B.idx++) {
    boolean_T guard1 = false;
    ros_code_B.ub_i = ub[ros_code_B.idx];
    ros_code_B.H_infnrm = lb[ros_code_B.idx];
    guard1 = false;
    if ((!rtIsInf(ros_code_B.H_infnrm)) && (!rtIsNaN(ros_code_B.H_infnrm))) {
      if (fabs(ros_code_B.H_infnrm - ros_code_B.ub_i) < 1.0E-8) {
        ros_code_B.mFixed++;
        ros_code_B.WorkingSet.indexFixed[ros_code_B.mFixed - 1] = ros_code_B.idx
          + 1;
      } else {
        ros_code_B.k++;
        ros_code_B.WorkingSet.indexLB[ros_code_B.k - 45] = ros_code_B.idx + 1;
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if ((!rtIsInf(ros_code_B.ub_i)) && (!rtIsNaN(ros_code_B.ub_i))) {
        ros_code_B.mUB++;
        ros_code_B.WorkingSet.indexUB[ros_code_B.mUB - 1] = ros_code_B.idx + 1;
      }
    }
  }

  ros_code_B.idx = (ros_code_B.k + ros_code_B.mUB) + ros_code_B.mFixed;
  ros_code_B.WorkingSet.mConstr = ros_code_B.idx;
  ros_code_B.WorkingSet.mConstrOrig = ros_code_B.idx;
  ros_code_B.WorkingSet.mConstrMax = 133;
  ros_code_B.WorkingSet.sizes[0] = ros_code_B.mFixed;
  ros_code_B.WorkingSet.sizes[1] = 0;
  ros_code_B.WorkingSet.sizes[2] = 44;
  ros_code_B.WorkingSet.sizes[3] = ros_code_B.k - 44;
  ros_code_B.WorkingSet.sizes[4] = ros_code_B.mUB;
  for (ros_code_B.idx = 0; ros_code_B.idx < 5; ros_code_B.idx++) {
    ros_code_B.WorkingSet.sizesNormal[ros_code_B.idx] =
      ros_code_B.WorkingSet.sizes[ros_code_B.idx];
  }

  ros_code_B.WorkingSet.sizesPhaseOne[0] = ros_code_B.mFixed;
  ros_code_B.WorkingSet.sizesPhaseOne[1] = 0;
  ros_code_B.WorkingSet.sizesPhaseOne[2] = 44;
  ros_code_B.WorkingSet.sizesPhaseOne[3] = ros_code_B.k - 43;
  ros_code_B.WorkingSet.sizesPhaseOne[4] = ros_code_B.mUB;
  ros_code_B.WorkingSet.sizesRegularized[0] = ros_code_B.mFixed;
  ros_code_B.WorkingSet.sizesRegularized[1] = 0;
  ros_code_B.WorkingSet.sizesRegularized[2] = 44;
  ros_code_B.WorkingSet.sizesRegularized[3] = ros_code_B.k;
  ros_code_B.WorkingSet.sizesRegularized[4] = ros_code_B.mUB;
  ros_code_B.WorkingSet.sizesRegPhaseOne[0] = ros_code_B.mFixed;
  ros_code_B.WorkingSet.sizesRegPhaseOne[1] = 0;
  ros_code_B.WorkingSet.sizesRegPhaseOne[2] = 44;
  ros_code_B.WorkingSet.sizesRegPhaseOne[3] = ros_code_B.k + 1;
  ros_code_B.WorkingSet.sizesRegPhaseOne[4] = ros_code_B.mUB;
  ros_code_B.WorkingSet.isActiveIdxNormal[0] = 1;
  ros_code_B.WorkingSet.isActiveIdxNormal[1] = ros_code_B.mFixed;
  ros_code_B.WorkingSet.isActiveIdxNormal[2] = 0;
  ros_code_B.WorkingSet.isActiveIdxNormal[3] = 44;
  ros_code_B.WorkingSet.isActiveIdxNormal[4] = ros_code_B.k - 44;
  ros_code_B.WorkingSet.isActiveIdxNormal[5] = ros_code_B.mUB;
  for (ros_code_B.idx = 0; ros_code_B.idx < 6; ros_code_B.idx++) {
    ros_code_B.WorkingSet.isActiveIdxRegPhaseOne[ros_code_B.idx] =
      ros_code_B.WorkingSet.isActiveIdxNormal[ros_code_B.idx];
  }

  for (ros_code_B.idx = 0; ros_code_B.idx < 5; ros_code_B.idx++) {
    ros_code_B.WorkingSet.isActiveIdxRegPhaseOne[ros_code_B.idx + 1] +=
      ros_code_B.WorkingSet.isActiveIdxRegPhaseOne[ros_code_B.idx];
  }

  for (ros_code_B.idx = 0; ros_code_B.idx < 6; ros_code_B.idx++) {
    ros_code_B.WorkingSet.isActiveIdx[ros_code_B.idx] =
      ros_code_B.WorkingSet.isActiveIdxRegPhaseOne[ros_code_B.idx];
  }

  ros_code_B.WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
  ros_code_B.WorkingSet.isActiveIdxRegPhaseOne[1] = ros_code_B.mFixed;
  ros_code_B.WorkingSet.isActiveIdxRegPhaseOne[2] = 0;
  ros_code_B.WorkingSet.isActiveIdxRegPhaseOne[3] = 44;
  ros_code_B.WorkingSet.isActiveIdxRegPhaseOne[4] = ros_code_B.k - 43;
  ros_code_B.WorkingSet.isActiveIdxRegPhaseOne[5] = ros_code_B.mUB;
  for (ros_code_B.idx = 0; ros_code_B.idx < 5; ros_code_B.idx++) {
    ros_code_B.WorkingSet.isActiveIdxNormal[ros_code_B.idx + 1] +=
      ros_code_B.WorkingSet.isActiveIdxNormal[ros_code_B.idx];
    ros_code_B.WorkingSet.isActiveIdxRegPhaseOne[ros_code_B.idx + 1] +=
      ros_code_B.WorkingSet.isActiveIdxRegPhaseOne[ros_code_B.idx];
  }

  for (ros_code_B.idx = 0; ros_code_B.idx < 6; ros_code_B.idx++) {
    ros_code_B.WorkingSet.isActiveIdxPhaseOne[ros_code_B.idx] =
      ros_code_B.WorkingSet.isActiveIdxRegPhaseOne[ros_code_B.idx];
  }

  ros_code_B.WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
  ros_code_B.WorkingSet.isActiveIdxRegPhaseOne[1] = ros_code_B.mFixed;
  ros_code_B.WorkingSet.isActiveIdxRegPhaseOne[2] = 0;
  ros_code_B.WorkingSet.isActiveIdxRegPhaseOne[3] = 44;
  ros_code_B.WorkingSet.isActiveIdxRegPhaseOne[4] = ros_code_B.k;
  ros_code_B.WorkingSet.isActiveIdxRegPhaseOne[5] = ros_code_B.mUB;
  for (ros_code_B.idx = 0; ros_code_B.idx < 5; ros_code_B.idx++) {
    ros_code_B.WorkingSet.isActiveIdxRegPhaseOne[ros_code_B.idx + 1] +=
      ros_code_B.WorkingSet.isActiveIdxRegPhaseOne[ros_code_B.idx];
  }

  for (ros_code_B.idx = 0; ros_code_B.idx < 6; ros_code_B.idx++) {
    ros_code_B.WorkingSet.isActiveIdxRegularized[ros_code_B.idx] =
      ros_code_B.WorkingSet.isActiveIdxRegPhaseOne[ros_code_B.idx];
  }

  ros_code_B.WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
  ros_code_B.WorkingSet.isActiveIdxRegPhaseOne[1] = ros_code_B.mFixed;
  ros_code_B.WorkingSet.isActiveIdxRegPhaseOne[2] = 0;
  ros_code_B.WorkingSet.isActiveIdxRegPhaseOne[3] = 44;
  ros_code_B.WorkingSet.isActiveIdxRegPhaseOne[4] = ros_code_B.k + 1;
  ros_code_B.WorkingSet.isActiveIdxRegPhaseOne[5] = ros_code_B.mUB;
  for (ros_code_B.idx = 0; ros_code_B.idx < 5; ros_code_B.idx++) {
    ros_code_B.WorkingSet.isActiveIdxRegPhaseOne[ros_code_B.idx + 1] +=
      ros_code_B.WorkingSet.isActiveIdxRegPhaseOne[ros_code_B.idx];
  }

  for (ros_code_B.idx = 0; ros_code_B.idx < 44; ros_code_B.idx++) {
    for (ros_code_B.colPos = 0; ros_code_B.colPos < 44; ros_code_B.colPos++) {
      ros_code_B.WorkingSet.Aineq[ros_code_B.colPos + 45 * ros_code_B.idx] =
        Aineq[44 * ros_code_B.colPos + ros_code_B.idx];
    }

    ros_code_B.WorkingSet.bineq[ros_code_B.idx] = bineq[ros_code_B.idx];
    ros_code_B.WorkingSet.lb[ros_code_B.idx] = -lb[ros_code_B.idx];
    ros_code_B.WorkingSet.ub[ros_code_B.idx] = ub[ros_code_B.idx];
  }

  ros_code_setProblemType(&ros_code_B.WorkingSet, 3);
  ros_code_B.idx = ros_code_B.WorkingSet.isActiveIdx[2];
  while (ros_code_B.idx < 134) {
    ros_code_B.WorkingSet.isActiveConstr[ros_code_B.idx - 1] = false;
    ros_code_B.idx++;
  }

  ros_code_B.WorkingSet.nWConstr[0] = ros_code_B.WorkingSet.sizes[0];
  ros_code_B.WorkingSet.nWConstr[1] = 0;
  ros_code_B.WorkingSet.nWConstr[2] = 0;
  ros_code_B.WorkingSet.nWConstr[3] = 0;
  ros_code_B.WorkingSet.nWConstr[4] = 0;
  ros_code_B.WorkingSet.nActiveConstr = ros_code_B.WorkingSet.nWConstr[0];
  ros_code_B.idx = 0;
  while (ros_code_B.idx <= ros_code_B.WorkingSet.sizes[0] - 1) {
    ros_code_B.WorkingSet.Wid[ros_code_B.idx] = 1;
    ros_code_B.WorkingSet.Wlocalidx[ros_code_B.idx] = ros_code_B.idx + 1;
    ros_code_B.WorkingSet.isActiveConstr[ros_code_B.idx] = true;
    ros_code_B.colPos = 45 * ros_code_B.idx - 1;
    ros_code_B.i_c = 0;
    while (ros_code_B.i_c <= ros_code_B.WorkingSet.indexFixed[ros_code_B.idx] -
           2) {
      ros_code_B.WorkingSet.ATwset[(ros_code_B.i_c + ros_code_B.colPos) + 1] =
        0.0;
      ros_code_B.i_c++;
    }

    ros_code_B.WorkingSet.ATwset[ros_code_B.WorkingSet.indexFixed[ros_code_B.idx]
      + ros_code_B.colPos] = 1.0;
    ros_code_B.i_c = ros_code_B.WorkingSet.indexFixed[ros_code_B.idx] + 1;
    while (ros_code_B.i_c <= ros_code_B.WorkingSet.nVar) {
      ros_code_B.WorkingSet.ATwset[ros_code_B.i_c + ros_code_B.colPos] = 0.0;
      ros_code_B.i_c++;
    }

    ros_code_B.WorkingSet.bwset[ros_code_B.idx] =
      ros_code_B.WorkingSet.ub[ros_code_B.WorkingSet.indexFixed[ros_code_B.idx]
      - 1];
    ros_code_B.idx++;
  }

  ros_code_B.WorkingSet.SLACK0 = 0.0;
  ros_code_B.ub_i = 1.0;
  ros_code_B.H_infnrm = 0.0;
  ros_code_B.f_infnrm = 0.0;
  for (ros_code_B.idx = 0; ros_code_B.idx < 44; ros_code_B.idx++) {
    ros_code_B.colSum = 0.0;
    ros_code_B.colPos = 45 * ros_code_B.idx;
    ros_code_B.b_colSum = 0.0;
    for (ros_code_B.i_c = 0; ros_code_B.i_c < 44; ros_code_B.i_c++) {
      ros_code_B.colSum += fabs(ros_code_B.WorkingSet.Aineq[ros_code_B.i_c +
        ros_code_B.colPos]);
      ros_code_B.b_colSum += fabs(H[44 * ros_code_B.idx + ros_code_B.i_c]);
    }

    if ((!(ros_code_B.ub_i >= ros_code_B.colSum)) && (!rtIsNaN(ros_code_B.colSum)))
    {
      ros_code_B.ub_i = ros_code_B.colSum;
    }

    if ((!(ros_code_B.H_infnrm >= ros_code_B.b_colSum)) && (!rtIsNaN
         (ros_code_B.b_colSum))) {
      ros_code_B.H_infnrm = ros_code_B.b_colSum;
    }

    ros_code_B.colSum = fabs(f[ros_code_B.idx]);
    if ((!(ros_code_B.f_infnrm >= ros_code_B.colSum)) && (!rtIsNaN
         (ros_code_B.colSum))) {
      ros_code_B.f_infnrm = ros_code_B.colSum;
    }
  }

  ros_code_B.expl_temp.RemainFeasible = false;
  if ((ros_code_B.ub_i >= ros_code_B.f_infnrm) || rtIsNaN(ros_code_B.f_infnrm))
  {
    ros_code_B.f_infnrm = ros_code_B.ub_i;
  }

  if ((ros_code_B.f_infnrm >= ros_code_B.H_infnrm) || rtIsNaN
      (ros_code_B.H_infnrm)) {
    ros_code_B.expl_temp.ProbRelTolFactor = ros_code_B.f_infnrm;
  } else {
    ros_code_B.expl_temp.ProbRelTolFactor = ros_code_B.H_infnrm;
  }

  ros_code_B.expl_temp.ConstrRelTolFactor = ros_code_B.ub_i;
  ros_code_B.expl_temp.MaxIterations = (((ros_code_B.mFixed + ros_code_B.k) +
    ros_code_B.mUB) + 44) * 10;
  ros_code_driver(H, f, &ros_code_B.solution, &ros_code_B.memspace,
                  &ros_code_B.WorkingSet, &ros_code_B.CholRegManager,
                  ros_code_B.expl_temp, &ros_code_B.QRManager,
                  &ros_code_B.QPObjective);
  memcpy(&x[0], &ros_code_B.solution.xstar[0], 44U * sizeof(real_T));
  if (ros_code_B.solution.state > 0) {
    *fval = ros_code_B.solution.fstar;
  } else {
    *fval = ros_code_computeFval(&ros_code_B.QPObjective,
      ros_code_B.memspace.workspace_double, H, f, ros_code_B.solution.xstar);
  }

  switch (ros_code_B.solution.state) {
   case 2:
    ros_code_B.solution.state = -3;
    break;

   case -3:
    ros_code_B.solution.state = -2;
    break;

   case 4:
    ros_code_B.solution.state = -2;
    break;
  }

  *exitflag = ros_code_B.solution.state;
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_linspace_m(real_T d2, real_T n, real_T y_data[], int32_T
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
        y_data[0] = 0.1;
        if (static_cast<int32_T>(n) >= 3) {
          if ((-d2 == 0.1) && (static_cast<int32_T>(n) > 2)) {
            ros_code_B.delta1 = d2 / (static_cast<real_T>(static_cast<int32_T>(n))
              - 1.0);
            for (int32_T c_k = 2; c_k < static_cast<int32_T>(n); c_k++) {
              y_data[c_k - 1] = (static_cast<real_T>((c_k << 1) -
                static_cast<int32_T>(n)) - 1.0) * ros_code_B.delta1;
            }

            if ((static_cast<int32_T>(n) & 1) == 1) {
              y_data[static_cast<int32_T>(n) >> 1] = 0.0;
            }
          } else if ((d2 < 0.0) && (fabs(d2) > 8.9884656743115785E+307)) {
            real_T delta2;
            ros_code_B.delta1 = 0.1 / (static_cast<real_T>(static_cast<int32_T>
              (n)) - 1.0);
            delta2 = d2 / (static_cast<real_T>(static_cast<int32_T>(n)) - 1.0);
            for (int32_T c_k = 0; c_k <= static_cast<int32_T>(n) - 3; c_k++) {
              y_data[c_k + 1] = ((static_cast<real_T>(c_k) + 1.0) * delta2 + 0.1)
                - (static_cast<real_T>(c_k) + 1.0) * ros_code_B.delta1;
            }
          } else {
            ros_code_B.delta1 = (d2 - 0.1) / (static_cast<real_T>
              (static_cast<int32_T>(n)) - 1.0);
            for (int32_T c_k = 0; c_k <= static_cast<int32_T>(n) - 3; c_k++) {
              y_data[c_k + 1] = (static_cast<real_T>(c_k) + 1.0) *
                ros_code_B.delta1 + 0.1;
            }
          }
        }
      }
    }
  }
}

static void ros_co_binary_expand_op_pijw35k(real_T in1_data[], int32_T in1_size
  [2], const real_T in2_data[], const int32_T in2_size[2], const real_T in3[6],
  int32_T in4)
{
  ros_code_B.in3 = in3[in4 + 1];
  ros_code_B.in2_size_idx_1 = in1_size[1] == 1 ? in2_size[1] : in1_size[1];
  ros_code_B.stride_0_1 = (in2_size[1] != 1);
  ros_code_B.stride_1_1 = (in1_size[1] != 1);
  ros_code_B.loop_ub_c = in1_size[1] == 1 ? in2_size[1] : in1_size[1];
  for (ros_code_B.i4 = 0; ros_code_B.i4 < ros_code_B.loop_ub_c; ros_code_B.i4++)
  {
    ros_code_B.in2_data_d[ros_code_B.i4] = in2_data[ros_code_B.i4 *
      ros_code_B.stride_0_1] * in1_data[ros_code_B.i4 * ros_code_B.stride_1_1] +
      ros_code_B.in3;
  }

  in1_size[0] = 1;
  in1_size[1] = ros_code_B.in2_size_idx_1;
  if (ros_code_B.in2_size_idx_1 - 1 >= 0) {
    memcpy(&in1_data[0], &ros_code_B.in2_data_d[0], ros_code_B.in2_size_idx_1 *
           sizeof(real_T));
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_polyval(const real_T p[6], const real_T x_data[], const
  int32_T x_size[2], real_T y_data[], int32_T y_size[2])
{
  y_size[0] = 1;
  y_size[1] = x_size[1];
  if (x_size[1] != 0) {
    ros_code_B.y_idx_1 = x_size[1];
    y_size[0] = 1;
    y_size[1] = x_size[1];
    for (ros_code_B.i2 = 0; ros_code_B.i2 < ros_code_B.y_idx_1; ros_code_B.i2++)
    {
      y_data[ros_code_B.i2] = p[0];
    }

    for (ros_code_B.y_idx_1 = 0; ros_code_B.y_idx_1 < 5; ros_code_B.y_idx_1++) {
      if (x_size[1] == y_size[1]) {
        ros_code_B.p = p[ros_code_B.y_idx_1 + 1];
        ros_code_B.loop_ub_g = x_size[1] - 1;
        y_size[0] = 1;
        y_size[1] = x_size[1];
        ros_code_B.scalarLB_n = (x_size[1] / 2) << 1;
        ros_code_B.vectorUB_l = ros_code_B.scalarLB_n - 2;
        for (ros_code_B.i2 = 0; ros_code_B.i2 <= ros_code_B.vectorUB_l;
             ros_code_B.i2 += 2) {
          __m128d tmp;
          ros_code_B.i3 = ros_code_B.i2;
          tmp = _mm_loadu_pd(&y_data[ros_code_B.i3]);
          _mm_storeu_pd(&y_data[ros_code_B.i3], _mm_add_pd(_mm_mul_pd
            (_mm_loadu_pd(&x_data[ros_code_B.i3]), tmp), _mm_set1_pd
            (ros_code_B.p)));
        }

        for (ros_code_B.i2 = ros_code_B.scalarLB_n; ros_code_B.i2 <=
             ros_code_B.loop_ub_g; ros_code_B.i2++) {
          ros_code_B.vectorUB_l = ros_code_B.i2;
          y_data[ros_code_B.vectorUB_l] = x_data[ros_code_B.vectorUB_l] *
            y_data[ros_code_B.vectorUB_l] + ros_code_B.p;
        }
      } else {
        ros_co_binary_expand_op_pijw35k(y_data, y_size, x_data, x_size, p,
          ros_code_B.y_idx_1);
      }
    }
  }
}

static void ros_code_binary_expand_op_p(real_T in1_data[], int32_T *in1_size,
  const real_T in2[30], real_T in3, const real_T in4_data[], real_T in5, const
  real_T in6_data[])
{
  __m128d tmp;

  // Outputs for Atomic SubSystem: '<Root>/Lattice_planner'
  // MATLAB Function: '<S3>/reducePath'
  ros_code_B.in4_tmp = static_cast<int32_T>(in5) - 1;
  ros_code_B.in4 = in4_data[ros_code_B.in4_tmp];
  if (in3 < 1.0) {
    ros_code_B.loop_ub_b = -1;
  } else {
    ros_code_B.loop_ub_b = static_cast<int32_T>(in3) - 1;
  }

  ros_code_B.in2_size_f = ros_code_B.loop_ub_b + 1;
  ros_code_B.scalarLB_a = ((ros_code_B.loop_ub_b + 1) / 2) << 1;

  // End of Outputs for SubSystem: '<Root>/Lattice_planner'
  ros_code_B.vectorUB_il = ros_code_B.scalarLB_a - 2;

  // Outputs for Atomic SubSystem: '<Root>/Lattice_planner'
  // MATLAB Function: '<S3>/reducePath'
  for (ros_code_B.i5 = 0; ros_code_B.i5 <= ros_code_B.vectorUB_il; ros_code_B.i5
       += 2) {
    tmp = _mm_loadu_pd(&in2[ros_code_B.i5]);
    _mm_storeu_pd(&ros_code_B.in2_data_h[ros_code_B.i5], _mm_sub_pd(tmp,
      _mm_set1_pd(ros_code_B.in4)));
  }

  for (ros_code_B.i5 = ros_code_B.scalarLB_a; ros_code_B.i5 <=
       ros_code_B.loop_ub_b; ros_code_B.i5++) {
    ros_code_B.in2_data_h[ros_code_B.i5] = in2[ros_code_B.i5] - ros_code_B.in4;
  }

  ros_code_power(ros_code_B.in2_data_h, &ros_code_B.in2_size_f,
                 ros_code_B.tmp_data_b, &ros_code_B.tmp_size_j);
  ros_code_B.in4 = in6_data[ros_code_B.in4_tmp];
  if (in3 < 1.0) {
    ros_code_B.loop_ub_b = -1;
  } else {
    ros_code_B.loop_ub_b = static_cast<int32_T>(in3) - 1;
  }

  ros_code_B.in2_size_f = ros_code_B.loop_ub_b + 1;
  ros_code_B.scalarLB_a = ((ros_code_B.loop_ub_b + 1) / 2) << 1;

  // End of Outputs for SubSystem: '<Root>/Lattice_planner'
  ros_code_B.vectorUB_il = ros_code_B.scalarLB_a - 2;

  // Outputs for Atomic SubSystem: '<Root>/Lattice_planner'
  // MATLAB Function: '<S3>/reducePath'
  for (ros_code_B.i5 = 0; ros_code_B.i5 <= ros_code_B.vectorUB_il; ros_code_B.i5
       += 2) {
    tmp = _mm_loadu_pd(&in2[ros_code_B.i5 + 10]);
    _mm_storeu_pd(&ros_code_B.in2_data_h[ros_code_B.i5], _mm_sub_pd(tmp,
      _mm_set1_pd(ros_code_B.in4)));
  }

  for (ros_code_B.i5 = ros_code_B.scalarLB_a; ros_code_B.i5 <=
       ros_code_B.loop_ub_b; ros_code_B.i5++) {
    ros_code_B.in2_data_h[ros_code_B.i5] = in2[ros_code_B.i5 + 10] -
      ros_code_B.in4;
  }

  ros_code_power(ros_code_B.in2_data_h, &ros_code_B.in2_size_f,
                 ros_code_B.tmp_data_p, &ros_code_B.tmp_size_oo);
  *in1_size = ros_code_B.tmp_size_oo == 1 ? ros_code_B.tmp_size_j :
    ros_code_B.tmp_size_oo;
  ros_code_B.scalarLB_a = (ros_code_B.tmp_size_j != 1);
  ros_code_B.vectorUB_il = (ros_code_B.tmp_size_oo != 1);
  ros_code_B.loop_ub_b = ros_code_B.tmp_size_oo == 1 ? ros_code_B.tmp_size_j :
    ros_code_B.tmp_size_oo;
  for (ros_code_B.i5 = 0; ros_code_B.i5 < ros_code_B.loop_ub_b; ros_code_B.i5++)
  {
    in1_data[ros_code_B.i5] = ros_code_B.tmp_data_b[ros_code_B.i5 *
      ros_code_B.scalarLB_a] + ros_code_B.tmp_data_p[ros_code_B.i5 *
      ros_code_B.vectorUB_il];
  }

  // End of Outputs for SubSystem: '<Root>/Lattice_planner'
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_sqrt(real_T x_data[], const int32_T *x_size)
{
  for (int32_T k = 0; k < *x_size; k++) {
    x_data[k] = sqrt(x_data[k]);
  }
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
      if ((x_data[0] > *ex) || (rtIsNaN(x_data[0]) && (!rtIsNaN(*ex)))) {
        *idx = *x_size;
      } else {
        *ex = x_data[0];
        *idx = 1;
      }
    }
  } else {
    int32_T k;
    if (!rtIsNaN(x_data[0])) {
      *idx = 1;
    } else {
      boolean_T exitg1;
      *idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= *x_size)) {
        if (!rtIsNaN(x_data[k - 1])) {
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
static void ros_code_power_en(const real_T a_data[], const int32_T a_size[2],
  real_T y_data[], int32_T y_size[2])
{
  y_size[0] = 1;
  y_size[1] = a_size[1];
  ros_code_B.k_h = 0;
  while (ros_code_B.k_h <= a_size[1] - 1) {
    ros_code_B.y_data_tmp_n = ros_code_B.k_h;
    ros_code_B.y_data_tmp = a_data[ros_code_B.y_data_tmp_n];
    y_data[ros_code_B.y_data_tmp_n] = ros_code_B.y_data_tmp *
      ros_code_B.y_data_tmp;
    ros_code_B.k_h++;
  }
}

static void ros_code_binary_expand_op(real_T in1_data[], int32_T in1_size[2],
  const real_T in2[30], int32_T in3, const real_T in4_data[], const int32_T
  in4_size[2], const real_T in5_data[], const int32_T in5_size[2])
{
  __m128d tmp;

  // Outputs for Atomic SubSystem: '<Root>/Lattice_planner'
  // MATLAB Function: '<S3>/reducePath'
  ros_code_B.in2 = in2[in3 - 1];
  ros_code_B.in2_size[0] = 1;
  ros_code_B.in2_size[1] = in4_size[1];
  ros_code_B.loop_ub_d = in4_size[1];
  ros_code_B.scalarLB_j = (in4_size[1] / 2) << 1;

  // End of Outputs for SubSystem: '<Root>/Lattice_planner'
  ros_code_B.vectorUB_i = ros_code_B.scalarLB_j - 2;

  // Outputs for Atomic SubSystem: '<Root>/Lattice_planner'
  // MATLAB Function: '<S3>/reducePath'
  for (ros_code_B.i_f = 0; ros_code_B.i_f <= ros_code_B.vectorUB_i;
       ros_code_B.i_f += 2) {
    ros_code_B.i1 = ros_code_B.i_f;
    tmp = _mm_loadu_pd(&in4_data[ros_code_B.i1]);
    _mm_storeu_pd(&ros_code_B.in2_data[ros_code_B.i1], _mm_sub_pd(_mm_set1_pd
      (ros_code_B.in2), tmp));
  }

  for (ros_code_B.i_f = ros_code_B.scalarLB_j; ros_code_B.i_f <
       ros_code_B.loop_ub_d; ros_code_B.i_f++) {
    ros_code_B.vectorUB_i = ros_code_B.i_f;
    ros_code_B.in2_data[ros_code_B.vectorUB_i] = ros_code_B.in2 -
      in4_data[ros_code_B.vectorUB_i];
  }

  ros_code_power_en(ros_code_B.in2_data, ros_code_B.in2_size,
                    ros_code_B.tmp_data_g, ros_code_B.tmp_size_i);
  ros_code_B.in2 = in2[in3 + 9];
  ros_code_B.in2_size[0] = 1;
  ros_code_B.in2_size[1] = in5_size[1];
  ros_code_B.loop_ub_d = in5_size[1];
  ros_code_B.scalarLB_j = (in5_size[1] / 2) << 1;

  // End of Outputs for SubSystem: '<Root>/Lattice_planner'
  ros_code_B.vectorUB_i = ros_code_B.scalarLB_j - 2;

  // Outputs for Atomic SubSystem: '<Root>/Lattice_planner'
  // MATLAB Function: '<S3>/reducePath'
  for (ros_code_B.i_f = 0; ros_code_B.i_f <= ros_code_B.vectorUB_i;
       ros_code_B.i_f += 2) {
    ros_code_B.i1 = ros_code_B.i_f;
    tmp = _mm_loadu_pd(&in5_data[ros_code_B.i1]);
    _mm_storeu_pd(&ros_code_B.in2_data[ros_code_B.i1], _mm_sub_pd(_mm_set1_pd
      (ros_code_B.in2), tmp));
  }

  for (ros_code_B.i_f = ros_code_B.scalarLB_j; ros_code_B.i_f <
       ros_code_B.loop_ub_d; ros_code_B.i_f++) {
    ros_code_B.vectorUB_i = ros_code_B.i_f;
    ros_code_B.in2_data[ros_code_B.vectorUB_i] = ros_code_B.in2 -
      in5_data[ros_code_B.vectorUB_i];
  }

  ros_code_power_en(ros_code_B.in2_data, ros_code_B.in2_size,
                    ros_code_B.tmp_data_l, ros_code_B.tmp_size_oy);
  in1_size[0] = 1;
  in1_size[1] = ros_code_B.tmp_size_oy[1] == 1 ? ros_code_B.tmp_size_i[1] :
    ros_code_B.tmp_size_oy[1];
  ros_code_B.scalarLB_j = (ros_code_B.tmp_size_i[1] != 1);
  ros_code_B.vectorUB_i = (ros_code_B.tmp_size_oy[1] != 1);
  ros_code_B.loop_ub_d = ros_code_B.tmp_size_oy[1] == 1 ? ros_code_B.tmp_size_i
    [1] : ros_code_B.tmp_size_oy[1];
  for (ros_code_B.i_f = 0; ros_code_B.i_f < ros_code_B.loop_ub_d; ros_code_B.i_f
       ++) {
    in1_data[ros_code_B.i_f] = ros_code_B.tmp_data_g[ros_code_B.i_f *
      ros_code_B.scalarLB_j] + ros_code_B.tmp_data_l[ros_code_B.i_f *
      ros_code_B.vectorUB_i];
  }

  // End of Outputs for SubSystem: '<Root>/Lattice_planner'
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_wrapToPi_n(real_T *lambda)
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
    if (rtIsNaN(*lambda + 3.1415926535897931)) {
      ros_code_B.varargout_1 = (rtNaN);
    } else if (rtIsInf(*lambda + 3.1415926535897931)) {
      ros_code_B.varargout_1 = (rtNaN);
    } else if (*lambda + 3.1415926535897931 == 0.0) {
      ros_code_B.varargout_1 = 0.0;
    } else {
      boolean_T rEQ0;
      ros_code_B.varargout_1 = fmod(*lambda + 3.1415926535897931,
        6.2831853071795862);
      rEQ0 = (ros_code_B.varargout_1 == 0.0);
      if (!rEQ0) {
        ros_code_B.q = fabs((*lambda + 3.1415926535897931) / 6.2831853071795862);
        rEQ0 = !(fabs(ros_code_B.q - floor(ros_code_B.q + 0.5)) >
                 2.2204460492503131E-16 * ros_code_B.q);
      }

      if (rEQ0) {
        ros_code_B.varargout_1 = 0.0;
      } else if (*lambda + 3.1415926535897931 < 0.0) {
        ros_code_B.varargout_1 += 6.2831853071795862;
      }
    }

    ros_code_B.z1_data = ros_code_B.varargout_1;
  }

  if (trueCount - 1 >= 0) {
    ros_code_B.x_data_b = ros_code_B.z1_data;
  }

  if (trueCount - 1 >= 0) {
    positiveInput_data = ((ros_code_B.z1_data == 0.0) && (*lambda +
      3.1415926535897931 > 0.0));
  }

  if ((trueCount - 1 >= 0) && positiveInput_data) {
    ros_code_B.x_data_b = 6.2831853071795862;
  }

  if (c || d) {
    *lambda = ros_code_B.x_data_b - 3.1415926535897931;
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static real_T ros_code_detectCollision(const real_T ego_corners_x[4], const
  real_T ego_corners_y[4], const real_T object_corners_x[4], const real_T
  object_corners_y[4], real_T s_object)
{
  real_T danger_flag;
  danger_flag = 0.0;
  for (int32_T i = 0; i < 4; i++) {
    if (danger_flag == 0.0) {
      real_T tmp;
      ros_code_B.ego_x = ego_corners_x[i];
      ros_code_B.ego_y = ego_corners_y[i];
      ros_code_B.d_o = object_corners_x[1] - ros_code_B.ego_x;
      ros_code_B.d1 = object_corners_y[1] - ros_code_B.ego_y;
      ros_code_B.d2 = object_corners_x[2] - ros_code_B.ego_x;
      ros_code_B.d3 = object_corners_y[2] - ros_code_B.ego_y;
      ros_code_B.d4 = object_corners_x[3] - ros_code_B.ego_x;
      tmp = object_corners_y[0] - ros_code_B.ego_y;
      ros_code_B.ego_x = object_corners_x[0] - ros_code_B.ego_x;
      ros_code_B.ego_y = object_corners_y[3] - ros_code_B.ego_y;
      if (((fabs(ros_code_B.ego_x * ros_code_B.d1 - ros_code_B.d_o * tmp) * 0.5
            + fabs(ros_code_B.d_o * ros_code_B.d3 - ros_code_B.d2 *
                   ros_code_B.d1) * 0.5) + fabs(ros_code_B.d2 * ros_code_B.ego_y
            - ros_code_B.d4 * ros_code_B.d3) * 0.5) + fabs(ros_code_B.d4 * tmp -
           ros_code_B.ego_x * ros_code_B.ego_y) * 0.5 <= s_object + 0.05) {
        danger_flag = 1.0;
      }
    }
  }

  return danger_flag;
}

// Function for MATLAB Function: '<S3>/reducePath'
static boolean_T ros_code_anyNonFinite(const real_T x_data[], const int32_T
  x_size[2])
{
  int32_T nx;
  boolean_T b_p;
  nx = x_size[0] * x_size[1];
  b_p = true;
  for (int32_T k = 0; k < nx; k++) {
    if (b_p && (rtIsInf(x_data[k]) || rtIsNaN(x_data[k]))) {
      b_p = false;
    }
  }

  return !b_p;
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_sqrt_g(creal_T *x)
{
  real_T absxi;
  if (x->im == 0.0) {
    if (x->re < 0.0) {
      ros_code_B.absxr = 0.0;
      absxi = sqrt(-x->re);
    } else {
      ros_code_B.absxr = sqrt(x->re);
      absxi = 0.0;
    }
  } else if (x->re == 0.0) {
    if (x->im < 0.0) {
      ros_code_B.absxr = sqrt(-x->im / 2.0);
      absxi = -ros_code_B.absxr;
    } else {
      ros_code_B.absxr = sqrt(x->im / 2.0);
      absxi = ros_code_B.absxr;
    }
  } else if (rtIsNaN(x->re)) {
    ros_code_B.absxr = x->re;
    absxi = x->re;
  } else if (rtIsNaN(x->im)) {
    ros_code_B.absxr = x->im;
    absxi = x->im;
  } else if (rtIsInf(x->im)) {
    ros_code_B.absxr = fabs(x->im);
    absxi = x->im;
  } else if (rtIsInf(x->re)) {
    if (x->re < 0.0) {
      ros_code_B.absxr = 0.0;
      absxi = x->im * -x->re;
    } else {
      ros_code_B.absxr = x->re;
      absxi = 0.0;
    }
  } else {
    ros_code_B.absxr = fabs(x->re);
    absxi = fabs(x->im);
    if ((ros_code_B.absxr > 4.4942328371557893E+307) || (absxi >
         4.4942328371557893E+307)) {
      ros_code_B.absxr *= 0.5;
      absxi = ros_code_rt_hypotd_snf(ros_code_B.absxr, absxi * 0.5);
      if (absxi > ros_code_B.absxr) {
        ros_code_B.absxr = sqrt(ros_code_B.absxr / absxi + 1.0) * sqrt(absxi);
      } else {
        ros_code_B.absxr = sqrt(absxi) * 1.4142135623730951;
      }
    } else {
      ros_code_B.absxr = sqrt((ros_code_rt_hypotd_snf(ros_code_B.absxr, absxi) +
        ros_code_B.absxr) * 0.5);
    }

    if (x->re > 0.0) {
      absxi = x->im / ros_code_B.absxr * 0.5;
    } else {
      if (x->im < 0.0) {
        absxi = -ros_code_B.absxr;
      } else {
        absxi = ros_code_B.absxr;
      }

      ros_code_B.absxr = x->im / absxi * 0.5;
    }
  }

  x->re = ros_code_B.absxr;
  x->im = absxi;
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_xzlartg_c(const creal_T f, const creal_T g, real_T *cs,
  creal_T *sn)
{
  real_T gs_im;
  int32_T count;
  boolean_T guard1 = false;
  ros_code_B.d = fabs(f.re);
  ros_code_B.scale_a = ros_code_B.d;
  ros_code_B.f2s_d = fabs(f.im);
  if (ros_code_B.f2s_d > ros_code_B.d) {
    ros_code_B.scale_a = ros_code_B.f2s_d;
  }

  ros_code_B.gs_re_n = fabs(g.re);
  gs_im = fabs(g.im);
  if (gs_im > ros_code_B.gs_re_n) {
    ros_code_B.gs_re_n = gs_im;
  }

  if (ros_code_B.gs_re_n > ros_code_B.scale_a) {
    ros_code_B.scale_a = ros_code_B.gs_re_n;
  }

  ros_code_B.fs_re_m = f.re;
  ros_code_B.fs_im_o = f.im;
  ros_code_B.gs_re_n = g.re;
  gs_im = g.im;
  count = 0;
  guard1 = false;
  if (ros_code_B.scale_a >= 7.4428285367870146E+137) {
    do {
      count++;
      ros_code_B.fs_re_m *= 1.3435752215134178E-138;
      ros_code_B.fs_im_o *= 1.3435752215134178E-138;
      ros_code_B.gs_re_n *= 1.3435752215134178E-138;
      gs_im *= 1.3435752215134178E-138;
      ros_code_B.scale_a *= 1.3435752215134178E-138;
    } while ((ros_code_B.scale_a >= 7.4428285367870146E+137) && (count < 20));

    guard1 = true;
  } else if (ros_code_B.scale_a <= 1.3435752215134178E-138) {
    if (((g.re == 0.0) && (g.im == 0.0)) || (rtIsNaN(g.re) || rtIsNaN(g.im))) {
      *cs = 1.0;
      sn->re = 0.0;
      sn->im = 0.0;
    } else {
      do {
        ros_code_B.fs_re_m *= 7.4428285367870146E+137;
        ros_code_B.fs_im_o *= 7.4428285367870146E+137;
        ros_code_B.gs_re_n *= 7.4428285367870146E+137;
        gs_im *= 7.4428285367870146E+137;
        ros_code_B.scale_a *= 7.4428285367870146E+137;
      } while (ros_code_B.scale_a <= 1.3435752215134178E-138);

      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    ros_code_B.scale_a = ros_code_B.fs_re_m * ros_code_B.fs_re_m +
      ros_code_B.fs_im_o * ros_code_B.fs_im_o;
    ros_code_B.g2_a = ros_code_B.gs_re_n * ros_code_B.gs_re_n + gs_im * gs_im;
    ros_code_B.x_p = ros_code_B.g2_a;
    if (ros_code_B.g2_a < 1.0) {
      ros_code_B.x_p = 1.0;
    }

    if (ros_code_B.scale_a <= ros_code_B.x_p * 2.0041683600089728E-292) {
      if ((f.re == 0.0) && (f.im == 0.0)) {
        *cs = 0.0;
        ros_code_B.d = ros_code_rt_hypotd_snf(ros_code_B.gs_re_n, gs_im);
        sn->re = ros_code_B.gs_re_n / ros_code_B.d;
        sn->im = -gs_im / ros_code_B.d;
      } else {
        ros_code_B.scale_a = sqrt(ros_code_B.g2_a);
        *cs = ros_code_rt_hypotd_snf(ros_code_B.fs_re_m, ros_code_B.fs_im_o) /
          ros_code_B.scale_a;
        if (ros_code_B.f2s_d > ros_code_B.d) {
          ros_code_B.d = ros_code_B.f2s_d;
        }

        if (ros_code_B.d > 1.0) {
          ros_code_B.d = ros_code_rt_hypotd_snf(f.re, f.im);
          ros_code_B.fs_re_m = f.re / ros_code_B.d;
          ros_code_B.fs_im_o = f.im / ros_code_B.d;
        } else {
          ros_code_B.fs_re_m = 7.4428285367870146E+137 * f.re;
          ros_code_B.f2s_d = 7.4428285367870146E+137 * f.im;
          ros_code_B.d = ros_code_rt_hypotd_snf(ros_code_B.fs_re_m,
            ros_code_B.f2s_d);
          ros_code_B.fs_re_m /= ros_code_B.d;
          ros_code_B.fs_im_o = ros_code_B.f2s_d / ros_code_B.d;
        }

        ros_code_B.gs_re_n /= ros_code_B.scale_a;
        gs_im = -gs_im / ros_code_B.scale_a;
        sn->re = ros_code_B.fs_re_m * ros_code_B.gs_re_n - ros_code_B.fs_im_o *
          gs_im;
        sn->im = ros_code_B.fs_re_m * gs_im + ros_code_B.fs_im_o *
          ros_code_B.gs_re_n;
      }
    } else {
      ros_code_B.f2s_d = sqrt(ros_code_B.g2_a / ros_code_B.scale_a + 1.0);
      *cs = 1.0 / ros_code_B.f2s_d;
      ros_code_B.d = ros_code_B.scale_a + ros_code_B.g2_a;
      ros_code_B.fs_re_m = ros_code_B.f2s_d * ros_code_B.fs_re_m / ros_code_B.d;
      ros_code_B.fs_im_o = ros_code_B.f2s_d * ros_code_B.fs_im_o / ros_code_B.d;
      sn->re = ros_code_B.fs_re_m * ros_code_B.gs_re_n - ros_code_B.fs_im_o *
        -gs_im;
      sn->im = ros_code_B.fs_re_m * -gs_im + ros_code_B.fs_im_o *
        ros_code_B.gs_re_n;
    }
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_xzlartg(const creal_T f, const creal_T g, real_T *cs,
  creal_T *sn, creal_T *r)
{
  int32_T count;
  int8_T rescaledir;
  boolean_T guard1 = false;
  ros_code_B.f2s = fabs(f.re);
  ros_code_B.scale_m = ros_code_B.f2s;
  ros_code_B.di = fabs(f.im);
  if (ros_code_B.di > ros_code_B.f2s) {
    ros_code_B.scale_m = ros_code_B.di;
  }

  ros_code_B.gs_re = fabs(g.re);
  ros_code_B.gs_im = fabs(g.im);
  if (ros_code_B.gs_im > ros_code_B.gs_re) {
    ros_code_B.gs_re = ros_code_B.gs_im;
  }

  if (ros_code_B.gs_re > ros_code_B.scale_m) {
    ros_code_B.scale_m = ros_code_B.gs_re;
  }

  ros_code_B.fs_re = f.re;
  ros_code_B.fs_im = f.im;
  ros_code_B.gs_re = g.re;
  ros_code_B.gs_im = g.im;
  count = -1;
  rescaledir = 0;
  guard1 = false;
  if (ros_code_B.scale_m >= 7.4428285367870146E+137) {
    do {
      count++;
      ros_code_B.fs_re *= 1.3435752215134178E-138;
      ros_code_B.fs_im *= 1.3435752215134178E-138;
      ros_code_B.gs_re *= 1.3435752215134178E-138;
      ros_code_B.gs_im *= 1.3435752215134178E-138;
      ros_code_B.scale_m *= 1.3435752215134178E-138;
    } while ((ros_code_B.scale_m >= 7.4428285367870146E+137) && (count + 1 < 20));

    rescaledir = 1;
    guard1 = true;
  } else if (ros_code_B.scale_m <= 1.3435752215134178E-138) {
    if (((g.re == 0.0) && (g.im == 0.0)) || (rtIsNaN(g.re) || rtIsNaN(g.im))) {
      *cs = 1.0;
      sn->re = 0.0;
      sn->im = 0.0;
      *r = f;
    } else {
      do {
        count++;
        ros_code_B.fs_re *= 7.4428285367870146E+137;
        ros_code_B.fs_im *= 7.4428285367870146E+137;
        ros_code_B.gs_re *= 7.4428285367870146E+137;
        ros_code_B.gs_im *= 7.4428285367870146E+137;
        ros_code_B.scale_m *= 7.4428285367870146E+137;
      } while (ros_code_B.scale_m <= 1.3435752215134178E-138);

      rescaledir = -1;
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    ros_code_B.scale_m = ros_code_B.fs_re * ros_code_B.fs_re + ros_code_B.fs_im *
      ros_code_B.fs_im;
    ros_code_B.g2 = ros_code_B.gs_re * ros_code_B.gs_re + ros_code_B.gs_im *
      ros_code_B.gs_im;
    ros_code_B.x_m = ros_code_B.g2;
    if (ros_code_B.g2 < 1.0) {
      ros_code_B.x_m = 1.0;
    }

    if (ros_code_B.scale_m <= ros_code_B.x_m * 2.0041683600089728E-292) {
      if ((f.re == 0.0) && (f.im == 0.0)) {
        *cs = 0.0;
        r->re = ros_code_rt_hypotd_snf(g.re, g.im);
        r->im = 0.0;
        ros_code_B.f2s = ros_code_rt_hypotd_snf(ros_code_B.gs_re,
          ros_code_B.gs_im);
        sn->re = ros_code_B.gs_re / ros_code_B.f2s;
        sn->im = -ros_code_B.gs_im / ros_code_B.f2s;
      } else {
        ros_code_B.scale_m = sqrt(ros_code_B.g2);
        *cs = ros_code_rt_hypotd_snf(ros_code_B.fs_re, ros_code_B.fs_im) /
          ros_code_B.scale_m;
        if (ros_code_B.di > ros_code_B.f2s) {
          ros_code_B.f2s = ros_code_B.di;
        }

        if (ros_code_B.f2s > 1.0) {
          ros_code_B.f2s = ros_code_rt_hypotd_snf(f.re, f.im);
          ros_code_B.fs_re = f.re / ros_code_B.f2s;
          ros_code_B.fs_im = f.im / ros_code_B.f2s;
        } else {
          ros_code_B.fs_re = 7.4428285367870146E+137 * f.re;
          ros_code_B.di = 7.4428285367870146E+137 * f.im;
          ros_code_B.f2s = ros_code_rt_hypotd_snf(ros_code_B.fs_re,
            ros_code_B.di);
          ros_code_B.fs_re /= ros_code_B.f2s;
          ros_code_B.fs_im = ros_code_B.di / ros_code_B.f2s;
        }

        ros_code_B.gs_re /= ros_code_B.scale_m;
        ros_code_B.gs_im = -ros_code_B.gs_im / ros_code_B.scale_m;
        sn->re = ros_code_B.fs_re * ros_code_B.gs_re - ros_code_B.fs_im *
          ros_code_B.gs_im;
        sn->im = ros_code_B.fs_re * ros_code_B.gs_im + ros_code_B.fs_im *
          ros_code_B.gs_re;
        r->re = (sn->re * g.re - sn->im * g.im) + *cs * f.re;
        r->im = (sn->re * g.im + sn->im * g.re) + *cs * f.im;
      }
    } else {
      ros_code_B.f2s = sqrt(ros_code_B.g2 / ros_code_B.scale_m + 1.0);
      r->re = ros_code_B.f2s * ros_code_B.fs_re;
      r->im = ros_code_B.f2s * ros_code_B.fs_im;
      *cs = 1.0 / ros_code_B.f2s;
      ros_code_B.f2s = ros_code_B.scale_m + ros_code_B.g2;
      ros_code_B.fs_re = r->re / ros_code_B.f2s;
      ros_code_B.f2s = r->im / ros_code_B.f2s;
      sn->re = ros_code_B.fs_re * ros_code_B.gs_re - ros_code_B.f2s *
        -ros_code_B.gs_im;
      sn->im = ros_code_B.fs_re * -ros_code_B.gs_im + ros_code_B.f2s *
        ros_code_B.gs_re;
      if (rescaledir > 0) {
        for (int32_T b_i = 0; b_i <= count; b_i++) {
          r->re *= 7.4428285367870146E+137;
          r->im *= 7.4428285367870146E+137;
        }
      } else if (rescaledir < 0) {
        for (int32_T b_i = 0; b_i <= count; b_i++) {
          r->re *= 1.3435752215134178E-138;
          r->im *= 1.3435752215134178E-138;
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_xzhgeqz(const creal_T A_data[], const int32_T A_size[2],
  int32_T ilo, int32_T ihi, int32_T *info, creal_T alpha1_data[], int32_T
  *alpha1_size, creal_T beta1_data[], int32_T *beta1_size)
{
  boolean_T failed;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  ros_code_B.b_A_size_idx_0 = A_size[0];
  ros_code_B.ifirst = A_size[0] * A_size[1];
  if (ros_code_B.ifirst - 1 >= 0) {
    memcpy(&ros_code_B.b_A_data_n[0], &A_data[0], ros_code_B.ifirst * sizeof
           (creal_T));
  }

  *info = 0;
  if ((A_size[0] == 1) && (A_size[1] == 1)) {
    ihi = 1;
  }

  *alpha1_size = A_size[0];
  ros_code_B.ifirst = A_size[0];
  if (ros_code_B.ifirst - 1 >= 0) {
    memset(&alpha1_data[0], 0, ros_code_B.ifirst * sizeof(creal_T));
  }

  *beta1_size = A_size[0];
  ros_code_B.ifirst = A_size[0];
  for (ros_code_B.nm1 = 0; ros_code_B.nm1 < ros_code_B.ifirst; ros_code_B.nm1++)
  {
    beta1_data[ros_code_B.nm1].re = 1.0;
    beta1_data[ros_code_B.nm1].im = 0.0;
  }

  ros_code_B.eshift_re = 0.0;
  ros_code_B.eshift_im = 0.0;
  ros_code_B.ctemp.re = 0.0;
  ros_code_B.ctemp.im = 0.0;
  ros_code_B.anorm = 0.0;
  if (ilo <= ihi) {
    ros_code_B.scale_c = 3.3121686421112381E-170;
    ros_code_B.ssq = 0.0;
    ros_code_B.nm1 = ihi - ilo;
    ros_code_B.ifirst = -1;
    while (ros_code_B.ifirst + 1 <= ros_code_B.nm1) {
      ros_code_B.colscale = 3.3121686421112381E-170;
      ros_code_B.anorm = 0.0;
      ros_code_B.col = ilo + ros_code_B.ifirst;
      if (ros_code_B.ifirst + 2 <= ros_code_B.nm1) {
        ros_code_B.ilastm1 = ros_code_B.ifirst + 2;
      } else {
        ros_code_B.ilastm1 = ros_code_B.nm1;
      }

      ros_code_B.ilastm1 += ilo;
      ros_code_B.ilastm = ilo;
      while (ros_code_B.ilastm <= ros_code_B.ilastm1) {
        ros_code_B.ctemp_tmp_tmp = (A_size[0] * ros_code_B.col +
          ros_code_B.ilastm) - 1;
        ros_code_B.absxk_o = fabs(A_data[ros_code_B.ctemp_tmp_tmp].re);
        if (ros_code_B.absxk_o > ros_code_B.colscale) {
          ros_code_B.t_l = ros_code_B.colscale / ros_code_B.absxk_o;
          ros_code_B.anorm = ros_code_B.anorm * ros_code_B.t_l * ros_code_B.t_l
            + 1.0;
          ros_code_B.colscale = ros_code_B.absxk_o;
        } else {
          ros_code_B.t_l = ros_code_B.absxk_o / ros_code_B.colscale;
          ros_code_B.anorm += ros_code_B.t_l * ros_code_B.t_l;
        }

        ros_code_B.absxk_o = fabs(A_data[ros_code_B.ctemp_tmp_tmp].im);
        if (ros_code_B.absxk_o > ros_code_B.colscale) {
          ros_code_B.t_l = ros_code_B.colscale / ros_code_B.absxk_o;
          ros_code_B.anorm = ros_code_B.anorm * ros_code_B.t_l * ros_code_B.t_l
            + 1.0;
          ros_code_B.colscale = ros_code_B.absxk_o;
        } else {
          ros_code_B.t_l = ros_code_B.absxk_o / ros_code_B.colscale;
          ros_code_B.anorm += ros_code_B.t_l * ros_code_B.t_l;
        }

        ros_code_B.ilastm++;
      }

      if (ros_code_B.scale_c >= ros_code_B.colscale) {
        ros_code_B.colscale /= ros_code_B.scale_c;
        ros_code_B.ssq += ros_code_B.colscale * ros_code_B.colscale *
          ros_code_B.anorm;
      } else {
        ros_code_B.scale_c /= ros_code_B.colscale;
        ros_code_B.ssq = ros_code_B.scale_c * ros_code_B.scale_c *
          ros_code_B.ssq + ros_code_B.anorm;
        ros_code_B.scale_c = ros_code_B.colscale;
      }

      ros_code_B.ifirst++;
    }

    ros_code_B.anorm = ros_code_B.scale_c * sqrt(ros_code_B.ssq);
  }

  ros_code_B.ssq = 2.2250738585072014E-308;
  ros_code_B.scale_c = 2.2204460492503131E-16 * ros_code_B.anorm;
  if (ros_code_B.scale_c > 2.2250738585072014E-308) {
    ros_code_B.ssq = ros_code_B.scale_c;
  }

  ros_code_B.scale_c = 2.2250738585072014E-308;
  if (ros_code_B.anorm > 2.2250738585072014E-308) {
    ros_code_B.scale_c = ros_code_B.anorm;
  }

  ros_code_B.anorm = 1.0 / ros_code_B.scale_c;
  ros_code_B.scale_c = 1.0 / sqrt(static_cast<real_T>(A_size[0]));
  failed = true;
  ros_code_B.nm1 = ihi;
  while (ros_code_B.nm1 + 1 <= A_size[0]) {
    alpha1_data[ros_code_B.nm1] = A_data[A_size[0] * ros_code_B.nm1 +
      ros_code_B.nm1];
    ros_code_B.nm1++;
  }

  guard1 = false;
  guard2 = false;
  if (ihi >= ilo) {
    boolean_T goto60;
    boolean_T goto70;
    boolean_T goto90;
    ros_code_B.ifirst = ilo;
    ros_code_B.col = ilo;
    ros_code_B.nm1 = ihi - 1;
    ros_code_B.ilastm1 = ihi - 2;
    ros_code_B.ilastm = ihi;
    ros_code_B.iiter = 0;
    goto60 = false;
    goto70 = false;
    goto90 = false;
    ros_code_B.jiter = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (ros_code_B.jiter <= ((ihi - ilo) + 1) * 30 - 1) {
        boolean_T exitg2;
        if (ros_code_B.nm1 + 1 == ilo) {
          goto60 = true;
        } else {
          ros_code_B.jp1 = ros_code_B.b_A_size_idx_0 * ros_code_B.ilastm1 +
            ros_code_B.nm1;
          if (fabs(ros_code_B.b_A_data_n[ros_code_B.jp1].re) + fabs
              (ros_code_B.b_A_data_n[ros_code_B.jp1].im) <= ros_code_B.ssq) {
            ros_code_B.b_A_data_n[ros_code_B.jp1].re = 0.0;
            ros_code_B.b_A_data_n[ros_code_B.jp1].im = 0.0;
            goto60 = true;
          } else {
            boolean_T guard3 = false;
            ros_code_B.j_i = ros_code_B.ilastm1;
            guard3 = false;
            exitg2 = false;
            while ((!exitg2) && (ros_code_B.j_i + 1 >= ilo)) {
              if (ros_code_B.j_i + 1 == ilo) {
                guard3 = true;
                exitg2 = true;
              } else {
                ros_code_B.jp1 = (ros_code_B.j_i - 1) *
                  ros_code_B.b_A_size_idx_0 + ros_code_B.j_i;
                if (fabs(ros_code_B.b_A_data_n[ros_code_B.jp1].re) + fabs
                    (ros_code_B.b_A_data_n[ros_code_B.jp1].im) <= ros_code_B.ssq)
                {
                  ros_code_B.b_A_data_n[ros_code_B.jp1].re = 0.0;
                  ros_code_B.b_A_data_n[ros_code_B.jp1].im = 0.0;
                  guard3 = true;
                  exitg2 = true;
                } else {
                  ros_code_B.j_i--;
                  guard3 = false;
                }
              }
            }

            if (guard3) {
              ros_code_B.ifirst = ros_code_B.j_i + 1;
              goto70 = true;
            }
          }
        }

        if ((!goto60) && (!goto70)) {
          ros_code_B.ifirst = *alpha1_size;
          for (ros_code_B.nm1 = 0; ros_code_B.nm1 < ros_code_B.ifirst;
               ros_code_B.nm1++) {
            alpha1_data[ros_code_B.nm1].re = (rtNaN);
            alpha1_data[ros_code_B.nm1].im = 0.0;
          }

          ros_code_B.ifirst = *beta1_size;
          for (ros_code_B.nm1 = 0; ros_code_B.nm1 < ros_code_B.ifirst;
               ros_code_B.nm1++) {
            beta1_data[ros_code_B.nm1].re = (rtNaN);
            beta1_data[ros_code_B.nm1].im = 0.0;
          }

          *info = 1;
          exitg1 = 1;
        } else if (goto60) {
          goto60 = false;
          alpha1_data[ros_code_B.nm1] =
            ros_code_B.b_A_data_n[ros_code_B.b_A_size_idx_0 * ros_code_B.nm1 +
            ros_code_B.nm1];
          ros_code_B.nm1 = ros_code_B.ilastm1;
          ros_code_B.ilastm1--;
          if (ros_code_B.nm1 + 1 < ilo) {
            failed = false;
            guard2 = true;
            exitg1 = 1;
          } else {
            ros_code_B.iiter = 0;
            ros_code_B.eshift_re = 0.0;
            ros_code_B.eshift_im = 0.0;
            ros_code_B.ilastm = ros_code_B.nm1 + 1;
            ros_code_B.jiter++;
          }
        } else {
          if (goto70) {
            goto70 = false;
            ros_code_B.iiter++;
            if (ros_code_B.iiter - ros_code_B.iiter / 10 * 10 != 0) {
              ros_code_B.j_i = ros_code_B.b_A_size_idx_0 * ros_code_B.ilastm1 +
                ros_code_B.ilastm1;
              ros_code_B.ar = ros_code_B.anorm *
                ros_code_B.b_A_data_n[ros_code_B.j_i].re;
              ros_code_B.ai = ros_code_B.anorm *
                ros_code_B.b_A_data_n[ros_code_B.j_i].im;
              if (ros_code_B.ai == 0.0) {
                ros_code_B.shift.re = ros_code_B.ar / ros_code_B.scale_c;
                ros_code_B.shift.im = 0.0;
              } else if (ros_code_B.ar == 0.0) {
                ros_code_B.shift.re = 0.0;
                ros_code_B.shift.im = ros_code_B.ai / ros_code_B.scale_c;
              } else {
                ros_code_B.shift.re = ros_code_B.ar / ros_code_B.scale_c;
                ros_code_B.shift.im = ros_code_B.ai / ros_code_B.scale_c;
              }

              ros_code_B.j_i = ros_code_B.b_A_size_idx_0 * ros_code_B.nm1 +
                ros_code_B.nm1;
              ros_code_B.ar = ros_code_B.anorm *
                ros_code_B.b_A_data_n[ros_code_B.j_i].re;
              ros_code_B.ai = ros_code_B.anorm *
                ros_code_B.b_A_data_n[ros_code_B.j_i].im;
              if (ros_code_B.ai == 0.0) {
                ros_code_B.t_l = ros_code_B.ar / ros_code_B.scale_c;
                ros_code_B.ad22_im = 0.0;
              } else if (ros_code_B.ar == 0.0) {
                ros_code_B.t_l = 0.0;
                ros_code_B.ad22_im = ros_code_B.ai / ros_code_B.scale_c;
              } else {
                ros_code_B.t_l = ros_code_B.ar / ros_code_B.scale_c;
                ros_code_B.ad22_im = ros_code_B.ai / ros_code_B.scale_c;
              }

              ros_code_B.t1_re = (ros_code_B.shift.re + ros_code_B.t_l) * 0.5;
              ros_code_B.t1_im = (ros_code_B.shift.im + ros_code_B.ad22_im) *
                0.5;
              ros_code_B.j_i = ros_code_B.b_A_size_idx_0 * ros_code_B.nm1 +
                ros_code_B.ilastm1;
              ros_code_B.ar = ros_code_B.anorm *
                ros_code_B.b_A_data_n[ros_code_B.j_i].re;
              ros_code_B.ai = ros_code_B.anorm *
                ros_code_B.b_A_data_n[ros_code_B.j_i].im;
              if (ros_code_B.ai == 0.0) {
                ros_code_B.colscale = ros_code_B.ar / ros_code_B.scale_c;
                ros_code_B.absxk_o = 0.0;
              } else if (ros_code_B.ar == 0.0) {
                ros_code_B.colscale = 0.0;
                ros_code_B.absxk_o = ros_code_B.ai / ros_code_B.scale_c;
              } else {
                ros_code_B.colscale = ros_code_B.ar / ros_code_B.scale_c;
                ros_code_B.absxk_o = ros_code_B.ai / ros_code_B.scale_c;
              }

              ros_code_B.j_i = ros_code_B.b_A_size_idx_0 * ros_code_B.ilastm1 +
                ros_code_B.nm1;
              ros_code_B.ar = ros_code_B.anorm *
                ros_code_B.b_A_data_n[ros_code_B.j_i].re;
              ros_code_B.ai = ros_code_B.anorm *
                ros_code_B.b_A_data_n[ros_code_B.j_i].im;
              if (ros_code_B.ai == 0.0) {
                ros_code_B.ar /= ros_code_B.scale_c;
                ros_code_B.ai = 0.0;
              } else if (ros_code_B.ar == 0.0) {
                ros_code_B.ar = 0.0;
                ros_code_B.ai /= ros_code_B.scale_c;
              } else {
                ros_code_B.ar /= ros_code_B.scale_c;
                ros_code_B.ai /= ros_code_B.scale_c;
              }

              ros_code_B.shift_im = ros_code_B.shift.re * ros_code_B.ad22_im +
                ros_code_B.shift.im * ros_code_B.t_l;
              ros_code_B.shift.re = ((ros_code_B.t1_re * ros_code_B.t1_re -
                ros_code_B.t1_im * ros_code_B.t1_im) + (ros_code_B.colscale *
                ros_code_B.ar - ros_code_B.absxk_o * ros_code_B.ai)) -
                (ros_code_B.shift.re * ros_code_B.t_l - ros_code_B.shift.im *
                 ros_code_B.ad22_im);
              ros_code_B.shift_tmp = ros_code_B.t1_re * ros_code_B.t1_im;
              ros_code_B.shift.im = ((ros_code_B.colscale * ros_code_B.ai +
                ros_code_B.absxk_o * ros_code_B.ar) + (ros_code_B.shift_tmp +
                ros_code_B.shift_tmp)) - ros_code_B.shift_im;
              ros_code_sqrt_g(&ros_code_B.shift);
              if ((ros_code_B.t1_re - ros_code_B.t_l) * ros_code_B.shift.re +
                  (ros_code_B.t1_im - ros_code_B.ad22_im) * ros_code_B.shift.im <=
                  0.0) {
                ros_code_B.shift.re += ros_code_B.t1_re;
                ros_code_B.shift.im += ros_code_B.t1_im;
              } else {
                ros_code_B.shift.re = ros_code_B.t1_re - ros_code_B.shift.re;
                ros_code_B.shift.im = ros_code_B.t1_im - ros_code_B.shift.im;
              }
            } else {
              ros_code_B.j_i = ros_code_B.b_A_size_idx_0 * ros_code_B.ilastm1 +
                ros_code_B.nm1;
              ros_code_B.ar = ros_code_B.anorm *
                ros_code_B.b_A_data_n[ros_code_B.j_i].re;
              ros_code_B.ai = ros_code_B.anorm *
                ros_code_B.b_A_data_n[ros_code_B.j_i].im;
              if (ros_code_B.ai == 0.0) {
                ros_code_B.colscale = ros_code_B.ar / ros_code_B.scale_c;
                ros_code_B.absxk_o = 0.0;
              } else if (ros_code_B.ar == 0.0) {
                ros_code_B.colscale = 0.0;
                ros_code_B.absxk_o = ros_code_B.ai / ros_code_B.scale_c;
              } else {
                ros_code_B.colscale = ros_code_B.ar / ros_code_B.scale_c;
                ros_code_B.absxk_o = ros_code_B.ai / ros_code_B.scale_c;
              }

              ros_code_B.eshift_re += ros_code_B.colscale;
              ros_code_B.eshift_im += ros_code_B.absxk_o;
              ros_code_B.shift.re = ros_code_B.eshift_re;
              ros_code_B.shift.im = ros_code_B.eshift_im;
            }

            ros_code_B.j_i = ros_code_B.ilastm1;
            ros_code_B.jp1 = ros_code_B.ilastm1 + 1;
            exitg2 = false;
            while ((!exitg2) && (ros_code_B.j_i + 1 > ros_code_B.ifirst)) {
              ros_code_B.col = ros_code_B.j_i + 1;
              ros_code_B.ctemp_tmp_tmp = ros_code_B.b_A_size_idx_0 *
                ros_code_B.j_i;
              ros_code_B.ctemp_tmp = ros_code_B.j_i + ros_code_B.ctemp_tmp_tmp;
              ros_code_B.ctemp.re = ros_code_B.anorm *
                ros_code_B.b_A_data_n[ros_code_B.ctemp_tmp].re -
                ros_code_B.shift.re * ros_code_B.scale_c;
              ros_code_B.ctemp.im = ros_code_B.anorm *
                ros_code_B.b_A_data_n[ros_code_B.ctemp_tmp].im -
                ros_code_B.shift.im * ros_code_B.scale_c;
              ros_code_B.colscale = fabs(ros_code_B.ctemp.re) + fabs
                (ros_code_B.ctemp.im);
              ros_code_B.ctemp_tmp_tmp += ros_code_B.jp1;
              ros_code_B.absxk_o = (fabs
                                    (ros_code_B.b_A_data_n[ros_code_B.ctemp_tmp_tmp]
                .re) + fabs(ros_code_B.b_A_data_n[ros_code_B.ctemp_tmp_tmp].im))
                * ros_code_B.anorm;
              ros_code_B.t_l = ros_code_B.colscale;
              if (ros_code_B.absxk_o > ros_code_B.colscale) {
                ros_code_B.t_l = ros_code_B.absxk_o;
              }

              if ((ros_code_B.t_l < 1.0) && (ros_code_B.t_l != 0.0)) {
                ros_code_B.colscale /= ros_code_B.t_l;
                ros_code_B.absxk_o /= ros_code_B.t_l;
              }

              ros_code_B.jp1 = (ros_code_B.j_i - 1) * ros_code_B.b_A_size_idx_0
                + ros_code_B.j_i;
              if ((fabs(ros_code_B.b_A_data_n[ros_code_B.jp1].re) + fabs
                   (ros_code_B.b_A_data_n[ros_code_B.jp1].im)) *
                  ros_code_B.absxk_o <= ros_code_B.colscale * ros_code_B.ssq) {
                goto90 = true;
                exitg2 = true;
              } else {
                ros_code_B.jp1 = ros_code_B.j_i;
                ros_code_B.j_i--;
              }
            }

            if (!goto90) {
              ros_code_B.col = ros_code_B.ifirst;
              ros_code_B.ctemp_tmp = ((ros_code_B.ifirst - 1) *
                ros_code_B.b_A_size_idx_0 + ros_code_B.ifirst) - 1;
              ros_code_B.ctemp.re = ros_code_B.b_A_data_n[ros_code_B.ctemp_tmp].
                re * ros_code_B.anorm - ros_code_B.shift.re * ros_code_B.scale_c;
              ros_code_B.ctemp.im = ros_code_B.b_A_data_n[ros_code_B.ctemp_tmp].
                im * ros_code_B.anorm - ros_code_B.shift.im * ros_code_B.scale_c;
            }

            goto90 = false;
            ros_code_B.j_i = (ros_code_B.col - 1) * ros_code_B.b_A_size_idx_0 +
              ros_code_B.col;
            ros_code_B.ascale.re = ros_code_B.b_A_data_n[ros_code_B.j_i].re *
              ros_code_B.anorm;
            ros_code_B.ascale.im = ros_code_B.b_A_data_n[ros_code_B.j_i].im *
              ros_code_B.anorm;
            ros_code_xzlartg_c(ros_code_B.ctemp, ros_code_B.ascale,
                               &ros_code_B.colscale, &ros_code_B.shift);
            ros_code_B.j_i = ros_code_B.col;
            ros_code_B.jp1 = ros_code_B.col - 2;
            while (ros_code_B.j_i < ros_code_B.nm1 + 1) {
              if (ros_code_B.j_i > ros_code_B.col) {
                ros_code_xzlartg(ros_code_B.b_A_data_n[1 +
                                 ros_code_B.b_A_size_idx_0 * ros_code_B.jp1],
                                 ros_code_B.b_A_data_n[ros_code_B.j_i +
                                 ros_code_B.b_A_size_idx_0 * ros_code_B.jp1],
                                 &ros_code_B.colscale, &ros_code_B.shift,
                                 &ros_code_B.b_A_data_n[1 +
                                 ros_code_B.b_A_size_idx_0 * ros_code_B.jp1]);
                ros_code_B.jp1 = ros_code_B.b_A_size_idx_0 * ros_code_B.jp1 +
                  ros_code_B.j_i;
                ros_code_B.b_A_data_n[ros_code_B.jp1].re = 0.0;
                ros_code_B.b_A_data_n[ros_code_B.jp1].im = 0.0;
              }

              ros_code_B.jp1 = ros_code_B.j_i - 1;
              while (ros_code_B.jp1 + 1 <= ros_code_B.ilastm) {
                ros_code_B.ctemp_tmp = ros_code_B.b_A_size_idx_0 *
                  ros_code_B.jp1;
                ros_code_B.ctemp_tmp_tmp = ros_code_B.j_i + ros_code_B.ctemp_tmp;
                ros_code_B.absxk_o =
                  ros_code_B.b_A_data_n[ros_code_B.ctemp_tmp_tmp].im;
                ros_code_B.t_l = ros_code_B.b_A_data_n[ros_code_B.ctemp_tmp_tmp]
                  .re;
                ros_code_B.ad22_im_tmp = (ros_code_B.j_i + ros_code_B.ctemp_tmp)
                  - 1;
                ros_code_B.ad22_im =
                  ros_code_B.b_A_data_n[ros_code_B.ad22_im_tmp].re;
                ros_code_B.t1_re = ros_code_B.b_A_data_n[ros_code_B.ad22_im_tmp]
                  .im;
                ros_code_B.b_A_data_n[ros_code_B.ctemp_tmp_tmp].re =
                  ros_code_B.colscale * ros_code_B.t_l - (ros_code_B.ad22_im *
                  ros_code_B.shift.re + ros_code_B.t1_re * ros_code_B.shift.im);
                ros_code_B.b_A_data_n[ros_code_B.ctemp_tmp_tmp].im =
                  ros_code_B.colscale * ros_code_B.absxk_o - (ros_code_B.t1_re *
                  ros_code_B.shift.re - ros_code_B.shift.im * ros_code_B.ad22_im);
                ros_code_B.b_A_data_n[ros_code_B.ad22_im_tmp].re =
                  (ros_code_B.shift.re * ros_code_B.t_l - ros_code_B.shift.im *
                   ros_code_B.absxk_o) + ros_code_B.ad22_im *
                  ros_code_B.colscale;
                ros_code_B.b_A_data_n[ros_code_B.ad22_im_tmp].im =
                  (ros_code_B.shift.re * ros_code_B.absxk_o +
                   ros_code_B.shift.im * ros_code_B.t_l) + ros_code_B.t1_re *
                  ros_code_B.colscale;
                ros_code_B.jp1++;
              }

              ros_code_B.shift.re = -ros_code_B.shift.re;
              ros_code_B.shift.im = -ros_code_B.shift.im;
              ros_code_B.jp1 = ros_code_B.j_i;
              if (ros_code_B.nm1 + 1 < ros_code_B.j_i + 2) {
                ros_code_B.jp1 = ros_code_B.nm1 - 1;
              }

              ros_code_B.ctemp_tmp = ros_code_B.ifirst - 1;
              while (ros_code_B.ctemp_tmp + 1 <= ros_code_B.jp1 + 2) {
                ros_code_B.ctemp_tmp_tmp = (ros_code_B.j_i - 1) *
                  ros_code_B.b_A_size_idx_0 + ros_code_B.ctemp_tmp;
                ros_code_B.absxk_o =
                  ros_code_B.b_A_data_n[ros_code_B.ctemp_tmp_tmp].im;
                ros_code_B.t_l = ros_code_B.b_A_data_n[ros_code_B.ctemp_tmp_tmp]
                  .re;
                ros_code_B.ad22_im_tmp = ros_code_B.b_A_size_idx_0 *
                  ros_code_B.j_i + ros_code_B.ctemp_tmp;
                ros_code_B.ad22_im =
                  ros_code_B.b_A_data_n[ros_code_B.ad22_im_tmp].re;
                ros_code_B.t1_re = ros_code_B.b_A_data_n[ros_code_B.ad22_im_tmp]
                  .im;
                ros_code_B.b_A_data_n[ros_code_B.ctemp_tmp_tmp].re =
                  ros_code_B.t_l * ros_code_B.colscale - (ros_code_B.shift.re *
                  ros_code_B.ad22_im + ros_code_B.shift.im * ros_code_B.t1_re);
                ros_code_B.b_A_data_n[ros_code_B.ctemp_tmp_tmp].im =
                  ros_code_B.absxk_o * ros_code_B.colscale -
                  (ros_code_B.shift.re * ros_code_B.t1_re - ros_code_B.shift.im *
                   ros_code_B.ad22_im);
                ros_code_B.b_A_data_n[ros_code_B.ad22_im_tmp].re =
                  (ros_code_B.t_l * ros_code_B.shift.re - ros_code_B.absxk_o *
                   ros_code_B.shift.im) + ros_code_B.colscale *
                  ros_code_B.ad22_im;
                ros_code_B.b_A_data_n[ros_code_B.ad22_im_tmp].im =
                  (ros_code_B.absxk_o * ros_code_B.shift.re + ros_code_B.t_l *
                   ros_code_B.shift.im) + ros_code_B.colscale * ros_code_B.t1_re;
                ros_code_B.ctemp_tmp++;
              }

              ros_code_B.jp1 = ros_code_B.j_i - 1;
              ros_code_B.j_i++;
            }
          }

          ros_code_B.jiter++;
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
      *info = ros_code_B.nm1 + 1;
      ros_code_B.ifirst = 0;
      while (ros_code_B.ifirst <= ros_code_B.nm1) {
        alpha1_data[ros_code_B.ifirst].re = (rtNaN);
        alpha1_data[ros_code_B.ifirst].im = 0.0;
        beta1_data[ros_code_B.ifirst].re = (rtNaN);
        beta1_data[ros_code_B.ifirst].im = 0.0;
        ros_code_B.ifirst++;
      }
    } else {
      guard1 = true;
    }
  }

  if (guard1) {
    ros_code_B.nm1 = 0;
    while (ros_code_B.nm1 <= ilo - 2) {
      alpha1_data[ros_code_B.nm1] =
        ros_code_B.b_A_data_n[ros_code_B.b_A_size_idx_0 * ros_code_B.nm1 +
        ros_code_B.nm1];
      ros_code_B.nm1++;
    }
  }
}

static void ros_code_rdivide(creal_T in1_data[], int32_T *in1_size, const
  creal_T in2_data[], const int32_T *in2_size)
{
  int32_T in1_size_idx_0;
  int32_T loop_ub;
  in1_size_idx_0 = *in2_size == 1 ? *in1_size : *in2_size;
  ros_code_B.stride_0_0 = (*in1_size != 1);
  ros_code_B.stride_1_0 = (*in2_size != 1);
  loop_ub = *in2_size == 1 ? *in1_size : *in2_size;
  for (ros_code_B.i6 = 0; ros_code_B.i6 < loop_ub; ros_code_B.i6++) {
    int32_T ar_tmp;
    ar_tmp = ros_code_B.i6 * ros_code_B.stride_0_0;
    ros_code_B.ar_m = in1_data[ar_tmp].re;
    ros_code_B.ai_m = in1_data[ar_tmp].im;
    ar_tmp = ros_code_B.i6 * ros_code_B.stride_1_0;
    ros_code_B.br = in2_data[ar_tmp].re;
    ros_code_B.bi = in2_data[ar_tmp].im;
    if (ros_code_B.bi == 0.0) {
      if (ros_code_B.ai_m == 0.0) {
        ros_code_B.in1_data_d[ros_code_B.i6].re = ros_code_B.ar_m /
          ros_code_B.br;
        ros_code_B.in1_data_d[ros_code_B.i6].im = 0.0;
      } else if (ros_code_B.ar_m == 0.0) {
        ros_code_B.in1_data_d[ros_code_B.i6].re = 0.0;
        ros_code_B.in1_data_d[ros_code_B.i6].im = ros_code_B.ai_m /
          ros_code_B.br;
      } else {
        ros_code_B.in1_data_d[ros_code_B.i6].re = ros_code_B.ar_m /
          ros_code_B.br;
        ros_code_B.in1_data_d[ros_code_B.i6].im = ros_code_B.ai_m /
          ros_code_B.br;
      }
    } else if (ros_code_B.br == 0.0) {
      if (ros_code_B.ar_m == 0.0) {
        ros_code_B.in1_data_d[ros_code_B.i6].re = ros_code_B.ai_m /
          ros_code_B.bi;
        ros_code_B.in1_data_d[ros_code_B.i6].im = 0.0;
      } else if (ros_code_B.ai_m == 0.0) {
        ros_code_B.in1_data_d[ros_code_B.i6].re = 0.0;
        ros_code_B.in1_data_d[ros_code_B.i6].im = -(ros_code_B.ar_m /
          ros_code_B.bi);
      } else {
        ros_code_B.in1_data_d[ros_code_B.i6].re = ros_code_B.ai_m /
          ros_code_B.bi;
        ros_code_B.in1_data_d[ros_code_B.i6].im = -(ros_code_B.ar_m /
          ros_code_B.bi);
      }
    } else {
      ros_code_B.brm = fabs(ros_code_B.br);
      ros_code_B.bim = fabs(ros_code_B.bi);
      if (ros_code_B.brm > ros_code_B.bim) {
        ros_code_B.brm = ros_code_B.bi / ros_code_B.br;
        ros_code_B.bi = ros_code_B.brm * ros_code_B.bi + ros_code_B.br;
        ros_code_B.in1_data_d[ros_code_B.i6].re = (ros_code_B.brm *
          ros_code_B.ai_m + ros_code_B.ar_m) / ros_code_B.bi;
        ros_code_B.in1_data_d[ros_code_B.i6].im = (ros_code_B.ai_m -
          ros_code_B.brm * ros_code_B.ar_m) / ros_code_B.bi;
      } else if (ros_code_B.bim == ros_code_B.brm) {
        ros_code_B.br = ros_code_B.br > 0.0 ? 0.5 : -0.5;
        ros_code_B.bi = ros_code_B.bi > 0.0 ? 0.5 : -0.5;
        ros_code_B.in1_data_d[ros_code_B.i6].re = (ros_code_B.ar_m *
          ros_code_B.br + ros_code_B.ai_m * ros_code_B.bi) / ros_code_B.brm;
        ros_code_B.in1_data_d[ros_code_B.i6].im = (ros_code_B.ai_m *
          ros_code_B.br - ros_code_B.ar_m * ros_code_B.bi) / ros_code_B.brm;
      } else {
        ros_code_B.brm = ros_code_B.br / ros_code_B.bi;
        ros_code_B.bi += ros_code_B.brm * ros_code_B.br;
        ros_code_B.in1_data_d[ros_code_B.i6].re = (ros_code_B.brm *
          ros_code_B.ar_m + ros_code_B.ai_m) / ros_code_B.bi;
        ros_code_B.in1_data_d[ros_code_B.i6].im = (ros_code_B.brm *
          ros_code_B.ai_m - ros_code_B.ar_m) / ros_code_B.bi;
      }
    }
  }

  *in1_size = in1_size_idx_0;
  if (in1_size_idx_0 - 1 >= 0) {
    memcpy(&in1_data[0], &ros_code_B.in1_data_d[0], in1_size_idx_0 * sizeof
           (creal_T));
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_eigStandard(const real_T A_data[], const int32_T A_size[2],
  creal_T V_data[], int32_T *V_size)
{
  boolean_T exitg1;
  ros_code_B.At_size[0] = A_size[0];
  ros_code_B.At_size[1] = A_size[1];
  ros_code_B.ii_b = A_size[0] * A_size[1];
  for (ros_code_B.nzcount = 0; ros_code_B.nzcount < ros_code_B.ii_b;
       ros_code_B.nzcount++) {
    ros_code_B.At_data[ros_code_B.nzcount].re = A_data[ros_code_B.nzcount];
    ros_code_B.At_data[ros_code_B.nzcount].im = 0.0;
  }

  ros_code_B.anrm = 0.0;
  ros_code_B.b_tmp = A_size[0] * A_size[1];
  ros_code_B.k_c = 0;
  exitg1 = false;
  while ((!exitg1) && (ros_code_B.k_c <= ros_code_B.b_tmp - 1)) {
    ros_code_B.absxk_g = ros_code_rt_hypotd_snf
      (ros_code_B.At_data[ros_code_B.k_c].re, ros_code_B.At_data[ros_code_B.k_c]
       .im);
    if (rtIsNaN(ros_code_B.absxk_g)) {
      ros_code_B.anrm = (rtNaN);
      exitg1 = true;
    } else {
      if (ros_code_B.absxk_g > ros_code_B.anrm) {
        ros_code_B.anrm = ros_code_B.absxk_g;
      }

      ros_code_B.k_c++;
    }
  }

  if (rtIsInf(ros_code_B.anrm) || rtIsNaN(ros_code_B.anrm)) {
    *V_size = A_size[0];
    ros_code_B.ii_b = A_size[0];
    for (ros_code_B.nzcount = 0; ros_code_B.nzcount < ros_code_B.ii_b;
         ros_code_B.nzcount++) {
      V_data[ros_code_B.nzcount].re = (rtNaN);
      V_data[ros_code_B.nzcount].im = 0.0;
    }

    ros_code_B.y_size_d = A_size[0];
    ros_code_B.ii_b = A_size[0];
    for (ros_code_B.nzcount = 0; ros_code_B.nzcount < ros_code_B.ii_b;
         ros_code_B.nzcount++) {
      ros_code_B.y_data_bn[ros_code_B.nzcount].re = (rtNaN);
      ros_code_B.y_data_bn[ros_code_B.nzcount].im = 0.0;
    }
  } else {
    boolean_T guard1 = false;
    boolean_T ilascl;
    boolean_T notdone;
    ilascl = false;
    ros_code_B.absxk_g = ros_code_B.anrm;
    guard1 = false;
    if ((ros_code_B.anrm > 0.0) && (ros_code_B.anrm < 6.7178761075670888E-139))
    {
      ros_code_B.absxk_g = 6.7178761075670888E-139;
      ilascl = true;
      guard1 = true;
    } else if (ros_code_B.anrm > 1.4885657073574029E+138) {
      ros_code_B.absxk_g = 1.4885657073574029E+138;
      ilascl = true;
      guard1 = true;
    }

    if (guard1) {
      ros_code_B.cfromc = ros_code_B.anrm;
      ros_code_B.ctoc = ros_code_B.absxk_g;
      notdone = true;
      while (notdone) {
        ros_code_B.cfrom1 = ros_code_B.cfromc * 2.0041683600089728E-292;
        ros_code_B.cto1 = ros_code_B.ctoc / 4.9896007738368E+291;
        if ((ros_code_B.cfrom1 > ros_code_B.ctoc) && (ros_code_B.ctoc != 0.0)) {
          ros_code_B.stemp_im_tmp = 2.0041683600089728E-292;
          ros_code_B.cfromc = ros_code_B.cfrom1;
        } else if (ros_code_B.cto1 > ros_code_B.cfromc) {
          ros_code_B.stemp_im_tmp = 4.9896007738368E+291;
          ros_code_B.ctoc = ros_code_B.cto1;
        } else {
          ros_code_B.stemp_im_tmp = ros_code_B.ctoc / ros_code_B.cfromc;
          notdone = false;
        }

        for (ros_code_B.nzcount = 0; ros_code_B.nzcount < ros_code_B.b_tmp;
             ros_code_B.nzcount++) {
          ros_code_B.At_data[ros_code_B.nzcount].re *= ros_code_B.stemp_im_tmp;
          ros_code_B.At_data[ros_code_B.nzcount].im *= ros_code_B.stemp_im_tmp;
        }
      }
    }

    ros_code_B.b_tmp = 1;
    ros_code_B.k_c = A_size[0];
    if (A_size[0] <= 1) {
      ros_code_B.k_c = 1;
    } else {
      int32_T exitg3;
      boolean_T exitg4;
      do {
        exitg3 = 0;
        ros_code_B.At = 0;
        ros_code_B.n_e = 0;
        notdone = false;
        ros_code_B.ii_b = ros_code_B.k_c;
        exitg1 = false;
        while ((!exitg1) && (ros_code_B.ii_b > 0)) {
          ros_code_B.nzcount = 0;
          ros_code_B.At = ros_code_B.ii_b;
          ros_code_B.n_e = ros_code_B.k_c;
          ros_code_B.jj = 0;
          exitg4 = false;
          while ((!exitg4) && (ros_code_B.jj <= ros_code_B.k_c - 1)) {
            ros_code_B.b_A_size_idx_1 = (ros_code_B.At_size[0] * ros_code_B.jj +
              ros_code_B.ii_b) - 1;
            if ((ros_code_B.At_data[ros_code_B.b_A_size_idx_1].re != 0.0) ||
                (ros_code_B.At_data[ros_code_B.b_A_size_idx_1].im != 0.0) ||
                (ros_code_B.jj + 1 == ros_code_B.ii_b)) {
              if (ros_code_B.nzcount == 0) {
                ros_code_B.n_e = ros_code_B.jj + 1;
                ros_code_B.nzcount = 1;
                ros_code_B.jj++;
              } else {
                ros_code_B.nzcount = 2;
                exitg4 = true;
              }
            } else {
              ros_code_B.jj++;
            }
          }

          if (ros_code_B.nzcount < 2) {
            notdone = true;
            exitg1 = true;
          } else {
            ros_code_B.ii_b--;
          }
        }

        if (!notdone) {
          exitg3 = 2;
        } else {
          ros_code_B.nzcount = ros_code_B.At_size[0];
          ros_code_B.b_A_size_idx_1 = ros_code_B.At_size[1];
          ros_code_B.ii_b = ros_code_B.At_size[0] * ros_code_B.At_size[1];
          if (ros_code_B.ii_b - 1 >= 0) {
            memcpy(&ros_code_B.b_A_data[0], &ros_code_B.At_data[0],
                   ros_code_B.ii_b * sizeof(creal_T));
          }

          if (ros_code_B.At != ros_code_B.k_c) {
            ros_code_B.ii_b = 0;
            while (ros_code_B.ii_b + 1 <= ros_code_B.At_size[0]) {
              ros_code_B.jj = ros_code_B.nzcount * ros_code_B.ii_b;
              ros_code_B.atmp_tmp = (ros_code_B.At + ros_code_B.jj) - 1;
              ros_code_B.atmp = ros_code_B.b_A_data[ros_code_B.atmp_tmp];
              ros_code_B.b_A_data_tmp = (ros_code_B.k_c + ros_code_B.jj) - 1;
              ros_code_B.b_A_data[ros_code_B.atmp_tmp] =
                ros_code_B.b_A_data[ros_code_B.b_A_data_tmp];
              ros_code_B.b_A_data[ros_code_B.b_A_data_tmp] = ros_code_B.atmp;
              ros_code_B.ii_b++;
            }
          }

          if (ros_code_B.n_e != ros_code_B.k_c) {
            ros_code_B.ii_b = 0;
            while (ros_code_B.ii_b <= ros_code_B.k_c - 1) {
              ros_code_B.jj = (ros_code_B.n_e - 1) * ros_code_B.nzcount +
                ros_code_B.ii_b;
              ros_code_B.atmp = ros_code_B.b_A_data[ros_code_B.jj];
              ros_code_B.b_A_data_tmp = (ros_code_B.k_c - 1) *
                ros_code_B.nzcount + ros_code_B.ii_b;
              ros_code_B.b_A_data[ros_code_B.jj] =
                ros_code_B.b_A_data[ros_code_B.b_A_data_tmp];
              ros_code_B.b_A_data[ros_code_B.b_A_data_tmp] = ros_code_B.atmp;
              ros_code_B.ii_b++;
            }
          }

          ros_code_B.ii_b = ros_code_B.nzcount * ros_code_B.b_A_size_idx_1;
          if (ros_code_B.ii_b - 1 >= 0) {
            memcpy(&ros_code_B.At_data[0], &ros_code_B.b_A_data[0],
                   ros_code_B.ii_b * sizeof(creal_T));
          }

          ros_code_B.k_c--;
          if (ros_code_B.k_c == 1) {
            exitg3 = 1;
          }
        }
      } while (exitg3 == 0);

      if (exitg3 == 1) {
      } else {
        int32_T exitg2;
        do {
          exitg2 = 0;
          ros_code_B.At = 0;
          ros_code_B.n_e = 0;
          notdone = false;
          ros_code_B.ii_b = ros_code_B.b_tmp;
          exitg1 = false;
          while ((!exitg1) && (ros_code_B.ii_b <= ros_code_B.k_c)) {
            ros_code_B.nzcount = 0;
            ros_code_B.At = ros_code_B.k_c;
            ros_code_B.n_e = ros_code_B.ii_b;
            ros_code_B.jj = ros_code_B.b_tmp;
            exitg4 = false;
            while ((!exitg4) && (ros_code_B.jj <= ros_code_B.k_c)) {
              ros_code_B.b_A_size_idx_1 = ((ros_code_B.ii_b - 1) *
                ros_code_B.At_size[0] + ros_code_B.jj) - 1;
              if ((ros_code_B.At_data[ros_code_B.b_A_size_idx_1].re != 0.0) ||
                  (ros_code_B.At_data[ros_code_B.b_A_size_idx_1].im != 0.0) ||
                  (ros_code_B.jj == ros_code_B.ii_b)) {
                if (ros_code_B.nzcount == 0) {
                  ros_code_B.At = ros_code_B.jj;
                  ros_code_B.nzcount = 1;
                  ros_code_B.jj++;
                } else {
                  ros_code_B.nzcount = 2;
                  exitg4 = true;
                }
              } else {
                ros_code_B.jj++;
              }
            }

            if (ros_code_B.nzcount < 2) {
              notdone = true;
              exitg1 = true;
            } else {
              ros_code_B.ii_b++;
            }
          }

          if (!notdone) {
            exitg2 = 1;
          } else {
            ros_code_B.nzcount = ros_code_B.At_size[0];
            ros_code_B.b_A_size_idx_1 = ros_code_B.At_size[1];
            ros_code_B.ii_b = ros_code_B.At_size[0] * ros_code_B.At_size[1];
            if (ros_code_B.ii_b - 1 >= 0) {
              memcpy(&ros_code_B.b_A_data[0], &ros_code_B.At_data[0],
                     ros_code_B.ii_b * sizeof(creal_T));
            }

            if (ros_code_B.At != ros_code_B.b_tmp) {
              ros_code_B.ii_b = ros_code_B.b_tmp - 1;
              while (ros_code_B.ii_b + 1 <= ros_code_B.At_size[0]) {
                ros_code_B.jj = ros_code_B.nzcount * ros_code_B.ii_b;
                ros_code_B.atmp_tmp = (ros_code_B.At + ros_code_B.jj) - 1;
                ros_code_B.atmp = ros_code_B.b_A_data[ros_code_B.atmp_tmp];
                ros_code_B.b_A_data_tmp = (ros_code_B.b_tmp + ros_code_B.jj) - 1;
                ros_code_B.b_A_data[ros_code_B.atmp_tmp] =
                  ros_code_B.b_A_data[ros_code_B.b_A_data_tmp];
                ros_code_B.b_A_data[ros_code_B.b_A_data_tmp] = ros_code_B.atmp;
                ros_code_B.ii_b++;
              }
            }

            if (ros_code_B.n_e != ros_code_B.b_tmp) {
              ros_code_B.ii_b = 0;
              while (ros_code_B.ii_b <= ros_code_B.k_c - 1) {
                ros_code_B.jj = (ros_code_B.n_e - 1) * ros_code_B.nzcount +
                  ros_code_B.ii_b;
                ros_code_B.atmp = ros_code_B.b_A_data[ros_code_B.jj];
                ros_code_B.b_A_data_tmp = (ros_code_B.b_tmp - 1) *
                  ros_code_B.nzcount + ros_code_B.ii_b;
                ros_code_B.b_A_data[ros_code_B.jj] =
                  ros_code_B.b_A_data[ros_code_B.b_A_data_tmp];
                ros_code_B.b_A_data[ros_code_B.b_A_data_tmp] = ros_code_B.atmp;
                ros_code_B.ii_b++;
              }
            }

            ros_code_B.ii_b = ros_code_B.nzcount * ros_code_B.b_A_size_idx_1;
            if (ros_code_B.ii_b - 1 >= 0) {
              memcpy(&ros_code_B.At_data[0], &ros_code_B.b_A_data[0],
                     ros_code_B.ii_b * sizeof(creal_T));
            }

            ros_code_B.b_tmp++;
            if (ros_code_B.b_tmp == ros_code_B.k_c) {
              exitg2 = 1;
            }
          }
        } while (exitg2 == 0);
      }
    }

    ros_code_B.n_e = ros_code_B.At_size[0];
    if ((ros_code_B.At_size[0] > 1) && (ros_code_B.k_c >= ros_code_B.b_tmp + 2))
    {
      ros_code_B.ii_b = ros_code_B.b_tmp;
      while (ros_code_B.ii_b < 2) {
        ros_code_xzlartg(ros_code_B.At_data[1], ros_code_B.At_data[2],
                         &ros_code_B.cfromc, &ros_code_B.atmp,
                         &ros_code_B.At_data[1]);
        ros_code_B.b_A_size_idx_1 = 2;
        ros_code_B.At_data[ros_code_B.b_A_size_idx_1].re = 0.0;
        ros_code_B.At_data[ros_code_B.b_A_size_idx_1].im = 0.0;
        ros_code_B.ii_b = 1;
        while (ros_code_B.ii_b + 1 <= ros_code_B.n_e) {
          ros_code_B.At = ros_code_B.At_size[0] * ros_code_B.ii_b;
          ros_code_B.ctoc = ros_code_B.At_data[2 + ros_code_B.At].im;
          ros_code_B.cfrom1 = ros_code_B.At_data[2 + ros_code_B.At].re;
          ros_code_B.cto1 = ros_code_B.At_data[1 + ros_code_B.At].re;
          ros_code_B.stemp_im_tmp = ros_code_B.At_data[1 + ros_code_B.At].im;
          ros_code_B.At_data[2 + ros_code_B.At].re = ros_code_B.cfromc *
            ros_code_B.cfrom1 - (ros_code_B.atmp.re * ros_code_B.cto1 +
            ros_code_B.atmp.im * ros_code_B.stemp_im_tmp);
          ros_code_B.At_data[2 + ros_code_B.At].im = ros_code_B.cfromc *
            ros_code_B.ctoc - (ros_code_B.atmp.re * ros_code_B.stemp_im_tmp -
                               ros_code_B.atmp.im * ros_code_B.cto1);
          ros_code_B.At_data[1 + ros_code_B.At].re = (ros_code_B.atmp.re *
            ros_code_B.cfrom1 - ros_code_B.atmp.im * ros_code_B.ctoc) +
            ros_code_B.cfromc * ros_code_B.cto1;
          ros_code_B.At_data[1 + ros_code_B.At].im = (ros_code_B.atmp.re *
            ros_code_B.ctoc + ros_code_B.atmp.im * ros_code_B.cfrom1) +
            ros_code_B.cfromc * ros_code_B.stemp_im_tmp;
          ros_code_B.ii_b++;
        }

        ros_code_B.atmp.re = -ros_code_B.atmp.re;
        ros_code_B.atmp.im = -ros_code_B.atmp.im;
        ros_code_B.ii_b = ros_code_B.At_size[0];
        ros_code_B.ctoc = ros_code_B.At_data[ros_code_B.ii_b].im;
        ros_code_B.cfrom1 = ros_code_B.At_data[ros_code_B.ii_b].re;
        ros_code_B.b_A_size_idx_1 = ros_code_B.At_size[0] << 1;
        ros_code_B.cto1 = ros_code_B.At_data[ros_code_B.b_A_size_idx_1].im;
        ros_code_B.At_data[ros_code_B.ii_b].re = ros_code_B.cfromc *
          ros_code_B.cfrom1 - (ros_code_B.atmp.re *
          ros_code_B.At_data[ros_code_B.b_A_size_idx_1].re + ros_code_B.atmp.im *
          ros_code_B.cto1);
        ros_code_B.At_data[ros_code_B.ii_b].im = ros_code_B.cfromc *
          ros_code_B.ctoc - (ros_code_B.atmp.re * ros_code_B.cto1 -
                             ros_code_B.atmp.im *
                             ros_code_B.At_data[ros_code_B.b_A_size_idx_1].re);
        ros_code_B.At_data[ros_code_B.b_A_size_idx_1].re = (ros_code_B.atmp.re *
          ros_code_B.cfrom1 - ros_code_B.atmp.im * ros_code_B.ctoc) +
          ros_code_B.cfromc * ros_code_B.At_data[ros_code_B.b_A_size_idx_1].re;
        ros_code_B.At_data[ros_code_B.b_A_size_idx_1].im = (ros_code_B.atmp.re *
          ros_code_B.ctoc + ros_code_B.atmp.im * ros_code_B.cfrom1) +
          ros_code_B.cfromc * ros_code_B.At_data[ros_code_B.b_A_size_idx_1].im;
        ros_code_B.ii_b = 1 + ros_code_B.At_size[0];
        ros_code_B.ctoc = ros_code_B.At_data[ros_code_B.ii_b].im;
        ros_code_B.cfrom1 = ros_code_B.At_data[ros_code_B.ii_b].re;
        ros_code_B.b_A_size_idx_1 = (ros_code_B.At_size[0] << 1) + 1;
        ros_code_B.cto1 = ros_code_B.At_data[ros_code_B.b_A_size_idx_1].im;
        ros_code_B.At_data[ros_code_B.ii_b].re = ros_code_B.cfromc *
          ros_code_B.cfrom1 - (ros_code_B.atmp.re *
          ros_code_B.At_data[ros_code_B.b_A_size_idx_1].re + ros_code_B.atmp.im *
          ros_code_B.cto1);
        ros_code_B.At_data[ros_code_B.ii_b].im = ros_code_B.cfromc *
          ros_code_B.ctoc - (ros_code_B.atmp.re * ros_code_B.cto1 -
                             ros_code_B.atmp.im *
                             ros_code_B.At_data[ros_code_B.b_A_size_idx_1].re);
        ros_code_B.At_data[ros_code_B.b_A_size_idx_1].re = (ros_code_B.atmp.re *
          ros_code_B.cfrom1 - ros_code_B.atmp.im * ros_code_B.ctoc) +
          ros_code_B.cfromc * ros_code_B.At_data[ros_code_B.b_A_size_idx_1].re;
        ros_code_B.At_data[ros_code_B.b_A_size_idx_1].im = (ros_code_B.atmp.re *
          ros_code_B.ctoc + ros_code_B.atmp.im * ros_code_B.cfrom1) +
          ros_code_B.cfromc * ros_code_B.At_data[ros_code_B.b_A_size_idx_1].im;
        ros_code_B.ii_b = 2 + ros_code_B.At_size[0];
        ros_code_B.ctoc = ros_code_B.At_data[ros_code_B.ii_b].im;
        ros_code_B.cfrom1 = ros_code_B.At_data[ros_code_B.ii_b].re;
        ros_code_B.b_A_size_idx_1 = (ros_code_B.At_size[0] << 1) + 2;
        ros_code_B.cto1 = ros_code_B.At_data[ros_code_B.b_A_size_idx_1].im;
        ros_code_B.At_data[ros_code_B.ii_b].re = ros_code_B.cfromc *
          ros_code_B.cfrom1 - (ros_code_B.atmp.re *
          ros_code_B.At_data[ros_code_B.b_A_size_idx_1].re + ros_code_B.atmp.im *
          ros_code_B.cto1);
        ros_code_B.At_data[ros_code_B.ii_b].im = ros_code_B.cfromc *
          ros_code_B.ctoc - (ros_code_B.atmp.re * ros_code_B.cto1 -
                             ros_code_B.atmp.im *
                             ros_code_B.At_data[ros_code_B.b_A_size_idx_1].re);
        ros_code_B.At_data[ros_code_B.b_A_size_idx_1].re = (ros_code_B.atmp.re *
          ros_code_B.cfrom1 - ros_code_B.atmp.im * ros_code_B.ctoc) +
          ros_code_B.cfromc * ros_code_B.At_data[ros_code_B.b_A_size_idx_1].re;
        ros_code_B.At_data[ros_code_B.b_A_size_idx_1].im = (ros_code_B.atmp.re *
          ros_code_B.ctoc + ros_code_B.atmp.im * ros_code_B.cfrom1) +
          ros_code_B.cfromc * ros_code_B.At_data[ros_code_B.b_A_size_idx_1].im;
        ros_code_B.ii_b = 2;
      }
    }

    ros_code_xzhgeqz(ros_code_B.At_data, ros_code_B.At_size, ros_code_B.b_tmp,
                     ros_code_B.k_c, &ros_code_B.n_e, V_data, V_size,
                     ros_code_B.y_data_bn, &ros_code_B.y_size_d);
    if ((ros_code_B.n_e == 0) && ilascl) {
      ilascl = true;
      while (ilascl) {
        ros_code_B.cfromc = ros_code_B.absxk_g * 2.0041683600089728E-292;
        ros_code_B.ctoc = ros_code_B.anrm / 4.9896007738368E+291;
        if ((ros_code_B.cfromc > ros_code_B.anrm) && (ros_code_B.anrm != 0.0)) {
          ros_code_B.cfrom1 = 2.0041683600089728E-292;
          ros_code_B.absxk_g = ros_code_B.cfromc;
        } else if (ros_code_B.ctoc > ros_code_B.absxk_g) {
          ros_code_B.cfrom1 = 4.9896007738368E+291;
          ros_code_B.anrm = ros_code_B.ctoc;
        } else {
          ros_code_B.cfrom1 = ros_code_B.anrm / ros_code_B.absxk_g;
          ilascl = false;
        }

        ros_code_B.ii_b = *V_size;
        for (ros_code_B.nzcount = 0; ros_code_B.nzcount < ros_code_B.ii_b;
             ros_code_B.nzcount++) {
          ros_code_B.atmp = V_data[ros_code_B.nzcount];
          ros_code_B.atmp.re *= ros_code_B.cfrom1;
          ros_code_B.atmp.im *= ros_code_B.cfrom1;
          V_data[ros_code_B.nzcount] = ros_code_B.atmp;
        }
      }
    }
  }

  if (*V_size == ros_code_B.y_size_d) {
    ros_code_B.ii_b = *V_size;
    for (ros_code_B.nzcount = 0; ros_code_B.nzcount < ros_code_B.ii_b;
         ros_code_B.nzcount++) {
      ros_code_B.atmp = V_data[ros_code_B.nzcount];
      ros_code_B.anrm = ros_code_B.atmp.re;
      ros_code_B.ctoc = ros_code_B.y_data_bn[ros_code_B.nzcount].re;
      ros_code_B.absxk_g = ros_code_B.y_data_bn[ros_code_B.nzcount].im;
      if (ros_code_B.absxk_g == 0.0) {
        if (ros_code_B.atmp.im == 0.0) {
          ros_code_B.atmp.re /= ros_code_B.ctoc;
          ros_code_B.atmp.im = 0.0;
        } else if (ros_code_B.atmp.re == 0.0) {
          ros_code_B.atmp.re = 0.0;
          ros_code_B.atmp.im /= ros_code_B.ctoc;
        } else {
          ros_code_B.atmp.re /= ros_code_B.ctoc;
          ros_code_B.atmp.im /= ros_code_B.ctoc;
        }
      } else if (ros_code_B.ctoc == 0.0) {
        if (ros_code_B.atmp.re == 0.0) {
          ros_code_B.atmp.re = ros_code_B.atmp.im / ros_code_B.absxk_g;
          ros_code_B.atmp.im = 0.0;
        } else if (ros_code_B.atmp.im == 0.0) {
          ros_code_B.atmp.re = 0.0;
          ros_code_B.atmp.im = -(ros_code_B.anrm / ros_code_B.absxk_g);
        } else {
          ros_code_B.atmp.re = ros_code_B.atmp.im / ros_code_B.absxk_g;
          ros_code_B.atmp.im = -(ros_code_B.anrm / ros_code_B.absxk_g);
        }
      } else {
        ros_code_B.cfromc = fabs(ros_code_B.ctoc);
        ros_code_B.cfrom1 = fabs(ros_code_B.absxk_g);
        if (ros_code_B.cfromc > ros_code_B.cfrom1) {
          ros_code_B.cfromc = ros_code_B.absxk_g / ros_code_B.ctoc;
          ros_code_B.absxk_g = ros_code_B.cfromc * ros_code_B.absxk_g +
            ros_code_B.ctoc;
          ros_code_B.atmp.re = (ros_code_B.cfromc * ros_code_B.atmp.im +
                                ros_code_B.atmp.re) / ros_code_B.absxk_g;
          ros_code_B.atmp.im = (ros_code_B.atmp.im - ros_code_B.cfromc *
                                ros_code_B.anrm) / ros_code_B.absxk_g;
        } else if (ros_code_B.cfrom1 == ros_code_B.cfromc) {
          ros_code_B.ctoc = ros_code_B.ctoc > 0.0 ? 0.5 : -0.5;
          ros_code_B.absxk_g = ros_code_B.absxk_g > 0.0 ? 0.5 : -0.5;
          ros_code_B.atmp.re = (ros_code_B.atmp.re * ros_code_B.ctoc +
                                ros_code_B.atmp.im * ros_code_B.absxk_g) /
            ros_code_B.cfromc;
          ros_code_B.atmp.im = (ros_code_B.atmp.im * ros_code_B.ctoc -
                                ros_code_B.anrm * ros_code_B.absxk_g) /
            ros_code_B.cfromc;
        } else {
          ros_code_B.cfromc = ros_code_B.ctoc / ros_code_B.absxk_g;
          ros_code_B.absxk_g += ros_code_B.cfromc * ros_code_B.ctoc;
          ros_code_B.atmp.re = (ros_code_B.cfromc * ros_code_B.atmp.re +
                                ros_code_B.atmp.im) / ros_code_B.absxk_g;
          ros_code_B.atmp.im = (ros_code_B.cfromc * ros_code_B.atmp.im -
                                ros_code_B.anrm) / ros_code_B.absxk_g;
        }
      }

      V_data[ros_code_B.nzcount] = ros_code_B.atmp;
    }
  } else {
    ros_code_rdivide(V_data, V_size, ros_code_B.y_data_bn, &ros_code_B.y_size_d);
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_xgehrd(real_T a_data[], int32_T a_size[2])
{
  int32_T work_size_idx_0_tmp;
  ros_code_B.b_a_size_idx_0 = a_size[0];
  ros_code_B.b_a_size_idx_1 = a_size[1];
  ros_code_B.loop_ub_e = a_size[0] * a_size[1];
  if (ros_code_B.loop_ub_e - 1 >= 0) {
    memcpy(&ros_code_B.b_a_data[0], &a_data[0], ros_code_B.loop_ub_e * sizeof
           (real_T));
  }

  ros_code_B.n_k = a_size[0];
  work_size_idx_0_tmp = static_cast<int8_T>(a_size[0]);
  if (work_size_idx_0_tmp - 1 >= 0) {
    memset(&ros_code_B.work_data[0], 0, work_size_idx_0_tmp * sizeof(real_T));
  }

  for (work_size_idx_0_tmp = 0; work_size_idx_0_tmp <= a_size[0] - 2;
       work_size_idx_0_tmp++) {
    int32_T alpha1_tmp;
    int32_T c_lastc_tmp;
    int32_T exitg1;
    boolean_T exitg2;
    ros_code_B.loop_ub_e = work_size_idx_0_tmp * ros_code_B.n_k;
    ros_code_B.in = (work_size_idx_0_tmp + 1) * ros_code_B.n_k;
    alpha1_tmp = (ros_code_B.b_a_size_idx_0 * work_size_idx_0_tmp +
                  work_size_idx_0_tmp) + 1;
    ros_code_B.alpha1 = ros_code_B.b_a_data[alpha1_tmp];
    ros_code_B.lastv_a = (ros_code_B.loop_ub_e + ros_code_B.n_k) - 1;
    c_lastc_tmp = ros_code_B.n_k - work_size_idx_0_tmp;
    ros_code_B.tau_data[work_size_idx_0_tmp] = 0.0;
    if (c_lastc_tmp - 1 > 0) {
      ros_code_B.xnorm_h = 0.0;
      if (c_lastc_tmp - 2 >= 1) {
        ros_code_B.xnorm_h = fabs(ros_code_B.b_a_data[ros_code_B.lastv_a]);
      }

      if (ros_code_B.xnorm_h != 0.0) {
        ros_code_B.xnorm_h = ros_code_rt_hypotd_snf(ros_code_B.alpha1,
          ros_code_B.xnorm_h);
        if (ros_code_B.alpha1 >= 0.0) {
          ros_code_B.xnorm_h = -ros_code_B.xnorm_h;
        }

        if (fabs(ros_code_B.xnorm_h) < 1.0020841800044864E-292) {
          ros_code_B.knt_f = 0;
          ros_code_B.rowleft = (ros_code_B.lastv_a + c_lastc_tmp) - 2;
          do {
            ros_code_B.knt_f++;
            ros_code_B.jy = ros_code_B.lastv_a;
            while (ros_code_B.jy + 1 <= ros_code_B.rowleft) {
              ros_code_B.b_a_data[ros_code_B.jy] *= 9.9792015476736E+291;
              ros_code_B.jy++;
            }

            ros_code_B.xnorm_h *= 9.9792015476736E+291;
            ros_code_B.alpha1 *= 9.9792015476736E+291;
          } while ((fabs(ros_code_B.xnorm_h) < 1.0020841800044864E-292) &&
                   (ros_code_B.knt_f < 20));

          ros_code_B.xnorm_h = 0.0;
          if (c_lastc_tmp - 2 >= 1) {
            ros_code_B.xnorm_h = fabs(ros_code_B.b_a_data[ros_code_B.lastv_a]);
          }

          ros_code_B.xnorm_h = ros_code_rt_hypotd_snf(ros_code_B.alpha1,
            ros_code_B.xnorm_h);
          if (ros_code_B.alpha1 >= 0.0) {
            ros_code_B.xnorm_h = -ros_code_B.xnorm_h;
          }

          ros_code_B.tau_data[work_size_idx_0_tmp] = (ros_code_B.xnorm_h -
            ros_code_B.alpha1) / ros_code_B.xnorm_h;
          ros_code_B.alpha1 = 1.0 / (ros_code_B.alpha1 - ros_code_B.xnorm_h);
          while (ros_code_B.lastv_a + 1 <= ros_code_B.rowleft) {
            ros_code_B.b_a_data[ros_code_B.lastv_a] *= ros_code_B.alpha1;
            ros_code_B.lastv_a++;
          }

          ros_code_B.lastv_a = 0;
          while (ros_code_B.lastv_a <= ros_code_B.knt_f - 1) {
            ros_code_B.xnorm_h *= 1.0020841800044864E-292;
            ros_code_B.lastv_a++;
          }

          ros_code_B.alpha1 = ros_code_B.xnorm_h;
        } else {
          ros_code_B.tau_data[work_size_idx_0_tmp] = (ros_code_B.xnorm_h -
            ros_code_B.alpha1) / ros_code_B.xnorm_h;
          ros_code_B.alpha1 = 1.0 / (ros_code_B.alpha1 - ros_code_B.xnorm_h);
          ros_code_B.knt_f = (ros_code_B.lastv_a + c_lastc_tmp) - 2;
          while (ros_code_B.lastv_a + 1 <= ros_code_B.knt_f) {
            ros_code_B.b_a_data[ros_code_B.lastv_a] *= ros_code_B.alpha1;
            ros_code_B.lastv_a++;
          }

          ros_code_B.alpha1 = ros_code_B.xnorm_h;
        }
      }
    }

    ros_code_B.b_a_data[alpha1_tmp] = 1.0;
    ros_code_B.loop_ub_e = (work_size_idx_0_tmp + ros_code_B.loop_ub_e) + 1;
    if (ros_code_B.tau_data[work_size_idx_0_tmp] != 0.0) {
      ros_code_B.lastv_a = c_lastc_tmp - 2;
      ros_code_B.knt_f = (ros_code_B.loop_ub_e + c_lastc_tmp) - 3;
      while ((ros_code_B.lastv_a + 1 > 0) &&
             (ros_code_B.b_a_data[ros_code_B.knt_f + 1] == 0.0)) {
        ros_code_B.lastv_a--;
        ros_code_B.knt_f--;
      }

      ros_code_B.knt_f = ros_code_B.n_k;
      exitg2 = false;
      while ((!exitg2) && (ros_code_B.knt_f > 0)) {
        ros_code_B.rowleft = ros_code_B.in + ros_code_B.knt_f;
        ros_code_B.jy = ros_code_B.rowleft;
        do {
          exitg1 = 0;
          if ((ros_code_B.n_k > 0) && (ros_code_B.jy <= ros_code_B.lastv_a *
               ros_code_B.n_k + ros_code_B.rowleft)) {
            if (ros_code_B.b_a_data[ros_code_B.jy - 1] != 0.0) {
              exitg1 = 1;
            } else {
              ros_code_B.jy += ros_code_B.n_k;
            }
          } else {
            ros_code_B.knt_f--;
            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }
    } else {
      ros_code_B.lastv_a = -1;
      ros_code_B.knt_f = 0;
    }

    if (ros_code_B.lastv_a + 1 > 0) {
      if (ros_code_B.knt_f != 0) {
        ros_code_B.rowleft = 0;
        while (ros_code_B.rowleft <= ros_code_B.knt_f - 1) {
          ros_code_B.work_data[ros_code_B.rowleft] = 0.0;
          ros_code_B.rowleft++;
        }

        ros_code_B.rowleft = ros_code_B.loop_ub_e;
        ros_code_B.jy = (ros_code_B.n_k * ros_code_B.lastv_a + ros_code_B.in) +
          1;
        ros_code_B.b_ix_e = ros_code_B.in + 1;
        while ((ros_code_B.n_k > 0) && (ros_code_B.b_ix_e <= ros_code_B.jy)) {
          ros_code_B.c_ix = 0;
          ros_code_B.g_d = (ros_code_B.b_ix_e + ros_code_B.knt_f) - 1;
          ros_code_B.c_lastc = ros_code_B.b_ix_e;
          while (ros_code_B.c_lastc <= ros_code_B.g_d) {
            ros_code_B.work_data[ros_code_B.c_ix] +=
              ros_code_B.b_a_data[ros_code_B.c_lastc - 1] *
              ros_code_B.b_a_data[ros_code_B.rowleft];
            ros_code_B.c_ix++;
            ros_code_B.c_lastc++;
          }

          ros_code_B.rowleft++;
          ros_code_B.b_ix_e += ros_code_B.n_k;
        }
      }

      if (!(-ros_code_B.tau_data[work_size_idx_0_tmp] == 0.0)) {
        ros_code_B.rowleft = ros_code_B.in;
        ros_code_B.jy = ros_code_B.loop_ub_e;
        ros_code_B.b_ix_e = 0;
        while (ros_code_B.b_ix_e <= ros_code_B.lastv_a) {
          if (ros_code_B.b_a_data[ros_code_B.jy] != 0.0) {
            ros_code_B.xnorm_h = ros_code_B.b_a_data[ros_code_B.jy] *
              -ros_code_B.tau_data[work_size_idx_0_tmp];
            ros_code_B.c_ix = 0;
            ros_code_B.g_d = ros_code_B.rowleft;
            ros_code_B.c_lastc = ros_code_B.knt_f + ros_code_B.rowleft;
            while (ros_code_B.g_d + 1 <= ros_code_B.c_lastc) {
              ros_code_B.b_a_data[ros_code_B.g_d] +=
                ros_code_B.work_data[ros_code_B.c_ix] * ros_code_B.xnorm_h;
              ros_code_B.c_ix++;
              ros_code_B.g_d++;
            }
          }

          ros_code_B.jy++;
          ros_code_B.rowleft += ros_code_B.n_k;
          ros_code_B.b_ix_e++;
        }
      }
    }

    ros_code_B.lastv_a = (work_size_idx_0_tmp + ros_code_B.in) + 2;
    if (ros_code_B.tau_data[work_size_idx_0_tmp] != 0.0) {
      ros_code_B.in = c_lastc_tmp - 1;
      ros_code_B.c_lastc = (ros_code_B.loop_ub_e + c_lastc_tmp) - 1;
      while ((ros_code_B.in > 0) && (ros_code_B.b_a_data[ros_code_B.c_lastc - 1]
              == 0.0)) {
        ros_code_B.in--;
        ros_code_B.c_lastc--;
      }

      ros_code_B.c_lastc = c_lastc_tmp - 1;
      exitg2 = false;
      while ((!exitg2) && (ros_code_B.c_lastc > 0)) {
        ros_code_B.knt_f = (ros_code_B.c_lastc - 1) * ros_code_B.n_k +
          ros_code_B.lastv_a;
        ros_code_B.rowleft = ros_code_B.knt_f;
        do {
          exitg1 = 0;
          if (ros_code_B.rowleft <= (ros_code_B.knt_f + ros_code_B.in) - 1) {
            if (ros_code_B.b_a_data[ros_code_B.rowleft - 1] != 0.0) {
              exitg1 = 1;
            } else {
              ros_code_B.rowleft++;
            }
          } else {
            ros_code_B.c_lastc--;
            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }

      ros_code_B.c_lastc--;
    } else {
      ros_code_B.in = 0;
      ros_code_B.c_lastc = -1;
    }

    if (ros_code_B.in > 0) {
      if (ros_code_B.c_lastc + 1 != 0) {
        ros_code_B.knt_f = 0;
        while (ros_code_B.knt_f <= ros_code_B.c_lastc) {
          ros_code_B.work_data[ros_code_B.knt_f] = 0.0;
          ros_code_B.knt_f++;
        }

        ros_code_B.knt_f = 0;
        ros_code_B.rowleft = ros_code_B.n_k * ros_code_B.c_lastc +
          ros_code_B.lastv_a;
        ros_code_B.jy = ros_code_B.lastv_a;
        while ((ros_code_B.n_k > 0) && (ros_code_B.jy <= ros_code_B.rowleft)) {
          ros_code_B.b_ix_e = ros_code_B.loop_ub_e;
          ros_code_B.xnorm_h = 0.0;
          ros_code_B.c_ix = (ros_code_B.jy + ros_code_B.in) - 1;
          ros_code_B.g_d = ros_code_B.jy;
          while (ros_code_B.g_d <= ros_code_B.c_ix) {
            ros_code_B.xnorm_h += ros_code_B.b_a_data[ros_code_B.g_d - 1] *
              ros_code_B.b_a_data[ros_code_B.b_ix_e];
            ros_code_B.b_ix_e++;
            ros_code_B.g_d++;
          }

          ros_code_B.work_data[ros_code_B.knt_f] += ros_code_B.xnorm_h;
          ros_code_B.knt_f++;
          ros_code_B.jy += ros_code_B.n_k;
        }
      }

      if (!(-ros_code_B.tau_data[work_size_idx_0_tmp] == 0.0)) {
        ros_code_B.lastv_a--;
        ros_code_B.knt_f = 0;
        ros_code_B.rowleft = 0;
        while (ros_code_B.rowleft <= ros_code_B.c_lastc) {
          if (ros_code_B.work_data[ros_code_B.knt_f] != 0.0) {
            ros_code_B.xnorm_h = ros_code_B.work_data[ros_code_B.knt_f] *
              -ros_code_B.tau_data[work_size_idx_0_tmp];
            ros_code_B.jy = ros_code_B.loop_ub_e;
            ros_code_B.b_ix_e = ros_code_B.lastv_a;
            ros_code_B.c_ix = ros_code_B.in + ros_code_B.lastv_a;
            while (ros_code_B.b_ix_e + 1 <= ros_code_B.c_ix) {
              ros_code_B.b_a_data[ros_code_B.b_ix_e] +=
                ros_code_B.b_a_data[ros_code_B.jy] * ros_code_B.xnorm_h;
              ros_code_B.jy++;
              ros_code_B.b_ix_e++;
            }
          }

          ros_code_B.knt_f++;
          ros_code_B.lastv_a += ros_code_B.n_k;
          ros_code_B.rowleft++;
        }
      }
    }

    ros_code_B.b_a_data[alpha1_tmp] = ros_code_B.alpha1;
  }

  a_size[1] = ros_code_B.b_a_size_idx_1;
  for (work_size_idx_0_tmp = 0; work_size_idx_0_tmp < ros_code_B.b_a_size_idx_1;
       work_size_idx_0_tmp++) {
    for (ros_code_B.n_k = 0; ros_code_B.n_k < ros_code_B.b_a_size_idx_0;
         ros_code_B.n_k++) {
      a_data[ros_code_B.n_k + a_size[0] * work_size_idx_0_tmp] =
        ros_code_B.b_a_data[ros_code_B.b_a_size_idx_0 * work_size_idx_0_tmp +
        ros_code_B.n_k];
    }
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static real_T ros_code_xnrm2(int32_T n, const real_T x[3])
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[1]);
    } else {
      ros_code_B.scale_f = 3.3121686421112381E-170;
      ros_code_B.absxk_h = fabs(x[1]);
      if (ros_code_B.absxk_h > 3.3121686421112381E-170) {
        y = 1.0;
        ros_code_B.scale_f = ros_code_B.absxk_h;
      } else {
        ros_code_B.t_m = ros_code_B.absxk_h / 3.3121686421112381E-170;
        y = ros_code_B.t_m * ros_code_B.t_m;
      }

      ros_code_B.absxk_h = fabs(x[2]);
      if (ros_code_B.absxk_h > ros_code_B.scale_f) {
        ros_code_B.t_m = ros_code_B.scale_f / ros_code_B.absxk_h;
        y = y * ros_code_B.t_m * ros_code_B.t_m + 1.0;
        ros_code_B.scale_f = ros_code_B.absxk_h;
      } else {
        ros_code_B.t_m = ros_code_B.absxk_h / ros_code_B.scale_f;
        y += ros_code_B.t_m * ros_code_B.t_m;
      }

      y = ros_code_B.scale_f * sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S3>/reducePath'
static real_T ros_code_xzlarfg(int32_T n, real_T *alpha1, real_T x[3])
{
  real_T tau;
  tau = 0.0;
  if (n > 0) {
    ros_code_B.xnorm_m = ros_code_xnrm2(n - 1, x);
    if (ros_code_B.xnorm_m != 0.0) {
      ros_code_B.xnorm_m = ros_code_rt_hypotd_snf(*alpha1, ros_code_B.xnorm_m);
      if (*alpha1 >= 0.0) {
        ros_code_B.xnorm_m = -ros_code_B.xnorm_m;
      }

      if (fabs(ros_code_B.xnorm_m) < 1.0020841800044864E-292) {
        int32_T knt;
        knt = 0;
        do {
          knt++;
          for (int32_T c_k = 1; c_k < n; c_k++) {
            x[c_k] *= 9.9792015476736E+291;
          }

          ros_code_B.xnorm_m *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while ((fabs(ros_code_B.xnorm_m) < 1.0020841800044864E-292) && (knt <
                  20));

        ros_code_B.xnorm_m = ros_code_rt_hypotd_snf(*alpha1, ros_code_xnrm2(n -
          1, x));
        if (*alpha1 >= 0.0) {
          ros_code_B.xnorm_m = -ros_code_B.xnorm_m;
        }

        tau = (ros_code_B.xnorm_m - *alpha1) / ros_code_B.xnorm_m;
        ros_code_B.a_cu = 1.0 / (*alpha1 - ros_code_B.xnorm_m);
        for (int32_T c_k = 1; c_k < n; c_k++) {
          x[c_k] *= ros_code_B.a_cu;
        }

        for (int32_T c_k = 0; c_k < knt; c_k++) {
          ros_code_B.xnorm_m *= 1.0020841800044864E-292;
        }

        *alpha1 = ros_code_B.xnorm_m;
      } else {
        tau = (ros_code_B.xnorm_m - *alpha1) / ros_code_B.xnorm_m;
        ros_code_B.a_cu = 1.0 / (*alpha1 - ros_code_B.xnorm_m);
        for (int32_T knt = 1; knt < n; knt++) {
          x[knt] *= ros_code_B.a_cu;
        }

        *alpha1 = ros_code_B.xnorm_m;
      }
    }
  }

  return tau;
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_xdlanv2(real_T *a, real_T *b, real_T *c, real_T *d, real_T *
  rt1r, real_T *rt1i, real_T *rt2r, real_T *rt2i, real_T *cs, real_T *sn)
{
  if (*c == 0.0) {
    *cs = 1.0;
    *sn = 0.0;
  } else if (*b == 0.0) {
    *cs = 0.0;
    *sn = 1.0;
    ros_code_B.bcmax = *d;
    *d = *a;
    *a = ros_code_B.bcmax;
    *b = -*c;
    *c = 0.0;
  } else {
    ros_code_B.tau = *a - *d;
    if ((ros_code_B.tau == 0.0) && ((*b < 0.0) != (*c < 0.0))) {
      *cs = 1.0;
      *sn = 0.0;
    } else {
      int32_T b_0;
      int32_T c_0;
      boolean_T tmp;
      ros_code_B.p_e = 0.5 * ros_code_B.tau;
      ros_code_B.bcmis = fabs(*b);
      ros_code_B.z = fabs(*c);
      tmp = rtIsNaN(ros_code_B.z);
      if ((ros_code_B.bcmis >= ros_code_B.z) || tmp) {
        ros_code_B.bcmax = ros_code_B.bcmis;
      } else {
        ros_code_B.bcmax = ros_code_B.z;
      }

      if ((ros_code_B.bcmis <= ros_code_B.z) || tmp) {
        ros_code_B.z = ros_code_B.bcmis;
      }

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

      ros_code_B.bcmis = ros_code_B.z * static_cast<real_T>(b_0) *
        static_cast<real_T>(c_0);
      ros_code_B.scale_o = fabs(ros_code_B.p_e);
      if ((!(ros_code_B.scale_o >= ros_code_B.bcmax)) && (!rtIsNaN
           (ros_code_B.bcmax))) {
        ros_code_B.scale_o = ros_code_B.bcmax;
      }

      ros_code_B.z = ros_code_B.p_e / ros_code_B.scale_o * ros_code_B.p_e +
        ros_code_B.bcmax / ros_code_B.scale_o * ros_code_B.bcmis;
      if (ros_code_B.z >= 8.8817841970012523E-16) {
        if (!(ros_code_B.p_e < 0.0)) {
          ros_code_B.tau = sqrt(ros_code_B.scale_o) * sqrt(ros_code_B.z);
        } else {
          ros_code_B.tau = -(sqrt(ros_code_B.scale_o) * sqrt(ros_code_B.z));
        }

        ros_code_B.z = ros_code_B.p_e + ros_code_B.tau;
        *a = *d + ros_code_B.z;
        *d -= ros_code_B.bcmax / ros_code_B.z * ros_code_B.bcmis;
        ros_code_B.tau = ros_code_rt_hypotd_snf(*c, ros_code_B.z);
        *cs = ros_code_B.z / ros_code_B.tau;
        *sn = *c / ros_code_B.tau;
        *b -= *c;
        *c = 0.0;
      } else {
        ros_code_B.bcmax = *b + *c;
        ros_code_B.tau = ros_code_rt_hypotd_snf(ros_code_B.bcmax, ros_code_B.tau);
        *cs = sqrt((fabs(ros_code_B.bcmax) / ros_code_B.tau + 1.0) * 0.5);
        if (!(ros_code_B.bcmax < 0.0)) {
          b_0 = 1;
        } else {
          b_0 = -1;
        }

        *sn = -(ros_code_B.p_e / (ros_code_B.tau * *cs)) * static_cast<real_T>
          (b_0);
        ros_code_B.p_e = *a * *cs + *b * *sn;
        ros_code_B.tau = -*a * *sn + *b * *cs;
        ros_code_B.bcmax = *c * *cs + *d * *sn;
        ros_code_B.bcmis = -*c * *sn + *d * *cs;
        *b = ros_code_B.tau * *cs + ros_code_B.bcmis * *sn;
        *c = -ros_code_B.p_e * *sn + ros_code_B.bcmax * *cs;
        ros_code_B.bcmax = ((ros_code_B.p_e * *cs + ros_code_B.bcmax * *sn) +
                            (-ros_code_B.tau * *sn + ros_code_B.bcmis * *cs)) *
          0.5;
        *a = ros_code_B.bcmax;
        *d = ros_code_B.bcmax;
        if (*c != 0.0) {
          if (*b != 0.0) {
            if ((*b < 0.0) == (*c < 0.0)) {
              ros_code_B.z = sqrt(fabs(*b));
              ros_code_B.bcmis = sqrt(fabs(*c));
              if (!(*c < 0.0)) {
                ros_code_B.p_e = ros_code_B.z * ros_code_B.bcmis;
              } else {
                ros_code_B.p_e = -(ros_code_B.z * ros_code_B.bcmis);
              }

              ros_code_B.tau = 1.0 / sqrt(fabs(*b + *c));
              *a = ros_code_B.bcmax + ros_code_B.p_e;
              *d = ros_code_B.bcmax - ros_code_B.p_e;
              *b -= *c;
              *c = 0.0;
              ros_code_B.p_e = ros_code_B.z * ros_code_B.tau;
              ros_code_B.tau *= ros_code_B.bcmis;
              ros_code_B.bcmax = *cs * ros_code_B.p_e - *sn * ros_code_B.tau;
              *sn = *cs * ros_code_B.tau + *sn * ros_code_B.p_e;
              *cs = ros_code_B.bcmax;
            }
          } else {
            *b = -*c;
            *c = 0.0;
            ros_code_B.bcmax = *cs;
            *cs = -*sn;
            *sn = ros_code_B.bcmax;
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
    *rt1i = sqrt(fabs(*b)) * sqrt(fabs(*c));
    *rt2i = -*rt1i;
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static int32_T ros_code_xhseqr(real_T h_data[], const int32_T h_size[2])
{
  int32_T info;
  ros_code_B.n_f = h_size[0];
  ros_code_B.ldh = h_size[0];
  info = 0;
  if (h_size[0] != 1) {
    boolean_T exitg1;
    ros_code_B.v[0] = 0.0;
    ros_code_B.v[1] = 0.0;
    ros_code_B.v[2] = 0.0;
    if (h_size[0] - 2 >= 1) {
      h_data[h_size[0] - 1] = 0.0;
    }

    ros_code_B.SMLNUM = static_cast<real_T>(h_size[0]) / 2.2204460492503131E-16 *
      2.2250738585072014E-308;
    ros_code_B.i_n = h_size[0] - 2;
    exitg1 = false;
    while ((!exitg1) && (ros_code_B.i_n + 2 >= 1)) {
      boolean_T exitg2;
      boolean_T goto150;
      ros_code_B.L = 1;
      goto150 = false;
      ros_code_B.b_ix_l = 0;
      exitg2 = false;
      while ((!exitg2) && (ros_code_B.b_ix_l < 301)) {
        boolean_T exitg3;
        ros_code_B.k_i = ros_code_B.i_n;
        exitg3 = false;
        while ((!exitg3) && (ros_code_B.k_i + 2 > 1)) {
          ros_code_B.tst_tmp_i = h_size[0] * ros_code_B.k_i;
          ros_code_B.L = (ros_code_B.k_i + ros_code_B.tst_tmp_i) + 1;
          if (fabs(h_data[ros_code_B.L]) <= ros_code_B.SMLNUM) {
            exitg3 = true;
          } else {
            ros_code_B.nr = (ros_code_B.k_i + 1) * h_size[0];
            ros_code_B.tst_tmp = (ros_code_B.k_i + ros_code_B.nr) + 1;
            ros_code_B.tst_tmp_i += ros_code_B.k_i;
            ros_code_B.tst = fabs(h_data[ros_code_B.tst_tmp]) + fabs
              (h_data[ros_code_B.tst_tmp_i]);
            if (ros_code_B.tst == 0.0) {
              if (ros_code_B.k_i >= 1) {
                ros_code_B.tst = fabs(h_data[(ros_code_B.k_i - 1) * h_size[0] +
                                      ros_code_B.k_i]);
              }

              if (ros_code_B.k_i + 3 <= ros_code_B.n_f) {
                ros_code_B.tst += fabs(h_data[(ros_code_B.k_i + ros_code_B.nr) +
                  2]);
              }
            }

            if (fabs(h_data[ros_code_B.L]) <= 2.2204460492503131E-16 *
                ros_code_B.tst) {
              ros_code_B.htmp1 = fabs(h_data[ros_code_B.L]);
              ros_code_B.tst = fabs(h_data[ros_code_B.k_i + ros_code_B.nr]);
              if (ros_code_B.htmp1 > ros_code_B.tst) {
                ros_code_B.ab = ros_code_B.htmp1;
                ros_code_B.ba = ros_code_B.tst;
              } else {
                ros_code_B.ab = ros_code_B.tst;
                ros_code_B.ba = ros_code_B.htmp1;
              }

              ros_code_B.tst = h_data[ros_code_B.tst_tmp];
              ros_code_B.htmp1 = fabs(ros_code_B.tst);
              ros_code_B.tst = fabs(h_data[ros_code_B.tst_tmp_i] -
                                    ros_code_B.tst);
              if (ros_code_B.htmp1 > ros_code_B.tst) {
                ros_code_B.aa = ros_code_B.htmp1;
                ros_code_B.htmp1 = ros_code_B.tst;
              } else {
                ros_code_B.aa = ros_code_B.tst;
              }

              ros_code_B.tst = ros_code_B.aa + ros_code_B.ab;
              ros_code_B.htmp1 = ros_code_B.aa / ros_code_B.tst *
                ros_code_B.htmp1 * 2.2204460492503131E-16;
              if ((ros_code_B.SMLNUM >= ros_code_B.htmp1) || rtIsNaN
                  (ros_code_B.htmp1)) {
                ros_code_B.htmp1 = ros_code_B.SMLNUM;
              }

              if (ros_code_B.ab / ros_code_B.tst * ros_code_B.ba <=
                  ros_code_B.htmp1) {
                exitg3 = true;
              } else {
                ros_code_B.k_i--;
              }
            } else {
              ros_code_B.k_i--;
            }
          }
        }

        ros_code_B.L = ros_code_B.k_i + 2;
        if (ros_code_B.k_i + 2 > 1) {
          h_data[(ros_code_B.k_i + h_size[0] * ros_code_B.k_i) + 1] = 0.0;
        }

        if (ros_code_B.k_i + 2 >= ros_code_B.i_n + 1) {
          goto150 = true;
          exitg2 = true;
        } else {
          switch (ros_code_B.b_ix_l) {
           case 10:
            ros_code_B.tst = fabs(h_data[2 + h_size[0]]) + fabs(h_data[1]);
            ros_code_B.ba = 0.75 * ros_code_B.tst + h_data[0];
            ros_code_B.h12 = -0.4375 * ros_code_B.tst;
            ros_code_B.aa = ros_code_B.tst;
            ros_code_B.ab = ros_code_B.ba;
            break;

           case 20:
            ros_code_B.tst = fabs(h_data[(h_size[0] * ros_code_B.i_n +
              ros_code_B.i_n) + 1]) + fabs(h_data[ros_code_B.i_n]);
            ros_code_B.ba = h_data[((ros_code_B.i_n + 1) * h_size[0] +
              ros_code_B.i_n) + 1] + 0.75 * ros_code_B.tst;
            ros_code_B.h12 = -0.4375 * ros_code_B.tst;
            ros_code_B.aa = ros_code_B.tst;
            ros_code_B.ab = ros_code_B.ba;
            break;

           default:
            ros_code_B.ba = h_data[h_size[0] * ros_code_B.i_n + ros_code_B.i_n];
            ros_code_B.aa = h_data[(h_size[0] * ros_code_B.i_n + ros_code_B.i_n)
              + 1];
            ros_code_B.h12 = h_data[(ros_code_B.i_n + 1) * h_size[0] +
              ros_code_B.i_n];
            ros_code_B.ab = h_data[((ros_code_B.i_n + 1) * h_size[0] +
              ros_code_B.i_n) + 1];
            break;
          }

          ros_code_B.tst = ((fabs(ros_code_B.ba) + fabs(ros_code_B.h12)) + fabs
                            (ros_code_B.aa)) + fabs(ros_code_B.ab);
          if (ros_code_B.tst == 0.0) {
            ros_code_B.ba = 0.0;
            ros_code_B.ab = 0.0;
            ros_code_B.htmp1 = 0.0;
            ros_code_B.aa = 0.0;
          } else {
            ros_code_B.ba /= ros_code_B.tst;
            ros_code_B.ab /= ros_code_B.tst;
            ros_code_B.htmp1 = (ros_code_B.ba + ros_code_B.ab) / 2.0;
            ros_code_B.ba = (ros_code_B.ba - ros_code_B.htmp1) * (ros_code_B.ab
              - ros_code_B.htmp1) - ros_code_B.h12 / ros_code_B.tst *
              (ros_code_B.aa / ros_code_B.tst);
            ros_code_B.aa = sqrt(fabs(ros_code_B.ba));
            if (ros_code_B.ba >= 0.0) {
              ros_code_B.ba = ros_code_B.htmp1 * ros_code_B.tst;
              ros_code_B.htmp1 = ros_code_B.ba;
              ros_code_B.ab = ros_code_B.aa * ros_code_B.tst;
              ros_code_B.aa = -ros_code_B.ab;
            } else {
              ros_code_B.ba = ros_code_B.htmp1 + ros_code_B.aa;
              ros_code_B.htmp1 -= ros_code_B.aa;
              if (fabs(ros_code_B.ba - ros_code_B.ab) <= fabs(ros_code_B.htmp1 -
                   ros_code_B.ab)) {
                ros_code_B.ba *= ros_code_B.tst;
                ros_code_B.htmp1 = ros_code_B.ba;
              } else {
                ros_code_B.htmp1 *= ros_code_B.tst;
                ros_code_B.ba = ros_code_B.htmp1;
              }

              ros_code_B.ab = 0.0;
              ros_code_B.aa = 0.0;
            }
          }

          if (ros_code_B.i_n >= 1) {
            ros_code_B.tst_tmp = 0;
            ros_code_B.h12 = h_data[ros_code_B.tst_tmp] - ros_code_B.htmp1;
            ros_code_B.nr = ros_code_B.i_n;
            ros_code_B.tst = (fabs(ros_code_B.h12) + fabs(ros_code_B.aa)) + fabs
              (h_data[ros_code_B.nr]);
            ros_code_B.h21s = h_data[ros_code_B.nr] / ros_code_B.tst;
            ros_code_B.v_tmp = h_data[ros_code_B.tst_tmp];
            ros_code_B.v[0] = (ros_code_B.h12 / ros_code_B.tst *
                               (ros_code_B.v_tmp - ros_code_B.ba) +
                               h_data[h_size[0] * ros_code_B.i_n] *
                               ros_code_B.h21s) - ros_code_B.aa / ros_code_B.tst
              * ros_code_B.ab;
            ros_code_B.v[1] = (((h_data[h_size[0] * ros_code_B.i_n +
                                 ros_code_B.i_n] + ros_code_B.v_tmp) -
                                ros_code_B.ba) - ros_code_B.htmp1) *
              ros_code_B.h21s;
            ros_code_B.v[2] = h_data[(h_size[0] * ros_code_B.i_n +
              ros_code_B.i_n) + 1] * ros_code_B.h21s;
            ros_code_B.tst = (fabs(ros_code_B.v[0]) + fabs(ros_code_B.v[1])) +
              fabs(ros_code_B.v[2]);
            ros_code_B.v[0] /= ros_code_B.tst;
            ros_code_B.v[1] /= ros_code_B.tst;
            ros_code_B.v[2] /= ros_code_B.tst;
          }

          ros_code_B.k_i = ros_code_B.i_n;
          while (ros_code_B.k_i <= ros_code_B.i_n + 1) {
            ros_code_B.nr = (ros_code_B.i_n - ros_code_B.k_i) + 3;
            if (ros_code_B.nr >= 3) {
              ros_code_B.nr = 3;
            }

            if (ros_code_B.k_i > ros_code_B.i_n) {
              ros_code_B.hoffset = (ros_code_B.k_i - 2) * ros_code_B.ldh +
                ros_code_B.k_i;
              ros_code_B.tst_tmp = 0;
              while (ros_code_B.tst_tmp <= ros_code_B.nr - 1) {
                ros_code_B.v[ros_code_B.tst_tmp] = h_data[(ros_code_B.tst_tmp +
                  ros_code_B.hoffset) - 1];
                ros_code_B.tst_tmp++;
              }
            }

            ros_code_B.ab = ros_code_B.v[0];
            ros_code_B.tst = ros_code_xzlarfg(ros_code_B.nr, &ros_code_B.ab,
              ros_code_B.v);
            ros_code_B.v[0] = ros_code_B.ab;
            if (ros_code_B.k_i > ros_code_B.i_n) {
              h_data[ros_code_B.k_i - 1] = ros_code_B.ab;
              h_data[ros_code_B.k_i] = 0.0;
              if (ros_code_B.k_i < ros_code_B.i_n + 1) {
                h_data[2 - h_size[0]] = 0.0;
              }
            }

            ros_code_B.ab = ros_code_B.v[1];
            ros_code_B.ba = ros_code_B.tst * ros_code_B.v[1];
            switch (ros_code_B.nr) {
             case 3:
              {
                int32_T h21s_tmp;
                ros_code_B.htmp1 = ros_code_B.v[2];
                ros_code_B.aa = ros_code_B.tst * ros_code_B.v[2];
                ros_code_B.nr = ros_code_B.k_i - 1;
                while (ros_code_B.nr + 1 <= ros_code_B.n_f) {
                  ros_code_B.tst_tmp_i = h_size[0] * ros_code_B.nr;
                  h21s_tmp = (ros_code_B.k_i + ros_code_B.tst_tmp_i) - 1;
                  ros_code_B.tst_tmp = ros_code_B.k_i + ros_code_B.tst_tmp_i;
                  ros_code_B.h21s = (ros_code_B.ab * h_data[ros_code_B.tst_tmp]
                                     + h_data[h21s_tmp]) + h_data[2 +
                    ros_code_B.tst_tmp_i] * ros_code_B.htmp1;
                  h_data[h21s_tmp] -= ros_code_B.h21s * ros_code_B.tst;
                  h_data[ros_code_B.tst_tmp] -= ros_code_B.h21s * ros_code_B.ba;
                  h_data[2 + ros_code_B.tst_tmp_i] -= ros_code_B.h21s *
                    ros_code_B.aa;
                  ros_code_B.nr++;
                }

                if (ros_code_B.k_i + 3 <= ros_code_B.i_n + 2) {
                  ros_code_B.nr = ros_code_B.k_i + 3;
                } else {
                  ros_code_B.nr = ros_code_B.i_n + 2;
                }

                ros_code_B.hoffset = 0;
                while (ros_code_B.hoffset <= ros_code_B.nr - 1) {
                  ros_code_B.tst_tmp = (ros_code_B.k_i - 1) * h_size[0] +
                    ros_code_B.hoffset;
                  ros_code_B.h12 = h_data[ros_code_B.tst_tmp];
                  ros_code_B.tst_tmp_i = h_size[0] * ros_code_B.k_i +
                    ros_code_B.hoffset;
                  h21s_tmp = (h_size[0] << 1) + ros_code_B.hoffset;
                  ros_code_B.h21s = (ros_code_B.ab * h_data[ros_code_B.tst_tmp_i]
                                     + ros_code_B.h12) + ros_code_B.htmp1 *
                    h_data[h21s_tmp];
                  h_data[ros_code_B.tst_tmp] = ros_code_B.h12 - ros_code_B.h21s *
                    ros_code_B.tst;
                  h_data[ros_code_B.tst_tmp_i] -= ros_code_B.h21s *
                    ros_code_B.ba;
                  h_data[h21s_tmp] -= ros_code_B.h21s * ros_code_B.aa;
                  ros_code_B.hoffset++;
                }
              }
              break;

             case 2:
              {
                ros_code_B.nr = ros_code_B.k_i - 1;
                while (ros_code_B.nr + 1 <= ros_code_B.n_f) {
                  ros_code_B.tst_tmp = h_size[0] * ros_code_B.nr;
                  ros_code_B.hoffset = (ros_code_B.k_i + ros_code_B.tst_tmp) - 1;
                  ros_code_B.h12 = h_data[ros_code_B.hoffset];
                  ros_code_B.tst_tmp_i = ros_code_B.k_i + ros_code_B.tst_tmp;
                  ros_code_B.h21s = ros_code_B.ab * h_data[ros_code_B.tst_tmp_i]
                    + ros_code_B.h12;
                  h_data[ros_code_B.hoffset] = ros_code_B.h12 - ros_code_B.h21s *
                    ros_code_B.tst;
                  h_data[ros_code_B.tst_tmp_i] -= ros_code_B.h21s *
                    ros_code_B.ba;
                  ros_code_B.nr++;
                }

                ros_code_B.nr = 0;
                while (ros_code_B.nr <= ros_code_B.i_n + 1) {
                  int32_T h21s_tmp;
                  ros_code_B.tst_tmp_i = (ros_code_B.k_i - 1) * h_size[0] +
                    ros_code_B.nr;
                  h21s_tmp = h_size[0] * ros_code_B.k_i + ros_code_B.nr;
                  ros_code_B.h21s = ros_code_B.ab * h_data[h21s_tmp] +
                    h_data[ros_code_B.tst_tmp_i];
                  h_data[ros_code_B.tst_tmp_i] -= ros_code_B.h21s *
                    ros_code_B.tst;
                  h_data[h21s_tmp] -= ros_code_B.h21s * ros_code_B.ba;
                  ros_code_B.nr++;
                }
              }
              break;
            }

            ros_code_B.k_i++;
          }

          ros_code_B.b_ix_l++;
        }
      }

      if (!goto150) {
        info = ros_code_B.i_n + 2;
        exitg1 = true;
      } else {
        if ((ros_code_B.i_n + 2 != ros_code_B.L) && (ros_code_B.i_n + 1 ==
             ros_code_B.L)) {
          ros_code_B.nr = (ros_code_B.i_n + 1) * h_size[0];
          ros_code_B.b_ix_l = ros_code_B.i_n + ros_code_B.nr;
          ros_code_B.ba = h_data[ros_code_B.b_ix_l];
          ros_code_B.k_i = (h_size[0] * ros_code_B.i_n + ros_code_B.i_n) + 1;
          ros_code_B.htmp1 = h_data[ros_code_B.k_i];
          ros_code_B.nr = (ros_code_B.i_n + ros_code_B.nr) + 1;
          ros_code_B.aa = h_data[ros_code_B.nr];
          ros_code_xdlanv2(&h_data[ros_code_B.i_n + h_size[0] * ros_code_B.i_n],
                           &ros_code_B.ba, &ros_code_B.htmp1, &ros_code_B.aa,
                           &ros_code_B.h12, &ros_code_B.h21s, &ros_code_B.v_tmp,
                           &ros_code_B.a__4, &ros_code_B.tst, &ros_code_B.ab);
          h_data[ros_code_B.b_ix_l] = ros_code_B.ba;
          h_data[ros_code_B.k_i] = ros_code_B.htmp1;
          h_data[ros_code_B.nr] = ros_code_B.aa;
          if (ros_code_B.n_f > ros_code_B.i_n + 2) {
            ros_code_B.b_ix_l = (ros_code_B.n_f - ros_code_B.i_n) - 3;
            if (ros_code_B.b_ix_l + 1 >= 1) {
              ros_code_B.k_i = (ros_code_B.i_n + 2) * ros_code_B.ldh +
                ros_code_B.i_n;
              ros_code_B.nr = ros_code_B.k_i + 1;
              ros_code_B.hoffset = 0;
              while (ros_code_B.hoffset <= ros_code_B.b_ix_l) {
                ros_code_B.ba = h_data[ros_code_B.k_i] * ros_code_B.tst +
                  h_data[ros_code_B.nr] * ros_code_B.ab;
                h_data[ros_code_B.nr] = h_data[ros_code_B.nr] * ros_code_B.tst -
                  h_data[ros_code_B.k_i] * ros_code_B.ab;
                h_data[ros_code_B.k_i] = ros_code_B.ba;
                ros_code_B.nr += ros_code_B.ldh;
                ros_code_B.k_i += ros_code_B.ldh;
                ros_code_B.hoffset++;
              }
            }
          }

          if (ros_code_B.i_n >= 1) {
            ros_code_B.b_ix_l = ros_code_B.i_n * ros_code_B.ldh;
            ros_code_B.i_n = (ros_code_B.i_n + 1) * ros_code_B.ldh;
            ros_code_B.ba = h_data[ros_code_B.b_ix_l] * ros_code_B.tst +
              h_data[ros_code_B.i_n] * ros_code_B.ab;
            h_data[ros_code_B.i_n] = h_data[ros_code_B.i_n] * ros_code_B.tst -
              h_data[ros_code_B.b_ix_l] * ros_code_B.ab;
            h_data[ros_code_B.b_ix_l] = ros_code_B.ba;
          }
        }

        ros_code_B.i_n = ros_code_B.L - 3;
      }
    }
  }

  return info;
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_schur(real_T A_data[], int32_T A_size[2], real_T V_data[],
  int32_T V_size[2])
{
  if (ros_code_anyNonFinite(A_data, A_size)) {
    int8_T b_idx_0;
    b_idx_0 = static_cast<int8_T>(A_size[0]);
    V_size[0] = static_cast<int8_T>(A_size[0]);
    V_size[1] = static_cast<int8_T>(A_size[1]);
    ros_code_B.istart = static_cast<int8_T>(A_size[0]) * static_cast<int8_T>
      (A_size[1]) - 1;
    for (ros_code_B.i_cm = 0; ros_code_B.i_cm <= ros_code_B.istart;
         ros_code_B.i_cm++) {
      V_data[ros_code_B.i_cm] = (rtNaN);
    }

    if (static_cast<int8_T>(A_size[0]) > 1) {
      ros_code_B.istart = 2;
      if (static_cast<int8_T>(A_size[0]) - 2 <= static_cast<int8_T>(A_size[1]) -
          1) {
        ros_code_B.jend = static_cast<int8_T>(A_size[0]) - 2;
      } else {
        ros_code_B.jend = static_cast<int8_T>(A_size[1]) - 1;
      }

      ros_code_B.V = 0;
      while (ros_code_B.V <= ros_code_B.jend) {
        ros_code_B.i_cm = ros_code_B.istart;
        while (ros_code_B.i_cm <= b_idx_0) {
          V_data[(ros_code_B.i_cm + V_size[0] * ros_code_B.V) - 1] = 0.0;
          ros_code_B.i_cm++;
        }

        ros_code_B.istart++;
        ros_code_B.V++;
      }
    }
  } else {
    ros_code_xgehrd(A_data, A_size);
    V_size[0] = A_size[0];
    V_size[1] = A_size[1];
    ros_code_B.istart = A_size[0] * A_size[1];
    if (ros_code_B.istart - 1 >= 0) {
      memcpy(&V_data[0], &A_data[0], ros_code_B.istart * sizeof(real_T));
    }

    ros_code_xhseqr(V_data, V_size);
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_eig(const real_T A_data[], const int32_T A_size[2], creal_T
  V_data[], int32_T *V_size)
{
  if (ros_code_anyNonFinite(A_data, A_size)) {
    ros_code_B.c_i_o = A_size[0];
    *V_size = A_size[0];
    for (ros_code_B.n = 0; ros_code_B.n < ros_code_B.c_i_o; ros_code_B.n++) {
      V_data[ros_code_B.n].re = (rtNaN);
      V_data[ros_code_B.n].im = 0.0;
    }
  } else {
    int32_T exitg1;
    boolean_T c_p;
    boolean_T exitg2;
    c_p = (A_size[0] == A_size[1]);
    if (c_p) {
      ros_code_B.n = 0;
      exitg2 = false;
      while ((!exitg2) && (ros_code_B.n <= A_size[1] - 1)) {
        ros_code_B.c_i_o = 0;
        do {
          exitg1 = 0;
          if (ros_code_B.c_i_o <= ros_code_B.n) {
            if (!(A_data[A_size[0] * ros_code_B.n + ros_code_B.c_i_o] ==
                  A_data[A_size[0] * ros_code_B.c_i_o + ros_code_B.n])) {
              c_p = false;
              exitg1 = 1;
            } else {
              ros_code_B.c_i_o++;
            }
          } else {
            ros_code_B.n++;
            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }
    }

    if (c_p) {
      ros_code_B.A_size[0] = A_size[0];
      ros_code_B.A_size[1] = A_size[1];
      ros_code_B.n = A_size[0] * A_size[1] - 1;
      if (ros_code_B.n >= 0) {
        memcpy(&ros_code_B.A_data[0], &A_data[0], (ros_code_B.n + 1) * sizeof
               (real_T));
      }

      ros_code_schur(ros_code_B.A_data, ros_code_B.A_size, ros_code_B.T_data,
                     ros_code_B.T_size);
      ros_code_B.c_i_o = ros_code_B.T_size[0];
      ros_code_B.n = 0;
      while (ros_code_B.n <= ros_code_B.T_size[0] - 1) {
        ros_code_B.b_V_data[ros_code_B.n] = ros_code_B.T_data[ros_code_B.T_size
          [0] * ros_code_B.n + ros_code_B.n];
        ros_code_B.n++;
      }

      *V_size = ros_code_B.T_size[0];
      for (ros_code_B.n = 0; ros_code_B.n < ros_code_B.c_i_o; ros_code_B.n++) {
        V_data[ros_code_B.n].re = ros_code_B.b_V_data[ros_code_B.n];
        V_data[ros_code_B.n].im = 0.0;
      }
    } else {
      c_p = (A_size[0] == A_size[1]);
      if (c_p) {
        ros_code_B.n = 0;
        exitg2 = false;
        while ((!exitg2) && (ros_code_B.n <= A_size[1] - 1)) {
          ros_code_B.c_i_o = 0;
          do {
            exitg1 = 0;
            if (ros_code_B.c_i_o <= ros_code_B.n) {
              if (!(A_data[A_size[0] * ros_code_B.n + ros_code_B.c_i_o] ==
                    -A_data[A_size[0] * ros_code_B.c_i_o + ros_code_B.n])) {
                c_p = false;
                exitg1 = 1;
              } else {
                ros_code_B.c_i_o++;
              }
            } else {
              ros_code_B.n++;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      }

      if (c_p) {
        ros_code_B.A_size[0] = A_size[0];
        ros_code_B.A_size[1] = A_size[1];
        ros_code_B.n = A_size[0] * A_size[1] - 1;
        if (ros_code_B.n >= 0) {
          memcpy(&ros_code_B.A_data[0], &A_data[0], (ros_code_B.n + 1) * sizeof
                 (real_T));
        }

        ros_code_schur(ros_code_B.A_data, ros_code_B.A_size, ros_code_B.T_data,
                       ros_code_B.T_size);
        ros_code_B.n = ros_code_B.T_size[0];
        *V_size = ros_code_B.T_size[0];
        ros_code_B.c_i_o = 1;
        do {
          exitg1 = 0;
          if (ros_code_B.c_i_o <= ros_code_B.n) {
            boolean_T guard1 = false;
            guard1 = false;
            if (ros_code_B.c_i_o != ros_code_B.n) {
              ros_code_B.lambda = ros_code_B.T_data[(ros_code_B.c_i_o - 1) *
                ros_code_B.T_size[0] + ros_code_B.c_i_o];
              if (ros_code_B.lambda != 0.0) {
                ros_code_B.lambda = fabs(ros_code_B.lambda);
                V_data[ros_code_B.c_i_o - 1].re = 0.0;
                V_data[ros_code_B.c_i_o - 1].im = ros_code_B.lambda;
                V_data[ros_code_B.c_i_o].re = 0.0;
                V_data[ros_code_B.c_i_o].im = -ros_code_B.lambda;
                ros_code_B.c_i_o += 2;
              } else {
                guard1 = true;
              }
            } else {
              guard1 = true;
            }

            if (guard1) {
              V_data[ros_code_B.c_i_o - 1].re = 0.0;
              V_data[ros_code_B.c_i_o - 1].im = 0.0;
              ros_code_B.c_i_o++;
            }
          } else {
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      } else {
        ros_code_eigStandard(A_data, A_size, V_data, V_size);
      }
    }
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_roots(const real_T c[3], creal_T r_data[], int32_T *r_size)
{
  r_data[0].re = 0.0;
  r_data[0].im = 0.0;
  r_data[1].re = 0.0;
  r_data[1].im = 0.0;
  ros_code_B.k1_l = 1;
  while ((ros_code_B.k1_l <= 3) && (!(c[ros_code_B.k1_l - 1] != 0.0))) {
    ros_code_B.k1_l++;
  }

  ros_code_B.k2_k = 3;
  while ((ros_code_B.k2_k >= ros_code_B.k1_l) && (!(c[ros_code_B.k2_k - 1] !=
           0.0))) {
    ros_code_B.k2_k--;
  }

  if (ros_code_B.k1_l < ros_code_B.k2_k) {
    boolean_T exitg1;
    ros_code_B.companDim_j = ros_code_B.k2_k - ros_code_B.k1_l;
    exitg1 = false;
    while ((!exitg1) && (ros_code_B.companDim_j > 0)) {
      boolean_T exitg2;
      ros_code_B.j_f = 0;
      exitg2 = false;
      while ((!exitg2) && (ros_code_B.j_f + 1 <= ros_code_B.companDim_j)) {
        ros_code_B.ctmp_j[ros_code_B.j_f] = c[ros_code_B.k1_l + ros_code_B.j_f] /
          c[ros_code_B.k1_l - 1];
        if (rtIsInf(fabs(ros_code_B.ctmp_j[ros_code_B.j_f]))) {
          exitg2 = true;
        } else {
          ros_code_B.j_f++;
        }
      }

      if (ros_code_B.j_f + 1 > ros_code_B.companDim_j) {
        exitg1 = true;
      } else {
        ros_code_B.k1_l++;
        ros_code_B.companDim_j--;
      }
    }

    if (ros_code_B.companDim_j < 1) {
      if (3 - ros_code_B.k2_k < 1) {
        *r_size = 0;
      } else {
        *r_size = 3 - ros_code_B.k2_k;
      }
    } else {
      ros_code_B.a_size_n[0] = ros_code_B.companDim_j;
      ros_code_B.a_size_n[1] = ros_code_B.companDim_j;
      ros_code_B.k1_l = ros_code_B.companDim_j * ros_code_B.companDim_j - 1;
      memset(&ros_code_B.a_data_e[0], 0, (ros_code_B.k1_l + 1) * sizeof(real_T));
      ros_code_B.k1_l = 0;
      while (ros_code_B.k1_l <= ros_code_B.companDim_j - 2) {
        ros_code_B.a_data_e[0] = -ros_code_B.ctmp_j[0];
        ros_code_B.a_data_e[1] = 1.0;
        ros_code_B.k1_l = 1;
      }

      ros_code_B.a_data_e[ros_code_B.companDim_j * (ros_code_B.companDim_j - 1)]
        = -ros_code_B.ctmp_j[ros_code_B.companDim_j - 1];
      if (2 - ros_code_B.k2_k >= 0) {
        r_data[0].re = 0.0;
        r_data[0].im = 0.0;
      }

      ros_code_eig(ros_code_B.a_data_e, ros_code_B.a_size_n, ros_code_B.f_data,
                   &ros_code_B.f_size);
      ros_code_B.k1_l = 0;
      while (ros_code_B.k1_l <= ros_code_B.companDim_j - 1) {
        r_data[(ros_code_B.k1_l - ros_code_B.k2_k) + 3] =
          ros_code_B.f_data[ros_code_B.k1_l];
        ros_code_B.k1_l++;
      }

      *r_size = (ros_code_B.companDim_j - ros_code_B.k2_k) + 3;
    }
  } else if (3 - ros_code_B.k2_k < 1) {
    *r_size = 0;
  } else {
    *r_size = 3 - ros_code_B.k2_k;
  }
}

static void ros_c_binary_expand_op_pijw35kx(real_T in1_data[], int32_T *in1_size,
  const real_T in2_data[], const int32_T *in2_size, const real_T in3[4], int32_T
  in4)
{
  ros_code_B.in3_c = in3[in4 + 1];
  ros_code_B.in2_size_idx_0_n = *in1_size == 1 ? *in2_size : *in1_size;
  ros_code_B.stride_0_0_h = (*in2_size != 1);
  ros_code_B.stride_1_0_b = (*in1_size != 1);
  ros_code_B.loop_ub_o = *in1_size == 1 ? *in2_size : *in1_size;
  for (ros_code_B.i10 = 0; ros_code_B.i10 < ros_code_B.loop_ub_o; ros_code_B.i10
       ++) {
    ros_code_B.in2_data_j[ros_code_B.i10] = in2_data[ros_code_B.i10 *
      ros_code_B.stride_0_0_h] * in1_data[ros_code_B.i10 *
      ros_code_B.stride_1_0_b] + ros_code_B.in3_c;
  }

  *in1_size = ros_code_B.in2_size_idx_0_n;
  if (ros_code_B.in2_size_idx_0_n - 1 >= 0) {
    memcpy(&in1_data[0], &ros_code_B.in2_data_j[0], ros_code_B.in2_size_idx_0_n *
           sizeof(real_T));
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_polyval_on(const real_T p[4], const real_T x_data[], const
  int32_T *x_size, real_T y_data[], int32_T *y_size)
{
  *y_size = *x_size;
  if (*x_size != 0) {
    ros_code_B.y_idx_0_n = *x_size;
    *y_size = *x_size;
    for (ros_code_B.i9 = 0; ros_code_B.i9 < ros_code_B.y_idx_0_n; ros_code_B.i9
         ++) {
      y_data[ros_code_B.i9] = p[0];
    }

    for (ros_code_B.y_idx_0_n = 0; ros_code_B.y_idx_0_n < 3;
         ros_code_B.y_idx_0_n++) {
      if (*x_size == *y_size) {
        ros_code_B.p_ei = p[ros_code_B.y_idx_0_n + 1];
        *y_size = *x_size;
        ros_code_B.loop_ub_cy = *x_size;
        ros_code_B.scalarLB_he = (*x_size / 2) << 1;
        ros_code_B.vectorUB_kq = ros_code_B.scalarLB_he - 2;
        for (ros_code_B.i9 = 0; ros_code_B.i9 <= ros_code_B.vectorUB_kq;
             ros_code_B.i9 += 2) {
          __m128d tmp;
          tmp = _mm_loadu_pd(&y_data[ros_code_B.i9]);
          _mm_storeu_pd(&y_data[ros_code_B.i9], _mm_add_pd(_mm_mul_pd
            (_mm_loadu_pd(&x_data[ros_code_B.i9]), tmp), _mm_set1_pd
            (ros_code_B.p_ei)));
        }

        for (ros_code_B.i9 = ros_code_B.scalarLB_he; ros_code_B.i9 <
             ros_code_B.loop_ub_cy; ros_code_B.i9++) {
          y_data[ros_code_B.i9] = x_data[ros_code_B.i9] * y_data[ros_code_B.i9]
            + ros_code_B.p_ei;
        }
      } else {
        ros_c_binary_expand_op_pijw35kx(y_data, y_size, x_data, x_size, p,
          ros_code_B.y_idx_0_n);
      }
    }
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_abs(const real_T x_data[], const int32_T *x_size, real_T
  y_data[], int32_T *y_size)
{
  *y_size = *x_size;
  for (int32_T k = 0; k < *x_size; k++) {
    y_data[k] = fabs(x_data[k]);
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
      } else if (rtIsNaN(x_data[0])) {
        if (!rtIsNaN(ex)) {
        } else {
          ex = x_data[0];
        }
      } else {
        ex = x_data[0];
      }
    }
  } else {
    int32_T idx;
    if (!rtIsNaN(x_data[0])) {
      idx = 1;
    } else {
      int32_T k;
      boolean_T exitg1;
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= *x_size)) {
        if (!rtIsNaN(x_data[k - 1])) {
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
static boolean_T ros_code_all(const boolean_T x[4])
{
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= 3)) {
    if (!x[k]) {
      y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return y;
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_roots_n(const real_T c[4], creal_T r_data[], int32_T
  *r_size)
{
  r_data[0].re = 0.0;
  r_data[0].im = 0.0;
  r_data[1].re = 0.0;
  r_data[1].im = 0.0;
  r_data[2].re = 0.0;
  r_data[2].im = 0.0;
  ros_code_B.k1 = 1;
  while ((ros_code_B.k1 <= 4) && (!(c[ros_code_B.k1 - 1] != 0.0))) {
    ros_code_B.k1++;
  }

  ros_code_B.k2 = 4;
  while ((ros_code_B.k2 >= ros_code_B.k1) && (!(c[ros_code_B.k2 - 1] != 0.0))) {
    ros_code_B.k2--;
  }

  if (ros_code_B.k1 < ros_code_B.k2) {
    boolean_T exitg1;
    ros_code_B.companDim = ros_code_B.k2 - ros_code_B.k1;
    exitg1 = false;
    while ((!exitg1) && (ros_code_B.companDim > 0)) {
      boolean_T exitg2;
      ros_code_B.j = 0;
      exitg2 = false;
      while ((!exitg2) && (ros_code_B.j + 1 <= ros_code_B.companDim)) {
        ros_code_B.ctmp[ros_code_B.j] = c[ros_code_B.k1 + ros_code_B.j] /
          c[ros_code_B.k1 - 1];
        if (rtIsInf(fabs(ros_code_B.ctmp[ros_code_B.j]))) {
          exitg2 = true;
        } else {
          ros_code_B.j++;
        }
      }

      if (ros_code_B.j + 1 > ros_code_B.companDim) {
        exitg1 = true;
      } else {
        ros_code_B.k1++;
        ros_code_B.companDim--;
      }
    }

    if (ros_code_B.companDim < 1) {
      if (4 - ros_code_B.k2 < 1) {
        *r_size = 0;
      } else {
        *r_size = 4 - ros_code_B.k2;
      }
    } else {
      ros_code_B.a_size[0] = ros_code_B.companDim;
      ros_code_B.a_size[1] = ros_code_B.companDim;
      ros_code_B.k1 = ros_code_B.companDim * ros_code_B.companDim - 1;
      memset(&ros_code_B.a_data[0], 0, (ros_code_B.k1 + 1) * sizeof(real_T));
      ros_code_B.k1 = 0;
      while (ros_code_B.k1 <= ros_code_B.companDim - 2) {
        ros_code_B.j = ros_code_B.companDim * ros_code_B.k1;
        ros_code_B.a_data[ros_code_B.j] = -ros_code_B.ctmp[ros_code_B.k1];
        ros_code_B.a_data[(ros_code_B.k1 + ros_code_B.j) + 1] = 1.0;
        ros_code_B.k1++;
      }

      ros_code_B.a_data[ros_code_B.companDim * (ros_code_B.companDim - 1)] =
        -ros_code_B.ctmp[ros_code_B.companDim - 1];
      ros_code_B.k1 = 0;
      while (ros_code_B.k1 <= 3 - ros_code_B.k2) {
        r_data[ros_code_B.k1].re = 0.0;
        r_data[ros_code_B.k1].im = 0.0;
        ros_code_B.k1++;
      }

      ros_code_eig(ros_code_B.a_data, ros_code_B.a_size, ros_code_B.eiga_data,
                   &ros_code_B.eiga_size);
      ros_code_B.k1 = 0;
      while (ros_code_B.k1 <= ros_code_B.companDim - 1) {
        r_data[(ros_code_B.k1 - ros_code_B.k2) + 4] =
          ros_code_B.eiga_data[ros_code_B.k1];
        ros_code_B.k1++;
      }

      *r_size = (ros_code_B.companDim - ros_code_B.k2) + 4;
    }
  } else if (4 - ros_code_B.k2 < 1) {
    *r_size = 0;
  } else {
    *r_size = 4 - ros_code_B.k2;
  }
}

static void ros__binary_expand_op_pijw35kxv(real_T in1_data[], int32_T *in1_size,
  const real_T in2_data[], const int32_T *in2_size, const real_T in3[5], int32_T
  in4)
{
  ros_code_B.in3_p = in3[in4 + 1];
  ros_code_B.in2_size_idx_0 = *in1_size == 1 ? *in2_size : *in1_size;
  ros_code_B.stride_0_0_j = (*in2_size != 1);
  ros_code_B.stride_1_0_o = (*in1_size != 1);
  ros_code_B.loop_ub_cs = *in1_size == 1 ? *in2_size : *in1_size;
  for (ros_code_B.i8 = 0; ros_code_B.i8 < ros_code_B.loop_ub_cs; ros_code_B.i8++)
  {
    ros_code_B.in2_data_f[ros_code_B.i8] = in2_data[ros_code_B.i8 *
      ros_code_B.stride_0_0_j] * in1_data[ros_code_B.i8 *
      ros_code_B.stride_1_0_o] + ros_code_B.in3_p;
  }

  *in1_size = ros_code_B.in2_size_idx_0;
  if (ros_code_B.in2_size_idx_0 - 1 >= 0) {
    memcpy(&in1_data[0], &ros_code_B.in2_data_f[0], ros_code_B.in2_size_idx_0 *
           sizeof(real_T));
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static void ros_code_polyval_ong(const real_T p[5], const real_T x_data[], const
  int32_T *x_size, real_T y_data[], int32_T *y_size)
{
  *y_size = *x_size;
  if (*x_size != 0) {
    ros_code_B.y_idx_0 = *x_size;
    *y_size = *x_size;
    for (ros_code_B.i7 = 0; ros_code_B.i7 < ros_code_B.y_idx_0; ros_code_B.i7++)
    {
      y_data[ros_code_B.i7] = p[0];
    }

    for (ros_code_B.y_idx_0 = 0; ros_code_B.y_idx_0 < 4; ros_code_B.y_idx_0++) {
      if (*x_size == *y_size) {
        ros_code_B.p_p = p[ros_code_B.y_idx_0 + 1];
        *y_size = *x_size;
        ros_code_B.loop_ub_eg = *x_size;
        ros_code_B.scalarLB_h = (*x_size / 2) << 1;
        ros_code_B.vectorUB_k = ros_code_B.scalarLB_h - 2;
        for (ros_code_B.i7 = 0; ros_code_B.i7 <= ros_code_B.vectorUB_k;
             ros_code_B.i7 += 2) {
          __m128d tmp;
          tmp = _mm_loadu_pd(&y_data[ros_code_B.i7]);
          _mm_storeu_pd(&y_data[ros_code_B.i7], _mm_add_pd(_mm_mul_pd
            (_mm_loadu_pd(&x_data[ros_code_B.i7]), tmp), _mm_set1_pd
            (ros_code_B.p_p)));
        }

        for (ros_code_B.i7 = ros_code_B.scalarLB_h; ros_code_B.i7 <
             ros_code_B.loop_ub_eg; ros_code_B.i7++) {
          y_data[ros_code_B.i7] = x_data[ros_code_B.i7] * y_data[ros_code_B.i7]
            + ros_code_B.p_p;
        }
      } else {
        ros__binary_expand_op_pijw35kxv(y_data, y_size, x_data, x_size, p,
          ros_code_B.y_idx_0);
      }
    }
  }
}

// Function for MATLAB Function: '<S3>/reducePath'
static boolean_T ros_code_all_j(const boolean_T x[3])
{
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= 2)) {
    if (!x[k]) {
      y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return y;
}

// Model step function
void ros_code_step(void)
{
  __m128d tmp;
  __m128d tmp_0;
  int8_T d[2];
  int8_T g_data;
  boolean_T d_data[2];
  boolean_T e_data[2];
  boolean_T mask1;
  boolean_T mask2;
  boolean_T positiveInput_data;
  static const int8_T s[9] = { 2, 0, 0, 0, 2, 0, 0, 0, 3 };

  static const int8_T b_a[15] = { 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 };

  static const real_T y[9] = { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.5 };

  static const int8_T u[968] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 20 };

  static const int8_T t[4] = { 1, 0, 0, 1 };

  static const int8_T ed[10] = { 0, 0, 0, 0, 0, 0, 1, 0, 0, 1 };

  static const real_T l[8] = { 0.5, 0.25, 0.5, -0.25, -0.5, -0.25, -0.5, 0.25 };

  static const real_T m[8] = { 1.0, 0.5, 1.0, -0.5, -1.0, -0.5, -1.0, 0.5 };

  boolean_T exitg1;
  if (ros_code_M->Timing.TaskCounters.TID[2] == 0) {
    // Outputs for Atomic SubSystem: '<Root>/Subscribe2'
    // MATLABSystem: '<S6>/SourceBlock'
    mask1 = Sub_ros_code_1565.getLatestMessage(&ros_code_B.b_varargout_2_l);

    // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S26>/Enable'

    if (mask1) {
      // SignalConversion generated from: '<S26>/In1'
      ros_code_B.In1_a = ros_code_B.b_varargout_2_l;
    }

    // End of MATLABSystem: '<S6>/SourceBlock'
    // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe2'

    // Outputs for Atomic SubSystem: '<Root>/current_state_convert1'
    // MATLAB Function: '<S7>/MATLAB Function'
    ros_code_B.aSinInput = 1.0 / sqrt(((ros_code_B.In1_a.Pose.Pose.Orientation.X
      * ros_code_B.In1_a.Pose.Pose.Orientation.X +
      ros_code_B.In1_a.Pose.Pose.Orientation.Y *
      ros_code_B.In1_a.Pose.Pose.Orientation.Y) +
      ros_code_B.In1_a.Pose.Pose.Orientation.Z *
      ros_code_B.In1_a.Pose.Pose.Orientation.Z) +
      ros_code_B.In1_a.Pose.Pose.Orientation.W *
      ros_code_B.In1_a.Pose.Pose.Orientation.W);
    ros_code_B.y[0] = ros_code_B.In1_a.Pose.Pose.Orientation.X *
      ros_code_B.aSinInput;
    ros_code_B.y[1] = ros_code_B.In1_a.Pose.Pose.Orientation.Y *
      ros_code_B.aSinInput;
    ros_code_B.y[2] = ros_code_B.In1_a.Pose.Pose.Orientation.Z *
      ros_code_B.aSinInput;
    ros_code_B.y[3] = ros_code_B.In1_a.Pose.Pose.Orientation.W *
      ros_code_B.aSinInput;
    ros_code_B.aSinInput = (ros_code_B.y[1] * ros_code_B.y[3] - ros_code_B.y[0] *
      ros_code_B.y[2]) * -2.0;
    mask1 = (ros_code_B.aSinInput >= 0.99999999999999778);
    mask2 = (ros_code_B.aSinInput <= -0.99999999999999778);
    if (ros_code_B.aSinInput >= 0.99999999999999778) {
      ros_code_B.aSinInput = 1.0;
    }

    if (mask2) {
      ros_code_B.aSinInput = -1.0;
    }

    ros_code_B.global_path_num = ros_code_B.y[0] * ros_code_B.y[0];
    ros_code_B.predict_accurate_index = ros_code_B.y[1] * ros_code_B.y[1];
    ros_code_B.ds = ros_code_B.y[2] * ros_code_B.y[2];
    ros_code_B.mean_angle = ros_code_B.y[3] * ros_code_B.y[3];
    ros_code_B.eulZYX[0] = rt_atan2d_snf((ros_code_B.y[1] * ros_code_B.y[2] +
      ros_code_B.y[0] * ros_code_B.y[3]) * 2.0, ((ros_code_B.global_path_num +
      ros_code_B.predict_accurate_index) - ros_code_B.ds) -
      ros_code_B.mean_angle);
    ros_code_B.eulZYX[1] = asin(ros_code_B.aSinInput);
    ros_code_B.eulZYX[2] = rt_atan2d_snf((ros_code_B.y[2] * ros_code_B.y[3] +
      ros_code_B.y[0] * ros_code_B.y[1]) * 2.0, ((ros_code_B.global_path_num -
      ros_code_B.predict_accurate_index) - ros_code_B.ds) +
      ros_code_B.mean_angle);
    ros_code_B.i = 0;
    if (mask1 || mask2) {
      ros_code_B.i = 1;
    }

    ros_code_B.x_size_k = ros_code_B.i;
    if (ros_code_B.i - 1 >= 0) {
      ros_code_B.x_data_m = ros_code_B.aSinInput;
    }

    ros_code_B.nx = 0;
    while (ros_code_B.nx <= ros_code_B.i - 1) {
      if (!rtIsNaN(ros_code_B.x_data_m)) {
        if (ros_code_B.x_data_m < 0.0) {
          ros_code_B.x_data_m = -1.0;
        } else {
          ros_code_B.x_data_m = (ros_code_B.x_data_m > 0.0);
        }
      }

      ros_code_B.nx = 1;
    }

    ros_code_B.lastBlockLength = 0;
    if (mask1 || mask2) {
      ros_code_B.lastBlockLength = 1;
    }

    ros_code_B.d_size = static_cast<int8_T>(ros_code_B.lastBlockLength);
    if (static_cast<int8_T>(ros_code_B.lastBlockLength) - 1 >= 0) {
      ros_code_B.d_data = rt_atan2d_snf(ros_code_B.y[1], ros_code_B.y[0]);
    }

    if (mask1 || mask2) {
      g_data = 1;
    }

    if (ros_code_B.i != static_cast<int8_T>(ros_code_B.lastBlockLength)) {
      ros_code_binary_expand_op_pijw3(ros_code_B.eulZYX, &g_data,
        &ros_code_B.x_data_m, &ros_code_B.x_size_k, &ros_code_B.d_data,
        &ros_code_B.d_size);
    }

    ros_code_B.i = 0;
    if (mask1 || mask2) {
      ros_code_B.i = 1;
    }

    if (ros_code_B.i - 1 >= 0) {
      ros_code_B.eulZYX[2] = 0.0;
    }

    ros_code_B.current_state_C[0] = ros_code_B.In1_a.Pose.Pose.Position.X;
    ros_code_B.current_state_C[1] = ros_code_B.In1_a.Pose.Pose.Position.Y;
    ros_code_B.current_state_C[2] = ros_code_B.eulZYX[2];
    ros_code_B.current_state_C[3] = sqrt(ros_code_B.In1_a.Twist.Twist.Linear.X *
      ros_code_B.In1_a.Twist.Twist.Linear.X +
      ros_code_B.In1_a.Twist.Twist.Linear.Y *
      ros_code_B.In1_a.Twist.Twist.Linear.Y);
    ros_code_B.current_state_C[4] = ros_code_B.In1_a.Twist.Twist.Angular.Z;

    // End of MATLAB Function: '<S7>/MATLAB Function'
    // End of Outputs for SubSystem: '<Root>/current_state_convert1'

    // Outputs for Atomic SubSystem: '<Root>/Global_planner'
    // Outputs for Atomic SubSystem: '<S2>/Subscribe1'
    // MATLABSystem: '<S9>/SourceBlock' incorporates:
    //   MATLAB Function: '<S11>/getGlobalPathData'

    mask1 = Sub_ros_code_1497.getLatestMessage(&ros_code_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S2>/get_global_path' incorporates:
    //   EnablePort: '<S11>/Enable'

    // Outputs for Enabled SubSystem: '<S9>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S14>/Enable'

    if (mask1) {
      // MATLAB Function: '<S11>/getGlobalPathData'
      memset(&ros_code_B.global_path_array[0], 0, 60U * sizeof(real_T));
      memset(&ros_code_B.preprocess_global_path_array[0], 0, 10000U * sizeof
             (real_T));
      ros_code_B.global_path_num = 0.0;
      for (ros_code_B.i = 0; ros_code_B.i < 1000; ros_code_B.i++) {
        if ((ros_code_B.b_varargout_2.Poses[ros_code_B.i].Pose.Orientation.X !=
             0.0) || (ros_code_B.b_varargout_2.Poses[ros_code_B.i].
                      Pose.Orientation.Y != 0.0) ||
            (ros_code_B.b_varargout_2.Poses[ros_code_B.i].Pose.Orientation.Z !=
             0.0) || (ros_code_B.b_varargout_2.Poses[ros_code_B.i].
                      Pose.Orientation.W != 0.0)) {
          ros_code_B.global_path_num++;
          ros_code_B.global_path_array[static_cast<int32_T>
            (ros_code_B.global_path_num) - 1] =
            ros_code_B.b_varargout_2.Poses[ros_code_B.i].Pose.Position.X;
          ros_code_B.global_path_array[static_cast<int32_T>
            (ros_code_B.global_path_num) + 19] =
            ros_code_B.b_varargout_2.Poses[ros_code_B.i].Pose.Position.Y;
          ros_code_B.ddls_coeffs[0] =
            ros_code_B.b_varargout_2.Poses[ros_code_B.i].Pose.Orientation.X;
          ros_code_B.ddls_coeffs[1] =
            ros_code_B.b_varargout_2.Poses[ros_code_B.i].Pose.Orientation.Y;
          ros_code_B.ddls_coeffs[2] =
            ros_code_B.b_varargout_2.Poses[ros_code_B.i].Pose.Orientation.Z;
          ros_code_B.ddls_coeffs[3] =
            ros_code_B.b_varargout_2.Poses[ros_code_B.i].Pose.Orientation.W;
          ros_code_quat2eul(ros_code_B.ddls_coeffs, ros_code_B.eulZYX);
          ros_code_B.global_path_array[static_cast<int32_T>
            (ros_code_B.global_path_num) + 39] = ros_code_B.eulZYX[2];
        }
      }

      ros_code_B.global_path_array[19] = ros_code_B.global_path_num;
      ros_code_B.a_m = ros_code_B.global_path_array[static_cast<int32_T>
        (ros_code_B.global_path_num - 1.0) - 1] - ros_code_B.global_path_array[
        static_cast<int32_T>(ros_code_B.global_path_num) - 1];
      ros_code_B.lv_0 = ros_code_B.global_path_array[static_cast<int32_T>
        (ros_code_B.global_path_num - 1.0) + 19] - ros_code_B.global_path_array[
        static_cast<int32_T>(ros_code_B.global_path_num) + 19];
      ros_code_B.aSinInput = rt_roundd_snf((sqrt(ros_code_B.a_m * ros_code_B.a_m
        + ros_code_B.lv_0 * ros_code_B.lv_0) + ros_code_B.global_path_num) *
        100.0);
      if (!(ros_code_B.aSinInput <= 99999.0)) {
        ros_code_B.aSinInput = 99999.0;
      }

      ros_code_linspace(ros_code_B.global_path_num, ros_code_B.aSinInput,
                        ros_code_B.param_new_data, ros_code_B.param_new_size);
      ros_code_B.tmp_size[0] = 1;
      ros_code_B.tmp_size[1] = static_cast<int32_T>(ros_code_B.global_path_num -
        1.0) + 1;
      ros_code_B.nblocks = static_cast<int32_T>(ros_code_B.global_path_num - 1.0);
      for (ros_code_B.nx = 0; ros_code_B.nx <= ros_code_B.nblocks; ros_code_B.nx
           ++) {
        ros_code_B.tmp_data_o[ros_code_B.nx] = static_cast<real_T>(ros_code_B.nx)
          + 1.0;
      }

      ros_code_B.nblocks = static_cast<int32_T>(ros_code_B.global_path_num);
      ros_code_B.rtb_global_path_array_size = static_cast<int32_T>
        (ros_code_B.global_path_num);
      if (ros_code_B.nblocks - 1 >= 0) {
        memcpy(&ros_code_B.rtb_global_path_array_data[0],
               &ros_code_B.global_path_array[0], ros_code_B.nblocks * sizeof
               (real_T));
      }

      // MATLAB Function: '<S11>/getGlobalPathData'
      ros_code_interp1(ros_code_B.tmp_data_o, ros_code_B.tmp_size,
                       ros_code_B.rtb_global_path_array_data,
                       &ros_code_B.rtb_global_path_array_size,
                       ros_code_B.param_new_data, ros_code_B.param_new_size,
                       ros_code_B.X_interp_data, ros_code_B.g_size);
      ros_code_B.tmp_size[0] = 1;
      ros_code_B.tmp_size[1] = static_cast<int32_T>(ros_code_B.global_path_num -
        1.0) + 1;
      ros_code_B.nblocks = static_cast<int32_T>(ros_code_B.global_path_num - 1.0);
      for (ros_code_B.nx = 0; ros_code_B.nx <= ros_code_B.nblocks; ros_code_B.nx
           ++) {
        ros_code_B.tmp_data_o[ros_code_B.nx] = static_cast<real_T>(ros_code_B.nx)
          + 1.0;
      }

      ros_code_B.nblocks = static_cast<int32_T>(ros_code_B.global_path_num);
      ros_code_B.rtb_global_path_array_size = static_cast<int32_T>
        (ros_code_B.global_path_num);
      if (ros_code_B.nblocks - 1 >= 0) {
        memcpy(&ros_code_B.rtb_global_path_array_data[0],
               &ros_code_B.global_path_array[20], ros_code_B.nblocks * sizeof
               (real_T));
      }

      // MATLAB Function: '<S11>/getGlobalPathData'
      ros_code_interp1(ros_code_B.tmp_data_o, ros_code_B.tmp_size,
                       ros_code_B.rtb_global_path_array_data,
                       &ros_code_B.rtb_global_path_array_size,
                       ros_code_B.param_new_data, ros_code_B.param_new_size,
                       ros_code_B.Y_interp_data, ros_code_B.Y_interp_size);
      ros_code_B.nblocks = static_cast<int32_T>(ros_code_B.global_path_num);
      ros_code_B.rtb_global_path_array_size = static_cast<int32_T>
        (ros_code_B.global_path_num);
      if (ros_code_B.nblocks - 1 >= 0) {
        memcpy(&ros_code_B.rtb_global_path_array_data[0],
               &ros_code_B.global_path_array[40], ros_code_B.nblocks * sizeof
               (real_T));
      }

      // MATLAB Function: '<S11>/getGlobalPathData'
      ros_code_B.nx = 0;
      while (ros_code_B.nx <= static_cast<int32_T>(ros_code_B.global_path_num) -
             1) {
        ros_code_B.rtb_global_path_array_data[ros_code_B.nx] = cos
          (ros_code_B.rtb_global_path_array_data[ros_code_B.nx]);
        ros_code_B.nx++;
      }

      ros_code_B.tmp_size[0] = 1;
      ros_code_B.tmp_size[1] = static_cast<int32_T>(ros_code_B.global_path_num -
        1.0) + 1;
      ros_code_B.nblocks = static_cast<int32_T>(ros_code_B.global_path_num - 1.0);
      for (ros_code_B.nx = 0; ros_code_B.nx <= ros_code_B.nblocks; ros_code_B.nx
           ++) {
        ros_code_B.tmp_data_o[ros_code_B.nx] = static_cast<real_T>(ros_code_B.nx)
          + 1.0;
      }

      ros_code_interp1(ros_code_B.tmp_data_o, ros_code_B.tmp_size,
                       ros_code_B.rtb_global_path_array_data,
                       &ros_code_B.rtb_global_path_array_size,
                       ros_code_B.param_new_data, ros_code_B.param_new_size,
                       ros_code_B.cos_interp_data, ros_code_B.cos_interp_size);
      ros_code_B.nblocks = static_cast<int32_T>(ros_code_B.global_path_num);
      ros_code_B.rtb_global_path_array_size = static_cast<int32_T>
        (ros_code_B.global_path_num);
      if (ros_code_B.nblocks - 1 >= 0) {
        memcpy(&ros_code_B.rtb_global_path_array_data[0],
               &ros_code_B.global_path_array[40], ros_code_B.nblocks * sizeof
               (real_T));
      }

      // MATLAB Function: '<S11>/getGlobalPathData'
      ros_code_B.nx = 0;
      while (ros_code_B.nx <= static_cast<int32_T>(ros_code_B.global_path_num) -
             1) {
        ros_code_B.rtb_global_path_array_data[ros_code_B.nx] = sin
          (ros_code_B.rtb_global_path_array_data[ros_code_B.nx]);
        ros_code_B.nx++;
      }

      ros_code_B.tmp_size[0] = 1;
      ros_code_B.tmp_size[1] = static_cast<int32_T>(ros_code_B.global_path_num -
        1.0) + 1;
      ros_code_B.nblocks = static_cast<int32_T>(ros_code_B.global_path_num - 1.0);
      for (ros_code_B.nx = 0; ros_code_B.nx <= ros_code_B.nblocks; ros_code_B.nx
           ++) {
        ros_code_B.tmp_data_o[ros_code_B.nx] = static_cast<real_T>(ros_code_B.nx)
          + 1.0;
      }

      ros_code_interp1(ros_code_B.tmp_data_o, ros_code_B.tmp_size,
                       ros_code_B.rtb_global_path_array_data,
                       &ros_code_B.rtb_global_path_array_size,
                       ros_code_B.param_new_data, ros_code_B.param_new_size,
                       ros_code_B.new_Theta_interp_data,
                       ros_code_B.new_Theta_interp_size);
      ros_code_B.tmp_size_o[0] = ros_code_B.new_Theta_interp_size[1];
      ros_code_B.tmp_size_o[1] = 2;
      ros_code_B.nblocks = ros_code_B.new_Theta_interp_size[1];
      if (ros_code_B.nblocks - 1 >= 0) {
        memcpy(&ros_code_B.trigo_interp_data[0],
               &ros_code_B.new_Theta_interp_data[0], ros_code_B.nblocks * sizeof
               (real_T));
      }

      // MATLAB Function: '<S11>/getGlobalPathData'
      ros_code_B.nblocks = ros_code_B.cos_interp_size[1];
      for (ros_code_B.nx = 0; ros_code_B.nx < ros_code_B.nblocks; ros_code_B.nx
           ++) {
        ros_code_B.trigo_interp_data[ros_code_B.nx + ros_code_B.tmp_size_o[0]] =
          ros_code_B.cos_interp_data[ros_code_B.nx];
      }

      ros_code_minimum2(ros_code_B.trigo_interp_data, ros_code_B.tmp_size_o,
                        ros_code_B.tmp_data, ros_code_B.tmp_size);
      ros_code_maximum2(ros_code_B.tmp_data, ros_code_B.tmp_size,
                        ros_code_B.trigo_interp_data, ros_code_B.tmp_size_o);
      ros_code_B.i = static_cast<int32_T>(ros_code_B.aSinInput);
      ros_code_B.lastBlockLength = static_cast<int32_T>(ros_code_B.aSinInput) -
        1;
      if (ros_code_B.lastBlockLength >= 0) {
        memset(&ros_code_B.new_Theta_interp_data[0], 0,
               (ros_code_B.lastBlockLength + 1) * sizeof(real_T));
      }

      // MATLAB Function: '<S11>/getGlobalPathData'
      ros_code_B.nx = 0;
      while (ros_code_B.nx <= static_cast<int32_T>(ros_code_B.aSinInput) - 1) {
        if (ros_code_B.trigo_interp_data[ros_code_B.nx] >= 0.0) {
          ros_code_B.new_Theta_interp_data[ros_code_B.nx] = acos
            (ros_code_B.trigo_interp_data[ros_code_B.nx + ros_code_B.tmp_size_o
             [0]]);
        } else {
          ros_code_B.new_Theta_interp_data[ros_code_B.nx] = -acos
            (ros_code_B.trigo_interp_data[ros_code_B.nx + ros_code_B.tmp_size_o
             [0]]);
        }

        ros_code_B.nx++;
      }

      ros_code_gradient(ros_code_B.X_interp_data, ros_code_B.g_size,
                        ros_code_B.param_new_data, ros_code_B.param_new_size);
      ros_code_gradient(ros_code_B.Y_interp_data, ros_code_B.Y_interp_size,
                        ros_code_B.cos_interp_data, ros_code_B.cos_interp_size);
      ros_code_gradient(ros_code_B.param_new_data, ros_code_B.param_new_size,
                        ros_code_B.sin_interp_data, ros_code_B.tmp_size);
      ros_code_gradient(ros_code_B.cos_interp_data, ros_code_B.cos_interp_size,
                        ros_code_B.ddy_data, ros_code_B.tmp_size);
      ros_code_B.nx = 0;
      while (ros_code_B.nx <= static_cast<int32_T>(ros_code_B.aSinInput) - 1) {
        ros_code_B.firstBlockLength = ros_code_B.nx;
        ros_code_B.predict_accurate_index =
          ros_code_B.param_new_data[ros_code_B.firstBlockLength];
        ros_code_B.mean_angle =
          ros_code_B.cos_interp_data[ros_code_B.firstBlockLength];
        ros_code_B.global_path_num = rt_powd_snf
          (ros_code_B.predict_accurate_index * ros_code_B.predict_accurate_index
           + ros_code_B.mean_angle * ros_code_B.mean_angle, 1.5);
        if (ros_code_B.global_path_num != 0.0) {
          ros_code_B.curvature_data[ros_code_B.firstBlockLength] =
            (ros_code_B.predict_accurate_index *
             ros_code_B.ddy_data[ros_code_B.firstBlockLength] -
             ros_code_B.mean_angle *
             ros_code_B.sin_interp_data[ros_code_B.firstBlockLength]) /
            ros_code_B.global_path_num;
        } else {
          ros_code_B.curvature_data[ros_code_B.firstBlockLength] = 0.0;
        }

        ros_code_B.nx++;
      }

      if (ros_code_B.lastBlockLength >= 0) {
        memset(&ros_code_B.param_new_data[0], 0, (ros_code_B.lastBlockLength + 1)
               * sizeof(real_T));
      }

      // MATLAB Function: '<S11>/getGlobalPathData'
      ros_code_B.param_new_data[0] = 0.0;
      ros_code_B.nx = 0;
      while (ros_code_B.nx <= static_cast<int32_T>(ros_code_B.aSinInput + -1.0)
             - 1) {
        ros_code_B.firstBlockLength = ros_code_B.nx + 1;
        ros_code_B.lastBlockLength = ros_code_B.nx;
        ros_code_B.global_path_num =
          ros_code_B.X_interp_data[ros_code_B.firstBlockLength] -
          ros_code_B.X_interp_data[ros_code_B.lastBlockLength];
        ros_code_B.predict_accurate_index =
          ros_code_B.Y_interp_data[ros_code_B.firstBlockLength] -
          ros_code_B.Y_interp_data[ros_code_B.lastBlockLength];
        ros_code_B.param_new_data[ros_code_B.firstBlockLength] = sqrt
          (ros_code_B.global_path_num * ros_code_B.global_path_num +
           ros_code_B.predict_accurate_index * ros_code_B.predict_accurate_index)
          + ros_code_B.param_new_data[ros_code_B.lastBlockLength];
        ros_code_B.nx++;
      }

      ros_code_B.preprocess_global_path_array[1999] = ros_code_B.aSinInput;
      ros_code_B.nblocks = ros_code_B.g_size[1];
      if (ros_code_B.nblocks - 1 >= 0) {
        memcpy(&ros_code_B.preprocess_global_path_array[0],
               &ros_code_B.X_interp_data[0], ros_code_B.nblocks * sizeof(real_T));
      }

      // MATLAB Function: '<S11>/getGlobalPathData'
      ros_code_B.nblocks = ros_code_B.Y_interp_size[1];
      if (ros_code_B.nblocks - 1 >= 0) {
        memcpy(&ros_code_B.preprocess_global_path_array[2000],
               &ros_code_B.Y_interp_data[0], ros_code_B.nblocks * sizeof(real_T));
      }

      // MATLAB Function: '<S11>/getGlobalPathData'
      ros_code_B.nblocks = static_cast<int32_T>(ros_code_B.aSinInput);
      if (ros_code_B.nblocks - 1 >= 0) {
        memcpy(&ros_code_B.preprocess_global_path_array[4000],
               &ros_code_B.new_Theta_interp_data[0], ros_code_B.nblocks * sizeof
               (real_T));
      }

      if (ros_code_B.i - 1 >= 0) {
        memcpy(&ros_code_B.preprocess_global_path_array[6000],
               &ros_code_B.curvature_data[0], ros_code_B.i * sizeof(real_T));
      }

      // MATLAB Function: '<S11>/getGlobalPathData'
      ros_code_B.nblocks = static_cast<int32_T>(ros_code_B.aSinInput);
      if (ros_code_B.nblocks - 1 >= 0) {
        memcpy(&ros_code_B.preprocess_global_path_array[8000],
               &ros_code_B.param_new_data[0], ros_code_B.nblocks * sizeof(real_T));
      }

      // MATLAB Function: '<S11>/getGlobalPathData'
      ros_code_B.get_global_pose = 1.0;
    }

    // End of MATLABSystem: '<S9>/SourceBlock'
    // End of Outputs for SubSystem: '<S9>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<S2>/get_global_path'
    // End of Outputs for SubSystem: '<S2>/Subscribe1'

    // Outputs for Atomic SubSystem: '<S2>/Subscribe'
    // MATLABSystem: '<S8>/SourceBlock'
    mask1 = Sub_ros_code_1496.getLatestMessage(&ros_code_B.b_varargout_2_m);

    // Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S13>/Enable'

    if (mask1) {
      // SignalConversion generated from: '<S13>/In1'
      ros_code_B.In1_i = ros_code_B.b_varargout_2_m;
    }

    // End of MATLABSystem: '<S8>/SourceBlock'
    // End of Outputs for SubSystem: '<S8>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<S2>/Subscribe'

    // MATLAB Function: '<S2>/getObjectData'
    memset(&ros_code_B.object_array[0], 0, 40U * sizeof(real_T));
    ros_code_B.object_num = 0.0;
    while (ros_code_B.In1_i.Markers[static_cast<int32_T>(ros_code_B.object_num +
            1.0) - 1].Id != 0) {
      ros_code_B.object_num++;
    }

    ros_code_B.object_array[9] = ros_code_B.object_num;
    ros_code_B.i = 0;
    while (ros_code_B.i <= static_cast<int32_T>(ros_code_B.object_num) - 1) {
      ros_code_B.object_array[ros_code_B.i] =
        ros_code_B.In1_i.Markers[ros_code_B.i].Pose.Position.X;
      ros_code_B.object_array[ros_code_B.i + 10] =
        ros_code_B.In1_i.Markers[ros_code_B.i].Pose.Position.Y;
      ros_code_B.object_array[ros_code_B.i + 20] =
        ros_code_B.In1_i.Markers[ros_code_B.i].Scale.X;
      ros_code_B.object_array[ros_code_B.i + 30] =
        ros_code_B.In1_i.Markers[ros_code_B.i].Scale.Y;
      ros_code_B.i++;
    }

    // End of MATLAB Function: '<S2>/getObjectData'

    // MATLAB Function: '<S2>/objectConvert'
    memset(&ros_code_B.object_array_F[0], 0, 30U * sizeof(real_T));
    if (ros_code_B.get_global_pose != 0.0) {
      ros_code_B.i = 0;
      while (ros_code_B.i <= static_cast<int32_T>(ros_code_B.object_array[9]) -
             1) {
        ros_code_B.aSinInput = ros_code_B.object_array[ros_code_B.i];
        ros_code_B.object_num = ros_code_B.object_array[ros_code_B.i + 10];
        for (ros_code_B.nx = 0; ros_code_B.nx <= 1998; ros_code_B.nx += 2) {
          tmp_0 = _mm_loadu_pd
            (&ros_code_B.preprocess_global_path_array[ros_code_B.nx]);
          tmp_0 = _mm_sub_pd(tmp_0, _mm_set1_pd(ros_code_B.aSinInput));
          tmp = _mm_loadu_pd
            (&ros_code_B.preprocess_global_path_array[ros_code_B.nx + 2000]);
          tmp = _mm_sub_pd(tmp, _mm_set1_pd(ros_code_B.object_num));
          _mm_storeu_pd(&ros_code_B.distances[ros_code_B.nx], _mm_sqrt_pd
                        (_mm_add_pd(_mm_mul_pd(tmp, tmp), _mm_mul_pd(tmp_0,
            tmp_0))));
        }

        if (!rtIsNaN(ros_code_B.distances[0])) {
          ros_code_B.nx = 1;
        } else {
          ros_code_B.nx = 0;
          ros_code_B.nblocks = 2;
          exitg1 = false;
          while ((!exitg1) && (ros_code_B.nblocks < 2001)) {
            if (!rtIsNaN(ros_code_B.distances[ros_code_B.nblocks - 1])) {
              ros_code_B.nx = ros_code_B.nblocks;
              exitg1 = true;
            } else {
              ros_code_B.nblocks++;
            }
          }
        }

        if (ros_code_B.nx == 0) {
          ros_code_B.lastBlockLength = 0;
        } else {
          ros_code_B.ex = ros_code_B.distances[ros_code_B.nx - 1];
          ros_code_B.lastBlockLength = ros_code_B.nx - 1;
          while (ros_code_B.nx + 1 <= 2000) {
            if (ros_code_B.ex > ros_code_B.distances[ros_code_B.nx]) {
              ros_code_B.ex = ros_code_B.distances[ros_code_B.nx];
              ros_code_B.lastBlockLength = ros_code_B.nx;
            }

            ros_code_B.nx++;
          }
        }

        ros_code_B.aSinInput = ros_code_B.object_array[ros_code_B.i] -
          ros_code_B.preprocess_global_path_array[ros_code_B.lastBlockLength];
        ros_code_B.global_path_num = ros_code_B.object_num -
          ros_code_B.preprocess_global_path_array[ros_code_B.lastBlockLength +
          2000];
        ros_code_B.predict_accurate_index =
          ros_code_B.preprocess_global_path_array[ros_code_B.lastBlockLength +
          4000];
        ros_code_B.ds = ros_code_B.global_path_num * cos
          (ros_code_B.predict_accurate_index) - ros_code_B.aSinInput * sin
          (ros_code_B.predict_accurate_index);
        ros_code_B.object_array_F[ros_code_B.i] =
          ros_code_B.preprocess_global_path_array[ros_code_B.lastBlockLength +
          8000];
        if (!rtIsNaN(ros_code_B.ds)) {
          if (ros_code_B.ds < 0.0) {
            ros_code_B.ds = -1.0;
          } else {
            ros_code_B.ds = (ros_code_B.ds > 0.0);
          }
        }

        ros_code_B.object_array_F[ros_code_B.i + 10] = sqrt(ros_code_B.aSinInput
          * ros_code_B.aSinInput + ros_code_B.global_path_num *
          ros_code_B.global_path_num) * ros_code_B.ds;
        ros_code_B.object_array_F[ros_code_B.i + 20] =
          ros_code_B.lastBlockLength + 1;
        ros_code_B.i++;
      }

      ros_code_B.object_array_F[9] = ros_code_B.object_array[9];
    }

    // End of MATLAB Function: '<S2>/objectConvert'
    // End of Outputs for SubSystem: '<Root>/Global_planner'
  }

  // Clock: '<Root>/Clock2'
  ros_code_B.aSinInput = ros_code_M->Timing.t[0];
  if (ros_code_M->Timing.TaskCounters.TID[2] == 0) {
    boolean_T rEQ0;

    // Outputs for Atomic SubSystem: '<Root>/Lattice_planner'
    // MATLAB Function: '<S3>/currentStateConvert' incorporates:
    //   Memory: '<S3>/Memory'

    memset(&ros_code_B.current_state_F[0], 0, sizeof(real_T) << 3U);
    ros_code_B.global_path_num = 0.0;
    ros_code_B.predict_accurate_index = 0.0;
    ros_code_B.a_m = ros_code_B.current_state_C[0] -
      ros_code_DW.Memory_PreviousInput[0];
    ros_code_B.lv_0 = ros_code_B.current_state_C[1] -
      ros_code_DW.Memory_PreviousInput[1];
    ros_code_B.ds = sqrt(ros_code_B.a_m * ros_code_B.a_m + ros_code_B.lv_0 *
                         ros_code_B.lv_0);
    if (ros_code_B.get_global_pose != 0.0) {
      ros_code_B.global_path_num = ros_code_B.preprocess_global_path_array[
        static_cast<int32_T>(ros_code_B.preprocess_global_path_array[1999]) +
        7999];
      ros_code_B.sa3 = ros_code_B.preprocess_global_path_array[4000];
      for (ros_code_B.nx = 0; ros_code_B.nx < 199; ros_code_B.nx++) {
        ros_code_B.sa3 += ros_code_B.preprocess_global_path_array[(ros_code_B.nx
          + 1) * 10 + 4000];
      }

      ros_code_B.mean_angle = ros_code_B.sa3 / 200.0;
      ros_code_B.predict_accurate_index = cos(ros_code_B.mean_angle);
      ros_code_B.d_ls = ros_code_B.predict_accurate_index *
        ros_code_B.predict_accurate_index;
      ros_code_B.predict_accurate_index = ros_code_B.current_state_C[0];
      ros_code_B.mean_angle = sin(ros_code_B.mean_angle);
      ros_code_B.mean_angle *= ros_code_B.mean_angle;
      ros_code_B.dd_s = ros_code_B.current_state_C[1];
      for (ros_code_B.nx = 0; ros_code_B.nx < 200; ros_code_B.nx++) {
        ros_code_B.a_m = ros_code_B.preprocess_global_path_array[10 *
          ros_code_B.nx] - ros_code_B.predict_accurate_index;
        ros_code_B.kappa_x = ros_code_B.a_m * ros_code_B.a_m;
        ros_code_B.a_m = ros_code_B.preprocess_global_path_array[10 *
          ros_code_B.nx + 2000] - ros_code_B.dd_s;
        ros_code_B.approximate_distances[ros_code_B.nx] = sqrt(ros_code_B.a_m *
          ros_code_B.a_m * ros_code_B.mean_angle + ros_code_B.d_ls *
          ros_code_B.kappa_x);
      }

      if (!rtIsNaN(ros_code_B.approximate_distances[0])) {
        ros_code_B.nx = 1;
      } else {
        ros_code_B.nx = 0;
        ros_code_B.i = 2;
        exitg1 = false;
        while ((!exitg1) && (ros_code_B.i < 201)) {
          if (!rtIsNaN(ros_code_B.approximate_distances[ros_code_B.i - 1])) {
            ros_code_B.nx = ros_code_B.i;
            exitg1 = true;
          } else {
            ros_code_B.i++;
          }
        }
      }

      if (ros_code_B.nx == 0) {
        ros_code_B.lastBlockLength = 0;
      } else {
        ros_code_B.ex = ros_code_B.approximate_distances[ros_code_B.nx - 1];
        ros_code_B.lastBlockLength = ros_code_B.nx - 1;
        while (ros_code_B.nx + 1 < 201) {
          if (ros_code_B.ex > ros_code_B.approximate_distances[ros_code_B.nx]) {
            ros_code_B.ex = ros_code_B.approximate_distances[ros_code_B.nx];
            ros_code_B.lastBlockLength = ros_code_B.nx;
          }

          ros_code_B.nx++;
        }
      }

      ros_code_B.i = ros_code_B.lastBlockLength * 10 + 1;
      if (ros_code_B.lastBlockLength + 1 == 1) {
        ros_code_B.min_range = 1.0;
        ros_code_B.max_range = 10.0;
      } else if (ros_code_B.i >= ros_code_B.preprocess_global_path_array[1999] -
                 10.0) {
        ros_code_B.min_range = ros_code_B.preprocess_global_path_array[1999] -
          10.0;
        ros_code_B.max_range = ros_code_B.preprocess_global_path_array[1999];
      } else {
        ros_code_B.min_range = static_cast<real_T>(ros_code_B.i) - 5.0;
        ros_code_B.max_range = static_cast<real_T>(ros_code_B.i) + 5.0;
      }

      if (ros_code_B.min_range > ros_code_B.max_range) {
        ros_code_B.c_cg = -1;
        ros_code_B.i = -1;
      } else {
        ros_code_B.c_cg = static_cast<int32_T>(ros_code_B.min_range) - 2;
        ros_code_B.i = static_cast<int32_T>(ros_code_B.max_range) - 1;
      }

      ros_code_B.nx = ros_code_B.i - ros_code_B.c_cg;
      if (ros_code_B.nx == 0) {
        ros_code_B.predict_accurate_index = 0.0;
      } else {
        if (ros_code_B.nx <= 1024) {
          ros_code_B.firstBlockLength = ros_code_B.nx;
          ros_code_B.lastBlockLength = 1024;
          ros_code_B.nblocks = 1;
        } else {
          ros_code_B.firstBlockLength = 1024;
          ros_code_B.lastBlockLength = ros_code_B.nx;
          ros_code_B.nblocks = 2;
        }

        ros_code_B.predict_accurate_index =
          ros_code_B.preprocess_global_path_array[ros_code_B.c_cg + 4001];
        ros_code_B.i = 2;
        while (ros_code_B.i <= ros_code_B.firstBlockLength) {
          ros_code_B.predict_accurate_index +=
            ros_code_B.preprocess_global_path_array[(ros_code_B.c_cg +
            ros_code_B.i) + 4000];
          ros_code_B.i++;
        }

        ros_code_B.i = 2;
        while (ros_code_B.i <= ros_code_B.nblocks) {
          ros_code_B.mean_angle =
            ros_code_B.preprocess_global_path_array[ros_code_B.c_cg + 5025];
          ros_code_B.i = 2;
          while (ros_code_B.i <= ros_code_B.lastBlockLength - 1024) {
            ros_code_B.mean_angle += ros_code_B.preprocess_global_path_array
              [(ros_code_B.c_cg + ros_code_B.i) + 5024];
            ros_code_B.i++;
          }

          ros_code_B.predict_accurate_index += ros_code_B.mean_angle;
          ros_code_B.i = 3;
        }
      }

      ros_code_B.mean_angle = ros_code_B.predict_accurate_index / static_cast<
        real_T>(ros_code_B.nx);
      if (ros_code_B.min_range > ros_code_B.max_range) {
        ros_code_B.e = 0;
        ros_code_B.c_cg = 0;
        ros_code_B.g = 0;
        ros_code_B.firstBlockLength = 0;
      } else {
        ros_code_B.e = static_cast<int32_T>(ros_code_B.min_range) - 1;
        ros_code_B.c_cg = static_cast<int32_T>(ros_code_B.max_range);
        ros_code_B.g = static_cast<int32_T>(ros_code_B.min_range) - 1;
        ros_code_B.firstBlockLength = static_cast<int32_T>(ros_code_B.max_range);
      }

      ros_code_B.predict_accurate_index = cos(ros_code_B.mean_angle);
      ros_code_B.d_ls = ros_code_B.predict_accurate_index *
        ros_code_B.predict_accurate_index;
      ros_code_B.predict_accurate_index = sin(ros_code_B.mean_angle);
      ros_code_B.mean_angle = ros_code_B.predict_accurate_index *
        ros_code_B.predict_accurate_index;
      ros_code_B.predict_accurate_index = ros_code_B.current_state_C[0];
      ros_code_B.nblocks = ros_code_B.c_cg - ros_code_B.e;
      ros_code_B.b_y_size = ros_code_B.nblocks;
      ros_code_B.scalarLB = (ros_code_B.nblocks / 2) << 1;
      ros_code_B.vectorUB = ros_code_B.scalarLB - 2;
      for (ros_code_B.nx = 0; ros_code_B.nx <= ros_code_B.vectorUB;
           ros_code_B.nx += 2) {
        tmp_0 = _mm_loadu_pd
          (&ros_code_B.preprocess_global_path_array[ros_code_B.e + ros_code_B.nx]);
        _mm_storeu_pd(&ros_code_B.distances[ros_code_B.nx], _mm_sub_pd(tmp_0,
          _mm_set1_pd(ros_code_B.predict_accurate_index)));
      }

      for (ros_code_B.nx = ros_code_B.scalarLB; ros_code_B.nx <
           ros_code_B.nblocks; ros_code_B.nx++) {
        ros_code_B.distances[ros_code_B.nx] =
          ros_code_B.preprocess_global_path_array[ros_code_B.e + ros_code_B.nx]
          - ros_code_B.predict_accurate_index;
      }

      ros_code_B.predict_accurate_index = ros_code_B.current_state_C[1];
      ros_code_B.loop_ub = ros_code_B.firstBlockLength - ros_code_B.g;
      ros_code_B.tmp_size_n = ros_code_B.loop_ub;
      ros_code_B.scalarLB_tmp = (ros_code_B.loop_ub / 2) << 1;
      ros_code_B.vectorUB = ros_code_B.scalarLB_tmp - 2;
      for (ros_code_B.nx = 0; ros_code_B.nx <= ros_code_B.vectorUB;
           ros_code_B.nx += 2) {
        tmp_0 = _mm_loadu_pd(&ros_code_B.preprocess_global_path_array
                             [(ros_code_B.g + ros_code_B.nx) + 2000]);
        _mm_storeu_pd(&ros_code_B.tmp_data_k[ros_code_B.nx], _mm_sub_pd(tmp_0,
          _mm_set1_pd(ros_code_B.predict_accurate_index)));
      }

      for (ros_code_B.nx = ros_code_B.scalarLB_tmp; ros_code_B.nx <
           ros_code_B.loop_ub; ros_code_B.nx++) {
        ros_code_B.tmp_data_k[ros_code_B.nx] =
          ros_code_B.preprocess_global_path_array[(ros_code_B.g + ros_code_B.nx)
          + 2000] - ros_code_B.predict_accurate_index;
      }

      ros_code_power(ros_code_B.distances, &ros_code_B.b_y_size,
                     ros_code_B.tmp_data_c, &ros_code_B.x_size_k);
      ros_code_power(ros_code_B.tmp_data_k, &ros_code_B.tmp_size_n,
                     ros_code_B.tmp_data_c, &ros_code_B.d_size);
      if (ros_code_B.x_size_k == ros_code_B.d_size) {
        ros_code_B.predict_accurate_index = ros_code_B.current_state_C[0];
        ros_code_B.b_y_size = ros_code_B.nblocks;
        ros_code_B.scalarLB = (ros_code_B.nblocks / 2) << 1;
        ros_code_B.vectorUB = ros_code_B.scalarLB - 2;
        for (ros_code_B.nx = 0; ros_code_B.nx <= ros_code_B.vectorUB;
             ros_code_B.nx += 2) {
          tmp_0 = _mm_loadu_pd
            (&ros_code_B.preprocess_global_path_array[ros_code_B.e +
             ros_code_B.nx]);
          _mm_storeu_pd(&ros_code_B.distances[ros_code_B.nx], _mm_sub_pd(tmp_0,
            _mm_set1_pd(ros_code_B.predict_accurate_index)));
        }

        for (ros_code_B.nx = ros_code_B.scalarLB; ros_code_B.nx <
             ros_code_B.nblocks; ros_code_B.nx++) {
          ros_code_B.distances[ros_code_B.nx] =
            ros_code_B.preprocess_global_path_array[ros_code_B.e + ros_code_B.nx]
            - ros_code_B.predict_accurate_index;
        }

        ros_code_power(ros_code_B.distances, &ros_code_B.b_y_size,
                       ros_code_B.tmp_data_k, &ros_code_B.tmp_size_n);
        ros_code_B.predict_accurate_index = ros_code_B.current_state_C[1];
        ros_code_B.b_y_size = ros_code_B.loop_ub;
        ros_code_B.vectorUB = ros_code_B.scalarLB_tmp - 2;
        for (ros_code_B.nx = 0; ros_code_B.nx <= ros_code_B.vectorUB;
             ros_code_B.nx += 2) {
          tmp_0 = _mm_loadu_pd(&ros_code_B.preprocess_global_path_array
                               [(ros_code_B.g + ros_code_B.nx) + 2000]);
          _mm_storeu_pd(&ros_code_B.distances[ros_code_B.nx], _mm_sub_pd(tmp_0,
            _mm_set1_pd(ros_code_B.predict_accurate_index)));
        }

        for (ros_code_B.nx = ros_code_B.scalarLB_tmp; ros_code_B.nx <
             ros_code_B.loop_ub; ros_code_B.nx++) {
          ros_code_B.distances[ros_code_B.nx] =
            ros_code_B.preprocess_global_path_array[(ros_code_B.g +
            ros_code_B.nx) + 2000] - ros_code_B.predict_accurate_index;
        }

        ros_code_power(ros_code_B.distances, &ros_code_B.b_y_size,
                       ros_code_B.tmp_data_c, &ros_code_B.x_size_k);
        ros_code_B.accurate_distance_size = ros_code_B.tmp_size_n;
        ros_code_B.nblocks = ros_code_B.tmp_size_n;
        ros_code_B.scalarLB = (ros_code_B.tmp_size_n / 2) << 1;
        ros_code_B.vectorUB = ros_code_B.scalarLB - 2;
        for (ros_code_B.nx = 0; ros_code_B.nx <= ros_code_B.vectorUB;
             ros_code_B.nx += 2) {
          tmp_0 = _mm_loadu_pd(&ros_code_B.tmp_data_k[ros_code_B.nx]);
          tmp = _mm_loadu_pd(&ros_code_B.tmp_data_c[ros_code_B.nx]);
          _mm_storeu_pd(&ros_code_B.accurate_distance_data[ros_code_B.nx],
                        _mm_add_pd(_mm_mul_pd(_mm_set1_pd(ros_code_B.d_ls),
            tmp_0), _mm_mul_pd(_mm_set1_pd(ros_code_B.mean_angle), tmp)));
        }

        for (ros_code_B.nx = ros_code_B.scalarLB; ros_code_B.nx <
             ros_code_B.nblocks; ros_code_B.nx++) {
          ros_code_B.accurate_distance_data[ros_code_B.nx] = ros_code_B.d_ls *
            ros_code_B.tmp_data_k[ros_code_B.nx] + ros_code_B.mean_angle *
            ros_code_B.tmp_data_c[ros_code_B.nx];
        }
      } else {
        ros_code_binary_expand_op_pijw(ros_code_B.accurate_distance_data,
          &ros_code_B.accurate_distance_size, ros_code_B.d_ls,
          ros_code_B.preprocess_global_path_array, ros_code_B.e, ros_code_B.c_cg
          - 1, ros_code_B.current_state_C, ros_code_B.mean_angle, ros_code_B.g,
          ros_code_B.firstBlockLength - 1);
      }

      ros_code_B.nx = ros_code_B.accurate_distance_size;
      ros_code_B.i = 0;
      while (ros_code_B.i <= ros_code_B.nx - 1) {
        ros_code_B.accurate_distance_data[ros_code_B.i] = sqrt
          (ros_code_B.accurate_distance_data[ros_code_B.i]);
        ros_code_B.i++;
      }

      ros_code_B.nblocks = ros_code_B.accurate_distance_size;
      if (ros_code_B.accurate_distance_size <= 2) {
        if (ros_code_B.accurate_distance_size == 1) {
          ros_code_B.i = 1;
        } else {
          ros_code_B.object_num =
            ros_code_B.accurate_distance_data[ros_code_B.accurate_distance_size
            - 1];
          if (ros_code_B.accurate_distance_data[0] > ros_code_B.object_num) {
            ros_code_B.i = ros_code_B.accurate_distance_size;
          } else if (rtIsNaN(ros_code_B.accurate_distance_data[0])) {
            if (!rtIsNaN(ros_code_B.object_num)) {
              ros_code_B.i = ros_code_B.accurate_distance_size;
            } else {
              ros_code_B.i = 1;
            }
          } else {
            ros_code_B.i = 1;
          }
        }
      } else {
        if (!rtIsNaN(ros_code_B.accurate_distance_data[0])) {
          ros_code_B.i = 1;
        } else {
          ros_code_B.i = 0;
          ros_code_B.lastBlockLength = 2;
          exitg1 = false;
          while ((!exitg1) && (ros_code_B.lastBlockLength <= ros_code_B.nblocks))
          {
            if (!rtIsNaN
                (ros_code_B.accurate_distance_data[ros_code_B.lastBlockLength -
                 1])) {
              ros_code_B.i = ros_code_B.lastBlockLength;
              exitg1 = true;
            } else {
              ros_code_B.lastBlockLength++;
            }
          }
        }

        if (ros_code_B.i == 0) {
          ros_code_B.i = 1;
        } else {
          ros_code_B.predict_accurate_index =
            ros_code_B.accurate_distance_data[ros_code_B.i - 1];
          ros_code_B.lastBlockLength = ros_code_B.i;
          while (ros_code_B.lastBlockLength + 1 <= ros_code_B.nblocks) {
            if (ros_code_B.predict_accurate_index >
                ros_code_B.accurate_distance_data[ros_code_B.lastBlockLength]) {
              ros_code_B.predict_accurate_index =
                ros_code_B.accurate_distance_data[ros_code_B.lastBlockLength];
              ros_code_B.i = ros_code_B.lastBlockLength + 1;
            }

            ros_code_B.lastBlockLength++;
          }
        }
      }

      ros_code_B.predict_accurate_index = (ros_code_B.min_range +
        static_cast<real_T>(ros_code_B.i)) - 1.0;
      if (ros_code_B.predict_accurate_index == 1.0) {
        for (ros_code_B.nx = 0; ros_code_B.nx < 5; ros_code_B.nx++) {
          ros_code_B.last_path_data[ros_code_B.nx] =
            ros_code_B.preprocess_global_path_array[2000 * ros_code_B.nx];
        }
      } else {
        for (ros_code_B.nx = 0; ros_code_B.nx < 5; ros_code_B.nx++) {
          ros_code_B.last_path_data[ros_code_B.nx] =
            ros_code_B.preprocess_global_path_array[(static_cast<int32_T>
            (ros_code_B.predict_accurate_index - 1.0) + 2000 * ros_code_B.nx) -
            1];
        }
      }

      if (ros_code_B.ds == 0.0) {
        ros_code_B.kappa_x = 0.0;
      } else {
        ros_code_B.mean_angle = ros_code_B.current_state_C[2] -
          ros_code_DW.Memory_PreviousInput[2];
        ros_code_wrapToPi(&ros_code_B.mean_angle);
        ros_code_B.kappa_x = ros_code_B.mean_angle / ros_code_B.ds;
      }

      ros_code_B.start_index = ros_code_B.preprocess_global_path_array[
        static_cast<int32_T>(ros_code_B.predict_accurate_index) + 5999];
      ros_code_B.ds = ros_code_B.preprocess_global_path_array
        [static_cast<int32_T>(ros_code_B.predict_accurate_index) + 3999];
      ros_code_B.angle_diff = ros_code_B.current_state_C[2] - ros_code_B.ds;
      ros_code_wrapToPi(&ros_code_B.angle_diff);
      ros_code_B.c_a_tmp = ros_code_B.current_state_C[0] -
        ros_code_B.preprocess_global_path_array[static_cast<int32_T>
        (ros_code_B.predict_accurate_index) - 1];
      ros_code_B.dd_s = ros_code_B.current_state_C[1] -
        ros_code_B.preprocess_global_path_array[static_cast<int32_T>
        (ros_code_B.predict_accurate_index) + 1999];
      ros_code_B.ds = ros_code_B.dd_s * cos(ros_code_B.ds) - ros_code_B.c_a_tmp *
        sin(ros_code_B.ds);
      if (!rtIsNaN(ros_code_B.ds)) {
        if (ros_code_B.ds < 0.0) {
          ros_code_B.ds = -1.0;
        } else {
          ros_code_B.ds = (ros_code_B.ds > 0.0);
        }
      }

      ros_code_B.ds *= sqrt(ros_code_B.c_a_tmp * ros_code_B.c_a_tmp +
                            ros_code_B.dd_s * ros_code_B.dd_s);
      ros_code_B.dd_s = cos(ros_code_B.angle_diff);
      ros_code_B.s = 1.0 - ros_code_B.start_index * ros_code_B.ds;
      ros_code_B.mean_angle = ros_code_B.current_state_C[3] * ros_code_B.dd_s /
        ros_code_B.s;
      ros_code_B.dd_ls = tan(ros_code_B.angle_diff);
      ros_code_B.d_ls = ros_code_B.s * ros_code_B.dd_ls;
      ros_code_B.ex = (ros_code_B.start_index - ros_code_B.last_path_data[3]) *
        ros_code_B.ds + ros_code_B.start_index * ros_code_B.d_ls;
      ros_code_B.dd_ls = (ros_code_B.s / ros_code_B.dd_s * ros_code_B.kappa_x -
                          ros_code_B.start_index) * (ros_code_B.s /
        (ros_code_B.dd_s * ros_code_B.dd_s)) + -ros_code_B.ex * ros_code_B.dd_ls;
      ros_code_B.min_range = ros_code_B.mean_angle * ros_code_B.mean_angle;
      ros_code_B.dd_s = ((ros_code_B.current_state_C[3] -
                          ros_code_DW.Memory_PreviousInput[3]) * ros_code_B.dd_s
                         - (((1.0 - ros_code_B.start_index * ros_code_B.ds) /
        ros_code_B.dd_s - ros_code_B.start_index) * ros_code_B.kappa_x -
                            ros_code_B.ex) * ros_code_B.d_ls *
                         ros_code_B.min_range) / ros_code_B.s;
      ros_code_B.current_state_F[0] = ros_code_B.preprocess_global_path_array[
        static_cast<int32_T>(ros_code_B.predict_accurate_index) + 7999];
      ros_code_B.current_state_F[1] = ros_code_B.mean_angle;
      ros_code_B.current_state_F[2] = ros_code_B.dd_s;
      ros_code_B.current_state_F[3] = ros_code_B.ds;
      ros_code_B.current_state_F[4] = ros_code_B.d_ls;
      ros_code_B.current_state_F[5] = ros_code_B.dd_ls;
      ros_code_B.current_state_F[6] = ros_code_B.mean_angle * ros_code_B.d_ls;
      ros_code_B.current_state_F[7] = ros_code_B.min_range * ros_code_B.dd_ls +
        ros_code_B.d_ls * ros_code_B.dd_s;
    }

    // MATLAB Function: '<S3>/predictState' incorporates:
    //   MATLAB Function: '<S3>/currentStateConvert'
    //   Memory: '<S3>/Memory1'
    //   RateTransition: '<Root>/Rate Transition11'

    memset(&ros_code_B.predict_state_F[0], 0, 9U * sizeof(real_T));
    memcpy(&ros_code_B.predict_state_F[0], &ros_code_B.current_state_F[0],
           sizeof(real_T) << 3U);
    ros_code_B.predict_next_state[0] = ros_code_B.current_state_C[0];
    ros_code_B.predict_next_state[1] = ros_code_B.current_state_C[1];
    ros_code_B.predict_next_state[2] = ros_code_B.current_state_C[2];
    mask1 = true;
    ros_code_B.nx = 0;
    exitg1 = false;
    while ((!exitg1) && (ros_code_B.nx < 15)) {
      if (!(ros_code_DW.Memory1_PreviousInput[ros_code_B.nx] == 0.0)) {
        mask1 = false;
        exitg1 = true;
      } else {
        ros_code_B.nx++;
      }
    }

    if (!mask1) {
      ros_code_B.mean_angle = ros_code_B.aSinInput -
        ros_code_DW.Memory1_PreviousInput[12];
      ros_code_B.B1[0] = ros_code_DW.Memory1_PreviousInput[5];
      ros_code_B.B1[1] = ros_code_DW.Memory1_PreviousInput[4];
      ros_code_B.B1[2] = ros_code_DW.Memory1_PreviousInput[3];
      ros_code_B.B1[3] = ros_code_DW.Memory1_PreviousInput[2];
      ros_code_B.B1[4] = ros_code_DW.Memory1_PreviousInput[1];
      ros_code_B.B1[5] = ros_code_DW.Memory1_PreviousInput[0];
      ros_code_B.s = ros_code_DW.Memory1_PreviousInput[5];
      for (ros_code_B.nx = 0; ros_code_B.nx < 5; ros_code_B.nx++) {
        ros_code_B.s = ros_code_B.mean_angle * ros_code_B.s +
          ros_code_B.B1[ros_code_B.nx + 1];
      }

      ros_code_B.B1[0] = ros_code_DW.Memory1_PreviousInput[11];
      ros_code_B.B1[1] = ros_code_DW.Memory1_PreviousInput[10];
      ros_code_B.B1[2] = ros_code_DW.Memory1_PreviousInput[9];
      ros_code_B.B1[3] = ros_code_DW.Memory1_PreviousInput[8];
      ros_code_B.B1[4] = ros_code_DW.Memory1_PreviousInput[7];
      ros_code_B.B1[5] = ros_code_DW.Memory1_PreviousInput[6];
      ros_code_B.ds = ros_code_DW.Memory1_PreviousInput[11];
      for (ros_code_B.i = 0; ros_code_B.i < 5; ros_code_B.i++) {
        ros_code_B.ds = ros_code_B.s * ros_code_B.ds +
          ros_code_B.B1[ros_code_B.i + 1];
      }

      ros_code_B.d_ls = (((5.0 * ros_code_DW.Memory1_PreviousInput[11] *
                           ros_code_B.s + 4.0 *
                           ros_code_DW.Memory1_PreviousInput[10]) * ros_code_B.s
                          + 3.0 * ros_code_DW.Memory1_PreviousInput[9]) *
                         ros_code_B.s + 2.0 * ros_code_DW.Memory1_PreviousInput
                         [8]) * ros_code_B.s +
        ros_code_DW.Memory1_PreviousInput[7];
      if (ros_code_DW.Memory1_PreviousInput[13] - 50.0 >= 1.0) {
        ros_code_B.min_range = ros_code_DW.Memory1_PreviousInput[13] - 50.0;
      } else {
        ros_code_B.min_range = 1.0;
      }

      if ((ros_code_DW.Memory1_PreviousInput[14] + 10.0 <=
           ros_code_B.preprocess_global_path_array[1999]) || rtIsNaN
          (ros_code_B.preprocess_global_path_array[1999])) {
        ros_code_B.max_range = ros_code_DW.Memory1_PreviousInput[14] + 10.0;
      } else {
        ros_code_B.max_range = ros_code_B.preprocess_global_path_array[1999];
      }

      if (ros_code_B.min_range > ros_code_B.max_range) {
        ros_code_B.c_cg = 0;
        ros_code_B.i = 0;
      } else {
        ros_code_B.c_cg = static_cast<int32_T>(ros_code_B.min_range) - 1;
        ros_code_B.i = static_cast<int32_T>(ros_code_B.max_range);
      }

      ros_code_B.nblocks = ros_code_B.i - ros_code_B.c_cg;
      ros_code_B.scalarLB = (ros_code_B.nblocks / 2) << 1;
      ros_code_B.vectorUB = ros_code_B.scalarLB - 2;
      for (ros_code_B.nx = 0; ros_code_B.nx <= ros_code_B.vectorUB;
           ros_code_B.nx += 2) {
        tmp_0 = _mm_loadu_pd(&ros_code_B.preprocess_global_path_array
                             [(ros_code_B.c_cg + ros_code_B.nx) + 8000]);
        _mm_storeu_pd(&ros_code_B.accurate_distance_data[ros_code_B.nx],
                      _mm_sub_pd(tmp_0, _mm_set1_pd(ros_code_B.s)));
      }

      for (ros_code_B.nx = ros_code_B.scalarLB; ros_code_B.nx <
           ros_code_B.nblocks; ros_code_B.nx++) {
        ros_code_B.accurate_distance_data[ros_code_B.nx] =
          ros_code_B.preprocess_global_path_array[(ros_code_B.c_cg +
          ros_code_B.nx) + 8000] - ros_code_B.s;
      }

      ros_code_B.b_y_size = ros_code_B.nblocks;
      ros_code_B.i = 0;
      while (ros_code_B.i <= ros_code_B.nblocks - 1) {
        ros_code_B.distances[ros_code_B.i] =
          ros_code_B.accurate_distance_data[ros_code_B.i] *
          ros_code_B.accurate_distance_data[ros_code_B.i];
        ros_code_B.i++;
      }

      ros_code_B.accurate_distance_size = ros_code_B.nblocks;
      if (ros_code_B.nblocks - 1 >= 0) {
        memcpy(&ros_code_B.accurate_distance_data[0], &ros_code_B.distances[0],
               ros_code_B.nblocks * sizeof(real_T));
      }

      ros_code_B.i = 0;
      while (ros_code_B.i <= ros_code_B.b_y_size - 1) {
        ros_code_B.accurate_distance_data[ros_code_B.i] = sqrt
          (ros_code_B.accurate_distance_data[ros_code_B.i]);
        ros_code_B.i++;
      }

      ros_code_B.nblocks = ros_code_B.b_y_size;
      if (ros_code_B.b_y_size <= 2) {
        if (ros_code_B.b_y_size == 1) {
          ros_code_B.nx = 1;
        } else {
          ros_code_B.object_num =
            ros_code_B.accurate_distance_data[ros_code_B.b_y_size - 1];
          if (ros_code_B.accurate_distance_data[0] > ros_code_B.object_num) {
            ros_code_B.nx = ros_code_B.b_y_size;
          } else if (rtIsNaN(ros_code_B.accurate_distance_data[0])) {
            if (!rtIsNaN(ros_code_B.object_num)) {
              ros_code_B.nx = ros_code_B.b_y_size;
            } else {
              ros_code_B.nx = 1;
            }
          } else {
            ros_code_B.nx = 1;
          }
        }
      } else {
        if (!rtIsNaN(ros_code_B.accurate_distance_data[0])) {
          ros_code_B.nx = 1;
        } else {
          ros_code_B.nx = 0;
          ros_code_B.lastBlockLength = 2;
          exitg1 = false;
          while ((!exitg1) && (ros_code_B.lastBlockLength <= ros_code_B.nblocks))
          {
            if (!rtIsNaN
                (ros_code_B.accurate_distance_data[ros_code_B.lastBlockLength -
                 1])) {
              ros_code_B.nx = ros_code_B.lastBlockLength;
              exitg1 = true;
            } else {
              ros_code_B.lastBlockLength++;
            }
          }
        }

        if (ros_code_B.nx == 0) {
          ros_code_B.nx = 1;
        } else {
          ros_code_B.ex = ros_code_B.accurate_distance_data[ros_code_B.nx - 1];
          ros_code_B.lastBlockLength = ros_code_B.nx;
          while (ros_code_B.lastBlockLength + 1 <= ros_code_B.nblocks) {
            if (ros_code_B.ex >
                ros_code_B.accurate_distance_data[ros_code_B.lastBlockLength]) {
              ros_code_B.ex =
                ros_code_B.accurate_distance_data[ros_code_B.lastBlockLength];
              ros_code_B.nx = ros_code_B.lastBlockLength + 1;
            }

            ros_code_B.lastBlockLength++;
          }
        }
      }

      ros_code_B.object_num = (ros_code_B.min_range + static_cast<real_T>
        (ros_code_B.nx)) - 1.0;
      ros_code_B.dd_s = ros_code_B.preprocess_global_path_array
        [static_cast<int32_T>(ros_code_B.object_num) + 3999];
      ros_code_B.max_range = rt_atan2d_snf(ros_code_B.d_ls, 1.0 -
        ros_code_B.preprocess_global_path_array[static_cast<int32_T>
        (ros_code_B.object_num) + 5999] * ros_code_B.ds) + ros_code_B.dd_s;
      mask1 = (ros_code_B.max_range < -3.1415926535897931);
      mask2 = (ros_code_B.max_range > 3.1415926535897931);
      ros_code_B.i = 0;
      if (mask1 || mask2) {
        ros_code_B.i = 1;
      }

      if (ros_code_B.i - 1 >= 0) {
        ros_code_B.x_data_m = ros_code_B.max_range + 3.1415926535897931;
      }

      if (ros_code_B.i - 1 >= 0) {
        if (rtIsNaN(ros_code_B.max_range + 3.1415926535897931)) {
          ros_code_B.ex = (rtNaN);
        } else if (rtIsInf(ros_code_B.max_range + 3.1415926535897931)) {
          ros_code_B.ex = (rtNaN);
        } else if (ros_code_B.max_range + 3.1415926535897931 == 0.0) {
          ros_code_B.ex = 0.0;
        } else {
          ros_code_B.ex = fmod(ros_code_B.max_range + 3.1415926535897931,
                               6.2831853071795862);
          rEQ0 = (ros_code_B.ex == 0.0);
          if (!rEQ0) {
            ros_code_B.dd_ls = fabs((ros_code_B.max_range + 3.1415926535897931) /
              6.2831853071795862);
            rEQ0 = !(fabs(ros_code_B.dd_ls - floor(ros_code_B.dd_ls + 0.5)) >
                     2.2204460492503131E-16 * ros_code_B.dd_ls);
          }

          if (rEQ0) {
            ros_code_B.ex = 0.0;
          } else if (ros_code_B.max_range + 3.1415926535897931 < 0.0) {
            ros_code_B.ex += 6.2831853071795862;
          }
        }

        ros_code_B.x_data_m = ros_code_B.ex;
      }

      if (ros_code_B.i - 1 >= 0) {
        ros_code_B.nx = 0;
        positiveInput_data = ((ros_code_B.x_data_m == 0.0) &&
                              (ros_code_B.max_range + 3.1415926535897931 > 0.0));
      }

      if (ros_code_B.i - 1 >= 0) {
        ros_code_B.e = 0;
        if (positiveInput_data) {
          ros_code_B.x_data_m = 6.2831853071795862;
        }
      }

      ros_code_B.predict_next_state[2] = ros_code_B.max_range;
      if (mask1 || mask2) {
        ros_code_B.predict_next_state[2] = ros_code_B.x_data_m -
          3.1415926535897931;
      }

      ros_code_B.predict_next_state[0] =
        ros_code_B.preprocess_global_path_array[static_cast<int32_T>
        (ros_code_B.object_num) - 1] - sin(ros_code_B.dd_s) * ros_code_B.ds;
      ros_code_B.predict_next_state[1] = cos(ros_code_B.dd_s) * ros_code_B.ds +
        ros_code_B.preprocess_global_path_array[static_cast<int32_T>
        (ros_code_B.object_num) + 1999];
      ros_code_B.predict_state_F[0] = ros_code_B.s;
      ros_code_B.predict_state_F[1] = (((5.0 *
        ros_code_DW.Memory1_PreviousInput[5] * ros_code_B.mean_angle + 4.0 *
        ros_code_DW.Memory1_PreviousInput[4]) * ros_code_B.mean_angle + 3.0 *
        ros_code_DW.Memory1_PreviousInput[3]) * ros_code_B.mean_angle + 2.0 *
        ros_code_DW.Memory1_PreviousInput[2]) * ros_code_B.mean_angle +
        ros_code_DW.Memory1_PreviousInput[1];
      ros_code_B.predict_state_F[2] = ((20.0 *
        ros_code_DW.Memory1_PreviousInput[5] * ros_code_B.mean_angle + 12.0 *
        ros_code_DW.Memory1_PreviousInput[4]) * ros_code_B.mean_angle + 6.0 *
        ros_code_DW.Memory1_PreviousInput[3]) * ros_code_B.mean_angle + 2.0 *
        ros_code_DW.Memory1_PreviousInput[2];
      ros_code_B.predict_state_F[3] = ros_code_B.ds;
      ros_code_B.predict_state_F[4] = ros_code_B.d_ls;
      ros_code_B.predict_state_F[5] = ((20.0 *
        ros_code_DW.Memory1_PreviousInput[11] * ros_code_B.s + 12.0 *
        ros_code_DW.Memory1_PreviousInput[10]) * ros_code_B.s + 6.0 *
        ros_code_DW.Memory1_PreviousInput[9]) * ros_code_B.s + 2.0 *
        ros_code_DW.Memory1_PreviousInput[8];
      ros_code_B.predict_state_F[6] = 0.0;
      ros_code_B.predict_state_F[7] = 0.0;
      ros_code_B.predict_state_F[8] = ros_code_B.object_num;
    }

    // End of MATLAB Function: '<S3>/predictState'

    // MATLAB Function: '<S3>/sampleTrajectory' incorporates:
    //   MATLAB Function: '<S3>/currentStateConvert'

    ros_code_B.firstBlockLength = 0;
    ros_code_B.a_m = ros_code_B.current_state_C[0] -
      ros_code_B.predict_next_state[0];
    ros_code_B.lv_0 = ros_code_B.current_state_C[1] -
      ros_code_B.predict_next_state[1];
    if (sqrt(ros_code_B.a_m * ros_code_B.a_m + ros_code_B.lv_0 * ros_code_B.lv_0)
        >= 10.0) {
      ros_code_B.eulZYX[0] = ros_code_B.current_state_C[0];
      ros_code_B.eulZYX[1] = ros_code_B.current_state_C[1];
      ros_code_B.eulZYX[2] = ros_code_B.current_state_C[2];
    } else {
      memcpy(&ros_code_B.current_state_F[0], &ros_code_B.predict_state_F[0],
             sizeof(real_T) << 3U);
      ros_code_B.predict_accurate_index = ros_code_B.predict_state_F[8];
      ros_code_B.eulZYX[0] = ros_code_B.predict_next_state[0];
      ros_code_B.eulZYX[1] = ros_code_B.predict_next_state[1];
      ros_code_B.eulZYX[2] = ros_code_B.predict_next_state[2];
    }

    if (fabs(ros_code_B.current_state_F[0] - ros_code_B.global_path_num) >= 0.1)
    {
      ros_code_B.firstBlockLength = 1;
    }

    memset(&ros_code_B.Tau_sl[0], 0, 50778U * sizeof(real_T));
    ros_code_B.dd_ls = ros_code_B.current_state_F[0];
    ros_code_B.min_range = ros_code_B.current_state_F[1];
    ros_code_B.sa_0 = ros_code_B.current_state_F[2];
    ros_code_B.ls_0 = ros_code_B.current_state_F[3];
    ros_code_B.lv_0 = ros_code_B.current_state_F[4];
    ros_code_B.la_0 = ros_code_B.current_state_F[5];
    if (ros_code_B.global_path_num - ros_code_B.current_state_F[0] > 3.0) {
      ros_code_B.max_range = ros_code_B.current_state_F[2] / 2.0;
      ros_code_B.object_num = 0.0;
      ros_code_B.last_path_data[2] = ros_code_B.max_range;
      ros_code_B.last_path_data[3] = ros_code_B.current_state_F[1];
      ros_code_B.last_path_data[4] = ros_code_B.current_state_F[0];
      ros_code_B.sa4[2] = ros_code_B.max_range;
      ros_code_B.sa4[3] = ros_code_B.current_state_F[1];
      ros_code_B.sa4[4] = ros_code_B.current_state_F[0];
      for (ros_code_B.i = 0; ros_code_B.i < 21; ros_code_B.i++) {
        ros_code_B.a_m = static_cast<real_T>(ros_code_B.i) * 0.1 + 2.0;
        for (ros_code_B.lastBlockLength = 0; ros_code_B.lastBlockLength < 6;
             ros_code_B.lastBlockLength++) {
          ros_code_B.ds = static_cast<real_T>(ros_code_B.lastBlockLength) * 0.1
            + 0.5;
          ros_code_B.sa3 = -((3.0 * ros_code_B.min_range - 3.0 * ros_code_B.ds)
                             + 2.0 * ros_code_B.a_m * ros_code_B.sa_0) /
            (ros_code_B.a_m * ros_code_B.a_m * 3.0);
          ros_code_B.sa4_c = ((2.0 * ros_code_B.min_range - 2.0 * ros_code_B.ds)
                              + ros_code_B.a_m * ros_code_B.sa_0) / (4.0 *
            rt_powd_snf(ros_code_B.a_m, 3.0));
          ros_code_B.last_path_data[0] = ros_code_B.sa4_c;
          ros_code_B.last_path_data[1] = ros_code_B.sa3;
          ros_code_B.S_start = ros_code_polyval_o(ros_code_B.last_path_data, 0.0);
          ros_code_B.sa4[0] = ros_code_B.sa4_c;
          ros_code_B.sa4[1] = ros_code_B.sa3;
          ros_code_B.S_end = ros_code_polyval_o(ros_code_B.sa4, ros_code_B.a_m);
          ros_code_B.c_a_tmp = ros_code_B.S_end - ros_code_B.S_start;
          for (ros_code_B.nx = 0; ros_code_B.nx < 31; ros_code_B.nx++) {
            ros_code_B.ls_1 = static_cast<real_T>(ros_code_B.nx) * 0.1 + -1.5;
            ros_code_B.object_num++;
            ros_code_B.Tau_sl[static_cast<int32_T>(ros_code_B.object_num) - 1] =
              ros_code_B.dd_ls;
            ros_code_B.Tau_sl[static_cast<int32_T>(ros_code_B.object_num) + 3905]
              = ros_code_B.min_range;
            ros_code_B.Tau_sl[static_cast<int32_T>(ros_code_B.object_num) + 7811]
              = ros_code_B.max_range;
            ros_code_B.Tau_sl[static_cast<int32_T>(ros_code_B.object_num) +
              11717] = ros_code_B.sa3;
            ros_code_B.Tau_sl[static_cast<int32_T>(ros_code_B.object_num) +
              15623] = ros_code_B.sa4_c;
            ros_code_B.Tau_sl[static_cast<int32_T>(ros_code_B.object_num) +
              19529] = 0.0;
            ros_code_B.ds = rt_powd_snf(ros_code_B.S_end, 5.0);
            ros_code_B.mean_angle = rt_powd_snf(ros_code_B.S_start, 5.0);
            ros_code_B.d_ls = rt_powd_snf(ros_code_B.S_end, 3.0);
            ros_code_B.dd_s = rt_powd_snf(ros_code_B.S_start, 4.0);
            ros_code_B.kappa_x = rt_powd_snf(ros_code_B.S_end, 4.0);
            ros_code_B.start_index = rt_powd_snf(ros_code_B.S_start, 3.0);
            ros_code_B.angle_diff = ros_code_B.S_start * ros_code_B.S_start;
            ros_code_B.ex = ros_code_B.S_end * ros_code_B.S_end;
            ros_code_B.rtb_Tau_sl_tmp_tmp_p = 8.0 * ros_code_B.d_ls;
            ros_code_B.s = ros_code_B.rtb_Tau_sl_tmp_tmp_p *
              ros_code_B.start_index;
            ros_code_B.rtb_Tau_sl_tmp_j = 10.0 * ros_code_B.kappa_x;
            ros_code_B.rtb_Tau_sl_tmp_h = 2.0 * ros_code_B.ds;
            ros_code_B.rtb_Tau_sl_tmp_c = 2.0 * ros_code_B.mean_angle;
            ros_code_B.rtb_Tau_sl_tmp_ct = ros_code_B.ex * 3.0;
            ros_code_B.rtb_Tau_sl_tmp_p = ros_code_B.rtb_Tau_sl_tmp_h *
              ros_code_B.S_start;
            ros_code_B.rtb_Tau_sl_tmp_a = 2.0 * ros_code_B.S_end *
              ros_code_B.mean_angle * 0.0;
            ros_code_B.rtb_Tau_sl_tmp_e = ros_code_B.rtb_Tau_sl_tmp_j *
              ros_code_B.S_start;
            ros_code_B.rtb_Tau_sl_tmp_ax = 10.0 * ros_code_B.S_end *
              ros_code_B.dd_s;
            ros_code_B.rtb_Tau_sl_tmp_l = ((ros_code_B.d_ls -
              ros_code_B.rtb_Tau_sl_tmp_ct * ros_code_B.S_start) + 3.0 *
              ros_code_B.S_end * ros_code_B.angle_diff) - ros_code_B.start_index;
            ros_code_B.rtb_Tau_sl_tmp_o2 = ros_code_B.ex * 20.0;
            ros_code_B.rtb_Tau_sl_tmp_i = 2.0 * ros_code_B.d_ls;
            ros_code_B.Tau_sl[static_cast<int32_T>(ros_code_B.object_num) +
              23435] = (((((((((((((((((ros_code_B.rtb_Tau_sl_tmp_h *
              ros_code_B.ls_0 - ros_code_B.rtb_Tau_sl_tmp_c * ros_code_B.ls_1) +
              ros_code_B.d_ls * ros_code_B.dd_s * ros_code_B.la_0) - 2.0 *
              ros_code_B.kappa_x * ros_code_B.start_index * ros_code_B.la_0) +
              ros_code_B.angle_diff * ros_code_B.ds * ros_code_B.la_0) -
              ros_code_B.ex * ros_code_B.mean_angle * 0.0) +
              ros_code_B.rtb_Tau_sl_tmp_i * ros_code_B.dd_s * 0.0) -
                                  ros_code_B.kappa_x * ros_code_B.start_index *
                                  0.0) + 20.0 * ros_code_B.d_ls *
                                 ros_code_B.angle_diff * ros_code_B.ls_0) -
                                ros_code_B.rtb_Tau_sl_tmp_o2 *
                                ros_code_B.start_index * ros_code_B.ls_1) -
                               ros_code_B.s * ros_code_B.lv_0) +
                              ros_code_B.rtb_Tau_sl_tmp_j *
                              ros_code_B.angle_diff * ros_code_B.lv_0) -
                             ros_code_B.ex * 10.0 * ros_code_B.dd_s * 0.0) +
                            ros_code_B.s * 0.0) - ros_code_B.rtb_Tau_sl_tmp_e *
                           ros_code_B.ls_0) + ros_code_B.rtb_Tau_sl_tmp_ax *
                          ros_code_B.ls_1) - ros_code_B.rtb_Tau_sl_tmp_p *
                         ros_code_B.lv_0) + ros_code_B.rtb_Tau_sl_tmp_a) /
              (ros_code_B.c_a_tmp * ros_code_B.c_a_tmp * 2.0 *
               ros_code_B.rtb_Tau_sl_tmp_l);
            ros_code_B.rtb_Tau_sl_tmp_tmp_a = 4.0 * ros_code_B.d_ls;
            ros_code_B.s = ros_code_B.rtb_Tau_sl_tmp_tmp_a *
              ros_code_B.start_index;
            ros_code_B.rtb_Tau_sl_tmp_tmp = ros_code_B.ex * 60.0;
            ros_code_B.rtb_Tau_sl_tmp_j = ros_code_B.rtb_Tau_sl_tmp_tmp *
              ros_code_B.angle_diff;
            ros_code_B.rtb_Tau_sl_tmp_o = 3.0 * ros_code_B.kappa_x;
            ros_code_B.rtb_Tau_sl_tmp = 24.0 * ros_code_B.d_ls;
            ros_code_B.rtb_Tau_sl_tmp_m = ros_code_B.ex * 16.0;
            ros_code_B.Tau_sl[static_cast<int32_T>(ros_code_B.object_num) +
              27341] = (((((((((((((((((ros_code_B.rtb_Tau_sl_tmp_h *
              ros_code_B.lv_0 - ros_code_B.rtb_Tau_sl_tmp_c * 0.0) -
              ros_code_B.rtb_Tau_sl_tmp_ct * ros_code_B.dd_s * ros_code_B.la_0)
              + ros_code_B.s * ros_code_B.la_0) + ros_code_B.angle_diff *
              ros_code_B.kappa_x * ros_code_B.la_0) - ros_code_B.ex *
              ros_code_B.dd_s * 0.0) - ros_code_B.s * 0.0) +
                                  ros_code_B.rtb_Tau_sl_tmp_o *
                                  ros_code_B.angle_diff * 0.0) -
                                 ros_code_B.rtb_Tau_sl_tmp_j * ros_code_B.ls_0)
                                + ros_code_B.rtb_Tau_sl_tmp_j * ros_code_B.ls_1)
                               + ros_code_B.ex * 24.0 * ros_code_B.start_index *
                               ros_code_B.lv_0) - 16.0 * ros_code_B.d_ls *
                              ros_code_B.angle_diff * ros_code_B.lv_0) +
                             ros_code_B.rtb_Tau_sl_tmp_m *
                             ros_code_B.start_index * 0.0) -
                            ros_code_B.rtb_Tau_sl_tmp * ros_code_B.angle_diff *
                            0.0) - ros_code_B.rtb_Tau_sl_tmp_p * ros_code_B.la_0)
                          + ros_code_B.rtb_Tau_sl_tmp_a) -
                         ros_code_B.rtb_Tau_sl_tmp_e * ros_code_B.lv_0) +
                        ros_code_B.rtb_Tau_sl_tmp_ax * 0.0) /
              (ros_code_B.c_a_tmp * ros_code_B.c_a_tmp * 2.0 *
               ros_code_B.rtb_Tau_sl_tmp_l);
            ros_code_B.s = ros_code_B.ex * 12.0 * ros_code_B.angle_diff;
            ros_code_B.rtb_Tau_sl_tmp_j = 60.0 * ros_code_B.S_end *
              ros_code_B.angle_diff;
            ros_code_B.rtb_Tau_sl_tmp_h = ros_code_B.rtb_Tau_sl_tmp_tmp *
              ros_code_B.S_start;
            ros_code_B.rtb_Tau_sl_tmp_c = ros_code_B.ex * 8.0;
            ros_code_B.rtb_Tau_sl_tmp_ct = ros_code_B.c_a_tmp *
              ros_code_B.c_a_tmp * 2.0 * ros_code_B.rtb_Tau_sl_tmp_l;
            ros_code_B.Tau_sl[static_cast<int32_T>(ros_code_B.object_num) +
              31247] = (((((((((((((((((ros_code_B.ds * ros_code_B.la_0 -
              ros_code_B.mean_angle * 0.0) - ros_code_B.rtb_Tau_sl_tmp_tmp_p *
              ros_code_B.angle_diff * ros_code_B.la_0) +
              ros_code_B.rtb_Tau_sl_tmp_c * ros_code_B.start_index * 0.0) -
              ros_code_B.s * ros_code_B.lv_0) + ros_code_B.s * 0.0) + 3.0 *
              ros_code_B.S_end * ros_code_B.dd_s * ros_code_B.la_0) + 4.0 *
                                  ros_code_B.kappa_x * ros_code_B.S_start *
                                  ros_code_B.la_0) - 4.0 * ros_code_B.S_end *
                                 ros_code_B.dd_s * 0.0) -
                                ros_code_B.rtb_Tau_sl_tmp_o * ros_code_B.S_start
                                * 0.0) + ros_code_B.rtb_Tau_sl_tmp_j *
                               ros_code_B.ls_0) + ros_code_B.rtb_Tau_sl_tmp_h *
                              ros_code_B.ls_0) - ros_code_B.rtb_Tau_sl_tmp_j *
                             ros_code_B.ls_1) - ros_code_B.rtb_Tau_sl_tmp_h *
                            ros_code_B.ls_1) - 24.0 * ros_code_B.S_end *
                           ros_code_B.start_index * ros_code_B.lv_0) + 36.0 *
                          ros_code_B.d_ls * ros_code_B.S_start * ros_code_B.lv_0)
                         - 36.0 * ros_code_B.S_end * ros_code_B.start_index *
                         0.0) + ros_code_B.rtb_Tau_sl_tmp * ros_code_B.S_start *
                        0.0) / ros_code_B.rtb_Tau_sl_tmp_ct;
            ros_code_B.ds = ros_code_B.angle_diff * 20.0;
            ros_code_B.mean_angle = ros_code_B.rtb_Tau_sl_tmp_c *
              ros_code_B.angle_diff;
            ros_code_B.s = 80.0 * ros_code_B.S_end * ros_code_B.S_start;
            ros_code_B.rtb_Tau_sl_tmp_j = 2.0 * ros_code_B.S_end *
              ros_code_B.S_start;
            ros_code_B.rtb_Tau_sl_tmp_h = ((ros_code_B.ex -
              ros_code_B.rtb_Tau_sl_tmp_j) + ros_code_B.angle_diff) * 2.0 *
              ros_code_B.rtb_Tau_sl_tmp_l;
            ros_code_B.Tau_sl[static_cast<int32_T>(ros_code_B.object_num) +
              35153] = -(((((((((((((((((((((ros_code_B.rtb_Tau_sl_tmp_o *
              ros_code_B.la_0 - ros_code_B.kappa_x * 0.0) + ros_code_B.dd_s *
              ros_code_B.la_0) - 3.0 * ros_code_B.dd_s * 0.0) +
              ros_code_B.rtb_Tau_sl_tmp_o2 * ros_code_B.ls_0) -
              ros_code_B.rtb_Tau_sl_tmp_o2 * ros_code_B.ls_1) + ros_code_B.ds *
              ros_code_B.ls_0) - ros_code_B.ds * ros_code_B.ls_1) + 12.0 *
              ros_code_B.d_ls * ros_code_B.lv_0) +
              ros_code_B.rtb_Tau_sl_tmp_tmp_p * 0.0) - 8.0 *
              ros_code_B.start_index * ros_code_B.lv_0) - 12.0 *
              ros_code_B.start_index * 0.0) - ros_code_B.mean_angle *
                                  ros_code_B.la_0) + ros_code_B.mean_angle * 0.0)
                                + ros_code_B.s * ros_code_B.ls_0) - ros_code_B.s
                               * ros_code_B.ls_1) + 4.0 * ros_code_B.S_end *
                              ros_code_B.start_index * ros_code_B.la_0) -
                             ros_code_B.rtb_Tau_sl_tmp_tmp_a *
                             ros_code_B.S_start * 0.0) - 32.0 * ros_code_B.S_end
                            * ros_code_B.angle_diff * ros_code_B.lv_0) +
                           ros_code_B.ex * 28.0 * ros_code_B.S_start *
                           ros_code_B.lv_0) - 28.0 * ros_code_B.S_end *
                          ros_code_B.angle_diff * 0.0) + ros_code_B.ex * 32.0 *
                         ros_code_B.S_start * 0.0) / ros_code_B.rtb_Tau_sl_tmp_h;
            ros_code_B.ds = ros_code_B.rtb_Tau_sl_tmp_j * 0.0;
            ros_code_B.Tau_sl[static_cast<int32_T>(ros_code_B.object_num) +
              39059] = (((((((((((((((((30.0 * ros_code_B.S_end *
              ros_code_B.ls_0 - 30.0 * ros_code_B.S_end * ros_code_B.ls_1) +
              30.0 * ros_code_B.S_start * ros_code_B.ls_0) - 30.0 *
              ros_code_B.S_start * ros_code_B.ls_1) + 3.0 * ros_code_B.d_ls *
              ros_code_B.la_0) - ros_code_B.rtb_Tau_sl_tmp_i * 0.0) + 2.0 *
              ros_code_B.start_index * ros_code_B.la_0) - 3.0 *
                                  ros_code_B.start_index * 0.0) +
                                 ros_code_B.rtb_Tau_sl_tmp_m * ros_code_B.lv_0)
                                + ros_code_B.ex * 14.0 * 0.0) -
                               ros_code_B.angle_diff * 14.0 * ros_code_B.lv_0) -
                              ros_code_B.angle_diff * 16.0 * 0.0) -
                             ros_code_B.rtb_Tau_sl_tmp_j * ros_code_B.lv_0) +
                            ros_code_B.ds) - ros_code_B.angle_diff *
                           ros_code_B.S_end * ros_code_B.la_0) - ros_code_B.ex *
                          4.0 * ros_code_B.S_start * ros_code_B.la_0) + 4.0 *
                         ros_code_B.S_end * ros_code_B.angle_diff * 0.0) +
                        ros_code_B.ex * ros_code_B.S_start * 0.0) /
              ros_code_B.rtb_Tau_sl_tmp_ct;
            ros_code_B.Tau_sl[static_cast<int32_T>(ros_code_B.object_num) +
              42965] = -(((((((((((12.0 * ros_code_B.ls_0 - 12.0 *
              ros_code_B.ls_1) + 6.0 * ros_code_B.S_end * ros_code_B.lv_0) + 6.0
                                 * ros_code_B.S_end * 0.0) - 6.0 *
                                ros_code_B.S_start * ros_code_B.lv_0) - 6.0 *
                               ros_code_B.S_start * 0.0) + ros_code_B.ex *
                              ros_code_B.la_0) - ros_code_B.ex * 0.0) +
                            ros_code_B.angle_diff * ros_code_B.la_0) -
                           ros_code_B.angle_diff * 0.0) -
                          ros_code_B.rtb_Tau_sl_tmp_j * ros_code_B.la_0) +
                         ros_code_B.ds) / ros_code_B.rtb_Tau_sl_tmp_h;
            ros_code_B.Tau_sl[static_cast<int32_T>(ros_code_B.object_num) +
              46871] = ros_code_B.a_m;
          }
        }
      }

      ros_code_B.Tau_sl[3905] = ros_code_B.object_num;
    } else {
      ros_code_B.max_range = ros_code_B.current_state_F[2] / 2.0;
      ros_code_B.object_num = 0.0;
      ros_code_B.B1[3] = ros_code_B.max_range;
      ros_code_B.B1[4] = ros_code_B.current_state_F[1];
      ros_code_B.B1[5] = ros_code_B.current_state_F[0];
      ros_code_B.sa5[3] = ros_code_B.max_range;
      ros_code_B.sa5[4] = ros_code_B.current_state_F[1];
      ros_code_B.sa5[5] = ros_code_B.current_state_F[0];
      for (ros_code_B.i = 0; ros_code_B.i < 21; ros_code_B.i++) {
        ros_code_B.a_m = static_cast<real_T>(ros_code_B.i) * 0.1 + 2.0;
        ros_code_B.ds = ros_code_B.a_m * ros_code_B.a_m;
        ros_code_B.mean_angle = ros_code_B.ds * 3.0 * ros_code_B.sa_0;
        ros_code_B.sa3 = -(((20.0 * ros_code_B.dd_ls - 20.0 *
                             ros_code_B.global_path_num) + 12.0 * ros_code_B.a_m
                            * ros_code_B.min_range) + ros_code_B.mean_angle) /
          (2.0 * rt_powd_snf(ros_code_B.a_m, 3.0));
        ros_code_B.sa4_c = (((30.0 * ros_code_B.dd_ls - 30.0 *
                              ros_code_B.global_path_num) + 16.0 *
                             ros_code_B.a_m * ros_code_B.min_range) +
                            ros_code_B.mean_angle) / (2.0 * rt_powd_snf
          (ros_code_B.a_m, 4.0));
        ros_code_B.ds = -(((12.0 * ros_code_B.dd_ls - 12.0 *
                            ros_code_B.global_path_num) + 6.0 * ros_code_B.a_m *
                           ros_code_B.min_range) + ros_code_B.ds *
                          ros_code_B.sa_0) / (2.0 * rt_powd_snf(ros_code_B.a_m,
          5.0));
        ros_code_B.B1[0] = ros_code_B.ds;
        ros_code_B.B1[1] = ros_code_B.sa4_c;
        ros_code_B.B1[2] = ros_code_B.sa3;
        ros_code_B.S_start = ros_code_polyval_gh(ros_code_B.B1, 0.0);
        ros_code_B.sa5[0] = ros_code_B.ds;
        ros_code_B.sa5[1] = ros_code_B.sa4_c;
        ros_code_B.sa5[2] = ros_code_B.sa3;
        ros_code_B.S_end = ros_code_polyval_gh(ros_code_B.sa5, ros_code_B.a_m);
        ros_code_B.dd_s = ros_code_B.S_end - ros_code_B.S_start;
        ros_code_B.object_num++;
        ros_code_B.c_a_tmp = rt_powd_snf(ros_code_B.S_end, 5.0);
        ros_code_B.s = rt_powd_snf(ros_code_B.S_start, 5.0);
        ros_code_B.kappa_x = rt_powd_snf(ros_code_B.S_end, 3.0);
        ros_code_B.d_ls = rt_powd_snf(ros_code_B.S_start, 4.0);
        ros_code_B.angle_diff = rt_powd_snf(ros_code_B.S_end, 4.0);
        ros_code_B.start_index = rt_powd_snf(ros_code_B.S_start, 3.0);
        ros_code_B.Tau_sl[static_cast<int32_T>(ros_code_B.object_num) - 1] =
          ros_code_B.dd_ls;
        ros_code_B.Tau_sl[static_cast<int32_T>(ros_code_B.object_num) + 3905] =
          ros_code_B.min_range;
        ros_code_B.Tau_sl[static_cast<int32_T>(ros_code_B.object_num) + 7811] =
          ros_code_B.max_range;
        ros_code_B.Tau_sl[static_cast<int32_T>(ros_code_B.object_num) + 11717] =
          ros_code_B.sa3;
        ros_code_B.Tau_sl[static_cast<int32_T>(ros_code_B.object_num) + 15623] =
          ros_code_B.sa4_c;
        ros_code_B.Tau_sl[static_cast<int32_T>(ros_code_B.object_num) + 19529] =
          ros_code_B.ds;
        ros_code_B.rtb_Tau_sl_tmp_j = ros_code_B.S_start * ros_code_B.S_start;
        ros_code_B.rtb_Tau_sl_tmp_h = ros_code_B.S_end * ros_code_B.S_end;
        ros_code_B.rtb_Tau_sl_tmp_tmp_p = ros_code_B.rtb_Tau_sl_tmp_h * 3.0;
        ros_code_B.rtb_Tau_sl_tmp_c = ros_code_B.rtb_Tau_sl_tmp_tmp_p *
          ros_code_B.S_start;
        ros_code_B.rtb_Tau_sl_tmp_ct = 3.0 * ros_code_B.S_end *
          ros_code_B.rtb_Tau_sl_tmp_j;
        ros_code_B.rtb_Tau_sl_tmp_p = 2.0 * rt_powd_snf(ros_code_B.S_end, 5.0) *
          ros_code_B.S_start;
        ros_code_B.rtb_Tau_sl_tmp_a = 10.0 * rt_powd_snf(ros_code_B.S_end, 4.0) *
          ros_code_B.S_start;
        ros_code_B.rtb_Tau_sl_tmp_e = ros_code_B.dd_s * ros_code_B.dd_s * 2.0;
        ros_code_B.rtb_Tau_sl_tmp_ax = 8.0 * ros_code_B.kappa_x;
        ros_code_B.rtb_Tau_sl_tmp_l = ros_code_B.rtb_Tau_sl_tmp_h * 20.0;
        ros_code_B.Tau_sl[static_cast<int32_T>(ros_code_B.object_num) + 23435] =
          (((((((((((((((((2.0 * ros_code_B.c_a_tmp * ros_code_B.ls_0 - 2.0 *
                           ros_code_B.s * 0.0) + ros_code_B.kappa_x *
                          ros_code_B.d_ls * ros_code_B.la_0) - 2.0 *
                         ros_code_B.angle_diff * ros_code_B.start_index *
                         ros_code_B.la_0) + ros_code_B.rtb_Tau_sl_tmp_j *
                        ros_code_B.c_a_tmp * ros_code_B.la_0) -
                       ros_code_B.rtb_Tau_sl_tmp_h * ros_code_B.s * 0.0) + 2.0 *
                      ros_code_B.kappa_x * ros_code_B.d_ls * 0.0) -
                     ros_code_B.angle_diff * ros_code_B.start_index * 0.0) +
                    20.0 * ros_code_B.kappa_x * ros_code_B.rtb_Tau_sl_tmp_j *
                    ros_code_B.ls_0) - ros_code_B.rtb_Tau_sl_tmp_l *
                   ros_code_B.start_index * 0.0) - 8.0 * ros_code_B.kappa_x *
                  ros_code_B.start_index * ros_code_B.lv_0) + 10.0 *
                 ros_code_B.angle_diff * ros_code_B.rtb_Tau_sl_tmp_j *
                 ros_code_B.lv_0) - ros_code_B.rtb_Tau_sl_tmp_h * 10.0 *
                ros_code_B.d_ls * 0.0) + ros_code_B.rtb_Tau_sl_tmp_ax *
               ros_code_B.start_index * 0.0) - ros_code_B.rtb_Tau_sl_tmp_a *
              ros_code_B.ls_0) + 10.0 * ros_code_B.S_end * ros_code_B.d_ls * 0.0)
            - ros_code_B.rtb_Tau_sl_tmp_p * ros_code_B.lv_0) + 2.0 *
           ros_code_B.S_end * ros_code_B.s * 0.0) / ((((ros_code_B.kappa_x -
          ros_code_B.rtb_Tau_sl_tmp_c) + ros_code_B.rtb_Tau_sl_tmp_ct) -
          ros_code_B.start_index) * ros_code_B.rtb_Tau_sl_tmp_e);
        ros_code_B.ds = ((ros_code_B.kappa_x - ros_code_B.rtb_Tau_sl_tmp_c) +
                         ros_code_B.rtb_Tau_sl_tmp_ct) - ros_code_B.start_index;
        ros_code_B.rtb_Tau_sl_tmp_tmp_a = ros_code_B.rtb_Tau_sl_tmp_h * 60.0;
        ros_code_B.rtb_Tau_sl_tmp_c = ros_code_B.rtb_Tau_sl_tmp_tmp_a *
          ros_code_B.rtb_Tau_sl_tmp_j;
        ros_code_B.rtb_Tau_sl_tmp_ct = ros_code_B.ds *
          ros_code_B.rtb_Tau_sl_tmp_e;
        ros_code_B.rtb_Tau_sl_tmp_e = 4.0 * ros_code_B.kappa_x;
        ros_code_B.rtb_Tau_sl_tmp_o2 = ros_code_B.rtb_Tau_sl_tmp_h * 16.0;
        ros_code_B.Tau_sl[static_cast<int32_T>(ros_code_B.object_num) + 27341] =
          (((((((((((((((((2.0 * rt_powd_snf(ros_code_B.S_end, 5.0) *
                           ros_code_B.lv_0 - 2.0 * ros_code_B.s * 0.0) -
                          ros_code_B.rtb_Tau_sl_tmp_tmp_p * ros_code_B.d_ls *
                          ros_code_B.la_0) + 4.0 * ros_code_B.kappa_x *
                         ros_code_B.start_index * ros_code_B.la_0) +
                        ros_code_B.rtb_Tau_sl_tmp_j * ros_code_B.angle_diff *
                        ros_code_B.la_0) - ros_code_B.rtb_Tau_sl_tmp_h *
                       ros_code_B.d_ls * 0.0) - ros_code_B.rtb_Tau_sl_tmp_e *
                      ros_code_B.start_index * 0.0) + 3.0 *
                     ros_code_B.angle_diff * ros_code_B.rtb_Tau_sl_tmp_j * 0.0)
                    - ros_code_B.rtb_Tau_sl_tmp_c * ros_code_B.ls_0) +
                   ros_code_B.rtb_Tau_sl_tmp_c * 0.0) +
                  ros_code_B.rtb_Tau_sl_tmp_h * 24.0 * ros_code_B.start_index *
                  ros_code_B.lv_0) - 16.0 * ros_code_B.kappa_x *
                 ros_code_B.rtb_Tau_sl_tmp_j * ros_code_B.lv_0) +
                ros_code_B.rtb_Tau_sl_tmp_o2 * ros_code_B.start_index * 0.0) -
               24.0 * ros_code_B.kappa_x * ros_code_B.rtb_Tau_sl_tmp_j * 0.0) -
              ros_code_B.rtb_Tau_sl_tmp_p * ros_code_B.la_0) + 2.0 *
             ros_code_B.S_end * ros_code_B.s * 0.0) -
            ros_code_B.rtb_Tau_sl_tmp_a * ros_code_B.lv_0) + 10.0 *
           ros_code_B.S_end * ros_code_B.d_ls * 0.0) /
          ros_code_B.rtb_Tau_sl_tmp_ct;
        ros_code_B.rtb_Tau_sl_tmp_c = ros_code_B.rtb_Tau_sl_tmp_h * 12.0 *
          ros_code_B.rtb_Tau_sl_tmp_j;
        ros_code_B.rtb_Tau_sl_tmp_p = 60.0 * ros_code_B.S_end *
          ros_code_B.rtb_Tau_sl_tmp_j;
        ros_code_B.rtb_Tau_sl_tmp_a = ros_code_B.rtb_Tau_sl_tmp_tmp_a *
          ros_code_B.S_start;
        ros_code_B.rtb_Tau_sl_tmp_i = 3.0 * ros_code_B.angle_diff;
        ros_code_B.rtb_Tau_sl_tmp_o = ros_code_B.rtb_Tau_sl_tmp_h * 8.0;
        ros_code_B.Tau_sl[static_cast<int32_T>(ros_code_B.object_num) + 31247] =
          (((((((((((((((((ros_code_B.c_a_tmp * ros_code_B.la_0 - ros_code_B.s *
                           0.0) - ros_code_B.rtb_Tau_sl_tmp_ax *
                          ros_code_B.rtb_Tau_sl_tmp_j * ros_code_B.la_0) +
                         ros_code_B.rtb_Tau_sl_tmp_o * ros_code_B.start_index *
                         0.0) - ros_code_B.rtb_Tau_sl_tmp_c * ros_code_B.lv_0) +
                       ros_code_B.rtb_Tau_sl_tmp_c * 0.0) + 3.0 *
                      ros_code_B.S_end * ros_code_B.d_ls * ros_code_B.la_0) +
                     4.0 * ros_code_B.angle_diff * ros_code_B.S_start *
                     ros_code_B.la_0) - 4.0 * ros_code_B.S_end * ros_code_B.d_ls
                    * 0.0) - ros_code_B.rtb_Tau_sl_tmp_i * ros_code_B.S_start *
                   0.0) + ros_code_B.rtb_Tau_sl_tmp_p * ros_code_B.ls_0) +
                 ros_code_B.rtb_Tau_sl_tmp_a * ros_code_B.ls_0) -
                ros_code_B.rtb_Tau_sl_tmp_p * 0.0) - ros_code_B.rtb_Tau_sl_tmp_a
               * 0.0) - 24.0 * ros_code_B.S_end * ros_code_B.start_index *
              ros_code_B.lv_0) + 36.0 * ros_code_B.kappa_x * ros_code_B.S_start *
             ros_code_B.lv_0) - 36.0 * ros_code_B.S_end * ros_code_B.start_index
            * 0.0) + 24.0 * ros_code_B.kappa_x * ros_code_B.S_start * 0.0) /
          ros_code_B.rtb_Tau_sl_tmp_ct;
        ros_code_B.s = 2.0 * ros_code_B.S_end * ros_code_B.S_start;
        ros_code_B.mean_angle = ((ros_code_B.rtb_Tau_sl_tmp_h - ros_code_B.s) +
          ros_code_B.rtb_Tau_sl_tmp_j) * 2.0 * ros_code_B.ds;
        ros_code_B.rtb_Tau_sl_tmp_c = ros_code_B.rtb_Tau_sl_tmp_j * 20.0;
        ros_code_B.rtb_Tau_sl_tmp_ct = ros_code_B.rtb_Tau_sl_tmp_o *
          ros_code_B.rtb_Tau_sl_tmp_j;
        ros_code_B.rtb_Tau_sl_tmp_p = 80.0 * ros_code_B.S_end *
          ros_code_B.S_start;
        ros_code_B.Tau_sl[static_cast<int32_T>(ros_code_B.object_num) + 35153] =
          -(((((((((((((((((((((ros_code_B.rtb_Tau_sl_tmp_i * ros_code_B.la_0 -
          ros_code_B.angle_diff * 0.0) + ros_code_B.d_ls * ros_code_B.la_0) -
                              3.0 * ros_code_B.d_ls * 0.0) +
                             ros_code_B.rtb_Tau_sl_tmp_l * ros_code_B.ls_0) -
                            ros_code_B.rtb_Tau_sl_tmp_l * 0.0) +
                           ros_code_B.rtb_Tau_sl_tmp_c * ros_code_B.ls_0) -
                          ros_code_B.rtb_Tau_sl_tmp_c * 0.0) + 12.0 *
                         ros_code_B.kappa_x * ros_code_B.lv_0) +
                        ros_code_B.rtb_Tau_sl_tmp_ax * 0.0) - 8.0 *
                       ros_code_B.start_index * ros_code_B.lv_0) - 12.0 *
                      ros_code_B.start_index * 0.0) -
                     ros_code_B.rtb_Tau_sl_tmp_ct * ros_code_B.la_0) +
                    ros_code_B.rtb_Tau_sl_tmp_ct * 0.0) +
                   ros_code_B.rtb_Tau_sl_tmp_p * ros_code_B.ls_0) -
                  ros_code_B.rtb_Tau_sl_tmp_p * 0.0) + 4.0 * ros_code_B.S_end *
                 ros_code_B.start_index * ros_code_B.la_0) -
                ros_code_B.rtb_Tau_sl_tmp_e * ros_code_B.S_start * 0.0) - 32.0 *
               ros_code_B.S_end * ros_code_B.rtb_Tau_sl_tmp_j * ros_code_B.lv_0)
              + ros_code_B.rtb_Tau_sl_tmp_h * 28.0 * ros_code_B.S_start *
              ros_code_B.lv_0) - 28.0 * ros_code_B.S_end *
             ros_code_B.rtb_Tau_sl_tmp_j * 0.0) + ros_code_B.rtb_Tau_sl_tmp_h *
            32.0 * ros_code_B.S_start * 0.0) / ros_code_B.mean_angle;
        ros_code_B.d_ls = ros_code_B.s * 0.0;
        ros_code_B.Tau_sl[static_cast<int32_T>(ros_code_B.object_num) + 39059] =
          (((((((((((((((((30.0 * ros_code_B.S_end * ros_code_B.ls_0 - 30.0 *
                           ros_code_B.S_end * 0.0) + 30.0 * ros_code_B.S_start *
                          ros_code_B.ls_0) - 30.0 * ros_code_B.S_start * 0.0) +
                        3.0 * ros_code_B.kappa_x * ros_code_B.la_0) - 2.0 *
                       ros_code_B.kappa_x * 0.0) + 2.0 * ros_code_B.start_index *
                      ros_code_B.la_0) - 3.0 * ros_code_B.start_index * 0.0) +
                    ros_code_B.rtb_Tau_sl_tmp_o2 * ros_code_B.lv_0) +
                   ros_code_B.rtb_Tau_sl_tmp_h * 14.0 * 0.0) -
                  ros_code_B.rtb_Tau_sl_tmp_j * 14.0 * ros_code_B.lv_0) -
                 ros_code_B.rtb_Tau_sl_tmp_j * 16.0 * 0.0) - ros_code_B.s *
                ros_code_B.lv_0) + ros_code_B.d_ls) -
              ros_code_B.rtb_Tau_sl_tmp_j * ros_code_B.S_end * ros_code_B.la_0)
             - ros_code_B.rtb_Tau_sl_tmp_h * 4.0 * ros_code_B.S_start *
             ros_code_B.la_0) + 4.0 * ros_code_B.S_end *
            ros_code_B.rtb_Tau_sl_tmp_j * 0.0) + ros_code_B.rtb_Tau_sl_tmp_h *
           ros_code_B.S_start * 0.0) / (ros_code_B.dd_s * ros_code_B.dd_s * 2.0 *
          ros_code_B.ds);
        ros_code_B.Tau_sl[static_cast<int32_T>(ros_code_B.object_num) + 42965] =
          -((((((((((6.0 * ros_code_B.S_end * ros_code_B.lv_0 + 12.0 *
                     ros_code_B.ls_0) + 6.0 * ros_code_B.S_end * 0.0) - 6.0 *
                   ros_code_B.S_start * ros_code_B.lv_0) - 6.0 *
                  ros_code_B.S_start * 0.0) + ros_code_B.rtb_Tau_sl_tmp_h *
                 ros_code_B.la_0) - ros_code_B.rtb_Tau_sl_tmp_h * 0.0) +
               ros_code_B.rtb_Tau_sl_tmp_j * ros_code_B.la_0) -
              ros_code_B.rtb_Tau_sl_tmp_j * 0.0) - ros_code_B.s *
             ros_code_B.la_0) + ros_code_B.d_ls) / ros_code_B.mean_angle;
        ros_code_B.Tau_sl[static_cast<int32_T>(ros_code_B.object_num) + 46871] =
          ros_code_B.a_m;
      }

      ros_code_B.Tau_sl[3905] = ros_code_B.object_num;
    }

    // MATLAB Function: '<S3>/reducePath'
    memset(&ros_code_B.rest_path[0], 0, 62496U * sizeof(real_T));
    if (ros_code_B.firstBlockLength != 0) {
      ros_code_B.lv_0 = 0.0;
      ros_code_B.sa_0 = 0.0;
      ros_code_B.la_0 = 0.0;
      ros_code_B.i = 0;
      while (ros_code_B.i <= static_cast<int32_T>(ros_code_B.Tau_sl[3905]) - 1)
      {
        ros_code_B.min_range = 0.0;
        ros_code_B.ls_0 = ros_code_B.Tau_sl[ros_code_B.i + 46872];
        ros_code_B.max_range = rt_roundd_snf(ros_code_B.ls_0 * 10.0);
        if (!(ros_code_B.max_range <= 100.0)) {
          ros_code_B.max_range = 100.0;
        }

        ros_code_B.dd_ls = ros_code_B.Tau_sl[ros_code_B.i + 19530];
        ros_code_B.B1[0] = ros_code_B.dd_ls;
        ros_code_B.ds = ros_code_B.Tau_sl[ros_code_B.i + 15624];
        ros_code_B.B1[1] = ros_code_B.ds;
        ros_code_B.mean_angle = ros_code_B.Tau_sl[ros_code_B.i + 11718];
        ros_code_B.B1[2] = ros_code_B.mean_angle;
        ros_code_B.d_ls = ros_code_B.Tau_sl[ros_code_B.i + 7812];
        ros_code_B.B1[3] = ros_code_B.d_ls;
        ros_code_B.dd_s = ros_code_B.Tau_sl[ros_code_B.i + 3906];
        ros_code_B.B1[4] = ros_code_B.dd_s;
        ros_code_B.B1[5] = ros_code_B.Tau_sl[ros_code_B.i];
        ros_code_linspace_m(ros_code_B.ls_0, ros_code_B.max_range,
                            ros_code_B.tmp_data_d, ros_code_B.tmp_size);
        ros_code_polyval(ros_code_B.B1, ros_code_B.tmp_data_d,
                         ros_code_B.tmp_size, ros_code_B.predit_s_data,
                         ros_code_B.g_size);
        ros_code_B.kappa_x = ros_code_B.Tau_sl[ros_code_B.i + 42966];
        ros_code_B.B1[0] = ros_code_B.kappa_x;
        ros_code_B.start_index = ros_code_B.Tau_sl[ros_code_B.i + 39060];
        ros_code_B.B1[1] = ros_code_B.start_index;
        ros_code_B.angle_diff = ros_code_B.Tau_sl[ros_code_B.i + 35154];
        ros_code_B.B1[2] = ros_code_B.angle_diff;
        ros_code_B.rtb_Tau_sl_tmp_j = ros_code_B.Tau_sl[ros_code_B.i + 31248];
        ros_code_B.B1[3] = ros_code_B.rtb_Tau_sl_tmp_j;
        ros_code_B.s = ros_code_B.Tau_sl[ros_code_B.i + 27342];
        ros_code_B.B1[4] = ros_code_B.s;
        ros_code_B.B1[5] = ros_code_B.Tau_sl[ros_code_B.i + 23436];
        ros_code_polyval(ros_code_B.B1, ros_code_B.predit_s_data,
                         ros_code_B.g_size, ros_code_B.predit_l_data,
                         ros_code_B.Y_interp_size);
        if (ros_code_B.object_array_F[9] <= 10.0) {
          ros_code_B.object_num = ros_code_B.object_array_F[9];
        } else {
          ros_code_B.object_num = 10.0;
        }

        if (ros_code_B.object_num != 0.0) {
          ros_code_B.nblocks = static_cast<int32_T>(ros_code_B.max_range);
          ros_code_B.sl_distance_size = static_cast<int32_T>
            (ros_code_B.max_range);
          if (ros_code_B.nblocks - 1 >= 0) {
            memset(&ros_code_B.sl_distance_data[0], 0, ros_code_B.nblocks *
                   sizeof(real_T));
          }

          ros_code_B.nx = static_cast<int32_T>(ros_code_B.object_num);
          ros_code_B.cg_object_distance_size = static_cast<int32_T>
            (ros_code_B.object_num);
          if (ros_code_B.nx - 1 >= 0) {
            memset(&ros_code_B.B2[0], 0, ros_code_B.nx * sizeof(real_T));
          }

          ros_code_B.a_m = rt_roundd_snf(ros_code_B.max_range / 2.0);
          ros_code_B.lastBlockLength = static_cast<int32_T>(ros_code_B.a_m) - 1;
          ros_code_B.max_range =
            ros_code_B.predit_s_data[ros_code_B.lastBlockLength];
          if (ros_code_B.object_num < 1.0) {
            ros_code_B.loop_ub = -1;
          } else {
            ros_code_B.loop_ub = static_cast<int32_T>(ros_code_B.object_num) - 1;
          }

          ros_code_B.rtb_object_array_F_size_o = ros_code_B.loop_ub + 1;
          ros_code_B.scalarLB = ((ros_code_B.loop_ub + 1) / 2) << 1;
          ros_code_B.vectorUB = ros_code_B.scalarLB - 2;
          for (ros_code_B.nx = 0; ros_code_B.nx <= ros_code_B.vectorUB;
               ros_code_B.nx += 2) {
            tmp_0 = _mm_loadu_pd(&ros_code_B.object_array_F[ros_code_B.nx]);
            _mm_storeu_pd(&ros_code_B.rtb_object_array_F_data_b[ros_code_B.nx],
                          _mm_sub_pd(tmp_0, _mm_set1_pd(ros_code_B.max_range)));
          }

          for (ros_code_B.nx = ros_code_B.scalarLB; ros_code_B.nx <=
               ros_code_B.loop_ub; ros_code_B.nx++) {
            ros_code_B.rtb_object_array_F_data_b[ros_code_B.nx] =
              ros_code_B.object_array_F[ros_code_B.nx] - ros_code_B.max_range;
          }

          ros_code_B.sa3 = ros_code_B.predit_l_data[ros_code_B.lastBlockLength];
          if (ros_code_B.object_num < 1.0) {
            ros_code_B.loop_ub = -1;
          } else {
            ros_code_B.loop_ub = static_cast<int32_T>(ros_code_B.object_num) - 1;
          }

          ros_code_B.rtb_object_array_F_size_g = ros_code_B.loop_ub + 1;
          ros_code_B.scalarLB = ((ros_code_B.loop_ub + 1) / 2) << 1;
          ros_code_B.vectorUB = ros_code_B.scalarLB - 2;
          for (ros_code_B.nx = 0; ros_code_B.nx <= ros_code_B.vectorUB;
               ros_code_B.nx += 2) {
            tmp_0 = _mm_loadu_pd(&ros_code_B.object_array_F[ros_code_B.nx + 10]);
            _mm_storeu_pd(&ros_code_B.rtb_object_array_F_data_l[ros_code_B.nx],
                          _mm_sub_pd(tmp_0, _mm_set1_pd(ros_code_B.sa3)));
          }

          for (ros_code_B.nx = ros_code_B.scalarLB; ros_code_B.nx <=
               ros_code_B.loop_ub; ros_code_B.nx++) {
            ros_code_B.rtb_object_array_F_data_l[ros_code_B.nx] =
              ros_code_B.object_array_F[ros_code_B.nx + 10] - ros_code_B.sa3;
          }

          ros_code_power(ros_code_B.rtb_object_array_F_data_b,
                         &ros_code_B.rtb_object_array_F_size_o,
                         ros_code_B.tmp_data_k, &ros_code_B.tmp_size_n);
          ros_code_power(ros_code_B.rtb_object_array_F_data_l,
                         &ros_code_B.rtb_object_array_F_size_g,
                         ros_code_B.tmp_data_k, &ros_code_B.x_size_k);
          if (ros_code_B.tmp_size_n == ros_code_B.x_size_k) {
            if (ros_code_B.object_num < 1.0) {
              ros_code_B.loop_ub = -1;
            } else {
              ros_code_B.loop_ub = static_cast<int32_T>(ros_code_B.object_num) -
                1;
            }

            ros_code_B.rtb_object_array_F_size_o = ros_code_B.loop_ub + 1;
            ros_code_B.scalarLB = ((ros_code_B.loop_ub + 1) / 2) << 1;
            ros_code_B.vectorUB = ros_code_B.scalarLB - 2;
            for (ros_code_B.nx = 0; ros_code_B.nx <= ros_code_B.vectorUB;
                 ros_code_B.nx += 2) {
              tmp_0 = _mm_loadu_pd(&ros_code_B.object_array_F[ros_code_B.nx]);
              _mm_storeu_pd(&ros_code_B.rtb_object_array_F_data_b[ros_code_B.nx],
                            _mm_sub_pd(tmp_0, _mm_set1_pd(ros_code_B.max_range)));
            }

            for (ros_code_B.nx = ros_code_B.scalarLB; ros_code_B.nx <=
                 ros_code_B.loop_ub; ros_code_B.nx++) {
              ros_code_B.rtb_object_array_F_data_b[ros_code_B.nx] =
                ros_code_B.object_array_F[ros_code_B.nx] - ros_code_B.max_range;
            }

            ros_code_power(ros_code_B.rtb_object_array_F_data_b,
                           &ros_code_B.rtb_object_array_F_size_o,
                           ros_code_B.distances, &ros_code_B.b_y_size);
            if (ros_code_B.object_num < 1.0) {
              ros_code_B.loop_ub = -1;
            } else {
              ros_code_B.loop_ub = static_cast<int32_T>(ros_code_B.object_num) -
                1;
            }

            ros_code_B.rtb_object_array_F_size_o = ros_code_B.loop_ub + 1;
            ros_code_B.scalarLB = ((ros_code_B.loop_ub + 1) / 2) << 1;
            ros_code_B.vectorUB = ros_code_B.scalarLB - 2;
            for (ros_code_B.nx = 0; ros_code_B.nx <= ros_code_B.vectorUB;
                 ros_code_B.nx += 2) {
              tmp_0 = _mm_loadu_pd(&ros_code_B.object_array_F[ros_code_B.nx + 10]);
              _mm_storeu_pd(&ros_code_B.rtb_object_array_F_data_b[ros_code_B.nx],
                            _mm_sub_pd(tmp_0, _mm_set1_pd(ros_code_B.sa3)));
            }

            for (ros_code_B.nx = ros_code_B.scalarLB; ros_code_B.nx <=
                 ros_code_B.loop_ub; ros_code_B.nx++) {
              ros_code_B.rtb_object_array_F_data_b[ros_code_B.nx] =
                ros_code_B.object_array_F[ros_code_B.nx + 10] - ros_code_B.sa3;
            }

            ros_code_power(ros_code_B.rtb_object_array_F_data_b,
                           &ros_code_B.rtb_object_array_F_size_o,
                           ros_code_B.tmp_data_k, &ros_code_B.tmp_size_n);
            ros_code_B.accurate_distance_size = ros_code_B.b_y_size;
            ros_code_B.loop_ub = ros_code_B.b_y_size;
            ros_code_B.scalarLB = (ros_code_B.b_y_size / 2) << 1;
            ros_code_B.vectorUB = ros_code_B.scalarLB - 2;
            for (ros_code_B.nx = 0; ros_code_B.nx <= ros_code_B.vectorUB;
                 ros_code_B.nx += 2) {
              tmp_0 = _mm_loadu_pd(&ros_code_B.distances[ros_code_B.nx]);
              tmp = _mm_loadu_pd(&ros_code_B.tmp_data_k[ros_code_B.nx]);
              _mm_storeu_pd(&ros_code_B.accurate_distance_data[ros_code_B.nx],
                            _mm_add_pd(tmp_0, tmp));
            }

            for (ros_code_B.nx = ros_code_B.scalarLB; ros_code_B.nx <
                 ros_code_B.loop_ub; ros_code_B.nx++) {
              ros_code_B.accurate_distance_data[ros_code_B.nx] =
                ros_code_B.distances[ros_code_B.nx] +
                ros_code_B.tmp_data_k[ros_code_B.nx];
            }
          } else {
            ros_code_binary_expand_op_p(ros_code_B.accurate_distance_data,
              &ros_code_B.accurate_distance_size, ros_code_B.object_array_F,
              ros_code_B.object_num, ros_code_B.predit_s_data, ros_code_B.a_m,
              ros_code_B.predit_l_data);
          }

          ros_code_sqrt(ros_code_B.accurate_distance_data,
                        &ros_code_B.accurate_distance_size);
          ros_code_B.loop_ub = ros_code_B.accurate_distance_size;
          if (ros_code_B.loop_ub - 1 >= 0) {
            memcpy(&ros_code_B.B2[0], &ros_code_B.accurate_distance_data[0],
                   ros_code_B.loop_ub * sizeof(real_T));
          }

          ros_code_minimum(ros_code_B.B2, &ros_code_B.cg_object_distance_size,
                           &ros_code_B.max_range, &ros_code_B.lastBlockLength);
          ros_code_B.max_range =
            ros_code_B.object_array_F[ros_code_B.lastBlockLength - 1];
          ros_code_B.rtb_object_array_F_size[0] = 1;
          ros_code_B.rtb_object_array_F_size[1] = ros_code_B.g_size[1];
          ros_code_B.loop_ub = ros_code_B.g_size[1];
          ros_code_B.scalarLB_tmp = (ros_code_B.g_size[1] / 2) << 1;
          ros_code_B.vectorUB = ros_code_B.scalarLB_tmp - 2;
          for (ros_code_B.nx = 0; ros_code_B.nx <= ros_code_B.vectorUB;
               ros_code_B.nx += 2) {
            ros_code_B.e = ros_code_B.nx;
            tmp_0 = _mm_loadu_pd(&ros_code_B.predit_s_data[ros_code_B.e]);
            _mm_storeu_pd(&ros_code_B.rtb_object_array_F_data[ros_code_B.e],
                          _mm_sub_pd(_mm_set1_pd(ros_code_B.max_range), tmp_0));
          }

          for (ros_code_B.nx = ros_code_B.scalarLB_tmp; ros_code_B.nx <
               ros_code_B.loop_ub; ros_code_B.nx++) {
            ros_code_B.scalarLB = ros_code_B.nx;
            ros_code_B.rtb_object_array_F_data[ros_code_B.scalarLB] =
              ros_code_B.max_range -
              ros_code_B.predit_s_data[ros_code_B.scalarLB];
          }

          ros_code_B.object_num =
            ros_code_B.object_array_F[ros_code_B.lastBlockLength + 9];
          ros_code_B.rtb_object_array_F_size_j[0] = 1;
          ros_code_B.rtb_object_array_F_size_j[1] = ros_code_B.Y_interp_size[1];
          ros_code_B.loop_ub = ros_code_B.Y_interp_size[1];
          ros_code_B.c_cg = (ros_code_B.Y_interp_size[1] / 2) << 1;
          ros_code_B.vectorUB = ros_code_B.c_cg - 2;
          for (ros_code_B.nx = 0; ros_code_B.nx <= ros_code_B.vectorUB;
               ros_code_B.nx += 2) {
            ros_code_B.e = ros_code_B.nx;
            tmp_0 = _mm_loadu_pd(&ros_code_B.predit_l_data[ros_code_B.e]);
            _mm_storeu_pd(&ros_code_B.rtb_object_array_F_data_j[ros_code_B.e],
                          _mm_sub_pd(_mm_set1_pd(ros_code_B.object_num), tmp_0));
          }

          for (ros_code_B.nx = ros_code_B.c_cg; ros_code_B.nx <
               ros_code_B.loop_ub; ros_code_B.nx++) {
            ros_code_B.scalarLB = ros_code_B.nx;
            ros_code_B.rtb_object_array_F_data_j[ros_code_B.scalarLB] =
              ros_code_B.object_num -
              ros_code_B.predit_l_data[ros_code_B.scalarLB];
          }

          ros_code_power_en(ros_code_B.rtb_object_array_F_data,
                            ros_code_B.rtb_object_array_F_size,
                            ros_code_B.tmp_data_d, ros_code_B.tmp_size);
          ros_code_power_en(ros_code_B.rtb_object_array_F_data_j,
                            ros_code_B.rtb_object_array_F_size_j,
                            ros_code_B.tmp_data_d, ros_code_B.tmp_size_o);
          if (ros_code_B.tmp_size[1] == ros_code_B.tmp_size_o[1]) {
            ros_code_B.rtb_object_array_F_size[0] = 1;
            ros_code_B.rtb_object_array_F_size[1] = ros_code_B.g_size[1];
            ros_code_B.loop_ub = ros_code_B.g_size[1];
            ros_code_B.vectorUB = ros_code_B.scalarLB_tmp - 2;
            for (ros_code_B.nx = 0; ros_code_B.nx <= ros_code_B.vectorUB;
                 ros_code_B.nx += 2) {
              ros_code_B.e = ros_code_B.nx;
              tmp_0 = _mm_loadu_pd(&ros_code_B.predit_s_data[ros_code_B.e]);
              _mm_storeu_pd(&ros_code_B.rtb_object_array_F_data[ros_code_B.e],
                            _mm_sub_pd(_mm_set1_pd(ros_code_B.max_range), tmp_0));
            }

            for (ros_code_B.nx = ros_code_B.scalarLB_tmp; ros_code_B.nx <
                 ros_code_B.loop_ub; ros_code_B.nx++) {
              ros_code_B.scalarLB = ros_code_B.nx;
              ros_code_B.rtb_object_array_F_data[ros_code_B.scalarLB] =
                ros_code_B.max_range -
                ros_code_B.predit_s_data[ros_code_B.scalarLB];
            }

            ros_code_power_en(ros_code_B.rtb_object_array_F_data,
                              ros_code_B.rtb_object_array_F_size,
                              ros_code_B.rtb_object_array_F_data_j,
                              ros_code_B.rtb_object_array_F_size_j);
            ros_code_B.rtb_object_array_F_size[0] = 1;
            ros_code_B.rtb_object_array_F_size[1] = ros_code_B.Y_interp_size[1];
            ros_code_B.loop_ub = ros_code_B.Y_interp_size[1];
            ros_code_B.vectorUB = ros_code_B.c_cg - 2;
            for (ros_code_B.nx = 0; ros_code_B.nx <= ros_code_B.vectorUB;
                 ros_code_B.nx += 2) {
              ros_code_B.e = ros_code_B.nx;
              tmp_0 = _mm_loadu_pd(&ros_code_B.predit_l_data[ros_code_B.e]);
              _mm_storeu_pd(&ros_code_B.rtb_object_array_F_data[ros_code_B.e],
                            _mm_sub_pd(_mm_set1_pd(ros_code_B.object_num), tmp_0));
            }

            for (ros_code_B.nx = ros_code_B.c_cg; ros_code_B.nx <
                 ros_code_B.loop_ub; ros_code_B.nx++) {
              ros_code_B.scalarLB = ros_code_B.nx;
              ros_code_B.rtb_object_array_F_data[ros_code_B.scalarLB] =
                ros_code_B.object_num -
                ros_code_B.predit_l_data[ros_code_B.scalarLB];
            }

            ros_code_power_en(ros_code_B.rtb_object_array_F_data,
                              ros_code_B.rtb_object_array_F_size,
                              ros_code_B.tmp_data_d, ros_code_B.tmp_size);
            ros_code_B.n_size[0] = 1;
            ros_code_B.n_size[1] = ros_code_B.rtb_object_array_F_size_j[1];
            ros_code_B.loop_ub = ros_code_B.rtb_object_array_F_size_j[1];
            ros_code_B.scalarLB = (ros_code_B.rtb_object_array_F_size_j[1] / 2) <<
              1;
            ros_code_B.vectorUB = ros_code_B.scalarLB - 2;
            for (ros_code_B.nx = 0; ros_code_B.nx <= ros_code_B.vectorUB;
                 ros_code_B.nx += 2) {
              ros_code_B.e = ros_code_B.nx;
              tmp_0 = _mm_loadu_pd
                (&ros_code_B.rtb_object_array_F_data_j[ros_code_B.e]);
              tmp = _mm_loadu_pd(&ros_code_B.tmp_data_d[ros_code_B.e]);
              _mm_storeu_pd(&ros_code_B.n_data[ros_code_B.nx], _mm_add_pd(tmp_0,
                tmp));
            }

            for (ros_code_B.nx = ros_code_B.scalarLB; ros_code_B.nx <
                 ros_code_B.loop_ub; ros_code_B.nx++) {
              ros_code_B.vectorUB = ros_code_B.nx;
              ros_code_B.n_data[ros_code_B.vectorUB] =
                ros_code_B.rtb_object_array_F_data_j[ros_code_B.vectorUB] +
                ros_code_B.tmp_data_d[ros_code_B.vectorUB];
            }
          } else {
            ros_code_binary_expand_op(ros_code_B.n_data, ros_code_B.n_size,
              ros_code_B.object_array_F, ros_code_B.lastBlockLength,
              ros_code_B.predit_s_data, ros_code_B.g_size,
              ros_code_B.predit_l_data, ros_code_B.Y_interp_size);
          }

          ros_code_B.nx = ros_code_B.n_size[1];
          ros_code_B.c_cg = 0;
          while (ros_code_B.c_cg <= ros_code_B.nx - 1) {
            ros_code_B.vectorUB = ros_code_B.c_cg;
            ros_code_B.n_data[ros_code_B.vectorUB] = sqrt
              (ros_code_B.n_data[ros_code_B.vectorUB]);
            ros_code_B.c_cg++;
          }

          if (ros_code_B.nblocks - 1 >= 0) {
            memcpy(&ros_code_B.sl_distance_data[0], &ros_code_B.n_data[0],
                   ros_code_B.nblocks * sizeof(real_T));
          }

          ros_code_minimum(ros_code_B.sl_distance_data,
                           &ros_code_B.sl_distance_size, &ros_code_B.max_range,
                           &ros_code_B.c_cg);
          if (ros_code_B.max_range <= 6.0) {
            ros_code_B.max_range =
              ros_code_B.object_array_F[ros_code_B.lastBlockLength + 19];
            if (ros_code_B.max_range + -600.0 >= 1.0) {
              ros_code_B.min_range = ros_code_B.max_range + -600.0;
            } else {
              ros_code_B.min_range = 1.0;
            }

            if ((ros_code_B.max_range + 600.0 <=
                 ros_code_B.preprocess_global_path_array[1999]) || rtIsNaN
                (ros_code_B.preprocess_global_path_array[1999])) {
              ros_code_B.max_range += 600.0;
            } else {
              ros_code_B.max_range = ros_code_B.preprocess_global_path_array
                [1999];
            }

            if (ros_code_B.min_range > ros_code_B.max_range) {
              ros_code_B.scalarLB_tmp = 0;
              ros_code_B.nx = 0;
            } else {
              ros_code_B.scalarLB_tmp = static_cast<int32_T>
                (ros_code_B.min_range) - 1;
              ros_code_B.nx = static_cast<int32_T>(ros_code_B.max_range);
            }

            ros_code_B.max_range = ros_code_B.predit_s_data[ros_code_B.c_cg - 1];
            ros_code_B.nblocks = ros_code_B.nx - ros_code_B.scalarLB_tmp;
            ros_code_B.b_y_size = ros_code_B.nblocks;
            ros_code_B.scalarLB = (ros_code_B.nblocks / 2) << 1;
            ros_code_B.vectorUB = ros_code_B.scalarLB - 2;
            for (ros_code_B.nx = 0; ros_code_B.nx <= ros_code_B.vectorUB;
                 ros_code_B.nx += 2) {
              tmp_0 = _mm_loadu_pd(&ros_code_B.preprocess_global_path_array
                                   [(ros_code_B.scalarLB_tmp + ros_code_B.nx) +
                                   8000]);
              _mm_storeu_pd(&ros_code_B.distances[ros_code_B.nx], _mm_sub_pd
                            (tmp_0, _mm_set1_pd(ros_code_B.max_range)));
            }

            for (ros_code_B.nx = ros_code_B.scalarLB; ros_code_B.nx <
                 ros_code_B.nblocks; ros_code_B.nx++) {
              ros_code_B.distances[ros_code_B.nx] =
                ros_code_B.preprocess_global_path_array[(ros_code_B.scalarLB_tmp
                + ros_code_B.nx) + 8000] - ros_code_B.max_range;
            }

            ros_code_power(ros_code_B.distances, &ros_code_B.b_y_size,
                           ros_code_B.accurate_distance_data,
                           &ros_code_B.accurate_distance_size);
            ros_code_sqrt(ros_code_B.accurate_distance_data,
                          &ros_code_B.accurate_distance_size);
            ros_code_minimum(ros_code_B.accurate_distance_data,
                             &ros_code_B.accurate_distance_size,
                             &ros_code_B.object_num, &ros_code_B.nx);
            ros_code_B.object_num = (ros_code_B.min_range + static_cast<real_T>
              (ros_code_B.nx)) - 1.0;
            ros_code_B.min_range = ros_code_B.preprocess_global_path_array[
              static_cast<int32_T>(ros_code_B.object_num) + 3999];
            ros_code_B.sa4_c = ros_code_B.predit_l_data[ros_code_B.c_cg - 1];
            ros_code_B.a_m = ros_code_B.preprocess_global_path_array[
              static_cast<int32_T>(ros_code_B.object_num) - 1] -
              ros_code_B.sa4_c * sin(ros_code_B.min_range);
            ros_code_B.sa3 = ros_code_B.sa4_c * cos(ros_code_B.min_range) +
              ros_code_B.preprocess_global_path_array[static_cast<int32_T>
              (ros_code_B.object_num) + 1999];
            ros_code_B.last_path_data[0] = ros_code_B.kappa_x * 5.0;
            ros_code_B.last_path_data[1] = ros_code_B.start_index * 4.0;
            ros_code_B.last_path_data[2] = ros_code_B.angle_diff * 3.0;
            ros_code_B.last_path_data[3] = ros_code_B.rtb_Tau_sl_tmp_j * 2.0;
            ros_code_B.last_path_data[4] = ros_code_B.s;
            ros_code_B.max_range = rt_atan2d_snf(ros_code_polyval_o
              (ros_code_B.last_path_data, ros_code_B.max_range), 1.0 -
              ros_code_B.preprocess_global_path_array[static_cast<int32_T>
              (ros_code_B.object_num) + 5999] * ros_code_B.sa4_c) +
              ros_code_B.min_range;
            ros_code_wrapToPi_n(&ros_code_B.max_range);
            ros_code_B.S_end = sin(ros_code_B.max_range);
            ros_code_B.c_a_tmp = cos(ros_code_B.max_range);
            ros_code_B.ddls_coeffs[0] = ros_code_B.c_a_tmp;
            ros_code_B.ddls_coeffs[2] = -ros_code_B.S_end;
            ros_code_B.ddls_coeffs[1] = ros_code_B.S_end;
            ros_code_B.ddls_coeffs[3] = ros_code_B.c_a_tmp;
            for (ros_code_B.nx = 0; ros_code_B.nx < 2; ros_code_B.nx++) {
              for (ros_code_B.c_cg = 0; ros_code_B.c_cg < 4; ros_code_B.c_cg++)
              {
                ros_code_B.nblocks = ros_code_B.c_cg << 1;
                ros_code_B.loop_ub = ros_code_B.nx + ros_code_B.nblocks;
                ros_code_B.current_state_F[ros_code_B.loop_ub] = 0.0;
                ros_code_B.current_state_F[ros_code_B.loop_ub] +=
                  l[ros_code_B.nblocks] * ros_code_B.ddls_coeffs[ros_code_B.nx];
                ros_code_B.current_state_F[ros_code_B.loop_ub] +=
                  l[ros_code_B.nblocks + 1] *
                  ros_code_B.ddls_coeffs[ros_code_B.nx + 2];
              }
            }

            ros_code_B.object_num =
              ros_code_B.object_array[ros_code_B.lastBlockLength - 1];
            ros_code_B.sa4_c =
              ros_code_B.object_array[ros_code_B.lastBlockLength + 9];
            ros_code_B.ddls_coeffs[0] = ros_code_B.current_state_F[0] +
              ros_code_B.a_m;
            ros_code_B.y[0] = ros_code_B.current_state_F[1] + ros_code_B.sa3;
            ros_code_B.object_corners_x[0] = ros_code_B.current_state_F[0] +
              ros_code_B.object_num;
            ros_code_B.object_corners_y[0] = ros_code_B.current_state_F[1] +
              ros_code_B.sa4_c;
            ros_code_B.ddls_coeffs[1] = ros_code_B.current_state_F[2] +
              ros_code_B.a_m;
            ros_code_B.y[1] = ros_code_B.current_state_F[3] + ros_code_B.sa3;
            ros_code_B.object_corners_x[1] = ros_code_B.current_state_F[2] +
              ros_code_B.object_num;
            ros_code_B.object_corners_y[1] = ros_code_B.current_state_F[3] +
              ros_code_B.sa4_c;
            ros_code_B.ddls_coeffs[2] = ros_code_B.current_state_F[4] +
              ros_code_B.a_m;
            ros_code_B.y[2] = ros_code_B.current_state_F[5] + ros_code_B.sa3;
            ros_code_B.object_corners_x[2] = ros_code_B.current_state_F[4] +
              ros_code_B.object_num;
            ros_code_B.object_corners_y[2] = ros_code_B.current_state_F[5] +
              ros_code_B.sa4_c;
            ros_code_B.ddls_coeffs[3] = ros_code_B.current_state_F[6] +
              ros_code_B.a_m;
            ros_code_B.y[3] = ros_code_B.current_state_F[7] + ros_code_B.sa3;
            ros_code_B.object_corners_x[3] = ros_code_B.current_state_F[6] +
              ros_code_B.object_num;
            ros_code_B.object_corners_y[3] = ros_code_B.current_state_F[7] +
              ros_code_B.sa4_c;
            ros_code_B.S_start = ros_code_detectCollision(ros_code_B.ddls_coeffs,
              ros_code_B.y, ros_code_B.object_corners_x,
              ros_code_B.object_corners_y,
              ros_code_B.object_array[ros_code_B.lastBlockLength + 19] *
              ros_code_B.object_array[ros_code_B.lastBlockLength + 29]);
            ros_code_B.min_range = ros_code_detectCollision
              (ros_code_B.object_corners_x, ros_code_B.object_corners_y,
               ros_code_B.ddls_coeffs, ros_code_B.y, 0.5);
            if ((ros_code_B.S_start >= ros_code_B.min_range) || rtIsNaN
                (ros_code_B.min_range)) {
              ros_code_B.min_range = ros_code_B.S_start;
            }

            if (ros_code_B.min_range == 0.0) {
              ros_code_B.ddls_coeffs[0] = ros_code_B.c_a_tmp;
              ros_code_B.ddls_coeffs[2] = -sin(ros_code_B.max_range);
              ros_code_B.ddls_coeffs[1] = ros_code_B.S_end;
              ros_code_B.ddls_coeffs[3] = ros_code_B.c_a_tmp;
              for (ros_code_B.nx = 0; ros_code_B.nx < 2; ros_code_B.nx++) {
                for (ros_code_B.c_cg = 0; ros_code_B.c_cg < 4; ros_code_B.c_cg++)
                {
                  ros_code_B.nblocks = ros_code_B.c_cg << 1;
                  ros_code_B.loop_ub = ros_code_B.nx + ros_code_B.nblocks;
                  ros_code_B.current_state_F[ros_code_B.loop_ub] = 0.0;
                  ros_code_B.current_state_F[ros_code_B.loop_ub] +=
                    m[ros_code_B.nblocks] * ros_code_B.ddls_coeffs[ros_code_B.nx];
                  ros_code_B.current_state_F[ros_code_B.loop_ub] +=
                    m[ros_code_B.nblocks + 1] *
                    ros_code_B.ddls_coeffs[ros_code_B.nx + 2];
                }
              }

              ros_code_B.ddls_coeffs[0] = ros_code_B.current_state_F[1] +
                ros_code_B.sa3;
              ros_code_B.y[0] = ros_code_B.current_state_F[0] +
                ros_code_B.object_num;
              ros_code_B.object_corners_x[0] = ros_code_B.current_state_F[1] +
                ros_code_B.sa4_c;
              ros_code_B.object_corners_y[0] = ros_code_B.current_state_F[0] +
                ros_code_B.a_m;
              ros_code_B.ddls_coeffs[1] = ros_code_B.current_state_F[3] +
                ros_code_B.sa3;
              ros_code_B.y[1] = ros_code_B.current_state_F[2] +
                ros_code_B.object_num;
              ros_code_B.object_corners_x[1] = ros_code_B.current_state_F[3] +
                ros_code_B.sa4_c;
              ros_code_B.object_corners_y[1] = ros_code_B.current_state_F[2] +
                ros_code_B.a_m;
              ros_code_B.ddls_coeffs[2] = ros_code_B.current_state_F[5] +
                ros_code_B.sa3;
              ros_code_B.y[2] = ros_code_B.current_state_F[4] +
                ros_code_B.object_num;
              ros_code_B.object_corners_x[2] = ros_code_B.current_state_F[5] +
                ros_code_B.sa4_c;
              ros_code_B.object_corners_y[2] = ros_code_B.current_state_F[4] +
                ros_code_B.a_m;
              ros_code_B.ddls_coeffs[3] = ros_code_B.current_state_F[7] +
                ros_code_B.sa3;
              ros_code_B.y[3] = ros_code_B.current_state_F[6] +
                ros_code_B.object_num;
              ros_code_B.object_corners_x[3] = ros_code_B.current_state_F[7] +
                ros_code_B.sa4_c;
              ros_code_B.object_corners_y[3] = ros_code_B.current_state_F[6] +
                ros_code_B.a_m;
              ros_code_B.S_start = ros_code_detectCollision
                (ros_code_B.object_corners_y, ros_code_B.ddls_coeffs,
                 ros_code_B.y, ros_code_B.object_corners_x, 2.0);
              ros_code_B.max_range = ros_code_detectCollision(ros_code_B.y,
                ros_code_B.ddls_coeffs, ros_code_B.object_corners_x,
                ros_code_B.ddls_coeffs, 2.0);
              if ((ros_code_B.S_start >= ros_code_B.max_range) || rtIsNaN
                  (ros_code_B.max_range)) {
                ros_code_B.max_range = ros_code_B.S_start;
              }

              if (ros_code_B.max_range == 1.0) {
                ros_code_B.a_m -= ros_code_B.object_num;
                ros_code_B.lv_0 = ros_code_B.sa3 - ros_code_B.sa4_c;
                ros_code_B.lv_0 = sqrt(ros_code_B.a_m * ros_code_B.a_m +
                  ros_code_B.lv_0 * ros_code_B.lv_0);
              }
            }
          }
        }

        if (ros_code_B.min_range != 1.0) {
          ros_code_B.lastBlockLength = 0;
          ros_code_B.predict_next_state[0] = ros_code_B.dd_ls * 60.0;
          ros_code_B.predict_next_state[1] = ros_code_B.ds * 24.0;
          ros_code_B.c_a_tmp = ros_code_B.mean_angle * 6.0;
          ros_code_B.predict_next_state[2] = ros_code_B.c_a_tmp;
          ros_code_roots(ros_code_B.predict_next_state,
                         ros_code_B.roots_ddds_data, &ros_code_B.tmp_size_n);
          ros_code_B.real_roots_ddds_size = ros_code_B.tmp_size_n;
          ros_code_B.nblocks = ros_code_B.tmp_size_n;
          for (ros_code_B.nx = 0; ros_code_B.nx < ros_code_B.nblocks;
               ros_code_B.nx++) {
            ros_code_B.real_roots_ddds_data[ros_code_B.nx] =
              ros_code_B.roots_ddds_data[ros_code_B.nx].re;
          }

          ros_code_B.loop_ub = ros_code_B.tmp_size_n;
          ros_code_B.nblocks = ros_code_B.tmp_size_n;
          for (ros_code_B.nx = 0; ros_code_B.nx < ros_code_B.nblocks;
               ros_code_B.nx++) {
            d_data[ros_code_B.nx] =
              (ros_code_B.real_roots_ddds_data[ros_code_B.nx] < 0.0);
          }

          ros_code_B.nblocks = ros_code_B.tmp_size_n;
          for (ros_code_B.nx = 0; ros_code_B.nx < ros_code_B.nblocks;
               ros_code_B.nx++) {
            e_data[ros_code_B.nx] =
              (ros_code_B.real_roots_ddds_data[ros_code_B.nx] > ros_code_B.ls_0);
          }

          ros_code_B.nx = 0;
          while (ros_code_B.nx <= ros_code_B.loop_ub - 1) {
            if (d_data[ros_code_B.nx] || e_data[ros_code_B.nx]) {
              ros_code_B.real_roots_ddds_data[ros_code_B.nx] = 0.0;
            }

            ros_code_B.nx++;
          }

          ros_code_B.ddls_coeffs[0] = ros_code_B.dd_ls * 20.0;
          ros_code_B.ddls_coeffs[1] = ros_code_B.ds * 12.0;
          ros_code_B.ddls_coeffs[2] = ros_code_B.c_a_tmp;
          ros_code_B.ddls_coeffs[3] = ros_code_B.d_ls * 2.0;
          ros_code_polyval_on(ros_code_B.ddls_coeffs,
                              ros_code_B.real_roots_ddds_data,
                              &ros_code_B.real_roots_ddds_size,
                              ros_code_B.tmp_data_a, &ros_code_B.tmp_size_n);
          ros_code_abs(ros_code_B.tmp_data_a, &ros_code_B.tmp_size_n,
                       ros_code_B.tmp_data_bj, &ros_code_B.x_size_k);
          ros_code_B.min_range = ros_code_maximum(ros_code_B.tmp_data_bj,
            &ros_code_B.x_size_k);
          if (ros_code_B.min_range > 4.9) {
            ros_code_B.lastBlockLength = 1;
          } else {
            ros_code_B.last_path_data[0] = ros_code_B.kappa_x * 5.0;
            ros_code_B.last_path_data[1] = ros_code_B.start_index * 4.0;
            ros_code_B.last_path_data[2] = ros_code_B.angle_diff * 3.0;
            ros_code_B.ex = ros_code_B.rtb_Tau_sl_tmp_j * 2.0;
            ros_code_B.last_path_data[3] = ros_code_B.ex;
            ros_code_B.last_path_data[4] = ros_code_B.s;
            ros_code_B.ddls_coeffs[0] = ros_code_B.kappa_x * 20.0;
            ros_code_B.ddls_coeffs[1] = ros_code_B.start_index * 12.0;
            ros_code_B.angle_diff *= 6.0;
            ros_code_B.ddls_coeffs[2] = ros_code_B.angle_diff;
            ros_code_B.ddls_coeffs[3] = ros_code_B.ex;
            ros_code_B.predict_next_state[0] = ros_code_B.kappa_x * 60.0;
            ros_code_B.predict_next_state[1] = ros_code_B.start_index * 24.0;
            ros_code_B.predict_next_state[2] = ros_code_B.angle_diff;
            ros_code_B.B1[0] = ros_code_B.dd_ls;
            ros_code_B.B1[1] = ros_code_B.ds;
            ros_code_B.B1[2] = ros_code_B.mean_angle;
            ros_code_B.B1[3] = ros_code_B.d_ls;
            ros_code_B.B1[4] = ros_code_B.dd_s;
            ros_code_B.B1[5] = ros_code_B.Tau_sl[ros_code_B.i];
            ros_code_B.kappa_x = ros_code_B.dd_ls;
            for (ros_code_B.nx = 0; ros_code_B.nx < 5; ros_code_B.nx++) {
              ros_code_B.kappa_x = 0.0 * ros_code_B.kappa_x +
                ros_code_B.B1[ros_code_B.nx + 1];
            }

            ros_code_B.B1[0] = ros_code_B.dd_ls;
            ros_code_B.B1[1] = ros_code_B.ds;
            ros_code_B.B1[2] = ros_code_B.mean_angle;
            ros_code_B.B1[3] = ros_code_B.d_ls;
            ros_code_B.B1[4] = ros_code_B.dd_s;
            ros_code_B.B1[5] = ros_code_B.Tau_sl[ros_code_B.i];
            for (ros_code_B.nx = 0; ros_code_B.nx < 5; ros_code_B.nx++) {
              ros_code_B.dd_ls = ros_code_B.ls_0 * ros_code_B.dd_ls +
                ros_code_B.B1[ros_code_B.nx + 1];
            }

            ros_code_B.ddls_coeffs_n[0] = (ros_code_B.ddls_coeffs[0] == 0.0);
            ros_code_B.ddls_coeffs_n[1] = (ros_code_B.ddls_coeffs[1] == 0.0);
            ros_code_B.ddls_coeffs_n[2] = (ros_code_B.angle_diff == 0.0);
            ros_code_B.ddls_coeffs_n[3] = (ros_code_B.ex == 0.0);
            if (ros_code_all(ros_code_B.ddls_coeffs_n)) {
              if (ros_code_polyval_o(ros_code_B.last_path_data,
                                     ros_code_B.kappa_x) > 1.0471975511965976) {
                ros_code_B.lastBlockLength = 1;
              }
            } else {
              ros_code_roots_n(ros_code_B.ddls_coeffs,
                               ros_code_B.roots_ddls_data,
                               &ros_code_B.tmp_size_n);
              ros_code_B.real_roots_ddls_size = ros_code_B.tmp_size_n;
              ros_code_B.nblocks = ros_code_B.tmp_size_n;
              for (ros_code_B.nx = 0; ros_code_B.nx < ros_code_B.nblocks;
                   ros_code_B.nx++) {
                ros_code_B.real_roots_ddls_data[ros_code_B.nx] =
                  ros_code_B.roots_ddls_data[ros_code_B.nx].re;
              }

              ros_code_B.loop_ub = ros_code_B.tmp_size_n;
              ros_code_B.nblocks = ros_code_B.tmp_size_n;
              for (ros_code_B.nx = 0; ros_code_B.nx < ros_code_B.nblocks;
                   ros_code_B.nx++) {
                ros_code_B.f_data_f[ros_code_B.nx] =
                  (ros_code_B.real_roots_ddls_data[ros_code_B.nx] <
                   ros_code_B.kappa_x);
              }

              ros_code_B.nblocks = ros_code_B.tmp_size_n;
              for (ros_code_B.nx = 0; ros_code_B.nx < ros_code_B.nblocks;
                   ros_code_B.nx++) {
                ros_code_B.g_data[ros_code_B.nx] =
                  (ros_code_B.real_roots_ddls_data[ros_code_B.nx] >
                   ros_code_B.dd_ls);
              }

              ros_code_B.nx = 0;
              while (ros_code_B.nx <= ros_code_B.loop_ub - 1) {
                if (ros_code_B.f_data_f[ros_code_B.nx] ||
                    ros_code_B.g_data[ros_code_B.nx]) {
                  ros_code_B.real_roots_ddls_data[ros_code_B.nx] =
                    ros_code_B.kappa_x;
                }

                ros_code_B.nx++;
              }

              ros_code_polyval_ong(ros_code_B.last_path_data,
                                   ros_code_B.real_roots_ddls_data,
                                   &ros_code_B.real_roots_ddls_size,
                                   ros_code_B.tmp_data_bj,
                                   &ros_code_B.tmp_size_n);
              ros_code_abs(ros_code_B.tmp_data_bj, &ros_code_B.tmp_size_n,
                           ros_code_B.real_roots_ddls_data, &ros_code_B.x_size_k);
              if (ros_code_maximum(ros_code_B.real_roots_ddls_data,
                                   &ros_code_B.x_size_k) > 1.0471975511965976) {
                ros_code_B.lastBlockLength = 1;
              }
            }

            ros_code_B.f_data_f[0] = (ros_code_B.predict_next_state[0] == 0.0);
            ros_code_B.f_data_f[1] = (ros_code_B.predict_next_state[1] == 0.0);
            ros_code_B.f_data_f[2] = (ros_code_B.angle_diff == 0.0);
            if (ros_code_all_j(ros_code_B.f_data_f)) {
              ros_code_B.la_0 = ((ros_code_B.kappa_x * ros_code_B.ddls_coeffs[0]
                                  + ros_code_B.ddls_coeffs[1]) *
                                 ros_code_B.kappa_x + ros_code_B.angle_diff) *
                ros_code_B.kappa_x + ros_code_B.ex;
            } else {
              ros_code_roots(ros_code_B.predict_next_state,
                             ros_code_B.roots_ddds_data, &ros_code_B.tmp_size_n);
              ros_code_B.real_roots_ddds_size = ros_code_B.tmp_size_n;
              ros_code_B.nblocks = ros_code_B.tmp_size_n;
              for (ros_code_B.nx = 0; ros_code_B.nx < ros_code_B.nblocks;
                   ros_code_B.nx++) {
                ros_code_B.real_roots_ddds_data[ros_code_B.nx] =
                  ros_code_B.roots_ddds_data[ros_code_B.nx].re;
              }

              ros_code_B.loop_ub = ros_code_B.tmp_size_n;
              ros_code_B.nblocks = ros_code_B.tmp_size_n;
              for (ros_code_B.nx = 0; ros_code_B.nx < ros_code_B.nblocks;
                   ros_code_B.nx++) {
                d_data[ros_code_B.nx] =
                  (ros_code_B.real_roots_ddds_data[ros_code_B.nx] <
                   ros_code_B.kappa_x);
              }

              ros_code_B.nblocks = ros_code_B.tmp_size_n;
              for (ros_code_B.nx = 0; ros_code_B.nx < ros_code_B.nblocks;
                   ros_code_B.nx++) {
                e_data[ros_code_B.nx] =
                  (ros_code_B.real_roots_ddds_data[ros_code_B.nx] >
                   ros_code_B.dd_ls);
              }

              ros_code_B.nx = 0;
              while (ros_code_B.nx <= ros_code_B.loop_ub - 1) {
                if (d_data[ros_code_B.nx] || e_data[ros_code_B.nx]) {
                  ros_code_B.real_roots_ddds_data[ros_code_B.nx] =
                    ros_code_B.kappa_x;
                }

                ros_code_B.nx++;
              }

              ros_code_polyval_on(ros_code_B.ddls_coeffs,
                                  ros_code_B.real_roots_ddds_data,
                                  &ros_code_B.real_roots_ddds_size,
                                  ros_code_B.tmp_data_a, &ros_code_B.tmp_size_n);
              ros_code_abs(ros_code_B.tmp_data_a, &ros_code_B.tmp_size_n,
                           ros_code_B.tmp_data_bj, &ros_code_B.x_size_k);
              ros_code_B.la_0 = ros_code_maximum(ros_code_B.tmp_data_bj,
                &ros_code_B.x_size_k);
            }
          }

          if (ros_code_B.lastBlockLength != 1) {
            ros_code_B.sa_0++;
            for (ros_code_B.nx = 0; ros_code_B.nx < 13; ros_code_B.nx++) {
              ros_code_B.rest_path[(static_cast<int32_T>(ros_code_B.sa_0) + 3906
                                    * ros_code_B.nx) - 1] = ros_code_B.Tau_sl
                [3906 * ros_code_B.nx + ros_code_B.i];
            }

            ros_code_B.rest_path[static_cast<int32_T>(ros_code_B.sa_0) + 50777] =
              ros_code_B.min_range;
            ros_code_B.rest_path[static_cast<int32_T>(ros_code_B.sa_0) + 54683] =
              ros_code_B.la_0;
            ros_code_B.rest_path[static_cast<int32_T>(ros_code_B.sa_0) + 58589] =
              ros_code_B.lv_0;
          }
        }

        ros_code_B.i++;
      }

      ros_code_B.rest_path[3905] = ros_code_B.sa_0;
    }

    // MATLAB Function: '<S3>/costCalculate' incorporates:
    //   MATLAB Function: '<S3>/reducePath'
    //   MATLAB Function: '<S3>/sampleTrajectory'

    memset(&ros_code_B.local_path_F[0], 0, 54684U * sizeof(real_T));
    ros_code_B.local_path_F[3905] = ros_code_B.rest_path[3905];
    ros_code_B.i = 0;
    while (ros_code_B.i <= static_cast<int32_T>(ros_code_B.rest_path[3905]) - 1)
    {
      ros_code_B.d_ls = ros_code_B.rest_path[ros_code_B.i + 46872];
      ros_code_B.ds = ros_code_B.rest_path[ros_code_B.i + 19530];
      ros_code_B.B1[0] = ros_code_B.ds;
      ros_code_B.mean_angle = ros_code_B.rest_path[ros_code_B.i + 15624];
      ros_code_B.B1[1] = ros_code_B.mean_angle;
      ros_code_B.dd_s = ros_code_B.rest_path[ros_code_B.i + 11718];
      ros_code_B.B1[2] = ros_code_B.dd_s;
      ros_code_B.kappa_x = ros_code_B.rest_path[ros_code_B.i + 7812];
      ros_code_B.B1[3] = ros_code_B.kappa_x;
      ros_code_B.start_index = ros_code_B.rest_path[ros_code_B.i + 3906];
      ros_code_B.B1[4] = ros_code_B.start_index;
      ros_code_B.B1[5] = ros_code_B.rest_path[ros_code_B.i];
      ros_code_B.dd_ls = ros_code_B.ds;
      for (ros_code_B.nx = 0; ros_code_B.nx < 5; ros_code_B.nx++) {
        ros_code_B.dd_ls = ros_code_B.d_ls * ros_code_B.dd_ls +
          ros_code_B.B1[ros_code_B.nx + 1];
      }

      ros_code_B.ds = (((ros_code_B.ds * 5.0 * ros_code_B.d_ls +
                         ros_code_B.mean_angle * 4.0) * ros_code_B.d_ls +
                        ros_code_B.dd_s * 3.0) * ros_code_B.d_ls +
                       ros_code_B.kappa_x * 2.0) * ros_code_B.d_ls +
        ros_code_B.start_index;
      ros_code_B.B1[0] = ros_code_B.rest_path[ros_code_B.i + 42966];
      ros_code_B.B1[1] = ros_code_B.rest_path[ros_code_B.i + 39060];
      ros_code_B.B1[2] = ros_code_B.rest_path[ros_code_B.i + 35154];
      ros_code_B.B1[3] = ros_code_B.rest_path[ros_code_B.i + 31248];
      ros_code_B.B1[4] = ros_code_B.rest_path[ros_code_B.i + 27342];
      ros_code_B.B1[5] = ros_code_B.rest_path[ros_code_B.i + 23436];
      ros_code_B.sa3 = ros_code_B.B1[0];
      for (ros_code_B.c_cg = 0; ros_code_B.c_cg < 5; ros_code_B.c_cg++) {
        ros_code_B.sa3 = ros_code_B.dd_ls * ros_code_B.sa3 +
          ros_code_B.B1[ros_code_B.c_cg + 1];
      }

      for (ros_code_B.nx = 0; ros_code_B.nx < 6; ros_code_B.nx++) {
        ros_code_B.local_path_F[ros_code_B.i + 3906 * ros_code_B.nx] =
          ros_code_B.rest_path[3906 * ros_code_B.nx + ros_code_B.i];
        ros_code_B.local_path_F[ros_code_B.i + 3906 * (ros_code_B.nx + 6)] =
          ros_code_B.rest_path[(ros_code_B.nx + 6) * 3906 + ros_code_B.i];
      }

      ros_code_B.local_path_F[ros_code_B.i + 46872] = ros_code_B.d_ls;
      ros_code_B.local_path_F[ros_code_B.i + 50778] = ((((sqrt((1.0 -
        ros_code_B.ds) * (1.0 - ros_code_B.ds)) * 0.2 + (6.0 -
        ros_code_B.rest_path[ros_code_B.i + 58590]) * 2.0) +
        ros_code_B.rest_path[ros_code_B.i + 50778]) +
        ros_code_B.rest_path[ros_code_B.i + 54684]) + 1.5 * fabs(ros_code_B.sa3))
        + ros_code_B.d_ls * 0.1;
      ros_code_B.i++;
    }

    // End of MATLAB Function: '<S3>/costCalculate'

    // Update for Memory: '<S3>/Memory1' incorporates:
    //   MATLAB Function: '<S3>/pathConvert'

    memset(&ros_code_DW.Memory1_PreviousInput[0], 0, 15U * sizeof(real_T));

    // MATLAB Function: '<S3>/pathConvert' incorporates:
    //   MATLAB Function: '<S3>/currentStateConvert'
    //   MATLAB Function: '<S3>/sampleTrajectory'

    ros_code_B.lastBlockLength = 0;
    if ((ros_code_B.firstBlockLength != 0) && (ros_code_B.local_path_F[3905] >=
         1.0)) {
      ros_code_B.lastBlockLength = static_cast<int32_T>(ros_code_B.local_path_F
        [3905]);
      ros_code_B.sort_all_trajecotry_size[0] = static_cast<int32_T>
        (ros_code_B.local_path_F[3905]);
      ros_code_B.sort_all_trajecotry_size[1] = 14;
      for (ros_code_B.nx = 0; ros_code_B.nx < 14; ros_code_B.nx++) {
        for (ros_code_B.c_cg = 0; ros_code_B.c_cg < ros_code_B.lastBlockLength;
             ros_code_B.c_cg++) {
          ros_code_B.sort_all_trajecotry_data[ros_code_B.c_cg +
            ros_code_B.lastBlockLength * ros_code_B.nx] =
            ros_code_B.local_path_F[3906 * ros_code_B.nx + ros_code_B.c_cg];
        }
      }

      ros_code_sortrows(ros_code_B.sort_all_trajecotry_data,
                        ros_code_B.sort_all_trajecotry_size);
      ros_code_B.lastBlockLength = 1;
      ros_code_B.dd_s =
        ros_code_B.sort_all_trajecotry_data[ros_code_B.sort_all_trajecotry_size
        [0] * 12];
      ros_code_B.kappa_x = ros_code_B.eulZYX[2];
      ros_code_B.start_index = 0.0;
      ros_code_B.angle_diff = 0.0;
      ros_code_B.t[10] = 1.0;
      ros_code_B.t[0] = 0.0;
      for (ros_code_B.nx = 0; ros_code_B.nx < 9; ros_code_B.nx++) {
        ros_code_B.t[ros_code_B.nx + 1] = (static_cast<real_T>(ros_code_B.nx) +
          1.0) * 0.1;
      }

      if (ros_code_B.predict_accurate_index + -100.0 >= 1.0) {
        ros_code_B.min_range = ros_code_B.predict_accurate_index + -100.0;
      } else {
        ros_code_B.min_range = 1.0;
      }

      for (ros_code_B.scalarLB_tmp = 0; ros_code_B.scalarLB_tmp < 11;
           ros_code_B.scalarLB_tmp++) {
        if (ros_code_B.t[ros_code_B.scalarLB_tmp] >= ros_code_B.dd_s) {
          ros_code_B.t[ros_code_B.scalarLB_tmp] = ros_code_B.dd_s;
        }

        ros_code_B.d_ls =
          ros_code_B.sort_all_trajecotry_data[ros_code_B.sort_all_trajecotry_size
          [0] * 5];
        ros_code_B.B1[0] = ros_code_B.d_ls;
        ros_code_B.dd_ls =
          ros_code_B.sort_all_trajecotry_data[ros_code_B.sort_all_trajecotry_size
          [0] << 2];
        ros_code_B.B1[1] = ros_code_B.dd_ls;
        ros_code_B.a_m =
          ros_code_B.sort_all_trajecotry_data[ros_code_B.sort_all_trajecotry_size
          [0] * 3];
        ros_code_B.B1[2] = ros_code_B.a_m;
        ros_code_B.lv_0 =
          ros_code_B.sort_all_trajecotry_data[ros_code_B.sort_all_trajecotry_size
          [0] << 1];
        ros_code_B.B1[3] = ros_code_B.lv_0;
        ros_code_B.max_range =
          ros_code_B.sort_all_trajecotry_data[ros_code_B.sort_all_trajecotry_size
          [0]];
        ros_code_B.B1[4] = ros_code_B.max_range;
        ros_code_B.B1[5] = ros_code_B.sort_all_trajecotry_data[0];
        ros_code_B.s = ros_code_B.d_ls;
        for (ros_code_B.nx = 0; ros_code_B.nx < 5; ros_code_B.nx++) {
          ros_code_B.s = ros_code_B.t[ros_code_B.scalarLB_tmp] * ros_code_B.s +
            ros_code_B.B1[ros_code_B.nx + 1];
        }

        ros_code_B.mean_angle = (((5.0 * ros_code_B.d_ls *
          ros_code_B.t[ros_code_B.scalarLB_tmp] + 4.0 * ros_code_B.dd_ls) *
          ros_code_B.t[ros_code_B.scalarLB_tmp] + 3.0 * ros_code_B.a_m) *
          ros_code_B.t[ros_code_B.scalarLB_tmp] + 2.0 * ros_code_B.lv_0) *
          ros_code_B.t[ros_code_B.scalarLB_tmp] + ros_code_B.max_range;
        if (ros_code_B.s >= ros_code_B.global_path_num) {
          ros_code_B.s = ros_code_B.global_path_num;
          ros_code_B.mean_angle = 0.0;
        }

        if ((ros_code_B.predict_accurate_index + 400.0 <=
             ros_code_B.preprocess_global_path_array[1999]) || rtIsNaN
            (ros_code_B.preprocess_global_path_array[1999])) {
          ros_code_B.max_range = ros_code_B.predict_accurate_index + 400.0;
        } else {
          ros_code_B.max_range = ros_code_B.preprocess_global_path_array[1999];
        }

        if (ros_code_B.min_range > ros_code_B.max_range) {
          ros_code_B.c_cg = 0;
          ros_code_B.i = 0;
        } else {
          ros_code_B.c_cg = static_cast<int32_T>(ros_code_B.min_range) - 1;
          ros_code_B.i = static_cast<int32_T>(ros_code_B.max_range);
        }

        ros_code_B.nblocks = ros_code_B.i - ros_code_B.c_cg;
        ros_code_B.accurate_distance_size = ros_code_B.nblocks;
        ros_code_B.scalarLB = (ros_code_B.nblocks / 2) << 1;
        ros_code_B.vectorUB = ros_code_B.scalarLB - 2;
        for (ros_code_B.nx = 0; ros_code_B.nx <= ros_code_B.vectorUB;
             ros_code_B.nx += 2) {
          tmp_0 = _mm_loadu_pd(&ros_code_B.preprocess_global_path_array
                               [(ros_code_B.c_cg + ros_code_B.nx) + 8000]);
          _mm_storeu_pd(&ros_code_B.accurate_distance_data[ros_code_B.nx],
                        _mm_sub_pd(tmp_0, _mm_set1_pd(ros_code_B.s)));
        }

        for (ros_code_B.nx = ros_code_B.scalarLB; ros_code_B.nx <
             ros_code_B.nblocks; ros_code_B.nx++) {
          ros_code_B.accurate_distance_data[ros_code_B.nx] =
            ros_code_B.preprocess_global_path_array[(ros_code_B.c_cg +
            ros_code_B.nx) + 8000] - ros_code_B.s;
        }

        ros_code_B.b_y_size = ros_code_B.nblocks;
        ros_code_B.nblocks = 0;
        while (ros_code_B.nblocks <= ros_code_B.accurate_distance_size - 1) {
          ros_code_B.distances[ros_code_B.nblocks] =
            ros_code_B.accurate_distance_data[ros_code_B.nblocks] *
            ros_code_B.accurate_distance_data[ros_code_B.nblocks];
          ros_code_B.nblocks++;
        }

        ros_code_B.nblocks = ros_code_B.b_y_size;
        if (ros_code_B.nblocks - 1 >= 0) {
          memcpy(&ros_code_B.accurate_distance_data[0], &ros_code_B.distances[0],
                 ros_code_B.nblocks * sizeof(real_T));
        }

        ros_code_B.i = 0;
        while (ros_code_B.i <= ros_code_B.b_y_size - 1) {
          ros_code_B.accurate_distance_data[ros_code_B.i] = sqrt
            (ros_code_B.accurate_distance_data[ros_code_B.i]);
          ros_code_B.i++;
        }

        ros_code_B.nblocks = ros_code_B.b_y_size;
        if (ros_code_B.b_y_size <= 2) {
          if (ros_code_B.b_y_size == 1) {
            ros_code_B.nx = 1;
          } else {
            ros_code_B.object_num =
              ros_code_B.accurate_distance_data[ros_code_B.b_y_size - 1];
            if (ros_code_B.accurate_distance_data[0] > ros_code_B.object_num) {
              ros_code_B.nx = ros_code_B.b_y_size;
            } else if (rtIsNaN(ros_code_B.accurate_distance_data[0])) {
              if (!rtIsNaN(ros_code_B.object_num)) {
                ros_code_B.nx = ros_code_B.b_y_size;
              } else {
                ros_code_B.nx = 1;
              }
            } else {
              ros_code_B.nx = 1;
            }
          }
        } else {
          if (!rtIsNaN(ros_code_B.accurate_distance_data[0])) {
            ros_code_B.nx = 1;
          } else {
            ros_code_B.nx = 0;
            ros_code_B.i = 2;
            exitg1 = false;
            while ((!exitg1) && (ros_code_B.i <= ros_code_B.nblocks)) {
              if (!rtIsNaN(ros_code_B.accurate_distance_data[ros_code_B.i - 1]))
              {
                ros_code_B.nx = ros_code_B.i;
                exitg1 = true;
              } else {
                ros_code_B.i++;
              }
            }
          }

          if (ros_code_B.nx == 0) {
            ros_code_B.nx = 1;
          } else {
            ros_code_B.ex = ros_code_B.accurate_distance_data[ros_code_B.nx - 1];
            ros_code_B.i = ros_code_B.nx;
            while (ros_code_B.i + 1 <= ros_code_B.nblocks) {
              if (ros_code_B.ex > ros_code_B.accurate_distance_data[ros_code_B.i])
              {
                ros_code_B.ex = ros_code_B.accurate_distance_data[ros_code_B.i];
                ros_code_B.nx = ros_code_B.i + 1;
              }

              ros_code_B.i++;
            }
          }
        }

        ros_code_B.object_num = (ros_code_B.min_range + static_cast<real_T>
          (ros_code_B.nx)) - 1.0;
        switch (ros_code_B.scalarLB_tmp + 1) {
         case 1:
          ros_code_B.start_index = ros_code_B.object_num;
          break;

         case 11:
          ros_code_B.angle_diff = ros_code_B.object_num;
          break;
        }

        ros_code_B.d_ls =
          ros_code_B.sort_all_trajecotry_data[ros_code_B.sort_all_trajecotry_size
          [0] * 11];
        ros_code_B.B1[0] = ros_code_B.d_ls;
        ros_code_B.dd_ls =
          ros_code_B.sort_all_trajecotry_data[ros_code_B.sort_all_trajecotry_size
          [0] * 10];
        ros_code_B.B1[1] = ros_code_B.dd_ls;
        ros_code_B.a_m =
          ros_code_B.sort_all_trajecotry_data[ros_code_B.sort_all_trajecotry_size
          [0] * 9];
        ros_code_B.B1[2] = ros_code_B.a_m;
        ros_code_B.lv_0 =
          ros_code_B.sort_all_trajecotry_data[ros_code_B.sort_all_trajecotry_size
          [0] << 3];
        ros_code_B.B1[3] = ros_code_B.lv_0;
        ros_code_B.max_range =
          ros_code_B.sort_all_trajecotry_data[ros_code_B.sort_all_trajecotry_size
          [0] * 7];
        ros_code_B.B1[4] = ros_code_B.max_range;
        ros_code_B.B1[5] =
          ros_code_B.sort_all_trajecotry_data[ros_code_B.sort_all_trajecotry_size
          [0] * 6];
        ros_code_B.ds = ros_code_B.d_ls;
        for (ros_code_B.i = 0; ros_code_B.i < 5; ros_code_B.i++) {
          ros_code_B.ds = ros_code_B.s * ros_code_B.ds +
            ros_code_B.B1[ros_code_B.i + 1];
        }

        ros_code_B.d_ls = (((5.0 * ros_code_B.d_ls * ros_code_B.s + 4.0 *
                             ros_code_B.dd_ls) * ros_code_B.s + 3.0 *
                            ros_code_B.a_m) * ros_code_B.s + 2.0 *
                           ros_code_B.lv_0) * ros_code_B.s +
          ros_code_B.max_range;
        ros_code_B.lv_0 = ros_code_B.d_ls * ros_code_B.mean_angle;
        ros_code_B.max_range = rt_atan2d_snf(ros_code_B.d_ls, 1.0 -
          ros_code_B.preprocess_global_path_array[static_cast<int32_T>
          (ros_code_B.object_num) + 5999] * ros_code_B.ds) +
          ros_code_B.preprocess_global_path_array[static_cast<int32_T>
          (ros_code_B.object_num) + 3999];
        mask1 = (ros_code_B.max_range < -3.1415926535897931);
        mask2 = (ros_code_B.max_range > 3.1415926535897931);
        ros_code_B.i = 0;
        if (mask1 || mask2) {
          ros_code_B.i = 1;
        }

        if (ros_code_B.i - 1 >= 0) {
          ros_code_B.x_data_m = ros_code_B.max_range + 3.1415926535897931;
        }

        if (ros_code_B.i - 1 >= 0) {
          if (rtIsNaN(ros_code_B.max_range + 3.1415926535897931)) {
            ros_code_B.ex = (rtNaN);
          } else if (rtIsInf(ros_code_B.max_range + 3.1415926535897931)) {
            ros_code_B.ex = (rtNaN);
          } else if (ros_code_B.max_range + 3.1415926535897931 == 0.0) {
            ros_code_B.ex = 0.0;
          } else {
            ros_code_B.ex = fmod(ros_code_B.max_range + 3.1415926535897931,
                                 6.2831853071795862);
            rEQ0 = (ros_code_B.ex == 0.0);
            if (!rEQ0) {
              ros_code_B.dd_ls = fabs((ros_code_B.max_range + 3.1415926535897931)
                / 6.2831853071795862);
              rEQ0 = !(fabs(ros_code_B.dd_ls - floor(ros_code_B.dd_ls + 0.5)) >
                       2.2204460492503131E-16 * ros_code_B.dd_ls);
            }

            if (rEQ0) {
              ros_code_B.ex = 0.0;
            } else if (ros_code_B.max_range + 3.1415926535897931 < 0.0) {
              ros_code_B.ex += 6.2831853071795862;
            }
          }

          ros_code_B.x_data_m = ros_code_B.ex;
        }

        if (ros_code_B.i - 1 >= 0) {
          ros_code_B.nx = 0;
          positiveInput_data = ((ros_code_B.x_data_m == 0.0) &&
                                (ros_code_B.max_range + 3.1415926535897931 > 0.0));
        }

        if (ros_code_B.i - 1 >= 0) {
          ros_code_B.e = 0;
          if (positiveInput_data) {
            ros_code_B.x_data_m = 6.2831853071795862;
          }
        }

        if (mask1 || mask2) {
          ros_code_B.max_range = ros_code_B.x_data_m - 3.1415926535897931;
        }

        ros_code_B.a_m = 1.0 - ros_code_B.preprocess_global_path_array[
          static_cast<int32_T>(ros_code_B.object_num) + 5999] * ros_code_B.ds;
        ros_code_B.d_ls = (ros_code_B.max_range - ros_code_B.kappa_x) / 0.1;
        ros_code_B.kappa_x = ros_code_B.max_range;
        ros_code_B.s = ros_code_B.preprocess_global_path_array
          [static_cast<int32_T>(ros_code_B.object_num) + 3999];
        ros_code_B.predict_state[ros_code_B.scalarLB_tmp] =
          ros_code_B.preprocess_global_path_array[static_cast<int32_T>
          (ros_code_B.object_num) - 1] - sin(ros_code_B.s) * ros_code_B.ds;
        ros_code_B.predict_state[ros_code_B.scalarLB_tmp + 11] = cos
          (ros_code_B.s) * ros_code_B.ds +
          ros_code_B.preprocess_global_path_array[static_cast<int32_T>
          (ros_code_B.object_num) + 1999];
        ros_code_B.predict_state[ros_code_B.scalarLB_tmp + 22] =
          ros_code_B.max_range;
        ros_code_B.predict_state[ros_code_B.scalarLB_tmp + 33] = sqrt
          (ros_code_B.mean_angle * ros_code_B.mean_angle * (ros_code_B.a_m *
            ros_code_B.a_m) + ros_code_B.lv_0 * ros_code_B.lv_0);
        ros_code_B.predict_state[ros_code_B.scalarLB_tmp + 44] = ros_code_B.d_ls;
        ros_code_B.predict_state[ros_code_B.scalarLB_tmp + 55] =
          ros_code_B.t[ros_code_B.scalarLB_tmp];
      }

      // Update for Memory: '<S3>/Memory1' incorporates:
      //   MATLAB Function: '<S3>/currentStateConvert'
      //   MATLAB Function: '<S3>/sampleTrajectory'
      //   RateTransition: '<Root>/Rate Transition11'

      for (ros_code_B.nx = 0; ros_code_B.nx < 6; ros_code_B.nx++) {
        ros_code_DW.Memory1_PreviousInput[ros_code_B.nx] =
          ros_code_B.sort_all_trajecotry_data[ros_code_B.sort_all_trajecotry_size
          [0] * ros_code_B.nx];
        ros_code_DW.Memory1_PreviousInput[ros_code_B.nx + 6] =
          ros_code_B.sort_all_trajecotry_data[(ros_code_B.nx + 6) *
          ros_code_B.sort_all_trajecotry_size[0]];
      }

      ros_code_DW.Memory1_PreviousInput[12] = ros_code_B.aSinInput;
      ros_code_DW.Memory1_PreviousInput[13] = ros_code_B.start_index;
      ros_code_DW.Memory1_PreviousInput[14] = ros_code_B.angle_diff;
    } else {
      for (ros_code_B.i = 0; ros_code_B.i < 11; ros_code_B.i++) {
        ros_code_B.predict_state[ros_code_B.i] = ros_code_B.eulZYX[0];
        ros_code_B.predict_state[ros_code_B.i + 11] = ros_code_B.eulZYX[1];
        ros_code_B.predict_state[ros_code_B.i + 22] = ros_code_B.eulZYX[2];
        ros_code_B.predict_state[ros_code_B.i + 33] = 0.0;
        ros_code_B.predict_state[ros_code_B.i + 44] = 0.0;
        ros_code_B.predict_state[ros_code_B.i + 55] = 0.0;
      }
    }

    // Update for Memory: '<S3>/Memory'
    for (ros_code_B.i = 0; ros_code_B.i < 5; ros_code_B.i++) {
      ros_code_DW.Memory_PreviousInput[ros_code_B.i] =
        ros_code_B.current_state_C[ros_code_B.i];
    }

    // End of Update for Memory: '<S3>/Memory'
    // End of Outputs for SubSystem: '<Root>/Lattice_planner'

    // Outputs for Atomic SubSystem: '<Root>/MPC_controller'
    // MATLAB Function: '<S4>/MPC//buildConstraintMatrix' incorporates:
    //   MATLAB Function: '<S3>/currentStateConvert'
    //   MATLAB Function: '<S3>/pathConvert'

    memset(&ros_code_B.Aueq[0], 0, 1936U * sizeof(real_T));
    for (ros_code_B.i = 0; ros_code_B.i < 44; ros_code_B.i++) {
      ros_code_B.Bueq[ros_code_B.i] = 0.0;
      ros_code_B.lb[ros_code_B.i] = 0.0;
      ros_code_B.ub[ros_code_B.i] = 1.5;
    }

    // Outputs for Atomic SubSystem: '<Root>/Lattice_planner'
    if (ros_code_B.lastBlockLength != 0) {
      memset(&ros_code_B.A[0], 0, 484U * sizeof(int8_T));
      memset(&ros_code_B.U_max[0], 0, 22U * sizeof(real_T));
      memset(&ros_code_B.U_min[0], 0, 22U * sizeof(real_T));
      memset(&ros_code_B.U_k[0], 0, 22U * sizeof(real_T));
      ros_code_B.E_2[1] = 0;
      ros_code_B.E_2[2] = 0;
      ros_code_B.E_2[0] = 1;
      ros_code_B.E_2[3] = 1;
      memset(&ros_code_B.E_2N[0], 0, 484U * sizeof(int8_T));
      for (ros_code_B.c_cg = 0; ros_code_B.c_cg < 22; ros_code_B.c_cg++) {
        ros_code_B.E_2N[ros_code_B.c_cg + 22 * ros_code_B.c_cg] = 1;
      }

      for (ros_code_B.i = 0; ros_code_B.i < 11; ros_code_B.i++) {
        if (ros_code_B.i >= 0) {
          ros_code_B.b = ros_code_B.i << 1;
          ros_code_B.c_cg = (ros_code_B.i + 1) << 1;
          if (ros_code_B.b + 1 > ros_code_B.c_cg) {
            ros_code_B.b = 0;
            ros_code_B.c_cg = 0;
          }

          d[0] = static_cast<int8_T>(ros_code_B.c_cg - ros_code_B.b);
        }

        ros_code_B.scalarLB_tmp = 0;
        while (ros_code_B.scalarLB_tmp <= ros_code_B.i) {
          ros_code_B.firstBlockLength = ros_code_B.scalarLB_tmp << 1;
          ros_code_B.g = (ros_code_B.scalarLB_tmp + 1) << 1;
          if (ros_code_B.firstBlockLength + 1 > ros_code_B.g) {
            ros_code_B.firstBlockLength = 0;
            ros_code_B.g = 0;
          }

          d[1] = static_cast<int8_T>(ros_code_B.g - ros_code_B.firstBlockLength);
          ros_code_B.nblocks = d[1];
          for (ros_code_B.nx = 0; ros_code_B.nx < ros_code_B.nblocks;
               ros_code_B.nx++) {
            ros_code_B.loop_ub = d[0];
            for (ros_code_B.c_cg = 0; ros_code_B.c_cg < ros_code_B.loop_ub;
                 ros_code_B.c_cg++) {
              ros_code_B.A[(ros_code_B.b + ros_code_B.c_cg) + 22 *
                (ros_code_B.firstBlockLength + ros_code_B.nx)] =
                ros_code_B.E_2[d[0] * ros_code_B.nx + ros_code_B.c_cg];
            }
          }

          ros_code_B.scalarLB_tmp++;
        }

        ros_code_B.nx = ros_code_B.i << 1;
        if (ros_code_B.nx + 1 > ((ros_code_B.i + 1) << 1)) {
          ros_code_B.nx = 0;
        }

        ros_code_B.aSinInput = ros_code_B.predict_state[ros_code_B.i + 33];
        ros_code_B.U_max[ros_code_B.nx] = 1.5 - ros_code_B.aSinInput;
        ros_code_B.global_path_num = ros_code_B.predict_state[ros_code_B.i + 44];
        ros_code_B.U_max[ros_code_B.nx + 1] = 1.0 - ros_code_B.global_path_num;
        ros_code_B.firstBlockLength = ros_code_B.i << 1;
        ros_code_B.nx = ros_code_B.firstBlockLength;
        ros_code_B.e = (ros_code_B.i + 1) << 1;
        if (ros_code_B.firstBlockLength + 1 > ros_code_B.e) {
          ros_code_B.nx = 0;
        }

        ros_code_B.U_min[ros_code_B.nx] = -1.5 - ros_code_B.aSinInput;
        ros_code_B.U_min[ros_code_B.nx + 1] = -1.0 - ros_code_B.global_path_num;
        ros_code_B.nblocks = ros_code_B.firstBlockLength;
        ros_code_B.nx = ros_code_B.e;
        if (ros_code_B.firstBlockLength + 1 > ros_code_B.e) {
          ros_code_B.nblocks = 0;
          ros_code_B.nx = 0;
        }

        ros_code_B.c_cg = ros_code_B.nx - ros_code_B.nblocks;
        for (ros_code_B.nx = 0; ros_code_B.nx < ros_code_B.c_cg; ros_code_B.nx++)
        {
          ros_code_B.lb[ros_code_B.nblocks + ros_code_B.nx] = 0.05 *
            static_cast<real_T>(ros_code_B.nx) + -0.1;
        }

        ros_code_B.nblocks = ros_code_B.firstBlockLength;
        ros_code_B.nx = ros_code_B.e;
        if (ros_code_B.firstBlockLength + 1 > ros_code_B.e) {
          ros_code_B.nblocks = 0;
          ros_code_B.nx = 0;
        }

        ros_code_B.c_cg = ros_code_B.nx - ros_code_B.nblocks;
        for (ros_code_B.nx = 0; ros_code_B.nx < ros_code_B.c_cg; ros_code_B.nx++)
        {
          ros_code_B.ub[ros_code_B.nblocks + ros_code_B.nx] = -0.05 *
            static_cast<real_T>(ros_code_B.nx) + 0.1;
        }

        ros_code_B.nx = ros_code_B.i << 1;
        if (ros_code_B.nx + 1 > ((ros_code_B.i + 1) << 1)) {
          ros_code_B.nx = 0;
        }

        ros_code_B.U_k[ros_code_B.nx] = ros_code_B.current_state_C[3] -
          ros_code_B.predict_state[33];
        ros_code_B.U_k[ros_code_B.nx + 1] = ros_code_B.current_state_C[4] -
          ros_code_B.predict_state[44];
      }

      for (ros_code_B.i = 0; ros_code_B.i < 22; ros_code_B.i++) {
        for (ros_code_B.nx = 0; ros_code_B.nx < 22; ros_code_B.nx++) {
          int8_T A;
          ros_code_B.b = 22 * ros_code_B.i + ros_code_B.nx;
          g_data = ros_code_B.E_2N[ros_code_B.b];
          A = ros_code_B.A[ros_code_B.b];
          ros_code_B.b = 44 * ros_code_B.i + ros_code_B.nx;
          ros_code_B.Aueq[ros_code_B.b] = A;
          ros_code_B.nblocks = (ros_code_B.i + 22) * 44 + ros_code_B.nx;
          ros_code_B.Aueq[ros_code_B.nblocks] = -static_cast<real_T>(g_data);
          ros_code_B.Aueq[ros_code_B.b + 22] = -static_cast<real_T>(A);
          ros_code_B.Aueq[ros_code_B.nblocks + 22] = g_data;
        }

        ros_code_B.Bueq[ros_code_B.i] = ros_code_B.U_max[ros_code_B.i] -
          ros_code_B.U_k[ros_code_B.i];
        ros_code_B.Bueq[ros_code_B.i + 22] = -ros_code_B.U_min[ros_code_B.i] +
          ros_code_B.U_k[ros_code_B.i];
      }
    }

    // End of MATLAB Function: '<S4>/MPC//buildConstraintMatrix'
    // End of Outputs for SubSystem: '<Root>/Lattice_planner'

    // MATLAB Function: '<S4>/MPC//buildPredictionModel' incorporates:
    //   MATLAB Function: '<S3>/currentStateConvert'
    //   MATLAB Function: '<S3>/pathConvert'

    memset(&ros_code_B.G[0], 0, 33U * sizeof(real_T));
    memset(&ros_code_B.Z[0], 0, 726U * sizeof(real_T));
    ros_code_B.aSinInput = 0.0;
    ros_code_B.global_path_num = 0.0;
    ros_code_B.predict_accurate_index = 0.0;
    ros_code_B.dd_s = 0.0;

    // Outputs for Atomic SubSystem: '<Root>/Lattice_planner'
    if (ros_code_B.lastBlockLength != 0) {
      memset(&ros_code_B.a[0], 0, 165U * sizeof(real_T));
      memset(&ros_code_B.A_21[0], 0, 25U * sizeof(real_T));
      ros_code_eye(ros_code_B.A_all);
      memset(&ros_code_B.B_all[0], 0, 1210U * sizeof(real_T));
      ros_code_B.global_path_num = ros_code_B.current_state_C[3] -
        ros_code_B.predict_state[33];
      ros_code_B.dd_s = ros_code_B.current_state_C[4] -
        ros_code_B.predict_state[44];
      ros_code_B.aSinInput = ros_code_B.predict_state[33];
      ros_code_B.predict_accurate_index = ros_code_B.predict_state[44];
      ros_code_B.B1[3] = 0.0;
      ros_code_B.B1[4] = 0.0;
      ros_code_B.B1[2] = 0.0;
      ros_code_B.B1[5] = 0.1;
      for (ros_code_B.nx = 0; ros_code_B.nx < 15; ros_code_B.nx++) {
        ros_code_B.iv[ros_code_B.nx] = b_a[ros_code_B.nx];
      }

      for (ros_code_B.i = 0; ros_code_B.i < 11; ros_code_B.i++) {
        ros_code_B.mean_angle = ros_code_B.predict_state[ros_code_B.i + 22];
        ros_code_B.ds = sin(ros_code_B.mean_angle);
        ros_code_B.mean_angle = cos(ros_code_B.mean_angle);
        ros_code_B.B1[0] = 0.1 * ros_code_B.mean_angle;
        ros_code_B.B1[1] = 0.1 * ros_code_B.ds;
        ros_code_B.A2[0] = 1.0;
        ros_code_B.A2[5] = 0.0;
        ros_code_B.d_ls = ros_code_B.predict_state[ros_code_B.i + 33];
        ros_code_B.A2[10] = ros_code_B.d_ls * -0.1 * ros_code_B.ds;
        ros_code_B.A2[1] = 0.0;
        ros_code_B.A2[6] = 1.0;
        ros_code_B.A2[11] = ros_code_B.d_ls * 0.1 * ros_code_B.mean_angle;
        ros_code_B.A2[2] = 0.0;
        ros_code_B.A2[7] = 0.0;
        ros_code_B.A2[12] = 1.0;
        for (ros_code_B.nx = 0; ros_code_B.nx < 2; ros_code_B.nx++) {
          ros_code_B.b = (ros_code_B.nx + 3) * 5;
          ros_code_B.A2[ros_code_B.b] = ros_code_B.B1[3 * ros_code_B.nx];
          ros_code_B.A2[ros_code_B.b + 1] = ros_code_B.B1[3 * ros_code_B.nx + 1];
          ros_code_B.A2[ros_code_B.b + 2] = ros_code_B.B1[3 * ros_code_B.nx + 2];
        }

        for (ros_code_B.nx = 0; ros_code_B.nx < 5; ros_code_B.nx++) {
          ros_code_B.b = ros_code_B.nx << 1;
          ros_code_B.A2[5 * ros_code_B.nx + 3] = ed[ros_code_B.b];
          ros_code_B.A2[5 * ros_code_B.nx + 4] = ed[ros_code_B.b + 1];
        }

        for (ros_code_B.nx = 0; ros_code_B.nx < 2; ros_code_B.nx++) {
          ros_code_B.B2[5 * ros_code_B.nx] = ros_code_B.B1[3 * ros_code_B.nx];
          ros_code_B.B2[5 * ros_code_B.nx + 1] = ros_code_B.B1[3 * ros_code_B.nx
            + 1];
          ros_code_B.B2[5 * ros_code_B.nx + 2] = ros_code_B.B1[3 * ros_code_B.nx
            + 2];
          ros_code_B.b = ros_code_B.nx << 1;
          ros_code_B.B2[5 * ros_code_B.nx + 3] = t[ros_code_B.b];
          ros_code_B.B2[5 * ros_code_B.nx + 4] = t[ros_code_B.b + 1];
        }

        ros_code_B.b = ros_code_B.i * 3;
        ros_code_B.firstBlockLength = (ros_code_B.i + 1) * 3;
        if (ros_code_B.b + 1 > ros_code_B.firstBlockLength) {
          ros_code_B.scalarLB_tmp = 0;
          ros_code_B.loop_ub = 0;
        } else {
          ros_code_B.scalarLB_tmp = ros_code_B.b;
          ros_code_B.loop_ub = ros_code_B.firstBlockLength;
        }

        ros_code_B.scalarLB = ros_code_B.i << 1;
        ros_code_B.vectorUB = (ros_code_B.i + 1) << 1;
        if (ros_code_B.scalarLB + 1 > ros_code_B.vectorUB) {
          ros_code_B.g = 0;
          ros_code_B.e = 0;
        } else {
          ros_code_B.g = ros_code_B.scalarLB;
          ros_code_B.e = ros_code_B.vectorUB;
        }

        for (ros_code_B.nx = 0; ros_code_B.nx < 3; ros_code_B.nx++) {
          for (ros_code_B.c_cg = 0; ros_code_B.c_cg < 2; ros_code_B.c_cg++) {
            ros_code_B.nblocks = 3 * ros_code_B.c_cg + ros_code_B.nx;
            ros_code_B.sa5[ros_code_B.nblocks] = 0.0;
            for (ros_code_B.r_f = 0; ros_code_B.r_f < 5; ros_code_B.r_f++) {
              ros_code_B.sa5[ros_code_B.nblocks] += static_cast<real_T>
                (ros_code_B.iv[3 * ros_code_B.r_f + ros_code_B.nx]) *
                ros_code_B.B2[5 * ros_code_B.c_cg + ros_code_B.r_f];
            }
          }
        }

        d[0] = static_cast<int8_T>(ros_code_B.loop_ub - ros_code_B.scalarLB_tmp);
        d[1] = static_cast<int8_T>(ros_code_B.e - ros_code_B.g);
        ros_code_B.nblocks = d[1];
        for (ros_code_B.nx = 0; ros_code_B.nx < ros_code_B.nblocks;
             ros_code_B.nx++) {
          ros_code_B.loop_ub = d[0];
          for (ros_code_B.c_cg = 0; ros_code_B.c_cg < ros_code_B.loop_ub;
               ros_code_B.c_cg++) {
            ros_code_B.Z[(ros_code_B.scalarLB_tmp + ros_code_B.c_cg) + 33 *
              (ros_code_B.g + ros_code_B.nx)] = ros_code_B.sa5[d[0] *
              ros_code_B.nx + ros_code_B.c_cg];
          }
        }

        if (ros_code_B.i + 1 == 1) {
          memcpy(&ros_code_B.A_21[0], &ros_code_B.A2[0], 25U * sizeof(real_T));
          for (ros_code_B.nx = 0; ros_code_B.nx < 3; ros_code_B.nx++) {
            for (ros_code_B.c_cg = 0; ros_code_B.c_cg < 5; ros_code_B.c_cg++) {
              ros_code_B.b = 33 * ros_code_B.c_cg + ros_code_B.nx;
              ros_code_B.a[ros_code_B.b] = 0.0;
              for (ros_code_B.nblocks = 0; ros_code_B.nblocks < 5;
                   ros_code_B.nblocks++) {
                ros_code_B.a[ros_code_B.b] += static_cast<real_T>(ros_code_B.iv
                  [3 * ros_code_B.nblocks + ros_code_B.nx]) * ros_code_B.A2[5 *
                  ros_code_B.c_cg + ros_code_B.nblocks];
              }
            }
          }

          for (ros_code_B.nx = 0; ros_code_B.nx < 2; ros_code_B.nx++) {
            for (ros_code_B.c_cg = 0; ros_code_B.c_cg < 5; ros_code_B.c_cg++) {
              ros_code_B.B_all[ros_code_B.c_cg + 55 * ros_code_B.nx] =
                ros_code_B.B2[5 * ros_code_B.nx + ros_code_B.c_cg];
            }
          }
        } else {
          ros_code_B.scalarLB_tmp = 5 * ros_code_B.i;
          ros_code_B.g = (ros_code_B.i + 1) * 5;
          if (ros_code_B.scalarLB_tmp + 1 > ros_code_B.g) {
            ros_code_B.e = 0;
            ros_code_B.c_cg = 0;
          } else {
            ros_code_B.e = ros_code_B.scalarLB_tmp;
            ros_code_B.c_cg = ros_code_B.g;
          }

          if (ros_code_B.scalarLB + 1 > ros_code_B.vectorUB) {
            ros_code_B.scalarLB = 0;
            ros_code_B.vectorUB = 0;
          }

          d[0] = static_cast<int8_T>(ros_code_B.c_cg - ros_code_B.e);
          d[1] = static_cast<int8_T>(ros_code_B.vectorUB - ros_code_B.scalarLB);
          ros_code_B.nblocks = d[1];
          for (ros_code_B.nx = 0; ros_code_B.nx < ros_code_B.nblocks;
               ros_code_B.nx++) {
            ros_code_B.loop_ub = d[0];
            for (ros_code_B.c_cg = 0; ros_code_B.c_cg < ros_code_B.loop_ub;
                 ros_code_B.c_cg++) {
              ros_code_B.B_all[(ros_code_B.e + ros_code_B.c_cg) + 55 *
                (ros_code_B.scalarLB + ros_code_B.nx)] = ros_code_B.B2[d[0] *
                ros_code_B.nx + ros_code_B.c_cg];
            }
          }

          if (ros_code_B.scalarLB_tmp + 1 > ros_code_B.g) {
            ros_code_B.e = 0;
            ros_code_B.nx = 0;
          } else {
            ros_code_B.e = ros_code_B.scalarLB_tmp;
            ros_code_B.nx = ros_code_B.g;
          }

          ros_code_B.loop_ub = (ros_code_B.i - 1) * 5;
          if (ros_code_B.loop_ub + 1 > ros_code_B.scalarLB_tmp) {
            ros_code_B.r_f = 0;
            ros_code_B.c_cg = 0;
          } else {
            ros_code_B.r_f = ros_code_B.loop_ub;
            ros_code_B.c_cg = ros_code_B.scalarLB_tmp;
          }

          if (ros_code_B.scalarLB_tmp + 1 > ros_code_B.g) {
            ros_code_B.v_p = 0;
          } else {
            ros_code_B.v_p = ros_code_B.scalarLB_tmp;
          }

          ros_code_B.nblocks = ros_code_B.nx - ros_code_B.e;
          if (ros_code_B.c_cg - ros_code_B.r_f == ros_code_B.nblocks) {
            for (ros_code_B.nx = 0; ros_code_B.nx < 22; ros_code_B.nx++) {
              ros_code_B.scalarLB = (ros_code_B.nblocks / 2) << 1;
              ros_code_B.vectorUB = ros_code_B.scalarLB - 2;
              for (ros_code_B.c_cg = 0; ros_code_B.c_cg <= ros_code_B.vectorUB;
                   ros_code_B.c_cg += 2) {
                tmp_0 = _mm_loadu_pd(&ros_code_B.B_all[(ros_code_B.e +
                  ros_code_B.c_cg) + 55 * ros_code_B.nx]);
                tmp = _mm_loadu_pd(&ros_code_B.B_all[(ros_code_B.r_f +
                  ros_code_B.c_cg) + 55 * ros_code_B.nx]);
                _mm_storeu_pd(&ros_code_B.B_all_data[ros_code_B.c_cg +
                              ros_code_B.nblocks * ros_code_B.nx], _mm_add_pd
                              (tmp_0, tmp));
              }

              for (ros_code_B.c_cg = ros_code_B.scalarLB; ros_code_B.c_cg <
                   ros_code_B.nblocks; ros_code_B.c_cg++) {
                ros_code_B.B_all_data[ros_code_B.c_cg + ros_code_B.nblocks *
                  ros_code_B.nx] = ros_code_B.B_all[(ros_code_B.e +
                  ros_code_B.c_cg) + 55 * ros_code_B.nx] + ros_code_B.B_all
                  [(ros_code_B.r_f + ros_code_B.c_cg) + 55 * ros_code_B.nx];
              }
            }

            for (ros_code_B.nx = 0; ros_code_B.nx < 22; ros_code_B.nx++) {
              for (ros_code_B.c_cg = 0; ros_code_B.c_cg < ros_code_B.nblocks;
                   ros_code_B.c_cg++) {
                ros_code_B.B_all[(ros_code_B.v_p + ros_code_B.c_cg) + 55 *
                  ros_code_B.nx] = ros_code_B.B_all_data[ros_code_B.nblocks *
                  ros_code_B.nx + ros_code_B.c_cg];
              }
            }
          } else {
            ros_code_binary_expand_op_pij(ros_code_B.B_all, ros_code_B.v_p,
              ros_code_B.e, ros_code_B.nx - 1, ros_code_B.r_f, ros_code_B.c_cg -
              1);
          }

          if (ros_code_B.i - 1 >= 0) {
            if (ros_code_B.loop_ub + 1 > ros_code_B.scalarLB_tmp) {
              ros_code_B.ab_n = 0;
              ros_code_B.y_p = 0;
            } else {
              ros_code_B.ab_n = ros_code_B.loop_ub;
              ros_code_B.y_p = ros_code_B.scalarLB_tmp;
            }

            if (ros_code_B.scalarLB_tmp + 1 > ros_code_B.g) {
              ros_code_B.ib = 0;
              ros_code_B.qb = 0;
              ros_code_B.pb = 0;
              ros_code_B.yb = 0;
              ros_code_B.xb = 0;
            } else {
              ros_code_B.ib = ros_code_B.scalarLB_tmp;
              ros_code_B.qb = ros_code_B.scalarLB_tmp;
              ros_code_B.pb = ros_code_B.g;
              ros_code_B.yb = ros_code_B.scalarLB_tmp;
              ros_code_B.xb = ros_code_B.g;
            }

            if (ros_code_B.b + 1 > ros_code_B.firstBlockLength) {
              ros_code_B.xc = 0;
            } else {
              ros_code_B.xc = ros_code_B.b;
            }
          }

          ros_code_B.scalarLB = 0;
          while (ros_code_B.scalarLB <= ros_code_B.i - 1) {
            ros_code_B.vectorUB = ros_code_B.scalarLB * 5;
            ros_code_B.e = (ros_code_B.scalarLB + 1) * 5;
            if (ros_code_B.vectorUB + 1 > ros_code_B.e) {
              ros_code_B.r_f = 0;
              ros_code_B.nx = 0;
              ros_code_B.v_p = 0;
            } else {
              ros_code_B.r_f = ros_code_B.vectorUB;
              ros_code_B.nx = ros_code_B.e;
              ros_code_B.v_p = ros_code_B.vectorUB;
            }

            ros_code_B.nblocks = ros_code_B.y_p - ros_code_B.ab_n;
            ros_code_B.A_all_size[0] = ros_code_B.nblocks;
            ros_code_B.loop_ub = ros_code_B.nx - ros_code_B.r_f;
            ros_code_B.A_all_size[1] = ros_code_B.loop_ub;
            for (ros_code_B.nx = 0; ros_code_B.nx < ros_code_B.loop_ub;
                 ros_code_B.nx++) {
              for (ros_code_B.c_cg = 0; ros_code_B.c_cg < ros_code_B.nblocks;
                   ros_code_B.c_cg++) {
                ros_code_B.A_all_data_c[ros_code_B.c_cg + ros_code_B.nblocks *
                  ros_code_B.nx] = ros_code_B.A_all[((ros_code_B.r_f +
                  ros_code_B.nx) * 55 + ros_code_B.ab_n) + ros_code_B.c_cg];
              }
            }

            ros_code_mtimes(ros_code_B.A2, ros_code_B.A_all_data_c,
                            ros_code_B.A_all_size, ros_code_B.tmp_data_m,
                            ros_code_B.tmp_size);
            ros_code_B.nblocks = ros_code_B.tmp_size[1];
            for (ros_code_B.nx = 0; ros_code_B.nx < ros_code_B.nblocks;
                 ros_code_B.nx++) {
              for (ros_code_B.c_cg = 0; ros_code_B.c_cg < 5; ros_code_B.c_cg++)
              {
                ros_code_B.A_all[(ros_code_B.ib + ros_code_B.c_cg) + 55 *
                  (ros_code_B.v_p + ros_code_B.nx)] = ros_code_B.tmp_data_m[5 *
                  ros_code_B.nx + ros_code_B.c_cg];
              }
            }

            if (ros_code_B.vectorUB + 1 > ros_code_B.e) {
              ros_code_B.vectorUB = 0;
              ros_code_B.e = 0;
            }

            ros_code_B.r_f = ros_code_B.scalarLB << 1;
            ros_code_B.nx = (ros_code_B.scalarLB + 1) << 1;
            if (ros_code_B.r_f + 1 > ros_code_B.nx) {
              ros_code_B.v_p = 0;
              ros_code_B.cc = 0;
              ros_code_B.r_f = 0;
            } else {
              ros_code_B.v_p = ros_code_B.r_f;
              ros_code_B.cc = ros_code_B.nx;
            }

            ros_code_B.nblocks = ros_code_B.pb - ros_code_B.qb;
            ros_code_B.A_all_size_n[0] = ros_code_B.nblocks;
            ros_code_B.loop_ub = ros_code_B.e - ros_code_B.vectorUB;
            ros_code_B.A_all_size_n[1] = ros_code_B.loop_ub;
            for (ros_code_B.nx = 0; ros_code_B.nx < ros_code_B.loop_ub;
                 ros_code_B.nx++) {
              for (ros_code_B.c_cg = 0; ros_code_B.c_cg < ros_code_B.nblocks;
                   ros_code_B.c_cg++) {
                ros_code_B.A_all_data[ros_code_B.c_cg + ros_code_B.nblocks *
                  ros_code_B.nx] = ros_code_B.A_all[((ros_code_B.vectorUB +
                  ros_code_B.nx) * 55 + ros_code_B.qb) + ros_code_B.c_cg];
              }
            }

            ros_code_B.nblocks = ros_code_B.xb - ros_code_B.yb;
            ros_code_B.B_all_size[0] = ros_code_B.nblocks;
            ros_code_B.loop_ub = ros_code_B.cc - ros_code_B.v_p;
            ros_code_B.B_all_size[1] = ros_code_B.loop_ub;
            for (ros_code_B.nx = 0; ros_code_B.nx < ros_code_B.loop_ub;
                 ros_code_B.nx++) {
              for (ros_code_B.c_cg = 0; ros_code_B.c_cg < ros_code_B.nblocks;
                   ros_code_B.c_cg++) {
                ros_code_B.B_all_data_g[ros_code_B.c_cg + ros_code_B.nblocks *
                  ros_code_B.nx] = ros_code_B.B_all[((ros_code_B.v_p +
                  ros_code_B.nx) * 55 + ros_code_B.yb) + ros_code_B.c_cg];
              }
            }

            ros_code_mtimes_d(ros_code_B.A_all_data, ros_code_B.A_all_size_n,
                              ros_code_B.tmp_data_n, ros_code_B.tmp_size);
            ros_code_mtimes_du(ros_code_B.tmp_data_n, ros_code_B.tmp_size,
                               ros_code_B.B_all_data_g, ros_code_B.B_all_size,
                               ros_code_B.global_path_array,
                               ros_code_B.tmp_size_o);
            ros_code_B.nblocks = ros_code_B.tmp_size_o[1];
            for (ros_code_B.nx = 0; ros_code_B.nx < ros_code_B.nblocks;
                 ros_code_B.nx++) {
              ros_code_B.c_cg = (ros_code_B.r_f + ros_code_B.nx) * 33 +
                ros_code_B.xc;
              ros_code_B.Z[ros_code_B.c_cg] = ros_code_B.global_path_array[3 *
                ros_code_B.nx];
              ros_code_B.Z[ros_code_B.c_cg + 1] = ros_code_B.global_path_array[3
                * ros_code_B.nx + 1];
              ros_code_B.Z[ros_code_B.c_cg + 2] = ros_code_B.global_path_array[3
                * ros_code_B.nx + 2];
            }

            ros_code_B.scalarLB++;
          }

          if (ros_code_B.scalarLB_tmp + 1 > ros_code_B.g) {
            ros_code_B.scalarLB_tmp = 0;
            ros_code_B.g = 0;
          }

          if (ros_code_B.b + 1 > ros_code_B.firstBlockLength) {
            ros_code_B.b = 0;
            ros_code_B.firstBlockLength = 0;
          }

          ros_code_B.nblocks = ros_code_B.g - ros_code_B.scalarLB_tmp;
          for (ros_code_B.nx = 0; ros_code_B.nx < 5; ros_code_B.nx++) {
            for (ros_code_B.c_cg = 0; ros_code_B.c_cg < ros_code_B.nblocks;
                 ros_code_B.c_cg++) {
              ros_code_B.A_all_data_g[ros_code_B.c_cg + ros_code_B.nblocks *
                ros_code_B.nx] = ros_code_B.A_all[(ros_code_B.scalarLB_tmp +
                ros_code_B.c_cg) + 55 * ros_code_B.nx];
            }
          }

          for (ros_code_B.nx = 0; ros_code_B.nx < 3; ros_code_B.nx++) {
            for (ros_code_B.c_cg = 0; ros_code_B.c_cg < 5; ros_code_B.c_cg++) {
              ros_code_B.nblocks = 3 * ros_code_B.c_cg + ros_code_B.nx;
              ros_code_B.dv4[ros_code_B.nblocks] = 0.0;
              for (ros_code_B.r_f = 0; ros_code_B.r_f < 5; ros_code_B.r_f++) {
                ros_code_B.dv4[ros_code_B.nblocks] += static_cast<real_T>
                  (ros_code_B.iv[3 * ros_code_B.r_f + ros_code_B.nx]) *
                  ros_code_B.A_all_data_g[5 * ros_code_B.c_cg + ros_code_B.r_f];
              }
            }

            for (ros_code_B.c_cg = 0; ros_code_B.c_cg < 5; ros_code_B.c_cg++) {
              ros_code_B.nblocks = 3 * ros_code_B.c_cg + ros_code_B.nx;
              ros_code_B.dv5[ros_code_B.nblocks] = 0.0;
              for (ros_code_B.r_f = 0; ros_code_B.r_f < 5; ros_code_B.r_f++) {
                ros_code_B.dv5[ros_code_B.nblocks] += ros_code_B.dv4[3 *
                  ros_code_B.r_f + ros_code_B.nx] * ros_code_B.A_21[5 *
                  ros_code_B.c_cg + ros_code_B.r_f];
              }
            }
          }

          d[0] = static_cast<int8_T>(ros_code_B.firstBlockLength - ros_code_B.b);
          d[1] = 5;
          ros_code_B.nblocks = d[0];
          for (ros_code_B.nx = 0; ros_code_B.nx < 5; ros_code_B.nx++) {
            for (ros_code_B.c_cg = 0; ros_code_B.c_cg < ros_code_B.nblocks;
                 ros_code_B.c_cg++) {
              ros_code_B.a[(ros_code_B.b + ros_code_B.c_cg) + 33 * ros_code_B.nx]
                = ros_code_B.dv5[d[0] * ros_code_B.nx + ros_code_B.c_cg];
            }
          }
        }
      }

      ros_code_B.last_path_data[0] = ros_code_B.current_state_C[0] -
        ros_code_B.predict_state[0];
      ros_code_B.last_path_data[1] = ros_code_B.current_state_C[1] -
        ros_code_B.predict_state[11];
      ros_code_B.ds = ros_code_B.current_state_C[2] - ros_code_B.predict_state
        [22];
      ros_code_B.last_path_data[2] = rt_atan2d_snf(sin(ros_code_B.ds), cos
        (ros_code_B.ds));
      ros_code_B.last_path_data[3] = ros_code_B.global_path_num;
      ros_code_B.last_path_data[4] = ros_code_B.dd_s;
      for (ros_code_B.nx = 0; ros_code_B.nx < 33; ros_code_B.nx++) {
        ros_code_B.a_l[ros_code_B.nx] = 0.0;
        for (ros_code_B.c_cg = 0; ros_code_B.c_cg < 5; ros_code_B.c_cg++) {
          ros_code_B.a_l[ros_code_B.nx] += ros_code_B.a[33 * ros_code_B.c_cg +
            ros_code_B.nx] * ros_code_B.last_path_data[ros_code_B.c_cg];
        }

        ros_code_B.G[ros_code_B.nx] = ros_code_B.a_l[ros_code_B.nx];
      }
    }

    // End of MATLAB Function: '<S4>/MPC//buildPredictionModel'
    // End of Outputs for SubSystem: '<Root>/Lattice_planner'

    // MATLAB Function: '<S4>/MPC//solveQuadraticProgramming' incorporates:
    //   MATLAB Function: '<S3>/pathConvert'

    ros_code_B.ds = 0.0;
    ros_code_B.d_ls = 0.0;

    // Outputs for Atomic SubSystem: '<Root>/Lattice_planner'
    if (ros_code_B.lastBlockLength != 0) {
      memset(&ros_code_B.Q[0], 0, 1089U * sizeof(real_T));
      memset(&ros_code_B.A[0], 0, 484U * sizeof(int8_T));
      for (ros_code_B.i = 0; ros_code_B.i < 10; ros_code_B.i++) {
        ros_code_B.scalarLB_tmp = ros_code_B.i * 3;
        ros_code_B.g = (ros_code_B.i + 1) * 3;
        if (ros_code_B.scalarLB_tmp + 1 > ros_code_B.g) {
          ros_code_B.e = 0;
          ros_code_B.c_cg = 0;
          ros_code_B.scalarLB_tmp = 0;
          ros_code_B.g = 0;
        } else {
          ros_code_B.e = ros_code_B.scalarLB_tmp;
          ros_code_B.c_cg = ros_code_B.g;
        }

        d[0] = static_cast<int8_T>(ros_code_B.c_cg - ros_code_B.e);
        d[1] = static_cast<int8_T>(ros_code_B.g - ros_code_B.scalarLB_tmp);
        ros_code_B.nblocks = d[1];
        for (ros_code_B.nx = 0; ros_code_B.nx < ros_code_B.nblocks;
             ros_code_B.nx++) {
          ros_code_B.loop_ub = d[0];
          for (ros_code_B.c_cg = 0; ros_code_B.c_cg < ros_code_B.loop_ub;
               ros_code_B.c_cg++) {
            ros_code_B.Q[(ros_code_B.e + ros_code_B.c_cg) + 33 *
              (ros_code_B.scalarLB_tmp + ros_code_B.nx)] = y[d[0] *
              ros_code_B.nx + ros_code_B.c_cg];
          }
        }

        ros_code_B.ab_n = ros_code_B.i << 1;
        ros_code_B.y_p = (ros_code_B.i + 1) << 1;
        if (ros_code_B.ab_n + 1 > ros_code_B.y_p) {
          ros_code_B.e = 0;
          ros_code_B.nx = 0;
          ros_code_B.ab_n = 0;
          ros_code_B.y_p = 0;
        } else {
          ros_code_B.e = ros_code_B.ab_n;
          ros_code_B.nx = ros_code_B.y_p;
        }

        d[0] = static_cast<int8_T>(ros_code_B.nx - ros_code_B.e);
        d[1] = static_cast<int8_T>(ros_code_B.y_p - ros_code_B.ab_n);
        ros_code_B.nblocks = d[1];
        for (ros_code_B.nx = 0; ros_code_B.nx < ros_code_B.nblocks;
             ros_code_B.nx++) {
          ros_code_B.loop_ub = d[0];
          for (ros_code_B.c_cg = 0; ros_code_B.c_cg < ros_code_B.loop_ub;
               ros_code_B.c_cg++) {
            ros_code_B.A[(ros_code_B.e + ros_code_B.c_cg) + 22 *
              (ros_code_B.ab_n + ros_code_B.nx)] = t[d[0] * ros_code_B.nx +
              ros_code_B.c_cg];
          }
        }
      }

      for (ros_code_B.nx = 0; ros_code_B.nx < 3; ros_code_B.nx++) {
        ros_code_B.ab_n = (ros_code_B.nx + 30) * 33;
        ros_code_B.Q[ros_code_B.ab_n + 30] = s[3 * ros_code_B.nx];
        ros_code_B.Q[ros_code_B.ab_n + 31] = s[3 * ros_code_B.nx + 1];
        ros_code_B.Q[ros_code_B.ab_n + 32] = s[3 * ros_code_B.nx + 2];
      }

      ros_code_B.A[460] = 1;
      ros_code_B.A[461] = 0;
      ros_code_B.A[482] = 0;
      ros_code_B.A[483] = 1;
      for (ros_code_B.nx = 0; ros_code_B.nx < 33; ros_code_B.nx++) {
        for (ros_code_B.c_cg = 0; ros_code_B.c_cg < 22; ros_code_B.c_cg++) {
          ros_code_B.nblocks = 22 * ros_code_B.nx + ros_code_B.c_cg;
          ros_code_B.dv1[ros_code_B.nblocks] = 0.0;
          for (ros_code_B.r_f = 0; ros_code_B.r_f < 33; ros_code_B.r_f++) {
            ros_code_B.dv1[ros_code_B.nblocks] += ros_code_B.Z[33 *
              ros_code_B.c_cg + ros_code_B.r_f] * 2.0 * ros_code_B.Q[33 *
              ros_code_B.nx + ros_code_B.r_f];
          }
        }
      }

      for (ros_code_B.nx = 0; ros_code_B.nx < 22; ros_code_B.nx++) {
        for (ros_code_B.c_cg = 0; ros_code_B.c_cg < 22; ros_code_B.c_cg++) {
          ros_code_B.c_a_tmp = 0.0;
          for (ros_code_B.nblocks = 0; ros_code_B.nblocks < 33;
               ros_code_B.nblocks++) {
            ros_code_B.c_a_tmp += ros_code_B.dv1[22 * ros_code_B.nblocks +
              ros_code_B.nx] * ros_code_B.Z[33 * ros_code_B.c_cg +
              ros_code_B.nblocks];
          }

          ros_code_B.nblocks = 22 * ros_code_B.c_cg + ros_code_B.nx;
          ros_code_B.dv2[ros_code_B.nblocks] = static_cast<real_T>
            (ros_code_B.A[ros_code_B.nblocks]) + ros_code_B.c_a_tmp;
        }
      }

      for (ros_code_B.nx = 0; ros_code_B.nx < 33; ros_code_B.nx++) {
        ros_code_B.a_l[ros_code_B.nx] = 0.0;
        for (ros_code_B.c_cg = 0; ros_code_B.c_cg < 33; ros_code_B.c_cg++) {
          ros_code_B.a_l[ros_code_B.nx] += ros_code_B.Q[33 * ros_code_B.nx +
            ros_code_B.c_cg] * (2.0 * ros_code_B.G[ros_code_B.c_cg]);
        }
      }

      for (ros_code_B.nx = 0; ros_code_B.nx < 22; ros_code_B.nx++) {
        ros_code_B.U_max[ros_code_B.nx] = 0.0;
        for (ros_code_B.c_cg = 0; ros_code_B.c_cg < 33; ros_code_B.c_cg++) {
          ros_code_B.U_max[ros_code_B.nx] += ros_code_B.Z[33 * ros_code_B.nx +
            ros_code_B.c_cg] * ros_code_B.a_l[ros_code_B.c_cg];
        }

        for (ros_code_B.c_cg = 0; ros_code_B.c_cg < 22; ros_code_B.c_cg++) {
          ros_code_B.dv[ros_code_B.c_cg + 44 * ros_code_B.nx] = ros_code_B.dv2
            [22 * ros_code_B.nx + ros_code_B.c_cg];
          ros_code_B.dv[ros_code_B.c_cg + 44 * (ros_code_B.nx + 22)] = 0.0;
        }
      }

      for (ros_code_B.nx = 0; ros_code_B.nx < 44; ros_code_B.nx++) {
        for (ros_code_B.c_cg = 0; ros_code_B.c_cg < 22; ros_code_B.c_cg++) {
          ros_code_B.dv[(ros_code_B.c_cg + 44 * ros_code_B.nx) + 22] = u[22 *
            ros_code_B.nx + ros_code_B.c_cg];
        }
      }

      for (ros_code_B.nx = 0; ros_code_B.nx < 22; ros_code_B.nx++) {
        ros_code_B.dv3[ros_code_B.nx] = ros_code_B.U_max[ros_code_B.nx];
        ros_code_B.dv3[ros_code_B.nx + 22] = 0.0;
      }

      ros_code_quadprog(ros_code_B.dv, ros_code_B.dv3, ros_code_B.Aueq,
                        ros_code_B.Bueq, ros_code_B.lb, ros_code_B.ub,
                        ros_code_B.x, &ros_code_B.max_range,
                        &ros_code_B.mean_angle);
      if (ros_code_B.mean_angle != 0.0) {
        ros_code_B.ds = (ros_code_B.x[0] + ros_code_B.aSinInput) +
          ros_code_B.global_path_num;
        ros_code_B.d_ls = (ros_code_B.x[1] + ros_code_B.predict_accurate_index)
          + ros_code_B.dd_s;
      }
    }

    // End of Outputs for SubSystem: '<Root>/Lattice_planner'
    // End of Outputs for SubSystem: '<Root>/MPC_controller'

    // BusAssignment: '<Root>/Bus Assignment2' incorporates:
    //   Constant: '<S1>/Constant'
    //   MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'

    ros_code_B.BusAssignment2 = ros_code_P.Constant_Value_i;

    // Outputs for Atomic SubSystem: '<Root>/MPC_controller'
    ros_code_B.BusAssignment2.Linear.X = ros_code_B.ds;
    ros_code_B.BusAssignment2.Angular.Z = ros_code_B.d_ls;

    // End of Outputs for SubSystem: '<Root>/MPC_controller'

    // Outputs for Atomic SubSystem: '<Root>/Publish2'
    // MATLABSystem: '<S5>/SinkBlock'
    Pub_ros_code_1577.publish(&ros_code_B.BusAssignment2);

    // End of Outputs for SubSystem: '<Root>/Publish2'
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  ros_code_M->Timing.t[0] =
    ((time_T)(++ros_code_M->Timing.clockTick0)) * ros_code_M->Timing.stepSize0;

  {
    // Update absolute timer for sample time: [0.02s, 0.0s]
    // The "clockTick1" counts the number of times the code of this task has
    //  been executed. The resolution of this integer timer is 0.02, which is the step size
    //  of the task. Size of "clockTick1" ensures timer will not overflow during the
    //  application lifespan selected.

    ros_code_M->Timing.clockTick1++;
  }

  rate_scheduler();
}

// Model initialize function
void ros_code_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&ros_code_M->solverInfo,
                          &ros_code_M->Timing.simTimeStep);
    rtsiSetTPtr(&ros_code_M->solverInfo, &rtmGetTPtr(ros_code_M));
    rtsiSetStepSizePtr(&ros_code_M->solverInfo, &ros_code_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&ros_code_M->solverInfo, (&rtmGetErrorStatus
      (ros_code_M)));
    rtsiSetRTModelPtr(&ros_code_M->solverInfo, ros_code_M);
  }

  rtsiSetSimTimeStep(&ros_code_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&ros_code_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(ros_code_M, &ros_code_M->Timing.tArray[0]);
  ros_code_M->Timing.stepSize0 = 0.02;

  {
    char_T b_zeroDelimTopic_1[13];
    char_T b_zeroDelimTopic_0[9];
    char_T b_zeroDelimTopic[6];
    static const char_T tmp[5] = { '/', 'o', 'd', 'o', 'm' };

    static const char_T tmp_0[12] = { '/', 'g', 'l', 'o', 'b', 'a', 'l', '_',
      'p', 'a', 't', 'h' };

    static const char_T tmp_1[51] = { '/', 'f', 'a', 'k', 'e', '_', 'o', 'b',
      's', 't', 'a', 'c', 'l', 'e', '_', 'p', 'u', 'b', 'l', 'i', 's', 'h', 'e',
      'r', '/', 'v', 'i', 's', 'u', 'a', 'l', 'i', 'z', 'a', 't', 'i', 'o', 'n',
      '_', 'm', 'a', 'r', 'k', 'e', 'r', '_', 'a', 'r', 'r', 'a', 'y' };

    static const char_T tmp_2[8] = { '/', 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2'
    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S26>/In1' incorporates:
    //   Outport: '<S26>/Out1'

    ros_code_B.In1_a = ros_code_P.Out1_Y0_n;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // Start for MATLABSystem: '<S6>/SourceBlock'
    ros_code_DW.obj.matlabCodegenIsDeleted = false;
    ros_code_DW.obj.isInitialized = 1;
    for (int32_T i = 0; i < 5; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[5] = '\x00';
    Sub_ros_code_1565.createSubscriber(&b_zeroDelimTopic[0], 1);
    ros_code_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe2'

    // SystemInitialize for Atomic SubSystem: '<Root>/Global_planner'
    // SystemInitialize for Atomic SubSystem: '<S2>/Subscribe1'
    // Start for MATLABSystem: '<S9>/SourceBlock'
    ros_code_DW.obj_m.matlabCodegenIsDeleted = false;
    ros_code_DW.obj_m.isInitialized = 1;
    for (int32_T i = 0; i < 12; i++) {
      b_zeroDelimTopic_1[i] = tmp_0[i];
    }

    b_zeroDelimTopic_1[12] = '\x00';
    Sub_ros_code_1497.createSubscriber(&b_zeroDelimTopic_1[0], 1000);
    ros_code_DW.obj_m.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S2>/Subscribe1'

    // SystemInitialize for Enabled SubSystem: '<S2>/get_global_path'
    // SystemInitialize for Outport: '<S11>/preprocess_global_path_array'
    for (int32_T i = 0; i < 10000; i++) {
      ros_code_B.preprocess_global_path_array[i] =
        ros_code_P.preprocess_global_path_array_Y0;
    }

    // End of SystemInitialize for Outport: '<S11>/preprocess_global_path_array' 

    // SystemInitialize for Outport: '<S11>/get_global_pose'
    ros_code_B.get_global_pose = ros_code_P.get_global_pose_Y0;

    // End of SystemInitialize for SubSystem: '<S2>/get_global_path'

    // SystemInitialize for Atomic SubSystem: '<S2>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S8>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S13>/In1' incorporates:
    //   Outport: '<S13>/Out1'

    ros_code_B.In1_i = ros_code_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S8>/Enabled Subsystem'

    // Start for MATLABSystem: '<S8>/SourceBlock'
    ros_code_DW.obj_c.matlabCodegenIsDeleted = false;
    ros_code_DW.obj_c.isInitialized = 1;
    for (int32_T i = 0; i < 51; i++) {
      ros_code_B.b_zeroDelimTopic[i] = tmp_1[i];
    }

    ros_code_B.b_zeroDelimTopic[51] = '\x00';
    Sub_ros_code_1496.createSubscriber(&ros_code_B.b_zeroDelimTopic[0], 1);
    ros_code_DW.obj_c.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S8>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S2>/Subscribe'
    // End of SystemInitialize for SubSystem: '<Root>/Global_planner'

    // SystemInitialize for Atomic SubSystem: '<Root>/Lattice_planner'
    // InitializeConditions for Memory: '<S3>/Memory'
    for (int32_T i = 0; i < 5; i++) {
      ros_code_DW.Memory_PreviousInput[i] = ros_code_P.Memory_InitialCondition;
    }

    // End of InitializeConditions for Memory: '<S3>/Memory'

    // InitializeConditions for Memory: '<S3>/Memory1'
    memcpy(&ros_code_DW.Memory1_PreviousInput[0],
           &ros_code_P.Memory1_InitialCondition[0], 15U * sizeof(real_T));

    // End of SystemInitialize for SubSystem: '<Root>/Lattice_planner'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish2'
    // Start for MATLABSystem: '<S5>/SinkBlock'
    ros_code_DW.obj_g.matlabCodegenIsDeleted = false;
    ros_code_DW.obj_g.isInitialized = 1;
    for (int32_T i = 0; i < 8; i++) {
      b_zeroDelimTopic_0[i] = tmp_2[i];
    }

    b_zeroDelimTopic_0[8] = '\x00';
    Pub_ros_code_1577.createPublisher(&b_zeroDelimTopic_0[0], 1);
    ros_code_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish2'
  }
}

// Model terminate function
void ros_code_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe2'
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!ros_code_DW.obj.matlabCodegenIsDeleted) {
    ros_code_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe2'

  // Terminate for Atomic SubSystem: '<Root>/Global_planner'
  // Terminate for Atomic SubSystem: '<S2>/Subscribe1'
  // Terminate for MATLABSystem: '<S9>/SourceBlock'
  if (!ros_code_DW.obj_m.matlabCodegenIsDeleted) {
    ros_code_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/SourceBlock'
  // End of Terminate for SubSystem: '<S2>/Subscribe1'

  // Terminate for Atomic SubSystem: '<S2>/Subscribe'
  // Terminate for MATLABSystem: '<S8>/SourceBlock'
  if (!ros_code_DW.obj_c.matlabCodegenIsDeleted) {
    ros_code_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/SourceBlock'
  // End of Terminate for SubSystem: '<S2>/Subscribe'
  // End of Terminate for SubSystem: '<Root>/Global_planner'

  // Terminate for Atomic SubSystem: '<Root>/Publish2'
  // Terminate for MATLABSystem: '<S5>/SinkBlock'
  if (!ros_code_DW.obj_g.matlabCodegenIsDeleted) {
    ros_code_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish2'
}

//
// File trailer for generated code.
//
// [EOF]
//
