#include<Servo.h>

const int servoPin = 2;

Servo servo;

int servoAngle = 0;

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
}

void loop() {
  for (int i = 0; i <= 180; i++) {
    servo.write(i);
    delay(10);
  }
  
  for (int i = 180; i >= 0; i--) {
    servo.write(i);
    delay(10);
  }
}