// Referenced to https://blog.csdn.net/mechleechan/article/details/79294181
// Response to RC remote controller reference to https://www.geek-workshop.com/thread-2408-1-1.html

#include <Servo.h>

#define SERVO_PIN 9
#define ESC_PIN   10

Servo servo;
Servo esc;
int potpin = 0;
int servo_val;
int esc_val;

void setup() {
    servo.attach(SERVO_PIN);

    esc.attach(ESC_PIN);
    esc.writeMicroseconds(1000); // initialize the signal to 1000

    Serial.begin(9600);
}

void loop() {
    servo_val = analogRead(potpin);
    servo_val = map(servo_val, 0, 1023, 0, 180);
    Serial.println(servo_val);
    servo.write(servo_val);

    esc_val = analogRead(A0);
    esc_val = map(esc_val, 0, 1023, 1000, 2000);
    Serial.println(esc_val);
    esc.writeMicroseconds(esc_val);

    // delay(15);
}