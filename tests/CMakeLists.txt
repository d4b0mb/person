add_executable(person_tests person_tests.cpp)
target_link_libraries(person_tests PRIVATE person person_examples)

add_test(NAME person_tests COMMAND person_tests)
