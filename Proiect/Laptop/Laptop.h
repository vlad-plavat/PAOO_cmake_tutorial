#pragma once
#include <string>

class Laptop{
	
	typedef struct Service{
		char date[100];
		char type[100];
		Service *prev;
	}Service;

	int year;
	char brand[100];
	char *description;
	Service *service_events;

public:
	Laptop(int year, std::string brand, std::string desc);
	~Laptop();
	Laptop(const Laptop &oldLaptop);
	Laptop(Laptop &&oldLaptop);
	void show();
	void changeYear(int newYear);
	void addService(std::string date, std::string type);
	void solveService();
};
