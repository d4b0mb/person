#include "person/Person.h"

Person::Person(std::string firstName, std::string lastName, NationalID id)
    : firstName_(std::move(firstName)), lastName_(std::move(lastName)), id_(std::move(id)) {}

Person::Person(std::string firstName, std::string middleName, std::string lastName, NationalID id)
    : firstName_(std::move(firstName)),
      middleName_(std::move(middleName)),
      lastName_(std::move(lastName)),
      id_(std::move(id)) {}

std::string Person::fullName() const {
    std::string result = firstName_;
    for (const std::string* part : {&middleName_, &lastName_}) {
        if (!part->empty()) {
            if (!result.empty()) {
                result += " ";
            }
            result += *part;
        }
    }
    return result;
}

void Person::setFirstName(std::string firstName) { firstName_ = std::move(firstName); }
void Person::setMiddleName(std::string middleName) { middleName_ = std::move(middleName); }
void Person::setLastName(std::string lastName) { lastName_ = std::move(lastName); }
void Person::setId(NationalID id) { id_ = std::move(id); }

std::string Person::describe() const { return fullName() + " (ID: " + id_.toString() + ")"; }
