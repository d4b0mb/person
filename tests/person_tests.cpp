#include <cassert>
#include <iostream>
#include <stdexcept>

#include "Student.h"
#include "person/Person.h"

namespace {

void testCountryValidatesCode() {
    Country eg("eg");
    assert(eg.code() == "EG");
    assert(eg.name() == "Egypt");

    Country unlisted("KE");
    assert(unlisted.name() == "KE");  // falls back to the code

    bool threw = false;
    try {
        Country bad("E1");
    } catch (const std::invalid_argument&) {
        threw = true;
    }
    assert(threw);
}

void testNationalIdRequiresCountry() {
    bool threw = false;
    try {
        NationalID id("12345", Country());
    } catch (const std::invalid_argument&) {
        threw = true;
    }
    assert(threw);

    NationalID id("12345", Country("US"));
    assert(id.isSet());
    assert(id.toString() == "US-12345");
    assert(NationalID().toString() == "(not assigned)");
}

void testPersonFullName() {
    Person noMiddle("John", "Doe");
    assert(noMiddle.fullName() == "John Doe");

    Person withMiddle("John", "Q", "Doe");
    assert(withMiddle.fullName() == "John Q Doe");
}

void testPersonDescribeWithoutId() {
    Person unregistered("Jane", "Doe");
    assert(!unregistered.id().isSet());
    assert(unregistered.describe() == "Jane Doe (ID: (not assigned))");
}

void testPersonIdCanBeAssignedLater() {
    Person p("Jane", "Doe");
    p.setId(NationalID("55", Country("EG")));
    assert(p.id().isSet());
    assert(p.id().issuingCountry().code() == "EG");
}

void testStudentExtendsPerson() {
    Student student("Omar", "Ali", NationalID("998877", Country("EG")), "Computer Science", 2026);
    assert(student.major() == "Computer Science");
    assert(student.id().issuingCountry().code() == "EG");

    // A Student "is-a" Person, so it can be used polymorphically.
    const Person& asPerson = student;
    assert(asPerson.describe() == student.describe());
}

}  // namespace

int main() {
    testCountryValidatesCode();
    testNationalIdRequiresCountry();
    testPersonFullName();
    testPersonDescribeWithoutId();
    testPersonIdCanBeAssignedLater();
    testStudentExtendsPerson();

    std::cout << "All tests passed.\n";
    return 0;
}
