// Referenced to https://blog.csdn.net/mechleechan/article/details/79294181
// Response to RC remote controller reference to https://www.geek-workshop.com/thread-2408-1-1.html

#include <Servo.h>
#include <ros.h>
#include <Arduino.h>

#include <bebop_msgs/ChassisCmd.h>
#include <bebop_msgs/topic.h>

class Chassis {
public:
    void Init(int esc_pin, int servo_pin) {
        esc_.attach(esc_pin);
        servo_.attach(servo_pin);

        esc_.writeMicroseconds(kMiddlePulseWidth_);
        servo_.write(kMiddleAngle_);
    }

    void Move() {
        esc_.writeMicroseconds(pulse_width_);
        servo_.write(angle_);
    }

    void Update(int pulse_width, int angle) {
        if (pulse_width > kMaxPulseWidth_) pulse_width = kMaxPulseWidth_;
        else if (pulse_width < kMinPulseWidth_) pulse_width = kMinPulseWidth_;

        if (angle > kMaxAngle_) angle = kMaxAngle_;
        else if (angle < kMinAngle_) angle = kMinAngle_;
        
        pulse_width_ = pulse_width;
        angle_ = angle;
    }

private:
    const int kMinPulseWidth_ = 1000;
    const int kMaxPulseWidth_ = 2000;
    const int kMiddlePulseWidth_ = 1500;
    const int kMinAngle_ = 0;
    const int kMaxAngle_ = 180;
    const int kMiddleAngle_ = 90;

private:
    int pulse_width_ = 0;
    int angle_ = 0;
    Servo servo_;
    Servo esc_;
};

void OnChassisCmd(const bebop_msgs::ChassisCmd& cmd);

const int kServoPin = 9;
const int kEscPin = 10;

ros::NodeHandle nh;
Chassis chassis;
ros::Subscriber<bebop_msgs::ChassisCmd> cmd_sub(bebop_msgs::kTopicChassisCmd, &OnChassisCmd);

void OnChassisCmd(const bebop_msgs::ChassisCmd& cmd) {
    chassis.Update(cmd.pulse_width, cmd.angle);
}

void setup() {
    chassis.Init(kEscPin, kServoPin);
    delay(2000);

    nh.initNode();
    nh.subscribe(cmd_sub);
    delay(1000);
}

void loop() {
    chassis.Move();
}