#include <string>
#include <vector>
#include "student.h"
#include "degree.h"
using namespace std;

// Define Constructor
Student::Student()
{
	id = "";
	firstName = "";
	lastName = "";
	email = "";
	age = -1;
	daysInCourses[0] = 0;
	daysInCourses[1] = 0;
	daysInCourses[2] = 0;
	degreeProgram = SECURITY;
	return;
}

// Define Public Functions
void Student::print() {

	// Other Vars
	char charTab = '\t';

	// Print all Specific Student Data
	cout << charTab << "ID: " << id << charTab;
	cout << "First Name: " << firstName << charTab;
	cout << "Last Name: " << lastName << charTab;
	//cout << "Email: " << classRosterArray[i].GetEmail() << endl;
	cout << "Age: " << age << charTab << charTab;
	cout << "Days In Courses: { ";
	// For Loop to Print out Days in Courses
	for (int j = 0; j < 3; j++)
	{
		// Print Days in Course Number
		cout << daysInCourses[j];
		// If its NOT the last iteration, print Print a comma
		if (!(j == 2))
		{
			cout << ", ";
		}
		else
		{
			cout << " } ";
		}
	}
	cout << charTab;
	// switch Loop to Print out Enum as text
	switch (degreeProgram)
	{
	case 0:
		cout << "Degree Program: Security" << endl << endl;
		break;
	case 1:
		cout << "Degree Program: Network" << endl << endl;
		break;
	case 2:
		cout << "Degree Program: Software" << endl << endl;
		break;
	default:
		cout << "Degree Program: SECURITY" << endl << endl;
		break;
	}
}

// Define Setter Functions
void Student::SetID(string id) {
	this->id = id;
	return;
}
void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
	return;
}
void Student::SetLastName(string lastName) {
	this->lastName = lastName;
	return;
}
void Student::SetEmail(string email) {
	this->email = email;
	return;
}
void Student::SetAge(int age) {
	this->age = age;
	return;
}
void Student::SetDaysInCourses(int daysInCoursesToSet[]) {
	// Loop to add all elements to Days In Courses private student variable
	for (int i = 0; i < 3; i++)
	{
		daysInCourses[i] = daysInCoursesToSet[i];
	}
	return;
}
void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
	return;
}

// Define Getting Functions
string Student::GetID() const {
	return id;
}
string Student::GetFirstName() const {
	return firstName;
}
string Student::GetLastName() const {
	return lastName;
}
string Student::GetEmail() const {
	return email;
}
int Student::GetAge() const {
	return age;
}
int* Student::GetDaysInCourses() {
	return daysInCourses;
}
DegreeProgram Student::GetDegreeProgram() const {
	return degreeProgram;
}
