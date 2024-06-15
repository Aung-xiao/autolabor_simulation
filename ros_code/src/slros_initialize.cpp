#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "ros_code";

// For Block ros_code/Global_planner/Subscribe
SimulinkSubscriber<visualization_msgs::MarkerArray, SL_Bus_ros_code_visualization_msgs_MarkerArray> Sub_ros_code_1817;

// For Block ros_code/Global_planner/Subscribe1
SimulinkSubscriber<nav_msgs::Path, SL_Bus_ros_code_nav_msgs_Path> Sub_ros_code_1818;

// For Block ros_code/Subscribe2
SimulinkSubscriber<nav_msgs::Odometry, SL_Bus_ros_code_nav_msgs_Odometry> Sub_ros_code_1880;

// For Block ros_code/Publish2
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_ros_code_geometry_msgs_Twist> Pub_ros_code_1865;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

