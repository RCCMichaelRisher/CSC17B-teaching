#pragma once

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Person {
    protected: 
        string name;
        int id;
    public: 
        Person();
        Person( string name, int id ) : name( name ), id( id ) {}

        // Accessors
        string getName() const { return name; }
        int getId() const { return id; }
        // Mutators
        void setName( string name ) { this->name = name; }
        void setId( int id ) { this->id = id; }
        // Destructor
        virtual ~Person() {}

        //print function
        virtual void print() const {
            cout << "Name: " << name << endl;
            cout << "ID: " << id << endl;
        }

        // Function to save to binary file
        virtual void saveToFile( ofstream &outFile ) const {
            outFile.write(reinterpret_cast<const char *>(this), sizeof( this ));
        }
      
};