#include "Person.h"
#ifndef MECHANIC_H
#define MECHANIC_H

class Mechanic : public Person {
private:
	int NoOfAppointments;
public:
	Mechanic();
	~Mechanic();

	Appointment* BookedTimes;
	void Init_Appointments(int n); //Initializes the BookedTimes dynamic array with the number of appointments this mechanic already has

	void Increment_Appointments(); //Increments the number of appointments this mechanic has

	void SetNoOfAppointments(int n); //Sets the number of appointments this mechanic has

	int GetNoOfAppointments(); //Returns the number of appointments this mechanic has

	bool isAvailable(int hour, int minute); //Check if the mechanic is available

	void printInfo();
};
#endif
