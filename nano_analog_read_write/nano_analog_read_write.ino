/*
Fades LED connected to PWM output pin 3 basing on the position of the potentiometer.

 - Reads input value from analog pin A0 connected to center pin of a potentiometer by using function analogRead().
 - analogRead() converts analog input value into digital level value in range [0, 1023].
 - Outer pins of potentiometer are connected to 5V and GND pins accordingly.
 - Received input value is converted into corresponding value in the range [0, 255] which is
   accepted by analogWrite() function by using map() function. 
- analogWrite() outputs the value to PWM pin 3 connected to LED.
*/
int potPin = A0;
int ledPin = 3;
float potOhms = 1000;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin);
  float voltage = potValue * (5.0 / 1023.0);
  float resistance =  potOhms - potValue * (potOhms / 1023.0);
  Serial.print("Sensor value: ");
  Serial.println(potValue);
  Serial.print("Voltage value: ");
  Serial.println(voltage);
  Serial.print("Resistance value: ");
  Serial.println(resistance);
  int led_brightness = map(potValue, 0, 1024, 0, 255);
  analogWrite(ledPin, led_brightness);
  delay(10);
}
