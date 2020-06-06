#include "SmartCar.h"

//unsigned long time = 0;
//time = millis();

DcMotor motor_left(7, 8, 9);
DcMotor motor_right(2, 4, 10);

TwoWheelRobot robot(&motor_left, &motor_right);

void setup() {
  motor_left.set_speed(-200);
  motor_right.set_speed(-133);

}

void loop() {


}
