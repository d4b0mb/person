#pragma once

#include <string>

#include "person/NationalID.h"

// Minimal, reusable representation of a registered person: a name and the
// national ID that identifies them.
//
// This class is intentionally lean: it only carries information that
// applies to *every* person, regardless of context. Anything specific to
// one kind of person -- a student's major, an employee's job title, a
// system user's access level, and so on -- belongs in a class that
// derives from Person rather than in Person itself. See examples/Student.h
// for a worked example, and README.md for the reasoning.
//
// Person is designed to be used as a base class: its destructor is
// virtual, its data members are protected, and describe() is virtual so
// derived classes can extend it.
class Person {
public:
    Person() = default;

    Person(std::string firstName, std::string lastName, NationalID id = NationalID());
    Person(std::string firstName, std::string middleName, std::string lastName, NationalID id = NationalID());

    virtual ~Person() = default;
    Person(const Person&) = default;
    Person(Person&&) = default;
    Person& operator=(const Person&) = default;
    Person& operator=(Person&&) = default;

    const std::string& firstName() const noexcept { return firstName_; }
    const std::string& middleName() const noexcept { return middleName_; }
    const std::string& lastName() const noexcept { return lastName_; }
    const NationalID& id() const noexcept { return id_; }

    // Joins the non-empty name parts with single spaces.
    std::string fullName() const;

    void setFirstName(std::string firstName);
    void setMiddleName(std::string middleName);
    void setLastName(std::string lastName);

    // An ID can be assigned after construction -- e.g. once a country
    // finishes issuing a document for a person who was registered earlier.
    void setId(NationalID id);

    // Human-readable one-line summary. Override in derived classes to
    // include additional information.
    virtual std::string describe() const;

protected:
    std::string firstName_;
    std::string middleName_;
    std::string lastName_;
    NationalID id_;
};
