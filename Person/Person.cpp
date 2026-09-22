#include "Person.h"
using namespace std;

int Person::nextId = 1;

Person::Person(const string& firstName, const string& middleName,
               const string& lastName, const string& major,
               int age, Access clearance)
    : firstName(firstName), middleName(middleName), lastName(lastName),
      major(major), age(age), idN(nextId++), clearance(clearance) {}


string Person::getFullName() const {
    return firstName + " " + middleName + " " + lastName;
}

string Person::getMajor() const {
    return major;
}

int Person::getAge() const {
    return age;
}

int Person::getIdN() const {
    return idN;
}

Access Person::getClearance() const {
    return clearance;
}


void Person::updateName(const Person& modifier, const string& first, const string& middle, const string& last) {

    if (modifier.getClearance() != Access::admin) {
        throw runtime_error("Unauthorized: Only Admin can modify names.");
    }

    firstName = first;
    middleName = middle;
    lastName = last;
}

void Person::setMajor(const Person& modifier, const string& newMajor) {

    if (modifier.getClearance() != Access::admin) {
        throw runtime_error("Unauthorized: Only Admin can modify the major.");
    }

    major = newMajor;
}

void Person::setAge(const Person& modifier, int newAge) {

    if (modifier.getClearance() != Access::admin) {
        throw runtime_error("Unauthorized: Only Admin can modify the age.");
    }
    
    if (newAge < 0) {
        throw invalid_argument("Invalid age: Age cannot be negative.");
    }

    if (newAge>= 90){
        throw invalid_argument("R u sure about that?");
    }

    age = newAge;
}
