#include <SoftwareSerial.h>
//Bluetooth serial 
SoftwareSerial bt(0,1 ); // RX, TX


// Arduino pin numbers
const int SW_pin = 8; // digital pin connected to switch output
const int xPin = 0; // analog pin connected to X output
const int yPin = 1; // analog pin connected to Y output
int oldButtonState = LOW;
bool toggle = false;


void setup() {
  // Enable switch pin and set high
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  bt.begin(9600);
  //Serial.begin(9600);
}

void loop() {
  
  //Serial.print("Switch:  ");
  // Get the current button state
   int newButtonState = digitalRead(SW_pin);
   // Has the button gone high since the last input?
  if (newButtonState == HIGH && oldButtonState == LOW) {
    if (toggle == false) {
      // Toggle Autonomous on
      toggle = true;

    } else {
      // Toggle Autonomous off
      toggle = false;
    }
  }
  // Store the button's state so we can tell if it has changed
  oldButtonState = newButtonState;
  //bt.println("REc");

    
   bt.println(toggle);
  //Serial.print("\n");
  //Serial.print("X-axis: ");
  int xPosition = (analogRead(xPin));
  //Serial.print(xPosition);
  bt.println(xPosition);
  //Serial.print("\n");
  //Serial.print("Y-axis: ");
  int yPosition = (analogRead(yPin));
  bt.println(yPosition);
  //Serial.println(yPosition);
  //Serial.print("\n\n");
  delay(5);
}
