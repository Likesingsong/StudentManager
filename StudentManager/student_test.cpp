#include "student_test.h"
#include "student.h"
#include "student_manager.h"

void testStudent()
{
    // 创建学生对象
    Student student("李四", 20);
    student.setId("20250002");
    student.setSchool("第二中学");
    student.setClassName("高三二班");
    student.setGrade(88.0);
    // 打印学生信息
    student.printInfo();
    // 修改学生信息
    student.setGrade(90.0);
    std::cout << "修改后的学生信息：" << std::endl;
    student.printInfo();
}

void testAddStudent()
{
    // 创建学生对象: 张三
    Student student("张三", 18);
    student.setId("20250001");
    student.setSchool("第一中学");
    student.setClassName("高一一班");
    student.setGrade(85.0);


    // 创建学生对象: 李四
    Student student2("李四", 19);
    student2.setId("20250002");
    student2.setSchool("第二中学");
    student2.setClassName("高二二班");
    student2.setGrade(90.0);

    // 创建学生对象: 王五
    Student student3("王五", 21);
    student3.setId("20250003");
    student3.setSchool("第三中学");
    student3.setClassName("高三三班");
    student3.setGrade(95.0);

    // 使用StudentManager类添加学生信息
    StudentManager manager;
    bool res1 = manager.addStudent(student);
    bool res2 = manager.addStudent(student2);
    bool res3 = manager.addStudent(student3);
    if (!res1 || !res2 || !res3)
    {
        std::cerr << "添加学生信息失败！" << std::endl;
        return;
	}
    manager.printAllStudents(); // 显示所有学生信息
    // 添加学生信息
    std::cout << "添加学生信息成功！" << std::endl;
}

void testLoadStudents()
{
    const std::string DATA_FILE = "students.txt";
    StudentManager manager;
    bool result = manager.loadFromFile(DATA_FILE); // 加载学生信息
    if (!result)
    {
        std::cerr << "加载学生信息失败！" << std::endl;
        return;
    }
    manager.printAllStudents(); // 显示所有学生信息
    std::cout << "加载学生信息成功！" << std::endl;
}

void testSaveStudentToFile()
{
    StudentManager manager;
    // 创建学生对象
    Student student("张大力", 18);
    student.setId("20250003");
    student.setSchool("第一中学");
    student.setClassName("高一一班");
    student.setGrade(85.0);
    // 添加学生信息
    manager.addStudent(student);
    // 保存到文件
    if (manager.saveToFile(true))
    {
        std::cout << "学生信息保存成功！" << std::endl;
    }
    else
    {
        std::cerr << "学生信息保存失败！" << std::endl;
    }
}

void testFindStudentById()
{
    StudentManager manager;
    
    std::string id;
    std::cout << "请输入要查找的学生学号: ";
    std::cin >> id;
    Student* student = manager.findStudentById(id);
    if (student)
    {
        student->printInfo(); // 打印学生信息
    }
    else
    {
        std::cout << "未找到学号为 " << id << " 的学生信息。" << std::endl;
    }
}

void testModifyStudent()
{
    StudentManager manager;
    std::string id;
    std::cout << "请输入要修改的学生学号: ";
    std::cin >> id;
    bool result = manager.modifyStudent(id); // 修改学生信息
    if (result)
    {
        std::cout << "===== 修改后的信息 =====" << std::endl;
        Student* student = manager.findStudentById(id);
        if (student)
        {
            student->printInfo(); // 打印修改后的学生信息
        }
    }
    else
    {
        std::cerr << "学生信息修改失败！" << std::endl;
    }
}

void testDeleteStudent()
{
    StudentManager manager;
    std::string id;
    std::cout << "请输入要删除的学生学号: ";
    std::cin >> id;
    bool result = manager.deleteStudent(id); // 删除学生信息
    if (result)
    {
        std::cout << "学生信息删除成功！" << std::endl;
    }
    else
    {
        std::cerr << "学生信息删除失败！" << std::endl;
    }
}