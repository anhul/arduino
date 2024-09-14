int ledPin = 2;
int ledOnTime = 2000;
int ledOffTime = 1000;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(ledOnTime);
  
  digitalWrite(ledPin, LOW); 
  delay(ledOffTime); 

}
