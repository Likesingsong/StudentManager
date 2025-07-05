#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Student.h"

void printStudentMenu();

// 学生管理类
class StudentManager {
private:
    std::vector<Student> students;
    std::string data_file = "students.txt";
public:
    StudentManager();

    ~StudentManager();

    void setDataFile(const std::string& filename);

    bool addStudent(const Student& stu);

    Student* findStudentById(const std::string& id);

    bool modifyStudent(const std::string& id);

	bool modifyGradeByStuId(const std::string& id);

    bool deleteStudent(const std::string& id);

    void printAllStudents() const;

    bool loadFromFile(const std::string& filename);

    bool saveToFile(bool appendMode = false) const;

	bool sortStudentsByGrade(bool ascending = true);
};
