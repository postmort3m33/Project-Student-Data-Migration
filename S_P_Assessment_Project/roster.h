#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
#include "degree.h"

class Roster
{
   public:
	   // Constructor
	   Roster();
	   ~Roster();

	   // Functions
	   void add(string studentID, string firstName, string lastName,
		        string emailAddress, int age, int daysInCourse1, 
		        int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	   void remove(string studentID);
	   void PrintInvalidEmails();
	   void printAverageDaysInCourse(string studentID);
	   void printByDegreeProgram(DegreeProgram degreeProgram);
	   void printAll();

	   // Getters
	   Student** GetClassRosterArray();
	   int GetStudentIndex() const;
	   Student GetStudentByID(string studentID) const;

   private:
	   int studentIndex;
	   Student *classRosterArray[5];
};

#endif



