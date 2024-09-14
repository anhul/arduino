// Turns on LED connected to digital pin 2,
// when pressing the push button attached to diginal pin 7.
// - when the button is not pressed button pin is pulled HIGH
// - when the button is pressed the input pin is pulled LOW
int ledPin = 2;
int ledOnTime = 2000;
int ledOffTime = 1000;

int buttonPin = 7;
int buttonState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    digitalWrite(ledPin, HIGH);
  } else {
      digitalWrite(ledPin, LOW); 
  }

}
