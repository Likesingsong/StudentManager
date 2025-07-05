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
		case 1:  // 添加
			addStudent(manager);
			break;
		case 2:  // 查看
			queryStudentById(manager);
			break;
		case 3:  // 修改
			modifyStudentById(manager);
			break;
		case 4:  // 删除
			deleteStudentById(manager);
			break;
		case 5: // 显示所有
			manager.printAllStudents();
			break;
		case 6: // 根据学号修改学生成绩
			modifyStudentGradeById(manager);
			break;
		case 7: // 学生成绩排序
			sortStudentsByGrade(manager);
			break;
		case 0:
			std::cout << "退出系统。" << std::endl;
			break;
		default:
			std::cout << "无效选择，请重新输入。\n\n";
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除输入缓冲区
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

void addStudent(StudentManager & manager)
{
	Student stu;
	std::string id;
	std::string name;
	std::string school;
	std::string className;
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

	if (manager.addStudent(stu))
	{
		std::cout << "学生信息添加成功！\n\n";
	}
	else
	{
		std::cerr << "学生信息添加失败！\n\n";
	}
}

void queryStudentById(StudentManager& manager)
{
	std::string id;
	std::cout << "输入要查询的学生学号: ";
	std::cin >> id;
	Student* find_stu = manager.findStudentById(id);
	if (find_stu)
	{
		find_stu->printInfo();
	}
	else 
	{
		std::cout << "未找到该学生！\n\n";
	}
}

void modifyStudentById(StudentManager& manager)
{
	std::string id;
	std::cout << "输入要修改的学生学号: ";
	std::cin >> id;
	bool result = manager.modifyStudent(id);
	if (result)
	{
		std::cout << "修改成功！\n\n";
	}
	else
	{
		std::cout << "未找到该学生！\n\n";
	}
}

void deleteStudentById(StudentManager& manager)
{
	std::string id;
	std::cout << "输入要删除的学生学号: ";
	std::cin >> id;
	bool result = manager.deleteStudent(id);
	if (result)
	{
		std::cout << "删除成功！\n\n";
	}
	else
	{
		std::cout << "未找到该学生！\n\n";
	}
}

void modifyStudentGradeById(StudentManager& manager)
{
	std::string id;
	std::cout << "输入要修改成绩的学生学号: ";
	std::cin >> id;
	bool result = manager.modifyGradeByStuId(id);
	if (result)
	{
		std::cout << "未找到该学生！\n\n";
	}
	else
	{
		std::cerr << "学生成绩修改失败！\n\n";
	}
}

void sortStudentsByGrade(StudentManager& manager)
{
	bool result = manager.sortStudentsByGrade();
	if (result)
	{
		std::cout << "学生成绩排序成功！\n\n";
	}
	else
	{
		std::cout << "学生成绩排序失败！\n\n";
	}
}
