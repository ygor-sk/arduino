// code:   https://www.youtube.com/watch?v=CEz1EeDlpbs
// wiring: https://create.arduino.cc/projecthub/debanshudas23/getting-started-with-stepper-motor-28byj-48-3de8c9

#include <Stepper.h>

int stepsPerRevolution = 2048;
int motorSpeed = 10;


int VRx = A1;
int VRy = A0;
int SW = 8;

int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

Stepper myStepper(stepsPerRevolution, 5, 3, 4, 2);


void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(motorSpeed);

  // set up joystick
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 
}

void loop() {
//  myStepper.step(256);
//  delay(500);


  // read joystick input
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  mapX = map(xPosition, 0, 1023, 512, -512);
  mapY = map(yPosition, 0, 1023, 512, -512);
  
  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.print(mapY);
  Serial.print(" | Button: ");
  Serial.println(SW_state);

  if (abs(mapX) > 50) {
    myStepper.step(-mapX / 32);
    Serial.println("moving x");
    
  } else {
    delay(100); 
  }

 
}
