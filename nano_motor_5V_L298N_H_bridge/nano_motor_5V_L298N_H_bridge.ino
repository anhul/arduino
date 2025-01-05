/*
Controls small DC motor AMS1141M by using H-bridge L298N.
*/
const int potPin = A0;
// PWM pin to control motor speed
const int enA = 3;
// Input pins to control motor spinning direction
const int in1 = 4;
const int in2 = 5;

const int ledPin = 2;
const int buttonPin = 7;
bool direction = 0;

void setup() {
pinMode(enA, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(ledPin, OUTPUT);
pinMode(buttonPin, INPUT_PULLUP);

}

void loop() {
  int potPos = analogRead(potPin);
  int motorSpeed = map(potPos, 0, 1023, 0, 255);
  if (motorSpeed > 3) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }  
  analogWrite(enA, motorSpeed);
  bool buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    direction = !direction;
  } 
  if (direction == 0) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);   
  } else if (direction == 1) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }  
  delay(20);
}
