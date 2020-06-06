#include <Servo.h>
#include "ProximitySensor.h"

class DirectionalProximitySensor {

    ProximitySensor *sensor;
    Servo *servo;

    void setAngleDeg(int angle) {
        servo->write(angle);
        waitToReachPosition();
    }

    void waitToReachPosition() {
        delay(20);
    }

    public:

        DirectionalProximitySensor(int servoPin, int trigPin, int echoPin) {
            this->servo = new Servo();
            servo->attach(servoPin);
            this->sensor = new ProximitySensor(trigPin, echoPin);
        }    

        ~DirectionalProximitySensor() {
            delete this->servo;
            delete this->sensor;
        }

        float measureDistanceStraightAhead() {
            setAngleDeg(90);
            return sensor->measureDistanceCm();
        }          

        float measureMinDistanceOnLeftSide() {
            int min_distance = 1.0e10f;
            for (int angle = 70; angle >= 10; angle -= 20) {
                setAngleDeg(angle);
                float current_distance = sensor->measureDistanceCm();
                if (current_distance > min_distance) {
                    min_distance = current_distance;
                }
            }
            return min_distance;
        }  

        float measureMinDistanceOnRightSide() {
            int min_distance = 1.0e10f;
            for (int angle = 110; angle <= 170; angle += 20) {
                setAngleDeg(angle);
                float current_distance = sensor->measureDistanceCm();
                if (current_distance > min_distance) {
                    min_distance = current_distance;
                }
            }
            return min_distance;
        }      

};