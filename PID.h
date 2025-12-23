#ifndef PID_H
#define PID_H
#include <Arduino.h>

class PID {
  public:
    float Kp, Ki, Kd;
    float previousError;
    float integral;

    // Constructor
    PID(float p, float i, float d) {
      Kp = p;
      Ki = i;
      Kd = d;
      previousError = 0;
      integral = 0;
    }

    float calculate(float error) {
      // P Term
      float P = Kp * error;

      // I Term
      integral += error;
      float I = Ki * integral;

      // D Term
      float derivative = error - previousError;
      float D = Kd * derivative;

      previousError = error;

      return (P + I + D);
    }

    void reset() {
      previousError = 0;
      integral = 0;
    }
};

#endif