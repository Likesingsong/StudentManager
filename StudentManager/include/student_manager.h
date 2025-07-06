#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Student.h"
#include "data_structure.h"

void printStudentMenu();

// Student manager class
class StudentManager
{
private:
    DoublyLinkedList<Student> students; // List to store student objects
    std::string data_file = "../students.txt";
public:
    StudentManager();

    ~StudentManager();

    void setDataFile(const std::string& filename);

    bool addStudent(const Student& stu);

    Student* findStudentById(const std::string& id);

    bool modifyStudent(const std::string& id);

	bool modifyGradeByStuId(const std::string& id);

    bool deleteStudent(const std::string& id);

    void printAllStudents();

    bool loadFromFile(const std::string& filename);

    bool saveToFile(bool appendMode = false);

	bool sortStudentsByGrade(bool ascending = true);
};
