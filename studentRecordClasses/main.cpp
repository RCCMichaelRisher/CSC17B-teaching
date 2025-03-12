/* 
 * Author: Michael Risher
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <string>  //Input Output Library
using namespace std;

//User Libraries
#include "Course.hpp"
//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    string filename = "students.dat";
    int numStudents;
    string courseName;
    //Initialize Variables
    cout << "Enter number of students: ";
    cin >> numStudents;
    cin.ignore();

    cout << "Enter course name: ";
    getline(cin, courseName);

    //create the course dyanmically
    Course *course = new Course( numStudents, courseName );

    //add professor
    course->addProfessor();
    //input students
    course->inputStudents();
    
    //print course info
    course->print();
    
    //Clean up memory and files
    delete course;
    //Exit the Program
    return 0;
}

/**
 * string filename = "students.dat";
    int numStudents;

    cout << "Enter number of students: ";
    cin >> numStudents;
    cin.ignore();
 * 
 */