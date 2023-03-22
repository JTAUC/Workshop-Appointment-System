#include "Mechanic.h"

void Mechanic::SetNoOfAppointments(int n) { NoOfAppointments = n; }

int Mechanic::GetNoOfAppointments() { return NoOfAppointments; }

bool Mechanic::isAvailable(int hour, int minute) {
	if (NoOfAppointments == 0) { return 1; }

	for (int i = 0; i < NoOfAppointments; i++) {
		if ((BookedTimes[i].hours == hour) && (BookedTimes[i].minutes == minute))
			return 0;
	}
	return 1;
}

Mechanic::Mechanic() {
	NoOfAppointments = 0;
}

Mechanic::~Mechanic() {
	delete[] BookedTimes;
}

void Mechanic::Init_Appointments(int n) {
	BookedTimes = new Appointment[n];
}

void Mechanic::Increment_Appointments() {
	Appointment* resize = new Appointment[NoOfAppointments + 1];
	for (int i = 0; i < NoOfAppointments; i++) {
		resize[i] = BookedTimes[i]; //Copy old data members into new dynamic array
	}
	NoOfAppointments++;
	
	BookedTimes = resize;
}

void Mechanic::printInfo() {
	cout << "ID: " << GetID() << endl;
	cout << "Name: " << GetName() << endl;
	cout << "Age: " << GetAge() << endl;
	cout << "No. Of Appointments: " << GetNoOfAppointments() << endl;
	cout << "\n";
}

