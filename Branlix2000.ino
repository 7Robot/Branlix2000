#include <Servo.h> 

// White LED
int ledW=5;
// Red LED (Left)
int ledR=2;
// Green LED (Right)
int ledG=7;

// Left button
int buttonL=10;
// Right button
int buttonR=4;

// Old button states for rising edge detection
buttonL_old=0;
buttonR_old=0;


// Speaker
int speaker=3;

// Servo declaration
Servo servo;
// Init arrow in center position
int arrowPos = 87;

void setup() {
	// Pin affectation
	servo.attach(9);

	// LED pins declarations
	pinMode(ledG, OUTPUT);
	pinMode(ledR, OUTPUT);
	pinMode(ledW, OUTPUT);

	digitalWrite(ledW, HIGH);
	digitalWrite(ledG, HIGH);
	digitalWrite(ledR, HIGH);
}

void loop() {

	servo.write(arrowPos); 

	/*
  // Left button rising edge
  if (buttonL && buttonL_old==0){

  }
  // Right button rising edge
  if(buttonR && buttonR_old==0){

  }
    */
}
