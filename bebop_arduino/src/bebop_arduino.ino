// Referenced to https://blog.csdn.net/mechleechan/article/details/79294181
// Response to RC remote controller reference to https://www.geek-workshop.com/thread-2408-1-1.html

#include <Servo.h>
#include <ros.h>
#include <bebop_control_msgs/ChassisCmd.h>

#define SERVO_PIN 9
#define ESC_PIN   10

Servo servo;
Servo esc;
int potpin = 0;
int servo_val;
int esc_val;

void OnChassisCmd(const bebop_control_msgs::ChassisCmd& cmd) {
    servo_val = map(cmd.steer, 
                    bebop_control_msgs::ChassisCmd::MIN_STEER,
                    bebop_control_msgs::ChassisCmd::MAX_STEER,
                    0, 180);
    esc_val = map(cmd.velocity,
                  bebop_control_msgs::ChassisCmd::MIN_VELOCITY,
                  bebop_control_msgs::ChassisCmd::MAX_VELOCITY,
                  1000, 2000);
}

ros::NodeHandle nh;
ros::Subscriber<bebop_control_msgs::ChassisCmd> cmd_sub("/chassis_cmd", &OnChassisCmd);

void setup() {
    nh.initNode();
    nh.subscribe(cmd_sub);

    servo.attach(SERVO_PIN);

    esc.attach(ESC_PIN);
    esc.writeMicroseconds(1000); // initialize the signal to 1000
}

void loop() {
    servo.write(servo_val);
    esc.writeMicroseconds(esc_val);
}