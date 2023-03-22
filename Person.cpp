#include "Person.h"

Person::Person() {
	Name = "";
	ID = -1;
	Age = -1;
}

Person::Person(int id = -1, int age = -1, std::string name = "") {
	Name = name;
	ID = id;
	Age = age;
}

void Person::SetName(std::string n) { Name = n; }
void Person::SetID(int i) { ID = i; }
void Person::SetAge(int a) { Age = a; }

int Person::GetID() { return ID; }
int Person::GetAge() { return Age; }
std::string Person::GetName() { return Name; }

