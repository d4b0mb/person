# person

A small, dependency-free C++ library modeling a registered person, designed
to be used as a base class by whatever system needs one (student records,
employee directories, patient registration, ...).

## Why this shape

A person is identified by an ID number, but an ID number alone isn't
enough: every country runs its own numbering scheme, so the same string of
digits issued by two different countries identifies two different people.
`NationalID` pairs the number with the issuing `Country` so the two can
never be separated, and its constructor rejects a number without a
country.

`Country` stores an ISO 3166-1 alpha-2 code (`"EG"`, `"US"`, `"GB"`, ...)
rather than a fixed enum, so supporting a new country never requires a
code change to the library.

`Person` itself only carries what's true of *every* person: a name and a
`NationalID`. Anything specific to one context — a student's major, an
employee's job title, a system user's access level — belongs on a class
that derives from `Person`, not on `Person` itself. That's what keeps it a
usable template: `Person` has a virtual destructor, protected data
members, and a virtual `describe()`, so a new class can extend it with
`class Foo : public Person { ... }` and add exactly the fields it needs.
See [`examples/Student.h`](examples/Student.h) and
[`examples/Student.cpp`](examples/Student.cpp) for a worked example, and
[`examples/demo.cpp`](examples/demo.cpp) for it in use.

An ID can also be attached after construction via `setId()`, since
registration and ID issuance don't always happen at the same time (a
newborn, for instance, may be registered before their national ID exists).

## Layout

```
include/person/   Public headers (Country, NationalID, Person)
src/               Library implementation
examples/          Student, a worked example of extending Person, plus a demo
tests/             Unit tests
```

## Building

Requires CMake 3.14+ and a C++17 compiler.

```sh
cmake -S . -B build
cmake --build build
```

Run the demo:

```sh
./build/examples/person_demo
```

Run the tests:

```sh
ctest --test-dir build --output-on-failure
```

## Usage

```cpp
#include "person/Person.h"

Person alice("Alice", "Nour", "Hassan",
             NationalID("29001010112345", Country("EG")));

alice.describe();       // "Alice Nour Hassan (ID: EG-29001010112345)"
alice.id().issuingCountry().name();  // "Egypt"
```

Extending `Person` for a new use case:

```cpp
class Employee : public Person {
public:
    Employee(std::string firstName, std::string lastName, NationalID id, std::string title)
        : Person(std::move(firstName), std::move(lastName), std::move(id)),
          title_(std::move(title)) {}

    const std::string& title() const noexcept { return title_; }

private:
    std::string title_;
};
```

## License

MIT — see [LICENSE](LICENSE).
