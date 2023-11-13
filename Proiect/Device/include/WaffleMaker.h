#pragma once
#include <string>
#include "Device.h"

namespace WaffleMaker_nmsp{

class WaffleMaker: public Device_nmsp::Device{
	
	int numberOfWaffles;
	int isOn;
	
public:
	WaffleMaker();
	void show() override;
	void turnOn() override;
	void turnOff() override;
	float getPowerConsumption() override;
};

}
