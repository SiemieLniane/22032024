#include<Servo.h>

const int servoPin = 2;
const int lewoPin = 7;
const int prawoPin = 8;

Servo servo;

int servoAngle = 0;

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
  pinMode(lewoPin,INPUT);
  pinMode(prawoPin,INPUT);
}

void loop() {
  int lewoValue = digitalRead(lewoPin);
  int prawoValue = digitalRead(prawoPin);
  if (lewoValue == HIGH && servoAngle >= 0) {
    servoAngle--;
  } 
  if (prawoValue == HIGH && servoAngle <= 180) {
     servoAngle++;
  }
  if (lewoValue == prawoValue) {
    if (servoAngle < 90) {
      servoAngle++;
    }
    if (servoAngle > 90) {
      servoAngle--;
    }
  }
    servo.write(servoAngle);
    delay(2);
  }
  
/*
for (int i = 0; i <= 180; i++) {
    servo.write(0.5);
    delay(delayMs);
  }
  
  for (int i = 180; i >= 0; i--) {
    servo.write(i);
    delay(delayMs);
  }
*/