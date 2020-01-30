#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

#ifndef Gpio_H
#define Gpio_H

class Gpio {
	public:
		Gpio(const int pinNumber, std::string initialDir, int initialVal);
	    Gpio(const int pinNumber, std::string initialDir);
		int getValue();
		std::string getDirection();
		void setValue(int newVal);
		void setDirection(std::string newDir);
	private:
		int pinNum;
    	std::string direction;
		int value;
};

#endif
