#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
#include "roster.h"
#include "degree.h"
using namespace std;

// Extracting String Data from Comma Seperated String
string ExtractStringData(string inputStream, int entryNum)
{
    // Vars
    int charCount = 0;
    int commaCount = 0;
    int entryStringPos = 0;
    int lastEntryCharCount = 0;

    // Find out how many chars until the first comma..
    for (int i = 0; i < inputStream.size(); i++)
    {
        // Add to Char Count for every loop
        charCount++;

        // Find first Comma
        if (inputStream.at(i) == ',')
        {
            // Up Comma Count
            commaCount++;

            // Set Last Character Entra Count (minus the comma)
            lastEntryCharCount = charCount - 1;            

            // Reset Char Count for next iteration
            charCount = 0;
        }

        // This is the ID so only one comma count
        if (commaCount == entryNum) {

            // Record the comma Position
            entryStringPos = i;

            // Break Loop
            break;
        }
    }

    // Create new Substring and return
    int stringStartPos = entryStringPos - lastEntryCharCount;
    return inputStream.substr(stringStartPos, lastEntryCharCount);
}

// Extracting Int Data from Comma Seperated String
int ExtractIntData(string inputStream, int entryNum)
{
    // Vars
    int charCount = 0;
    int commaCount = 0;
    int entryStringPos = 0;
    int lastEntryCharCount = 0;

    // Find out how many chars until the first comma..
    for (int i = 0; i < inputStream.size(); i++)
    {
        // Add to Char Count for every loop
        charCount++;

        // Find first Comma
        if (inputStream.at(i) == ',')
        {
            // Up Comma Count
            commaCount++;

            // Set Last Character Entra Count
            lastEntryCharCount = charCount - 1;

            // Reset Char Count
            charCount = 0;
        }

        // This is the ID so only one comma count
        if (commaCount == entryNum) {

            // Record the string Position
            entryStringPos = i;

            // Break Loop
            break;
        }
    }

    // Create new Substring and return
    int stringStartPos = entryStringPos - lastEntryCharCount;
    return stoi(inputStream.substr(stringStartPos, lastEntryCharCount));
}

// Extracting DegreeProgram Data from Comma Seperated String
DegreeProgram ExtractDPData(string inputStream)
{
    // Vars
    int charCount = 0;
    int commaCount = 0;
    int entryStringPos = 0;
    int lastEntryCharCount = 0;

    // Find out how many chars until the first comma..
    for (int i = 0; i < inputStream.size(); i++)
    {
        // Find first Comma
        if (inputStream.at(i) == ',')
        {
            // Up Comma Count
            commaCount++;
        }

        // This is the ID so only one comma count
        if (commaCount == 8) {

            // Record the string Position
            entryStringPos = i;

            // Break Loop
            break;
        }
    }

    // Create new Substring and Test for DegreeProgram Enumerators
    string subString = inputStream.substr(entryStringPos + 1);
    DegreeProgram thisProgram;

    // If else Branch
    if (subString == "SECURITY")
    {
        thisProgram = SECURITY;
    }
    else if (subString == "NETWORK")
    {
        thisProgram = NETWORK;
    }
    else if (subString == "SOFTWARE")
    {
        thisProgram = SOFTWARE;
    }
    else
    {
        thisProgram = SECURITY;
    }

    // Return DegreeProgram
    return thisProgram;
}

// Function to Loop Thruogh and Print Average Course Days
void PrintAllAverageCourseDays(Roster& classRoster)
{

    // Loop through Students and Print Average Course Days
    Student** classRosterArray = classRoster.GetClassRosterArray();

    cout << endl << endl;
    cout << "************************************************" << endl;
    cout << "***        Average Days in Courses           ***" << endl;
    cout << "************************************************" << endl << endl;
    // Loop
    for (int i = 0; i < classRoster.GetStudentIndex(); i++)
    {
        // Prinnt Course Average
        cout << "(ID: " << classRosterArray[i]->GetID() << ") ";
        classRoster.printAverageDaysInCourse(classRosterArray[i]->GetID());
        cout << endl;
    }
}

// Main Function
int main()
{
    // Print Out Student Information
    cout << endl << endl;
    cout << setfill('*') << setw(50) << "" << endl;
    cout << "*** Scripting and Programming - Applications ***" << endl;
    cout << "***    Written in C++ by Joshua Touchstone   ***" << endl;
    cout << "***           Student ID:002977973           ***" << endl;
    cout << "************************************************" << endl << endl << endl;

    // Input String
    const string studentData[] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
      "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
      "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
      "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
      "A5,Joshua,Touchstone,jtouch4@wgu.edu,30,14,11,21,SOFTWARE" };

    // String size
    const int DATA_STRING_SIZE = 5;

    // Create a new Roster to Hold All Student Objects
    cout << "Creating new Class Roster..." << endl << endl;
    Roster classRoster;

    // Loop to Create all Student Objects and add them to Roster
    cout << "Parsing Data..." << endl << endl;
    for (int i = 0; i < DATA_STRING_SIZE; i++)
    {
        // Get Inputs from Raw Student Data Stream
        string studentID = ExtractStringData(studentData[i], 1);
        string firstName = ExtractStringData(studentData[i], 2);
        string lastName = ExtractStringData(studentData[i], 3);
        string emailAddress = ExtractStringData(studentData[i], 4);
        int age = ExtractIntData(studentData[i], 5);
        int daysInCourse1 = ExtractIntData(studentData[i], 6);
        int daysInCourse2 = ExtractIntData(studentData[i], 7);
        int daysInCourse3 = ExtractIntData(studentData[i], 8);
        DegreeProgram degreeProgram = ExtractDPData(studentData[i]);

        // Now Add this Student to the Roster
        cout << "Added new student to Class Roster..." << endl;
        classRoster.add(studentID, firstName, lastName, emailAddress,
            age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    }   
    cout << endl << endl;
    
    // Print out Entire Roster
    classRoster.printAll();
    
    // Print Invalid Emails
    cout << endl << endl << "Checking for Invalid Email Addresses..." << endl << endl;
    classRoster.PrintInvalidEmails();

    // Print All Course Averages
    cout << endl << endl << "Computing Average Days in All Courses...";
    PrintAllAverageCourseDays(classRoster);

    // Print by Degree Program
    cout << endl << endl << "Forming new list by category request...";
    classRoster.printByDegreeProgram(SOFTWARE);

    // Remove a Student
    cout << endl << endl << endl << "Removing requested student..." << endl;
    classRoster.remove("A3");

    // Print All
    classRoster.printAll();

    // Remove a Student
    cout << endl << endl << endl << "Removing requested student..." << endl;
    classRoster.remove("A3");

    // End Program
    return 0;
}

