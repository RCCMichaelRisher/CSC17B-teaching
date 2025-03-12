#include "Student.hpp"

#include <iomanip>
#include <iostream>

void Student::print() const {
    cout << left << setw(10) << "Name:" << this->name << endl;
  cout << left << setw(10) << "ID:" << this->id << endl;
  cout << left << setw(10) << "Tests:";
  for (int i = 0; i < this->nGrades; i++) {
      cout << this->grades[i];
      if (i < this->nGrades - 1) cout << ", ";
  }
  cout << endl;
  cout << left << setw(10) << "Average:" << fixed << setprecision(2) << this->average << endl << endl;
}

void Student::calcAvg(){
    this->average = 0;
    for (int i = 0; i < this->nGrades; i++) {
        this->average += this->grades[i];
    }
    this->average /= this->nGrades;
}