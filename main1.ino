#include "Pins.h"
#include "PID.h"
#include "IR.h"
#include "Motor.h"

// --- Objects ---
ir IR;
Motor motor;

// PID Tuning: (Kp, Ki, Kd)
// Kp=25.0 (Strong turns), Ki=0.0 (No memory), Kd=14.0 (Reduces wobbling)
PID pid(25.0, 0.0, 14.0); 

void setup() {
  Serial.begin(9600);
  motor.setup();
  
  // Wait 2 seconds before starting so you can move your hand
  delay(2000);
}

void loop() {
  // 1. Get the error from IR sensors
  int error = IR.getError();

  // --- STOP LOGIC: BOTH BLACK ---
  // If IR.getError() returns 100, it means both sensors are on Black.
  if (error == 100) {
    motor.stop();    // Stop the motors
    while(1);        // Infinite loop: Freezes the robot here forever
  }

  // 2. Calculate PID Output
  float pidOutput = pid.calculate(error);

  // 3. Drive Motors
  motor.control(pidOutput);
  
  // Debugging (Uncomment if needed)
  // Serial.println(error);
}