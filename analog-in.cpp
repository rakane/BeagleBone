#include "analog-in.h"

ADC::ADC(const int adcNumber)
{
	if(adcNumber > 6 || adcNumber < 0) {
		std::cout << "Error!: ADC pins range from 0-6\n";
		exit(0);
	} else {
		pinNum = adcNumber;
	}
}

int ADC::getRawVoltage() {
	std::string path = "/sys/bus/iio/devices/iio:device0/in_voltage" + std::to_string(pinNum) + "_raw";
	std::ifstream valStream(path, std::ifstream::in);
	std::string value = "";
	value += valStream.get();

	while(valStream.good()) {
		value += valStream.get();
	}	
	
	value += '\0';
	valStream.close();
	return std::atoi(value.c_str());
}

float ADC::getVoltage() {
	std::string path = "/sys/bus/iio/devices/iio:device0/in_voltage" + std::to_string(pinNum) + "_raw";
	std::ifstream valStream(path, std::ifstream::in);
	std::string value = "";
	value += valStream.get();

	while(valStream.good()) {
		value += valStream.get();
	}	
	
	value += '\0';
	valStream.close();

	int integerVal = std::atoi(value.c_str());
	std::cout << std::to_string(integerVal) << "\n";

	return ((float) integerVal / 4096.0) * 1.8;

}
