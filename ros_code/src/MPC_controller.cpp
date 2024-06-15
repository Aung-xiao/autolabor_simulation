//
// File: MPC_controller.cpp
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
#include "MPC_controller.h"
#include "ros_code_types.h"
#include <cstring>
#include <cmath>
#include "ros_code_private.h"
#include <emmintrin.h>
#include "ros_code.h"

// Forward declaration for local functions
static void ros_code_eye(real_T b_I[11025]);
static void ros_code_factoryConstruct(sFUo2n2eWek74Kh1Ligw2mE_ros_c_T *obj);
static void ros_cod_modifyOverheadPhaseOne_(sU7yup9HkfLOO3uVZruoOBF_ros_c_T *obj);
static void ros_code_setProblemType(sU7yup9HkfLOO3uVZruoOBF_ros_c_T *obj,
  int32_T PROBLEM_TYPE);
static real_T ros_code_xnrm2_k(int32_T n, const real_T x[21505], int32_T ix0,
  B_MPC_controller_ros_code_T *localB);
static real_T ros_code_xzlarfg_e(int32_T n, real_T *alpha1, real_T x[21505],
  int32_T ix0, B_MPC_controller_ros_code_T *localB);
static void ros_code_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau,
  real_T C[21505], int32_T ic0, real_T work[253], B_MPC_controller_ros_code_T
  *localB);
static void ros_code_qrf(real_T A[21505], int32_T m, int32_T n, int32_T nfxd,
  real_T tau[85], B_MPC_controller_ros_code_T *localB);
static void ros_code_qrpf(real_T A[21505], int32_T m, int32_T n, int32_T nfxd,
  real_T tau[85], int32_T jpvt[253], B_MPC_controller_ros_code_T *localB);
static void ros_code_factorQRE(sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *obj, int32_T
  mrows, int32_T ncols, B_MPC_controller_ros_code_T *localB);
static void ros_code_computeQ_(sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *obj, int32_T
  nrows, B_MPC_controller_ros_code_T *localB);
static void ros_code_IndexOfDependentEq_(int32_T depIdx[253], int32_T mFixed,
  int32_T nDep, sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *qrmanager, int32_T mRows,
  int32_T nCols, B_MPC_controller_ros_code_T *localB);
static void ros_code_countsort(int32_T x[253], int32_T xLen, int32_T workspace
  [253], int32_T xMin, int32_T xMax);
static void ros_code_removeConstr(sU7yup9HkfLOO3uVZruoOBF_ros_c_T *obj, int32_T
  idx_global);
static void ros_code_removeEqConstr(sU7yup9HkfLOO3uVZruoOBF_ros_c_T *obj,
  int32_T idx_global, B_MPC_controller_ros_code_T *localB);
static void ros_code_RemoveDependentEq_(sIBsEwkwZMwV16lGx5frI7G_ros_c_T
  *memspace, sU7yup9HkfLOO3uVZruoOBF_ros_c_T *workingset, int32_T *nDepInd,
  sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *qrmanager, B_MPC_controller_ros_code_T
  *localB);
static void ros_code_RemoveDependentIneq_(sU7yup9HkfLOO3uVZruoOBF_ros_c_T
  *workingset, sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *qrmanager,
  sIBsEwkwZMwV16lGx5frI7G_ros_c_T *memspace, real_T tolfactor,
  B_MPC_controller_ros_code_T *localB);
static void ros_code_removeAllIneqConstr(sU7yup9HkfLOO3uVZruoOBF_ros_c_T *obj);
static void ros_code_factorQR(sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *obj, const real_T
  A[21505], int32_T mrows, int32_T ncols, B_MPC_controller_ros_code_T *localB);
static real_T ros_code_maxConstraintViolation(sU7yup9HkfLOO3uVZruoOBF_ros_c_T
  *obj, const real_T x[21505], B_MPC_controller_ros_code_T *localB);
static real_T ros_co_maxConstraintViolation_l(sU7yup9HkfLOO3uVZruoOBF_ros_c_T
  *obj, const real_T x[21505], B_MPC_controller_ros_code_T *localB);
static boolean_T ros_cod_feasibleX0ForWorkingSet(real_T workspace[21505], real_T
  xCurrent[85], sU7yup9HkfLOO3uVZruoOBF_ros_c_T *workingset,
  sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *qrmanager, B_MPC_controller_ros_code_T
  *localB);
static real_T ros_c_maxConstraintViolation_la(sU7yup9HkfLOO3uVZruoOBF_ros_c_T
  *obj, const real_T x[85], B_MPC_controller_ros_code_T *localB);
static void ros_code_PresolveWorkingSet(sizV6IUWKAiWqwEIFf7P38E_ros_c_T
  *solution, sIBsEwkwZMwV16lGx5frI7G_ros_c_T *memspace,
  sU7yup9HkfLOO3uVZruoOBF_ros_c_T *workingset, sxn76bLJrqJiWwjGl8YOqSB_ros_c_T
  *qrmanager, B_MPC_controller_ros_code_T *localB);
static void ros_code_xgemv(int32_T m, int32_T n, const real_T A[7056], int32_T
  lda, const real_T x[85], real_T y[84]);
static void ros_code_computeGrad_StoreHx(smUUAx65r5SQ5CSZDAURIoG_ros_c_T *obj,
  const real_T H[7056], const real_T f[84], const real_T x[85],
  B_MPC_controller_ros_code_T *localB);
static real_T ros_code_computeFval_ReuseHx(const smUUAx65r5SQ5CSZDAURIoG_ros_c_T
  *obj, real_T workspace[21505], const real_T f[84], const real_T x[85]);
static void ros_code_xrotg(real_T *a, real_T *b, real_T *c, real_T *s,
  B_MPC_controller_ros_code_T *localB);
static void ros_code_deleteColMoveEnd(sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *obj,
  int32_T idx, B_MPC_controller_ros_code_T *localB);
static void ros_cod_computeProjectedHessian(const real_T H[7056],
  sFUo2n2eWek74Kh1Ligw2mE_ros_c_T *cholmanager, const
  sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *qrmanager, sIBsEwkwZMwV16lGx5frI7G_ros_c_T
  *memspace, B_MPC_controller_ros_code_T *localB);
static void ros_code_xgemv_n(int32_T m, int32_T n, const real_T A[7225], int32_T
  ia0, const real_T x[21505], real_T y[85]);
static int32_T ros_code_ixamax(int32_T n, const real_T x[7225]);
static void ros_code_fullColLDL2_(sFUo2n2eWek74Kh1Ligw2mE_ros_c_T *obj, int32_T
  NColsRemain, real_T REG_PRIMAL, B_MPC_controller_ros_code_T *localB);
static void ros_code_compute_deltax(const real_T H[7056],
  sizV6IUWKAiWqwEIFf7P38E_ros_c_T *solution, sIBsEwkwZMwV16lGx5frI7G_ros_c_T
  *memspace, const sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *qrmanager,
  sFUo2n2eWek74Kh1Ligw2mE_ros_c_T *cholmanager, const
  smUUAx65r5SQ5CSZDAURIoG_ros_c_T *objective, B_MPC_controller_ros_code_T
  *localB);
static real_T ros_code_xnrm2_kp(int32_T n, const real_T x[85],
  B_MPC_controller_ros_code_T *localB);
static void ros_code_compute_lambda(real_T workspace[21505],
  sizV6IUWKAiWqwEIFf7P38E_ros_c_T *solution, const
  smUUAx65r5SQ5CSZDAURIoG_ros_c_T *objective, const
  sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *qrmanager, B_MPC_controller_ros_code_T
  *localB);
static void ros_code_xgemv_nm(int32_T m, const real_T A[7140], const real_T x[85],
  real_T y[21505], B_MPC_controller_ros_code_T *localB);
static void ros_code_xgemv_nmi(int32_T m, const real_T A[7140], const real_T x
  [85], real_T y[21505], B_MPC_controller_ros_code_T *localB);
static void ros_code_ratiotest(const real_T solution_xstar[85], const real_T
  solution_searchDir[85], real_T workspace[21505], int32_T workingset_nVar,
  const real_T workingset_Aineq[7140], const real_T workingset_bineq[84], const
  real_T workingset_lb[85], const real_T workingset_ub[85], const int32_T
  workingset_indexLB[85], const int32_T workingset_indexUB[85], const int32_T
  workingset_sizes[5], const int32_T workingset_isActiveIdx[6], const boolean_T
  workingset_isActiveConstr[253], const int32_T workingset_nWConstr[5], real_T
  *toldelta, real_T *alpha, boolean_T *newBlocking, int32_T *constrType, int32_T
  *constrIdx, B_MPC_controller_ros_code_T *localB);
static void ros_code_feasibleratiotest(const real_T solution_xstar[85], const
  real_T solution_searchDir[85], real_T workspace[21505], int32_T
  workingset_nVar, const real_T workingset_Aineq[7140], const real_T
  workingset_bineq[84], const real_T workingset_lb[85], const real_T
  workingset_ub[85], const int32_T workingset_indexLB[85], const int32_T
  workingset_indexUB[85], const int32_T workingset_sizes[5], const int32_T
  workingset_isActiveIdx[6], const boolean_T workingset_isActiveConstr[253],
  const int32_T workingset_nWConstr[5], boolean_T isPhaseOne, real_T *alpha,
  boolean_T *newBlocking, int32_T *constrType, int32_T *constrIdx,
  B_MPC_controller_ros_code_T *localB);
static void ros_co_checkUnboundedOrIllPosed(sizV6IUWKAiWqwEIFf7P38E_ros_c_T
  *solution, const smUUAx65r5SQ5CSZDAURIoG_ros_c_T *objective,
  B_MPC_controller_ros_code_T *localB);
static void ros__addBoundToActiveSetMatrix_(sU7yup9HkfLOO3uVZruoOBF_ros_c_T *obj,
  int32_T TYPE, int32_T idx_local);
static void ros__checkStoppingAndUpdateFval(int32_T *activeSetChangeID, const
  real_T f[84], sizV6IUWKAiWqwEIFf7P38E_ros_c_T *solution,
  sIBsEwkwZMwV16lGx5frI7G_ros_c_T *memspace, const
  smUUAx65r5SQ5CSZDAURIoG_ros_c_T *objective, sU7yup9HkfLOO3uVZruoOBF_ros_c_T
  *workingset, sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *qrmanager, real_T
  options_ObjectiveLimit, int32_T runTimeOptions_MaxIterations, real_T
  runTimeOptions_ConstrRelTolFact, boolean_T updateFval,
  B_MPC_controller_ros_code_T *localB);
static void ros_code_iterate(const real_T H[7056], const real_T f[84],
  sizV6IUWKAiWqwEIFf7P38E_ros_c_T *solution, sIBsEwkwZMwV16lGx5frI7G_ros_c_T
  *memspace, sU7yup9HkfLOO3uVZruoOBF_ros_c_T *workingset,
  sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *qrmanager, sFUo2n2eWek74Kh1Ligw2mE_ros_c_T
  *cholmanager, smUUAx65r5SQ5CSZDAURIoG_ros_c_T *objective, real_T
  options_ObjectiveLimit, real_T options_StepTolerance, int32_T
  runTimeOptions_MaxIterations, real_T runTimeOptions_ConstrRelTolFact, real_T
  runTimeOptions_ProbRelTolFactor, boolean_T runTimeOptions_RemainFeasible,
  B_MPC_controller_ros_code_T *localB);
static void ros_code_linearForm_(boolean_T obj_hasLinear, int32_T obj_nvar,
  real_T workspace[21505], const real_T H[7056], const real_T f[84], const
  real_T x[85], B_MPC_controller_ros_code_T *localB);
static real_T ros_code_computeFval(const smUUAx65r5SQ5CSZDAURIoG_ros_c_T *obj,
  real_T workspace[21505], const real_T H[7056], const real_T f[84], const
  real_T x[85], B_MPC_controller_ros_code_T *localB);
static void ros_code_phaseone(const real_T H[7056], const real_T f[84],
  sizV6IUWKAiWqwEIFf7P38E_ros_c_T *solution, sIBsEwkwZMwV16lGx5frI7G_ros_c_T
  *memspace, sU7yup9HkfLOO3uVZruoOBF_ros_c_T *workingset,
  sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *qrmanager, sFUo2n2eWek74Kh1Ligw2mE_ros_c_T
  *cholmanager, const sL9bDKomAYkxZSVrG9w6En_ros_co_T *runTimeOptions,
  smUUAx65r5SQ5CSZDAURIoG_ros_c_T *objective, sSOeZ9WO10chPn9Si6PKiCB_ros_c_T
  *options, B_MPC_controller_ros_code_T *localB);
static boolean_T ros_code_strcmp(const char_T a[8]);
static void ros_code_computeFirstOrderOpt(sizV6IUWKAiWqwEIFf7P38E_ros_c_T
  *solution, const smUUAx65r5SQ5CSZDAURIoG_ros_c_T *objective, int32_T
  workingset_nVar, const real_T workingset_ATwset[21505], int32_T
  workingset_nActiveConstr, real_T workspace[21505], B_MPC_controller_ros_code_T
  *localB);
static int32_T ros_code_RemoveDependentEq__o(sIBsEwkwZMwV16lGx5frI7G_ros_c_T
  *memspace, sU7yup9HkfLOO3uVZruoOBF_ros_c_T *workingset,
  sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *qrmanager, B_MPC_controller_ros_code_T
  *localB);
static void ros_code_PresolveWorkingSet_k(sizV6IUWKAiWqwEIFf7P38E_ros_c_T
  *solution, sIBsEwkwZMwV16lGx5frI7G_ros_c_T *memspace,
  sU7yup9HkfLOO3uVZruoOBF_ros_c_T *workingset, sxn76bLJrqJiWwjGl8YOqSB_ros_c_T
  *qrmanager, B_MPC_controller_ros_code_T *localB);
static void ros_code_phaseone_f(const real_T H[7056], const real_T f[84],
  sizV6IUWKAiWqwEIFf7P38E_ros_c_T *solution, sIBsEwkwZMwV16lGx5frI7G_ros_c_T
  *memspace, sU7yup9HkfLOO3uVZruoOBF_ros_c_T *workingset,
  sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *qrmanager, sFUo2n2eWek74Kh1Ligw2mE_ros_c_T
  *cholmanager, smUUAx65r5SQ5CSZDAURIoG_ros_c_T *objective,
  sSOeZ9WO10chPn9Si6PKiCB_ros_c_T *options, const
  sL9bDKomAYkxZSVrG9w6En_ros_co_T *runTimeOptions, B_MPC_controller_ros_code_T
  *localB);
static void ros_code_driver(const real_T H[7056], const real_T f[84],
  sizV6IUWKAiWqwEIFf7P38E_ros_c_T *solution, sIBsEwkwZMwV16lGx5frI7G_ros_c_T
  *memspace, sU7yup9HkfLOO3uVZruoOBF_ros_c_T *workingset,
  sFUo2n2eWek74Kh1Ligw2mE_ros_c_T *cholmanager, sL9bDKomAYkxZSVrG9w6En_ros_co_T
  runTimeOptions, sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *qrmanager,
  smUUAx65r5SQ5CSZDAURIoG_ros_c_T *objective, B_MPC_controller_ros_code_T
  *localB);
static void ros_code_quadprog(const real_T H[7056], const real_T f[84], const
  real_T Aineq[7056], const real_T bineq[84], const real_T lb[84], const real_T
  ub[84], real_T x[84], real_T *fval, real_T *exitflag,
  B_MPC_controller_ros_code_T *localB);
static void ros_code_binary_expand_op_l(real_T in1[4410], int32_T in2, int32_T
  in4, int32_T in5, int32_T in6, int32_T in7, B_MPC_controller_ros_code_T
  *localB);
static void ros_code_mtimes(const real_T A[25], const real_T B_data[], const
  int32_T B_size[2], real_T C_data[], int32_T C_size[2]);
static void ros_code_mtimes_p(const real_T B_data[], const int32_T B_size[2],
  real_T C_data[], int32_T C_size[2]);
static void ros_code_mtimes_pg(const real_T A_data[], const int32_T A_size[2],
  const real_T B_data[], const int32_T B_size[2], real_T C_data[], int32_T
  C_size[2]);

