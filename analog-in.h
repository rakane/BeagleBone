#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

#ifndef ADC_H
#define ADC_H

class ADC {
	public:
		ADC(const int adcNum);
		int getRawVoltage();
		float getVoltage();
	private:
		int pinNum;
};

#endif

