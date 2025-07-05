// student_manager.cpp

#include "student_manager.h"

// 构造函数
StudentManager::StudentManager()
{
    loadFromFile(data_file);
}

// 析构函数
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
	if (exists) return false; // 如果学号已存在，返回false
    students.push_back(stu);
    return true;
}

Student* StudentManager::findStudentById(const std::string& id)
{
    for (auto& stu : students)
    {
		if (stu.getId() == id) return &stu; // 返回指向找到的学生对象的指针
        
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
        std::cout << "请输入新的成绩: (原为" << student->getGrade() << ")" << std::endl;
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
	std::ofstream fout(data_file, appendMode ? std::ios::app : std::ios::out); // 使用appendMode参数来决定是否追加写入
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
	if (students.empty()) return false; // 如果学生列表为空，直接返回false
	// 使用冒泡排序算法对学生按成绩进行排序
    // 这段代码位于一个双重循环中，实现了冒泡排序算法，用于对students（学生对象的vector）按成绩进行排序。
    for (size_t i = 0; i < students.size() - 1; ++i)
    {
        for (size_t j = 0; j < students.size() - i - 1; ++j)
        {
            // ascending是一个布尔变量，表示排序方式：true为升序，false为降序。
            // students[j].getGrade()获取第j个学生的成绩。
            if ((ascending && students[j].getGrade() > students[j + 1].getGrade()) ||   // 如果是升序（ascending == true），当前一个学生成绩大于后一个学生成绩时，交换两者位置。
                (!ascending && students[j].getGrade() < students[j + 1].getGrade()))    // 如果是降序（ascending == false），当前一个学生成绩小于后一个学生成绩时，交换两者位置。
            {
                // std::swap用于交换vector中两个学生对象的位置。
                std::swap(students[j], students[j + 1]);
            }
        }
	}
    return true;
}
