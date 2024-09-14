/* Turns on LED connected to digital pin 2,
when pressing the push button attached to digital input pin 7.

Instead of using external pull up resistor, the input pin is
configured in INPUT_PULLUP mode. That means this pin is pulled up
to VCC 5V using internal 20 KOm resistor.

When the button is not pressed, the input pin is pulled HIGH.
When the button is pressed, the input pin is pulled LOW.
*/
int ledPin = 2;
int buttonPin = 7;
int buttonState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    digitalWrite(ledPin, HIGH);
  } else {
      digitalWrite(ledPin, LOW); 
  }
}
