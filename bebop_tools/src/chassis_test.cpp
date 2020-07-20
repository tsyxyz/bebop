#include <ros/ros.h>
#include <gflags/gflags.h>

#include <bebop_control_msgs/ChassisCmd.h>
#include "bebop_msgs/topic.h"

DEFINE_double(steer, 0, "steer angle in rad, <0 left, >0 right");
DEFINE_double(throttle, 0, "throttle, <0 backward, >0 forward");

int main(int argc, char** argv) {
    google::ParseCommandLineFlags(&argc, &argv, false);
    
    ros::init(argc, argv, "chassis_test");
    ros::NodeHandle nh;

    ros::Publisher cmd_pub = nh.advertise<bebop_control_msgs::ChassisCmd>(bebop_msgs::kTopicChassisCmd, 100);
    ros::Rate loop_rate(50);

    bebop_control_msgs::ChassisCmd cmd;
    while (ros::ok()) {
        cmd.header.stamp = ros::Time::now();
        cmd.steer = FLAGS_steer;
        cmd.throttle = FLAGS_throttle;
        cmd_pub.publish(cmd);
        ROS_INFO("Pub ChassisCmd, steer %f, throttle %f", cmd.steer, cmd.throttle);

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}