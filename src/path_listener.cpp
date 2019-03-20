#include <fstream>
#include <iostream>
#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "nav_msgs/Path.h"

using namespace std;
ofstream fout("/home/ctb/CODE/uav/catkin_ws/bagfiles/path_groundtruth.txt");

void pathCallback(const nav_msgs::Path &odom_msg)
{
    //ROS_INFO("path callback");
    ROS_INFO_STREAM("path"<<odom_msg.poses.size());
    int len=odom_msg.poses.size();
    float position_x=odom_msg.poses.back().pose.position.x;
    float position_y=odom_msg.poses.back().pose.position.y;
    float position_z=odom_msg.poses.back().pose.position.z;

    float orientation_x=odom_msg.poses.back().pose.orientation.x;
    float orientation_y=odom_msg.poses.back().pose.orientation.y;
    float orientation_z=odom_msg.poses.back().pose.orientation.z;
    float orientation_w=odom_msg.poses.back().pose.orientation.w;

    fout<<len<<" ";
    fout<<position_x<<" ";
    fout<<position_y<<" ";
    fout<<position_z<<" ";
    fout<<orientation_x<<" ";
    fout<<orientation_y<<" ";
    fout<<orientation_z<<" ";
    fout<<orientation_z<<" ";
    fout<<endl;
    //float data=odom_msg.poses.pose.position.x;
}

int main(int argc, char **argv)
{
    ros::init(argc,argv,"path_listener");
    ros::NodeHandle n;

    ROS_INFO("start receiving path data");

    ros::Subscriber sub = n.subscribe("/benchmark_publisher/path", 1000, pathCallback);

    ros::spin();
    fout.close();

    return 0;

}


