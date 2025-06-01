#include "student_manager.h"

// 构造函数
StudentManager::StudentManager() {
    loadFromFile(data_file);
}

void StudentManager::setDataFile(const std::string& filename) {
    data_file = filename;
}

int StudentManager::addStudent(const Student& stu) {
    bool exists = findStudentById(stu.getId()) != nullptr;
    if (exists) {
        std::cout << "学号为 " << stu.getId() << " 的学生已存在，无法添加。" << std::endl;
        return false;
    }
    students.push_back(stu);
    return saveToFile();
}

Student* StudentManager::findStudentById(const std::string& id) {
    for (auto& stu : students) {
        if (stu.getId() == id) {
            return &stu;
        }
    }
    return nullptr;
}

bool StudentManager::modifyStudent(const std::string& id) {
    Student* student = findStudentById(id);

    if (student) {
        std::string newName;
        std::string newSchool;
        std::string newClassName;
        int newAge;
        double newGrade;
        std::cout << "请输入新的姓名: (原为" << student->getName() << ")" << std::endl;
        std::cin >> newName;
        std::cout << "请输入新的年龄: (原为" << student->getAge() << ")" << std::endl;
        std::cin >> newAge;
        std::cout << "请输入新的学校: (原为" << student->getSchool() << ")" << std::endl;
        std::cin >> newSchool;
        std::cout << "请输入新的班级: (原为" << student->getClassName() << ")" << std::endl;
        std::cin >> newClassName;
        std::cout << "请输入新的成绩: (原为" << student->getGrade() << ")" << std::endl;
        std::cin >> newGrade;
        student->setName(newName);
        student->setAge(newAge);
        student->setSchool(newSchool);
        student->setClassName(newClassName);
        student->setGrade(newGrade);
        if (saveToFile()) {
            return true;
        } else {
            return false;
        }
    } else {
        std::cout << "未找到学号为 " << id << " 的学生信息。" << std::endl;
        return false;
    }
}

bool StudentManager::deleteStudent(const std::string& id) {
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getId() == id) {
            students.erase(it);
            if (saveToFile()) {
                return true;
            }
            return false;
        }
    }
    return false;
}

void StudentManager::printAllStudents() const {
    for (const auto& stu : students) {
        stu.printInfo();
        std::cout << "------------------------" << std::endl;
    }
}

bool StudentManager::loadFromFile(const std::string& filename) {
    std::ifstream fileCheck(filename);
    if (!fileCheck.is_open()) {
        std::ofstream createFile(filename);
        createFile.close();
        setDataFile(filename);
    }
    std::ifstream fin(filename, std::ios::binary);
    if (!fin.is_open()) {
        return false;
    }
    students.clear();

    std::string id, name, school, className;
    int age;
    double grade;
    while (fin >> id >> name >> age >> school >> className >> grade) {
        students.emplace_back(id, name, age, school, className, grade);
    }

    fin.close();
    return true;
}

bool StudentManager::saveToFile(bool appendMode) const {
    std::ifstream fileCheck(data_file);
    if (!fileCheck.is_open()) {
        return false;
    }
    std::ofstream fout(data_file, appendMode ? std::ios::app : std::ios::out);
    if (!fout.is_open()) return false;
    for (const auto& stu : students) {
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