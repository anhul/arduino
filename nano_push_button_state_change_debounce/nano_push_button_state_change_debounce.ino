/* Turns on/off LED connected to digital pin 2
when pressing the push button attached to the digital input pin 7.
Ignores button pin state change withing very short periods to eliminate 
side effects of button bouncing or noises.

Funtion millis() returns the number of milliseconds passed since 
the Arduino board began running the current program. 
This number will overflow (go back to zero), after approximately 50 days.
*/
const int ledPin = 2;
const int buttonPin = 7;

int lastButtonPinState = HIGH; // last button pin state
int lastButtonState = HIGH; // last stable button state
bool ledState = LOW; // LED state

// unsigned long because the time is measured in milliseconds 
// and will quickly become a bigger number than can be stored in an int.
unsigned long lastTimeButtonPinStateChanged = 0;  // the last time the button pin state was changed
unsigned long debounceDelay = 50;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int buttonPinState = digitalRead(buttonPin);
  if (buttonPinState != lastButtonPinState) {
    lastTimeButtonPinStateChanged = millis();
  }
  lastButtonPinState = buttonPinState;

  if ((millis() - lastTimeButtonPinStateChanged) > debounceDelay) {
    // consider current pin state as stable button state
    int buttonState = buttonPinState;
    if (buttonState != lastButtonState) {      
      if (buttonState == LOW) {
        ledState = !ledState;
        digitalWrite(ledPin, ledState); 
      }
      lastButtonState = buttonState;   
    }    
  }  
}
