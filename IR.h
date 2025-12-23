#ifndef IR_H
#define IR_H
#include <Arduino.h>
#include "Pins.h"

// THRESHOLD:
// Adjust this if your sensors are inverted.
// Currently: Analog > 500 means BLACK.
#define THRESHOLD 500 

class ir {
  public:
    int rawRight, rawLeft;
    
    void readVal() {
      rawRight = analogRead(irR);
      rawLeft = analogRead(irL);
    }

    // Returns: 
    // 0   = Center (Go Straight)
    // -1  = Turn Left
    // 1   = Turn Right
    // 100 = Both Black (STOP)
    int getError() {
      readVal();

      bool leftSeeLine = (rawLeft > THRESHOLD);
      bool rightSeeLine = (rawRight > THRESHOLD);

      // --- CASE: BOTH BLACK (STOP) ---
      if (leftSeeLine && rightSeeLine) {
        return 100; // Special code for Main Loop
      }
      
      // --- CASE: TURN LEFT ---
      else if (leftSeeLine && !rightSeeLine) {
        return -1; 
      }
      // --- CASE: TURN RIGHT ---
      else if (!leftSeeLine && rightSeeLine) {
        return 1;  
      }
      // --- CASE: BOTH WHITE (CENTER) ---
      else {
        return 0;  
      }
    }
};

#endif