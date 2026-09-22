add_library(person_examples
    Student.cpp
)
target_include_directories(person_examples PUBLIC .)
target_link_libraries(person_examples PUBLIC person)
target_compile_options(person_examples PRIVATE -Wall -Wextra -Wpedantic)

add_executable(person_demo demo.cpp)
target_link_libraries(person_demo PRIVATE person person_examples)
