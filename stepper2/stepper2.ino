// code:   https://www.youtube.com/watch?v=CEz1EeDlpbs
// wiring: https://create.arduino.cc/projecthub/debanshudas23/getting-started-with-stepper-motor-28byj-48-3de8c9

#include <Stepper.h>

int stepsPerRevolution = 2048;
int motorSpeed = 10;

Stepper myStepper(stepsPerRevolution, 5, 3, 4, 2);


void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(motorSpeed);
}

void loop() {
  myStepper.step(256);
  delay(500);
  myStepper.step(256);
  delay(500);
  myStepper.step(256);
  delay(500);
  myStepper.step(-256);
  delay(500);
  myStepper.step(-256);
  delay(500);
  myStepper.step(-256);
  delay(500);
}
