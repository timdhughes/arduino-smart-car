// Run this program when attaching the proximity sensor to the servo motor.
// This program puts the proximity sensor at 90 degrees, directly in front of the smart car.
#include <Servo.h>

Servo myservo;  
void setup() {
  // SG90 datasheet states that the minimum pulse width is 1000 us and maxmimum is 2000 us
  // After some experimentation, applying a scale factor of 3/4 gave the best results.
  myservo.attach(6, 750, 1500);  
  myservo.write(90);      
}

void loop() {}