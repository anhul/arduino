
/*
 Controls unipolar stepper motor 28BYJ-48 using motor driver module ULN2003
 The motor is attached to digital pins 8 - 11 of the Arduino.
 
 Please keep in mind that step() is a blocking function. 
 This means that the Arduino will wait until the motor stops running before proceeding to the next line in your sketch.
 */

#include <Stepper.h>

// Defines the number of steps per rotation
const int STEPS_PER_REVOLUTION = 2048;

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper(STEPS_PER_REVOLUTION, 8, 10, 9, 11);

void setup() { 
}

void loop() {
  // step one revolution  in clockwise direction
  myStepper.setSpeed(1);
  myStepper.step(STEPS_PER_REVOLUTION);
  delay(500);

  // step one revolution in the counterclockwise direction
  myStepper.setSpeed(20);
  myStepper.step(-STEPS_PER_REVOLUTION);
  delay(500);
}

