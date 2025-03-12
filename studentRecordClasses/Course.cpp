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
        this->students[i].calcAvg(); // Calculate average
    }
}

void Course::addProfessor(){
    Professor *p = new Professor;
    int inputNum;
    string inputStr;

    cout << "Input Professor Details:\n";

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
    cout << endl;
    cout << "Course Name: " << this->name << endl;
    cout << "Number of Students: " << this->numStudents << endl;
    cout << "-----Professor-----" << endl;
    if (this->professor != nullptr) {
        this->professor->print();
    } else {
        cout << "No professor assigned." << endl;
    }
    cout << "-----Students-----" << endl;
    for (int i = 0; i < this->numStudents; i++) {
        this->students[i].print();
    }

}

void Course::saveToFile( string filename ) const {
    ofstream outfile( filename, ios::binary );
    if( !outfile ) {
        cout << "Error opening file for writing." << endl;
        return;
    }
    //save course to binary file
    // Save course name
    int nameLength = this->name.size();
    outfile.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
    outfile.write(this->name.c_str(), nameLength);

    // Save number of students
    outfile.write(reinterpret_cast<const char*>(&this->numStudents), sizeof(this->numStudents));

    // Save professor details
    bool hasProfessor = (this->professor != nullptr);
    outfile.write(reinterpret_cast<const char*>(&hasProfessor), sizeof(hasProfessor));
    if (hasProfessor) {
        this->professor->saveToFile(outfile);
    }

    // Save students details
    for (int i = 0; i < this->numStudents; i++) {
        this->students[i].saveToFile(outfile);
    }

    outfile.close();
}

void Course::loadFromFile( string filename ){
    ifstream infile( filename, ios::binary );
    if( !infile ) {
        cout << "Error opening file for reading." << endl;
        return;
    }
    //load course from binary file
    // Load course name
    int nameLength;
    infile.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
    char *tempName = new char[nameLength + 1];
    infile.read(tempName, nameLength);
    tempName[nameLength] = '\0';
    this->name = string(tempName);
    delete [] tempName;
    // Load number of students
    infile.read(reinterpret_cast<char*>(&this->numStudents), sizeof(this->numStudents));
    // Load professor details
    bool hasProfessor;
    infile.read(reinterpret_cast<char*>(&hasProfessor), sizeof(hasProfessor));
    if (hasProfessor) {
        this->professor = new Professor;
        this->professor->loadFromFile(infile);
    } else {
        this->professor = nullptr;
    }
    // Load students details
    this->students = new Student[this->numStudents];
    for (int i = 0; i < this->numStudents; i++) {
        this->students[i].loadFromFile(infile);
    }
    infile.close();
}