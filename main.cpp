#include <iostream>
#include <unistd.h>
#include "gpio.h"
#include "analog-in.h"

int main()
{
		std::cout << "Setting up IO pins...\n";
		Gpio gpio1(115, "out", 1);
		Gpio gpio2(117, "in");
		ADC adc0(0);	
}
