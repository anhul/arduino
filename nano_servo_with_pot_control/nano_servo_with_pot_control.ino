/*
Controls servo motor
- sets specific position(angle) of servo horn depending on the position of the potentiometer
*/
#include <Servo.h>

Servo myservo;
int servoPin = 9;
int potPin = A0;
int potLastPos;

void servoMoveTo(int pos, int step_delay=0) {  
  int steps = 1;
  int target_pos = pos; 
  int current_pos = myservo.read();
  if (current_pos < target_pos) {
    for (int pos = current_pos; pos <= target_pos; pos += steps){
      myservo.write(pos);
      if (step_delay != 0) {
       delay(step_delay); 
      }
      
    }  
  } else if (current_pos > target_pos) {
    for (int pos = current_pos; pos >= target_pos; pos -= steps){
      myservo.write(pos);
      if (step_delay != 0) {
       delay(step_delay); 
      }
    }
  }    
}

void setup() {
  myservo.attach(servoPin);
  potLastPos = analogRead(potPin);
  Serial.begin(9600);
  Serial.print(potLastPos);
}

void loop() {
  int potPos = analogRead(potPin);  
  // if statement is used to eliminate servo horn trembling due to pot values fluctuations 
  if ((abs(potPos - potLastPos) > 6) || (potPos == 0) || (potPos == 1023))  {
    Serial.println(potPos);
    int angle = map(potPos, 0, 1023, 0, 180);
    myservo.write(angle);
    potLastPos = potPos;
    delay(10);
  }
  
}
