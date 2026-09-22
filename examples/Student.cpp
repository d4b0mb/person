#include "Student.h"

Student::Student(std::string firstName, std::string lastName, NationalID id, std::string major, int enrollmentYear)
    : Person(std::move(firstName), std::move(lastName), std::move(id)),
      major_(std::move(major)),
      enrollmentYear_(enrollmentYear) {}

std::string Student::describe() const {
    return Person::describe() + ", " + major_ + " major (class of " + std::to_string(enrollmentYear_) + ")";
}
