//
// Created by ctb on 1/20/19.
//

#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include "std_msgs/String.h"
#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "nav_msgs/Path.h"
using namespace std;

ros::Publisher pub_distance;

void pathTrackerCallback(const nav_msgs::Path &odom_msg)
{
    //ROS_INFO_STREAM("path"<<odom_msg.poses.size());
    int len=odom_msg.poses.size();
    float position_x=odom_msg.poses.back().pose.position.x;
    float position_y=odom_msg.poses.back().pose.position.y;
    float position_z=odom_msg.poses.back().pose.position.z;
    ROS_INFO_STREAM("position"<<position_x<<position_y<<position_z);

    float orientation_x=odom_msg.poses.back().pose.orientation.x;
    float orientation_y=odom_msg.poses.back().pose.orientation.y;
    float orientation_z=odom_msg.poses.back().pose.orientation.z;
    float orientation_w=odom_msg.poses.back().pose.orientation.w;

    //calculate the distance between the AP and the camera
    float position_ap_x=4.239254485518047;
    float position_ap_y=1.217918714770732;
    float position_ap_z=1.2099123218848773;
    float distance=pow(pow(position_x-position_ap_x,2) +pow(position_y-position_ap_y,2)+pow(position_z-position_ap_z ,2),0.5);
    string result;
    ostringstream convert;
    convert <<distance;
    result=convert.str();
    ROS_INFO_STREAM("the distance between the AP and the camera is "<<result);

    //convert string to ROS data and publish
    std_msgs::String msg;
    msg.data=result;
    pub_distance.publish(msg);

}

int main(int argc, char **argv)
{
    ros::init(argc,argv,"path_tracker");
    ros::NodeHandle n("~");

    ROS_INFO("tracking the path and creating the PCL");

    pub_distance=n.advertise<std_msgs::String>("distance", 1000);

    ros::Subscriber sub_path=n.subscribe("/benchmark_publisher/path", 1000, pathTrackerCallback);
    ros::Rate r(20);
    ros::spin();
}

