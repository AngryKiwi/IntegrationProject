#include <Encoder.h>
#include <PID_v1.h>

double Setpoint, Input, Output;
PID myPID(&Input, &Output, &Setpoint, 4, 2, 2, DIRECT);
Encoder myEnc(2, 3);
long oldPosition  = -999;

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  //Input = myEnc.read();
  //Serial.println(Input);
  Setpoint = -100;
  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(-255, 255);
  myPID.SetSampleTime(10);
}

void loop() {
speedControlPID();
}

void speedControlPID(){
    long newPosition = myEnc.read();
  //Serial.println("newPosition:");
 // Serial.println(newPosition);
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    Input = myEnc.read();
    myPID.Compute();
//    Serial.println("INPUT:");   
//    Serial.println(Input);
//    Serial.println("OUTPUT:");
//    Serial.println(Output);
//    Serial.println("NEW POSITION:");
//    Serial.println(newPosition);

    if (Output > 0) {
      digitalWrite(8, HIGH);
      digitalWrite(9,LOW);
      analogWrite(5, abs(Output));
    } else if (Output < 0) {
      digitalWrite(8, LOW);
      digitalWrite(9,HIGH);
      analogWrite(5, abs(Output));
    } else {
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      analogWrite(5, abs(Output));
    }
  }
}
