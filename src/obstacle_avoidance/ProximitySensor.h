#include <Arduino.h>

const double MICROSECONDS_TO_CM = 0.034/2.0;

class ProximitySensor {

    int trigPin = 12;
    int echoPin = 13;

    public:

        ProximitySensor(int trigPin, int echoPin) {
            this->trigPin = trigPin;
            this->echoPin = echoPin;
            pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
            pinMode(echoPin, INPUT); // Sets the echoPin as an Input
        }    

        float measureDistanceCm() {
            
            // Clear the trigPin
            digitalWrite(trigPin, LOW);
            delayMicroseconds(2);
            
            // Set the trigPin on HIGH state for 10 microseconds
            digitalWrite(trigPin, HIGH);
            delayMicroseconds(10);
            digitalWrite(trigPin, LOW);

            // Read the echoPin, returns the sound wave travel time in microseconds, and calculate distance
            return pulseIn(echoPin, HIGH) * MICROSECONDS_TO_CM;
        }

};