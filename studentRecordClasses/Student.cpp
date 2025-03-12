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

void Student::saveToFile(ofstream &outFile) const  {
    Person::saveToFile(outFile);
    outFile.write(reinterpret_cast<const char *>(&nGrades), sizeof(nGrades));
    outFile.write(reinterpret_cast<const char *>(grades), nGrades * sizeof(int));
    outFile.write(reinterpret_cast<const char *>(&average), sizeof(average));
}

void Student::loadFromFile(ifstream &inFile) {
    Person::loadFromFile(inFile);
    inFile.read(reinterpret_cast<char *>(&nGrades), sizeof(nGrades));
    grades = new int[nGrades];
    inFile.read(reinterpret_cast<char *>(grades), nGrades * sizeof(int));
    inFile.read(reinterpret_cast<char *>(&average), sizeof(average));
}