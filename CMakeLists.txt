cmake_minimum_required(VERSION 3.14)
project(person LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Build type" FORCE)
endif()

add_library(person
    src/Country.cpp
    src/NationalID.cpp
    src/Person.cpp
)
target_include_directories(person PUBLIC include)
target_compile_options(person PRIVATE -Wall -Wextra -Wpedantic)

add_subdirectory(examples)

option(PERSON_BUILD_TESTS "Build the person library's tests" ON)
if(PERSON_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
