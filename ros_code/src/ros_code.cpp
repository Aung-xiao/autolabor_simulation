//
// File: ros_code.cpp
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
#include "ros_code.h"
#include "Global_planner.h"
#include <cstring>
#include "current_state_convert.h"
#include "Lattice_planner.h"
#include "MPC_controller.h"
#include "rtwtypes.h"
#include "ros_code_private.h"

extern "C" {

#include "rt_nonfinite.h"

}
// Block signals (default storage)
  B_ros_code_T ros_code_B;

// Block states (default storage)
DW_ros_code_T ros_code_DW;

// Real-time model
RT_MODEL_ros_code_T ros_code_M_{ };

RT_MODEL_ros_code_T *const ros_code_M{ &ros_code_M_ };

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
  if ((ros_code_M->Timing.TaskCounters.TID[2]) > 4) {// Sample time: [0.05s, 0.0s] 
    ros_code_M->Timing.TaskCounters.TID[2] = 0;
  }

  (ros_code_M->Timing.TaskCounters.TID[3])++;
  if ((ros_code_M->Timing.TaskCounters.TID[3]) > 9) {// Sample time: [0.1s, 0.0s] 
    ros_code_M->Timing.TaskCounters.TID[3] = 0;
  }
}

// Model step function
void ros_code_step(void)
{
  real_T *rtb_RateTransition16_0;
  real_T *rtb_RateTransition17_0;
  if (ros_code_M->Timing.TaskCounters.TID[2] == 0) {
    // Outputs for Atomic SubSystem: '<Root>/Subscribe2'
    // MATLABSystem: '<S6>/SourceBlock'
    ros_code_B.b_varargout_1 = Sub_ros_code_1880.getLatestMessage
      (&ros_code_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S26>/Enable'

    if (ros_code_B.b_varargout_1) {
      // SignalConversion generated from: '<S26>/In1'
      ros_code_B.In1 = ros_code_B.b_varargout_2;
    }

    // End of MATLABSystem: '<S6>/SourceBlock'
    // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe2'

    // Outputs for Atomic SubSystem: '<Root>/current_state_convert'
    ros_code_current_state_convert(&ros_code_B.In1, ros_code_B.current_state_C,
      &ros_code_B.current_state_convert);

    // End of Outputs for SubSystem: '<Root>/current_state_convert'
  }

  if (ros_code_M->Timing.TaskCounters.TID[3] == 0) {
    // Outputs for Atomic SubSystem: '<Root>/Global_planner'
    ros_code_Global_planner(&ros_code_B.get_global_pose,
      ros_code_B.preprocess_global_path_array, ros_code_B.global_path_array,
      ros_code_B.object_array_F, ros_code_B.object_array,
      &ros_code_B.Global_planner);

    // End of Outputs for SubSystem: '<Root>/Global_planner'
  }

  // RateTransition: '<Root>/Rate Transition18' incorporates:
  //   Clock: '<Root>/Clock3'

  if (ros_code_M->Timing.TaskCounters.TID[2] == 0) {
    // RateTransition: '<Root>/Rate Transition16'
    rtb_RateTransition16_0 = &ros_code_B.preprocess_global_path_array[0];

    // RateTransition: '<Root>/Rate Transition13'
    if (ros_code_M->Timing.TaskCounters.TID[3] == 0) {
      // RateTransition: '<Root>/Rate Transition13'
      std::memcpy(&ros_code_B.RateTransition13[0],
                  &ros_code_DW.RateTransition13_Buffer0[0], 30U * sizeof(real_T));
    }

    // End of RateTransition: '<Root>/Rate Transition13'

    // RateTransition: '<Root>/Rate Transition17'
    rtb_RateTransition17_0 = &ros_code_B.object_array[0];

    // Outputs for Atomic SubSystem: '<Root>/Lattice_planner'
    ros_code_Lattice_planner(ros_code_B.current_state_C,
      ros_code_B.get_global_pose, rtb_RateTransition16_0,
      ros_code_B.RateTransition13, rtb_RateTransition17_0, ros_code_M->Timing.t
      [0], &ros_code_B.rtb_get_local_path_c, ros_code_B.predict_state,
      ros_code_B.rtb_current_state_C_i_m, &ros_code_B.predict_state[0],
      &ros_code_B.Lattice_planner, &ros_code_DW.Lattice_planner);

    // End of Outputs for SubSystem: '<Root>/Lattice_planner'

    // Outputs for Atomic SubSystem: '<Root>/MPC_controller'
    ros_code_MPC_controller(ros_code_B.rtb_get_local_path_c,
      ros_code_B.predict_state, ros_code_B.rtb_current_state_C_i_m,
      &ros_code_B.rtb_v_k, &ros_code_B.rtb_w_cl, &ros_code_B.MPC_controller);

    // End of Outputs for SubSystem: '<Root>/MPC_controller'

    // BusAssignment: '<Root>/Bus Assignment2' incorporates:
    //   Clock: '<Root>/Clock3'
    //   Constant: '<S1>/Constant'

    ros_code_B.BusAssignment2 = ros_code_P.Constant_Value_p;
    ros_code_B.BusAssignment2.Linear.X = ros_code_B.rtb_v_k;
    ros_code_B.BusAssignment2.Angular.Z = ros_code_B.rtb_w_cl;

    // Outputs for Atomic SubSystem: '<Root>/Publish2'
    // MATLABSystem: '<S5>/SinkBlock'
    Pub_ros_code_1865.publish(&ros_code_B.BusAssignment2);

    // End of Outputs for SubSystem: '<Root>/Publish2'
  }

  // End of RateTransition: '<Root>/Rate Transition18'

  // Update for RateTransition: '<Root>/Rate Transition13'
  if (ros_code_M->Timing.TaskCounters.TID[3] == 0) {
    std::memcpy(&ros_code_DW.RateTransition13_Buffer0[0],
                &ros_code_B.object_array_F[0], 30U * sizeof(real_T));
  }

  // End of Update for RateTransition: '<Root>/Rate Transition13'

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  ros_code_M->Timing.t[0] =
    ((time_T)(++ros_code_M->Timing.clockTick0)) * ros_code_M->Timing.stepSize0;

  {
    // Update absolute timer for sample time: [0.01s, 0.0s]
    // The "clockTick1" counts the number of times the code of this task has
    //  been executed. The resolution of this integer timer is 0.01, which is the step size
    //  of the task. Size of "clockTick1" ensures timer will not overflow during the
    //  application lifespan selected.

    ros_code_M->Timing.clockTick1++;
  }

  rate_scheduler();
}

void getParamsFromServer(ros::NodeHandle& nh, Params& params) {
    // 使用map容器来简化参数分类和获取逻辑
    std::map<std::string, std::vector<std::string>> paramCategories = {
            {"sample_param", {"T_max", "T_min", "t_step", "L_max", "L_min", "l_step", "ds_max", "ds_min", "ds_step", "predict_state_tolerance", "planning_end_distance", "start_plan_s"}},
            {"reduce_param", {"vehicle_length", "vehicle_width", "dds_threshold", "dls_threshold", "max_object_distance", "expansion_coeff"}},
            {"path_cost_param", {"ds_cost", "l_cost", "t_cost", "object_cost", "dds_cost", "ddls_cost"}},
            {"constraint_param", {"v_min", "v_max", "w_min", "w_max", "Delta_v_min", "Delta_v_max", "Delta_w_min", "Delta_w_max", "epsilon_max"}},
            {"MPC_cost_param", {"ex_stage_cost", "ey_stage_cost", "etheta_stage_cost", "ex_end_cost", "ey_end_cost", "etheta_end_cost", "delta_u_cost", "delta_w_cost", "epsilon_cost"}}
    };

    // 遍历map获取参数
    for (const auto& category : paramCategories) {
        XmlRpc::XmlRpcValue* currentParamCategory;
        if (category.first == "sample_param") {
            currentParamCategory = &params.sample_param;
        } else if (category.first == "reduce_param") {
            currentParamCategory = &params.reduce_param;
        } else if (category.first == "path_cost_param") {
            currentParamCategory = &params.path_cost_param;
        } else if (category.first == "constraint_param") {
            currentParamCategory = &params.constraint_param;
        } else if (category.first == "MPC_cost_param") {
            currentParamCategory = &params.MPC_cost_param;
        } else {
            ROS_WARN("Unknown parameter category: %s", category.first.c_str());
            continue;
        }

        for (const std::string& paramName : category.second) {
            XmlRpc::XmlRpcValue value;
            if (nh.getParam("ros_code/" + paramName, value)) {
                (*currentParamCategory)[paramName] = value;
            } else {
                ROS_WARN("Failed to get parameter: %s from category %s", paramName.c_str(), category.first.c_str());
            }
        }
    }
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
  ros_code_M->Timing.stepSize0 = 0.01;

  Params params;
  getParamsFromServer(*SLROSNodePtr, params);

  // 定义键的列表
  std::vector<std::string> sample_keys = {"T_max", "T_min", "t_step", "L_max", "L_min", "l_step", "ds_max", "ds_min", "ds_step", "predict_state_tolerance", "planning_end_distance", "start_plan_s"};
  std::vector<std::string> reduce_keys = {"vehicle_length", "vehicle_width", "dds_threshold", "dls_threshold", "max_object_distance", "expansion_coeff"};
  std::vector<std::string> path_cost_keys = {"ds_cost", "l_cost", "t_cost", "object_cost", "dds_cost", "ddls_cost"};
  std::vector<std::string> constraint_keys = {"v_min", "v_max", "w_min", "w_max", "Delta_v_min", "Delta_v_max", "Delta_w_min", "Delta_w_max", "epsilon_max"};
  std::vector<std::string> MPC_cost_keys = {"ex_stage_cost", "ey_stage_cost", "etheta_stage_cost", "ex_end_cost", "ey_end_cost", "etheta_end_cost", "delta_u_cost", "delta_w_cost", "epsilon_cost"};

//  ROS_INFO_STREAM("T_max: " << static_cast<double>(sample_keys.size()));

    for (int i = 0; i < sample_keys.size(); i++) {
        ros_code_P.sample_param[i] = static_cast<double>(params.sample_param[sample_keys[i]]);
        ROS_INFO_STREAM(sample_keys[i]<<":" << static_cast<double>(ros_code_P.sample_param[i]));
    }
    for (int i = 0; i < reduce_keys.size(); i++) {
        ros_code_P.reduce_param[i] = static_cast<double>(params.reduce_param[reduce_keys[i]]);
        ROS_INFO_STREAM(reduce_keys[i]<<":" << static_cast<double>(ros_code_P.reduce_param[i]));
    }
    for (int i = 0; i < path_cost_keys.size(); i++) {
        ros_code_P.path_cost_param[i] = static_cast<double>(params.path_cost_param[path_cost_keys[i]]);
        ROS_INFO_STREAM(path_cost_keys[i]<<":" << static_cast<double>(ros_code_P.path_cost_param[i]));
    }
    for (int i = 0; i < constraint_keys.size(); i++) {
        ros_code_P.constraint_param[i] = static_cast<double>(params.constraint_param[constraint_keys[i]]);
        ROS_INFO_STREAM(constraint_keys[i]<<":" << static_cast<double>(ros_code_P.constraint_param[i]));
    }
    for (int i = 0; i < MPC_cost_keys.size(); i++) {
        ros_code_P.MPC_cost_param[i] = static_cast<double>(params.MPC_cost_param[MPC_cost_keys[i]]);
        ROS_INFO_STREAM(MPC_cost_keys[i]<<":" << static_cast<double>(ros_code_P.MPC_cost_param[i]));
    }

  {
    static const char_T tmp_0[8]{ '/', 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    static const char_T tmp[5]{ '/', 'o', 'd', 'o', 'm' };

    char_T b_zeroDelimTopic_0[9];
    char_T b_zeroDelimTopic[6];
    for (int32_T i{0}; i < 30; i++) {
      // Start for RateTransition: '<Root>/Rate Transition13'
      ros_code_B.RateTransition13[i] =
        ros_code_P.RateTransition13_InitialConditi;
    }

    // InitializeConditions for RateTransition: '<Root>/Rate Transition13'
    for (int32_T i{0}; i < 30; i++) {
      ros_code_DW.RateTransition13_Buffer0[i] =
        ros_code_P.RateTransition13_InitialConditi;
    }

    // End of InitializeConditions for RateTransition: '<Root>/Rate Transition13' 

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2'
    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S26>/In1' incorporates:
    //   Outport: '<S26>/Out1'

    ros_code_B.In1 = ros_code_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // Start for MATLABSystem: '<S6>/SourceBlock'
    ros_code_DW.obj.matlabCodegenIsDeleted = false;
    ros_code_DW.obj.isInitialized = 1;
    for (int32_T i{0}; i < 5; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[5] = '\x00';
    Sub_ros_code_1880.createSubscriber(&b_zeroDelimTopic[0], 1);
    ros_code_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe2'

    // SystemInitialize for Atomic SubSystem: '<Root>/Global_planner'
    ros_code_Global_planner_Init(&ros_code_B.get_global_pose,
      ros_code_B.preprocess_global_path_array, ros_code_B.global_path_array,
      &ros_code_B.Global_planner, &ros_code_DW.Global_planner,
      &ros_code_P.Global_planner);

    // End of SystemInitialize for SubSystem: '<Root>/Global_planner'

    // SystemInitialize for Atomic SubSystem: '<Root>/Lattice_planner'
    ros_code_Lattice_planner_Init(&ros_code_DW.Lattice_planner,
      &ros_code_P.Lattice_planner);

    // End of SystemInitialize for SubSystem: '<Root>/Lattice_planner'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish2'
    // Start for MATLABSystem: '<S5>/SinkBlock'
    ros_code_DW.obj_d.matlabCodegenIsDeleted = false;
    ros_code_DW.obj_d.isInitialized = 1;
    for (int32_T i{0}; i < 8; i++) {
      b_zeroDelimTopic_0[i] = tmp_0[i];
    }

    b_zeroDelimTopic_0[8] = '\x00';
    Pub_ros_code_1865.createPublisher(&b_zeroDelimTopic_0[0], 1);
    ros_code_DW.obj_d.isSetupComplete = true;

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
  ros_code_Global_planner_Term(&ros_code_DW.Global_planner);

  // End of Terminate for SubSystem: '<Root>/Global_planner'

  // Terminate for Atomic SubSystem: '<Root>/Publish2'
  // Terminate for MATLABSystem: '<S5>/SinkBlock'
  if (!ros_code_DW.obj_d.matlabCodegenIsDeleted) {
    ros_code_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish2'
}

//
// File trailer for generated code.
//
// [EOF]
//
