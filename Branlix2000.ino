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

long unsigned int oldmillis1=0;
long unsigned int oldmillis2=0;

// Old button states for rising edge detection
bool buttonL_old=0;
bool buttonR_old=0;


// Speaker
int spk=3;

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

	// Buttons pin declarations
	pinMode(buttonL,INPUT);
	pinMode(buttonR,INPUT);
}

void loop() {


//////////////////////////////////////////////
servo.write(arrowPos);

	// Left button rising edge
	if (!digitalRead(buttonL) && buttonL_old==1){
		arrowPos++;
		digitalWrite(ledR, HIGH);
		oldmillis1=millis();
		tone(spk, 900, 50);
	}
	// Right button rising edge
	if(!digitalRead(buttonR) && buttonR_old==1){
		arrowPos--;
		digitalWrite(ledG, HIGH);
		oldmillis2=millis();
		tone(spk, 700, 50);
	}

	// Tempo de clignotement des leds
	if(millis()-oldmillis1==50)
	digitalWrite(ledR, LOW);
	if(millis()-oldmillis2==50)
	digitalWrite(ledG, LOW);

	// Buttons state reading
	buttonL_old=digitalRead(buttonL);
	buttonR_old=digitalRead(buttonR);
	//////////////////////////////////////////////

	if (arrowPos>111 || arrowPos<65){
		win();
	}

}

void win(){
	delay(2000);
	int i=20;
	while (digitalRead(buttonL)!=0 || digitalRead(buttonR)!=0)
	{
		for(; i<5000; i++)
		tone(spk, i, 50);
		i=20;
	}
	arrowPos=87;
	delay(1000);
	digitalWrite(ledG, LOW);
	digitalWrite(ledR, LOW);
}

