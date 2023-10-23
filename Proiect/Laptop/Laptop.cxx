#include "Laptop.h"
#include <iostream>
#include <cstring>

Laptop::Laptop(int year, std::string brand, std::string desc){
	std::cout<<"I have been created."<<std::endl;
	this->year = year;
	strcpy(this->brand, brand.c_str());
	this->description = new char[desc.size()+1];
	strcpy(this->description, desc.c_str());
	this->service_events = NULL;
}

Laptop::Laptop(const Laptop &oldLaptop){
	std::cout<<"I have been copied."<<std::endl;
	this->year = oldLaptop.year;
	strcpy(this->brand, oldLaptop.brand);
	this->description = new char[strlen(oldLaptop.description)+1];
	strcpy(this->description, oldLaptop.description);
	Laptop::Service *p = oldLaptop.service_events, *np = NULL;
	while(p != NULL){
		Laptop::Service *nserv = new Service;
		strcpy(nserv->date, p->date);
		strcpy(nserv->type, p->type);
		nserv->prev=np;
		np=nserv;
		p = p->prev;
	}
	Laptop::Service *cr=np, *prev=NULL, *nxt=NULL;
	while(cr != NULL){
		nxt = cr->prev;
		cr->prev = prev;
		prev = cr;
		cr = nxt;
	}
	this->service_events = prev;
}

Laptop::~Laptop(){
	std::cout<<"I have been deleted."<<std::endl;
	delete[] this->description;
	Laptop::Service *p = this->service_events, *np = NULL;
	while(p != NULL){
		np = p->prev;
		delete p;
		p = np;
	}
}


Laptop::Laptop(Laptop &&oldLaptop){
	std::cout<<"I have been moved."<<std::endl;
	this->year = oldLaptop.year;
	strcpy(this->brand, oldLaptop.brand);
	this->description = oldLaptop.description;
	this->service_events = oldLaptop.service_events;
	oldLaptop.description = NULL;
	oldLaptop.service_events = NULL;
}

void Laptop::show(){
	if(this->description == NULL){
		std::cout<<"LAPTOP HAS BEEN DELETED!"<<std::endl;
		return;
	}
	std::cout<<this->brand<<std::endl<<"Year: "<<this->year<<std::endl<<this->description<<std::endl;
	Laptop::Service *p = this->service_events;
	while(p != NULL){
		std::cout<<"\t"<<p->date<<"\t"<<p->type<<std::endl;
		p = p->prev;
	}
	std::cout<<std::endl;
}

void Laptop::changeYear(int newYear){
	this->year = newYear;
}

void Laptop::addService(std::string date, std::string type){
	Laptop::Service *p = new Service;
	strcpy(p->date, date.c_str());
	strcpy(p->type, type.c_str());
	p->prev = this->service_events;
	this->service_events = p;
}

void Laptop::solveService(){
	Laptop::Service *p = this->service_events;
	while(p != NULL){
		strcat(p->type, " - SOLVED");
		p = p->prev;
	}
}
