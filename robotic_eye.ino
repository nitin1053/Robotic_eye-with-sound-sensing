#include <Servo.h>

Servo servoLeft; // servo motor for left eye
Servo servoRight; // servo motor for right eye
int soundSensorLeft = A0; // sound sensor on left
int soundSensorRight = A1; // sound sensor on right

void setup() {
  servoLeft.attach(9); // attach servo to pin 9
  servoRight.attach(10); // attach servo to pin 10
  pinMode(soundSensorLeft, INPUT); // set sound sensor on left as input
  pinMode(soundSensorRight, INPUT); // set sound sensor on right as input
}

void loop() {
  int soundLevelLeft = analogRead(soundSensorLeft); // read sound level on left
  int soundLevelRight = analogRead(soundSensorRight); // read sound level on right

  // if sound is detected on left
  if(soundLevelLeft > 500) {
    // turn left
    servoLeft.write(0); // turn left
    delay(1000); // wait for 1 second
    servoLeft.write(90); // stop
  }

  // if sound is detected on right
  if(soundLevelRight > 500) {
    // turn right
    servoRight.write(180); // turn right
    delay(1000); // wait for 1 second
    servoRight.write(90); // stop
  }
}
