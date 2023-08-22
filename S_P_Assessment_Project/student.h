#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <string>
#include <iostream>
#include "degree.h"
using namespace std;

class Student
{
   public:
	   // Default Constructor
	   Student();

	   // Public Functions
	   void print();

	   // Public Mutators
	   void SetID(string id);
	   void SetFirstName(string firstName);
	   void SetLastName(string lastName);
	   void SetEmail(string email);
	   void SetAge(int age);
	   void SetDaysInCourses(int daysInCoursesToSet[]);
	   void SetDegreeProgram(DegreeProgram degreeProgram);

	   // Public Accessors
	   string GetID() const;
	   string GetFirstName() const;
	   string GetLastName() const;
	   string GetEmail() const;
	   int GetAge() const;
	   int* GetDaysInCourses();
	   DegreeProgram GetDegreeProgram() const;	   

   private:
	   string id;
	   string firstName;
	   string lastName;
	   string email;
	   int age;
	   int daysInCourses[3];
	   DegreeProgram degreeProgram;
};

#endif



