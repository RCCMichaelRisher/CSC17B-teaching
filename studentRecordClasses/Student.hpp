#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "Person.hpp"

using namespace std;

class Student : public Person {
    private: 
      int *grades;
      int nGrades;
      float average;
    public: 
        Student(){}
        Student( string name, int id, int nGrades ) : Person( name, id ), nGrades( nGrades ) {
            grades = new int[nGrades];
            average = 0;
        }

        // Accessors
        int getNGrades() const { return nGrades; }
        int *getGrades() const { return grades; }
        float getAverage() const { return average; }

        // Mutators
        void setNGrades( int nGrades ) { this->nGrades = nGrades; }
        void setGrades( int *grades ) { this->grades = grades; }
        void setAverage( float average ) { this->average = average; }

        //print function
        virtual void print() const override;
        //calculate average
        void calcAvg();
        //save to file
        void saveToFile(ofstream &outFile) const override;
        //load from file
        void loadFromFile(ifstream &inFile) override;

        //destructor
        virtual ~Student() { 
            delete [] grades; 
        }

      
};


#endif /* STUDENT_HPP */