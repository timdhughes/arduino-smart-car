#include <Arduino.h>

class DcMotor {

    int motorForwardPin;
    int motorReversePin;
    int speedPin;

    public:
    
        DcMotor(int motorForwardPin, int motorReversePin, int speedPin) {
            this->motorForwardPin = motorForwardPin;
            this->motorReversePin = motorReversePin;
            this->speedPin = speedPin;
            pinMode(motorForwardPin, OUTPUT);
            pinMode(motorReversePin, OUTPUT);
            pinMode(speedPin, OUTPUT);
        }

        // Set speed between -255 and 255 
        void setSpeed(int speed) {

            analogWrite(this->speedPin, abs(speed));
            
            if (speed > 0) {
                digitalWrite(this->motorForwardPin, HIGH);
                digitalWrite(this->motorReversePin, LOW);
            } else {
                digitalWrite(this->motorForwardPin, LOW);
                digitalWrite(this->motorReversePin, HIGH);
            }      
            
        }

};

class TwoWheelRobot {
    
    DcMotor *leftMotor;
    DcMotor *rightMotor;
    
    public:

        TwoWheelRobot(DcMotor* leftMotor, DcMotor* rightMotor) {
            this->leftMotor = leftMotor;
            this->rightMotor = rightMotor;
        }

        void stop(int duration_ms = 1000) {
            this->setSpeed(0, 0);
            delay(duration_ms);
        }

        void backUp(int duration_ms = 500) {
            this->setSpeed(-255, -255);
            delay(duration_ms);
        }

        void setSpeed(int speed_left, int speed_right) {
            this->leftMotor->setSpeed(speed_left);
            this->rightMotor->setSpeed(speed_right);            
        }

        void turn(int deg) {

            this->leftMotor->setSpeed(200);
            this->rightMotor->setSpeed(-55);
            
            delay(750);

            this->leftMotor->setSpeed(0);
            this->rightMotor->setSpeed(0);       

        }
};
