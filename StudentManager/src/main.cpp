// main.cpp

#include "student_manager.h"

void printStudentMenu();
void addStudent(StudentManager& manager);
void queryStudentById(StudentManager& manager);
void modifyStudentById(StudentManager& manager);
void deleteStudentById(StudentManager& manager);
void modifyStudentGradeById(StudentManager& manager);
void sortStudentsByGrade(StudentManager& manager);

int main()
{
    StudentManager manager;

    int choice;
    do
    {
        printStudentMenu();

        std::cin >> choice;

        switch (choice)
        {
        case 1:  // Add
            addStudent(manager);
            break;
        case 2:  // Query
            queryStudentById(manager);
            break;
        case 3:  // Modify
            modifyStudentById(manager);
            break;
        case 4:  // Delete
            deleteStudentById(manager);
            break;
        case 5: // Show all
            manager.printAllStudents();
            break;
        case 6: // Modify student grade by ID
            modifyStudentGradeById(manager);
            break;
        case 7: // Sort students by grade
            sortStudentsByGrade(manager);
            break;
        case 0:
            std::cout << "Exit system." << std::endl;
            break;
        default:
            std::cout << "Invalid choice, please try again.\n\n";
        }
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    } while (choice != 0);

    return 0;
}

// Student information operation menu function
void printStudentMenu()
{
    std::cout << "==============================" << std::endl;
    std::cout << " Student Information Management System Menu " << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "1. Add student information" << std::endl;
    std::cout << "2. Query student information" << std::endl;
    std::cout << "3. Modify student information" << std::endl;
    std::cout << "4. Delete student information" << std::endl;
    std::cout << "5. Show all students" << std::endl;
    std::cout << "6. Modify student grade" << std::endl;
    std::cout << "7. Sort students by grade" << std::endl;
    std::cout << "0. Exit system" << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "Please enter your choice > ";
}

void addStudent(StudentManager & manager)
{
    Student stu;
    std::string id;
    std::string name;
    std::string school;
    std::string className;
    int age;
    double grade;
    std::cout << "Enter ID Name Age School Class Grade (separated by spaces): ";
    std::cin >> id >> name >> age >> school >> className >> grade;
    stu.setId(id);
    stu.setName(name);
    stu.setAge(age);
    stu.setSchool(school);
    stu.setClassName(className);
    stu.setGrade(grade);

    if (manager.addStudent(stu))
    {
        std::cout << "Student information added successfully!\n\n";
    }
    else
    {
        std::cerr << "Failed to add student information!\n\n";
    }
}

void queryStudentById(StudentManager& manager)
{
    std::string id;
    std::cout << "Enter the student ID to query: ";
    std::cin >> id;
    Student* find_stu = manager.findStudentById(id);
    if (find_stu)
    {
        find_stu->printInfo();
    }
    else 
    {
        std::cout << "Student not found!\n\n";
    }
}

void modifyStudentById(StudentManager& manager)
{
    std::string id;
    std::cout << "Enter the student ID to modify: ";
    std::cin >> id;
    bool result = manager.modifyStudent(id);
    if (result)
    {
        std::cout << "Modification successful!\n\n";
    }
    else
    {
        std::cout << "Student not found!\n\n";
    }
}

void deleteStudentById(StudentManager& manager)
{
    std::string id;
    std::cout << "Enter the student ID to delete: ";
    std::cin >> id;
    bool result = manager.deleteStudent(id);
    if (result)
    {
        std::cout << "Deletion successful!\n\n";
    }
    else
    {
        std::cout << "Student not found!\n\n";
    }
}

void modifyStudentGradeById(StudentManager& manager)
{
    std::string id;
    std::cout << "Enter the student ID to modify grade: ";
    std::cin >> id;
    bool result = manager.modifyGradeByStuId(id);
    if (result)
    {
        std::cout << "Student not found!\n\n";
    }
    else
    {
        std::cerr << "Failed to modify student grade!\n\n";
    }
}

void sortStudentsByGrade(StudentManager& manager)
{
    bool result = manager.sortStudentsByGrade();
    if (result)
    {
        std::cout << "Student grades sorted successfully!\n\n";
    }
    else
    {
        std::cout << "Failed to sort student grades!\n\n";
    }
}
