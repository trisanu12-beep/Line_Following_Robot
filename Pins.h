#ifndef PINS_H
#define PINS_H
#include <Arduino.h>

// --- IR Sensor Pins ---
#define irL A0  // Left Sensor
#define irR A1  // Right Sensor

// --- Motor Driver (L298N) Pins ---
// Motor A (Left)
#define M1pin1 2
#define M1pin2 3
#define ENA    9   // PWM Pin

// Motor B (Right)
#define M2pin1 4
#define M2pin2 5
#define ENB    10  // PWM Pin

#endif