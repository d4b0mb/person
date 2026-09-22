#include <iostream>

#include "Student.h"
#include "person/Person.h"

int main() {
    Person alice("Alice", "Nour", "Hassan", NationalID("29001010112345", Country("EG")));
    std::cout << alice.describe() << "\n";

    Student bob("Bob", "Smith", NationalID("123-45-6789", Country("US")), "Computer Science", 2027);
    std::cout << bob.describe() << "\n";

    // Registration can happen before an ID has been issued.
    Person pending("Jane", "Doe");
    std::cout << pending.describe() << "\n";
    pending.setId(NationalID("998877", Country("GB")));
    std::cout << pending.describe() << "\n";

    return 0;
}
