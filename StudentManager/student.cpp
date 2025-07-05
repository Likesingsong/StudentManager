#include "student.h"
#include <iostream>

Student::Student()
    : id_("000000"), name_(""), age_(0), school_("未知学校"), className_("未知班级"), grade_(0.0) {}

Student::Student(const std::string& name, int age)
    : id_("000000"), name_(name), age_(age), school_("未知学校"), className_("未知班级"), grade_(0.0) {}

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

void Student::printInfo() const {
    std::cout << "学号: " << id_ << std::endl;
    std::cout << "姓名: " << name_ << std::endl;
    std::cout << "年龄: " << age_ << std::endl;
    std::cout << "学校: " << school_ << std::endl;
    std::cout << "班级: " << className_ << std::endl;
    std::cout << "成绩: " << grade_ << std::endl;
    std::cout << "\n\n";
}