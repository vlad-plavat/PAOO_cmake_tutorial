#pragma once
#include <string>
#include "Device.h"

namespace Laptop_nmsp{

class Laptop: public Device_nmsp::Device{
	
	typedef struct Service{
		char date[100];
		char type[100];
		Service *prev;
	}Service;

	int year;
	char brand[100];
	char *description;
	Service *service_events;
	
protected:
	int isOn;

public:
	Laptop(int year, char *brand, char *desc);
	~Laptop();
	Laptop(const Laptop &oldLaptop);
	Laptop(Laptop &&oldLaptop);
	void changeYear(int newYear);
	void addService(char *date, char *type);
	void solveService();
	
	Laptop& operator=(const Laptop &oldLaptop);
	Laptop& operator=(Laptop &&oldLaptop);
	
	
	virtual void show() override;
	void turnOn() override;
	void turnOff() override;
	virtual float getPowerConsumption() override;
	
	void playGame(char *game); //play game using integrated GPU
	
};

}
