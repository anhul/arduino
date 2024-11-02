/* Turns on/off LED connected to digital pin 2
when pressing the push button attached 
to the digital input pin 3 supporting hardware interrupts.

*/
const byte ledPin = 2;
const byte buttonPin = 3;

volatile bool ledState = LOW; // LED state

void changeState() {
  /*
  Interrupt Service Routine (ISR) to monitor state change 
  and toggle LED state accodingly

  Static variables have the property of preserving their value even after they are out of their scope!
  Hence, a static variable preserves its previous value in its previous scope 
  and is not initialized again in the new scope. 
  */
  static unsigned long lastInterruptTime = 0;
  unsigned long interruptTime = millis();
  if (interruptTime - lastInterruptTime >= 50) {
      ledState = !ledState;
      digitalWrite(ledPin, ledState);
  } else {
    lastInterruptTime = interruptTime;
  }    
}

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  // Attach Interrupt to Interrupt Service Routine
  attachInterrupt(digitalPinToInterrupt(buttonPin), changeState, FALLING);
}

void loop() {
 delay(5000);
}
