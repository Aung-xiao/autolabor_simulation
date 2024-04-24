//
// Created by aung on 2024/4/19.
//
#include <ros/ros.h>
#include <nav_msgs/Path.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/PoseStamped.h>

class SimplePathPlanner
{
public:
    SimplePathPlanner() : nh("~"), global_path_topic("/global_path"),goal_topic("/move_base_simple/goal"),odom_topic("/odom"),frame_id("map")
    {
        // Get the global path topic name from parameter server if provided
        nh.param("global_path_topic", global_path_topic, global_path_topic);
        nh.param("goal_topice", goal_topic, goal_topic);
        nh.param("odom_topic", odom_topic, odom_topic);
        nh.param("frame_id", frame_id, frame_id);

        // Publisher and Subscribers
        path_pub = nh.advertise<nav_msgs::Path>(global_path_topic, 10);
        goal_sub = nh.subscribe(goal_topic, 10, &SimplePathPlanner::goalCallback, this);
        pose_sub = nh.subscribe(odom_topic, 10, &SimplePathPlanner::poseCallback, this);

        // Initialize path
        global_path.header.frame_id = frame_id;
    }

    void goalCallback(const geometry_msgs::PoseStamped::ConstPtr& goal_msg)
    {
        target_goal = *goal_msg;
        publishPath();
    }

    void poseCallback(const nav_msgs::Odometry::ConstPtr& odom_msg)
    {
        current_pose.header.stamp = ros::Time::now();
        current_pose.pose = odom_msg->pose.pose;
        publishPath();
    }

    void publishPath()
    {
        if (current_pose.header.stamp == ros::Time(0) || target_goal.header.stamp == ros::Time(0))
        {
            ROS_WARN("Current pose or goal not yet received.");
            return;
        }

        global_path.poses.clear();

        global_path.poses.push_back(current_pose);
        global_path.poses.push_back(target_goal);

        global_path.header.stamp = ros::Time::now();
        path_pub.publish(global_path);
    }

private:
    ros::NodeHandle nh;
    ros::Publisher path_pub;
    ros::Subscriber goal_sub;
    ros::Subscriber pose_sub;
    geometry_msgs::PoseStamped current_pose;
    geometry_msgs::PoseStamped target_goal;
    nav_msgs::Path global_path;
    std::string global_path_topic,goal_topic,odom_topic,frame_id;
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "simple_path_planner");
    SimplePathPlanner spp;
    ros::spin();
    return 0;
}