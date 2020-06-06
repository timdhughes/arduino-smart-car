#include <Arduino.h>

class DcMotor {

    int pinDir1;
    int pinDir2;
    int speedPin;

    public:
    
        DcMotor(int pinDir1, int pinDir2, int speedPin) {
            this->pinDir1 = pinDir1;
            this->pinDir2 = pinDir2;
            this->speedPin = speedPin;
            pinMode(pinDir1, OUTPUT);
            pinMode(pinDir2, OUTPUT);
            pinMode(speedPin, OUTPUT);
        }

        // Set speed between -255 and 255 
        void set_speed(int speed) {

            analogWrite(this->speedPin, abs(speed));
            
            if (speed > 0) {
                digitalWrite(this->pinDir1, HIGH);
                digitalWrite(this->pinDir2, LOW);
            } else {
                digitalWrite(this->pinDir1, LOW);
                digitalWrite(this->pinDir2, HIGH);
            }      
            
        }

};

class TwoWheelRobot {
    
    DcMotor *motor1;
    DcMotor *motor2;
    
    public:

        TwoWheelRobot(DcMotor* motor1, DcMotor* motor2) {
            this->motor1 = motor1;
            this->motor2 = motor2;
        }
};
