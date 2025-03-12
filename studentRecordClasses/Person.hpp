#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Person {
    protected: 
        string name;
        int id;
    public: 
        Person(){}
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
            int nameLength = name.size();
            outFile.write(reinterpret_cast<const char *>(&nameLength), sizeof(nameLength));
            outFile.write(name.c_str(), nameLength);
            outFile.write(reinterpret_cast<const char *>(&id), sizeof(id));
        }

        // Function to load from binary file
        virtual void loadFromFile( ifstream &inFile ) {
            int nameLength;
            inFile.read(reinterpret_cast<char *>(&nameLength), sizeof(nameLength));
            char *tempName = new char[nameLength + 1];
            inFile.read(tempName, nameLength);
            tempName[nameLength] = '\0';
            name = string(tempName);
            delete [] tempName;
            inFile.read(reinterpret_cast<char *>(&id), sizeof(id));
        }
      
};

#endif /* PERSON_HPP */