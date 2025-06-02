// StudentManager.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "student_manager.h"

void printStudentMenu();
void setOutputFormat();

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
        case 1:  // 添加
        {
            Student stu;
            std::string id, name, school, className;
            int age;
            double grade;
            std::cout << "输入学号 姓名 年龄 学校 班级 成绩（空格分隔）: ";
            std::cin >> id >> name >> age >> school >> className >> grade;
            stu.setId(id);
            stu.setName(name);
            stu.setAge(age);
            stu.setSchool(school);
            stu.setClassName(className);
            stu.setGrade(grade);

            manager.addStudent(stu);

            if (manager.saveToFile(true))
            {
                std::cout << "学生信息保存成功！" << std::endl;
            }
            else
            {
                std::cerr << "学生信息保存失败！" << std::endl;
            }
            setOutputFormat();
        }
            break;
        case 2:  // 查看
        {
            std::string id;
            std::cout << "输入要查询的学号: ";
            std::cin >> id;
            Student* find_stu = manager.findStudentById(id);
            if (find_stu) find_stu->printInfo();
            else std::cout << "未找到该学生！" << std::endl;
            setOutputFormat();
        }
            break;
        case 3:  // 修改
        {
            std::string id;
            std::cout << "输入要修改的学号: ";
            std::cin >> id;
            bool result = manager.modifyStudent(id);
            if (result)
            {
                std::cout << "修改成功！" << std::endl;
            }
            else
            {
                std::cout << "修改失败！" << std::endl;
            }
            setOutputFormat();
        }
            break;
        case 4:  // 删除
        {
            std::string id;
            std::cout << "输入要删除的学号: ";
            std::cin >> id;
            if (manager.deleteStudent(id))
            {
                std::cout << "删除成功！" << std::endl;
            }
            else {
                std::cout << "未找到该学生！" << std::endl;
            }
            setOutputFormat();
        }
            break;
		case 5: // 显示所有
            manager.printAllStudents();
            std::cout << std::endl;
            std::cout << std::endl;
            break;
        case 6: // 根据学号修改学生成绩
        {
            std::string id;
            std::cout << "输入要修改成绩的学生学号: ";
            std::cin >> id;
            if (manager.modifyGradeByStuId(id))
            {
                std::cout << "学生成绩修改成功！" << std::endl;
            }
            else
            {
                std::cerr << "学生成绩修改失败！" << std::endl;
			}
            setOutputFormat();
        }
            break;
        case 7: // 学生成绩排序
            if (manager.sortStudentsByGrade())
            {
                std::cout << "学生成绩排序成功！" << std::endl;
            }
            else
            {
                std::cout << "学生成绩排序失败！" << std::endl;
            }
            setOutputFormat();
            break;
        case 0:
            std::cout << "退出系统。" << std::endl;
            break;
        default:
            std::cout << "无效选择，请重新输入。" << std::endl;
			setOutputFormat();
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (choice != 0);

    return 0;
}

// 学生信息操作菜单函数
void printStudentMenu() 
{
    std::cout << "==============================" << std::endl;
    std::cout << " 学生信息管理系统菜单 " << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "1. 添加学生信息" << std::endl;
    std::cout << "2. 查看学生信息" << std::endl;
    std::cout << "3. 修改学生信息" << std::endl;
    std::cout << "4. 删除学生信息" << std::endl;
    std::cout << "5. 显示所有学生" << std::endl;
    std::cout << "6. 修改学生成绩" << std::endl;
    std::cout << "7. 学生成绩排序" << std::endl;
    std::cout << "0. 退出系统" << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "请输入您的选择 > ";
}

// 控制输出格式
void setOutputFormat() 
{
    std::cout << std::endl;
    std::cout << std::endl;
}
