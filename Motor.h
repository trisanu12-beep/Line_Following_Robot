#ifndef MOTOR_H
#define MOTOR_H
#include <Arduino.h>
#include "Pins.h"

class Motor {
  public:
    // Base speed for the robot (0-255)
    // Reduce this if the robot wobbles too much!
    int baseSpeed = 50; 

    void setup() {
      pinMode(M1pin1, OUTPUT);
      pinMode(M1pin2, OUTPUT);
      pinMode(ENA, OUTPUT);
      pinMode(M2pin1, OUTPUT);
      pinMode(M2pin2, OUTPUT);
      pinMode(ENB, OUTPUT);
    }

    void control(float pidValue) {
      // Calculate speeds
      // If pidValue is (+), we turn Right -> Increase Left Motor, Decrease Right Motor
      int leftSpeed = baseSpeed + pidValue;
      int rightSpeed = baseSpeed - pidValue;

      // Constrain speeds to PWM range 0-255
      leftSpeed = constrain(leftSpeed, 0, 255);
      rightSpeed = constrain(rightSpeed, 0, 255);

      // Apply to motors
      driveLeft(leftSpeed);
      driveRight(rightSpeed);
    }

    void stop() {
      digitalWrite(M1pin1, LOW);
      digitalWrite(M1pin2, LOW);
      analogWrite(ENA, 0);

      digitalWrite(M2pin1, LOW);
      digitalWrite(M2pin2, LOW);
      analogWrite(ENB, 0);
    }

  private:
    void driveLeft(int spd) {
      if (spd > 0) {
        digitalWrite(M1pin1, HIGH);
        digitalWrite(M1pin2, LOW);
      } else {
        // Simple stop if speed is 0 or negative (or implement reverse if needed)
        digitalWrite(M1pin1, LOW);
        digitalWrite(M1pin2, LOW);
      }
      analogWrite(ENA, abs(spd));
    }

    void driveRight(int spd) {
      if (spd > 0) {
        digitalWrite(M2pin1, HIGH);
        digitalWrite(M2pin2, LOW);
      } else {
        digitalWrite(M2pin1, LOW);
        digitalWrite(M2pin2, LOW);
      }
      analogWrite(ENB, abs(spd));
    }
};

#endif