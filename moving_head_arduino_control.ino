#include <MultiStepper.h>
#include <AccelStepper.h>

const int tiltArmLeftPulsePin = 2;
const int tiltArmLeftDirPin = 3;
const int tiltArmLeftEnablePin = 4;

const int tiltArmRightPulsePin = 6;
const int tiltArmRightDirPin = 7;
const int tiltArmRightEnablePin = 8;

const int panPulsePin = 10;
const int panDirPin = 11;
const int panEnablePin = 12;

const int maxSpeed = 5000;
const int speed = 5000;
const int accel = 200;

AccelStepper tiltArmLeft(AccelStepper::DRIVER, tiltArmLeftPulsePin, tiltArmLeftDirPin);
AccelStepper tiltArmRight(AccelStepper::DRIVER, tiltArmRightPulsePin, tiltArmRightDirPin);
AccelStepper panStepper(AccelStepper::DRIVER, panPulsePin, panDirPin);
MultiStepper bothTiltSteppers();

void setup() {

  panStepper.setEnablePin(panEnablePin);
  panStepper.setMaxSpeed(100);
  panStepper.setSpeed(100);
  panStepper.setAcceleration(50);

  tiltArmLeft.setEnablePin(tiltArmLeftEnablePin);
  tiltArmRight.setEnablePin(tiltArmRightEnablePin);
  tiltArmLeft.setMaxSpeed(maxSpeed);
  tiltArmRight.setMaxSpeed(maxSpeed);
  tiltArmLeft.setSpeed(speed);
  tiltArmRight.setSpeed(speed);
  tiltArmLeft.setAcceleration(accel);
  tiltArmRight.setAcceleration(accel);

  tiltArmLeft.moveTo(300);
  tiltArmRight.moveTo(300);
  panStepper.moveTo(300);

}

void loop() {

  //tiltArmLeft.run();
  //tiltArmRight.run();
  //panStepper.run();
  if (tiltArmLeft.distanceToGo() == 0) { tiltArmLeft.stop(); tiltArmLeft.moveTo(-tiltArmLeft.targetPosition()); }
  if (tiltArmRight.distanceToGo() == 0) { tiltArmRight.stop(); tiltArmRight.moveTo(-tiltArmRight.targetPosition()); }
  if (panStepper.distanceToGo() == 0) { panStepper.stop(); panStepper.moveTo(-panStepper.targetPosition()); }
}
