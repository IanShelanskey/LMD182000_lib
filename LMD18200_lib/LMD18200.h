#ifndef Lmd18200_h
#define Lmd18200_h


class LMD18200
{
	public:
		LMD18200(int DirectionInput, int SpeedInput, int BrakeInput, int CurrentSensePin, int ThermalFlagPin);
		void setDirection(int Direction);
		void setSpeed(int Speed);
		void setBrake(int State);
		float getCurrent();
		void setTemperatureFlagCallback(void (*TempFlagCallback)());

	private:
		void (*_TempFlagCallback)();
		int _DirectionPin;
		int _SpeedPin;
		int _BrakePin;
		int _CurrentSensePin;
		int _ThermalFlagPin;
};


#endif


/*
Copyright 2017 Ian Shelanskey - ishelanskey@gmail.com

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/