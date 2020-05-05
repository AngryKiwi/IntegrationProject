#include <SoftwareSerial.h>
//Bluetooth serial
SoftwareSerial bt(0, 1 ); // RX, TX


// Arduino pin numbers
const int SW_pin = 8; // digital pin connected to jostick button output
const int SW_Autonomous_Manual = 7; // digital pin connected to button
const int xPin = 0; // analog pin connected to X output
const int yPin = 1; // analog pin connected to Y output
int oldButtonState = LOW;
int oldButtonState_Autonomous_Manual = LOW;
bool toggle = false;
bool toggle_Autonomous_Manual = false;
int oldVal;

void setup() {
  // Enable switch pin and set high
  pinMode(SW_pin, INPUT);
  pinMode(SW_Autonomous_Manual, INPUT);
  digitalWrite(SW_Autonomous_Manual, HIGH);
  digitalWrite(SW_pin, HIGH);
  bt.begin(9600); // bluetooth sending 9600 baud
}

void loop() {
  // Get the current button state
  int newButtonState = digitalRead(SW_pin);
  // Has the button gone high since the last input?
  if (newButtonState == HIGH && oldButtonState == LOW) {
    if (toggle == false) {
      // Toggle half to full speed on
      toggle = true;

    } else {
      // Toggle quarter to half speed on
      toggle = false;
    }
  }
  // Store the button's state so we can tell if it has changed
  oldButtonState = newButtonState;


  // Get the current button state
  int newButtonState_Autonomous_Manual = digitalRead(SW_Autonomous_Manual);
  // Has the button gone high since the last input?
  if (newButtonState_Autonomous_Manual == HIGH && oldButtonState_Autonomous_Manual == LOW) {
    if (toggle_Autonomous_Manual == false) {
      // Toggle Autonomous on
      toggle_Autonomous_Manual = true;

    } else {
      // Toggle Manual on
      toggle_Autonomous_Manual = false;
    }
  }
  // Store the button's state so we can tell if it has changed
  oldButtonState_Autonomous_Manual = newButtonState_Autonomous_Manual;

  //Manual Mode
  if (toggle_Autonomous_Manual == false) {
    // 0 to HalfSpeed
    if (toggle == false) {
      int newVal = getDataFalse();
      if (newVal != oldVal) {
        bt.println(newVal);
      }
      oldVal = newVal;
    } else { // HalfSpeed to FullSpeed
      int newVal = getDataTrue();
      if (newVal != oldVal) {
        bt.println(newVal);
      }
      oldVal = newVal;
    }
  } else { //Autonomous Mode
    int newVal = 50; // Send command 50 for Autonomous Mode
    if (newVal != oldVal) {
      bt.println(newVal);
    }
    oldVal = newVal;
  }

}

//Mapping Joystick for 0 to half speed
int getDataFalse() {
  //Mapping to an easier to read range
  int xPos = analogRead(xPin);
  int yPos = analogRead(yPin);
  xPos = map(xPos, 0, 1023, 0, 7);
  yPos = map(yPos, 0, 1023, 0, 7);
  if (xPos == 3 && yPos == 3) {
    return 1;
  } else if (xPos == 3 && yPos < 3 && yPos != 0) {
    return 2;
  } else if (xPos == 3 && yPos == 0) {
    return 3;
  } else if (xPos == 3 && yPos > 3 && yPos < 6) {
    return 4;
  } else if (xPos == 3 && yPos >= 6) {
    return 5;
  } else if (xPos > 3 && xPos < 6 && yPos == 3) {
    return 6;
  } else if (xPos >= 6 && yPos == 3) {
    return 7;
  } else if (xPos < 3 && xPos != 0 && yPos == 3) {
    return 8;
  } else if (xPos == 0 && yPos == 3) {
    return 9;
  } else if (xPos > 3 && yPos < 3 && yPos != 0 ) {
    return 10;
  } else if (xPos >= 6 && yPos == 0) {
    return 11;
  } else if (xPos > 3 && xPos < 6 && yPos > 3 && yPos < 6) {
    return 12;
  } else if (xPos >= 6 && yPos >= 6) {
    return 13;
  } else if (xPos < 3 && yPos > 3 && yPos < 6) {
    return 14;
  } else if (xPos == 0 && yPos >= 6) {
    return 15;
  } else if (xPos < 3 && xPos != 0 && yPos < 3 && yPos != 0) {
    return 16;
  } else if (xPos == 0 && yPos == 0) {
    return 17;
  }
}


//Mapping Joystick for half speed to fullspeed
int getDataTrue() {
  //Mapping to an easier to read range
  int xPos = analogRead(xPin);
  int yPos = analogRead(yPin);
  xPos = map(xPos, 0, 1023, 0, 7);
  yPos = map(yPos, 0, 1023, 0, 7);
  if (xPos == 3 && yPos == 3) {
    return 1;
  } else if (xPos == 3 && yPos < 3 && yPos != 0) {
    return 18;
  } else if (xPos == 3 && yPos == 0) {
    return 19;
  } else if (xPos == 3 && yPos > 3 && yPos < 6) {
    return 20;
  } else if (xPos == 3 && yPos >= 6) {
    return 21;
  } else if (xPos > 3 && xPos < 6 && yPos == 3) {
    return 22;
  } else if (xPos >= 6 && yPos == 3) {
    return 23;
  } else if (xPos < 3 && xPos != 0 && yPos == 3) {
    return 24;
  } else if (xPos == 0 && yPos == 3) {
    return 25;
  } else if (xPos > 3 && yPos < 3 && yPos != 0 ) {
    return 26;
  } else if (xPos >= 6 && yPos == 0) {
    return 27;
  } else if (xPos > 3 && xPos < 6 && yPos > 3 && yPos < 6) {
    return 28;
  } else if (xPos >= 6 && yPos >= 6) {
    return 29;
  } else if (xPos < 3 && yPos > 3 && yPos < 6) {
    return 30;
  } else if (xPos == 0 && yPos >= 6) {
    return 31;
  } else if (xPos < 3 && xPos != 0 && yPos < 3 && yPos != 0) {
    return 32;
  } else if (xPos == 0 && yPos == 0) {
    return 33;
  }
}
