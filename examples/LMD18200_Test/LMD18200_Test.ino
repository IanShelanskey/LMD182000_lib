#include "LMD18200.h"


//Set these pins to the correct input pins for teensy. 
int Direction_pin 		= 9;
int Speed_pin 			= 16;
int Brake_pin 			= 20;
int CurrentSense_pin 	= 14;
int TempFlag_pin 		= 17;

//Create a motor controller object. 
LMD18200 MotorController = LMD18200(Direction_pin, Speed_pin, Brake_pin, CurrentSense_pin, TempFlag_pin);

void setup()
{
	Serial.begin(115200);
	Serial.println("____Starting Program____");
}

void loop()
{
	//Go up for 2 secs
	MotorController.setDirection(1);
	MotorController.setSpeed(100);
	delay(2000);
	
	//Switch Direction, keep speed.
	MotorController.setDirection(0);
	delay(2000);
	
	//Go faster.
	MotorController.setSpeed(255);
	delay(2000);
	
	//Stop motor. 
	MotorController.setSpeed(0);
	delay(2000);
}
