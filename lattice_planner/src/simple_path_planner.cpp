//
// Created by aung on 2024/4/19.
//
#include <ros/ros.h>
#include <nav_msgs/Path.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/PoseStamped.h>
#include <cmath>
#include <tf/transform_broadcaster.h>
#include <tf/transform_datatypes.h>

class SimplePathPlanner
{
public:
    SimplePathPlanner() : nh("~"), global_path_topic("/global_path"),goal_topic("/move_base_simple/goal"),odom_topic("/odom"),frame_id("map"),distance_step(1.0)
    {
        // Get the global path topic name from parameter server if provided
        nh.param("global_path_topic", global_path_topic, global_path_topic);
        nh.param("goal_topic", goal_topic, goal_topic);
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
    static double getEuclideanDistance(const geometry_msgs::PoseStamped& p1, const geometry_msgs::PoseStamped& p2) {
        return std::hypot(p1.pose.position.x - p2.pose.position.x, p1.pose.position.y - p2.pose.position.y);
    }

    // return the quaternion between two points
    static geometry_msgs::Quaternion getDirection(const geometry_msgs::PoseStamped &current, const geometry_msgs::PoseStamped &next)
    {
        double dx = next.pose.position.x - current.pose.position.x;
        double dy = next.pose.position.y - current.pose.position.y;
        double yaw = atan2(dy, dx);
        return tf::createQuaternionMsgFromYaw(yaw);
    }

    void goalCallback(const geometry_msgs::PoseStamped::ConstPtr& goal_msg)
    {
        target_goal = *goal_msg;
        path_published = false; // 设置为false以便于publishPath函数可以执行
        // 不用调用 publishPath() 因为将在poseCallback中被调用
    }

    void poseCallback(const nav_msgs::Odometry::ConstPtr& odom_msg)
    {
        // 当收到第一个pose信息时或者目标点更新时，发布路径
        if (!path_published) {
            current_pose.header.stamp = ros::Time::now();
            current_pose.pose = odom_msg->pose.pose;
            publishPath();
            path_published = true; // 确保路径只会发布一次直到下一个目标点被接收
        }
    }

    void publishPath()
    {
        if (current_pose.header.stamp == ros::Time(0) || target_goal.header.stamp == ros::Time(0))
            return;

        double total_distance = getEuclideanDistance(current_pose, target_goal);
        int num_intermediate_points = std::floor(total_distance / distance_step);

        global_path.poses.clear();
        global_path.poses.push_back(current_pose);

        geometry_msgs::PoseStamped last_pose = current_pose;

        for(int i = 1; i <= num_intermediate_points; i++){
            double t = i * distance_step / total_distance;
            if(t > 1.0) {
                break; // Prevents overshooting the target goal
            }

            geometry_msgs::PoseStamped intermediate;
            intermediate.header.frame_id = frame_id;
            intermediate.header.stamp = ros::Time::now();
            intermediate.pose.position.x = (1 - t) * current_pose.pose.position.x + t * target_goal.pose.position.x;
            intermediate.pose.position.y = (1 - t) * current_pose.pose.position.y + t * target_goal.pose.position.y;

            // Set orientation from the last pose to the current intermediate pose
            intermediate.pose.orientation = getDirection(last_pose, intermediate);

            global_path.poses.push_back(intermediate);
            last_pose = intermediate; // Update last_pose for the next iteration
        }

        // Add the target goal as the last pose with its original orientation
        global_path.poses.push_back(target_goal);

        global_path.header.stamp = ros::Time::now();
        path_pub.publish(global_path);
    }

    bool path_published{false}; // 添加一个成员变量用来记录路径是否已经发布过

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
    spp.path_published = false; // 初始化时路径设为未发布
    ros::spin();
    return 0;
}