#pragma once

#include <string>

#include "person/Person.h"

// Example of building on Person: a Student is a Person plus the
// information that only makes sense in an academic context. This is the
// intended way to extend the library -- Person itself stays generic.
class Student : public Person {
public:
    Student(std::string firstName, std::string lastName, NationalID id, std::string major, int enrollmentYear);

    const std::string& major() const noexcept { return major_; }
    int enrollmentYear() const noexcept { return enrollmentYear_; }

    void setMajor(std::string major) { major_ = std::move(major); }

    std::string describe() const override;

private:
    std::string major_;
    int enrollmentYear_;
};
