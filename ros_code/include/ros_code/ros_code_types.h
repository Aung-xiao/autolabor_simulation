//
// File: ros_code_types.h
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
#ifndef RTW_HEADER_ros_code_types_h_
#define RTW_HEADER_ros_code_types_h_
#include "rtwtypes.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
struct SL_Bus_ros_code_geometry_msgs_Vector3
{
  real_T X;
  real_T Y;
  real_T Z;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_geometry_msgs_Twist_

// MsgType=geometry_msgs/Twist
struct SL_Bus_ros_code_geometry_msgs_Twist
{
  // MsgType=geometry_msgs/Vector3
  SL_Bus_ros_code_geometry_msgs_Vector3 Linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_ros_code_geometry_msgs_Vector3 Angular;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_ros_time_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_ros_time_Time_

// MsgType=ros_time/Time
struct SL_Bus_ros_code_ros_time_Time
{
  real_T Sec;
  real_T Nsec;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

struct SL_Bus_ROSVariableLengthArrayInfo
{
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_std_msgs_Header_

// MsgType=std_msgs/Header
struct SL_Bus_ros_code_std_msgs_Header
{
  uint32_T Seq;

  // MsgType=ros_time/Time
  SL_Bus_ros_code_ros_time_Time Stamp;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=FrameId_SL_Info:TruncateAction=warn 
  uint8_T FrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=FrameId
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_geometry_msgs_Point_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_geometry_msgs_Point_

// MsgType=geometry_msgs/Point
struct SL_Bus_ros_code_geometry_msgs_Point
{
  real_T X;
  real_T Y;
  real_T Z;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_geometry_msgs_Quaternion_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_geometry_msgs_Quaternion_

// MsgType=geometry_msgs/Quaternion
struct SL_Bus_ros_code_geometry_msgs_Quaternion
{
  real_T X;
  real_T Y;
  real_T Z;
  real_T W;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_geometry_msgs_Pose_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_geometry_msgs_Pose_

// MsgType=geometry_msgs/Pose
struct SL_Bus_ros_code_geometry_msgs_Pose
{
  // MsgType=geometry_msgs/Point
  SL_Bus_ros_code_geometry_msgs_Point Position;

