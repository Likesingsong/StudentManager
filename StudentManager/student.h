#pragma once
#include <string>
#include <iostream>

class Student {
private:
    std::string id_;
    std::string name_;
    int age_;
    std::string school_;
    std::string className_;
    double grade_;

public:
    Student();
    Student(const std::string& name, int age);
    Student(const std::string& id, const std::string& name, int age,
            const std::string& school, const std::string& className, double grade);

    std::string getId() const;
    void setId(const std::string& id);

    std::string getName() const;
    void setName(const std::string& name);

    int getAge() const;
    void setAge(int age);

    std::string getSchool() const;
    void setSchool(const std::string& school);

    std::string getClassName() const;
    void setClassName(const std::string& className);

    double getGrade() const;
    void setGrade(double grade);

    void printInfo() const;
};