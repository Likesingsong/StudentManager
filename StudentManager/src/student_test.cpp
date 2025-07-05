// student_test.cpp

#include "student_test.h"
#include "student.h"
#include "student_manager.h"

void testStudent()
{
    // Create a student object
    Student student("Li Si", 20);
    student.setId("20250002");
    student.setSchool("No.2 High School");
    student.setClassName("Senior 3 Class 2");
    student.setGrade(88.0);
    // Print student information
    student.printInfo();
    // Modify student information
    student.setGrade(90.0);
    std::cout << "Student information after modification:" << std::endl;
    student.printInfo();
}

void testAddStudent()
{
    // Create student object: Zhang San
    Student student("Zhang San", 18);
    student.setId("20250001");
    student.setSchool("No.1 High School");
    student.setClassName("Senior 1 Class 1");
    student.setGrade(85.0);

    // Create student object: Li Si
    Student student2("Li Si", 19);
    student2.setId("20250002");
    student2.setSchool("No.2 High School");
    student2.setClassName("Senior 2 Class 2");
    student2.setGrade(90.0);

    // Create student object: Wang Wu
    Student student3("Wang Wu", 21);
    student3.setId("20250003");
    student3.setSchool("No.3 High School");
    student3.setClassName("Senior 3 Class 3");
    student3.setGrade(95.0);

    // Use StudentManager class to add student information
    StudentManager manager;
    bool res1 = manager.addStudent(student);
    bool res2 = manager.addStudent(student2);
    bool res3 = manager.addStudent(student3);
    if (!res1 || !res2 || !res3)
    {
        std::cerr << "Failed to add student information!" << std::endl;
        return;
    }
    manager.printAllStudents(); // Show all student information
    // Add student information
    std::cout << "Student information added successfully!" << std::endl;
}

void testLoadStudents()
{
    const std::string DATA_FILE = "students.txt";
    StudentManager manager;
    bool result = manager.loadFromFile(DATA_FILE); // Load student information
    if (!result)
    {
        std::cerr << "Failed to load student information!" << std::endl;
        return;
    }
    manager.printAllStudents(); // Show all student information
    std::cout << "Student information loaded successfully!" << std::endl;
}

void testSaveStudentToFile()
{
    StudentManager manager;
    // Create student object
    Student student("Zhang Dali", 18);
    student.setId("20250003");
    student.setSchool("No.1 High School");
    student.setClassName("Senior 1 Class 1");
    student.setGrade(85.0);
    // Add student information
    manager.addStudent(student);
    // Save to file
    if (manager.saveToFile(true))
    {
        std::cout << "Student information saved successfully!" << std::endl;
    }
    else
    {
        std::cerr << "Failed to save student information!" << std::endl;
    }
}

void testFindStudentById()
{
    StudentManager manager;
    
    std::string id;
    std::cout << "Please enter the student ID to search: ";
    std::cin >> id;
    Student* student = manager.findStudentById(id);
    if (student)
    {
        student->printInfo(); // Print student information
    }
    else
    {
        std::cout << "No student information found for ID " << id << "." << std::endl;
    }
}

void testModifyStudent()
{
    StudentManager manager;
    std::string id;
    std::cout << "Please enter the student ID to modify: ";
    std::cin >> id;
    bool result = manager.modifyStudent(id); // Modify student information
    if (result)
    {
        std::cout << "===== Modified Information =====" << std::endl;
        Student* student = manager.findStudentById(id);
        if (student)
        {
            student->printInfo(); // Print modified student information
        }
    }
    else
    {
        std::cerr << "Failed to modify student information!" << std::endl;
    }
}

void testDeleteStudent()
{
    StudentManager manager;
    std::string id;
    std::cout << "Please enter the student ID to delete: ";
    std::cin >> id;
    bool result = manager.deleteStudent(id); // Delete student information
    if (result)
    {
        std::cout << "Student information deleted successfully!" << std::endl;
    }
    else
    {
        std::cerr << "Failed to delete student information!" << std::endl;
    }
}

void testModifyStudentScore()
{
    StudentManager manager;

    std::string id;
    std::cout << "Please enter the student ID to modify the grade: ";
    std::cin >> id;

    bool result = manager.modifyGradeByStuId(id); // Modify student grade
    if (result)
    {
        std::cout << "Student grade modified successfully!" << std::endl;
    }
    else
    {
        std::cerr << "Failed to modify student grade!" << std::endl;
    }
}

void testSortStudents()
{
    StudentManager manager;

    manager.sortStudentsByGrade(); // Ascending order
    manager.sortStudentsByGrade(false); // Descending order
}
