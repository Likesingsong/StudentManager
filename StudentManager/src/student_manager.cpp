// student_manager.cpp

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
    bool exists = findStudentById(stu.getId()) != nullptr;
    if (exists) return false; // Return false if student ID already exists
    students.push_back(stu);
    return true;
}

Student* StudentManager::findStudentById(const std::string& id)
{
    for (auto& stu : students)
    {
        if (stu.getId() == id) return &stu; // Return pointer to found student object
        
    }
    return nullptr;
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
    for (auto it = students.begin(); it != students.end(); ++it)
    {
        if (it->getId() == id)
        {
            students.erase(it);
            return true;
        }
    }
    return false;
}

void StudentManager::printAllStudents() const
{
    for (const auto& stu : students)
    {
        stu.printInfo();
        std::cout << "------------------------\n\n";
    }
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
        students.emplace_back(id, name, age, school, className, grade);
    }

    fin.close();
    return true;
}

bool StudentManager::saveToFile(bool appendMode) const
{
    std::ifstream fileCheck(data_file);
    if (!fileCheck.is_open())
    {
        return false;
    }
    std::ofstream fout(data_file, appendMode ? std::ios::app : std::ios::out); // Use appendMode to decide whether to append
    if (!fout.is_open()) return false;
    for (const auto& stu : students)
    {
        fout << stu.getId() << " "
            << stu.getName() << " "
            << stu.getAge() << " "
            << stu.getSchool() << " "
            << stu.getClassName() << " "
            << stu.getGrade() << std::endl;
    }
    fout.close();
    return true;
}

bool StudentManager::sortStudentsByGrade(bool ascending)
{
    if (students.empty()) return false; // Return false if student list is empty
    // Use bubble sort algorithm to sort students by grade
    // This code is in a double loop, implementing bubble sort to sort the students vector by grade.
    for (size_t i = 0; i < students.size() - 1; ++i)
    {
        for (size_t j = 0; j < students.size() - i - 1; ++j)
        {
            // ascending is a boolean variable indicating sort order: true for ascending, false for descending.
            // students[j].getGrade() gets the grade of the j-th student.
            if ((ascending && students[j].getGrade() > students[j + 1].getGrade()) ||   // If ascending, swap if current grade is greater than next.
                (!ascending && students[j].getGrade() < students[j + 1].getGrade()))    // If descending, swap if current grade is less than next.
            {
                // std::swap is used to swap two student objects in the vector.
                std::swap(students[j], students[j + 1]);
            }
        }
    }
    return true;
}
