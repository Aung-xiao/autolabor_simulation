#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "ros_code_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block ros_code/Global_planner/Subscribe
extern SimulinkSubscriber<visualization_msgs::MarkerArray, SL_Bus_ros_code_visualization_msgs_MarkerArray> Sub_ros_code_1817;

// For Block ros_code/Global_planner/Subscribe1
extern SimulinkSubscriber<nav_msgs::Path, SL_Bus_ros_code_nav_msgs_Path> Sub_ros_code_1818;

// For Block ros_code/Subscribe2
extern SimulinkSubscriber<nav_msgs::Odometry, SL_Bus_ros_code_nav_msgs_Odometry> Sub_ros_code_1880;

// For Block ros_code/Publish2
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_ros_code_geometry_msgs_Twist> Pub_ros_code_1865;

void slros_node_init(int argc, char** argv);

#endif
