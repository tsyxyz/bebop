#include <ros/ros.h>
#include <gflags/gflags.h>

#include <bebop_msgs/ChassisCmd.h>
#include "bebop_msgs/topic.h"

DEFINE_int32(angle, 0, "steer angle in degree");
DEFINE_int32(pulse_width, 0, "ESC pulse width");

int main(int argc, char** argv) {
    google::ParseCommandLineFlags(&argc, &argv, false);
    
    ros::init(argc, argv, "chassis_test");
    ros::NodeHandle nh;

    ros::Publisher cmd_pub = nh.advertise<bebop_msgs::ChassisCmd>(bebop_msgs::kTopicChassisCmd, 100);
    ros::Rate loop_rate(50);

    bebop_msgs::ChassisCmd cmd;
    while (ros::ok()) {
        cmd.header.stamp = ros::Time::now();
        cmd.angle = FLAGS_angle;
        cmd.pulse_width = FLAGS_pulse_width;
        cmd_pub.publish(cmd);
        ROS_INFO("Pub ChassisCmd, angle %d, throttle %u", cmd.angle, cmd.pulse_width);

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}