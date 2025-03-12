#pragma once


#include "Student.hpp"
#include "Professor.hpp"

#include <string>
#include <iostream>

using namespace std;

class Course {
    private: 
        int numStudents;
        Student *students;
        Professor *professor;
        string name;
    public: 
        Course(int numStudents, string name);
        Course();

        void inputStudents();
        void addProfessor();
        void print() const;

        //accessors
        int getNumStudents() const { return numStudents; }
        Student *getStudents() const { return students; }
        Professor *getProfessor() const { return professor; }
        string getName() const { return name; }
        
        //mutators
        void setNumStudents(int numStudents) { this->numStudents = numStudents; }
        void setStudents(Student *students) { this->students = students; }
        void setProfessor(Professor *professor) { this->professor = professor; }
        void setName(string name) { this->name = name; }

        //destructor
        ~Course() { 
            delete [] students; 
            delete professor; 
        }
};
