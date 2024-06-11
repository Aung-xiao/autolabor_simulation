#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_ros_code_geometry_msgs_Point and geometry_msgs::Point

void convertFromBus(geometry_msgs::Point* msgPtr, SL_Bus_ros_code_geometry_msgs_Point const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Point");

  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convertToBus(SL_Bus_ros_code_geometry_msgs_Point* busPtr, geometry_msgs::Point const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Point");

  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_ros_code_geometry_msgs_Pose and geometry_msgs::Pose

void convertFromBus(geometry_msgs::Pose* msgPtr, SL_Bus_ros_code_geometry_msgs_Pose const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Pose");

  convertFromBus(&msgPtr->orientation, &busPtr->Orientation);
  convertFromBus(&msgPtr->position, &busPtr->Position);
}

void convertToBus(SL_Bus_ros_code_geometry_msgs_Pose* busPtr, geometry_msgs::Pose const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Pose");

  convertToBus(&busPtr->Orientation, &msgPtr->orientation);
  convertToBus(&busPtr->Position, &msgPtr->position);
}


// Conversions between SL_Bus_ros_code_geometry_msgs_PoseStamped and geometry_msgs::PoseStamped

void convertFromBus(geometry_msgs::PoseStamped* msgPtr, SL_Bus_ros_code_geometry_msgs_PoseStamped const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/PoseStamped");

  convertFromBus(&msgPtr->header, &busPtr->Header);
  convertFromBus(&msgPtr->pose, &busPtr->Pose);
}

void convertToBus(SL_Bus_ros_code_geometry_msgs_PoseStamped* busPtr, geometry_msgs::PoseStamped const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/PoseStamped");

  convertToBus(&busPtr->Header, &msgPtr->header);
  convertToBus(&busPtr->Pose, &msgPtr->pose);
}


// Conversions between SL_Bus_ros_code_geometry_msgs_PoseWithCovariance and geometry_msgs::PoseWithCovariance

void convertFromBus(geometry_msgs::PoseWithCovariance* msgPtr, SL_Bus_ros_code_geometry_msgs_PoseWithCovariance const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/PoseWithCovariance");

  convertFromBusFixedPrimitiveArray(msgPtr->covariance, busPtr->Covariance);
  convertFromBus(&msgPtr->pose, &busPtr->Pose);
}

void convertToBus(SL_Bus_ros_code_geometry_msgs_PoseWithCovariance* busPtr, geometry_msgs::PoseWithCovariance const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/PoseWithCovariance");

  convertToBusFixedPrimitiveArray(busPtr->Covariance, msgPtr->covariance, slros::NoopWarning());
  convertToBus(&busPtr->Pose, &msgPtr->pose);
}


// Conversions between SL_Bus_ros_code_geometry_msgs_Quaternion and geometry_msgs::Quaternion

void convertFromBus(geometry_msgs::Quaternion* msgPtr, SL_Bus_ros_code_geometry_msgs_Quaternion const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Quaternion");

  msgPtr->w =  busPtr->W;
  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convertToBus(SL_Bus_ros_code_geometry_msgs_Quaternion* busPtr, geometry_msgs::Quaternion const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Quaternion");

  busPtr->W =  msgPtr->w;
  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_ros_code_geometry_msgs_Twist and geometry_msgs::Twist

void convertFromBus(geometry_msgs::Twist* msgPtr, SL_Bus_ros_code_geometry_msgs_Twist const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Twist");

  convertFromBus(&msgPtr->angular, &busPtr->Angular);
  convertFromBus(&msgPtr->linear, &busPtr->Linear);
}

void convertToBus(SL_Bus_ros_code_geometry_msgs_Twist* busPtr, geometry_msgs::Twist const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Twist");

  convertToBus(&busPtr->Angular, &msgPtr->angular);
  convertToBus(&busPtr->Linear, &msgPtr->linear);
}


// Conversions between SL_Bus_ros_code_geometry_msgs_TwistWithCovariance and geometry_msgs::TwistWithCovariance

void convertFromBus(geometry_msgs::TwistWithCovariance* msgPtr, SL_Bus_ros_code_geometry_msgs_TwistWithCovariance const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/TwistWithCovariance");

  convertFromBusFixedPrimitiveArray(msgPtr->covariance, busPtr->Covariance);
  convertFromBus(&msgPtr->twist, &busPtr->Twist);
}

void convertToBus(SL_Bus_ros_code_geometry_msgs_TwistWithCovariance* busPtr, geometry_msgs::TwistWithCovariance const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/TwistWithCovariance");

  convertToBusFixedPrimitiveArray(busPtr->Covariance, msgPtr->covariance, slros::NoopWarning());
  convertToBus(&busPtr->Twist, &msgPtr->twist);
}


// Conversions between SL_Bus_ros_code_geometry_msgs_Vector3 and geometry_msgs::Vector3

void convertFromBus(geometry_msgs::Vector3* msgPtr, SL_Bus_ros_code_geometry_msgs_Vector3 const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convertToBus(SL_Bus_ros_code_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_ros_code_nav_msgs_Odometry and nav_msgs::Odometry

void convertFromBus(nav_msgs::Odometry* msgPtr, SL_Bus_ros_code_nav_msgs_Odometry const* busPtr)
{
  const std::string rosMessageType("nav_msgs/Odometry");

  convertFromBusVariablePrimitiveArray(msgPtr->child_frame_id, busPtr->ChildFrameId, busPtr->ChildFrameId_SL_Info);
  convertFromBus(&msgPtr->header, &busPtr->Header);
  convertFromBus(&msgPtr->pose, &busPtr->Pose);
  convertFromBus(&msgPtr->twist, &busPtr->Twist);
}

void convertToBus(SL_Bus_ros_code_nav_msgs_Odometry* busPtr, nav_msgs::Odometry const* msgPtr)
{
  const std::string rosMessageType("nav_msgs/Odometry");

  convertToBusVariablePrimitiveArray(busPtr->ChildFrameId, busPtr->ChildFrameId_SL_Info, msgPtr->child_frame_id, slros::EnabledWarning(rosMessageType, "child_frame_id"));
  convertToBus(&busPtr->Header, &msgPtr->header);
  convertToBus(&busPtr->Pose, &msgPtr->pose);
  convertToBus(&busPtr->Twist, &msgPtr->twist);
}


// Conversions between SL_Bus_ros_code_nav_msgs_Path and nav_msgs::Path

void convertFromBus(nav_msgs::Path* msgPtr, SL_Bus_ros_code_nav_msgs_Path const* busPtr)
{
  const std::string rosMessageType("nav_msgs/Path");

  convertFromBus(&msgPtr->header, &busPtr->Header);
  convertFromBusVariableNestedArray(msgPtr->poses, busPtr->Poses, busPtr->Poses_SL_Info);
}

void convertToBus(SL_Bus_ros_code_nav_msgs_Path* busPtr, nav_msgs::Path const* msgPtr)
{
  const std::string rosMessageType("nav_msgs/Path");

  convertToBus(&busPtr->Header, &msgPtr->header);
  convertToBusVariableNestedArray(busPtr->Poses, busPtr->Poses_SL_Info, msgPtr->poses, slros::EnabledWarning(rosMessageType, "poses"));
}


// Conversions between SL_Bus_ros_code_ros_time_Duration and ros::Duration

void convertFromBus(ros::Duration* msgPtr, SL_Bus_ros_code_ros_time_Duration const* busPtr)
{
  const std::string rosMessageType("ros_time/Duration");

  msgPtr->nsec =  busPtr->Nsec;
  msgPtr->sec =  busPtr->Sec;
}

void convertToBus(SL_Bus_ros_code_ros_time_Duration* busPtr, ros::Duration const* msgPtr)
{
  const std::string rosMessageType("ros_time/Duration");

  busPtr->Nsec =  msgPtr->nsec;
  busPtr->Sec =  msgPtr->sec;
}


// Conversions between SL_Bus_ros_code_ros_time_Time and ros::Time

void convertFromBus(ros::Time* msgPtr, SL_Bus_ros_code_ros_time_Time const* busPtr)
{
  const std::string rosMessageType("ros_time/Time");

  msgPtr->nsec =  busPtr->Nsec;
  msgPtr->sec =  busPtr->Sec;
}

void convertToBus(SL_Bus_ros_code_ros_time_Time* busPtr, ros::Time const* msgPtr)
{
  const std::string rosMessageType("ros_time/Time");

  busPtr->Nsec =  msgPtr->nsec;
  busPtr->Sec =  msgPtr->sec;
}


// Conversions between SL_Bus_ros_code_std_msgs_ColorRGBA and std_msgs::ColorRGBA

void convertFromBus(std_msgs::ColorRGBA* msgPtr, SL_Bus_ros_code_std_msgs_ColorRGBA const* busPtr)
{
  const std::string rosMessageType("std_msgs/ColorRGBA");

  msgPtr->a =  busPtr->A;
  msgPtr->b =  busPtr->B;
  msgPtr->g =  busPtr->G;
  msgPtr->r =  busPtr->R;
}

void convertToBus(SL_Bus_ros_code_std_msgs_ColorRGBA* busPtr, std_msgs::ColorRGBA const* msgPtr)
{
  const std::string rosMessageType("std_msgs/ColorRGBA");

  busPtr->A =  msgPtr->a;
  busPtr->B =  msgPtr->b;
  busPtr->G =  msgPtr->g;
  busPtr->R =  msgPtr->r;
}


// Conversions between SL_Bus_ros_code_std_msgs_Header and std_msgs::Header

void convertFromBus(std_msgs::Header* msgPtr, SL_Bus_ros_code_std_msgs_Header const* busPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertFromBusVariablePrimitiveArray(msgPtr->frame_id, busPtr->FrameId, busPtr->FrameId_SL_Info);
  msgPtr->seq =  busPtr->Seq;
  convertFromBus(&msgPtr->stamp, &busPtr->Stamp);
}

void convertToBus(SL_Bus_ros_code_std_msgs_Header* busPtr, std_msgs::Header const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertToBusVariablePrimitiveArray(busPtr->FrameId, busPtr->FrameId_SL_Info, msgPtr->frame_id, slros::EnabledWarning(rosMessageType, "frame_id"));
  busPtr->Seq =  msgPtr->seq;
  convertToBus(&busPtr->Stamp, &msgPtr->stamp);
}


// Conversions between SL_Bus_ros_code_visualization_msgs_Marker and visualization_msgs::Marker

void convertFromBus(visualization_msgs::Marker* msgPtr, SL_Bus_ros_code_visualization_msgs_Marker const* busPtr)
{
  const std::string rosMessageType("visualization_msgs/Marker");

  msgPtr->action =  busPtr->Action;
  convertFromBus(&msgPtr->color, &busPtr->Color);
  convertFromBusVariableNestedArray(msgPtr->colors, busPtr->Colors, busPtr->Colors_SL_Info);
  msgPtr->frame_locked =  busPtr->FrameLocked;
  convertFromBus(&msgPtr->header, &busPtr->Header);
  msgPtr->id =  busPtr->Id;
  convertFromBus(&msgPtr->lifetime, &busPtr->Lifetime);
  convertFromBusVariablePrimitiveArray(msgPtr->mesh_resource, busPtr->MeshResource, busPtr->MeshResource_SL_Info);
  msgPtr->mesh_use_embedded_materials =  busPtr->MeshUseEmbeddedMaterials;
  convertFromBusVariablePrimitiveArray(msgPtr->ns, busPtr->Ns, busPtr->Ns_SL_Info);
  convertFromBusVariableNestedArray(msgPtr->points, busPtr->Points, busPtr->Points_SL_Info);
  convertFromBus(&msgPtr->pose, &busPtr->Pose);
  convertFromBus(&msgPtr->scale, &busPtr->Scale);
  convertFromBusVariablePrimitiveArray(msgPtr->text, busPtr->Text, busPtr->Text_SL_Info);
  msgPtr->type =  busPtr->Type;
}

void convertToBus(SL_Bus_ros_code_visualization_msgs_Marker* busPtr, visualization_msgs::Marker const* msgPtr)
{
  const std::string rosMessageType("visualization_msgs/Marker");

  busPtr->Action =  msgPtr->action;
  convertToBus(&busPtr->Color, &msgPtr->color);
  convertToBusVariableNestedArray(busPtr->Colors, busPtr->Colors_SL_Info, msgPtr->colors, slros::EnabledWarning(rosMessageType, "colors"));
  busPtr->FrameLocked =  msgPtr->frame_locked;
  convertToBus(&busPtr->Header, &msgPtr->header);
  busPtr->Id =  msgPtr->id;
  convertToBus(&busPtr->Lifetime, &msgPtr->lifetime);
  convertToBusVariablePrimitiveArray(busPtr->MeshResource, busPtr->MeshResource_SL_Info, msgPtr->mesh_resource, slros::EnabledWarning(rosMessageType, "mesh_resource"));
  busPtr->MeshUseEmbeddedMaterials =  msgPtr->mesh_use_embedded_materials;
  convertToBusVariablePrimitiveArray(busPtr->Ns, busPtr->Ns_SL_Info, msgPtr->ns, slros::EnabledWarning(rosMessageType, "ns"));
  convertToBusVariableNestedArray(busPtr->Points, busPtr->Points_SL_Info, msgPtr->points, slros::EnabledWarning(rosMessageType, "points"));
  convertToBus(&busPtr->Pose, &msgPtr->pose);
  convertToBus(&busPtr->Scale, &msgPtr->scale);
  convertToBusVariablePrimitiveArray(busPtr->Text, busPtr->Text_SL_Info, msgPtr->text, slros::EnabledWarning(rosMessageType, "text"));
  busPtr->Type =  msgPtr->type;
}


// Conversions between SL_Bus_ros_code_visualization_msgs_MarkerArray and visualization_msgs::MarkerArray

void convertFromBus(visualization_msgs::MarkerArray* msgPtr, SL_Bus_ros_code_visualization_msgs_MarkerArray const* busPtr)
{
  const std::string rosMessageType("visualization_msgs/MarkerArray");

  convertFromBusVariableNestedArray(msgPtr->markers, busPtr->Markers, busPtr->Markers_SL_Info);
}

void convertToBus(SL_Bus_ros_code_visualization_msgs_MarkerArray* busPtr, visualization_msgs::MarkerArray const* msgPtr)
{
  const std::string rosMessageType("visualization_msgs/MarkerArray");

  convertToBusVariableNestedArray(busPtr->Markers, busPtr->Markers_SL_Info, msgPtr->markers, slros::EnabledWarning(rosMessageType, "markers"));
}

