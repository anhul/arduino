/*
Controls servo motor
- sets specific position(angle) of servo horn
- sets speed of servo by setting delay time after each step in 1 degree
- prints current position of the servo horn
*/
#include <Servo.h>

Servo myservo;
int servoPin = 9;

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

void servoPosPrint(){
  int pos = myservo.read();
  Serial.print("Current position: ");
  Serial.println(pos);
}

void setup() {
  Serial.begin(9600);
  myservo.attach(servoPin);
  servoMoveTo(0); // Set servo at init 0 degree possition
  servoPosPrint(); 
}

void loop() {
  servoMoveTo(90, 5);
  servoPosPrint();  
  delay(1000);

 servoMoveTo(180, 5);
  servoPosPrint();  
  delay(1000);

 servoMoveTo(90, 20);
  servoPosPrint();  
  delay(1000);

 servoMoveTo(0, 50);
  servoPosPrint();  
  delay(1000);
}
