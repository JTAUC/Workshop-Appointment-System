#include "Header.h"
#include "Mechanic.h"
#include "Customer.h"
#include "Queue.h"
#include <fstream>
#include <string>

string currentLine_mechanics, currentLine_customers;
int no_of_mechanics, no_of_customers;
fstream file;
fstream file2;
Mechanic* mechanics;
Customer* customers;
int j = 0;

template <class T>
void swap_(T& a, T& b) { //Simple template swap function to swap two elements
	T temp = a;
	a = b;
	b = temp;
}

void Init_MechanicsArray() {
	for (int i = 0; i < no_of_mechanics; i++) { //Initializing Dynamic Array of Mechanics
		int no_of_appointments = 0;
		file >> currentLine_mechanics;
		mechanics[i].SetName(currentLine_mechanics);
		file >> currentLine_mechanics;
		mechanics[i].SetAge(stoi(currentLine_mechanics));
		file >> currentLine_mechanics;
		mechanics[i].SetID(stoi(currentLine_mechanics));
		file >> currentLine_mechanics;
		mechanics[i].SetNoOfAppointments(stoi(currentLine_mechanics));
		no_of_appointments = mechanics[i].GetNoOfAppointments();

		if (no_of_appointments > 0)
			mechanics[i].Init_Appointments(no_of_appointments);

		for (int j = 0; j < no_of_appointments; j++) {
			file >> currentLine_mechanics;
			mechanics[i].BookedTimes[j].hours = stoi(currentLine_mechanics);
			file >> currentLine_mechanics;
			mechanics[i].BookedTimes[j].minutes = stoi(currentLine_mechanics);
			//cout << "H: " << mechanics[i].BookedTimes[j].hours << ":" << mechanics[i].BookedTimes[j].minutes << endl;
		}
	}
}

bool AssignAvailableMechanic(int hour, int minute, int i) { //Function used to determine an available mechanic for the customer
	if (j >= no_of_mechanics)
		j = 0;

	while (!mechanics[j].isAvailable(hour, minute)) { //Check if the mechanic is available
		j++;
		if (j >= no_of_mechanics) { return 0; }
	}
	
	mechanics[j].Increment_Appointments();
	int n = mechanics[j].GetNoOfAppointments();
	mechanics[j].BookedTimes[n - 1].hours = hour;
	mechanics[j].BookedTimes[n - 1].minutes = minute;
	customers[i].SetAppointment(hour, minute);
	customers[i].SetMechanicID(mechanics[j].GetID());
	customers[i].SetMechanicName(mechanics[j].GetName());
	j++;
	return 1;
}

void Init_CustomerArray() {
	for (int i = 0; i < no_of_customers; i++) { //Initializing Dynamic Array of Customers
		file2 >> currentLine_customers;
		customers[i].SetName(currentLine_customers);
		file2 >> currentLine_customers;
		int hour = stoi(currentLine_customers);
		file2 >> currentLine_customers;
		int minute = stoi(currentLine_customers);

		if (AssignAvailableMechanic(hour, minute, i)) {
			customers[i].SetAppointmentStatus(0);
		}
	}
}

void SortCustomerArray(const Customer* unsorted, Customer* sorted, int size) {
	int i, j;

	for (int i = 0; i < size; i++)
		sorted[i] = unsorted[i];

	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1 - i; j++) {
			if (sorted[j] > sorted[j + 1]) {
				swap_<Customer>(sorted[j], sorted[j + 1]);
			}
		}
	}
}

void OutputResults(Queue<Customer> q) {
	for (int i = 0; i < no_of_customers; i++) {
		Customer c = q.pop();

		cout << "CUSTOMER INFO:" << endl;
		c.printInfo();
		cout << "MECHANIC INFO:" << endl;
		for (int i = 0; i < no_of_mechanics; i++) { //This segment finds the mechanic object assigned to our customer using IDs
													//A more effecient way of doing this is keeping a mechanic reference object in our customer class
			if (mechanics[i].GetID() == c.GetMechanicID()) {
				mechanics[i].printInfo();
			}
		}
	}
}

void EnqueueCustomers() {
	Queue<Customer> customerQueue(no_of_customers); //Construct new Queue of type Customer
	Customer* sortedCustomers = new Customer[no_of_customers]; //Create new dynamic array to store the sorted customers by appointment time
	SortCustomerArray(customers, sortedCustomers, no_of_customers); //Sort the customer array

	for (int i = 0; i < no_of_customers; i++) {
		customerQueue.push(sortedCustomers[i]); //Push each customer into the queue
	}

	OutputResults(customerQueue); //Output the results in order

	delete[] sortedCustomers;
}

int main() {
	
	file.open("mechanics.txt");
	file2.open("customers.txt");
	getline(file, currentLine_mechanics);
	getline(file2, currentLine_customers);
	no_of_mechanics = stoi(currentLine_mechanics); //Convert the number of mechanics and customers to int so we can use it for mathematical operations in the future
	no_of_customers = stoi(currentLine_customers);

	mechanics = new Mechanic[no_of_mechanics];
	customers = new Customer[no_of_customers];

	Init_MechanicsArray(); //Initialize both the mechanics and customer arrays
	Init_CustomerArray();
	EnqueueCustomers(); //Start the sorted Queue process

	delete [] mechanics;
	delete [] customers;
}