  // MsgType=geometry_msgs/Quaternion
  SL_Bus_ros_code_geometry_msgs_Quaternion Orientation;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_std_msgs_ColorRGBA_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_std_msgs_ColorRGBA_

// MsgType=std_msgs/ColorRGBA
struct SL_Bus_ros_code_std_msgs_ColorRGBA
{
  real32_T R;
  real32_T G;
  real32_T B;
  real32_T A;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_ros_time_Duration_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_ros_time_Duration_

// MsgType=ros_time/Duration
struct SL_Bus_ros_code_ros_time_Duration
{
  real_T Sec;
  real_T Nsec;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_visualization_msgs_Marker_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_visualization_msgs_Marker_

// MsgType=visualization_msgs/Marker
struct SL_Bus_ros_code_visualization_msgs_Marker
{
  // MsgType=std_msgs/Header
  SL_Bus_ros_code_std_msgs_Header Header;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=Ns_SL_Info:TruncateAction=warn 
  uint8_T Ns[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Ns
  SL_Bus_ROSVariableLengthArrayInfo Ns_SL_Info;
  int32_T Id;
  int32_T Type;
  int32_T Action;

  // MsgType=geometry_msgs/Pose
  SL_Bus_ros_code_geometry_msgs_Pose Pose;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_ros_code_geometry_msgs_Vector3 Scale;

  // MsgType=std_msgs/ColorRGBA
  SL_Bus_ros_code_std_msgs_ColorRGBA Color;

  // MsgType=ros_time/Duration
  SL_Bus_ros_code_ros_time_Duration Lifetime;
  boolean_T FrameLocked;

  // MsgType=geometry_msgs/Point:IsVarLen=1:VarLenCategory=data:VarLenElem=Points_SL_Info:TruncateAction=warn 
  SL_Bus_ros_code_geometry_msgs_Point Points[16];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Points
  SL_Bus_ROSVariableLengthArrayInfo Points_SL_Info;

  // MsgType=std_msgs/ColorRGBA:IsVarLen=1:VarLenCategory=data:VarLenElem=Colors_SL_Info:TruncateAction=warn 
  SL_Bus_ros_code_std_msgs_ColorRGBA Colors[16];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Colors
  SL_Bus_ROSVariableLengthArrayInfo Colors_SL_Info;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=Text_SL_Info:TruncateAction=warn 
  uint8_T Text[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Text
  SL_Bus_ROSVariableLengthArrayInfo Text_SL_Info;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=MeshResource_SL_Info:TruncateAction=warn 
  uint8_T MeshResource[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=MeshResource
  SL_Bus_ROSVariableLengthArrayInfo MeshResource_SL_Info;
  boolean_T MeshUseEmbeddedMaterials;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_visualization_msgs_MarkerArray_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_visualization_msgs_MarkerArray_

// MsgType=visualization_msgs/MarkerArray
struct SL_Bus_ros_code_visualization_msgs_MarkerArray
{
  // MsgType=visualization_msgs/Marker:IsVarLen=1:VarLenCategory=data:VarLenElem=Markers_SL_Info:TruncateAction=warn 
  SL_Bus_ros_code_visualization_msgs_Marker Markers[16];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Markers
  SL_Bus_ROSVariableLengthArrayInfo Markers_SL_Info;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_geometry_msgs_PoseStamped_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_geometry_msgs_PoseStamped_

// MsgType=geometry_msgs/PoseStamped
struct SL_Bus_ros_code_geometry_msgs_PoseStamped
{
  // MsgType=std_msgs/Header
  SL_Bus_ros_code_std_msgs_Header Header;

  // MsgType=geometry_msgs/Pose
  SL_Bus_ros_code_geometry_msgs_Pose Pose;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_nav_msgs_Path_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_nav_msgs_Path_

// MsgType=nav_msgs/Path
struct SL_Bus_ros_code_nav_msgs_Path
{
  // MsgType=std_msgs/Header
  SL_Bus_ros_code_std_msgs_Header Header;

  // MsgType=geometry_msgs/PoseStamped:IsVarLen=1:VarLenCategory=data:VarLenElem=Poses_SL_Info:TruncateAction=warn 
  SL_Bus_ros_code_geometry_msgs_PoseStamped Poses[1000];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=Poses
  SL_Bus_ROSVariableLengthArrayInfo Poses_SL_Info;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_geometry_msgs_PoseWithCovariance_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_geometry_msgs_PoseWithCovariance_

// MsgType=geometry_msgs/PoseWithCovariance
struct SL_Bus_ros_code_geometry_msgs_PoseWithCovariance
{
  // MsgType=geometry_msgs/Pose
  SL_Bus_ros_code_geometry_msgs_Pose Pose;
  real_T Covariance[36];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_geometry_msgs_TwistWithCovariance_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_geometry_msgs_TwistWithCovariance_

// MsgType=geometry_msgs/TwistWithCovariance
struct SL_Bus_ros_code_geometry_msgs_TwistWithCovariance
{
  // MsgType=geometry_msgs/Twist
  SL_Bus_ros_code_geometry_msgs_Twist Twist;
  real_T Covariance[36];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_nav_msgs_Odometry_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ros_code_nav_msgs_Odometry_

// MsgType=nav_msgs/Odometry
struct SL_Bus_ros_code_nav_msgs_Odometry
{
  // MsgType=std_msgs/Header
  SL_Bus_ros_code_std_msgs_Header Header;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=ChildFrameId_SL_Info:TruncateAction=warn 
  uint8_T ChildFrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=ChildFrameId
  SL_Bus_ROSVariableLengthArrayInfo ChildFrameId_SL_Info;

  // MsgType=geometry_msgs/PoseWithCovariance
  SL_Bus_ros_code_geometry_msgs_PoseWithCovariance Pose;

  // MsgType=geometry_msgs/TwistWithCovariance
  SL_Bus_ros_code_geometry_msgs_TwistWithCovariance Twist;
};

#endif

#ifndef struct_ros_slroscpp_internal_block_S_T
#define struct_ros_slroscpp_internal_block_S_T

struct ros_slroscpp_internal_block_S_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slroscpp_internal_block_S_T

// Custom Type definition for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming' 
#ifndef struct_sEf9458k7RTCGn6XpAY3FSD_ros_c_T
#define struct_sEf9458k7RTCGn6XpAY3FSD_ros_c_T

struct sEf9458k7RTCGn6XpAY3FSD_ros_c_T
{
  real_T xstar[45];
  real_T fstar;
  real_T firstorderopt;
  real_T lambda[133];
  int32_T state;
  real_T maxConstr;
  int32_T iterations;
  real_T searchDir[45];
};

#endif                                // struct_sEf9458k7RTCGn6XpAY3FSD_ros_c_T

#ifndef struct_scRVBsoAowahmPoAIYa5ea_ros_co_T
#define struct_scRVBsoAowahmPoAIYa5ea_ros_co_T

struct scRVBsoAowahmPoAIYa5ea_ros_co_T
{
  real_T grad[45];
  real_T Hx[44];
  boolean_T hasLinear;
  int32_T nvar;
  int32_T maxVar;
  real_T beta;
  real_T rho;
  int32_T objtype;
  int32_T prev_objtype;
  int32_T prev_nvar;
  boolean_T prev_hasLinear;
  real_T gammaScalar;
};

#endif                                // struct_scRVBsoAowahmPoAIYa5ea_ros_co_T

#ifndef struct_svUSr4TrK4x4Kz9rQJTxkkF_ros_c_T
#define struct_svUSr4TrK4x4Kz9rQJTxkkF_ros_c_T

struct svUSr4TrK4x4Kz9rQJTxkkF_ros_c_T
{
  real_T FMat[2025];
  int32_T ldm;
  int32_T ndims;
  int32_T info;
  real_T scaleFactor;
  boolean_T ConvexCheck;
  real_T regTol_;
  real_T workspace_[2160];
  real_T workspace2_[2160];
};

#endif                                // struct_svUSr4TrK4x4Kz9rQJTxkkF_ros_c_T

#ifndef struct_sL9bDKomAYkxZSVrG9w6En_ros_co_T
#define struct_sL9bDKomAYkxZSVrG9w6En_ros_co_T

struct sL9bDKomAYkxZSVrG9w6En_ros_co_T
{
  int32_T MaxIterations;
  real_T ConstrRelTolFactor;
  real_T ProbRelTolFactor;
  boolean_T RemainFeasible;
};

#endif                                // struct_sL9bDKomAYkxZSVrG9w6En_ros_co_T

#ifndef struct_ros_slroscpp_internal_block_P_T
#define struct_ros_slroscpp_internal_block_P_T

struct ros_slroscpp_internal_block_P_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slroscpp_internal_block_P_T

// Custom Type definition for MATLAB Function: '<S4>/MPC//solveQuadraticProgramming' 
#ifndef struct_siBmBjpOUwoybpuj9rEfGvD_ros_c_T
#define struct_siBmBjpOUwoybpuj9rEfGvD_ros_c_T

struct siBmBjpOUwoybpuj9rEfGvD_ros_c_T
{
  int32_T ldq;
  real_T QR[5985];
  real_T Q[2025];
  int32_T jpvt[133];
  int32_T mrows;
  int32_T ncols;
  real_T tau[45];
  int32_T minRowCol;
  boolean_T usedPivoting;
};

#endif                                // struct_siBmBjpOUwoybpuj9rEfGvD_ros_c_T

#ifndef struct_sg8qKdtlZ7nXgcAC5MP2QHC_ros_c_T
#define struct_sg8qKdtlZ7nXgcAC5MP2QHC_ros_c_T

struct sg8qKdtlZ7nXgcAC5MP2QHC_ros_c_T
{
  real_T workspace_double[5985];
  int32_T workspace_int[133];
  int32_T workspace_sort[133];
};

#endif                                // struct_sg8qKdtlZ7nXgcAC5MP2QHC_ros_c_T

#ifndef struct_snBUc3P0iDgb4fuyQLszkYC_ros_c_T
#define struct_snBUc3P0iDgb4fuyQLszkYC_ros_c_T

struct snBUc3P0iDgb4fuyQLszkYC_ros_c_T
{
  int32_T mConstr;
  int32_T mConstrOrig;
  int32_T mConstrMax;
  int32_T nVar;
  int32_T nVarOrig;
  int32_T nVarMax;
  int32_T ldA;
  real_T Aineq[1980];
  real_T bineq[44];
  real_T lb[45];
  real_T ub[45];
  int32_T indexLB[45];
  int32_T indexUB[45];
  int32_T indexFixed[45];
  int32_T mEqRemoved;
  real_T ATwset[5985];
  real_T bwset[133];
  int32_T nActiveConstr;
  real_T maxConstrWorkspace[133];
  int32_T sizes[5];
  int32_T sizesNormal[5];
  int32_T sizesPhaseOne[5];
  int32_T sizesRegularized[5];
  int32_T sizesRegPhaseOne[5];
  int32_T isActiveIdx[6];
  int32_T isActiveIdxNormal[6];
  int32_T isActiveIdxPhaseOne[6];
  int32_T isActiveIdxRegularized[6];
  int32_T isActiveIdxRegPhaseOne[6];
  boolean_T isActiveConstr[133];
  int32_T Wid[133];
  int32_T Wlocalidx[133];
  int32_T nWConstr[5];
  int32_T probType;
  real_T SLACK0;
};

#endif                                // struct_snBUc3P0iDgb4fuyQLszkYC_ros_c_T

#ifndef struct_sSOeZ9WO10chPn9Si6PKiCB_ros_c_T
#define struct_sSOeZ9WO10chPn9Si6PKiCB_ros_c_T

struct sSOeZ9WO10chPn9Si6PKiCB_ros_c_T
{
  real_T InitDamping;
  char_T FiniteDifferenceType[7];
  boolean_T SpecifyObjectiveGradient;
  boolean_T ScaleProblem;
  boolean_T SpecifyConstraintGradient;
  boolean_T NonFiniteSupport;
  boolean_T IterDisplaySQP;
  real_T FiniteDifferenceStepSize;
  real_T MaxFunctionEvaluations;
  boolean_T IterDisplayQP;
  real_T PricingTolerance;
  char_T Algorithm[10];
  real_T ObjectiveLimit;
  real_T ConstraintTolerance;
  real_T OptimalityTolerance;
  real_T StepTolerance;
  real_T MaxIterations;
  real_T FunctionTolerance;
  char_T SolverName[8];
  boolean_T CheckGradients;
  char_T Diagnostics[3];
  real_T DiffMaxChange;
  real_T DiffMinChange;
  char_T Display[5];
  char_T FunValCheck[3];
  boolean_T UseParallel;
  char_T LinearSolver[4];
  char_T SubproblemAlgorithm[2];
};

#endif                                // struct_sSOeZ9WO10chPn9Si6PKiCB_ros_c_T

// Parameters (default storage)
typedef struct P_ros_code_T_ P_ros_code_T;

// Forward declaration for rtModel
typedef struct tag_RTM_ros_code_T RT_MODEL_ros_code_T;

#endif                                 // RTW_HEADER_ros_code_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
