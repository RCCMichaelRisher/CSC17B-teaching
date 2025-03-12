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
        virtual void print() const override {
            cout << "Professor ";
            Person::print();
            cout << "Department: " << department << endl;
            cout << "Email: " << email << endl;
        }
        // accessors
        string getDepartment() const { return department; }
        string getEmail() const { return email; }
        // mutators
        void setDepartment(string department) { this->department = department; }
        void setEmail(string email) { this->email = email; }
};
