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