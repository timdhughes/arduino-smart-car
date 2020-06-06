#include "SmartCar.h"
#include "DirectionalProximitySensor.h"

// Define pins
const int left_motor_forward_pin = 7;
const int left_motor_backward_pin = 8;
const int left_motor_speed_pin = 3;

const int right_motor_forward_pin = 2;
const int right_motor_backward_pin = 4;
const int right_motor_speed_pin = 5;

const int ultrasonic_trigger_pin = 12;
const int ultrasonic_speed_pin = 13;

// The servo library use timer 1 and disables all other analogWrite() commands for associated timer 1 pins.  
// In this case, pins 9 and 10 are attached to timer 1.
// See for https://www.arduino.cc/en/Tutorial/SecretsOfArduinoPWM
// IMPORTANT: Pin 10 can no longer be used for analogWrite() 
const int servo_motor_pin = 9; 

DcMotor motor_left(left_motor_forward_pin, left_motor_backward_pin, left_motor_speed_pin);
DcMotor motor_right(right_motor_forward_pin, right_motor_backward_pin, right_motor_speed_pin);

TwoWheelRobot robot(&motor_left, &motor_right);

DirectionalProximitySensor proximity_sensor(servo_motor_pin, ultrasonic_trigger_pin, ultrasonic_speed_pin);

int max_speed = 255;
int approach_speed = 200;


void setup() {  
  Serial.begin(9600); // Starts the serial communication
}


void loop() {
    
  float dist_cm = proximity_sensor.measureDistanceStraightAhead();
  printDist(dist_cm);

  if (dist_cm < 20) {

    Serial.println("Stopping and backing up...");  
    robot.stop(300);
    robot.backUp(400);
    robot.stop(300);

    float distance_left_cm = proximity_sensor.measureMinDistanceOnLeftSide();
    float distance_right_cm = proximity_sensor.measureMinDistanceOnRightSide();

    if (distance_left_cm < dist_cm) {
      Serial.println("Right turn");  
      robot.setSpeed(200, -55);
      delay(700);
      robot.stop(300);
    }
    else {
      Serial.println("Left turn");  
      robot.setSpeed(-55, 200);
      delay(700);
      robot.stop(300);
    }
  }
  else{
    robot.setSpeed(255, 255);
  }
  
}

void printDist(double dist_cm) {
  Serial.print("Distance (cm): ");
  Serial.println(dist_cm);  
}
