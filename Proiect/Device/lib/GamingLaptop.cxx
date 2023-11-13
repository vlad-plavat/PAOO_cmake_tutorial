#include "GamingLaptop.h"
#include <iostream>
#include <cstring>

using namespace Laptop_nmsp;
using namespace GamingLaptop_nmsp;

GamingLaptop::GamingLaptop(int year, char *brand, char *desc, char *GPU): Laptop(year, brand, desc){
	strcpy(this->GPU, GPU);
}


void GamingLaptop::show(){
	Laptop::show();
	std::cout<<"+++GPU: "<<GPU<<std::endl<<std::endl;
}

float GamingLaptop::getPowerConsumption(){
	return isOn?130:0;
}

void GamingLaptop::playGame(char *game){
	std::cout<<"Playing "<<game<<" using "<<GPU<<" GPU."<<std::endl;
}

