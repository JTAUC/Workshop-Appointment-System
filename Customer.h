#include "Header.h"
#include "Person.h"
#include "Mechanic.h"
#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer : public Person {
private:
	int MechanicID;
	string MechanicName;
	Appointment appointment;
	bool noAppointment;
public:

	Customer();

	void SetMechanicID(int i); //Set the assigned mechanic's ID

	void SetMechanicName(std::string name); //Set the assigned mechanic's Name

	void SetAppointment(int h, int m); //Overloaded method to set an appointment for this customer using individual hour and minutes

	void SetAppointment(Appointment a); //Overloaded method to set an appointment for this customer using an appointment object

	void SetAppointmentStatus(bool b); //Set if a customer has an appointment or not

	int GetMechanicID(); //Get the assigned mechanic's ID

	std::string GetMechanicName(); //Get the assigned mechanic's Name

	Appointment GetAppointment(); //Get this customer's scheduled appointment

	bool GetAppointmentStatus(); //Check if customer has an appointment

	void printInfo();

	bool operator < (Customer a); //Overloaded < operator to compare customer appointment's time

	bool operator > (Customer a); //Overloaded > operator to compare customer appointment's time

	bool operator == (Customer a); //Overloaded == operator to compare customer appointment's time
};
#endif