// Function for MATLAB Function: '<S4>/MPC//buildPredictionModel'
static void ros_code_eye(real_T b_I[11025])
{
  std::memset(&b_I[0], 0, 11025U * sizeof(real_T));
  for (int32_T k{0}; k < 105; k++) {
    b_I[k + 105 * k] = 1.0;
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_factoryConstruct(sFUo2n2eWek74Kh1Ligw2mE_ros_c_T *obj)
{
  obj->ldm = 85;
  obj->ndims = 0;
  obj->info = 0;
  obj->scaleFactor = 1.0;
  obj->ConvexCheck = true;
  obj->regTol_ = 0.0;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_cod_modifyOverheadPhaseOne_(sU7yup9HkfLOO3uVZruoOBF_ros_c_T *obj)
{
  for (int32_T idx{0}; idx < obj->sizes[0]; idx++) {
    obj->ATwset[85 * idx + 84] = 0.0;
  }

  for (int32_T idx{0}; idx < 84; idx++) {
    obj->Aineq[85 * idx + 84] = -1.0;
  }

  obj->indexLB[obj->sizes[3] - 1] = 85;
  obj->lb[84] = obj->SLACK0;
  for (int32_T idx{obj->isActiveIdx[2]}; idx <= obj->nActiveConstr; idx++) {
    obj->ATwset[85 * (idx - 1) + 84] = -1.0;
  }

  if (obj->nWConstr[4] > 0) {
    for (int32_T idx{0}; idx <= obj->sizesNormal[4]; idx++) {
      obj->isActiveConstr[(obj->isActiveIdx[4] + idx) - 1] = false;
    }
  }

  obj->isActiveConstr[obj->isActiveIdx[4] - 2] = false;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_setProblemType(sU7yup9HkfLOO3uVZruoOBF_ros_c_T *obj,
  int32_T PROBLEM_TYPE)
{
  switch (PROBLEM_TYPE) {
   case 3:
    obj->nVar = 84;
    obj->mConstr = obj->mConstrOrig;
    if (obj->nWConstr[4] > 0) {
      for (int32_T idx_lb{-1}; idx_lb < obj->sizesNormal[4] - 1; idx_lb++) {
        obj->isActiveConstr[obj->isActiveIdxNormal[4] + idx_lb] =
          obj->isActiveConstr[obj->isActiveIdx[4] + idx_lb];
      }
    }

    for (int32_T idx_lb{0}; idx_lb < 5; idx_lb++) {
      obj->sizes[idx_lb] = obj->sizesNormal[idx_lb];
    }

    for (int32_T idx_lb{0}; idx_lb < 6; idx_lb++) {
      obj->isActiveIdx[idx_lb] = obj->isActiveIdxNormal[idx_lb];
    }
    break;

   case 1:
    obj->nVar = 85;
    obj->mConstr = obj->mConstrOrig + 1;
    for (int32_T idx_lb{0}; idx_lb < 5; idx_lb++) {
      obj->sizes[idx_lb] = obj->sizesPhaseOne[idx_lb];
    }

    for (int32_T idx_lb{0}; idx_lb < 6; idx_lb++) {
      obj->isActiveIdx[idx_lb] = obj->isActiveIdxPhaseOne[idx_lb];
    }

    ros_cod_modifyOverheadPhaseOne_(obj);
    break;

   case 2:
    {
      int32_T idx_lb;
      obj->nVar = 84;
      obj->mConstr = 252;
      for (idx_lb = 0; idx_lb < 5; idx_lb++) {
        obj->sizes[idx_lb] = obj->sizesRegularized[idx_lb];
      }

      if (obj->probType != 4) {
        int32_T colOffsetAineq;
        for (idx_lb = 0; idx_lb < 84; idx_lb++) {
          colOffsetAineq = 85 * idx_lb;
          for (int32_T idx_row{85}; idx_row <= idx_lb + 84; idx_row++) {
            obj->Aineq[(idx_row + colOffsetAineq) - 1] = 0.0;
          }

          obj->Aineq[(idx_lb + colOffsetAineq) + 84] = -1.0;
        }

        idx_lb = 84;
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

        obj->lb[84] = 0.0;
        for (idx_lb = obj->isActiveIdx[2] - 1; idx_lb < obj->nActiveConstr;
             idx_lb++) {
          colOffsetAineq = 85 * idx_lb - 1;
          if (obj->Wid[idx_lb] == 3) {
            for (int32_T idx_row{85}; idx_row <= obj->Wlocalidx[idx_lb] + 83;
                 idx_row++) {
              obj->ATwset[idx_row + colOffsetAineq] = 0.0;
            }

            obj->ATwset[(obj->Wlocalidx[idx_lb] + colOffsetAineq) + 84] = -1.0;
            for (int32_T idx_row{obj->Wlocalidx[idx_lb] + 85}; idx_row < 85;
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
    obj->nVar = 85;
    obj->mConstr = 253;
    for (int32_T idx_lb{0}; idx_lb < 5; idx_lb++) {
      obj->sizes[idx_lb] = obj->sizesRegPhaseOne[idx_lb];
    }

    for (int32_T idx_lb{0}; idx_lb < 6; idx_lb++) {
      obj->isActiveIdx[idx_lb] = obj->isActiveIdxRegPhaseOne[idx_lb];
    }

    ros_cod_modifyOverheadPhaseOne_(obj);
    break;
  }

  obj->probType = PROBLEM_TYPE;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static real_T ros_code_xnrm2_k(int32_T n, const real_T x[21505], int32_T ix0,
  B_MPC_controller_ros_code_T *localB)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = std::abs(x[ix0 - 1]);
    } else {
      int32_T kend;
      localB->scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (int32_T k{ix0}; k <= kend; k++) {
        localB->absxk = std::abs(x[k - 1]);
        if (localB->absxk > localB->scale) {
          localB->t = localB->scale / localB->absxk;
          y = y * localB->t * localB->t + 1.0;
          localB->scale = localB->absxk;
        } else {
          localB->t = localB->absxk / localB->scale;
          y += localB->t * localB->t;
        }
      }

      y = localB->scale * std::sqrt(y);
    }
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T y;
  a = std::abs(u0);
  y = std::abs(u1);
  if (a < y) {
    a /= y;
    y *= std::sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = std::sqrt(y * y + 1.0) * a;
  } else if (!std::isnan(y)) {
    y = a * 1.4142135623730951;
  }

  return y;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static real_T ros_code_xzlarfg_e(int32_T n, real_T *alpha1, real_T x[21505],
  int32_T ix0, B_MPC_controller_ros_code_T *localB)
{
  real_T tau;
  tau = 0.0;
  if (n > 0) {
    localB->xnorm = ros_code_xnrm2_k(n - 1, x, ix0, localB);
    if (localB->xnorm != 0.0) {
      localB->xnorm = rt_hypotd_snf(*alpha1, localB->xnorm);
      if (*alpha1 >= 0.0) {
        localB->xnorm = -localB->xnorm;
      }

      if (std::abs(localB->xnorm) < 1.0020841800044864E-292) {
        int32_T c_k;
        int32_T knt;
        knt = 0;
        c_k = (ix0 + n) - 2;
        do {
          knt++;
          for (int32_T b_k{ix0}; b_k <= c_k; b_k++) {
            x[b_k - 1] *= 9.9792015476736E+291;
          }

          localB->xnorm *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while ((std::abs(localB->xnorm) < 1.0020841800044864E-292) && (knt <
                  20));

        localB->xnorm = rt_hypotd_snf(*alpha1, ros_code_xnrm2_k(n - 1, x, ix0,
          localB));
        if (*alpha1 >= 0.0) {
          localB->xnorm = -localB->xnorm;
        }

        tau = (localB->xnorm - *alpha1) / localB->xnorm;
        localB->a_m = 1.0 / (*alpha1 - localB->xnorm);
        for (int32_T b_k{ix0}; b_k <= c_k; b_k++) {
          x[b_k - 1] *= localB->a_m;
        }

        for (c_k = 0; c_k < knt; c_k++) {
          localB->xnorm *= 1.0020841800044864E-292;
        }

        *alpha1 = localB->xnorm;
      } else {
        int32_T knt;
        tau = (localB->xnorm - *alpha1) / localB->xnorm;
        localB->a_m = 1.0 / (*alpha1 - localB->xnorm);
        knt = (ix0 + n) - 2;
        for (int32_T c_k{ix0}; c_k <= knt; c_k++) {
          x[c_k - 1] *= localB->a_m;
        }

        *alpha1 = localB->xnorm;
      }
    }
  }

  return tau;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau,
  real_T C[21505], int32_T ic0, real_T work[253], B_MPC_controller_ros_code_T
  *localB)
{
  int32_T coltop;
  int32_T jy;
  if (tau != 0.0) {
    boolean_T exitg2;
    localB->lastv = m;
    localB->lastc = iv0 + m;
    while ((localB->lastv > 0) && (C[localB->lastc - 2] == 0.0)) {
      localB->lastv--;
      localB->lastc--;
    }

    localB->lastc = n;
    exitg2 = false;
    while ((!exitg2) && (localB->lastc > 0)) {
      int32_T exitg1;
      coltop = (localB->lastc - 1) * 85 + ic0;
      jy = coltop;
      do {
        exitg1 = 0;
        if (jy <= (coltop + localB->lastv) - 1) {
          if (C[jy - 1] != 0.0) {
            exitg1 = 1;
          } else {
            jy++;
          }
        } else {
          localB->lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }

    localB->lastc--;
  } else {
    localB->lastv = 0;
    localB->lastc = -1;
  }

  if (localB->lastv > 0) {
    int32_T d;
    int32_T ia;
    int32_T ix;
    if (localB->lastc + 1 != 0) {
      for (coltop = 0; coltop <= localB->lastc; coltop++) {
        work[coltop] = 0.0;
      }

      coltop = 0;
      jy = 85 * localB->lastc + ic0;
      for (int32_T iac{ic0}; iac <= jy; iac += 85) {
        ix = iv0;
        localB->c_l = 0.0;
        d = (iac + localB->lastv) - 1;
        for (ia = iac; ia <= d; ia++) {
          localB->c_l += C[ia - 1] * C[ix - 1];
          ix++;
        }

        work[coltop] += localB->c_l;
        coltop++;
      }
    }

    if (!(-tau == 0.0)) {
      coltop = ic0 - 1;
      jy = 0;
      for (int32_T iac{0}; iac <= localB->lastc; iac++) {
        if (work[jy] != 0.0) {
          localB->c_l = work[jy] * -tau;
          ix = iv0;
          d = coltop;
          ia = localB->lastv + coltop;
          while (d + 1 <= ia) {
            C[d] += C[ix - 1] * localB->c_l;
            ix++;
            d++;
          }
        }

        jy++;
        coltop += 85;
      }
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_qrf(real_T A[21505], int32_T m, int32_T n, int32_T nfxd,
  real_T tau[85], B_MPC_controller_ros_code_T *localB)
{
  std::memset(&localB->work_b[0], 0, 253U * sizeof(real_T));
  localB->i_o = 0;
  while (localB->i_o <= nfxd - 1) {
    localB->ii_g = localB->i_o * 85 + localB->i_o;
    localB->mmi_c = m - localB->i_o;
    if (localB->i_o + 1 < m) {
      localB->b_atmp = A[localB->ii_g];
      tau[localB->i_o] = ros_code_xzlarfg_e(localB->mmi_c, &localB->b_atmp, A,
        localB->ii_g + 2, localB);
      A[localB->ii_g] = localB->b_atmp;
    } else {
      tau[localB->i_o] = 0.0;
    }

    if (localB->i_o + 1 < n) {
      localB->b_atmp = A[localB->ii_g];
      A[localB->ii_g] = 1.0;
      ros_code_xzlarf(localB->mmi_c, (n - localB->i_o) - 1, localB->ii_g + 1,
                      tau[localB->i_o], A, localB->ii_g + 86, localB->work_b,
                      localB);
      A[localB->ii_g] = localB->b_atmp;
    }

    localB->i_o++;
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_qrpf(real_T A[21505], int32_T m, int32_T n, int32_T nfxd,
  real_T tau[85], int32_T jpvt[253], B_MPC_controller_ros_code_T *localB)
{
  if (m <= n) {
    localB->minmn = m;
  } else {
    localB->minmn = n;
  }

  std::memset(&localB->work[0], 0, 253U * sizeof(real_T));
  std::memset(&localB->vn1[0], 0, 253U * sizeof(real_T));
  std::memset(&localB->vn2[0], 0, 253U * sizeof(real_T));
  localB->i_g = nfxd;
  while (localB->i_g + 1 <= n) {
    localB->vn1[localB->i_g] = ros_code_xnrm2_k(m - nfxd, A, (localB->i_g * 85 +
      nfxd) + 1, localB);
    localB->vn2[localB->i_g] = localB->vn1[localB->i_g];
    localB->i_g++;
  }

  localB->i_g = nfxd;
  while (localB->i_g + 1 <= localB->minmn) {
    localB->b_j = localB->i_g + 1;
    localB->ii = localB->i_g * 85 + localB->i_g;
    localB->nmi = n - localB->i_g;
    localB->mmi = m - localB->i_g;
    if (localB->nmi < 1) {
      localB->pvt = -1;
    } else {
      localB->pvt = 0;
      if (localB->nmi > 1) {
        localB->ix_p = localB->i_g;
        localB->smax = std::abs(localB->vn1[localB->i_g]);
        localB->iy_p = 2;
        while (localB->iy_p <= localB->nmi) {
          localB->ix_p++;
          localB->s = std::abs(localB->vn1[localB->ix_p]);
          if (localB->s > localB->smax) {
            localB->pvt = localB->iy_p - 1;
            localB->smax = localB->s;
          }

          localB->iy_p++;
        }
      }
    }

    localB->pvt += localB->i_g;
    if (localB->pvt + 1 != localB->i_g + 1) {
      localB->ix_p = localB->pvt * 85;
      localB->iy_p = localB->i_g * 85;
      localB->b_k_a = 0;
      while (localB->b_k_a <= m - 1) {
        localB->smax = A[localB->ix_p];
        A[localB->ix_p] = A[localB->iy_p];
        A[localB->iy_p] = localB->smax;
        localB->ix_p++;
        localB->iy_p++;
        localB->b_k_a++;
      }

      localB->ix_p = jpvt[localB->pvt];
      jpvt[localB->pvt] = jpvt[localB->i_g];
      jpvt[localB->i_g] = localB->ix_p;
      localB->vn1[localB->pvt] = localB->vn1[localB->i_g];
      localB->vn2[localB->pvt] = localB->vn2[localB->i_g];
    }

    if (localB->i_g + 1 < m) {
      localB->smax = A[localB->ii];
      tau[localB->i_g] = ros_code_xzlarfg_e(localB->mmi, &localB->smax, A,
        localB->ii + 2, localB);
      A[localB->ii] = localB->smax;
    } else {
      tau[localB->i_g] = 0.0;
    }

    if (localB->i_g + 1 < n) {
      localB->smax = A[localB->ii];
      A[localB->ii] = 1.0;
      ros_code_xzlarf(localB->mmi, localB->nmi - 1, localB->ii + 1, tau
                      [localB->i_g], A, localB->ii + 86, localB->work, localB);
      A[localB->ii] = localB->smax;
    }

    while (localB->b_j + 1 <= n) {
      localB->ii = localB->b_j * 85 + localB->i_g;
      if (localB->vn1[localB->b_j] != 0.0) {
        localB->smax = std::abs(A[localB->ii]) / localB->vn1[localB->b_j];
        localB->smax = 1.0 - localB->smax * localB->smax;
        if (localB->smax < 0.0) {
          localB->smax = 0.0;
        }

        localB->s = localB->vn1[localB->b_j] / localB->vn2[localB->b_j];
        localB->s = localB->s * localB->s * localB->smax;
        if (localB->s <= 1.4901161193847656E-8) {
          if (localB->i_g + 1 < m) {
            localB->vn1[localB->b_j] = ros_code_xnrm2_k(localB->mmi - 1, A,
              localB->ii + 2, localB);
            localB->vn2[localB->b_j] = localB->vn1[localB->b_j];
          } else {
            localB->vn1[localB->b_j] = 0.0;
            localB->vn2[localB->b_j] = 0.0;
          }
        } else {
          localB->vn1[localB->b_j] *= std::sqrt(localB->smax);
        }
      }

      localB->b_j++;
    }

    localB->i_g++;
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_factorQRE(sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *obj, int32_T
  mrows, int32_T ncols, B_MPC_controller_ros_code_T *localB)
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
      localB->u1 = mrows;
    } else {
      localB->u1 = ncols;
    }

    obj->minRowCol = localB->u1;
    std::memcpy(&localB->A[0], &obj->QR[0], 21505U * sizeof(real_T));
    std::memcpy(&localB->jpvt[0], &obj->jpvt[0], 253U * sizeof(int32_T));
    std::memset(&obj->tau[0], 0, 85U * sizeof(real_T));
    if (localB->u1 < 1) {
      localB->u1 = 0;
      while (localB->u1 <= ncols - 1) {
        localB->jpvt[localB->u1] = localB->u1 + 1;
        localB->u1++;
      }
    } else {
      localB->nfxd = -1;
      localB->i_ct = 0;
      while (localB->i_ct <= ncols - 1) {
        if (localB->jpvt[localB->i_ct] != 0) {
          localB->nfxd++;
          if (localB->i_ct + 1 != localB->nfxd + 1) {
            localB->ix_j = localB->i_ct * 85;
            localB->iy_h = localB->nfxd * 85;
            localB->k_c = 0;
            while (localB->k_c <= mrows - 1) {
              localB->temp = localB->A[localB->ix_j];
              localB->A[localB->ix_j] = localB->A[localB->iy_h];
              localB->A[localB->iy_h] = localB->temp;
              localB->ix_j++;
              localB->iy_h++;
              localB->k_c++;
            }

            localB->jpvt[localB->i_ct] = localB->jpvt[localB->nfxd];
            localB->jpvt[localB->nfxd] = localB->i_ct + 1;
          } else {
            localB->jpvt[localB->i_ct] = localB->i_ct + 1;
          }
        } else {
          localB->jpvt[localB->i_ct] = localB->i_ct + 1;
        }

        localB->i_ct++;
      }

      if (localB->nfxd + 1 <= localB->u1) {
        localB->nfxd++;
      } else {
        localB->nfxd = localB->u1;
      }

      std::memset(&obj->tau[0], 0, 85U * sizeof(real_T));
      ros_code_qrf(localB->A, mrows, ncols, localB->nfxd, obj->tau, localB);
      if (localB->nfxd < localB->u1) {
        ros_code_qrpf(localB->A, mrows, ncols, localB->nfxd, obj->tau,
                      localB->jpvt, localB);
      }
    }

    std::memcpy(&obj->QR[0], &localB->A[0], 21505U * sizeof(real_T));
    std::memcpy(&obj->jpvt[0], &localB->jpvt[0], 253U * sizeof(int32_T));
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_computeQ_(sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *obj, int32_T
  nrows, B_MPC_controller_ros_code_T *localB)
{
  int32_T i;
  localB->idx_e = 0;
  while (localB->idx_e <= obj->minRowCol - 1) {
    i = 85 * localB->idx_e + localB->idx_e;
    localB->itau = obj->mrows - localB->idx_e;
    localB->iaii = 1;
    while (localB->iaii - 1 <= localB->itau - 2) {
      localB->lastv_o = i + localB->iaii;
      obj->Q[localB->lastv_o] = obj->QR[localB->lastv_o];
      localB->iaii++;
    }

    localB->idx_e++;
  }

  localB->idx_e = obj->mrows;
  if (nrows >= 1) {
    for (i = obj->minRowCol; i < nrows; i++) {
      localB->itau = i * 85;
      localB->iaii = 0;
      while (localB->iaii <= localB->idx_e - 1) {
        obj->Q[localB->itau + localB->iaii] = 0.0;
        localB->iaii++;
      }

      obj->Q[localB->itau + i] = 1.0;
    }

    localB->itau = obj->minRowCol - 1;
    std::memset(&localB->work_f[0], 0, 85U * sizeof(real_T));
    for (i = obj->minRowCol; i >= 1; i--) {
      localB->iaii = (i - 1) * 85 + i;
      if (i < nrows) {
        int32_T coltop;
        int32_T jy;
        obj->Q[localB->iaii - 1] = 1.0;
        localB->lastv_o = localB->idx_e - i;
        if (obj->tau[localB->itau] != 0.0) {
          boolean_T exitg2;
          localB->lastc_h = localB->iaii + localB->lastv_o;
          while ((localB->lastv_o + 1 > 0) && (obj->Q[localB->lastc_h - 1] ==
                  0.0)) {
            localB->lastv_o--;
            localB->lastc_h--;
          }

          localB->lastc_h = nrows - i;
          exitg2 = false;
          while ((!exitg2) && (localB->lastc_h > 0)) {
            int32_T exitg1;
            coltop = ((localB->lastc_h - 1) * 85 + localB->iaii) + 85;
            jy = coltop;
            do {
              exitg1 = 0;
              if (jy <= coltop + localB->lastv_o) {
                if (obj->Q[jy - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  jy++;
                }
              } else {
                localB->lastc_h--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
              exitg2 = true;
            }
          }

          localB->lastc_h--;
        } else {
          localB->lastv_o = -1;
          localB->lastc_h = -1;
        }

        if (localB->lastv_o + 1 > 0) {
          int32_T b_ia;
          int32_T e;
          if (localB->lastc_h + 1 != 0) {
            for (coltop = 0; coltop <= localB->lastc_h; coltop++) {
              localB->work_f[coltop] = 0.0;
            }

            coltop = 0;
            jy = (85 * localB->lastc_h + localB->iaii) + 85;
            for (int32_T iac{localB->iaii + 85}; iac <= jy; iac += 85) {
              localB->ix_l5 = localB->iaii;
              localB->c_ld = 0.0;
              e = iac + localB->lastv_o;
              for (b_ia = iac; b_ia <= e; b_ia++) {
                localB->c_ld += obj->Q[b_ia - 1] * obj->Q[localB->ix_l5 - 1];
                localB->ix_l5++;
              }

              localB->work_f[coltop] += localB->c_ld;
              coltop++;
            }
          }

          if (!(-obj->tau[localB->itau] == 0.0)) {
            coltop = localB->iaii + 84;
            jy = 0;
            for (int32_T iac{0}; iac <= localB->lastc_h; iac++) {
              if (localB->work_f[jy] != 0.0) {
                localB->c_ld = localB->work_f[jy] * -obj->tau[localB->itau];
                localB->ix_l5 = localB->iaii;
                e = coltop;
                b_ia = localB->lastv_o + coltop;
                while (e + 1 <= b_ia + 1) {
                  obj->Q[e] += obj->Q[localB->ix_l5 - 1] * localB->c_ld;
                  localB->ix_l5++;
                  e++;
                }
              }

              jy++;
              coltop += 85;
            }
          }
        }
      }

      if (i < localB->idx_e) {
        localB->lastv_o = (localB->iaii + localB->idx_e) - i;
        localB->lastc_h = localB->iaii;
        while (localB->lastc_h + 1 <= localB->lastv_o) {
          obj->Q[localB->lastc_h] *= -obj->tau[localB->itau];
          localB->lastc_h++;
        }
      }

      obj->Q[localB->iaii - 1] = 1.0 - obj->tau[localB->itau];
      localB->lastv_o = 0;
      while (localB->lastv_o <= i - 2) {
        obj->Q[(localB->iaii - localB->lastv_o) - 2] = 0.0;
        localB->lastv_o++;
      }

      localB->itau--;
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_IndexOfDependentEq_(int32_T depIdx[253], int32_T mFixed,
  int32_T nDep, sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *qrmanager, int32_T mRows,
  int32_T nCols, B_MPC_controller_ros_code_T *localB)
{
  localB->b_idx_m = 0;
  while (localB->b_idx_m <= mFixed - 1) {
    qrmanager->jpvt[localB->b_idx_m] = 1;
    localB->b_idx_m++;
  }

  localB->b_idx_m = mFixed;
  while (localB->b_idx_m + 1 <= nCols) {
    qrmanager->jpvt[localB->b_idx_m] = 0;
    localB->b_idx_m++;
  }

  ros_code_factorQRE(qrmanager, mRows, nCols, localB);
  localB->b_idx_m = 0;
  while (localB->b_idx_m <= nDep - 1) {
    depIdx[localB->b_idx_m] = qrmanager->jpvt[(nCols - nDep) + localB->b_idx_m];
    localB->b_idx_m++;
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_countsort(int32_T x[253], int32_T xLen, int32_T workspace
  [253], int32_T xMin, int32_T xMax)
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
    for (int32_T b_idxW{0}; b_idxW < b_tmp; b_idxW++) {
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
static void ros_code_removeConstr(sU7yup9HkfLOO3uVZruoOBF_ros_c_T *obj, int32_T
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
  for (int32_T b_idx{0}; b_idx < obj->nVar; b_idx++) {
    obj->ATwset[b_idx + 85 * (idx_global - 1)] = obj->ATwset[85 *
      idx_global_start_tmp_tmp + b_idx];
  }

  obj->bwset[idx_global - 1] = obj->bwset[idx_global_start_tmp_tmp];
  obj->nActiveConstr--;
  obj->nWConstr[TYPE_tmp]--;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_removeEqConstr(sU7yup9HkfLOO3uVZruoOBF_ros_c_T *obj,
  int32_T idx_global, B_MPC_controller_ros_code_T *localB)
{
  localB->totalEq = (obj->nWConstr[0] + obj->nWConstr[1]) - 1;
  if ((localB->totalEq + 1 != 0) && (idx_global <= localB->totalEq + 1)) {
    if ((localB->totalEq + 1 == obj->nActiveConstr) || (localB->totalEq + 1 ==
         idx_global)) {
      obj->mEqRemoved++;
      ros_code_removeConstr(obj, idx_global);
    } else {
      int32_T TYPE_tmp_tmp;
      int32_T b_idx;
      obj->mEqRemoved++;
      TYPE_tmp_tmp = obj->Wid[idx_global - 1] - 1;
      obj->isActiveConstr[(obj->isActiveIdx[TYPE_tmp_tmp] + obj->
                           Wlocalidx[idx_global - 1]) - 2] = false;
      obj->Wid[idx_global - 1] = obj->Wid[localB->totalEq];
      obj->Wlocalidx[idx_global - 1] = obj->Wlocalidx[localB->totalEq];
      for (b_idx = 0; b_idx < obj->nVar; b_idx++) {
        obj->ATwset[b_idx + 85 * (idx_global - 1)] = obj->ATwset[85 *
          localB->totalEq + b_idx];
      }

      obj->bwset[idx_global - 1] = obj->bwset[localB->totalEq];
      b_idx = obj->nActiveConstr - 1;
      obj->Wid[localB->totalEq] = obj->Wid[obj->nActiveConstr - 1];
      obj->Wlocalidx[localB->totalEq] = obj->Wlocalidx[b_idx];
      for (int32_T d_idx{0}; d_idx < obj->nVar; d_idx++) {
        obj->ATwset[d_idx + 85 * localB->totalEq] = obj->ATwset[85 * b_idx +
          d_idx];
      }

      obj->bwset[localB->totalEq] = obj->bwset[b_idx];
      obj->nActiveConstr--;
      obj->nWConstr[TYPE_tmp_tmp]--;
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_RemoveDependentEq_(sIBsEwkwZMwV16lGx5frI7G_ros_c_T
  *memspace, sU7yup9HkfLOO3uVZruoOBF_ros_c_T *workingset, int32_T *nDepInd,
  sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *qrmanager, B_MPC_controller_ros_code_T
  *localB)
{
  qrmanager->ldq = 85;
  std::memset(&qrmanager->QR[0], 0, 21505U * sizeof(real_T));
  std::memset(&qrmanager->Q[0], 0, 7225U * sizeof(real_T));
  std::memset(&qrmanager->jpvt[0], 0, 253U * sizeof(int32_T));
  qrmanager->mrows = 0;
  qrmanager->ncols = 0;
  std::memset(&qrmanager->tau[0], 0, 85U * sizeof(real_T));
  qrmanager->minRowCol = 0;
  qrmanager->usedPivoting = false;
  localB->i_p = workingset->nVar - 1;
  localB->mWorkingFixed = workingset->nWConstr[0] - 1;
  *nDepInd = 0;
  if (workingset->nWConstr[0] > 0) {
    localB->totalRank_m = 0;
    while (localB->totalRank_m <= localB->mWorkingFixed) {
      localB->ix_m = 0;
      while (localB->ix_m <= localB->i_p) {
        qrmanager->QR[localB->totalRank_m + 85 * localB->ix_m] =
          workingset->ATwset[85 * localB->totalRank_m + localB->ix_m];
        localB->ix_m++;
      }

      localB->totalRank_m++;
    }

    *nDepInd = workingset->nWConstr[0] - workingset->nVar;
    if (*nDepInd <= 0) {
      *nDepInd = 0;
    }

    localB->totalRank_m = 0;
    while (localB->totalRank_m <= localB->i_p) {
      qrmanager->jpvt[localB->totalRank_m] = 0;
      localB->totalRank_m++;
    }

    ros_code_factorQRE(qrmanager, workingset->nWConstr[0], workingset->nVar,
                       localB);
    localB->tol_d = 100.0 * static_cast<real_T>(workingset->nVar) *
      2.2204460492503131E-16;
    if (workingset->nVar <= workingset->nWConstr[0]) {
      localB->totalRank_m = workingset->nVar;
    } else {
      localB->totalRank_m = workingset->nWConstr[0];
    }

    localB->totalRank_m += (localB->totalRank_m - 1) * 85;
    while ((localB->totalRank_m > 0) && (std::abs(qrmanager->QR
             [localB->totalRank_m - 1]) < localB->tol_d)) {
      localB->totalRank_m -= 86;
      (*nDepInd)++;
    }

    if (*nDepInd > 0) {
      boolean_T exitg1;
      ros_code_computeQ_(qrmanager, qrmanager->mrows, localB);
      localB->totalRank_m = 0;
      exitg1 = false;
      while ((!exitg1) && (localB->totalRank_m <= *nDepInd - 1)) {
        localB->ix_m = (localB->mWorkingFixed - localB->totalRank_m) * 85;
        localB->qtb_g = 0.0;
        localB->iy_c = 0;
        localB->b_k_f = 0;
        while (localB->b_k_f <= localB->mWorkingFixed) {
          localB->qtb_g += qrmanager->Q[localB->ix_m] * workingset->bwset
            [localB->iy_c];
          localB->ix_m++;
          localB->iy_c++;
          localB->b_k_f++;
        }

        if (std::abs(localB->qtb_g) >= localB->tol_d) {
          *nDepInd = -1;
          exitg1 = true;
        } else {
          localB->totalRank_m++;
        }
      }
    }

    if (*nDepInd > 0) {
      localB->totalRank_m = 0;
      while (localB->totalRank_m <= localB->mWorkingFixed) {
        localB->ix_m = 85 * localB->totalRank_m;
        localB->iy_c = 1;
        while (localB->iy_c - 1 <= localB->i_p) {
          localB->b_k_f = (localB->ix_m + localB->iy_c) - 1;
          qrmanager->QR[localB->b_k_f] = workingset->ATwset[localB->b_k_f];
          localB->iy_c++;
        }

        localB->totalRank_m++;
      }

      ros_code_IndexOfDependentEq_(memspace->workspace_int, workingset->
        nWConstr[0], *nDepInd, qrmanager, workingset->nVar, workingset->
        nWConstr[0], localB);
      ros_code_countsort(memspace->workspace_int, *nDepInd,
                         memspace->workspace_sort, 1, workingset->nWConstr[0]);
      localB->i_p = *nDepInd;
      while (localB->i_p > 0) {
        ros_code_removeEqConstr(workingset, memspace->workspace_int[localB->i_p
          - 1], localB);
        localB->i_p--;
      }
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_RemoveDependentIneq_(sU7yup9HkfLOO3uVZruoOBF_ros_c_T
  *workingset, sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *qrmanager,
  sIBsEwkwZMwV16lGx5frI7G_ros_c_T *memspace, real_T tolfactor,
  B_MPC_controller_ros_code_T *localB)
{
  localB->nFixedConstr = workingset->nWConstr[0] + workingset->nWConstr[1];
  localB->nVar_o = workingset->nVar;
  if ((workingset->nWConstr[2] + workingset->nWConstr[3]) + workingset->
      nWConstr[4] > 0) {
    localB->tol_b = tolfactor * static_cast<real_T>(workingset->nVar) *
      2.2204460492503131E-16;
    localB->nDepIneq = 0;
    while (localB->nDepIneq <= localB->nFixedConstr - 1) {
      qrmanager->jpvt[localB->nDepIneq] = 1;
      localB->nDepIneq++;
    }

    localB->nDepIneq = localB->nFixedConstr + 1;
    while (localB->nDepIneq <= workingset->nActiveConstr) {
      qrmanager->jpvt[localB->nDepIneq - 1] = 0;
      localB->nDepIneq++;
    }

    localB->nDepIneq = 0;
    while (localB->nDepIneq <= workingset->nActiveConstr - 1) {
      localB->idx_b = 85 * localB->nDepIneq;
      localB->k_a = 1;
      while (localB->k_a - 1 <= localB->nVar_o - 1) {
        localB->i1 = (localB->idx_b + localB->k_a) - 1;
        qrmanager->QR[localB->i1] = workingset->ATwset[localB->i1];
        localB->k_a++;
      }

      localB->nDepIneq++;
    }

    ros_code_factorQRE(qrmanager, workingset->nVar, workingset->nActiveConstr,
                       localB);
    localB->nDepIneq = 0;
    localB->idx_b = workingset->nActiveConstr - 1;
    while (localB->idx_b + 1 > localB->nVar_o) {
      localB->nDepIneq++;
      memspace->workspace_int[localB->nDepIneq - 1] = qrmanager->jpvt
        [localB->idx_b];
      localB->idx_b--;
    }

    if (localB->idx_b + 1 <= workingset->nVar) {
      localB->nVar_o = 85 * localB->idx_b + localB->idx_b;
      while ((localB->idx_b + 1 > localB->nFixedConstr) && (std::abs
              (qrmanager->QR[localB->nVar_o]) < localB->tol_b)) {
        localB->nDepIneq++;
        memspace->workspace_int[localB->nDepIneq - 1] = qrmanager->jpvt
          [localB->idx_b];
        localB->idx_b--;
        localB->nVar_o -= 86;
      }
    }

    ros_code_countsort(memspace->workspace_int, localB->nDepIneq,
                       memspace->workspace_sort, localB->nFixedConstr + 1,
                       workingset->nActiveConstr);
    while (localB->nDepIneq > 0) {
      ros_code_removeConstr(workingset, memspace->workspace_int[localB->nDepIneq
                            - 1]);
      localB->nDepIneq--;
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_removeAllIneqConstr(sU7yup9HkfLOO3uVZruoOBF_ros_c_T *obj)
{
  for (int32_T idx_global{obj->nWConstr[0] + obj->nWConstr[1]}; idx_global <
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
static void ros_code_factorQR(sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *obj, const real_T
  A[21505], int32_T mrows, int32_T ncols, B_MPC_controller_ros_code_T *localB)
{
  boolean_T guard1{ false };

  localB->ix0_tmp = mrows * ncols;
  guard1 = false;
  if (localB->ix0_tmp > 0) {
    localB->i_i = 0;
    while (localB->i_i <= ncols - 1) {
      localB->ix0_tmp = 85 * localB->i_i;
      localB->k_f = 1;
      while (localB->k_f - 1 <= mrows - 1) {
        localB->i_f = (localB->ix0_tmp + localB->k_f) - 1;
        obj->QR[localB->i_f] = A[localB->i_f];
        localB->k_f++;
      }

      localB->i_i++;
    }

    guard1 = true;
  } else if (localB->ix0_tmp == 0) {
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
    localB->i_i = 0;
    while (localB->i_i <= ncols - 1) {
      obj->jpvt[localB->i_i] = localB->i_i + 1;
      localB->i_i++;
    }

    if (mrows <= ncols) {
      localB->ix0_tmp = mrows;
    } else {
      localB->ix0_tmp = ncols;
    }

    obj->minRowCol = localB->ix0_tmp;
    std::memset(&obj->tau[0], 0, 85U * sizeof(real_T));
    if (localB->ix0_tmp >= 1) {
      std::memset(&obj->tau[0], 0, 85U * sizeof(real_T));
      ros_code_qrf(obj->QR, mrows, ncols, localB->ix0_tmp, obj->tau, localB);
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static real_T ros_code_maxConstraintViolation(sU7yup9HkfLOO3uVZruoOBF_ros_c_T
  *obj, const real_T x[21505], B_MPC_controller_ros_code_T *localB)
{
  real_T v;
  int32_T mFixed;
  int32_T mUB;
  localB->mLB_f = obj->sizes[3];
  mUB = obj->sizes[4];
  mFixed = obj->sizes[0];
  if (obj->probType == 2) {
    v = 0.0;
    for (int32_T k{0}; k < 84; k++) {
      obj->maxConstrWorkspace[k] = obj->bineq[k];
      obj->maxConstrWorkspace[k] = -obj->maxConstrWorkspace[k];
    }

    for (int32_T k{0}; k <= 7056; k += 85) {
      int32_T ix;
      ix = 0;
      localB->c_a = 0.0;
      for (int32_T b{k}; b < k + 84; b++) {
        localB->c_a += obj->Aineq[b] * x[ix];
        ix++;
      }

      ix = div_nde_s32_floor(k, 85);
      obj->maxConstrWorkspace[ix] += localB->c_a;
    }

    for (int32_T k{0}; k < 84; k++) {
      obj->maxConstrWorkspace[k] -= x[k + 84];
      v = std::fmax(v, obj->maxConstrWorkspace[k]);
    }
  } else {
    v = 0.0;
    for (int32_T k{0}; k < 84; k++) {
      obj->maxConstrWorkspace[k] = obj->bineq[k];
      obj->maxConstrWorkspace[k] = -obj->maxConstrWorkspace[k];
    }

    for (int32_T k{0}; k <= 7056; k += 85) {
      int32_T b;
      int32_T ix;
      ix = 0;
      localB->c_a = 0.0;
      b = k + obj->nVar;
      for (int32_T ia{k}; ia < b; ia++) {
        localB->c_a += obj->Aineq[ia] * x[ix];
        ix++;
      }

      ix = div_nde_s32_floor(k, 85);
      obj->maxConstrWorkspace[ix] += localB->c_a;
    }

    for (int32_T k{0}; k < 84; k++) {
      v = std::fmax(v, obj->maxConstrWorkspace[k]);
    }
  }

  if (localB->mLB_f > 0) {
    for (int32_T k{0}; k < localB->mLB_f; k++) {
      v = std::fmax(v, -x[obj->indexLB[k] - 1] - obj->lb[obj->indexLB[k] - 1]);
    }
  }

  if (mUB > 0) {
    localB->mLB_f = 0;
    while (localB->mLB_f <= mUB - 1) {
      v = std::fmax(v, x[obj->indexUB[localB->mLB_f] - 1] - obj->ub[obj->
                    indexUB[localB->mLB_f] - 1]);
      localB->mLB_f++;
    }
  }

  if (mFixed > 0) {
    for (mUB = 0; mUB < mFixed; mUB++) {
      v = std::fmax(v, std::abs(x[obj->indexFixed[mUB] - 1] - obj->ub
        [obj->indexFixed[mUB] - 1]));
    }
  }

  return v;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static real_T ros_co_maxConstraintViolation_l(sU7yup9HkfLOO3uVZruoOBF_ros_c_T
  *obj, const real_T x[21505], B_MPC_controller_ros_code_T *localB)
{
  real_T v;
  int32_T mFixed;
  int32_T mUB;
  localB->mLB_e = obj->sizes[3];
  mUB = obj->sizes[4];
  mFixed = obj->sizes[0];
  if (obj->probType == 2) {
    v = 0.0;
    for (int32_T k{0}; k < 84; k++) {
      obj->maxConstrWorkspace[k] = obj->bineq[k];
      obj->maxConstrWorkspace[k] = -obj->maxConstrWorkspace[k];
    }

    for (int32_T k{0}; k <= 7056; k += 85) {
      int32_T ix;
      ix = 253;
      localB->c_f = 0.0;
      for (int32_T b{k}; b < k + 84; b++) {
        localB->c_f += obj->Aineq[b] * x[ix];
        ix++;
      }

      ix = div_nde_s32_floor(k, 85);
      obj->maxConstrWorkspace[ix] += localB->c_f;
    }

    for (int32_T k{0}; k < 84; k++) {
      obj->maxConstrWorkspace[k] -= x[k + 337];
      v = std::fmax(v, obj->maxConstrWorkspace[k]);
    }
  } else {
    v = 0.0;
    for (int32_T k{0}; k < 84; k++) {
      obj->maxConstrWorkspace[k] = obj->bineq[k];
      obj->maxConstrWorkspace[k] = -obj->maxConstrWorkspace[k];
    }

    for (int32_T k{0}; k <= 7056; k += 85) {
      int32_T b;
      int32_T ix;
      ix = 253;
      localB->c_f = 0.0;
      b = k + obj->nVar;
      for (int32_T ia{k}; ia < b; ia++) {
        localB->c_f += obj->Aineq[ia] * x[ix];
        ix++;
      }

      ix = div_nde_s32_floor(k, 85);
      obj->maxConstrWorkspace[ix] += localB->c_f;
    }

    for (int32_T k{0}; k < 84; k++) {
      v = std::fmax(v, obj->maxConstrWorkspace[k]);
    }
  }

  if (localB->mLB_e > 0) {
    for (int32_T k{0}; k < localB->mLB_e; k++) {
      v = std::fmax(v, -x[obj->indexLB[k] + 252] - obj->lb[obj->indexLB[k] - 1]);
    }
  }

  if (mUB > 0) {
    localB->mLB_e = 0;
    while (localB->mLB_e <= mUB - 1) {
      v = std::fmax(v, x[obj->indexUB[localB->mLB_e] + 252] - obj->ub
                    [obj->indexUB[localB->mLB_e] - 1]);
      localB->mLB_e++;
    }
  }

  if (mFixed > 0) {
    for (mUB = 0; mUB < mFixed; mUB++) {
      v = std::fmax(v, std::abs(x[obj->indexFixed[mUB] + 252] - obj->ub
        [obj->indexFixed[mUB] - 1]));
    }
  }

  return v;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static boolean_T ros_cod_feasibleX0ForWorkingSet(real_T workspace[21505], real_T
  xCurrent[85], sU7yup9HkfLOO3uVZruoOBF_ros_c_T *workingset,
  sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *qrmanager, B_MPC_controller_ros_code_T
  *localB)
{
  boolean_T nonDegenerateWset;
  localB->mWConstr_tmp_tmp = workingset->nActiveConstr - 1;
  localB->nVar_tmp_tmp_i = workingset->nVar;
  nonDegenerateWset = true;
  if (workingset->nActiveConstr != 0) {
    localB->iy_o = 0;
    while (localB->iy_o <= localB->mWConstr_tmp_tmp) {
      workspace[localB->iy_o] = workingset->bwset[localB->iy_o];
      workspace[localB->iy_o + 253] = workingset->bwset[localB->iy_o];
      localB->iy_o++;
    }

    if (workingset->nActiveConstr != 0) {
      localB->iy_o = 0;
      localB->iAcol = (workingset->nActiveConstr - 1) * 85 + 1;
      localB->b_ia = 1;
      while (localB->b_ia <= localB->iAcol) {
        localB->ix_l = 0;
        localB->c = 0.0;
        localB->d = (localB->b_ia + localB->nVar_tmp_tmp_i) - 1;
        localB->ia_o = localB->b_ia;
        while (localB->ia_o <= localB->d) {
          localB->c += workingset->ATwset[localB->ia_o - 1] * xCurrent
            [localB->ix_l];
          localB->ix_l++;
          localB->ia_o++;
        }

        workspace[localB->iy_o] += -localB->c;
        localB->iy_o++;
        localB->b_ia += 85;
      }
    }

    if (workingset->nActiveConstr >= workingset->nVar) {
      localB->iy_o = 0;
      while (localB->iy_o <= localB->nVar_tmp_tmp_i - 1) {
        localB->iAcol = 85 * localB->iy_o;
        localB->b_ia = 0;
        while (localB->b_ia <= localB->mWConstr_tmp_tmp) {
          qrmanager->QR[localB->b_ia + localB->iAcol] = workingset->ATwset[85 *
            localB->b_ia + localB->iy_o];
          localB->b_ia++;
        }

        localB->iy_o++;
      }

      qrmanager->usedPivoting = false;
      qrmanager->mrows = workingset->nActiveConstr;
      qrmanager->ncols = workingset->nVar;
      localB->iy_o = 0;
      while (localB->iy_o <= localB->nVar_tmp_tmp_i - 1) {
        qrmanager->jpvt[localB->iy_o] = localB->iy_o + 1;
        localB->iy_o++;
      }

      if (workingset->nActiveConstr <= workingset->nVar) {
        localB->iAcol = workingset->nActiveConstr;
      } else {
        localB->iAcol = workingset->nVar;
      }

      qrmanager->minRowCol = localB->iAcol;
      std::memcpy(&localB->B[0], &qrmanager->QR[0], 21505U * sizeof(real_T));
      std::memset(&qrmanager->tau[0], 0, 85U * sizeof(real_T));
      if (localB->iAcol >= 1) {
        std::memset(&qrmanager->tau[0], 0, 85U * sizeof(real_T));
        ros_code_qrf(localB->B, workingset->nActiveConstr, workingset->nVar,
                     localB->iAcol, qrmanager->tau, localB);
      }

      std::memcpy(&qrmanager->QR[0], &localB->B[0], 21505U * sizeof(real_T));
      ros_code_computeQ_(qrmanager, qrmanager->mrows, localB);
      std::memcpy(&localB->B[0], &workspace[0], 21505U * sizeof(real_T));
      localB->iy_o = 0;
      while (localB->iy_o + 1 <= localB->nVar_tmp_tmp_i) {
        workspace[localB->iy_o] = 0.0;
        localB->iy_o++;
      }

      localB->iy_o = 253;
      while (localB->iy_o + 1 <= localB->nVar_tmp_tmp_i + 253) {
        workspace[localB->iy_o] = 0.0;
        localB->iy_o++;
      }

      localB->iy_o = -1;
      localB->iAcol = 0;
      while (localB->iAcol + 1 <= localB->nVar_tmp_tmp_i) {
        localB->c = 0.0;
        localB->b_ia = 1;
        while (localB->b_ia - 1 <= localB->mWConstr_tmp_tmp) {
          localB->c += qrmanager->Q[localB->b_ia + localB->iy_o] * localB->
            B[localB->b_ia + -1];
          localB->b_ia++;
        }

        workspace[localB->iAcol] += localB->c;
        localB->iy_o += 85;
        localB->iAcol++;
      }

      localB->iy_o = -1;
      localB->iAcol = 253;
      while (localB->iAcol + 1 <= localB->nVar_tmp_tmp_i + 253) {
        localB->c = 0.0;
        localB->b_ia = 1;
        while (localB->b_ia - 1 <= localB->mWConstr_tmp_tmp) {
          localB->c += qrmanager->Q[localB->b_ia + localB->iy_o] * localB->
            B[localB->b_ia + 252];
          localB->b_ia++;
        }

        workspace[localB->iAcol] += localB->c;
        localB->iy_o += 85;
        localB->iAcol++;
      }

      localB->mWConstr_tmp_tmp = workingset->nVar;
      while (localB->mWConstr_tmp_tmp > 0) {
        localB->iy_o = (localB->mWConstr_tmp_tmp - 1) * 85 - 1;
        if (workspace[localB->mWConstr_tmp_tmp + -1] != 0.0) {
          workspace[localB->mWConstr_tmp_tmp + -1] /= qrmanager->QR
            [localB->mWConstr_tmp_tmp + localB->iy_o];
          localB->iAcol = 1;
          while (localB->iAcol - 1 <= localB->mWConstr_tmp_tmp - 2) {
            workspace[localB->iAcol + -1] -= workspace[localB->mWConstr_tmp_tmp
              + -1] * qrmanager->QR[localB->iAcol + localB->iy_o];
            localB->iAcol++;
          }
        }

        localB->mWConstr_tmp_tmp--;
      }

      localB->mWConstr_tmp_tmp = workingset->nVar;
      while (localB->mWConstr_tmp_tmp > 0) {
        localB->iy_o = (localB->mWConstr_tmp_tmp - 1) * 85 - 1;
        localB->c = workspace[localB->mWConstr_tmp_tmp + 252];
        if (localB->c != 0.0) {
          workspace[localB->mWConstr_tmp_tmp + 252] = localB->c / qrmanager->
            QR[localB->mWConstr_tmp_tmp + localB->iy_o];
          localB->iAcol = 1;
          while (localB->iAcol - 1 <= localB->mWConstr_tmp_tmp - 2) {
            workspace[localB->iAcol + 252] -= workspace[localB->mWConstr_tmp_tmp
              + 252] * qrmanager->QR[localB->iAcol + localB->iy_o];
            localB->iAcol++;
          }
        }

        localB->mWConstr_tmp_tmp--;
      }
    } else {
      ros_code_factorQR(qrmanager, workingset->ATwset, workingset->nVar,
                        workingset->nActiveConstr, localB);
      ros_code_computeQ_(qrmanager, qrmanager->minRowCol, localB);
      localB->iy_o = 1;
      while (localB->iy_o - 1 <= localB->mWConstr_tmp_tmp) {
        localB->iAcol = (localB->iy_o - 1) * 85 - 1;
        localB->c = workspace[localB->iy_o + -1];
        localB->b_ia = 1;
        while (localB->b_ia - 1 <= localB->iy_o - 2) {
          localB->c -= qrmanager->QR[localB->b_ia + localB->iAcol] *
            workspace[localB->b_ia + -1];
          localB->b_ia++;
        }

        workspace[localB->iy_o + -1] = localB->c / qrmanager->QR[localB->iy_o +
          localB->iAcol];
        localB->iy_o++;
      }

      localB->iy_o = 1;
      while (localB->iy_o - 1 <= localB->mWConstr_tmp_tmp) {
        localB->iAcol = (localB->iy_o - 1) * 85 - 1;
        localB->c = workspace[localB->iy_o + 252];
        localB->b_ia = 1;
        while (localB->b_ia - 1 <= localB->iy_o - 2) {
          localB->c -= qrmanager->QR[localB->b_ia + localB->iAcol] *
            workspace[localB->b_ia + 252];
          localB->b_ia++;
        }

        workspace[localB->iy_o + 252] = localB->c / qrmanager->QR[localB->iy_o +
          localB->iAcol];
        localB->iy_o++;
      }

      std::memcpy(&localB->B[0], &workspace[0], 21505U * sizeof(real_T));
      localB->iy_o = 0;
      while (localB->iy_o + 1 <= localB->nVar_tmp_tmp_i) {
        workspace[localB->iy_o] = 0.0;
        localB->iy_o++;
      }

      localB->iy_o = 253;
      while (localB->iy_o + 1 <= localB->nVar_tmp_tmp_i + 253) {
        workspace[localB->iy_o] = 0.0;
        localB->iy_o++;
      }

      localB->iy_o = -1;
      localB->iAcol = 1;
      while (localB->iAcol <= localB->mWConstr_tmp_tmp + 1) {
        localB->b_ia = localB->iy_o;
        localB->ix_l = 0;
        while (localB->ix_l + 1 <= localB->nVar_tmp_tmp_i) {
          localB->b_ia++;
          workspace[localB->ix_l] += localB->B[localB->iAcol - 1] * qrmanager->
            Q[localB->b_ia];
          localB->ix_l++;
        }

        localB->iy_o += 85;
        localB->iAcol++;
      }

      localB->iy_o = -1;
      localB->iAcol = 254;
      while (localB->iAcol <= localB->mWConstr_tmp_tmp + 254) {
        localB->b_ia = localB->iy_o;
        localB->ix_l = 253;
        while (localB->ix_l + 1 <= localB->nVar_tmp_tmp_i + 253) {
          localB->b_ia++;
          workspace[localB->ix_l] += localB->B[localB->iAcol - 1] * qrmanager->
            Q[localB->b_ia];
          localB->ix_l++;
        }

        localB->iy_o += 85;
        localB->iAcol++;
      }
    }

    localB->mWConstr_tmp_tmp = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (localB->mWConstr_tmp_tmp <= localB->nVar_tmp_tmp_i - 1) {
        if (std::isinf(workspace[localB->mWConstr_tmp_tmp]) || std::isnan
            (workspace[localB->mWConstr_tmp_tmp])) {
          nonDegenerateWset = false;
          exitg1 = 1;
        } else {
          localB->c = workspace[localB->mWConstr_tmp_tmp + 253];
          if (std::isinf(localB->c) || std::isnan(localB->c)) {
            nonDegenerateWset = false;
            exitg1 = 1;
          } else {
            localB->mWConstr_tmp_tmp++;
          }
        }
      } else {
        localB->mWConstr_tmp_tmp = 0;
        while (localB->mWConstr_tmp_tmp <= localB->nVar_tmp_tmp_i - 1) {
          workspace[localB->mWConstr_tmp_tmp] += xCurrent
            [localB->mWConstr_tmp_tmp];
          localB->mWConstr_tmp_tmp++;
        }

        localB->c = ros_code_maxConstraintViolation(workingset, workspace,
          localB);
        localB->constrViolation_basicX = ros_co_maxConstraintViolation_l
          (workingset, workspace, localB);
        if ((localB->c <= 2.2204460492503131E-16) || (localB->c <
             localB->constrViolation_basicX)) {
          localB->mWConstr_tmp_tmp = 0;
          while (localB->mWConstr_tmp_tmp <= localB->nVar_tmp_tmp_i - 1) {
            xCurrent[localB->mWConstr_tmp_tmp] = workspace
              [localB->mWConstr_tmp_tmp];
            localB->mWConstr_tmp_tmp++;
          }
        } else {
          localB->mWConstr_tmp_tmp = 0;
          while (localB->mWConstr_tmp_tmp <= localB->nVar_tmp_tmp_i - 1) {
            xCurrent[localB->mWConstr_tmp_tmp] = workspace
              [localB->mWConstr_tmp_tmp + 253];
            localB->mWConstr_tmp_tmp++;
          }
        }

        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return nonDegenerateWset;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static real_T ros_c_maxConstraintViolation_la(sU7yup9HkfLOO3uVZruoOBF_ros_c_T
  *obj, const real_T x[85], B_MPC_controller_ros_code_T *localB)
{
  real_T v;
  int32_T mFixed;
  int32_T mUB;
  localB->mLB = obj->sizes[3];
  mUB = obj->sizes[4];
  mFixed = obj->sizes[0];
  if (obj->probType == 2) {
    v = 0.0;
    for (int32_T k{0}; k < 84; k++) {
      obj->maxConstrWorkspace[k] = obj->bineq[k];
      obj->maxConstrWorkspace[k] = -obj->maxConstrWorkspace[k];
    }

    for (int32_T k{0}; k <= 7056; k += 85) {
      int32_T ix;
      ix = 0;
      localB->c_j = 0.0;
      for (int32_T b{k}; b < k + 84; b++) {
        localB->c_j += obj->Aineq[b] * x[ix];
        ix++;
      }

      ix = div_nde_s32_floor(k, 85);
      obj->maxConstrWorkspace[ix] += localB->c_j;
    }

    for (int32_T k{0}; k < 84; k++) {
      obj->maxConstrWorkspace[k] -= x[84];
      v = std::fmax(v, obj->maxConstrWorkspace[k]);
    }
  } else {
    v = 0.0;
    for (int32_T k{0}; k < 84; k++) {
      obj->maxConstrWorkspace[k] = obj->bineq[k];
      obj->maxConstrWorkspace[k] = -obj->maxConstrWorkspace[k];
    }

    for (int32_T k{0}; k <= 7056; k += 85) {
      int32_T b;
      int32_T ix;
      ix = 0;
      localB->c_j = 0.0;
      b = k + obj->nVar;
      for (int32_T ia{k}; ia < b; ia++) {
        localB->c_j += obj->Aineq[ia] * x[ix];
        ix++;
      }

      ix = div_nde_s32_floor(k, 85);
      obj->maxConstrWorkspace[ix] += localB->c_j;
    }

    for (int32_T k{0}; k < 84; k++) {
      v = std::fmax(v, obj->maxConstrWorkspace[k]);
    }
  }

  if (localB->mLB > 0) {
    for (int32_T k{0}; k < localB->mLB; k++) {
      v = std::fmax(v, -x[obj->indexLB[k] - 1] - obj->lb[obj->indexLB[k] - 1]);
    }
  }

  if (mUB > 0) {
    localB->mLB = 0;
    while (localB->mLB <= mUB - 1) {
      v = std::fmax(v, x[obj->indexUB[localB->mLB] - 1] - obj->ub[obj->
                    indexUB[localB->mLB] - 1]);
      localB->mLB++;
    }
  }

  if (mFixed > 0) {
    for (mUB = 0; mUB < mFixed; mUB++) {
      v = std::fmax(v, std::abs(x[obj->indexFixed[mUB] - 1] - obj->ub
        [obj->indexFixed[mUB] - 1]));
    }
  }

  return v;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_PresolveWorkingSet(sizV6IUWKAiWqwEIFf7P38E_ros_c_T
  *solution, sIBsEwkwZMwV16lGx5frI7G_ros_c_T *memspace,
  sU7yup9HkfLOO3uVZruoOBF_ros_c_T *workingset, sxn76bLJrqJiWwjGl8YOqSB_ros_c_T
  *qrmanager, B_MPC_controller_ros_code_T *localB)
{
  solution->state = 82;
  ros_code_RemoveDependentEq_(memspace, workingset, &localB->b_l, qrmanager,
    localB);
  if ((localB->b_l != -1) && (workingset->nActiveConstr <= 85)) {
    boolean_T guard1{ false };

    boolean_T okWorkingSet;
    ros_code_RemoveDependentIneq_(workingset, qrmanager, memspace, 100.0, localB);
    okWorkingSet = ros_cod_feasibleX0ForWorkingSet(memspace->workspace_double,
      solution->xstar, workingset, qrmanager, localB);
    guard1 = false;
    if (!okWorkingSet) {
      ros_code_RemoveDependentIneq_(workingset, qrmanager, memspace, 1000.0,
        localB);
      okWorkingSet = ros_cod_feasibleX0ForWorkingSet(memspace->workspace_double,
        solution->xstar, workingset, qrmanager, localB);
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
        localB->constrViolation_j = ros_c_maxConstraintViolation_la(workingset,
          solution->xstar, localB);
        if (localB->constrViolation_j > 1.0E-8) {
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
static void ros_code_xgemv(int32_T m, int32_T n, const real_T A[7056], int32_T
  lda, const real_T x[85], real_T y[84])
{
  if ((m != 0) && (n != 0)) {
    int32_T b;
    int32_T iac;
    int32_T ix;
    for (ix = 0; ix < m; ix++) {
      y[ix] = 0.0;
    }

    ix = 0;
    b = (n - 1) * lda + 1;
    iac = 1;
    while (((lda > 0) && (iac <= b)) || ((lda < 0) && (iac >= b))) {
      int32_T c;
      int32_T iy;
      iy = 0;
      c = (iac + m) - 1;
      for (int32_T ia{iac}; ia <= c; ia++) {
        y[iy] += A[ia - 1] * x[ix];
        iy++;
      }

      ix++;
      iac += lda;
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_computeGrad_StoreHx(smUUAx65r5SQ5CSZDAURIoG_ros_c_T *obj,
  const real_T H[7056], const real_T f[84], const real_T x[85],
  B_MPC_controller_ros_code_T *localB)
{
  switch (obj->objtype) {
   case 5:
    localB->b_ixlast = 0;
    while (localB->b_ixlast <= obj->nvar - 2) {
      obj->grad[localB->b_ixlast] = 0.0;
      localB->b_ixlast++;
    }

    obj->grad[obj->nvar - 1] = obj->gammaScalar;
    break;

   case 3:
    ros_code_xgemv(obj->nvar, obj->nvar, H, obj->nvar, x, obj->Hx);
    localB->b_ixlast = 0;
    while (localB->b_ixlast <= obj->nvar - 1) {
      obj->grad[localB->b_ixlast] = obj->Hx[localB->b_ixlast];
      localB->b_ixlast++;
    }

    if (obj->hasLinear && (obj->nvar >= 1)) {
      localB->b_ixlast = obj->nvar - 1;
      localB->b_k_h = 0;
      while (localB->b_k_h <= localB->b_ixlast) {
        obj->grad[localB->b_k_h] += f[localB->b_k_h];
        localB->b_k_h++;
      }
    }
    break;

   default:
    ros_code_xgemv(obj->nvar, obj->nvar, H, obj->nvar, x, obj->Hx);
    localB->b_ixlast = obj->nvar;
    while (localB->b_ixlast + 1 < 85) {
      obj->Hx[localB->b_ixlast] = 0.0 * x[localB->b_ixlast];
      localB->b_ixlast++;
    }

    std::memcpy(&obj->grad[0], &obj->Hx[0], 84U * sizeof(real_T));
    if (obj->hasLinear && (obj->nvar >= 1)) {
      localB->b_ixlast = obj->nvar - 1;
      localB->b_k_h = 0;
      while (localB->b_k_h <= localB->b_ixlast) {
        obj->grad[localB->b_k_h] += f[localB->b_k_h];
        localB->b_k_h++;
      }
    }
    break;
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static real_T ros_code_computeFval_ReuseHx(const smUUAx65r5SQ5CSZDAURIoG_ros_c_T
  *obj, real_T workspace[21505], const real_T f[84], const real_T x[85])
{
  real_T val;
  switch (obj->objtype) {
   case 5:
    val = x[obj->nvar - 1] * obj->gammaScalar;
    break;

   case 3:
    if (obj->hasLinear) {
      for (int32_T k{0}; k < obj->nvar; k++) {
        workspace[k] = 0.5 * obj->Hx[k] + f[k];
      }

      val = 0.0;
      if (obj->nvar >= 1) {
        for (int32_T k{0}; k < obj->nvar; k++) {
          val += x[k] * workspace[k];
        }
      }
    } else {
      val = 0.0;
      if (obj->nvar >= 1) {
        for (int32_T k{0}; k < obj->nvar; k++) {
          val += x[k] * obj->Hx[k];
        }
      }

      val *= 0.5;
    }
    break;

   default:
    if (obj->hasLinear) {
      for (int32_T k{0}; k < obj->nvar; k++) {
        workspace[k] = f[k];
      }

      for (int32_T k{0}; k <= 83 - obj->nvar; k++) {
        workspace[obj->nvar + k] = 0.0;
      }

      val = 0.0;
      for (int32_T k{0}; k < 84; k++) {
        workspace[k] += 0.5 * obj->Hx[k];
        val += x[k] * workspace[k];
      }
    } else {
      val = 0.0;
      for (int32_T k{0}; k < 84; k++) {
        val += x[k] * obj->Hx[k];
      }

      val *= 0.5;
      for (int32_T k = obj->nvar; k + 1 < 85; k++) {
        val += x[k] * 0.0;
      }
    }
    break;
  }

  return val;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_xrotg(real_T *a, real_T *b, real_T *c, real_T *s,
  B_MPC_controller_ros_code_T *localB)
{
  localB->roe = *b;
  localB->absa = std::abs(*a);
  localB->absb = std::abs(*b);
  if (localB->absa > localB->absb) {
    localB->roe = *a;
  }

  localB->scale_d = localB->absa + localB->absb;
  if (localB->scale_d == 0.0) {
    *s = 0.0;
    *c = 1.0;
    *a = 0.0;
    *b = 0.0;
  } else {
    localB->ads = localB->absa / localB->scale_d;
    localB->bds = localB->absb / localB->scale_d;
    localB->scale_d *= std::sqrt(localB->ads * localB->ads + localB->bds *
      localB->bds);
    if (localB->roe < 0.0) {
      localB->scale_d = -localB->scale_d;
    }

    *c = *a / localB->scale_d;
    *s = *b / localB->scale_d;
    if (localB->absa > localB->absb) {
      *b = *s;
    } else if (*c != 0.0) {
      *b = 1.0 / *c;
    } else {
      *b = 1.0;
    }

    *a = localB->scale_d;
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_deleteColMoveEnd(sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *obj,
  int32_T idx, B_MPC_controller_ros_code_T *localB)
{
  if (obj->usedPivoting) {
    localB->i_mc = 1;
    while ((localB->i_mc <= obj->ncols) && (obj->jpvt[localB->i_mc - 1] != idx))
    {
      localB->i_mc++;
    }

    idx = localB->i_mc;
  }

  if (idx >= obj->ncols) {
    obj->ncols--;
  } else {
    obj->jpvt[idx - 1] = obj->jpvt[obj->ncols - 1];
    localB->i_mc = 0;
    while (localB->i_mc <= obj->minRowCol - 1) {
      obj->QR[localB->i_mc + 85 * (idx - 1)] = obj->QR[(obj->ncols - 1) * 85 +
        localB->i_mc];
      localB->i_mc++;
    }

    obj->ncols--;
    if (obj->mrows <= obj->ncols) {
      obj->minRowCol = obj->mrows;
    } else {
      obj->minRowCol = obj->ncols;
    }

    if (idx < obj->mrows) {
      int32_T QRk0;
      int32_T b_ix;
      int32_T c_ix;
      int32_T idxRotGCol;
      int32_T ix;
      if (obj->mrows - 1 <= obj->ncols) {
        localB->i_mc = obj->mrows - 1;
      } else {
        localB->i_mc = obj->ncols;
      }

      localB->k_h = localB->i_mc;
      idxRotGCol = (idx - 1) * 85;
      while (localB->k_h >= idx) {
        QRk0 = localB->k_h + idxRotGCol;
        localB->b_temp = obj->QR[QRk0];
        ros_code_xrotg(&obj->QR[(localB->k_h + idxRotGCol) - 1], &localB->b_temp,
                       &localB->c_c, &localB->b_s, localB);
        obj->QR[QRk0] = localB->b_temp;
        c_ix = (localB->k_h - 1) * 85;
        obj->QR[localB->k_h + c_ix] = 0.0;
        QRk0 = 85 * idx + localB->k_h;
        b_ix = obj->ncols - idx;
        if (b_ix >= 1) {
          ix = QRk0 - 1;
          for (int32_T d_k{0}; d_k < b_ix; d_k++) {
            localB->b_temp = localB->c_c * obj->QR[ix] + localB->b_s * obj->
              QR[QRk0];
            obj->QR[QRk0] = localB->c_c * obj->QR[QRk0] - localB->b_s * obj->
              QR[ix];
            obj->QR[ix] = localB->b_temp;
            QRk0 += 85;
            ix += 85;
          }
        }

        if (obj->mrows >= 1) {
          QRk0 = c_ix + 85;
          for (b_ix = 0; b_ix < obj->mrows; b_ix++) {
            localB->b_temp = localB->c_c * obj->Q[c_ix] + localB->b_s * obj->
              Q[QRk0];
            obj->Q[QRk0] = localB->c_c * obj->Q[QRk0] - localB->b_s * obj->
              Q[c_ix];
            obj->Q[c_ix] = localB->b_temp;
            QRk0++;
            c_ix++;
          }
        }

        localB->k_h--;
      }

      localB->k_h = idx + 1;
      while (localB->k_h <= localB->i_mc) {
        idxRotGCol = (localB->k_h - 1) * 85;
        QRk0 = localB->k_h + idxRotGCol;
        localB->b_temp = obj->QR[QRk0];
        ros_code_xrotg(&obj->QR[(localB->k_h + idxRotGCol) - 1], &localB->b_temp,
                       &localB->c_c, &localB->b_s, localB);
        obj->QR[QRk0] = localB->b_temp;
        QRk0 = localB->k_h * 86;
        c_ix = obj->ncols - localB->k_h;
        if (c_ix >= 1) {
          b_ix = QRk0 - 1;
          for (ix = 0; ix < c_ix; ix++) {
            localB->b_temp = localB->c_c * obj->QR[b_ix] + localB->b_s * obj->
              QR[QRk0];
            obj->QR[QRk0] = localB->c_c * obj->QR[QRk0] - localB->b_s * obj->
              QR[b_ix];
            obj->QR[b_ix] = localB->b_temp;
            QRk0 += 85;
            b_ix += 85;
          }
        }

        if (obj->mrows >= 1) {
          QRk0 = idxRotGCol + 85;
          for (c_ix = 0; c_ix < obj->mrows; c_ix++) {
            localB->b_temp = localB->c_c * obj->Q[idxRotGCol] + localB->b_s *
              obj->Q[QRk0];
            obj->Q[QRk0] = localB->c_c * obj->Q[QRk0] - localB->b_s * obj->
              Q[idxRotGCol];
            obj->Q[idxRotGCol] = localB->b_temp;
            QRk0++;
            idxRotGCol++;
          }
        }

        localB->k_h++;
      }
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_cod_computeProjectedHessian(const real_T H[7056],
  sFUo2n2eWek74Kh1Ligw2mE_ros_c_T *cholmanager, const
  sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *qrmanager, sIBsEwkwZMwV16lGx5frI7G_ros_c_T
  *memspace, B_MPC_controller_ros_code_T *localB)
{
  int32_T c;
  int32_T cr;
  int32_T ia;
  int32_T ib;
  localB->nVars = qrmanager->mrows;
  localB->mNull_e = qrmanager->mrows - qrmanager->ncols;
  localB->nullStart = 85 * qrmanager->ncols;
  if ((qrmanager->mrows != 0) && (localB->mNull_e != 0)) {
    localB->br = localB->nullStart;
    localB->lastColC = (localB->mNull_e - 1) * 253;
    for (cr = 0; cr <= localB->lastColC; cr += 253) {
      localB->ar = cr;
      ib = cr + localB->nVars;
      while (localB->ar + 1 <= ib) {
        memspace->workspace_double[localB->ar] = 0.0;
        localB->ar++;
      }
    }

    for (cr = 0; cr <= localB->lastColC; cr += 253) {
      localB->ar = -1;
      ib = localB->br;
      c = localB->br + localB->nVars;
      while (ib + 1 <= c) {
        int32_T b_ic;
        int32_T d;
        ia = localB->ar;
        b_ic = cr;
        d = cr + localB->nVars;
        while (b_ic + 1 <= d) {
          ia++;
          memspace->workspace_double[b_ic] += qrmanager->Q[ib] * H[ia];
          b_ic++;
        }

        localB->ar += localB->nVars;
        ib++;
      }

      localB->br += 85;
    }
  }

  if (localB->mNull_e != 0) {
    localB->br = (localB->mNull_e - 1) * 85;
    localB->lastColC = 0;
    while (localB->lastColC <= localB->br) {
      cr = localB->lastColC;
      localB->ar = localB->lastColC + localB->mNull_e;
      while (cr + 1 <= localB->ar) {
        cholmanager->FMat[cr] = 0.0;
        cr++;
      }

      localB->lastColC += 85;
    }

    localB->lastColC = -1;
    for (cr = 0; cr <= localB->br; cr += 85) {
      localB->ar = localB->nullStart;
      ib = cr;
      c = cr + localB->mNull_e;
      while (ib + 1 <= c) {
        localB->temp_l = 0.0;
        for (ia = 1; ia - 1 < localB->nVars; ia++) {
          localB->temp_l += qrmanager->Q[(ia + localB->ar) - 1] *
            memspace->workspace_double[ia + localB->lastColC];
        }

        cholmanager->FMat[ib] += localB->temp_l;
        localB->ar += 85;
        ib++;
      }

      localB->lastColC += 253;
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_xgemv_n(int32_T m, int32_T n, const real_T A[7225], int32_T
  ia0, const real_T x[21505], real_T y[85])
{
  if (m != 0) {
    int32_T b;
    int32_T ix;
    for (ix = 0; ix < m; ix++) {
      y[ix] = 0.0;
    }

    ix = 0;
    b = (n - 1) * 85 + ia0;
    for (int32_T iac{ia0}; iac <= b; iac += 85) {
      int32_T c;
      int32_T iy;
      iy = 0;
      c = (iac + m) - 1;
      for (int32_T ia{iac}; ia <= c; ia++) {
        y[iy] += A[ia - 1] * x[ix];
        iy++;
      }

      ix++;
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static int32_T ros_code_ixamax(int32_T n, const real_T x[7225])
{
  int32_T idxmax;
  if (n < 1) {
    idxmax = 0;
  } else {
    idxmax = 1;
    if (n > 1) {
      real_T smax;
      int32_T ix;
      ix = 0;
      smax = std::abs(x[0]);
      for (int32_T k{2}; k <= n; k++) {
        real_T s;
        ix += 86;
        s = std::abs(x[ix]);
        if (s > smax) {
          idxmax = k;
          smax = s;
        }
      }
    }
  }

  return idxmax;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_fullColLDL2_(sFUo2n2eWek74Kh1Ligw2mE_ros_c_T *obj, int32_T
  NColsRemain, real_T REG_PRIMAL, B_MPC_controller_ros_code_T *localB)
{
  localB->lastDiag = 0;
  while (localB->lastDiag <= NColsRemain - 1) {
    int32_T jA;
    int32_T jy;
    localB->LD_diagOffset = 86 * localB->lastDiag;
    if (std::abs(obj->FMat[localB->LD_diagOffset]) <= obj->regTol_) {
      obj->FMat[localB->LD_diagOffset] += REG_PRIMAL;
    }

    localB->alpha1 = -1.0 / obj->FMat[localB->LD_diagOffset];
    localB->subMatrixDim = (NColsRemain - localB->lastDiag) - 2;
    for (jA = 0; jA <= localB->subMatrixDim; jA++) {
      obj->workspace_[jA] = obj->FMat[(localB->LD_diagOffset + jA) + 1];
    }

    if (!(localB->alpha1 == 0.0)) {
      jA = localB->LD_diagOffset + 86;
      jy = 0;
      for (int32_T j{0}; j <= localB->subMatrixDim; j++) {
        if (obj->workspace_[jy] != 0.0) {
          int32_T b;
          int32_T ijA;
          int32_T ix;
          localB->temp_d = obj->workspace_[jy] * localB->alpha1;
          ix = 0;
          ijA = jA;
          b = localB->subMatrixDim + jA;
          while (ijA + 1 <= b + 1) {
            obj->FMat[ijA] += obj->workspace_[ix] * localB->temp_d;
            ix++;
            ijA++;
          }
        }

        jy++;
        jA += 85;
      }
    }

    for (jA = 1; jA - 1 <= localB->subMatrixDim; jA++) {
      jy = localB->LD_diagOffset + jA;
      obj->FMat[jy] /= obj->FMat[localB->LD_diagOffset];
    }

    localB->lastDiag++;
  }

  localB->lastDiag = (NColsRemain - 1) * 86;
  if (std::abs(obj->FMat[localB->lastDiag]) <= obj->regTol_) {
    obj->FMat[localB->lastDiag] += REG_PRIMAL;
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_compute_deltax(const real_T H[7056],
  sizV6IUWKAiWqwEIFf7P38E_ros_c_T *solution, sIBsEwkwZMwV16lGx5frI7G_ros_c_T
  *memspace, const sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *qrmanager,
  sFUo2n2eWek74Kh1Ligw2mE_ros_c_T *cholmanager, const
  smUUAx65r5SQ5CSZDAURIoG_ros_c_T *objective, B_MPC_controller_ros_code_T
  *localB)
{
  localB->nVar_p = qrmanager->mrows - 1;
  localB->mNull = qrmanager->mrows - qrmanager->ncols;
  if (localB->mNull <= 0) {
    localB->mNull = 0;
    while (localB->mNull <= localB->nVar_p) {
      solution->searchDir[localB->mNull] = 0.0;
      localB->mNull++;
    }
  } else {
    localB->nullStartIdx = 0;
    while (localB->nullStartIdx <= localB->nVar_p) {
      solution->searchDir[localB->nullStartIdx] = -objective->grad
        [localB->nullStartIdx];
      localB->nullStartIdx++;
    }

    if (qrmanager->ncols <= 0) {
      if (objective->objtype == 3) {
        localB->b_SCALED_REG_PRIMAL = 1.4901161193847656E-6 * static_cast<real_T>
          (qrmanager->mrows);
        cholmanager->ndims = qrmanager->mrows;
        localB->mNull = 0;
        while (localB->mNull <= localB->nVar_p) {
          localB->nullStartIdx = (localB->nVar_p + 1) * localB->mNull;
          localB->b_A_maxDiag_idx = 85 * localB->mNull;
          localB->b_jjA = 1;
          while (localB->b_jjA - 1 <= localB->nVar_p) {
            cholmanager->FMat[(localB->b_A_maxDiag_idx + localB->b_jjA) - 1] =
              H[(localB->nullStartIdx + localB->b_jjA) - 1];
            localB->b_jjA++;
          }

          localB->mNull++;
        }

        localB->mNull = ros_code_ixamax(qrmanager->mrows, cholmanager->FMat) - 1;
        cholmanager->regTol_ = std::fmax(std::abs(cholmanager->FMat[85 *
          localB->mNull + localB->mNull]) * 2.2204460492503131E-16, std::abs
          (localB->b_SCALED_REG_PRIMAL));
        ros_code_fullColLDL2_(cholmanager, qrmanager->mrows,
                              localB->b_SCALED_REG_PRIMAL, localB);
        if (cholmanager->ConvexCheck) {
          localB->mNull = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (localB->mNull <= localB->nVar_p) {
              if (cholmanager->FMat[85 * localB->mNull + localB->mNull] <= 0.0)
              {
                cholmanager->info = -localB->mNull - 1;
                exitg1 = 1;
              } else {
                localB->mNull++;
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
          localB->mNull = cholmanager->ndims - 1;
          if (cholmanager->ndims != 0) {
            localB->nullStartIdx = 0;
            while (localB->nullStartIdx <= localB->mNull) {
              localB->nVar_p = localB->nullStartIdx * 85 + localB->nullStartIdx;
              localB->b_A_maxDiag_idx = localB->mNull - localB->nullStartIdx;
              localB->b_jjA = 1;
              while (localB->b_jjA - 1 <= localB->b_A_maxDiag_idx - 1) {
                localB->b_ix_j = localB->nullStartIdx + localB->b_jjA;
                solution->searchDir[localB->b_ix_j] -= cholmanager->FMat
                  [localB->nVar_p + localB->b_jjA] * solution->searchDir
                  [localB->nullStartIdx];
                localB->b_jjA++;
              }

              localB->nullStartIdx++;
            }
          }

          localB->nullStartIdx = 0;
          while (localB->nullStartIdx <= localB->mNull) {
            solution->searchDir[localB->nullStartIdx] /= cholmanager->FMat[85 *
              localB->nullStartIdx + localB->nullStartIdx];
            localB->nullStartIdx++;
          }

          if (cholmanager->ndims != 0) {
            localB->mNull = cholmanager->ndims - 1;
            while (localB->mNull + 1 > 0) {
              localB->nullStartIdx = localB->mNull * 85;
              localB->b_SCALED_REG_PRIMAL = solution->searchDir[localB->mNull];
              localB->nVar_p = cholmanager->ndims;
              while (localB->nVar_p >= localB->mNull + 2) {
                localB->b_SCALED_REG_PRIMAL -= cholmanager->FMat
                  [(localB->nullStartIdx + localB->nVar_p) - 1] *
                  solution->searchDir[localB->nVar_p - 1];
                localB->nVar_p--;
              }

              solution->searchDir[localB->mNull] = localB->b_SCALED_REG_PRIMAL;
              localB->mNull--;
            }
          }
        }
      }
    } else {
      localB->nullStartIdx = 85 * qrmanager->ncols + 1;
      if (objective->objtype == 5) {
        localB->b_A_maxDiag_idx = 0;
        while (localB->b_A_maxDiag_idx <= localB->mNull - 1) {
          memspace->workspace_double[localB->b_A_maxDiag_idx] = -qrmanager->Q
            [(qrmanager->ncols + localB->b_A_maxDiag_idx) * 85 + localB->nVar_p];
          localB->b_A_maxDiag_idx++;
        }

        ros_code_xgemv_n(qrmanager->mrows, localB->mNull, qrmanager->Q,
                         localB->nullStartIdx, memspace->workspace_double,
                         solution->searchDir);
      } else {
        if (objective->objtype == 3) {
          ros_cod_computeProjectedHessian(H, cholmanager, qrmanager, memspace,
            localB);
        }

        localB->b_SCALED_REG_PRIMAL = 1.4901161193847656E-6 * static_cast<real_T>
          (localB->mNull);
        cholmanager->ndims = localB->mNull;
        localB->b_A_maxDiag_idx = ros_code_ixamax(localB->mNull,
          cholmanager->FMat) - 1;
        cholmanager->regTol_ = std::fmax(std::abs(cholmanager->FMat[85 *
          localB->b_A_maxDiag_idx + localB->b_A_maxDiag_idx]) *
          2.2204460492503131E-16, localB->b_SCALED_REG_PRIMAL);
        ros_code_fullColLDL2_(cholmanager, localB->mNull,
                              localB->b_SCALED_REG_PRIMAL, localB);
        if (cholmanager->ConvexCheck) {
          localB->b_A_maxDiag_idx = 0;
          int32_T exitg1;
          do {
            exitg1 = 0;
            if (localB->b_A_maxDiag_idx <= localB->mNull - 1) {
              if (cholmanager->FMat[85 * localB->b_A_maxDiag_idx +
                  localB->b_A_maxDiag_idx] <= 0.0) {
                cholmanager->info = -localB->b_A_maxDiag_idx - 1;
                exitg1 = 1;
              } else {
                localB->b_A_maxDiag_idx++;
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
            localB->b_A_maxDiag_idx = 0;
            while (localB->b_A_maxDiag_idx <= localB->mNull - 1) {
              memspace->workspace_double[localB->b_A_maxDiag_idx] = 0.0;
              localB->b_A_maxDiag_idx++;
            }

            localB->b_A_maxDiag_idx = 0;
            localB->b_jjA = (localB->mNull - 1) * 85 + localB->nullStartIdx;
            localB->b_ix_j = localB->nullStartIdx;
            while (localB->b_ix_j <= localB->b_jjA) {
              localB->ix_p4 = 0;
              localB->b_SCALED_REG_PRIMAL = 0.0;
              localB->c_ix = localB->b_ix_j + localB->nVar_p;
              localB->ia_a = localB->b_ix_j;
              while (localB->ia_a <= localB->c_ix) {
                localB->b_SCALED_REG_PRIMAL += qrmanager->Q[localB->ia_a - 1] *
                  objective->grad[localB->ix_p4];
                localB->ix_p4++;
                localB->ia_a++;
              }

              memspace->workspace_double[localB->b_A_maxDiag_idx] +=
                -localB->b_SCALED_REG_PRIMAL;
              localB->b_A_maxDiag_idx++;
              localB->b_ix_j += 85;
            }
          }

          localB->nVar_p = cholmanager->ndims - 1;
          if (cholmanager->ndims != 0) {
            localB->b_A_maxDiag_idx = 0;
            while (localB->b_A_maxDiag_idx <= localB->nVar_p) {
              localB->b_jjA = localB->b_A_maxDiag_idx * 85 +
                localB->b_A_maxDiag_idx;
              localB->b_ix_j = localB->nVar_p - localB->b_A_maxDiag_idx;
              localB->ix_p4 = 1;
              while (localB->ix_p4 - 1 <= localB->b_ix_j - 1) {
                localB->c_ix = localB->b_A_maxDiag_idx + localB->ix_p4;
                memspace->workspace_double[localB->c_ix] -= cholmanager->
                  FMat[localB->b_jjA + localB->ix_p4] *
                  memspace->workspace_double[localB->b_A_maxDiag_idx];
                localB->ix_p4++;
              }

              localB->b_A_maxDiag_idx++;
            }
          }

          localB->b_A_maxDiag_idx = 0;
          while (localB->b_A_maxDiag_idx <= localB->nVar_p) {
            memspace->workspace_double[localB->b_A_maxDiag_idx] /=
              cholmanager->FMat[85 * localB->b_A_maxDiag_idx +
              localB->b_A_maxDiag_idx];
            localB->b_A_maxDiag_idx++;
          }

          if (cholmanager->ndims != 0) {
            localB->nVar_p = cholmanager->ndims - 1;
            while (localB->nVar_p + 1 > 0) {
              localB->b_A_maxDiag_idx = localB->nVar_p * 85;
              localB->b_SCALED_REG_PRIMAL = memspace->workspace_double
                [localB->nVar_p];
              localB->b_jjA = cholmanager->ndims;
              while (localB->b_jjA >= localB->nVar_p + 2) {
                localB->b_SCALED_REG_PRIMAL -= cholmanager->FMat
                  [(localB->b_A_maxDiag_idx + localB->b_jjA) - 1] *
                  memspace->workspace_double[localB->b_jjA - 1];
                localB->b_jjA--;
              }

              memspace->workspace_double[localB->nVar_p] =
                localB->b_SCALED_REG_PRIMAL;
              localB->nVar_p--;
            }
          }

          ros_code_xgemv_n(qrmanager->mrows, localB->mNull, qrmanager->Q,
                           localB->nullStartIdx, memspace->workspace_double,
                           solution->searchDir);
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static real_T ros_code_xnrm2_kp(int32_T n, const real_T x[85],
  B_MPC_controller_ros_code_T *localB)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = std::abs(x[0]);
    } else {
      localB->scale_h = 3.3121686421112381E-170;
      for (int32_T k{0}; k < n; k++) {
        real_T absxk;
        absxk = std::abs(x[k]);
        if (absxk > localB->scale_h) {
          real_T t;
          t = localB->scale_h / absxk;
          y = y * t * t + 1.0;
          localB->scale_h = absxk;
        } else {
          real_T t;
          t = absxk / localB->scale_h;
          y += t * t;
        }
      }

      y = localB->scale_h * std::sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_compute_lambda(real_T workspace[21505],
  sizV6IUWKAiWqwEIFf7P38E_ros_c_T *solution, const
  smUUAx65r5SQ5CSZDAURIoG_ros_c_T *objective, const
  sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *qrmanager, B_MPC_controller_ros_code_T
  *localB)
{
  if (qrmanager->ncols > 0) {
    int32_T c_idx;
    int32_T idxQR;
    boolean_T guard1{ false };

    guard1 = false;
    if (objective->objtype != 4) {
      boolean_T nonDegenerate;
      localB->c_jz = 100.0 * static_cast<real_T>(qrmanager->mrows) *
        2.2204460492503131E-16;
      nonDegenerate = ((qrmanager->mrows > 0) && (qrmanager->ncols > 0));
      if (nonDegenerate) {
        boolean_T guard2{ false };

        c_idx = qrmanager->ncols;
        guard2 = false;
        if (qrmanager->mrows < qrmanager->ncols) {
          idxQR = (qrmanager->ncols - 1) * 85 + qrmanager->mrows;
          while ((c_idx > qrmanager->mrows) && (std::abs(qrmanager->QR[idxQR - 1])
                  >= localB->c_jz)) {
            c_idx--;
            idxQR -= 85;
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
          idxQR = (c_idx - 1) * 85 + c_idx;
          while ((c_idx >= 1) && (std::abs(qrmanager->QR[idxQR - 1]) >=
                                  localB->c_jz)) {
            c_idx--;
            idxQR -= 86;
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
      int32_T ix;
      if (qrmanager->mrows != 0) {
        for (c_idx = 0; c_idx < qrmanager->ncols; c_idx++) {
          workspace[c_idx] = 0.0;
        }

        c_idx = 0;
        idxQR = (qrmanager->ncols - 1) * 85 + 1;
        for (int32_T iac{1}; iac <= idxQR; iac += 85) {
          int32_T d;
          ix = 0;
          localB->c_jz = 0.0;
          d = (iac + qrmanager->mrows) - 1;
          for (int32_T ia{iac}; ia <= d; ia++) {
            localB->c_jz += qrmanager->Q[ia - 1] * objective->grad[ix];
            ix++;
          }

          workspace[c_idx] += localB->c_jz;
          c_idx++;
        }
      }

      for (c_idx = qrmanager->ncols - 1; c_idx + 1 > 0; c_idx--) {
        idxQR = c_idx * 85 + c_idx;
        workspace[c_idx] /= qrmanager->QR[idxQR];
        for (int32_T iac{1}; iac - 1 < c_idx; iac++) {
          ix = c_idx - iac;
          workspace[ix] -= qrmanager->QR[idxQR - iac] * workspace[c_idx];
        }
      }

      for (c_idx = 0; c_idx < qrmanager->ncols; c_idx++) {
        solution->lambda[c_idx] = -workspace[c_idx];
      }
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_xgemv_nm(int32_T m, const real_T A[7140], const real_T x[85],
  real_T y[21505], B_MPC_controller_ros_code_T *localB)
{
  for (localB->b_iy_p = 0; localB->b_iy_p <= 82; localB->b_iy_p += 2) {
    __m128d tmp;
    tmp = _mm_loadu_pd(&y[localB->b_iy_p]);
    _mm_storeu_pd(&y[localB->b_iy_p], _mm_mul_pd(tmp, _mm_set1_pd(-1.0)));
  }

  for (localB->b_iy_p = 0; localB->b_iy_p <= 7056; localB->b_iy_p += 85) {
    int32_T b;
    localB->ix_k = 0;
    localB->c_d = 0.0;
    b = localB->b_iy_p + m;
    for (int32_T ia = localB->b_iy_p; ia < b; ia++) {
      localB->c_d += A[ia] * x[localB->ix_k];
      localB->ix_k++;
    }

    localB->ix_k = div_nde_s32_floor(localB->b_iy_p, 85);
    y[localB->ix_k] += localB->c_d;
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_xgemv_nmi(int32_T m, const real_T A[7140], const real_T x
  [85], real_T y[21505], B_MPC_controller_ros_code_T *localB)
{
  std::memset(&y[253], 0, 84U * sizeof(real_T));
  for (int32_T b_iy{0}; b_iy <= 7056; b_iy += 85) {
    int32_T b;
    int32_T ix;
    ix = 0;
    localB->c_o = 0.0;
    b = b_iy + m;
    for (int32_T ia{b_iy}; ia < b; ia++) {
      localB->c_o += A[ia] * x[ix];
      ix++;
    }

    ix = div_nde_s32_floor(b_iy, 85) + 253;
    y[ix] += localB->c_o;
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_ratiotest(const real_T solution_xstar[85], const real_T
  solution_searchDir[85], real_T workspace[21505], int32_T workingset_nVar,
  const real_T workingset_Aineq[7140], const real_T workingset_bineq[84], const
  real_T workingset_lb[85], const real_T workingset_ub[85], const int32_T
  workingset_indexLB[85], const int32_T workingset_indexUB[85], const int32_T
  workingset_sizes[5], const int32_T workingset_isActiveIdx[6], const boolean_T
  workingset_isActiveConstr[253], const int32_T workingset_nWConstr[5], real_T
  *toldelta, real_T *alpha, boolean_T *newBlocking, int32_T *constrType, int32_T
  *constrIdx, B_MPC_controller_ros_code_T *localB)
{
  *alpha = 1.0E+30;
  *newBlocking = false;
  *constrType = 0;
  *constrIdx = 0;
  localB->p_max = 0.0;
  localB->denomTol = 2.2204460492503131E-13 * ros_code_xnrm2_kp(workingset_nVar,
    solution_searchDir, localB);
  if (workingset_nWConstr[2] < 84) {
    std::memcpy(&workspace[0], &workingset_bineq[0], 84U * sizeof(real_T));
    ros_code_xgemv_nm(workingset_nVar, workingset_Aineq, solution_xstar,
                      workspace, localB);
    ros_code_xgemv_nmi(workingset_nVar, workingset_Aineq, solution_searchDir,
                       workspace, localB);
    for (localB->k_cs = 0; localB->k_cs < 84; localB->k_cs++) {
      localB->phaseOneCorrectionX = workspace[localB->k_cs + 253];
      if ((localB->phaseOneCorrectionX > localB->denomTol) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[2] + localB->k_cs)
           - 1])) {
        localB->alphaTemp = std::fmin(std::abs(workspace[localB->k_cs] -
          *toldelta), (1.0E-8 - workspace[localB->k_cs]) + *toldelta) /
          localB->phaseOneCorrectionX;
        if ((localB->alphaTemp <= *alpha) && (std::abs
             (localB->phaseOneCorrectionX) > localB->p_max)) {
          *alpha = localB->alphaTemp;
          *constrType = 3;
          *constrIdx = localB->k_cs + 1;
          *newBlocking = true;
        }

        localB->alphaTemp = std::fmin(std::abs(workspace[localB->k_cs]), 1.0E-8
          - workspace[localB->k_cs]) / localB->phaseOneCorrectionX;
        if (localB->alphaTemp < *alpha) {
          *alpha = localB->alphaTemp;
          *constrType = 3;
          *constrIdx = localB->k_cs + 1;
          *newBlocking = true;
          localB->p_max = std::abs(localB->phaseOneCorrectionX);
        }
      }
    }
  }

  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    localB->phaseOneCorrectionX = solution_xstar[workingset_nVar - 1] * 0.0;
    localB->phaseOneCorrectionP = solution_searchDir[workingset_nVar - 1] * 0.0;
    localB->k_cs = 0;
    while (localB->k_cs <= workingset_sizes[3] - 2) {
      localB->pk_corrected = -solution_searchDir[workingset_indexLB[localB->k_cs]
        - 1] - localB->phaseOneCorrectionP;
      if ((localB->pk_corrected > localB->denomTol) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[3] + localB->k_cs)
           - 1])) {
        localB->ratio_tmp = -solution_xstar[workingset_indexLB[localB->k_cs] - 1]
          - workingset_lb[workingset_indexLB[localB->k_cs] - 1];
        localB->alphaTemp = (localB->ratio_tmp - *toldelta) -
          localB->phaseOneCorrectionX;
        localB->alphaTemp = std::fmin(std::abs(localB->alphaTemp), 1.0E-8 -
          localB->alphaTemp) / localB->pk_corrected;
        if ((localB->alphaTemp <= *alpha) && (std::abs(localB->pk_corrected) >
             localB->p_max)) {
          *alpha = localB->alphaTemp;
          *constrType = 4;
          *constrIdx = localB->k_cs + 1;
          *newBlocking = true;
        }

        localB->alphaTemp = localB->ratio_tmp - localB->phaseOneCorrectionX;
        localB->alphaTemp = std::fmin(std::abs(localB->alphaTemp), 1.0E-8 -
          localB->alphaTemp) / localB->pk_corrected;
        if (localB->alphaTemp < *alpha) {
          *alpha = localB->alphaTemp;
          *constrType = 4;
          *constrIdx = localB->k_cs + 1;
          *newBlocking = true;
          localB->p_max = std::abs(localB->pk_corrected);
        }
      }

      localB->k_cs++;
    }

    localB->k_cs = workingset_indexLB[workingset_sizes[3] - 1] - 1;
    localB->phaseOneCorrectionX = solution_searchDir[localB->k_cs];
    if ((-localB->phaseOneCorrectionX > localB->denomTol) &&
        (!workingset_isActiveConstr[(workingset_isActiveIdx[3] +
          workingset_sizes[3]) - 2])) {
      localB->ratio_tmp = -solution_xstar[localB->k_cs] - workingset_lb
        [localB->k_cs];
      localB->alphaTemp = localB->ratio_tmp - *toldelta;
      localB->alphaTemp = std::fmin(std::abs(localB->alphaTemp), 1.0E-8 -
        localB->alphaTemp) / -localB->phaseOneCorrectionX;
      if ((localB->alphaTemp <= *alpha) && (std::abs(localB->phaseOneCorrectionX)
           > localB->p_max)) {
        *alpha = localB->alphaTemp;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
      }

      localB->alphaTemp = std::fmin(std::abs(localB->ratio_tmp), 1.0E-8 -
        localB->ratio_tmp) / -localB->phaseOneCorrectionX;
      if (localB->alphaTemp < *alpha) {
        *alpha = localB->alphaTemp;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
        localB->p_max = std::abs(solution_searchDir[localB->k_cs]);
      }
    }
  }

  if (workingset_nWConstr[4] < workingset_sizes[4]) {
    localB->phaseOneCorrectionX = solution_xstar[workingset_nVar - 1] * 0.0;
    localB->phaseOneCorrectionP = solution_searchDir[workingset_nVar - 1] * 0.0;
    localB->k_cs = 0;
    while (localB->k_cs <= workingset_sizes[4] - 1) {
      localB->pk_corrected = solution_searchDir[workingset_indexUB[localB->k_cs]
        - 1] - localB->phaseOneCorrectionP;
      if ((localB->pk_corrected > localB->denomTol) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[4] + localB->k_cs)
           - 1])) {
        localB->ratio_tmp = solution_xstar[workingset_indexUB[localB->k_cs] - 1]
          - workingset_ub[workingset_indexUB[localB->k_cs] - 1];
        localB->alphaTemp = (localB->ratio_tmp - *toldelta) -
          localB->phaseOneCorrectionX;
        localB->alphaTemp = std::fmin(std::abs(localB->alphaTemp), 1.0E-8 -
          localB->alphaTemp) / localB->pk_corrected;
        if ((localB->alphaTemp <= *alpha) && (std::abs(localB->pk_corrected) >
             localB->p_max)) {
          *alpha = localB->alphaTemp;
          *constrType = 5;
          *constrIdx = localB->k_cs + 1;
          *newBlocking = true;
        }

        localB->alphaTemp = localB->ratio_tmp - localB->phaseOneCorrectionX;
        localB->alphaTemp = std::fmin(std::abs(localB->alphaTemp), 1.0E-8 -
          localB->alphaTemp) / localB->pk_corrected;
        if (localB->alphaTemp < *alpha) {
          *alpha = localB->alphaTemp;
          *constrType = 5;
          *constrIdx = localB->k_cs + 1;
          *newBlocking = true;
          localB->p_max = std::abs(localB->pk_corrected);
        }
      }

      localB->k_cs++;
    }
  }

  *toldelta += 6.608625846508183E-7;
  if (localB->p_max > 0.0) {
    *alpha = std::fmax(*alpha, 6.608625846508183E-7 / localB->p_max);
  }

  *newBlocking = (((!*newBlocking) || (!(*alpha > 1.0))) && (*newBlocking));
  *alpha = std::fmin(*alpha, 1.0);
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_feasibleratiotest(const real_T solution_xstar[85], const
  real_T solution_searchDir[85], real_T workspace[21505], int32_T
  workingset_nVar, const real_T workingset_Aineq[7140], const real_T
  workingset_bineq[84], const real_T workingset_lb[85], const real_T
  workingset_ub[85], const int32_T workingset_indexLB[85], const int32_T
  workingset_indexUB[85], const int32_T workingset_sizes[5], const int32_T
  workingset_isActiveIdx[6], const boolean_T workingset_isActiveConstr[253],
  const int32_T workingset_nWConstr[5], boolean_T isPhaseOne, real_T *alpha,
  boolean_T *newBlocking, int32_T *constrType, int32_T *constrIdx,
  B_MPC_controller_ros_code_T *localB)
{
  *alpha = 1.0E+30;
  *newBlocking = false;
  *constrType = 0;
  *constrIdx = 0;
  localB->denomTol_o = 2.2204460492503131E-13 * ros_code_xnrm2_kp
    (workingset_nVar, solution_searchDir, localB);
  if (workingset_nWConstr[2] < 84) {
    std::memcpy(&workspace[0], &workingset_bineq[0], 84U * sizeof(real_T));
    ros_code_xgemv_nm(workingset_nVar, workingset_Aineq, solution_xstar,
                      workspace, localB);
    ros_code_xgemv_nmi(workingset_nVar, workingset_Aineq, solution_searchDir,
                       workspace, localB);
    for (localB->k_e = 0; localB->k_e < 84; localB->k_e++) {
      localB->phaseOneCorrectionX_n = workspace[localB->k_e + 253];
      if ((localB->phaseOneCorrectionX_n > localB->denomTol_o) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[2] + localB->k_e)
           - 1])) {
        localB->alphaTemp_b = std::fmin(std::abs(workspace[localB->k_e]), 1.0E-8
          - workspace[localB->k_e]) / localB->phaseOneCorrectionX_n;
        if (localB->alphaTemp_b < *alpha) {
          *alpha = localB->alphaTemp_b;
          *constrType = 3;
          *constrIdx = localB->k_e + 1;
          *newBlocking = true;
        }
      }
    }
  }

  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    localB->phaseOneCorrectionX_n = solution_xstar[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    localB->phaseOneCorrectionP_b = solution_searchDir[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    localB->k_e = 0;
    while (localB->k_e <= workingset_sizes[3] - 2) {
      localB->pk_corrected_l = -solution_searchDir[workingset_indexLB
        [localB->k_e] - 1] - localB->phaseOneCorrectionP_b;
      if ((localB->pk_corrected_l > localB->denomTol_o) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[3] + localB->k_e)
           - 1])) {
        localB->alphaTemp_b = (-solution_xstar[workingset_indexLB[localB->k_e] -
          1] - workingset_lb[workingset_indexLB[localB->k_e] - 1]) -
          localB->phaseOneCorrectionX_n;
        localB->alphaTemp_b = std::fmin(std::abs(localB->alphaTemp_b), 1.0E-8 -
          localB->alphaTemp_b) / localB->pk_corrected_l;
        if (localB->alphaTemp_b < *alpha) {
          *alpha = localB->alphaTemp_b;
          *constrType = 4;
          *constrIdx = localB->k_e + 1;
          *newBlocking = true;
        }
      }

      localB->k_e++;
    }

    localB->k_e = workingset_indexLB[workingset_sizes[3] - 1] - 1;
    localB->phaseOneCorrectionX_n = -solution_searchDir[localB->k_e];
    if ((localB->phaseOneCorrectionX_n > localB->denomTol_o) &&
        (!workingset_isActiveConstr[(workingset_isActiveIdx[3] +
          workingset_sizes[3]) - 2])) {
      localB->alphaTemp_b = -solution_xstar[localB->k_e] - workingset_lb
        [localB->k_e];
      localB->alphaTemp_b = std::fmin(std::abs(localB->alphaTemp_b), 1.0E-8 -
        localB->alphaTemp_b) / localB->phaseOneCorrectionX_n;
      if (localB->alphaTemp_b < *alpha) {
        *alpha = localB->alphaTemp_b;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
      }
    }
  }

  if (workingset_nWConstr[4] < workingset_sizes[4]) {
    localB->phaseOneCorrectionX_n = solution_xstar[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    localB->phaseOneCorrectionP_b = solution_searchDir[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    localB->k_e = 0;
    while (localB->k_e <= workingset_sizes[4] - 1) {
      localB->pk_corrected_l = solution_searchDir[workingset_indexUB[localB->k_e]
        - 1] - localB->phaseOneCorrectionP_b;
      if ((localB->pk_corrected_l > localB->denomTol_o) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[4] + localB->k_e)
           - 1])) {
        localB->alphaTemp_b = (solution_xstar[workingset_indexUB[localB->k_e] -
          1] - workingset_ub[workingset_indexUB[localB->k_e] - 1]) -
          localB->phaseOneCorrectionX_n;
        localB->alphaTemp_b = std::fmin(std::abs(localB->alphaTemp_b), 1.0E-8 -
          localB->alphaTemp_b) / localB->pk_corrected_l;
        if (localB->alphaTemp_b < *alpha) {
          *alpha = localB->alphaTemp_b;
          *constrType = 5;
          *constrIdx = localB->k_e + 1;
          *newBlocking = true;
        }
      }

      localB->k_e++;
    }
  }

  if (!isPhaseOne) {
    *newBlocking = (((!*newBlocking) || (!(*alpha > 1.0))) && (*newBlocking));
    *alpha = std::fmin(*alpha, 1.0);
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_co_checkUnboundedOrIllPosed(sizV6IUWKAiWqwEIFf7P38E_ros_c_T
  *solution, const smUUAx65r5SQ5CSZDAURIoG_ros_c_T *objective,
  B_MPC_controller_ros_code_T *localB)
{
  if (objective->objtype == 5) {
    if (ros_code_xnrm2_kp(objective->nvar, solution->searchDir, localB) > 100.0 *
        static_cast<real_T>(objective->nvar) * 1.4901161193847656E-8) {
      solution->state = 3;
    } else {
      solution->state = 4;
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros__addBoundToActiveSetMatrix_(sU7yup9HkfLOO3uVZruoOBF_ros_c_T *obj,
  int32_T TYPE, int32_T idx_local)
{
  int32_T colOffset;
  int32_T idx_bnd_local;
  obj->nWConstr[TYPE - 1]++;
  obj->isActiveConstr[(obj->isActiveIdx[TYPE - 1] + idx_local) - 2] = true;
  obj->nActiveConstr++;
  obj->Wid[obj->nActiveConstr - 1] = TYPE;
  obj->Wlocalidx[obj->nActiveConstr - 1] = idx_local;
  colOffset = (obj->nActiveConstr - 1) * 85 - 1;
  if (TYPE == 5) {
    idx_bnd_local = obj->indexUB[idx_local - 1];
    obj->bwset[obj->nActiveConstr - 1] = obj->ub[idx_bnd_local - 1];
  } else {
    idx_bnd_local = obj->indexLB[idx_local - 1];
    obj->bwset[obj->nActiveConstr - 1] = obj->lb[idx_bnd_local - 1];
  }

  for (int32_T idx{0}; idx <= idx_bnd_local - 2; idx++) {
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
static void ros__checkStoppingAndUpdateFval(int32_T *activeSetChangeID, const
  real_T f[84], sizV6IUWKAiWqwEIFf7P38E_ros_c_T *solution,
  sIBsEwkwZMwV16lGx5frI7G_ros_c_T *memspace, const
  smUUAx65r5SQ5CSZDAURIoG_ros_c_T *objective, sU7yup9HkfLOO3uVZruoOBF_ros_c_T
  *workingset, sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *qrmanager, real_T
  options_ObjectiveLimit, int32_T runTimeOptions_MaxIterations, real_T
  runTimeOptions_ConstrRelTolFact, boolean_T updateFval,
  B_MPC_controller_ros_code_T *localB)
{
  solution->iterations++;
  localB->nVar_tmp_tmp = objective->nvar - 1;
  if ((solution->iterations >= runTimeOptions_MaxIterations) &&
      ((solution->state != 1) || (objective->objtype == 5))) {
    solution->state = 0;
  }

  if (solution->iterations - solution->iterations / 50 * 50 == 0) {
    solution->maxConstr = ros_c_maxConstraintViolation_la(workingset,
      solution->xstar, localB);
    localB->tempMaxConstr = solution->maxConstr;
    if (objective->objtype == 5) {
      localB->tempMaxConstr = solution->maxConstr - solution->xstar
        [objective->nvar - 1];
    }

    if (localB->tempMaxConstr > 1.0E-8 * runTimeOptions_ConstrRelTolFact) {
      boolean_T nonDegenerateWset;
      localB->b_k_i = 0;
      while (localB->b_k_i <= localB->nVar_tmp_tmp) {
        solution->searchDir[localB->b_k_i] = solution->xstar[localB->b_k_i];
        localB->b_k_i++;
      }

      nonDegenerateWset = ros_cod_feasibleX0ForWorkingSet
        (memspace->workspace_double, solution->searchDir, workingset, qrmanager,
         localB);
      if ((!nonDegenerateWset) && (solution->state != 0)) {
        solution->state = -2;
      }

      *activeSetChangeID = 0;
      localB->tempMaxConstr = ros_c_maxConstraintViolation_la(workingset,
        solution->searchDir, localB);
      if (localB->tempMaxConstr < solution->maxConstr) {
        localB->b_k_i = 0;
        while (localB->b_k_i <= localB->nVar_tmp_tmp) {
          solution->xstar[localB->b_k_i] = solution->searchDir[localB->b_k_i];
          localB->b_k_i++;
        }

        solution->maxConstr = localB->tempMaxConstr;
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
static void ros_code_iterate(const real_T H[7056], const real_T f[84],
  sizV6IUWKAiWqwEIFf7P38E_ros_c_T *solution, sIBsEwkwZMwV16lGx5frI7G_ros_c_T
  *memspace, sU7yup9HkfLOO3uVZruoOBF_ros_c_T *workingset,
  sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *qrmanager, sFUo2n2eWek74Kh1Ligw2mE_ros_c_T
  *cholmanager, smUUAx65r5SQ5CSZDAURIoG_ros_c_T *objective, real_T
  options_ObjectiveLimit, real_T options_StepTolerance, int32_T
  runTimeOptions_MaxIterations, real_T runTimeOptions_ConstrRelTolFact, real_T
  runTimeOptions_ProbRelTolFactor, boolean_T runTimeOptions_RemainFeasible,
  B_MPC_controller_ros_code_T *localB)
{
  boolean_T newBlocking;
  boolean_T subProblemChanged;
  boolean_T updateFval;
  subProblemChanged = true;
  updateFval = true;
  localB->activeSetChangeID = 0;
  localB->TYPE = objective->objtype;
  localB->tolDelta = 6.7434957617430445E-7;
  localB->nVar_a = workingset->nVar;
  localB->globalActiveConstrIdx = 0;
  ros_code_computeGrad_StoreHx(objective, H, f, solution->xstar, localB);
  solution->fstar = ros_code_computeFval_ReuseHx(objective,
    memspace->workspace_double, f, solution->xstar);
  if (solution->iterations < runTimeOptions_MaxIterations) {
    solution->state = -5;
  } else {
    solution->state = 0;
  }

  std::memset(&solution->lambda[0], 0, 253U * sizeof(real_T));
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (solution->state == -5) {
      boolean_T guard1{ false };

      guard1 = false;
      if (subProblemChanged) {
        switch (localB->activeSetChangeID) {
         case 1:
          localB->idx_a = (workingset->nActiveConstr - 1) * 85;
          if (qrmanager->mrows <= qrmanager->ncols + 1) {
            qrmanager->minRowCol = qrmanager->mrows;
          } else {
            qrmanager->minRowCol = qrmanager->ncols + 1;
          }

          localB->b_iy = 85 * qrmanager->ncols;
          if (qrmanager->mrows != 0) {
            localB->iyend = localB->b_iy + qrmanager->mrows;
            localB->c_iy = localB->b_iy;
            while (localB->c_iy + 1 <= localB->iyend) {
              qrmanager->QR[localB->c_iy] = 0.0;
              localB->c_iy++;
            }

            localB->iyend = (qrmanager->mrows - 1) * 85 + 1;
            localB->c_iy = 1;
            while (localB->c_iy <= localB->iyend) {
              localB->b_ix = localB->idx_a;
              localB->normDelta = 0.0;
              localB->e = (localB->c_iy + qrmanager->mrows) - 1;
              localB->ia = localB->c_iy;
              while (localB->ia <= localB->e) {
                localB->normDelta += qrmanager->Q[localB->ia - 1] *
                  workingset->ATwset[localB->b_ix];
                localB->b_ix++;
                localB->ia++;
              }

              qrmanager->QR[localB->b_iy] += localB->normDelta;
              localB->b_iy++;
              localB->c_iy += 85;
            }
          }

          qrmanager->ncols++;
          qrmanager->jpvt[qrmanager->ncols - 1] = qrmanager->ncols;
          localB->idx_a = qrmanager->mrows - 2;
          while (localB->idx_a + 2 > qrmanager->ncols) {
            localB->b_iy = (qrmanager->ncols - 1) * 85;
            localB->iyend = (localB->idx_a + localB->b_iy) + 1;
            localB->temp_p = qrmanager->QR[localB->iyend];
            ros_code_xrotg(&qrmanager->QR[localB->idx_a + localB->b_iy],
                           &localB->temp_p, &localB->normDelta, &localB->s_n,
                           localB);
            qrmanager->QR[localB->iyend] = localB->temp_p;
            localB->b_iy = 85 * localB->idx_a;
            if (qrmanager->mrows >= 1) {
              localB->iyend = localB->b_iy + 85;
              localB->c_iy = 0;
              while (localB->c_iy <= qrmanager->mrows - 1) {
                localB->temp_p = localB->normDelta * qrmanager->Q[localB->b_iy]
                  + localB->s_n * qrmanager->Q[localB->iyend];
                qrmanager->Q[localB->iyend] = localB->normDelta * qrmanager->
                  Q[localB->iyend] - localB->s_n * qrmanager->Q[localB->b_iy];
                qrmanager->Q[localB->b_iy] = localB->temp_p;
                localB->iyend++;
                localB->b_iy++;
                localB->c_iy++;
              }
            }

            localB->idx_a--;
          }
          break;

         case -1:
          ros_code_deleteColMoveEnd(qrmanager, localB->globalActiveConstrIdx,
            localB);
          break;

         default:
          ros_code_factorQR(qrmanager, workingset->ATwset, localB->nVar_a,
                            workingset->nActiveConstr, localB);
          ros_code_computeQ_(qrmanager, qrmanager->mrows, localB);
          break;
        }

        ros_code_compute_deltax(H, solution, memspace, qrmanager, cholmanager,
          objective, localB);
        if (solution->state != -5) {
          exitg1 = 1;
        } else {
          localB->normDelta = ros_code_xnrm2_kp(localB->nVar_a,
            solution->searchDir, localB);
          guard1 = true;
        }
      } else {
        localB->idx_a = 0;
        while (localB->idx_a <= localB->nVar_a - 1) {
          solution->searchDir[localB->idx_a] = 0.0;
          localB->idx_a++;
        }

        localB->normDelta = 0.0;
        guard1 = true;
      }

      if (guard1) {
        if ((!subProblemChanged) || (localB->normDelta < options_StepTolerance) ||
            (workingset->nActiveConstr >= localB->nVar_a)) {
          ros_code_compute_lambda(memspace->workspace_double, solution,
            objective, qrmanager, localB);
          if ((solution->state != -7) || (workingset->nActiveConstr >
               localB->nVar_a)) {
            localB->idx_a = 0;
            localB->normDelta = 0.0 * runTimeOptions_ProbRelTolFactor *
              static_cast<real_T>(localB->TYPE != 5);
            localB->b_iy = workingset->nWConstr[0] + workingset->nWConstr[1];
            while (localB->b_iy + 1 <= workingset->nActiveConstr) {
              if (solution->lambda[localB->b_iy] < localB->normDelta) {
                localB->normDelta = solution->lambda[localB->b_iy];
                localB->idx_a = localB->b_iy + 1;
              }

              localB->b_iy++;
            }

            if (localB->idx_a == 0) {
              solution->state = 1;
            } else {
              localB->activeSetChangeID = -1;
              localB->globalActiveConstrIdx = localB->idx_a;
              subProblemChanged = true;
              ros_code_removeConstr(workingset, localB->idx_a);
              solution->lambda[localB->idx_a - 1] = 0.0;
            }
          } else {
            localB->idx_a = workingset->nActiveConstr;
            localB->activeSetChangeID = 0;
            localB->globalActiveConstrIdx = workingset->nActiveConstr;
            subProblemChanged = true;
            ros_code_removeConstr(workingset, workingset->nActiveConstr);
            solution->lambda[localB->idx_a - 1] = 0.0;
          }

          updateFval = false;
        } else {
          updateFval = (localB->TYPE == 5);
          if (updateFval || runTimeOptions_RemainFeasible) {
            ros_code_feasibleratiotest(solution->xstar, solution->searchDir,
              memspace->workspace_double, workingset->nVar, workingset->Aineq,
              workingset->bineq, workingset->lb, workingset->ub,
              workingset->indexLB, workingset->indexUB, workingset->sizes,
              workingset->isActiveIdx, workingset->isActiveConstr,
              workingset->nWConstr, updateFval, &localB->normDelta, &newBlocking,
              &localB->b_iy, &localB->idx_a, localB);
          } else {
            ros_code_ratiotest(solution->xstar, solution->searchDir,
                               memspace->workspace_double, workingset->nVar,
                               workingset->Aineq, workingset->bineq,
                               workingset->lb, workingset->ub,
                               workingset->indexLB, workingset->indexUB,
                               workingset->sizes, workingset->isActiveIdx,
                               workingset->isActiveConstr, workingset->nWConstr,
                               &localB->tolDelta, &localB->normDelta,
                               &newBlocking, &localB->b_iy, &localB->idx_a,
                               localB);
          }

          if (newBlocking) {
            switch (localB->b_iy) {
             case 3:
              workingset->nWConstr[2]++;
              workingset->isActiveConstr[(workingset->isActiveIdx[2] +
                localB->idx_a) - 2] = true;
              workingset->nActiveConstr++;
              workingset->Wid[workingset->nActiveConstr - 1] = 3;
              workingset->Wlocalidx[workingset->nActiveConstr - 1] =
                localB->idx_a;
              localB->activeSetChangeID = (localB->idx_a - 1) * 85;
              localB->b_iy = (workingset->nActiveConstr - 1) * 85;
              localB->iyend = 0;
              while (localB->iyend <= workingset->nVar - 1) {
                workingset->ATwset[localB->b_iy + localB->iyend] =
                  workingset->Aineq[localB->activeSetChangeID + localB->iyend];
                localB->iyend++;
              }

              workingset->bwset[workingset->nActiveConstr - 1] =
                workingset->bineq[localB->idx_a - 1];
              break;

             case 4:
              ros__addBoundToActiveSetMatrix_(workingset, 4, localB->idx_a);
              break;

             default:
              ros__addBoundToActiveSetMatrix_(workingset, 5, localB->idx_a);
              break;
            }

            localB->activeSetChangeID = 1;
          } else {
            ros_co_checkUnboundedOrIllPosed(solution, objective, localB);
            subProblemChanged = false;
            if (workingset->nActiveConstr == 0) {
              solution->state = 1;
            }
          }

          if (!(localB->normDelta == 0.0)) {
            localB->idx_a = 0;
            while (localB->idx_a <= localB->nVar_a - 1) {
              solution->xstar[localB->idx_a] += localB->normDelta *
                solution->searchDir[localB->idx_a];
              localB->idx_a++;
            }
          }

          ros_code_computeGrad_StoreHx(objective, H, f, solution->xstar, localB);
          updateFval = true;
        }

        ros__checkStoppingAndUpdateFval(&localB->activeSetChangeID, f, solution,
          memspace, objective, workingset, qrmanager, options_ObjectiveLimit,
          runTimeOptions_MaxIterations, runTimeOptions_ConstrRelTolFact,
          updateFval, localB);
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
static void ros_code_linearForm_(boolean_T obj_hasLinear, int32_T obj_nvar,
  real_T workspace[21505], const real_T H[7056], const real_T f[84], const
  real_T x[85], B_MPC_controller_ros_code_T *localB)
{
  int32_T ix;
  ix = 0;
  if (obj_hasLinear) {
    for (ix = 0; ix < obj_nvar; ix++) {
      workspace[ix] = f[ix];
    }

    ix = 1;
  }

  if (obj_nvar != 0) {
    int32_T b;
    int32_T iac;
    if (ix != 1) {
      for (ix = 0; ix < obj_nvar; ix++) {
        workspace[ix] = 0.0;
      }
    }

    ix = 0;
    b = (obj_nvar - 1) * obj_nvar + 1;
    iac = 1;
    while (((obj_nvar > 0) && (iac <= b)) || ((obj_nvar < 0) && (iac >= b))) {
      int32_T d;
      int32_T iy;
      localB->c_ju = 0.5 * x[ix];
      iy = 0;
      d = (iac + obj_nvar) - 1;
      for (int32_T ia{iac}; ia <= d; ia++) {
        workspace[iy] += H[ia - 1] * localB->c_ju;
        iy++;
      }

      ix++;
      iac += obj_nvar;
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static real_T ros_code_computeFval(const smUUAx65r5SQ5CSZDAURIoG_ros_c_T *obj,
  real_T workspace[21505], const real_T H[7056], const real_T f[84], const
  real_T x[85], B_MPC_controller_ros_code_T *localB)
{
  real_T val;
  switch (obj->objtype) {
   case 5:
    val = x[obj->nvar - 1] * obj->gammaScalar;
    break;

   case 3:
    ros_code_linearForm_(obj->hasLinear, obj->nvar, workspace, H, f, x, localB);
    val = 0.0;
    if (obj->nvar >= 1) {
      for (int32_T idx{0}; idx < obj->nvar; idx++) {
        val += x[idx] * workspace[idx];
      }
    }
    break;

   default:
    ros_code_linearForm_(obj->hasLinear, obj->nvar, workspace, H, f, x, localB);
    for (int32_T idx = obj->nvar; idx + 1 < 85; idx++) {
      workspace[idx] = 0.0 * x[idx];
    }

    val = 0.0;
    for (int32_T idx{0}; idx < 84; idx++) {
      val += x[idx] * workspace[idx];
    }
    break;
  }

  return val;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_phaseone(const real_T H[7056], const real_T f[84],
  sizV6IUWKAiWqwEIFf7P38E_ros_c_T *solution, sIBsEwkwZMwV16lGx5frI7G_ros_c_T
  *memspace, sU7yup9HkfLOO3uVZruoOBF_ros_c_T *workingset,
  sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *qrmanager, sFUo2n2eWek74Kh1Ligw2mE_ros_c_T
  *cholmanager, const sL9bDKomAYkxZSVrG9w6En_ros_co_T *runTimeOptions,
  smUUAx65r5SQ5CSZDAURIoG_ros_c_T *objective, sSOeZ9WO10chPn9Si6PKiCB_ros_c_T
  *options, B_MPC_controller_ros_code_T *localB)
{
  static const char_T b_Algorithm[10]{ 'a', 'c', 't', 'i', 'v', 'e', '-', 's',
    'e', 't' };

  static const char_T b_SolverName[8]{ 'q', 'u', 'a', 'd', 'p', 'r', 'o', 'g' };

  static const char_T b_FiniteDifferenceType[7]{ 'f', 'o', 'r', 'w', 'a', 'r',
    'd' };

  static const char_T b_Display[5]{ 'f', 'i', 'n', 'a', 'l' };

  options->InitDamping = 0.01;
  for (localB->i_me = 0; localB->i_me < 7; localB->i_me++) {
    options->FiniteDifferenceType[localB->i_me] = b_FiniteDifferenceType
      [localB->i_me];
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
  for (localB->i_me = 0; localB->i_me < 10; localB->i_me++) {
    options->Algorithm[localB->i_me] = b_Algorithm[localB->i_me];
  }

  options->ConstraintTolerance = 1.0E-8;
  options->OptimalityTolerance = 1.0E-8;
  options->MaxIterations = -1.0;
  options->FunctionTolerance = (rtInf);
  for (localB->i_me = 0; localB->i_me < 8; localB->i_me++) {
    options->SolverName[localB->i_me] = b_SolverName[localB->i_me];
  }

  options->CheckGradients = false;
  options->Diagnostics[0] = 'o';
  options->Diagnostics[1] = 'f';
  options->Diagnostics[2] = 'f';
  options->DiffMaxChange = (rtInf);
  options->DiffMinChange = 0.0;
  for (localB->i_me = 0; localB->i_me < 5; localB->i_me++) {
    options->Display[localB->i_me] = b_Display[localB->i_me];
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
  localB->nVar_h = workingset->nVar;
  solution->xstar[84] = solution->maxConstr + 1.0;
  ros_code_setProblemType(workingset, 1);
  ros_code_removeAllIneqConstr(workingset);
  std::memset(&objective->grad[0], 0, 85U * sizeof(real_T));
  std::memset(&objective->Hx[0], 0, 84U * sizeof(real_T));
  objective->maxVar = 85;
  objective->beta = 0.0;
  objective->rho = 0.0;
  objective->prev_objtype = 3;
  objective->prev_nvar = 84;
  objective->prev_hasLinear = true;
  objective->objtype = 5;
  objective->nvar = 85;
  objective->gammaScalar = 1.0;
  objective->hasLinear = true;
  options->ObjectiveLimit = 1.0E-8 * runTimeOptions->ConstrRelTolFactor;
  solution->fstar = ros_code_computeFval(objective, memspace->workspace_double,
    H, f, solution->xstar, localB);
  solution->state = 5;
  ros_code_iterate(H, f, solution, memspace, workingset, qrmanager, cholmanager,
                   objective, options->ObjectiveLimit, 1.4901161193847657E-10,
                   runTimeOptions->MaxIterations,
                   runTimeOptions->ConstrRelTolFactor,
                   runTimeOptions->ProbRelTolFactor,
                   runTimeOptions->RemainFeasible, localB);
  if (workingset->isActiveConstr[(workingset->isActiveIdx[3] + workingset->
       sizes[3]) - 2]) {
    boolean_T exitg1;
    localB->i_me = workingset->sizes[0];
    exitg1 = false;
    while ((!exitg1) && (localB->i_me + 1 <= workingset->nActiveConstr)) {
      if ((workingset->Wid[localB->i_me] == 4) && (workingset->Wlocalidx
           [localB->i_me] == workingset->sizes[3])) {
        ros_code_removeConstr(workingset, localB->i_me + 1);
        exitg1 = true;
      } else {
        localB->i_me++;
      }
    }
  }

  localB->i_me = workingset->nActiveConstr;
  while ((localB->i_me > workingset->sizes[0]) && (localB->i_me > localB->nVar_h))
  {
    ros_code_removeConstr(workingset, localB->i_me);
    localB->i_me--;
  }

  solution->maxConstr = solution->xstar[84];
  ros_code_setProblemType(workingset, 3);
  objective->objtype = objective->prev_objtype;
  objective->nvar = objective->prev_nvar;
  objective->hasLinear = objective->prev_hasLinear;
  options->ObjectiveLimit = -1.0E+20;
  options->StepTolerance = 1.0E-8;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static boolean_T ros_code_strcmp(const char_T a[8])
{
  static const char_T b[128]{ '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
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

  static const char_T c[8]{ 'q', 'u', 'a', 'd', 'p', 'r', 'o', 'g' };

  int32_T kstr;
  boolean_T b_bool;
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
static void ros_code_computeFirstOrderOpt(sizV6IUWKAiWqwEIFf7P38E_ros_c_T
  *solution, const smUUAx65r5SQ5CSZDAURIoG_ros_c_T *objective, int32_T
  workingset_nVar, const real_T workingset_ATwset[21505], int32_T
  workingset_nActiveConstr, real_T workspace[21505], B_MPC_controller_ros_code_T
  *localB)
{
  int32_T b_ix;
  int32_T ix;
  for (ix = 0; ix < workingset_nVar; ix++) {
    workspace[ix] = objective->grad[ix];
  }

  if (workingset_nActiveConstr != 0) {
    ix = 0;
    b_ix = (workingset_nActiveConstr - 1) * 85 + 1;
    for (int32_T iac{1}; iac <= b_ix; iac += 85) {
      int32_T c;
      int32_T iy;
      iy = 0;
      c = iac + workingset_nVar;
      for (int32_T ia{iac}; ia < c; ia++) {
        workspace[iy] += workingset_ATwset[ia - 1] * solution->lambda[ix];
        iy++;
      }

      ix++;
    }
  }

  ix = 1;
  b_ix = 0;
  localB->smax_e = std::abs(workspace[0]);
  for (int32_T iac{2}; iac <= workingset_nVar; iac++) {
    b_ix++;
    localB->s_b = std::abs(workspace[b_ix]);
    if (localB->s_b > localB->smax_e) {
      ix = iac;
      localB->smax_e = localB->s_b;
    }
  }

  solution->firstorderopt = std::abs(workspace[ix - 1]);
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static int32_T ros_code_RemoveDependentEq__o(sIBsEwkwZMwV16lGx5frI7G_ros_c_T
  *memspace, sU7yup9HkfLOO3uVZruoOBF_ros_c_T *workingset,
  sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *qrmanager, B_MPC_controller_ros_code_T
  *localB)
{
  int32_T nDepInd;
  localB->nVar = workingset->nVar - 1;
  localB->mTotalWorkingEq = workingset->nWConstr[0] + workingset->nWConstr[1];
  nDepInd = 0;
  if (localB->mTotalWorkingEq > 0) {
    localB->totalRank = 0;
    while (localB->totalRank <= localB->mTotalWorkingEq - 1) {
      localB->ix = 0;
      while (localB->ix <= localB->nVar) {
        qrmanager->QR[localB->totalRank + 85 * localB->ix] = workingset->ATwset
          [85 * localB->totalRank + localB->ix];
        localB->ix++;
      }

      localB->totalRank++;
    }

    nDepInd = localB->mTotalWorkingEq - workingset->nVar;
    if (nDepInd <= 0) {
      nDepInd = 0;
    }

    localB->totalRank = 0;
    while (localB->totalRank <= localB->nVar) {
      qrmanager->jpvt[localB->totalRank] = 0;
      localB->totalRank++;
    }

    ros_code_factorQRE(qrmanager, localB->mTotalWorkingEq, workingset->nVar,
                       localB);
    localB->tol = 100.0 * static_cast<real_T>(workingset->nVar) *
      2.2204460492503131E-16;
    if (workingset->nVar <= localB->mTotalWorkingEq) {
      localB->totalRank = workingset->nVar;
    } else {
      localB->totalRank = localB->mTotalWorkingEq;
    }

    localB->totalRank += (localB->totalRank - 1) * 85;
    while ((localB->totalRank > 0) && (std::abs(qrmanager->QR[localB->totalRank
             - 1]) < localB->tol)) {
      localB->totalRank -= 86;
      nDepInd++;
    }

    if (nDepInd > 0) {
      boolean_T exitg1;
      ros_code_computeQ_(qrmanager, qrmanager->mrows, localB);
      localB->totalRank = 0;
      exitg1 = false;
      while ((!exitg1) && (localB->totalRank <= nDepInd - 1)) {
        localB->ix = ((localB->mTotalWorkingEq - localB->totalRank) - 1) * 85;
        localB->qtb = 0.0;
        localB->iy = 0;
        localB->b_k = 0;
        while (localB->b_k <= localB->mTotalWorkingEq - 1) {
          localB->qtb += qrmanager->Q[localB->ix] * workingset->bwset[localB->iy];
          localB->ix++;
          localB->iy++;
          localB->b_k++;
        }

        if (std::abs(localB->qtb) >= localB->tol) {
          nDepInd = -1;
          exitg1 = true;
        } else {
          localB->totalRank++;
        }
      }
    }

    if (nDepInd > 0) {
      localB->totalRank = 0;
      while (localB->totalRank <= localB->mTotalWorkingEq - 1) {
        localB->ix = 85 * localB->totalRank;
        localB->iy = 1;
        while (localB->iy - 1 <= localB->nVar) {
          localB->b_k = (localB->ix + localB->iy) - 1;
          qrmanager->QR[localB->b_k] = workingset->ATwset[localB->b_k];
          localB->iy++;
        }

        localB->totalRank++;
      }

      ros_code_IndexOfDependentEq_(memspace->workspace_int, workingset->
        nWConstr[0], nDepInd, qrmanager, workingset->nVar,
        localB->mTotalWorkingEq, localB);
      ros_code_countsort(memspace->workspace_int, nDepInd,
                         memspace->workspace_sort, 1, localB->mTotalWorkingEq);
      localB->nVar = nDepInd;
      while (localB->nVar > 0) {
        ros_code_removeEqConstr(workingset, memspace->workspace_int[localB->nVar
          - 1], localB);
        localB->nVar--;
      }
    }
  }

  return nDepInd;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_PresolveWorkingSet_k(sizV6IUWKAiWqwEIFf7P38E_ros_c_T
  *solution, sIBsEwkwZMwV16lGx5frI7G_ros_c_T *memspace,
  sU7yup9HkfLOO3uVZruoOBF_ros_c_T *workingset, sxn76bLJrqJiWwjGl8YOqSB_ros_c_T
  *qrmanager, B_MPC_controller_ros_code_T *localB)
{
  solution->state = 82;
  localB->b_m = ros_code_RemoveDependentEq__o(memspace, workingset, qrmanager,
    localB);
  if ((localB->b_m != -1) && (workingset->nActiveConstr <= 85)) {
    boolean_T guard1{ false };

    boolean_T okWorkingSet;
    ros_code_RemoveDependentIneq_(workingset, qrmanager, memspace, 100.0, localB);
    okWorkingSet = ros_cod_feasibleX0ForWorkingSet(memspace->workspace_double,
      solution->xstar, workingset, qrmanager, localB);
    guard1 = false;
    if (!okWorkingSet) {
      ros_code_RemoveDependentIneq_(workingset, qrmanager, memspace, 1000.0,
        localB);
      okWorkingSet = ros_cod_feasibleX0ForWorkingSet(memspace->workspace_double,
        solution->xstar, workingset, qrmanager, localB);
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
        localB->constrViolation = ros_c_maxConstraintViolation_la(workingset,
          solution->xstar, localB);
        if (localB->constrViolation > 1.0E-8) {
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
static void ros_code_phaseone_f(const real_T H[7056], const real_T f[84],
  sizV6IUWKAiWqwEIFf7P38E_ros_c_T *solution, sIBsEwkwZMwV16lGx5frI7G_ros_c_T
  *memspace, sU7yup9HkfLOO3uVZruoOBF_ros_c_T *workingset,
  sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *qrmanager, sFUo2n2eWek74Kh1Ligw2mE_ros_c_T
  *cholmanager, smUUAx65r5SQ5CSZDAURIoG_ros_c_T *objective,
  sSOeZ9WO10chPn9Si6PKiCB_ros_c_T *options, const
  sL9bDKomAYkxZSVrG9w6En_ros_co_T *runTimeOptions, B_MPC_controller_ros_code_T
  *localB)
{
  localB->PROBTYPE_ORIG = workingset->probType;
  localB->nVar_e = workingset->nVar;
  solution->xstar[84] = solution->maxConstr + 1.0;
  if (workingset->probType == 3) {
    localB->mConstr = 1;
  } else {
    localB->mConstr = 4;
  }

  ros_code_setProblemType(workingset, localB->mConstr);
  ros_code_removeAllIneqConstr(workingset);
  objective->prev_objtype = objective->objtype;
  objective->prev_nvar = objective->nvar;
  objective->prev_hasLinear = objective->hasLinear;
  objective->objtype = 5;
  objective->nvar = 85;
  objective->gammaScalar = 1.0;
  objective->hasLinear = true;
  options->ObjectiveLimit = 1.0E-8 * runTimeOptions->ConstrRelTolFactor;
  options->StepTolerance = 1.4901161193847657E-10;
  solution->fstar = ros_code_computeFval(objective, memspace->workspace_double,
    H, f, solution->xstar, localB);
  solution->state = 5;
  ros_code_iterate(H, f, solution, memspace, workingset, qrmanager, cholmanager,
                   objective, options->ObjectiveLimit, options->StepTolerance,
                   runTimeOptions->MaxIterations,
                   runTimeOptions->ConstrRelTolFactor,
                   runTimeOptions->ProbRelTolFactor,
                   runTimeOptions->RemainFeasible, localB);
  if (workingset->isActiveConstr[(workingset->isActiveIdx[3] + workingset->
       sizes[3]) - 2]) {
    boolean_T exitg1;
    localB->mConstr = workingset->sizes[0];
    exitg1 = false;
    while ((!exitg1) && (localB->mConstr + 1 <= workingset->nActiveConstr)) {
      if ((workingset->Wid[localB->mConstr] == 4) && (workingset->
           Wlocalidx[localB->mConstr] == workingset->sizes[3])) {
        ros_code_removeConstr(workingset, localB->mConstr + 1);
        exitg1 = true;
      } else {
        localB->mConstr++;
      }
    }
  }

  localB->mConstr = workingset->nActiveConstr;
  while ((localB->mConstr > workingset->sizes[0]) && (localB->mConstr >
          localB->nVar_e)) {
    ros_code_removeConstr(workingset, localB->mConstr);
    localB->mConstr--;
  }

  solution->maxConstr = solution->xstar[84];
  ros_code_setProblemType(workingset, localB->PROBTYPE_ORIG);
  objective->objtype = objective->prev_objtype;
  objective->nvar = objective->prev_nvar;
  objective->hasLinear = objective->prev_hasLinear;
  options->ObjectiveLimit = -1.0E+20;
  options->StepTolerance = 1.0E-8;
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_driver(const real_T H[7056], const real_T f[84],
  sizV6IUWKAiWqwEIFf7P38E_ros_c_T *solution, sIBsEwkwZMwV16lGx5frI7G_ros_c_T
  *memspace, sU7yup9HkfLOO3uVZruoOBF_ros_c_T *workingset,
  sFUo2n2eWek74Kh1Ligw2mE_ros_c_T *cholmanager, sL9bDKomAYkxZSVrG9w6En_ros_co_T
  runTimeOptions, sxn76bLJrqJiWwjGl8YOqSB_ros_c_T *qrmanager,
  smUUAx65r5SQ5CSZDAURIoG_ros_c_T *objective, B_MPC_controller_ros_code_T
  *localB)
{
  static const char_T d_Algorithm[10]{ 'a', 'c', 't', 'i', 'v', 'e', '-', 's',
    'e', 't' };

  static const char_T d_SolverName[8]{ 'q', 'u', 'a', 'd', 'p', 'r', 'o', 'g' };

  static const char_T d_FiniteDifferenceType[7]{ 'f', 'o', 'r', 'w', 'a', 'r',
    'd' };

  static const char_T d_Display[5]{ 'f', 'i', 'n', 'a', 'l' };

  std::memset(&objective->grad[0], 0, 85U * sizeof(real_T));
  std::memset(&objective->Hx[0], 0, 84U * sizeof(real_T));
  objective->hasLinear = true;
  objective->nvar = 84;
  objective->maxVar = 85;
  objective->beta = 0.0;
  objective->rho = 0.0;
  objective->objtype = 3;
  objective->prev_objtype = 3;
  objective->prev_nvar = 0;
  objective->prev_hasLinear = false;
  objective->gammaScalar = 0.0;
  solution->iterations = 0;
  runTimeOptions.RemainFeasible = true;
  localB->i_c = workingset->nVar - 1;
  localB->b_idx = 0;
  while (localB->b_idx <= workingset->sizes[0] - 1) {
    solution->xstar[workingset->indexFixed[localB->b_idx] - 1] = workingset->
      ub[workingset->indexFixed[localB->b_idx] - 1];
    localB->b_idx++;
  }

  localB->b_idx = 0;
  while (localB->b_idx <= workingset->sizes[3] - 1) {
    if (workingset->isActiveConstr[(workingset->isActiveIdx[3] + localB->b_idx)
        - 1]) {
      solution->xstar[workingset->indexLB[localB->b_idx] - 1] = -workingset->
        lb[workingset->indexLB[localB->b_idx] - 1];
    }

    localB->b_idx++;
  }

  localB->b_idx = 0;
  while (localB->b_idx <= workingset->sizes[4] - 1) {
    if (workingset->isActiveConstr[(workingset->isActiveIdx[4] + localB->b_idx)
        - 1]) {
      solution->xstar[workingset->indexUB[localB->b_idx] - 1] = workingset->
        ub[workingset->indexUB[localB->b_idx] - 1];
    }

    localB->b_idx++;
  }

  ros_code_PresolveWorkingSet(solution, memspace, workingset, qrmanager, localB);
  localB->options.InitDamping = 0.01;
  for (localB->b_idx = 0; localB->b_idx < 7; localB->b_idx++) {
    localB->options.FiniteDifferenceType[localB->b_idx] =
      d_FiniteDifferenceType[localB->b_idx];
  }

  localB->options.SpecifyObjectiveGradient = false;
  localB->options.ScaleProblem = false;
  localB->options.SpecifyConstraintGradient = false;
  localB->options.NonFiniteSupport = true;
  localB->options.IterDisplaySQP = false;
  localB->options.FiniteDifferenceStepSize = -1.0;
  localB->options.MaxFunctionEvaluations = -1.0;
  localB->options.IterDisplayQP = false;
  localB->options.PricingTolerance = 0.0;
  for (localB->b_idx = 0; localB->b_idx < 10; localB->b_idx++) {
    localB->options.Algorithm[localB->b_idx] = d_Algorithm[localB->b_idx];
  }

  localB->options.ObjectiveLimit = -1.0E+20;
  localB->options.ConstraintTolerance = 1.0E-8;
  localB->options.OptimalityTolerance = 1.0E-8;
  localB->options.StepTolerance = 1.0E-8;
  localB->options.MaxIterations = -1.0;
  localB->options.FunctionTolerance = (rtInf);
  for (localB->b_idx = 0; localB->b_idx < 8; localB->b_idx++) {
    localB->options.SolverName[localB->b_idx] = d_SolverName[localB->b_idx];
  }

  localB->options.CheckGradients = false;
  localB->options.Diagnostics[0] = 'o';
  localB->options.Diagnostics[1] = 'f';
  localB->options.Diagnostics[2] = 'f';
  localB->options.DiffMaxChange = (rtInf);
  localB->options.DiffMinChange = 0.0;
  for (localB->b_idx = 0; localB->b_idx < 5; localB->b_idx++) {
    localB->options.Display[localB->b_idx] = d_Display[localB->b_idx];
  }

  localB->options.FunValCheck[0] = 'o';
  localB->options.FunValCheck[1] = 'f';
  localB->options.FunValCheck[2] = 'f';
  localB->options.UseParallel = false;
  localB->options.LinearSolver[0] = 'a';
  localB->options.LinearSolver[1] = 'u';
  localB->options.LinearSolver[2] = 't';
  localB->options.LinearSolver[3] = 'o';
  localB->options.SubproblemAlgorithm[0] = 'c';
  localB->options.SubproblemAlgorithm[1] = 'g';
  if (solution->state >= 0) {
    boolean_T guard1{ false };

    solution->iterations = 0;
    solution->maxConstr = ros_c_maxConstraintViolation_la(workingset,
      solution->xstar, localB);
    localB->maxConstr_new = 1.0E-8 * runTimeOptions.ConstrRelTolFactor;
    guard1 = false;
    if (solution->maxConstr > localB->maxConstr_new) {
      ros_code_phaseone(H, f, solution, memspace, workingset, qrmanager,
                        cholmanager, &runTimeOptions, objective,
                        &localB->options, localB);
      if (solution->state == 0) {
      } else {
        solution->maxConstr = ros_c_maxConstraintViolation_la(workingset,
          solution->xstar, localB);
        if (solution->maxConstr > localB->maxConstr_new) {
          std::memset(&solution->lambda[0], 0, 253U * sizeof(real_T));
          solution->fstar = ros_code_computeFval(objective,
            memspace->workspace_double, H, f, solution->xstar, localB);
          solution->state = -2;
        } else {
          if (solution->maxConstr > 0.0) {
            localB->b_idx = 0;
            while (localB->b_idx <= localB->i_c) {
              solution->searchDir[localB->b_idx] = solution->xstar[localB->b_idx];
              localB->b_idx++;
            }

            ros_code_PresolveWorkingSet_k(solution, memspace, workingset,
              qrmanager, localB);
            localB->maxConstr_new = ros_c_maxConstraintViolation_la(workingset,
              solution->xstar, localB);
            if (localB->maxConstr_new >= solution->maxConstr) {
              solution->maxConstr = localB->maxConstr_new;
              localB->b_idx = 0;
              while (localB->b_idx <= localB->i_c) {
                solution->xstar[localB->b_idx] = solution->searchDir
                  [localB->b_idx];
                localB->b_idx++;
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
                       cholmanager, objective, localB->options.ObjectiveLimit,
                       localB->options.StepTolerance,
                       runTimeOptions.MaxIterations,
                       runTimeOptions.ConstrRelTolFactor,
                       runTimeOptions.ProbRelTolFactor, true, localB);
      if (ros_code_strcmp(localB->options.SolverName) && (solution->state != -6))
      {
        solution->maxConstr = ros_c_maxConstraintViolation_la(workingset,
          solution->xstar, localB);
        ros_code_computeFirstOrderOpt(solution, objective, workingset->nVar,
          workingset->ATwset, workingset->nActiveConstr,
          memspace->workspace_double, localB);
        runTimeOptions.RemainFeasible = false;
        while ((solution->iterations < runTimeOptions.MaxIterations) &&
               ((solution->state == -7) || ((solution->state == 1) &&
                 ((solution->maxConstr > 1.0E-8 *
                   runTimeOptions.ConstrRelTolFactor) ||
                  (solution->firstorderopt > 1.0E-8 *
                   runTimeOptions.ProbRelTolFactor))))) {
          ros_cod_feasibleX0ForWorkingSet(memspace->workspace_double,
            solution->xstar, workingset, qrmanager, localB);
          ros_code_PresolveWorkingSet_k(solution, memspace, workingset,
            qrmanager, localB);
          ros_code_phaseone_f(H, f, solution, memspace, workingset, qrmanager,
                              cholmanager, objective, &localB->options,
                              &runTimeOptions, localB);
          ros_code_iterate(H, f, solution, memspace, workingset, qrmanager,
                           cholmanager, objective,
                           localB->options.ObjectiveLimit,
                           localB->options.StepTolerance,
                           runTimeOptions.MaxIterations,
                           runTimeOptions.ConstrRelTolFactor,
                           runTimeOptions.ProbRelTolFactor, false, localB);
          solution->maxConstr = ros_c_maxConstraintViolation_la(workingset,
            solution->xstar, localB);
          ros_code_computeFirstOrderOpt(solution, objective, workingset->nVar,
            workingset->ATwset, workingset->nActiveConstr,
            memspace->workspace_double, localB);
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
static void ros_code_quadprog(const real_T H[7056], const real_T f[84], const
  real_T Aineq[7056], const real_T bineq[84], const real_T lb[84], const real_T
  ub[84], real_T x[84], real_T *fval, real_T *exitflag,
  B_MPC_controller_ros_code_T *localB)
{
  localB->solution.fstar = 0.0;
  localB->solution.firstorderopt = 0.0;
  std::memset(&localB->solution.lambda[0], 0, 253U * sizeof(real_T));
  localB->solution.state = 0;
  localB->solution.maxConstr = 0.0;
  localB->solution.iterations = 0;
  std::memset(&localB->solution.searchDir[0], 0, 85U * sizeof(real_T));
  std::memset(&localB->solution.xstar[0], 0, 84U * sizeof(real_T));
  ros_code_factoryConstruct(&localB->CholRegManager);
  localB->CholRegManager.scaleFactor = 100.0;
  localB->WorkingSet.nVar = 84;
  localB->WorkingSet.nVarOrig = 84;
  localB->WorkingSet.nVarMax = 85;
  localB->WorkingSet.ldA = 85;
  std::memset(&localB->WorkingSet.Aineq[0], 0, 7140U * sizeof(real_T));
  std::memset(&localB->WorkingSet.bineq[0], 0, 84U * sizeof(real_T));
  std::memset(&localB->WorkingSet.lb[0], 0, 85U * sizeof(real_T));
  std::memset(&localB->WorkingSet.ub[0], 0, 85U * sizeof(real_T));
  localB->WorkingSet.mEqRemoved = 0;
  std::memset(&localB->WorkingSet.ATwset[0], 0, 21505U * sizeof(real_T));
  localB->WorkingSet.nActiveConstr = 0;
  std::memset(&localB->WorkingSet.bwset[0], 0, 253U * sizeof(real_T));
  std::memset(&localB->WorkingSet.maxConstrWorkspace[0], 0, 253U * sizeof(real_T));
  std::memset(&localB->WorkingSet.isActiveConstr[0], 0, 253U * sizeof(boolean_T));
  std::memset(&localB->WorkingSet.Wid[0], 0, 253U * sizeof(int32_T));
  std::memset(&localB->WorkingSet.Wlocalidx[0], 0, 253U * sizeof(int32_T));
  for (localB->i_m = 0; localB->i_m < 5; localB->i_m++) {
    localB->WorkingSet.nWConstr[localB->i_m] = 0;
  }

  localB->WorkingSet.probType = 3;
  localB->WorkingSet.SLACK0 = 1.0E-5;
  std::memset(&localB->WorkingSet.indexLB[0], 0, 85U * sizeof(int32_T));
  std::memset(&localB->WorkingSet.indexUB[0], 0, 85U * sizeof(int32_T));
  std::memset(&localB->WorkingSet.indexFixed[0], 0, 85U * sizeof(int32_T));
  localB->k = 84;
  localB->mUB = 0;
  localB->mFixed = 0;
  for (localB->idx = 0; localB->idx < 84; localB->idx++) {
    boolean_T guard1{ false };

    localB->ub_g = ub[localB->idx];
    localB->H_infnrm = lb[localB->idx];
    guard1 = false;
    if ((!std::isinf(localB->H_infnrm)) && (!std::isnan(localB->H_infnrm))) {
      if (std::abs(localB->H_infnrm - localB->ub_g) < 1.0E-8) {
        localB->mFixed++;
        localB->WorkingSet.indexFixed[localB->mFixed - 1] = localB->idx + 1;
      } else {
        localB->k++;
        localB->WorkingSet.indexLB[localB->k - 85] = localB->idx + 1;
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if ((!std::isinf(localB->ub_g)) && (!std::isnan(localB->ub_g))) {
        localB->mUB++;
        localB->WorkingSet.indexUB[localB->mUB - 1] = localB->idx + 1;
      }
    }
  }

  localB->idx = (localB->k + localB->mUB) + localB->mFixed;
  localB->WorkingSet.mConstr = localB->idx;
  localB->WorkingSet.mConstrOrig = localB->idx;
  localB->WorkingSet.mConstrMax = 253;
  localB->WorkingSet.sizes[0] = localB->mFixed;
  localB->WorkingSet.sizes[1] = 0;
  localB->WorkingSet.sizes[2] = 84;
  localB->WorkingSet.sizes[3] = localB->k - 84;
  localB->WorkingSet.sizes[4] = localB->mUB;
  for (localB->idx = 0; localB->idx < 5; localB->idx++) {
    localB->WorkingSet.sizesNormal[localB->idx] = localB->
      WorkingSet.sizes[localB->idx];
  }

  localB->WorkingSet.sizesPhaseOne[0] = localB->mFixed;
  localB->WorkingSet.sizesPhaseOne[1] = 0;
  localB->WorkingSet.sizesPhaseOne[2] = 84;
  localB->WorkingSet.sizesPhaseOne[3] = localB->k - 83;
  localB->WorkingSet.sizesPhaseOne[4] = localB->mUB;
  localB->WorkingSet.sizesRegularized[0] = localB->mFixed;
  localB->WorkingSet.sizesRegularized[1] = 0;
  localB->WorkingSet.sizesRegularized[2] = 84;
  localB->WorkingSet.sizesRegularized[3] = localB->k;
  localB->WorkingSet.sizesRegularized[4] = localB->mUB;
  localB->WorkingSet.sizesRegPhaseOne[0] = localB->mFixed;
  localB->WorkingSet.sizesRegPhaseOne[1] = 0;
  localB->WorkingSet.sizesRegPhaseOne[2] = 84;
  localB->WorkingSet.sizesRegPhaseOne[3] = localB->k + 1;
  localB->WorkingSet.sizesRegPhaseOne[4] = localB->mUB;
  localB->WorkingSet.isActiveIdxNormal[0] = 1;
  localB->WorkingSet.isActiveIdxNormal[1] = localB->mFixed;
  localB->WorkingSet.isActiveIdxNormal[2] = 0;
  localB->WorkingSet.isActiveIdxNormal[3] = 84;
  localB->WorkingSet.isActiveIdxNormal[4] = localB->k - 84;
  localB->WorkingSet.isActiveIdxNormal[5] = localB->mUB;
  for (localB->idx = 0; localB->idx < 6; localB->idx++) {
    localB->WorkingSet.isActiveIdxRegPhaseOne[localB->idx] =
      localB->WorkingSet.isActiveIdxNormal[localB->idx];
  }

  for (localB->idx = 0; localB->idx < 5; localB->idx++) {
    localB->WorkingSet.isActiveIdxRegPhaseOne[localB->idx + 1] +=
      localB->WorkingSet.isActiveIdxRegPhaseOne[localB->idx];
  }

  for (localB->idx = 0; localB->idx < 6; localB->idx++) {
    localB->WorkingSet.isActiveIdx[localB->idx] =
      localB->WorkingSet.isActiveIdxRegPhaseOne[localB->idx];
  }

  localB->WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
  localB->WorkingSet.isActiveIdxRegPhaseOne[1] = localB->mFixed;
  localB->WorkingSet.isActiveIdxRegPhaseOne[2] = 0;
  localB->WorkingSet.isActiveIdxRegPhaseOne[3] = 84;
  localB->WorkingSet.isActiveIdxRegPhaseOne[4] = localB->k - 83;
  localB->WorkingSet.isActiveIdxRegPhaseOne[5] = localB->mUB;
  for (localB->idx = 0; localB->idx < 5; localB->idx++) {
    localB->WorkingSet.isActiveIdxNormal[localB->idx + 1] +=
      localB->WorkingSet.isActiveIdxNormal[localB->idx];
    localB->WorkingSet.isActiveIdxRegPhaseOne[localB->idx + 1] +=
      localB->WorkingSet.isActiveIdxRegPhaseOne[localB->idx];
  }

  for (localB->idx = 0; localB->idx < 6; localB->idx++) {
    localB->WorkingSet.isActiveIdxPhaseOne[localB->idx] =
      localB->WorkingSet.isActiveIdxRegPhaseOne[localB->idx];
  }

  localB->WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
  localB->WorkingSet.isActiveIdxRegPhaseOne[1] = localB->mFixed;
  localB->WorkingSet.isActiveIdxRegPhaseOne[2] = 0;
  localB->WorkingSet.isActiveIdxRegPhaseOne[3] = 84;
  localB->WorkingSet.isActiveIdxRegPhaseOne[4] = localB->k;
  localB->WorkingSet.isActiveIdxRegPhaseOne[5] = localB->mUB;
  for (localB->idx = 0; localB->idx < 5; localB->idx++) {
    localB->WorkingSet.isActiveIdxRegPhaseOne[localB->idx + 1] +=
      localB->WorkingSet.isActiveIdxRegPhaseOne[localB->idx];
  }

  for (localB->idx = 0; localB->idx < 6; localB->idx++) {
    localB->WorkingSet.isActiveIdxRegularized[localB->idx] =
      localB->WorkingSet.isActiveIdxRegPhaseOne[localB->idx];
  }

  localB->WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
  localB->WorkingSet.isActiveIdxRegPhaseOne[1] = localB->mFixed;
  localB->WorkingSet.isActiveIdxRegPhaseOne[2] = 0;
  localB->WorkingSet.isActiveIdxRegPhaseOne[3] = 84;
  localB->WorkingSet.isActiveIdxRegPhaseOne[4] = localB->k + 1;
  localB->WorkingSet.isActiveIdxRegPhaseOne[5] = localB->mUB;
  for (localB->idx = 0; localB->idx < 5; localB->idx++) {
    localB->WorkingSet.isActiveIdxRegPhaseOne[localB->idx + 1] +=
      localB->WorkingSet.isActiveIdxRegPhaseOne[localB->idx];
  }

  for (localB->idx = 0; localB->idx < 84; localB->idx++) {
    for (localB->colPos = 0; localB->colPos < 84; localB->colPos++) {
      localB->WorkingSet.Aineq[localB->colPos + 85 * localB->idx] = Aineq[84 *
        localB->colPos + localB->idx];
    }

    localB->WorkingSet.bineq[localB->idx] = bineq[localB->idx];
    localB->WorkingSet.lb[localB->idx] = -lb[localB->idx];
    localB->WorkingSet.ub[localB->idx] = ub[localB->idx];
  }

  ros_code_setProblemType(&localB->WorkingSet, 3);
  localB->idx = localB->WorkingSet.isActiveIdx[2];
  while (localB->idx < 254) {
    localB->WorkingSet.isActiveConstr[localB->idx - 1] = false;
    localB->idx++;
  }

  localB->WorkingSet.nWConstr[0] = localB->WorkingSet.sizes[0];
  localB->WorkingSet.nWConstr[1] = 0;
  localB->WorkingSet.nWConstr[2] = 0;
  localB->WorkingSet.nWConstr[3] = 0;
  localB->WorkingSet.nWConstr[4] = 0;
  localB->WorkingSet.nActiveConstr = localB->WorkingSet.nWConstr[0];
  localB->idx = 0;
  while (localB->idx <= localB->WorkingSet.sizes[0] - 1) {
    localB->WorkingSet.Wid[localB->idx] = 1;
    localB->WorkingSet.Wlocalidx[localB->idx] = localB->idx + 1;
    localB->WorkingSet.isActiveConstr[localB->idx] = true;
    localB->colPos = 85 * localB->idx - 1;
    localB->i_m = 0;
    while (localB->i_m <= localB->WorkingSet.indexFixed[localB->idx] - 2) {
      localB->WorkingSet.ATwset[(localB->i_m + localB->colPos) + 1] = 0.0;
      localB->i_m++;
    }

    localB->WorkingSet.ATwset[localB->WorkingSet.indexFixed[localB->idx] +
      localB->colPos] = 1.0;
    localB->i_m = localB->WorkingSet.indexFixed[localB->idx] + 1;
    while (localB->i_m <= localB->WorkingSet.nVar) {
      localB->WorkingSet.ATwset[localB->i_m + localB->colPos] = 0.0;
      localB->i_m++;
    }

    localB->WorkingSet.bwset[localB->idx] = localB->WorkingSet.ub
      [localB->WorkingSet.indexFixed[localB->idx] - 1];
    localB->idx++;
  }

  localB->WorkingSet.SLACK0 = 0.0;
  localB->ub_g = 1.0;
  localB->H_infnrm = 0.0;
  localB->f_infnrm = 0.0;
  for (localB->idx = 0; localB->idx < 84; localB->idx++) {
    localB->colSum = 0.0;
    localB->colPos = 85 * localB->idx;
    localB->b_colSum = 0.0;
    for (localB->i_m = 0; localB->i_m < 84; localB->i_m++) {
      localB->colSum += std::abs(localB->WorkingSet.Aineq[localB->i_m +
        localB->colPos]);
      localB->b_colSum += std::abs(H[84 * localB->idx + localB->i_m]);
    }

    localB->ub_g = std::fmax(localB->ub_g, localB->colSum);
    localB->H_infnrm = std::fmax(localB->H_infnrm, localB->b_colSum);
    localB->f_infnrm = std::fmax(localB->f_infnrm, std::abs(f[localB->idx]));
  }

  localB->expl_temp.RemainFeasible = false;
  localB->expl_temp.ProbRelTolFactor = std::fmax(std::fmax(localB->ub_g,
    localB->f_infnrm), localB->H_infnrm);
  localB->expl_temp.ConstrRelTolFactor = localB->ub_g;
  localB->expl_temp.MaxIterations = (((localB->mFixed + localB->k) + localB->mUB)
    + 84) * 10;
  ros_code_driver(H, f, &localB->solution, &localB->memspace,
                  &localB->WorkingSet, &localB->CholRegManager,
                  localB->expl_temp, &localB->QRManager, &localB->QPObjective,
                  localB);
  std::memcpy(&x[0], &localB->solution.xstar[0], 84U * sizeof(real_T));
  if (localB->solution.state > 0) {
    *fval = localB->solution.fstar;
  } else {
    *fval = ros_code_computeFval(&localB->QPObjective,
      localB->memspace.workspace_double, H, f, localB->solution.xstar, localB);
  }

  switch (localB->solution.state) {
   case 2:
    localB->solution.state = -3;
    break;

   case -3:
    localB->solution.state = -2;
    break;

   case 4:
    localB->solution.state = -2;
    break;
  }

  *exitflag = localB->solution.state;
}

static void ros_code_binary_expand_op_l(real_T in1[4410], int32_T in2, int32_T
  in4, int32_T in5, int32_T in6, int32_T in7, B_MPC_controller_ros_code_T
  *localB)
{
  int32_T in1_size_idx_0;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;

  // MATLAB Function: '<S4>/MPC//buildPredictionModel'
  in1_size_idx_0 = (in7 - in6) + 1 == 1 ? (in5 - in4) + 1 : (in7 - in6) + 1;
  stride_0_0 = ((in5 - in4) + 1 != 1);
  stride_1_0 = ((in7 - in6) + 1 != 1);
  loop_ub = (in7 - in6) + 1 == 1 ? (in5 - in4) + 1 : (in7 - in6) + 1;
  for (int32_T i_0{0}; i_0 < 42; i_0++) {
    for (int32_T i{0}; i < loop_ub; i++) {
      localB->in1_data[i + in1_size_idx_0 * i_0] = in1[(i * stride_0_0 + in4) +
        105 * i_0] + in1[(i * stride_1_0 + in6) + 105 * i_0];
    }
  }

  for (int32_T i_0{0}; i_0 < 42; i_0++) {
    for (int32_T i{0}; i < in1_size_idx_0; i++) {
      in1[(in2 + i) + 105 * i_0] = localB->in1_data[in1_size_idx_0 * i_0 + i];
    }
  }

  // End of MATLAB Function: '<S4>/MPC//buildPredictionModel'
}

// Function for MATLAB Function: '<S4>/MPC//buildPredictionModel'
static void ros_code_mtimes(const real_T A[25], const real_T B_data[], const
  int32_T B_size[2], real_T C_data[], int32_T C_size[2])
{
  C_size[0] = 5;
  C_size[1] = B_size[1];
  for (int32_T j{0}; j < B_size[1]; j++) {
    int32_T boffset;
    int32_T coffset;
    coffset = j * 5;
    boffset = j * B_size[0];
    for (int32_T i{0}; i < 5; i++) {
      real_T s;
      s = 0.0;
      for (int32_T k{0}; k < 5; k++) {
        s += A[k * 5 + i] * B_data[boffset + k];
      }

      C_data[coffset + i] = s;
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//buildPredictionModel'
static void ros_code_mtimes_p(const real_T B_data[], const int32_T B_size[2],
  real_T C_data[], int32_T C_size[2])
{
  static const int8_T b[15]{ 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 };

  C_size[0] = 3;
  C_size[1] = B_size[1];
  for (int32_T j{0}; j < B_size[1]; j++) {
    int32_T boffset;
    int32_T coffset;
    coffset = j * 3;
    boffset = j * B_size[0];
    for (int32_T i{0}; i < 3; i++) {
      real_T s;
      s = 0.0;
      for (int32_T k{0}; k < 5; k++) {
        s += static_cast<real_T>(b[k * 3 + i]) * B_data[boffset + k];
      }

      C_data[coffset + i] = s;
    }
  }
}

// Function for MATLAB Function: '<S4>/MPC//buildPredictionModel'
static void ros_code_mtimes_pg(const real_T A_data[], const int32_T A_size[2],
  const real_T B_data[], const int32_T B_size[2], real_T C_data[], int32_T
  C_size[2])
{
  C_size[0] = 3;
  C_size[1] = B_size[1];
  for (int32_T j{0}; j < B_size[1]; j++) {
    int32_T boffset;
    int32_T coffset;
    coffset = j * 3;
    boffset = j * B_size[0];
    C_data[coffset] = 0.0;
    C_data[coffset + 1] = 0.0;
    C_data[coffset + 2] = 0.0;
    for (int32_T k{0}; k < A_size[1]; k++) {
      real_T bkj;
      int32_T aoffset;
      aoffset = k * 3;
      bkj = B_data[boffset + k];
      C_data[coffset] += A_data[aoffset] * bkj;
      C_data[coffset + 1] += A_data[aoffset + 1] * bkj;
      C_data[coffset + 2] += A_data[aoffset + 2] * bkj;
    }
  }
}

// Output and update for atomic system: '<Root>/MPC_controller'
void ros_code_MPC_controller(real_T rtu_get_local_path, const real_T
  rtu_predict_state[126], const real_T rtu_current_state[5], real_T *rty_v,
  real_T *rty_w, B_MPC_controller_ros_code_T *localB)
{
  static const int8_T a[1764]{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1 };

  static const int8_T b_a[15]{ 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 };

  static const int8_T ed[10]{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 1 };

  static const int8_T fd[4]{ 1, 0, 0, 1 };

  int8_T d[2];

  // MATLAB Function: '<S4>/MPC//buildConstraintMatrix' incorporates:
  //   Constant: '<S4>/Constant'

  std::memset(&localB->Aueq[0], 0, 7056U * sizeof(real_T));
  for (localB->i = 0; localB->i < 84; localB->i++) {
    localB->Bueq[localB->i] = 0.0;
    localB->lb[localB->i] = 0.0;
    localB->ub[localB->i] = ros_code_P.constraint_param[8];
  }

  if (rtu_get_local_path != 0.0) {
    std::memset(&localB->A_p[0], 0, 1764U * sizeof(int8_T));
    std::memset(&localB->U_max[0], 0, 42U * sizeof(real_T));
    std::memset(&localB->U_min[0], 0, 42U * sizeof(real_T));
    std::memset(&localB->U_k[0], 0, 42U * sizeof(real_T));
    localB->E_2[1] = 0;
    localB->E_2[2] = 0;
    localB->E_2[0] = 1;
    localB->E_2[3] = 1;
    std::memset(&localB->E_2N[0], 0, 1764U * sizeof(int8_T));
    for (localB->i = 0; localB->i < 42; localB->i++) {
      localB->E_2N[localB->i + 42 * localB->i] = 1;
    }

    for (localB->i = 0; localB->i < 21; localB->i++) {
      if (localB->i >= 0) {
        localB->b = localB->i << 1;
        localB->c_oy = (localB->i + 1) << 1;
        if (localB->b + 1 > localB->c_oy) {
          localB->b = 0;
          localB->c_oy = 0;
        }

        d[0] = static_cast<int8_T>(localB->c_oy - localB->b);
      }

      localB->j = 0;
      while (localB->j <= localB->i) {
        localB->f = localB->j << 1;
        localB->c_oy = (localB->j + 1) << 1;
        if (localB->f + 1 > localB->c_oy) {
          localB->f = 0;
          localB->c_oy = 0;
        }

        d[1] = static_cast<int8_T>(localB->c_oy - localB->f);
        localB->loop_ub = d[1];
        for (localB->c_oy = 0; localB->c_oy < localB->loop_ub; localB->c_oy++) {
          localB->loop_ub_n = d[0];
          for (localB->E_2N_tmp = 0; localB->E_2N_tmp < localB->loop_ub_n;
               localB->E_2N_tmp++) {
            localB->A_p[(localB->b + localB->E_2N_tmp) + 42 * (localB->f +
              localB->c_oy)] = localB->E_2[d[0] * localB->c_oy +
              localB->E_2N_tmp];
          }
        }

        localB->j++;
      }

      localB->c_oy = localB->i << 1;
      if (localB->c_oy + 1 > ((localB->i + 1) << 1)) {
        localB->c_oy = 0;
      }

      localB->rtb_u_ref_idx_0 = rtu_predict_state[localB->i + 63];
      localB->U_max[localB->c_oy] = ros_code_P.constraint_param[1] -
        localB->rtb_u_ref_idx_0;
      localB->rtb_diff_U_k_1_idx_0 = rtu_predict_state[localB->i + 84];
      localB->U_max[localB->c_oy + 1] = ros_code_P.constraint_param[3] -
        localB->rtb_diff_U_k_1_idx_0;
      localB->c_oy = localB->i << 1;
      if (localB->c_oy + 1 > ((localB->i + 1) << 1)) {
        localB->c_oy = 0;
      }

      localB->U_min[localB->c_oy] = ros_code_P.constraint_param[0] -
        localB->rtb_u_ref_idx_0;
      localB->U_min[localB->c_oy + 1] = ros_code_P.constraint_param[2] -
        localB->rtb_diff_U_k_1_idx_0;
      localB->c_oy = localB->i << 1;
      if (localB->c_oy + 1 > ((localB->i + 1) << 1)) {
        localB->c_oy = 0;
      }

      localB->lb[localB->c_oy] = ros_code_P.constraint_param[4];
      localB->lb[localB->c_oy + 1] = ros_code_P.constraint_param[6];
      localB->c_oy = localB->i << 1;
      if (localB->c_oy + 1 > ((localB->i + 1) << 1)) {
        localB->c_oy = 0;
      }

      localB->ub[localB->c_oy] = ros_code_P.constraint_param[5];
      localB->ub[localB->c_oy + 1] = ros_code_P.constraint_param[7];
      localB->c_oy = localB->i << 1;
      if (localB->c_oy + 1 > ((localB->i + 1) << 1)) {
        localB->c_oy = 0;
      }

      localB->U_k[localB->c_oy] = rtu_current_state[3] - rtu_predict_state[63];
      localB->U_k[localB->c_oy + 1] = rtu_current_state[4] - rtu_predict_state
        [84];
    }

    for (localB->i = 0; localB->i < 42; localB->i++) {
      for (localB->c_oy = 0; localB->c_oy < 42; localB->c_oy++) {
        int8_T A;
        int8_T E_2N;
        localB->E_2N_tmp = 42 * localB->i + localB->c_oy;
        E_2N = localB->E_2N[localB->E_2N_tmp];
        A = localB->A_p[localB->E_2N_tmp];
        localB->E_2N_tmp = 84 * localB->i + localB->c_oy;
        localB->Aueq[localB->E_2N_tmp] = A;
        localB->b = (localB->i + 42) * 84 + localB->c_oy;
        localB->Aueq[localB->b] = -static_cast<real_T>(E_2N);
        localB->Aueq[localB->E_2N_tmp + 42] = -static_cast<real_T>(A);
        localB->Aueq[localB->b + 42] = E_2N;
      }

      localB->Bueq[localB->i] = localB->U_max[localB->i] - localB->U_k[localB->i];
      localB->Bueq[localB->i + 42] = -localB->U_min[localB->i] + localB->
        U_k[localB->i];
    }
  }

  // End of MATLAB Function: '<S4>/MPC//buildConstraintMatrix'

  // MATLAB Function: '<S4>/MPC//buildPredictionModel'
  std::memset(&localB->G[0], 0, 63U * sizeof(real_T));
  std::memset(&localB->Z[0], 0, 2646U * sizeof(real_T));
  localB->rtb_u_ref_idx_0 = 0.0;
  localB->rtb_diff_U_k_1_idx_0 = 0.0;
  localB->rtb_u_ref_idx_1 = 0.0;
  localB->rtb_diff_U_k_1_idx_1 = 0.0;
  if (rtu_get_local_path != 0.0) {
    std::memset(&localB->a[0], 0, 315U * sizeof(real_T));
    std::memset(&localB->A_21[0], 0, 25U * sizeof(real_T));
    ros_code_eye(localB->A_all);
    std::memset(&localB->B_all[0], 0, 4410U * sizeof(real_T));
    localB->rtb_diff_U_k_1_idx_0 = rtu_current_state[3] - rtu_predict_state[63];
    localB->rtb_diff_U_k_1_idx_1 = rtu_current_state[4] - rtu_predict_state[84];
    localB->rtb_u_ref_idx_0 = rtu_predict_state[63];
    localB->rtb_u_ref_idx_1 = rtu_predict_state[84];
    localB->B1[3] = 0.0;
    localB->B1[4] = 0.0;
    localB->B1[2] = 0.0;
    localB->B1[5] = 0.05;
    for (localB->c_oy = 0; localB->c_oy < 15; localB->c_oy++) {
      localB->iv[localB->c_oy] = b_a[localB->c_oy];
    }

    for (localB->i = 0; localB->i < 21; localB->i++) {
      localB->B1_tmp_tmp = rtu_predict_state[localB->i + 42];
      localB->B1_tmp = std::sin(localB->B1_tmp_tmp);
      localB->B1_tmp_tmp = std::cos(localB->B1_tmp_tmp);
      localB->B1[0] = 0.05 * localB->B1_tmp_tmp;
      localB->B1[1] = 0.05 * localB->B1_tmp;
      localB->A2[0] = 1.0;
      localB->A2[5] = 0.0;
      localB->A2_tmp = rtu_predict_state[localB->i + 63];
      localB->A2[10] = localB->A2_tmp * -0.05 * localB->B1_tmp;
      localB->A2[1] = 0.0;
      localB->A2[6] = 1.0;
      localB->A2[11] = localB->A2_tmp * 0.05 * localB->B1_tmp_tmp;
      localB->A2[2] = 0.0;
      localB->A2[7] = 0.0;
      localB->A2[12] = 1.0;
      for (localB->c_oy = 0; localB->c_oy < 2; localB->c_oy++) {
        localB->E_2N_tmp = (localB->c_oy + 3) * 5;
        localB->A2[localB->E_2N_tmp] = localB->B1[3 * localB->c_oy];
        localB->A2[localB->E_2N_tmp + 1] = localB->B1[3 * localB->c_oy + 1];
        localB->A2[localB->E_2N_tmp + 2] = localB->B1[3 * localB->c_oy + 2];
      }

      for (localB->c_oy = 0; localB->c_oy < 5; localB->c_oy++) {
        localB->E_2N_tmp = localB->c_oy << 1;
        localB->A2[5 * localB->c_oy + 3] = ed[localB->E_2N_tmp];
        localB->A2[5 * localB->c_oy + 4] = ed[localB->E_2N_tmp + 1];
      }

      for (localB->c_oy = 0; localB->c_oy < 2; localB->c_oy++) {
        localB->B2[5 * localB->c_oy] = localB->B1[3 * localB->c_oy];
        localB->B2[5 * localB->c_oy + 1] = localB->B1[3 * localB->c_oy + 1];
        localB->B2[5 * localB->c_oy + 2] = localB->B1[3 * localB->c_oy + 2];
        localB->E_2N_tmp = localB->c_oy << 1;
        localB->B2[5 * localB->c_oy + 3] = fd[localB->E_2N_tmp];
        localB->B2[5 * localB->c_oy + 4] = fd[localB->E_2N_tmp + 1];
      }

      localB->b = localB->i * 3;
      localB->j = (localB->i + 1) * 3;
      if (localB->b + 1 > localB->j) {
        localB->pc = 0;
        localB->loop_ub_n = 0;
      } else {
        localB->pc = localB->b;
        localB->loop_ub_n = localB->j;
      }

      localB->qc_tmp = localB->i << 1;
      localB->rc_tmp = (localB->i + 1) << 1;
      if (localB->qc_tmp + 1 > localB->rc_tmp) {
        localB->tc = 0;
        localB->sc = 0;
      } else {
        localB->tc = localB->qc_tmp;
        localB->sc = localB->rc_tmp;
      }

      for (localB->c_oy = 0; localB->c_oy < 3; localB->c_oy++) {
        for (localB->E_2N_tmp = 0; localB->E_2N_tmp < 2; localB->E_2N_tmp++) {
          localB->loop_ub = 3 * localB->E_2N_tmp + localB->c_oy;
          localB->dv7[localB->loop_ub] = 0.0;
          for (localB->f = 0; localB->f < 5; localB->f++) {
            localB->dv7[localB->loop_ub] += static_cast<real_T>(localB->iv[3 *
              localB->f + localB->c_oy]) * localB->B2[5 * localB->E_2N_tmp +
              localB->f];
          }
        }
      }

      d[0] = static_cast<int8_T>(localB->loop_ub_n - localB->pc);
      d[1] = static_cast<int8_T>(localB->sc - localB->tc);
      localB->loop_ub = d[1];
      for (localB->c_oy = 0; localB->c_oy < localB->loop_ub; localB->c_oy++) {
        localB->loop_ub_n = d[0];
        for (localB->E_2N_tmp = 0; localB->E_2N_tmp < localB->loop_ub_n;
             localB->E_2N_tmp++) {
          localB->Z[(localB->pc + localB->E_2N_tmp) + 63 * (localB->tc +
            localB->c_oy)] = localB->dv7[d[0] * localB->c_oy + localB->E_2N_tmp];
        }
      }

      if (localB->i + 1 == 1) {
        std::memcpy(&localB->A_21[0], &localB->A2[0], 25U * sizeof(real_T));
        for (localB->c_oy = 0; localB->c_oy < 3; localB->c_oy++) {
          for (localB->E_2N_tmp = 0; localB->E_2N_tmp < 5; localB->E_2N_tmp++) {
            localB->b = 63 * localB->E_2N_tmp + localB->c_oy;
            localB->a[localB->b] = 0.0;
            for (localB->loop_ub = 0; localB->loop_ub < 5; localB->loop_ub++) {
              localB->a[localB->b] += static_cast<real_T>(localB->iv[3 *
                localB->loop_ub + localB->c_oy]) * localB->A2[5 *
                localB->E_2N_tmp + localB->loop_ub];
            }
          }
        }

        for (localB->c_oy = 0; localB->c_oy < 2; localB->c_oy++) {
          for (localB->E_2N_tmp = 0; localB->E_2N_tmp < 5; localB->E_2N_tmp++) {
            localB->B_all[localB->E_2N_tmp + 105 * localB->c_oy] = localB->B2[5 *
              localB->c_oy + localB->E_2N_tmp];
          }
        }
      } else {
        localB->f = 5 * localB->i;
        localB->pc = (localB->i + 1) * 5;
        if (localB->f + 1 > localB->pc) {
          localB->tc = 0;
          localB->c_oy = 0;
        } else {
          localB->tc = localB->f;
          localB->c_oy = localB->pc;
        }

        if (localB->qc_tmp + 1 > localB->rc_tmp) {
          localB->qc_tmp = 0;
          localB->rc_tmp = 0;
        }

        d[0] = static_cast<int8_T>(localB->c_oy - localB->tc);
        d[1] = static_cast<int8_T>(localB->rc_tmp - localB->qc_tmp);
        localB->loop_ub = d[1];
        for (localB->c_oy = 0; localB->c_oy < localB->loop_ub; localB->c_oy++) {
          localB->loop_ub_n = d[0];
          for (localB->E_2N_tmp = 0; localB->E_2N_tmp < localB->loop_ub_n;
               localB->E_2N_tmp++) {
            localB->B_all[(localB->tc + localB->E_2N_tmp) + 105 *
              (localB->qc_tmp + localB->c_oy)] = localB->B2[d[0] * localB->c_oy
              + localB->E_2N_tmp];
          }
        }

        if (localB->f + 1 > localB->pc) {
          localB->qc_tmp = 0;
          localB->c_oy = 0;
        } else {
          localB->qc_tmp = localB->f;
          localB->c_oy = localB->pc;
        }

        localB->loop_ub_n = (localB->i - 1) * 5;
        if (localB->loop_ub_n + 1 > localB->f) {
          localB->rc_tmp = 0;
          localB->E_2N_tmp = 0;
        } else {
          localB->rc_tmp = localB->loop_ub_n;
          localB->E_2N_tmp = localB->f;
        }

        if (localB->f + 1 > localB->pc) {
          localB->tc = 0;
        } else {
          localB->tc = localB->f;
        }

        localB->loop_ub = localB->c_oy - localB->qc_tmp;
        if (localB->E_2N_tmp - localB->rc_tmp == localB->loop_ub) {
          for (localB->c_oy = 0; localB->c_oy < 42; localB->c_oy++) {
            localB->sc = (localB->loop_ub / 2) << 1;
            localB->vectorUB = localB->sc - 2;
            for (localB->E_2N_tmp = 0; localB->E_2N_tmp <= localB->vectorUB;
                 localB->E_2N_tmp += 2) {
              __m128d tmp;
              __m128d tmp_0;
              tmp = _mm_loadu_pd(&localB->B_all[(localB->qc_tmp +
                localB->E_2N_tmp) + 105 * localB->c_oy]);
              tmp_0 = _mm_loadu_pd(&localB->B_all[(localB->rc_tmp +
                localB->E_2N_tmp) + 105 * localB->c_oy]);
              _mm_storeu_pd(&localB->B_all_data[localB->E_2N_tmp +
                            localB->loop_ub * localB->c_oy], _mm_add_pd(tmp,
                tmp_0));
            }

            for (localB->E_2N_tmp = localB->sc; localB->E_2N_tmp <
                 localB->loop_ub; localB->E_2N_tmp++) {
              localB->B_all_data[localB->E_2N_tmp + localB->loop_ub *
                localB->c_oy] = localB->B_all[(localB->qc_tmp + localB->E_2N_tmp)
                + 105 * localB->c_oy] + localB->B_all[(localB->rc_tmp +
                localB->E_2N_tmp) + 105 * localB->c_oy];
            }
          }

          for (localB->c_oy = 0; localB->c_oy < 42; localB->c_oy++) {
            for (localB->E_2N_tmp = 0; localB->E_2N_tmp < localB->loop_ub;
                 localB->E_2N_tmp++) {
              localB->B_all[(localB->tc + localB->E_2N_tmp) + 105 * localB->c_oy]
                = localB->B_all_data[localB->loop_ub * localB->c_oy +
                localB->E_2N_tmp];
            }
          }
        } else {
          ros_code_binary_expand_op_l(localB->B_all, localB->tc, localB->qc_tmp,
            localB->c_oy - 1, localB->rc_tmp, localB->E_2N_tmp - 1, localB);
        }

        if (localB->i - 1 >= 0) {
          if (localB->loop_ub_n + 1 > localB->f) {
            localB->ab = 0;
            localB->y = 0;
          } else {
            localB->ab = localB->loop_ub_n;
            localB->y = localB->f;
          }

          if (localB->f + 1 > localB->pc) {
            localB->ib = 0;
            localB->qb = 0;
            localB->pb = 0;
            localB->yb = 0;
            localB->xb = 0;
          } else {
            localB->ib = localB->f;
            localB->qb = localB->f;
            localB->pb = localB->pc;
            localB->yb = localB->f;
            localB->xb = localB->pc;
          }

          if (localB->b + 1 > localB->j) {
            localB->xc = 0;
          } else {
            localB->xc = localB->b;
          }
        }

        localB->qc_tmp = 0;
        while (localB->qc_tmp <= localB->i - 1) {
          localB->rc_tmp = localB->qc_tmp * 5;
          localB->tc = (localB->qc_tmp + 1) * 5;
          if (localB->rc_tmp + 1 > localB->tc) {
            localB->sc = 0;
            localB->c_oy = 0;
            localB->vectorUB = 0;
          } else {
            localB->sc = localB->rc_tmp;
            localB->c_oy = localB->tc;
            localB->vectorUB = localB->rc_tmp;
          }

          localB->loop_ub = localB->y - localB->ab;
          localB->A_all_size[0] = localB->loop_ub;
          localB->loop_ub_n = localB->c_oy - localB->sc;
          localB->A_all_size[1] = localB->loop_ub_n;
          for (localB->c_oy = 0; localB->c_oy < localB->loop_ub_n; localB->c_oy
               ++) {
            for (localB->E_2N_tmp = 0; localB->E_2N_tmp < localB->loop_ub;
                 localB->E_2N_tmp++) {
              localB->A_all_data_m[localB->E_2N_tmp + localB->loop_ub *
                localB->c_oy] = localB->A_all[((localB->sc + localB->c_oy) * 105
                + localB->ab) + localB->E_2N_tmp];
            }
          }

          ros_code_mtimes(localB->A2, localB->A_all_data_m, localB->A_all_size,
                          localB->tmp_data, localB->tmp_size);
          localB->loop_ub = localB->tmp_size[1];
          for (localB->c_oy = 0; localB->c_oy < localB->loop_ub; localB->c_oy++)
          {
            for (localB->E_2N_tmp = 0; localB->E_2N_tmp < 5; localB->E_2N_tmp++)
            {
              localB->A_all[(localB->ib + localB->E_2N_tmp) + 105 *
                (localB->vectorUB + localB->c_oy)] = localB->tmp_data[5 *
                localB->c_oy + localB->E_2N_tmp];
            }
          }

          if (localB->rc_tmp + 1 > localB->tc) {
            localB->rc_tmp = 0;
            localB->tc = 0;
          }

          localB->sc = localB->qc_tmp << 1;
          localB->c_oy = (localB->qc_tmp + 1) << 1;
          if (localB->sc + 1 > localB->c_oy) {
            localB->vectorUB = 0;
            localB->cc = 0;
            localB->sc = 0;
          } else {
            localB->vectorUB = localB->sc;
            localB->cc = localB->c_oy;
          }

          localB->loop_ub = localB->pb - localB->qb;
          localB->A_all_size_n[0] = localB->loop_ub;
          localB->loop_ub_n = localB->tc - localB->rc_tmp;
          localB->A_all_size_n[1] = localB->loop_ub_n;
          for (localB->c_oy = 0; localB->c_oy < localB->loop_ub_n; localB->c_oy
               ++) {
            for (localB->E_2N_tmp = 0; localB->E_2N_tmp < localB->loop_ub;
                 localB->E_2N_tmp++) {
              localB->A_all_data[localB->E_2N_tmp + localB->loop_ub *
                localB->c_oy] = localB->A_all[((localB->rc_tmp + localB->c_oy) *
                105 + localB->qb) + localB->E_2N_tmp];
            }
          }

          localB->loop_ub = localB->xb - localB->yb;
          localB->B_all_size[0] = localB->loop_ub;
          localB->loop_ub_n = localB->cc - localB->vectorUB;
          localB->B_all_size[1] = localB->loop_ub_n;
          for (localB->c_oy = 0; localB->c_oy < localB->loop_ub_n; localB->c_oy
               ++) {
            for (localB->E_2N_tmp = 0; localB->E_2N_tmp < localB->loop_ub;
                 localB->E_2N_tmp++) {
              localB->B_all_data_c[localB->E_2N_tmp + localB->loop_ub *
                localB->c_oy] = localB->B_all[((localB->vectorUB + localB->c_oy)
                * 105 + localB->yb) + localB->E_2N_tmp];
            }
          }

          ros_code_mtimes_p(localB->A_all_data, localB->A_all_size_n,
                            localB->tmp_data_c, localB->tmp_size);
          ros_code_mtimes_pg(localB->tmp_data_c, localB->tmp_size,
                             localB->B_all_data_c, localB->B_all_size,
                             localB->tmp_data_cv, localB->tmp_size_i);
          localB->loop_ub = localB->tmp_size_i[1];
          for (localB->c_oy = 0; localB->c_oy < localB->loop_ub; localB->c_oy++)
          {
            localB->E_2N_tmp = (localB->sc + localB->c_oy) * 63 + localB->xc;
            localB->Z[localB->E_2N_tmp] = localB->tmp_data_cv[3 * localB->c_oy];
            localB->Z[localB->E_2N_tmp + 1] = localB->tmp_data_cv[3 *
              localB->c_oy + 1];
            localB->Z[localB->E_2N_tmp + 2] = localB->tmp_data_cv[3 *
              localB->c_oy + 2];
          }

          localB->qc_tmp++;
        }

        if (localB->f + 1 > localB->pc) {
          localB->f = 0;
          localB->pc = 0;
        }

        if (localB->b + 1 > localB->j) {
          localB->b = 0;
          localB->j = 0;
        }

        localB->loop_ub = localB->pc - localB->f;
        for (localB->c_oy = 0; localB->c_oy < 5; localB->c_oy++) {
          for (localB->E_2N_tmp = 0; localB->E_2N_tmp < localB->loop_ub;
               localB->E_2N_tmp++) {
            localB->A_all_data_k[localB->E_2N_tmp + localB->loop_ub *
              localB->c_oy] = localB->A_all[(localB->f + localB->E_2N_tmp) + 105
              * localB->c_oy];
          }
        }

        for (localB->c_oy = 0; localB->c_oy < 3; localB->c_oy++) {
          for (localB->E_2N_tmp = 0; localB->E_2N_tmp < 5; localB->E_2N_tmp++) {
            localB->loop_ub = 3 * localB->E_2N_tmp + localB->c_oy;
            localB->dv4[localB->loop_ub] = 0.0;
            for (localB->f = 0; localB->f < 5; localB->f++) {
              localB->dv4[localB->loop_ub] += static_cast<real_T>(localB->iv[3 *
                localB->f + localB->c_oy]) * localB->A_all_data_k[5 *
                localB->E_2N_tmp + localB->f];
            }
          }

          for (localB->E_2N_tmp = 0; localB->E_2N_tmp < 5; localB->E_2N_tmp++) {
            localB->loop_ub = 3 * localB->E_2N_tmp + localB->c_oy;
            localB->dv5[localB->loop_ub] = 0.0;
            for (localB->f = 0; localB->f < 5; localB->f++) {
              localB->dv5[localB->loop_ub] += localB->dv4[3 * localB->f +
                localB->c_oy] * localB->A_21[5 * localB->E_2N_tmp + localB->f];
            }
          }
        }

        d[0] = static_cast<int8_T>(localB->j - localB->b);
        d[1] = 5;
        localB->loop_ub = d[0];
        for (localB->c_oy = 0; localB->c_oy < 5; localB->c_oy++) {
          for (localB->E_2N_tmp = 0; localB->E_2N_tmp < localB->loop_ub;
               localB->E_2N_tmp++) {
            localB->a[(localB->b + localB->E_2N_tmp) + 63 * localB->c_oy] =
              localB->dv5[d[0] * localB->c_oy + localB->E_2N_tmp];
          }
        }
      }
    }

    localB->rtu_current_state[0] = rtu_current_state[0] - rtu_predict_state[0];
    localB->rtu_current_state[1] = rtu_current_state[1] - rtu_predict_state[21];
    localB->B1_tmp = rtu_current_state[2] - rtu_predict_state[42];
    localB->rtu_current_state[2] = rt_atan2d_snf(std::sin(localB->B1_tmp), std::
      cos(localB->B1_tmp));
    localB->rtu_current_state[3] = localB->rtb_diff_U_k_1_idx_0;
    localB->rtu_current_state[4] = localB->rtb_diff_U_k_1_idx_1;
    for (localB->c_oy = 0; localB->c_oy < 63; localB->c_oy++) {
      localB->a_g[localB->c_oy] = 0.0;
      for (localB->E_2N_tmp = 0; localB->E_2N_tmp < 5; localB->E_2N_tmp++) {
        localB->a_g[localB->c_oy] += localB->a[63 * localB->E_2N_tmp +
          localB->c_oy] * localB->rtu_current_state[localB->E_2N_tmp];
      }

      localB->G[localB->c_oy] = localB->a_g[localB->c_oy];
    }
  }

  // End of MATLAB Function: '<S4>/MPC//buildPredictionModel'

  // MATLAB Function: '<S4>/MPC//solveQuadraticProgramming' incorporates:
  //   Constant: '<S4>/Constant1'

  *rty_v = 0.0;
  *rty_w = 0.0;
  if (rtu_get_local_path != 0.0) {
    std::memset(&localB->Q[0], 0, 3969U * sizeof(real_T));
    std::memset(&localB->R[0], 0, 1764U * sizeof(real_T));
    localB->dv6[0] = ros_code_P.MPC_cost_param[0];
    localB->dv6[3] = 0.0;
    localB->dv6[6] = 0.0;
    localB->dv6[1] = 0.0;
    localB->dv6[4] = ros_code_P.MPC_cost_param[1];
    localB->dv6[7] = 0.0;
    localB->dv6[2] = 0.0;
    localB->dv6[5] = 0.0;
    localB->dv6[8] = ros_code_P.MPC_cost_param[2];
    localB->dv8[0] = ros_code_P.MPC_cost_param[6];
    localB->dv8[2] = 0.0;
    localB->dv8[1] = 0.0;
    localB->dv8[3] = ros_code_P.MPC_cost_param[7];
    for (localB->i = 0; localB->i < 20; localB->i++) {
      localB->f = localB->i * 3;
      localB->pc = (localB->i + 1) * 3;
      if (localB->f + 1 > localB->pc) {
        localB->tc = 0;
        localB->c_oy = 0;
        localB->f = 0;
        localB->pc = 0;
      } else {
        localB->tc = localB->f;
        localB->c_oy = localB->pc;
      }

      d[0] = static_cast<int8_T>(localB->c_oy - localB->tc);
      d[1] = static_cast<int8_T>(localB->pc - localB->f);
      localB->loop_ub = d[1];
      for (localB->c_oy = 0; localB->c_oy < localB->loop_ub; localB->c_oy++) {
        localB->loop_ub_n = d[0];
        for (localB->E_2N_tmp = 0; localB->E_2N_tmp < localB->loop_ub_n;
             localB->E_2N_tmp++) {
          localB->Q[(localB->tc + localB->E_2N_tmp) + 63 * (localB->f +
            localB->c_oy)] = localB->dv6[d[0] * localB->c_oy + localB->E_2N_tmp];
        }
      }

      localB->ab = localB->i << 1;
      localB->y = (localB->i + 1) << 1;
      if (localB->ab + 1 > localB->y) {
        localB->qc_tmp = 0;
        localB->c_oy = 0;
        localB->ab = 0;
        localB->y = 0;
      } else {
        localB->qc_tmp = localB->ab;
        localB->c_oy = localB->y;
      }

      d[0] = static_cast<int8_T>(localB->c_oy - localB->qc_tmp);
      d[1] = static_cast<int8_T>(localB->y - localB->ab);
      localB->loop_ub = d[1];
      for (localB->c_oy = 0; localB->c_oy < localB->loop_ub; localB->c_oy++) {
        localB->loop_ub_n = d[0];
        for (localB->E_2N_tmp = 0; localB->E_2N_tmp < localB->loop_ub_n;
             localB->E_2N_tmp++) {
          localB->R[(localB->qc_tmp + localB->E_2N_tmp) + 42 * (localB->ab +
            localB->c_oy)] = localB->dv8[d[0] * localB->c_oy + localB->E_2N_tmp];
        }
      }
    }

    localB->Q[3840] = ros_code_P.MPC_cost_param[3];
    localB->Q[3903] = 0.0;
    localB->Q[3966] = 0.0;
    localB->Q[3841] = 0.0;
    localB->Q[3904] = ros_code_P.MPC_cost_param[4];
    localB->Q[3967] = 0.0;
    localB->Q[3842] = 0.0;
    localB->Q[3905] = 0.0;
    localB->Q[3968] = ros_code_P.MPC_cost_param[5];
    localB->R[1720] = ros_code_P.MPC_cost_param[6];
    localB->R[1762] = 0.0;
    localB->R[1721] = 0.0;
    localB->R[1763] = ros_code_P.MPC_cost_param[7];
    for (localB->c_oy = 0; localB->c_oy < 63; localB->c_oy++) {
      for (localB->E_2N_tmp = 0; localB->E_2N_tmp < 42; localB->E_2N_tmp++) {
        localB->loop_ub = 42 * localB->c_oy + localB->E_2N_tmp;
        localB->dv1[localB->loop_ub] = 0.0;
        for (localB->f = 0; localB->f < 63; localB->f++) {
          localB->dv1[localB->loop_ub] += localB->Z[63 * localB->E_2N_tmp +
            localB->f] * 2.0 * localB->Q[63 * localB->c_oy + localB->f];
        }
      }
    }

    for (localB->c_oy = 0; localB->c_oy < 42; localB->c_oy++) {
      for (localB->E_2N_tmp = 0; localB->E_2N_tmp < 42; localB->E_2N_tmp++) {
        localB->B1_tmp = 0.0;
        for (localB->loop_ub = 0; localB->loop_ub < 63; localB->loop_ub++) {
          localB->B1_tmp += localB->dv1[42 * localB->loop_ub + localB->c_oy] *
            localB->Z[63 * localB->E_2N_tmp + localB->loop_ub];
        }

        localB->loop_ub = 42 * localB->E_2N_tmp + localB->c_oy;
        localB->dv2[localB->loop_ub] = localB->R[localB->loop_ub] +
          localB->B1_tmp;
      }
    }

    localB->B1_tmp = ros_code_P.MPC_cost_param[8];
    for (localB->c_oy = 0; localB->c_oy < 63; localB->c_oy++) {
      localB->a_g[localB->c_oy] = 0.0;
      for (localB->E_2N_tmp = 0; localB->E_2N_tmp < 63; localB->E_2N_tmp++) {
        localB->a_g[localB->c_oy] += localB->Q[63 * localB->c_oy +
          localB->E_2N_tmp] * (2.0 * localB->G[localB->E_2N_tmp]);
      }
    }

    for (localB->c_oy = 0; localB->c_oy < 42; localB->c_oy++) {
      localB->U_max[localB->c_oy] = 0.0;
      for (localB->E_2N_tmp = 0; localB->E_2N_tmp < 63; localB->E_2N_tmp++) {
        localB->U_max[localB->c_oy] += localB->Z[63 * localB->c_oy +
          localB->E_2N_tmp] * localB->a_g[localB->E_2N_tmp];
      }

      for (localB->E_2N_tmp = 0; localB->E_2N_tmp < 42; localB->E_2N_tmp++) {
        localB->loop_ub = 84 * localB->c_oy + localB->E_2N_tmp;
        localB->f = 42 * localB->c_oy + localB->E_2N_tmp;
        localB->dv[localB->loop_ub] = localB->dv2[localB->f];
        localB->i = (localB->c_oy + 42) * 84 + localB->E_2N_tmp;
        localB->dv[localB->i] = 0.0;
        localB->dv[localB->loop_ub + 42] = 0.0;
        localB->dv[localB->i + 42] = static_cast<real_T>(a[localB->f]) *
          localB->B1_tmp * 2.0;
      }

      localB->dv3[localB->c_oy] = localB->U_max[localB->c_oy];
      localB->dv3[localB->c_oy + 42] = 0.0;
    }

    ros_code_quadprog(localB->dv, localB->dv3, localB->Aueq, localB->Bueq,
                      localB->lb, localB->ub, localB->x, &localB->B1_tmp,
                      &localB->B1_tmp_tmp, localB);
    if (localB->B1_tmp_tmp != 0.0) {
      *rty_v = (localB->x[0] + localB->rtb_u_ref_idx_0) +
        localB->rtb_diff_U_k_1_idx_0;
      *rty_w = (localB->x[1] + localB->rtb_u_ref_idx_1) +
        localB->rtb_diff_U_k_1_idx_1;
    }
  }

  // End of MATLAB Function: '<S4>/MPC//solveQuadraticProgramming'
}

//
// File trailer for generated code.
//
// [EOF]
//
