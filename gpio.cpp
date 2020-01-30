#include "gpio.h"

Gpio::Gpio(const int pinNumber, std::string initialDir, int initialVal)
{
	pinNum = pinNumber;

	if(initialDir.compare("in") != 0 && initialDir.compare("out") != 0) {
		std::cout << "Error!: Invalid initial direction\n";
		exit(0);	
	} else {
		direction = initialDir;
	}
		
	if(direction.compare("in") == 0) {
		std::cout << "Error!: Cannot set initial value on a pin direction of 'in'\n";
		exit(0);
	} else {
		if(initialVal != 0 && initialVal != 1) {
			std::cout << "Error!: Value must be set to 0 or 1\n";
		} else {
			value = initialVal;
		}
	}
				
	// Setup pin on board
	std::ofstream dirStream;
	try {
		std::string path = "/sys/class/gpio/gpio" + std::to_string(pinNum) +  "/direction";
		dirStream.open(path);
		dirStream << direction; 
		dirStream.close();
	} catch(int e) {
		std::cout << "Error! Failed to write to direction file\n";
		exit(0);
	}
	
	if(direction.compare("out") == 0) {
		try {
			std::string path = "/sys/class/gpio/gpio" + std::to_string(pinNum) +  "/value";
			std::ofstream valStream;
			valStream.open(path);
			valStream << value;
			valStream.close();
		} catch(int e) {
			std::cout << "Error! Failed to write to direction file\n";
			exit(0);
		}
	} else {
		std::cout << "Error! Cannot set value of pin direction 'in'\n";
		exit(0);
	}
}

Gpio::Gpio(const int pinNumber, std::string initialDir) {
	pinNum = pinNumber;

	if(initialDir.compare("in") != 0 && initialDir.compare("out") != 0)
	{
		std::cout << "Error!: Invalid initial direction\n";
		exit(0);	
	} else
	{
		direction = initialDir;
	}
	// Setup pin on board
	try {
		std::string path = "/sys/class/gpio/gpio" + std::to_string(pinNum) + "/direction";
		std::ofstream dirStream;
		dirStream.open(path);
		dirStream << direction; 
		dirStream.close();
	} catch(int e) {
		std::cout << "Error! Failed to write to direction file\n";
		exit(0);
	}	
}

int Gpio::getValue() {
	return value;
}

std::string Gpio::getDirection() {
	return direction;
}

void Gpio::setValue(int newVal) {
	if(newVal != 0 && newVal != 1) {
			std::cout << "Error!: Value must be set to 0 or 1\n";
	} else {
		value = newVal;
	}

	if(direction.compare("out") == 0) {
		try {
			std::string path = "/sys/class/gpio/gpio" + std::to_string(pinNum) +  "/value";
			std::ofstream valStream;
			valStream.open(path);
			valStream << value;
			valStream.close();
		} catch(int e) {
			std::cout << "Error! Failed to write to direction file\n";
			exit(0);
		}
	} else {
		std::cout << "Error! Cannot set value of pin direction 'in'\n";
		exit(0);
	}


}

void Gpio::setDirection(std::string newDir) {	
	if(newDir.compare("in") != 0 && newDir.compare("out") != 0) {
		std::cout << "Error!: Invalid initial direction\n";
		exit(0);	
	} else {
		direction = newDir;
	}

	std::ofstream dirStream;
	try {
		std::string path = "/sys/class/gpio/gpio" + std::to_string(pinNum) +  "/direction";
		dirStream.open(path);
		dirStream << direction; 
		dirStream.close();
	} catch(int e) {
		std::cout << "Error! Failed to write to direction file\n";
		exit(0);
	}
}
