#include "Arduino.h"
#include "LMD18200.h"

LMD18200::LMD18200(int DirectionPin, int SpeedPin, int BrakePin, int CurrentSensePin, int ThermalFlagPin)
{	
   /* Constructor for interfacing with the LMD18200 chip. 
	*
	* Args:
	*	DirectionPin 		Pin3 on the LMD18200 unit.
	*	SpeedPin 			Pin5 on the LMD18200 unit.
	*	BrakePin 			Pin4 on the LMD18200 unit.
	*	CurrentSensePin 	Pin8 on the LMD18200 unit.
	*	ThermalFlagPin 		Pin9 on the LMD18200 unit.
	*
	* Returns:
	* 	LMD18200 Object initiated to be used in setting speed, direction, brake.
	*/

	//Set pins for chip.
	_DirectionPin = DirectionPin;
	_SpeedPin = SpeedPin;
	_BrakePin = BrakePin;
	_CurrentSensePin = CurrentSensePin;
	_ThermalFlagPin = ThermalFlagPin;

	//Set pinmodes.
	pinMode(_DirectionPin, OUTPUT);
	pinMode(_SpeedPin, OUTPUT);
	pinMode(_BrakePin, OUTPUT);
	pinMode(_CurrentSensePin, INPUT);
	
	//Set thermal flag high and switch to input.
	pinMode(_ThermalFlagPin, OUTPUT);
	digitalWrite(_ThermalFlagPin, HIGH);
	pinMode(_ThermalFlagPin, INPUT);

}


void LMD18200::setDirection(int Direction)
{
   /* Method for setting direction of LMD18200 chip.
	*
	* Args:
	*	Direction 		HIGH or LOW on this argument will change the direction.
	*/

	digitalWrite(_DirectionPin, Direction);
}


void LMD18200::setSpeed(int Speed)
{
   /* Method for setting speed of LMD18200 chip.
	*
	* Args:
	*	Direction 		(0-255) on this argument will modulate the speed.
	*/
	analogWrite(_SpeedPin, Speed);
}


void LMD18200::setBrake(int State)
{
   /* Method for setting brake of LMD18200 chip.
	*
	* Args:
	*	Direction 		HIGH or LOW on this argument will engage/disengage the Brake.
	*/
	digitalWrite(_BrakePin, State);
}


float LMD18200::getCurrent()
{
   /* Method for getting current draw of LMD18200 chip.
	*
	* Returns:
	* 	float corresponding to the current draw of chip.
	*/
	return analogRead(_CurrentSensePin);
}


void LMD18200::setTemperatureFlagCallback(void (*TempFlagCallback)())
{
   /* Method for setting callback on temperature warning of LMD18200 chip
	*
	* Args:
	*	TempFlagCallback 	Callback to a method to handle a temperature warning.
	*
	* This method will create an ISR to the callback passed into it. 
	*/
	_TempFlagCallback = TempFlagCallback;
	attachInterrupt(digitalPinToInterrupt(_ThermalFlagPin), _TempFlagCallback, FALLING);
}

/*
Copyright 2017 Ian Shelanskey - ishelanskey@gmail.com

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/