#include "Customer.h"

Customer::Customer() {
	MechanicID = -1;
	MechanicName = "";
	noAppointment = true;
}

void Customer::SetMechanicID(int i) { MechanicID = i; }
void Customer::SetMechanicName(std::string name) { MechanicName = name; }
void Customer::SetAppointment(int h, int m) { appointment.hours = h; appointment.minutes = m; }
void Customer::SetAppointment(Appointment a) { appointment = a; }
void Customer::SetAppointmentStatus(bool b) { noAppointment = b; }

int Customer::GetMechanicID() { return MechanicID; }
std::string Customer::GetMechanicName() { return MechanicName; }
Person::Appointment Customer::GetAppointment() { return appointment; }
bool Customer::GetAppointmentStatus() { return noAppointment; }

bool Customer::operator < (Customer a) { //Returns true if appointment is earlier than given parameter appointment
	if (appointment.hours == a.GetAppointment().hours)
		return (appointment.minutes < a.GetAppointment().minutes ? 1 : 0);

	return (appointment.hours < a.GetAppointment().hours ? 1 : 0);
}

bool Customer::operator > (Customer a) { //Returns true if appointment is later than given parameter appointment
	if (appointment.hours == a.GetAppointment().hours)
		return (appointment.minutes > a.GetAppointment().minutes ? 1 : 0);

	return (appointment.hours > a.GetAppointment().hours ? 1 : 0);
}

bool Customer::operator == (Customer a) {
	return (appointment.hours == a.GetAppointment().hours && appointment.minutes == a.GetAppointment().minutes);
}

void Customer::printInfo() {
	cout << "Name: " << GetName() << endl;
	
	if (!noAppointment) { //Make sure customer has an appointment
		cout << "Mechanic Name: " << GetMechanicName() << endl;
		cout << "Appointment: " << GetAppointment().hours << ":" << GetAppointment().minutes << endl;
	}
	else {
		cout << "No suitable mechanic was available." << endl;
	}
	cout << "\n";
}