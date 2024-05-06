//
// Created by aung on 2024/4/19.
//
#include <ros/ros.h>
#include <nav_msgs/Path.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/PoseStamped.h>
#include <cmath> // Add this for std::hypot

class SimplePathPlanner
{
public:
    SimplePathPlanner() : nh("~"), global_path_topic("/global_path"),goal_topic("/move_base_simple/goal"),odom_topic("/odom"),frame_id("map"),distance_step(1.0)
    {
        // Get the global path topic name from parameter server if provided
        nh.param("global_path_topic", global_path_topic, global_path_topic);
        nh.param("goal_topice", goal_topic, goal_topic);
        nh.param("odom_topic", odom_topic, odom_topic);
        nh.param("frame_id", frame_id, frame_id);
        nh.param("distance_step", distance_step, distance_step);

        // Publisher and Subscribers
        path_pub = nh.advertise<nav_msgs::Path>(global_path_topic, 10);
        goal_sub = nh.subscribe(goal_topic, 10, &SimplePathPlanner::goalCallback, this);
        pose_sub = nh.subscribe(odom_topic, 10, &SimplePathPlanner::poseCallback, this);

        // Initialize path
        global_path.header.frame_id = frame_id;
    }

    // Add this helper function to return the Euclidean distance between two points
    double getEuclideanDistance(const geometry_msgs::PoseStamped& p1, const geometry_msgs::PoseStamped& p2) {
        return std::hypot(p1.pose.position.x - p2.pose.position.x, p1.pose.position.y - p2.pose.position.y);
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
            return;

        double total_distance = getEuclideanDistance(current_pose, target_goal);
        int num_intermediate_points = std::floor(total_distance/distance_step);

        global_path.poses.clear();
        global_path.poses.push_back(current_pose);

        for(int i = 1; i <= num_intermediate_points; i++){
            double t = i * distance_step / total_distance;
            geometry_msgs::PoseStamped intermediate;
            intermediate.header.frame_id = frame_id;
            intermediate.header.stamp = ros::Time::now();
            intermediate.pose.position.x = (1 - t) * current_pose.pose.position.x + t * target_goal.pose.position.x;
            intermediate.pose.position.y = (1 - t) * current_pose.pose.position.y + t * target_goal.pose.position.y;
            // For simplicity, we'll interpolate linearly.
            global_path.poses.push_back(intermediate);
        }

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
    double distance_step;
    std::string global_path_topic,goal_topic,odom_topic,frame_id;
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "simple_path_planner");
    SimplePathPlanner spp;
    ros::spin();
    return 0;
}