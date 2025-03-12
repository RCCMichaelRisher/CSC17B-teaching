/*
 * Author: Michael Risher
 * Purpose: Student Record System from before but now using classes
 */

// System Libraries
#include <iomanip>
#include <iostream>  //Input Output Library
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

// User Libraries

// Global Constants not Variables
// Science, Math, Conversions, Dimensions

// Structures
struct Student {
  string name;
  int id;
  int *grades;
  int nGrades;
  float average;

  // constructor
  Student() {
    name = "";
    id = -1;
    nGrades = 0;
    grades = nullptr;
    average = 0;
  }

  

  // desctructor
  ~Student() { delete[] grades; }
};

struct Roster {
  Student *students;
  int nStudents;
};

// Function Prototypes
void printStudent(const Student &s);
void inputStudents(Roster *roster);
void printRoster(const Roster *const roster);
void saveRoster( Roster *roster, string filename );
void loadPrintRoster( string filename );
void calcAvg( Student &s );
void clean( Roster *r );

// Execution begins here at main
int main(int argc, char **argv) {
  // Set random number seed
    srand(time(0));
  // Declare Variables
  string filename;  // binary file to save too
  int numStudents;  // the number of students
  Roster *roster;
  // Initialize Variables

  filename = "students.dat";
  //let the user decide to load a file or not
  cout << "Load a file? (y/n): ";
  char choice;
  cin >> choice;
  if( choice == 'y' ) {
      cout << "Enter the filename: ";
      cin >> filename;

      //load the file
      loadPrintRoster( filename );
  } else {
    cout << "Enter number of students to add: ";
    cin >> numStudents;

    roster = new Roster;
    roster->nStudents = numStudents;
    roster->students = new Student[numStudents];
    // init the students in the roster
    inputStudents(roster);

    // Map/Process the Inputs -> Outputs
    //save roster to a binary file
    saveRoster( roster, filename );

    // Display Inputs/Outputs
    printRoster(roster);

    //cleanup
    clean( roster );
  }

  // Exit the Program
  return 0;
}

void calcAvg( Student &s ) {
  s.average = 0;
  for (int i = 0; i < s.nGrades; i++) {
    s.average += s.grades[i];
  }
  s.average /= s.nGrades;
}

void printStudent(const Student *s) {
  cout << left << setw(10) << "Name:" << s->name << endl;
  cout << left << setw(10) << "ID:" << s->id << endl;
  cout << left << setw(10) << "Tests:";
  for (int i = 0; i < s->nGrades; i++) {
      cout << s->grades[i];
      if (i < s->nGrades - 1) cout << ", ";
  }
  cout << endl;
  cout << left << setw(10) << "Average:" << fixed << setprecision(2) << s->average << endl << endl;
}

void inputStudents(Roster *roster) {
  // cin.ignore(); // Clear input buffer
  for (int i = 0; i < roster->nStudents; i++) {
    cout << "\nEnter details for student " << i + 1 << ":\n";
    cout << "ID: ";
    cin >> roster->students[i].id;
    cin.ignore();
    cout << "Name: ";
    getline(cin, roster->students[i].name);

    cout << "Enter number of tests: ";
    cin >> roster->students[i].nGrades;
    roster->students[i].grades = new int[roster->students[i].nGrades];
    for (int j = 0; j < roster->students[i].nGrades; j++) {
      roster->students[i].grades[j] = rand() % 101; // Random grade
    }

    //roster->students[i].calcAvg();  // Compute the average
    calcAvg( roster->students[i] ); // Compute the average
  }
}

void printRoster(const Roster *const roster) {
    cout << endl << left << setw( 20 ) << setfill( '_' ) << "Roster: " << setfill(' ') << endl; // Print the roster header
    for (int i = 0; i < roster->nStudents; i++) {
    cout << "Student " << i + 1 << ":\n";
    printStudent(&roster->students[i]);  // Print the student
  }
}

// Save the roster to a binary file
void saveRoster(Roster *roster, string filename) {
    ofstream output(filename, ios::binary); // Open the file in binary mode
    if ( output.good() ) {
        output.write(reinterpret_cast<char *>(&roster->nStudents), sizeof(int)); // Write the number of students
        for (int i = 0; i < roster->nStudents; i++) {
            output.write(reinterpret_cast<char *>(&roster->students[i].id), sizeof(int)); // Write the ID
            int nameLength = roster->students[i].name.size(); // Get the length of the name
            output.write(reinterpret_cast<char *>(&nameLength), sizeof(int)); // Write the length of the name
            output.write(roster->students[i].name.c_str(), nameLength); // Write the name
            output.write(reinterpret_cast<char *>(&roster->students[i].nGrades), sizeof(int)); // Write the number of grades
            output.write(reinterpret_cast<char *>(roster->students[i].grades), roster->students[i].nGrades * sizeof(int)); // Write the grades
            output.write(reinterpret_cast<char *>(&roster->students[i].average), sizeof(float)); // Write the average
        }
        output.close();
    } else {
        cout << "Error: Could not open file " << filename << endl;
    }
}

void loadPrintRoster(string filename) {
    ifstream input(filename, ios::binary); // Open the file
    if ( input.good() ) {
        int nStudents;
        input.read(reinterpret_cast<char *>(&nStudents), sizeof(int)); // Read the number of students
        Roster *roster = new Roster; // Create a roster with the correct number of students
        roster->nStudents = nStudents;
        roster->students = new Student[nStudents]; // Allocate memory for the students
        for (int i = 0; i < nStudents; i++) {
            input.read(reinterpret_cast<char *>(&roster->students[i].id), sizeof(int)); // Read the ID
            int nameLength;
            input.read(reinterpret_cast<char *>(&nameLength), sizeof(int)); // Read the length of the name
            char *name = new char[nameLength + 1];  // Allocate memory for the name
            input.read(name, nameLength); // Read the name
            name[nameLength] = '\0'; // Null-terminate the name
            roster->students[i].name = string(name); // Assign the name to the student
            delete[] name; // Free the memory
            input.read(reinterpret_cast<char *>(&roster->students[i].nGrades), sizeof(int)); // Read the number of grades
            roster->students[i].grades = new int[roster->students[i].nGrades]; // Allocate memory for the grades
            input.read(reinterpret_cast<char *>(roster->students[i].grades), roster->students[i].nGrades * sizeof(int)); // Read the grades
            input.read(reinterpret_cast<char *>(&roster->students[i].average), sizeof(float)); // Read the average
        }
        input.close(); // Close the file
        printRoster(roster); // Print the roster 
        delete roster; // Free the memory
    } else {
        cout << "Error: Could not open file " << filename << endl; // Error message
    }
}

void clean( Roster *r ) {
    for (int i = 0; i < r->nStudents; i++) {
        delete[] r->students[i].grades;
    }
    delete[] r->students;
    delete r;
}

//
