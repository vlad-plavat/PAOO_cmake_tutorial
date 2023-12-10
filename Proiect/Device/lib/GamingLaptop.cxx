#include "GamingLaptop.h"
#include <iostream>
#include <cstring>
#include <pthread.h>
#include <unistd.h>
#include <cstdlib>
#include <mutex>

using namespace Laptop_nmsp;
using namespace GamingLaptop_nmsp;

char GamingLaptop::savedFile[20][100]={0,0};

std::mutex fileMutex;

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

void GamingLaptop::printSaveFile(){
	for(int nrline=0; nrline<20; nrline++){
		if(savedFile[nrline][0] != '\0'){
			std::cout<<savedFile[nrline]<<std::endl;
		}
	}
}

void* GamingLaptop::threadTask(void *game){
	
	fileMutex.lock();

	for(int i=0; i<10; i++){
		usleep(rand()%10000);
		for(int nrline=0; nrline<20; nrline++){
			if(savedFile[nrline][0] == '\0'){
				sprintf(savedFile[nrline], "%s: Line %d of %s save file.", (char*)game, i, (char*)game);
				break;
			}
		}
	}
	
	fileMutex.unlock();
	
	return NULL;
}

void GamingLaptop::saveGame(char *game){
	pthread_t t;
	pthread_create(&t, NULL, threadTask, game);
	pthread_detach(t);
}

