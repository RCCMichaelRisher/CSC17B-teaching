#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "Person.hpp"

using namespace std;
class Professor : public Person {
    private: 
        string department;
        string email;
    public: 
        Professor(){}
        Professor(string name, int id, string department, string email ) : Person(name, id), department(department), email(email) {}
        // Override display method
        virtual void print() const override;
        // accessors
        string getDepartment() const { return department; }
        string getEmail() const { return email; }
        // mutators
        void setDepartment(string department) { this->department = department; }
        void setEmail(string email) { this->email = email; }
        void saveToFile(ofstream &outFile) const override;

        //load from file
        void loadFromFile(ifstream &inFile) override;
};

#endif /* PROFESSOR_HPP */