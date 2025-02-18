#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person {
private:
    std::string name;
    int age;

public:
    Person(std::string name, int age);
    void introduce() const;
};

#endif
