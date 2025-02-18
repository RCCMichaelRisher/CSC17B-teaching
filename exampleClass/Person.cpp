#include "Person.h"
#include <iostream>


Person::Person(std::string name, int age) : name(name), age(age) {}

void Person::introduce() const {
    cout << "Hi, I'm " << name << " and I'm " << age << " years old." << endl;
}
