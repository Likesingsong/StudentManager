// student.cpp

#include "student.h"
#include <iostream>

// Default constructor
Student::Student()
    : id_("000000"), name_(""), age_(0), school_("Unknown School"), className_("Unknown Class"), grade_(0.0) {}

// Constructor with name and age
Student::Student(const std::string& name, int age)
    : id_("000000"), name_(name), age_(age), school_("Unknown School"), className_("Unknown Class"), grade_(0.0) {}

// Constructor with all fields
Student::Student(const std::string& id, const std::string& name, int age,
                 const std::string& school, const std::string& className, double grade)
    : id_(id), name_(name), age_(age), school_(school), className_(className), grade_(grade) {}

std::string Student::getId() const { return id_; }
void Student::setId(const std::string& id) { id_ = id; }

std::string Student::getName() const { return name_; }
void Student::setName(const std::string& name) { name_ = name; }

int Student::getAge() const { return age_; }
void Student::setAge(int age) { age_ = age; }

std::string Student::getSchool() const { return school_; }
void Student::setSchool(const std::string& school) { school_ = school; }

std::string Student::getClassName() const { return className_; }
void Student::setClassName(const std::string& className) { className_ = className; }

double Student::getGrade() const { return grade_; }
void Student::setGrade(double grade) { grade_ = grade; }

void Student::printInfo() const
{
    std::cout << "ID: " << id_ << std::endl;
    std::cout << "Name: " << name_ << std::endl;
    std::cout << "Age: " << age_ << std::endl;
    std::cout << "School: " << school_ << std::endl;
    std::cout << "Class: " << className_ << std::endl;
    std::cout << "Grade: " << grade_ << std::endl;
    std::cout << "\n\n";
}