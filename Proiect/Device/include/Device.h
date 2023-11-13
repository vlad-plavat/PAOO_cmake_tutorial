#pragma once
#include <string>

namespace Device_nmsp{

class Device{

public:
	virtual void turnOn() = 0;
	virtual void turnOff() = 0;
	virtual float getPowerConsumption() = 0;
	virtual void show() = 0;
};

}
