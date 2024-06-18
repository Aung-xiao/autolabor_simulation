//
// Created by aung on 2024/6/18.
//
#include <ros/ros.h>
#include <tf2_ros/transform_listener.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <nav_msgs/Odometry.h>

// 定义一个全局变量来存储速度信息
nav_msgs::Odometry current_wheel_odom;

void wheelOdomCallback(const nav_msgs::Odometry::ConstPtr& msg) {
    // 更新全局变量中的速度信息
    current_wheel_odom.twist.twist.linear.x = msg->twist.twist.linear.x;
    current_wheel_odom.twist.twist.angular.z = msg->twist.twist.angular.z;
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "odom_publisher");

    ros::NodeHandle nh;
    tf2_ros::Buffer tfBuffer;
    tf2_ros::TransformListener tfListener(tfBuffer);

    // 订阅 /wheel_odom 话题
    ros::Subscriber wheel_odom_sub = nh.subscribe("/wheel_odom", 10, wheelOdomCallback);

    ros::Publisher odom_pub = nh.advertise<nav_msgs::Odometry>("/odom", 10);

    ros::Rate rate(10.0);
    while (nh.ok()) {
        geometry_msgs::TransformStamped transformStamped;
        try {
            transformStamped = tfBuffer.lookupTransform("camera_init", "aft_mapped", ros::Time(0));
        } catch (tf2::TransformException &ex) {
            ROS_WARN("%s",ex.what());
            ros::Duration(1.0).sleep();
            continue;
        }

        nav_msgs::Odometry odom_msg;
        odom_msg.header.stamp = transformStamped.header.stamp;
        odom_msg.header.frame_id = "odom";

        // 设置位置和方向
        odom_msg.pose.pose.position.x = transformStamped.transform.translation.x;
        odom_msg.pose.pose.position.y = transformStamped.transform.translation.y;
        odom_msg.pose.pose.position.z = transformStamped.transform.translation.z;
        odom_msg.pose.pose.orientation = transformStamped.transform.rotation;

        // 设置速度信息，使用/wheel_odom话题中接收到的速度和角速度
        odom_msg.twist.twist.linear.x = current_wheel_odom.twist.twist.linear.x;
        odom_msg.twist.twist.angular.z = current_wheel_odom.twist.twist.angular.z;

        odom_pub.publish(odom_msg);

        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}