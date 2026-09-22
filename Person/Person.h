#include<iostream>
#include<stdexcept>
#include<string>
#ifndef PERSON_H_
#define PERSON_H_


enum class Access{
    admin,
    user,
    visitor,
    null
};


class Person{
    private:

     std::string firstName;
     std::string middleName;
     std::string lastName;
     std::string major;

     int age;
     int idN;

     Access clearance;

     // Hands out a unique idN to each Person as it's constructed, so an ID
     // is never supplied by the caller and never collides between people.
     static int nextId;

     public:
     Person():firstName("Unknown"), middleName(""), lastName(""), major("NA"), age(-1), idN(nextId++), clearance(Access::null){}
     Person(const std::string& firstName, const std::string& middleName, const std::string& lastName,
     const std::string& major, int age, Access clearance);
     ~Person() = default;

     std::string getFullName() const;
     std::string getMajor() const;
     int getAge() const;
     int getIdN() const;
     Access getClearance() const;

     void updateName(const Person& modifier, const std::string& first, const std::string& middle, const std::string& last);
     void setMajor(const Person& modifier, const std::string& newMajor);
     void setAge(const Person& modifier, int newAge);









};


#endif