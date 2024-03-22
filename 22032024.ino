// These constants won't change. They're used to give names to the pins used:


const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to


const int digitalOutPin1 = 9; // Analog output pin that the LED is attached to
const int digitalOutPin2 = 8; // Analog output pin that the LED is attached to
const int digitalOutPin3 = 7; // Analog output pin that the LED is attached to


int sensorValue = 0;        // value read from the pot

int outputValue = 0;        // value output to the PWM (analog out)


void setup() {


  // initialize serial communications at 9600 bps:


  pinMode(digitalOutPin1, OUTPUT);
  pinMode(digitalOutPin2, OUTPUT);
  pinMode(digitalOutPin3, OUTPUT);
}


void loop() {


  // read the analog in value:


  sensorValue = analogRead(analogInPin);


  // map it to the range of the analog out:


  outputValue = map(sensorValue, 0, 1023, 0, 255);


  // change the analog out value:
  int digitalOut1 = LOW;
  int digitalOut2 = LOW;
  int digitalOut3 = LOW;
  if (outputValue > 0 && outputValue < 80) {

    digitalOut1 = HIGH;

  }else if (outputValue <160) {
    
    digitalOut2 = HIGH;

  }else {
    
    digitalOut3 = HIGH;

  }

    digitalWrite(digitalOutPin1,digitalOut1);
    digitalWrite(digitalOutPin2,digitalOut2);
    digitalWrite(digitalOutPin3,digitalOut3);


}