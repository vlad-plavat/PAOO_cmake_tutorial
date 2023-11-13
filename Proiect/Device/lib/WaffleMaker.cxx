#include "WaffleMaker.h"
#include <iostream>
#include <cstring>

using namespace WaffleMaker_nmsp;

WaffleMaker::WaffleMaker(){
	std::cout<<"A waffle maker has been created."<<std::endl;
	this->isOn = 0;
	this->numberOfWaffles = 0;
}

void WaffleMaker::show(){
	if(isOn){
		std::cout<<"The waffle maker is cooking "<<this->numberOfWaffles<<" waffles."<<std::endl;
	}else{
		std::cout<<"The waffle maker has "<<this->numberOfWaffles<<" waffles inside."<<std::endl;
	}
	

}

void WaffleMaker::turnOn(){
	isOn = 1;
}

void WaffleMaker::turnOff(){
	isOn = 0;
}

float WaffleMaker::getPowerConsumption(){
	return isOn?numberOfWaffles*20:0;
}
