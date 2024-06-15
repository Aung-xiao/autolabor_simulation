//
// File: ros_code.h
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
#ifndef RTW_HEADER_ros_code_h_
#define RTW_HEADER_ros_code_h_
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "ros_code_types.h"
#include "current_state_convert.h"
#include "MPC_controller.h"
#include "Lattice_planner.h"
#include "Global_planner.h"

extern "C" {

#include "rt_nonfinite.h"

}
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
  real_T predict_state[126];           // '<S3>/pathConvert'
  SL_Bus_ros_code_nav_msgs_Odometry In1;// '<S26>/In1'
  SL_Bus_ros_code_nav_msgs_Odometry b_varargout_2;
  real_T global_path_array[60];        // '<S11>/getGlobalPathData'
  real_T RateTransition13[30];         // '<Root>/Rate Transition13'
  real_T object_array_F[30];           // '<S2>/objectConvert'
  real_T preprocess_global_path_array[10000];// '<S11>/getGlobalPathData'
  SL_Bus_ros_code_geometry_msgs_Twist BusAssignment2;// '<Root>/Bus Assignment2' 
  real_T rtb_current_state_C_i_m[5];
  real_T current_state_C[5];           // '<S7>/MATLAB Function'
  real_T get_global_pose;              // '<S11>/getGlobalPathData'
  real_T object_array[50];             // '<S2>/getObjectData'
  real_T rtb_w_cl;
  real_T rtb_v_k;
  real_T rtb_get_local_path_c;
  boolean_T b_varargout_1;
  B_current_state_convert_ros_c_T current_state_convert;// '<Root>/current_state_convert' 
  B_MPC_controller_ros_code_T MPC_controller;// '<Root>/MPC_controller'
  B_Lattice_planner_ros_code_T Lattice_planner;// '<Root>/Lattice_planner'
  B_Global_planner_ros_code_T Global_planner;// '<Root>/Global_planner'
};

// Block states (default storage) for system '<Root>'
struct DW_ros_code_T {
  ros_slroscpp_internal_block_S_T obj; // '<S6>/SourceBlock'
  ros_slroscpp_internal_block_P_T obj_d;// '<S5>/SinkBlock'
  real_T RateTransition13_Buffer0[30]; // '<Root>/Rate Transition13'
  DW_Lattice_planner_ros_code_T Lattice_planner;// '<Root>/Lattice_planner'
  DW_Global_planner_ros_code_T Global_planner;// '<Root>/Global_planner'
};

// Parameters (default storage)
struct P_ros_code_T_ {
  real_T MPC_cost_param[9];            // Variable: MPC_cost_param
                                          //  Referenced by: '<S4>/Constant1'

  real_T constraint_param[9];          // Variable: constraint_param
                                          //  Referenced by: '<S4>/Constant'

  real_T path_cost_param[6];           // Variable: path_cost_param
                                          //  Referenced by: '<S3>/Constant2'

  real_T reduce_param[6];              // Variable: reduce_param
                                          //  Referenced by: '<S3>/Constant1'

  real_T sample_param[12];             // Variable: sample_param
                                          //  Referenced by: '<S3>/Constant'

  SL_Bus_ros_code_nav_msgs_Odometry Out1_Y0;// Computed Parameter: Out1_Y0
                                               //  Referenced by: '<S26>/Out1'

  SL_Bus_ros_code_nav_msgs_Odometry Constant_Value;// Computed Parameter: Constant_Value
                                                      //  Referenced by: '<S6>/Constant'

  SL_Bus_ros_code_geometry_msgs_Twist Constant_Value_p;// Computed Parameter: Constant_Value_p
                                                          //  Referenced by: '<S1>/Constant'

  real_T RateTransition13_InitialConditi;// Expression: 0
                                            //  Referenced by: '<Root>/Rate Transition13'

  P_Lattice_planner_ros_code_T Lattice_planner;// '<Root>/Lattice_planner'
  P_Global_planner_ros_code_T Global_planner;// '<Root>/Global_planner'
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
      uint8_T TID[4];
    } TaskCounters;

    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[4];
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
//  '<S7>'   : 'ros_code/current_state_convert'
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
//  '<S27>'  : 'ros_code/current_state_convert/MATLAB Function'

#endif                                 // RTW_HEADER_ros_code_h_

//
// File trailer for generated code.
//
// [EOF]
//
