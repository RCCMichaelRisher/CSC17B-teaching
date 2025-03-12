#include "Course.hpp"


Course::Course(int numStudents, string name) {
    this->numStudents = numStudents;
    this->name = name;
    this->students = new Student[numStudents];
    this->professor = nullptr;
}


void Course::inputStudents(){
    for( int i = 0; i < this->numStudents; i++ ){
        cout << "\nEnter details for student " << i + 1 << ":\n";
        cout << "ID: ";
        int inputNum;
        cin >> inputNum;
        this->students[i].setId( inputNum );
        cin.ignore(); //ignore the newline
        //get the name
        cout << "Name: ";
        string inputStr;
        getline(cin, inputStr );
        this->students[i].setName( inputStr );

        cout << "Enter number of tests: ";
        cin >> inputNum;
        this->students[i].setNGrades( inputNum );

        //make a temp array
        int *intArray = new int[ inputNum ];

        for (int j = 0; j < this->students[i].getNGrades() ; j++) {
            intArray[j] = rand() % 101; // Random grade
        }

        this->students[i].setGrades( intArray );
    }
}

void Course::addProfessor(){
    Professor *p = new Professor;
    int inputNum;
    string inputStr;

    //get id
    cout << "Faculty Id: ";
    cin >> inputNum;
    cin.ignore();
    p->setId( inputNum );
    
    //get name
    cout << "Name: ";
    getline( cin, inputStr );
    p->setName( inputStr );

    //get department
    cout << "Department: ";
    getline( cin, inputStr );
    p->setDepartment( inputStr );

    //get emait
    cout << "Email: ";
    getline( cin, inputStr );
    p->setEmail( inputStr );

    this->professor = p;
}

void Course::print() const {
    cout << "Course Name: " << this->name << endl;
    cout << "Number of Students: " << this->numStudents << endl;
    cout << "Professor: " << endl;
    if (this->professor != nullptr) {
        this->professor->print();
    } else {
        cout << "No professor assigned." << endl;
    }
    cout << "Students: " << endl;
    for (int i = 0; i < this->numStudents; i++) {
        this->students[i].print();
    }

}