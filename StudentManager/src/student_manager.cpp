// student_manager.cpp

#include <algorithm>
#include "student_manager.h"

// Constructor
StudentManager::StudentManager()
{
    loadFromFile(data_file);
}

// Destructor
StudentManager::~StudentManager()
{
    saveToFile();
}

void StudentManager::setDataFile(const std::string& filename)
{
    data_file = filename;
}

bool StudentManager::addStudent(const Student& stu)
{
    bool exists = findStudentById(stu.getId()) != nullptr;  // Check if student ID already exists
    if (exists) return false;                               // Return false if student ID already exists
    students.push_back(stu);
    return true;
}

Student* StudentManager::findStudentById(const std::string& id)
{
Node<Student>* current = students.get_head();           // Get the head of the linked list
    while (current)
    {
        if (current->get_data()->getId() == id)         // Check if the current student's ID matches
        {
            return current->get_data();                 // Return the student object if found
        }
        current = current->get_next();                  // Move to the next node
    }
    return nullptr;                                     // Return nullptr if no student with the given ID is found
}

bool StudentManager::modifyStudent(const std::string& id)
{
    Student* student = findStudentById(id);

    if (student)
    {
        std::string newName;
        std::string newSchool;
        std::string newClassName;
        int newAge;
        double newGrade;
        std::cout << "Please enter new name: (current: " << student->getName() << ")" << std::endl;
        std::cin >> newName;
        std::cout << "Please enter new age: (current: " << student->getAge() << ")" << std::endl;
        std::cin >> newAge;
        std::cout << "Please enter new school: (current: " << student->getSchool() << ")" << std::endl;
        std::cin >> newSchool;
        std::cout << "Please enter new class: (current: " << student->getClassName() << ")" << std::endl;
        std::cin >> newClassName;
        std::cout << "Please enter new grade: (current: " << student->getGrade() << ")" << std::endl;
        std::cin >> newGrade;
        student->setName(newName);
        student->setAge(newAge);
        student->setSchool(newSchool);
        student->setClassName(newClassName);
        student->setGrade(newGrade);
        return true;
    }
    return false;
}

bool StudentManager::modifyGradeByStuId(const std::string& id)
{
    Student* student = findStudentById(id);

    if (student)
    {
        double newGrade;
        std::cout << "Please enter new grade: (current: " << student->getGrade() << ")" << std::endl;
        std::cin >> newGrade;
        student->setGrade(newGrade);
        return true;
    }
    return false;
}

bool StudentManager::deleteStudent(const std::string& id)
{
    Student* student = findStudentById(id);
    if (!student) return false;     // Return false if student not found
    students.remove(*student);      // Remove the student from the list
    return true;                    // Return true if deletion was successful
}

void StudentManager::printAllStudents()
{
    if (students.empty())
    {
        std::cout << "No students found." << std::endl;
        return;
    }
    std::cout << "List of all students:\n";
    std::cout << "------------------------\n";
    // Iterate through the linked list of students and print each student's information
    Node<Student>* current = students.get_head();
    while (current)
    {
        current->get_data()->printInfo();   // Call printInfo method of Student class to print student details
        std::cout << "------------------------\n";
        current = current->get_next();      // Move to the next node in the linked list
    }
    std::cout << "Total number of students: " << students.get_size() << std::endl; // Print the total number of students
    std::cout << "------------------------\n\n";
}

bool StudentManager::loadFromFile(const std::string& filename)
{
    std::ifstream fileCheck(filename);
    if (!fileCheck.is_open())
    {
        std::ofstream createFile(filename);
        createFile.close();
        setDataFile(filename);
    }
    std::ifstream fin(filename, std::ios::binary);
    if (!fin.is_open()) return false;
    students.clear();

    std::string id;
    std::string name;
    std::string school;
    std::string className;
    int age;
    double grade;
    while (fin >> id >> name >> age >> school >> className >> grade)
    {
        students.push_back(Student(id, name, age, school, className, grade));
    }

    fin.close();
    return true;
}

bool StudentManager::saveToFile(bool appendMode)
{
    std::ifstream fileCheck(data_file);
    if (!fileCheck.is_open())
    {
        return false;
    }
    std::ofstream fout(data_file, appendMode ? std::ios::app : std::ios::out); // Use appendMode to decide whether to append
    if (!fout.is_open()) return false;
    Node<Student>* current = students.get_head();
    if (current == nullptr) // Check if the list is empty
    {
        fout.close();
        return true;        // Return true even if no students are present
    }
    // Write each student's information to the file
    while (current)
    {
        fout << current->get_data()->getId() << " "
            << current->get_data()->getName() << " "
            << current->get_data()->getAge() << " "
            << current->get_data()->getSchool() << " "
            << current->get_data()->getClassName() << " "
            << current->get_data()->getGrade() << std::endl;
        current = current->get_next(); // Move to the next node
    }
    fout.close();
    return true;
}

bool StudentManager::sortStudentsByGrade(bool ascending)
{
    if (students.empty()) return false; // Return false if student list is empty
    
    bool swapped;                       // Flag to check if a swap was made in the current pass
    // Use bubble sort algorithm to sort students by grade
    // Repeat the sorting process until no swaps are made in a complete pass
    do
    {
        swapped = false;
        Node<Student>* current = students.get_head();
        while (current && current->get_next())
        {
            Node<Student>* nextNode = current->get_next();
            if ((ascending && current->get_data()->getGrade() > nextNode->get_data()->getGrade()) ||
                (!ascending && current->get_data()->getGrade() < nextNode->get_data()->getGrade()))
            {
                // Swap the data of the two nodes
                std::swap(*(current->get_data()), *(nextNode->get_data()));
                // Set the swapped flag to true
                swapped = true;
            }
            current = nextNode; // Move to the next node
        }
    } while (swapped); // Repeat until no swaps are made
    return true;
}
