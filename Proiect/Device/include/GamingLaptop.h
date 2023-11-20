#pragma once
#include <string>
#include "Laptop.h"

namespace GamingLaptop_nmsp{

class GamingLaptop: public Laptop_nmsp::Laptop{
	
	char GPU[100];
	char savedData[1000];
	static void* threadTask(void *game);
	
public:
	GamingLaptop(int year, char *brand, char *desc, char *GPU);
	void printGPU();
	void show() override;
	float getPowerConsumption() override;
	void playGame(char *game);	//play game using dedicated GPU
	void saveGame(char *game);
};

}
