//
// Created by aung on 2024/4/19.
//
#include <ros/ros.h>
#include <visualization_msgs/MarkerArray.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "fake_obstacle_publisher");
    ros::NodeHandle nh("~");
    double position_x{},position_y{},position_z{},scale_x{},scale_y{},scale_z{};

    nh.param("position_x", position_x, 1.0);
    nh.param("position_y", position_y, 1.0);
    nh.param("position_z", position_z, 1.0);
    nh.param("scale_x", scale_x, 1.0);
    nh.param("scale_y", scale_y, 1.0);
    nh.param("scale_z", scale_z, 1.0);

    ros::Publisher marker_pub = nh.advertise<visualization_msgs::MarkerArray>("visualization_marker_array", 1);

    visualization_msgs::MarkerArray markerArray;
    visualization_msgs::Marker marker;

    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();

    marker.ns = "fake_obstacle";
    marker.id = 1;

    marker.type = visualization_msgs::Marker::CUBE;
    marker.action = visualization_msgs::Marker::ADD;

    marker.pose.position.x = position_x;
    marker.pose.position.y = position_y;
    marker.pose.position.z = position_z;

    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    marker.scale.x = scale_x;
    marker.scale.y = scale_y;
    marker.scale.z = scale_z;

    // 设置障碍物的颜色和alpha值（透明度）
    marker.color.r = 1.0;
    marker.color.g = 0.0;
    marker.color.b = 0.0;
    marker.color.a = 1.0;

    marker.lifetime = ros::Duration(); // 0代表永久显示

    // 将创建的立方体障碍物添加到MarkerArray
    markerArray.markers.push_back(marker);

    while (ros::ok())
    {
        marker_pub.publish(markerArray);
        ros::spinOnce();
    }

    return 0;
}