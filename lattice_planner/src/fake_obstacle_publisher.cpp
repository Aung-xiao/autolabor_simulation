//
// Created by aung on 2024/4/19.
//
#include <ros/ros.h>
#include <visualization_msgs/MarkerArray.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "fake_obstacle_publisher");
    ros::NodeHandle nh;

    ros::Publisher marker_pub = nh.advertise<visualization_msgs::MarkerArray>("visualization_marker_array", 1);

    visualization_msgs::MarkerArray markerArray;
    visualization_msgs::Marker marker;

    marker.header.frame_id = "real_map";
    marker.header.stamp = ros::Time::now();

    marker.ns = "fake_obstacle";
    marker.id = 1;

    marker.type = visualization_msgs::Marker::CUBE;
    marker.action = visualization_msgs::Marker::ADD;

    marker.pose.position.x = 1.0; //修改为障碍物的X位置
    marker.pose.position.y = 1.0; //修改为障碍物的Y位置
    marker.pose.position.z = 0.5; //修改为障碍物的Z位置

    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    marker.scale.x = 1.0; //修改为障碍物的宽度
    marker.scale.y = 1.0; //修改为障碍物的深度
    marker.scale.z = 1.0; //修改为障碍物的高度

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