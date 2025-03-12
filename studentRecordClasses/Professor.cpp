#include "Professor.hpp"

void Professor::saveToFile(ofstream &outFile) const {
    Person::saveToFile(outFile);
    int deptLength = department.size();
    outFile.write(reinterpret_cast<const char *>(&deptLength), sizeof(deptLength));
    outFile.write(department.c_str(), deptLength);
    int emailLength = email.size();
    outFile.write(reinterpret_cast<const char *>(&emailLength), sizeof(emailLength));
    outFile.write(email.c_str(), emailLength);
}

//load from file
void Professor::loadFromFile(ifstream &inFile) {
    Person::loadFromFile(inFile);
    int deptLength;
    inFile.read(reinterpret_cast<char *>(&deptLength), sizeof(deptLength));
    char *tempDept = new char[deptLength + 1];
    inFile.read(tempDept, deptLength);
    tempDept[deptLength] = '\0';
    department = string(tempDept);
    delete [] tempDept;

    int emailLength;
    inFile.read(reinterpret_cast<char *>(&emailLength), sizeof(emailLength));
    char *tempEmail = new char[emailLength + 1];
    inFile.read(tempEmail, emailLength);
    tempEmail[emailLength] = '\0';
    email = string(tempEmail);
    delete [] tempEmail;
}

void Professor::print() const {
    cout << "Professor ";
    Person::print();
    cout << "Department: " << department << endl;
    cout << "Email: " << email << endl;
}