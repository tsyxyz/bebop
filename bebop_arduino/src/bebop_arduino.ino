// Referenced to https://blog.csdn.net/mechleechan/article/details/79294181
// Response to RC remote controller reference to https://www.geek-workshop.com/thread-2408-1-1.html

#include <Servo.h>
#include <ros.h>
#include <bebop_control_msgs/ChassisCmd.h>

const int kServoPin = 9;
const int kEscPin = 10;
const char* kChassisCmdTopic = "/chassis_cmd";
const int kServoMiddle = 90;
const int kEscMiddle = 1500;

Servo servo;
Servo esc;
int servo_val;
int esc_val;

void OnChassisCmd(const bebop_control_msgs::ChassisCmd& cmd) {
    servo_val = map(cmd.steer, 
                    bebop_control_msgs::ChassisCmd::kMinSteer,
                    bebop_control_msgs::ChassisCmd::kMaxSteer,
                    0, 180);
    esc_val = map(cmd.throttle,
                  bebop_control_msgs::ChassisCmd::kMinThrottle,
                  bebop_control_msgs::ChassisCmd::kMaxThrottle,
                  1000, 2000);
}

ros::NodeHandle nh;
ros::Subscriber<bebop_control_msgs::ChassisCmd> cmd_sub(kChassisCmdTopic, &OnChassisCmd);

void setup() {
    servo_val = kServoMiddle;
    esc_val = kEscMiddle;

    nh.initNode();
    nh.subscribe(cmd_sub);

    servo.attach(kServoPin);
    servo.write(kServoMiddle);

    esc.attach(kEscPin);
    esc.writeMicroseconds(kEscMiddle);
}

void loop() {
    servo.write(servo_val);
    esc.writeMicroseconds(esc_val);
}