#include <iostream>
#include <string>
#include <vector>
#include "roster.h"
#include "student.h"
#include "degree.h"
using namespace std;

// Constructor
Roster::Roster()
{
	// Init Vars
	studentIndex = 0;

	// Loop to dynamically allocate memory for all new students...
	for (int i = 0; i < 5; i++)
	{
		classRosterArray[i] = new Student;
	}
	return;
}

Roster::~Roster()
{
	// Message
	cout << "Deleting dynamically allocated memory from Roster..." << endl;
	
	// Loop through all active elements of rosterArray and delete them.
	for (int i = 0; i < studentIndex; i++)
	{
		delete classRosterArray[i];
	}
	return;
}

// Add Student Function Definition
void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
	             int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
	             DegreeProgram degreeProgram) {

	// Create a new Student Pointer Object and Allocate Memory for it
	//Student* newStudentPtr = new Student;
	Student * newStudentPtr = classRosterArray[studentIndex];

	// Set Student info
	newStudentPtr->SetID(studentID);
	newStudentPtr->SetFirstName(firstName);
	newStudentPtr->SetLastName(lastName);
	newStudentPtr->SetEmail(emailAddress);
	newStudentPtr->SetAge(age);
	int daysInCourses[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
	newStudentPtr->SetDaysInCourses(daysInCourses);
	newStudentPtr->SetDegreeProgram(degreeProgram);

	// Add this student to the Roster Array
	//classRosterArray[studentIndex] = newStudentPtr;

	// Add to index
	studentIndex += 1;
}

// Remove Student Function
void Roster::remove(string studentID)
{
	// Var
	bool studentFound = false;
	int foundIndex = 0;

	// Find Student with matching ID
	for (int i = 0; i < studentIndex; i++)
	{
		// Var
		string thisID = classRosterArray[i]->GetID();

		// If else
		if (thisID == studentID)
		{
			// Student Was Found
			studentFound = true;

			// Set Index of Found Student
			foundIndex = i;
		}
	}

	// If Student was Not Found, Display Error Mesaage
	if (!studentFound)
	{
		// Print
		cout << "ERROR: This student was not found." << endl << endl;
	}
	else
	{
		// Delete Array at Index and Call Destructor
		delete classRosterArray[foundIndex];
		
		// Now Loop to Move other array elements forward
		for (int i = foundIndex; i < studentIndex - 1; i++)
		{			
			// Move all the Rest of the element Forward..
			classRosterArray[i] = classRosterArray[i + 1];
		}

		// Subtract from student Index
		studentIndex -= 1;

		// Print
		cout << "Student was removed successfully!" << endl << endl;
	}
}

// Get Student Index
int Roster::GetStudentIndex() const {
	return studentIndex;
}

// Function Defninition to Print INvalid Emails
void Roster::PrintInvalidEmails()
{
	// Vars
	vector<string> invalidEmails;
	vector<string> matchingStudentIDs;

	// Iterate each student table tp find and check each email address
	for (int i = 0; i < studentIndex; i++)
	{
		// Email String
		string thisEmail = classRosterArray[i]->GetEmail();

		// Other Vars
		bool hasAtSign = false;
		bool hasPeriod = false;
		bool hasSpace = false;

		// Determine if this email address is valid (String Iteration)
		for (int j = 0; j < thisEmail.length(); j++)
		{
			// Check for @ symbol
			if (thisEmail.at(j) == '@') { hasAtSign = true; }
			// Has Period
			if (thisEmail.at(j) == '.') { hasPeriod = true; }
			// Has Space
			if (thisEmail.at(j) == ' ')	{ hasSpace = true; }
		}	

		// Expression to determine if this email is Valid...
		if (!hasAtSign || !hasPeriod || hasSpace)
		{
			// Add to invalid email list
			invalidEmails.push_back(thisEmail);

			// Add MAtching Student IDS to other List
			matchingStudentIDs.push_back(classRosterArray[i]->GetID());
		}
	}

	// Print out This invalid Email List
	cout << "************************************************" << endl;
	cout << "***         Invalid Email Addresses          ***" << endl;
	cout << "************************************************" << endl << endl;
	for (int i = 0; i < invalidEmails.size(); i++)
	{
		cout << invalidEmails.at(i) << " (ID: " << matchingStudentIDs.at(i) << ")" << endl;
	}
}

// Function to get the Class Roster Array
Student** Roster::GetClassRosterArray()
{
	// Returning a Pointer to an Array of Pointers
	return classRosterArray;
}

// Functiong to Get Student Object by ID
Student Roster::GetStudentByID(string studentID) const
{
	// Vars
	Student thisStudent;

	// Search thruoght Class Roster
	for (int i = 0; i < studentIndex; i++)
	{
		// If
		if (classRosterArray[i]->GetID() == studentID)
		{
			// This student
			thisStudent = *classRosterArray[i];
		}
	}

	// Return
	return thisStudent;
}

// Functiong thats Prints the Average Days in Course
void Roster::printAverageDaysInCourse(string studentID)
{
	// Days Average
	Student thisStudent;
	int daysAverage = 0;
	int* thisDaysInCourses;

	// Define this Student
	thisStudent = GetStudentByID(studentID);

	// Set Days in Courses
	thisDaysInCourses = thisStudent.GetDaysInCourses();

	// Loop to Get Avaergae
	for (int i = 0; i < 3; i++)
	{
		// Add t Days Average
		daysAverage += thisDaysInCourses[i];
	}

	// Set Average
	daysAverage /= 3;

	// Print it
	cout << "Average Days in Course: " << daysAverage;
}

// Function to Print Student Data Based on DegreeProgram
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	// Make a List of Students by DegreeProgram
	vector<Student> studentsByDegree;
	string degreeText;

	// Set the Degree Program Text to Display
	if (degreeProgram == 0) { degreeText = "Security"; }
	else if (degreeProgram == 1) { degreeText = "Network"; }
	else { degreeText = "Software"; }

	// Now Print the List of Students
	cout << endl << endl;
	cout << "************************************************" << endl;
	cout << "**   Students part of the " << degreeText << " program  ***" << endl;
	cout << "************************************************" << endl << endl;

	// Loop To fill the List
	for (int i = 0; i < studentIndex; i++)
	{
		// this students Degree
		DegreeProgram thisDegree = classRosterArray[i]->GetDegreeProgram();

		// Check it
		if (thisDegree == degreeProgram)
		{
			// Add to the List
			//studentsByDegree.push_back(classRosterArray.at(i));
			classRosterArray[i]->print();
		}
	}
}

// Print All Student Roster Information
void Roster::printAll() {

	// define Class Roster Array size
	int rosterSize = studentIndex;	

	// Print Stuff
	cout << "************************************************" << endl;
	cout << "***           Full Student Roster            ***" << endl;
	cout << "************************************************" << endl << endl;
	
	// Print for Every student in Student Array
	for (int i = 0; i < rosterSize; i++)
	{		
		// Call print from each Student
		classRosterArray[i]->print();		
	}
}
