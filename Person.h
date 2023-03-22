#include "Header.h"
#ifndef PERSON_H
#define PERSON_H

class Person {
private:
	int ID;
	int Age;

	string Name;
public:
	struct Appointment {
		int hours;
		int minutes;
	};

	Person();
	Person(int id, int age, std::string name);
		
	void SetID(int i); //Set Person ID
	void SetAge(int a); //Set Person Age
	void SetName(std::string n); //Set Person Name

	int GetID(); //Returns Person ID
	int GetAge(); //Returns Person Age
	std::string GetName(); //Returns Person Name

	virtual void printInfo() = 0; //Displays all needed info of Person
};
#endif
