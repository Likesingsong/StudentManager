#include "student_test.h"
#include "student.h"
#include "student_manager.h"

void testStudent()
{
    // ����ѧ������
    Student student("����", 20);
    student.setId("20250002");
    student.setSchool("�ڶ���ѧ");
    student.setClassName("��������");
    student.setGrade(88.0);
    // ��ӡѧ����Ϣ
    student.printInfo();
    // �޸�ѧ����Ϣ
    student.setGrade(90.0);
    std::cout << "�޸ĺ��ѧ����Ϣ��" << std::endl;
    student.printInfo();
}

void testAddStudent()
{
    // ����ѧ������: ����
    Student student("����", 18);
    student.setId("20250001");
    student.setSchool("��һ��ѧ");
    student.setClassName("��һһ��");
    student.setGrade(85.0);


    // ����ѧ������: ����
    Student student2("����", 19);
    student2.setId("20250002");
    student2.setSchool("�ڶ���ѧ");
    student2.setClassName("�߶�����");
    student2.setGrade(90.0);

    // ����ѧ������: ����
    Student student3("����", 21);
    student3.setId("20250003");
    student3.setSchool("������ѧ");
    student3.setClassName("��������");
    student3.setGrade(95.0);

    // ʹ��StudentManager�����ѧ����Ϣ
    StudentManager manager;
    bool res1 = manager.addStudent(student);
    bool res2 = manager.addStudent(student2);
    bool res3 = manager.addStudent(student3);
    if (!res1 || !res2 || !res3)
    {
        std::cerr << "���ѧ����Ϣʧ�ܣ�" << std::endl;
        return;
	}
    manager.printAllStudents(); // ��ʾ����ѧ����Ϣ
    // ���ѧ����Ϣ
    std::cout << "���ѧ����Ϣ�ɹ���" << std::endl;
}

void testLoadStudents()
{
    const std::string DATA_FILE = "students.txt";
    StudentManager manager;
    bool result = manager.loadFromFile(DATA_FILE); // ����ѧ����Ϣ
    if (!result)
    {
        std::cerr << "����ѧ����Ϣʧ�ܣ�" << std::endl;
        return;
    }
    manager.printAllStudents(); // ��ʾ����ѧ����Ϣ
    std::cout << "����ѧ����Ϣ�ɹ���" << std::endl;
}

void testSaveStudentToFile()
{
    StudentManager manager;
    // ����ѧ������
    Student student("�Ŵ���", 18);
    student.setId("20250003");
    student.setSchool("��һ��ѧ");
    student.setClassName("��һһ��");
    student.setGrade(85.0);
    // ���ѧ����Ϣ
    manager.addStudent(student);
    // ���浽�ļ�
    if (manager.saveToFile(true))
    {
        std::cout << "ѧ����Ϣ����ɹ���" << std::endl;
    }
    else
    {
        std::cerr << "ѧ����Ϣ����ʧ�ܣ�" << std::endl;
    }
}

void testFindStudentById()
{
    StudentManager manager;
    
    std::string id;
    std::cout << "������Ҫ���ҵ�ѧ��ѧ��: ";
    std::cin >> id;
    Student* student = manager.findStudentById(id);
    if (student)
    {
        student->printInfo(); // ��ӡѧ����Ϣ
    }
    else
    {
        std::cout << "δ�ҵ�ѧ��Ϊ " << id << " ��ѧ����Ϣ��" << std::endl;
    }
}

void testModifyStudent()
{
    StudentManager manager;
    std::string id;
    std::cout << "������Ҫ�޸ĵ�ѧ��ѧ��: ";
    std::cin >> id;
    bool result = manager.modifyStudent(id); // �޸�ѧ����Ϣ
    if (result)
    {
        std::cout << "===== �޸ĺ����Ϣ =====" << std::endl;
        Student* student = manager.findStudentById(id);
        if (student)
        {
            student->printInfo(); // ��ӡ�޸ĺ��ѧ����Ϣ
        }
    }
    else
    {
        std::cerr << "ѧ����Ϣ�޸�ʧ�ܣ�" << std::endl;
    }
}

void testDeleteStudent()
{
    StudentManager manager;
    std::string id;
    std::cout << "������Ҫɾ����ѧ��ѧ��: ";
    std::cin >> id;
    bool result = manager.deleteStudent(id); // ɾ��ѧ����Ϣ
    if (result)
    {
        std::cout << "ѧ����Ϣɾ���ɹ���" << std::endl;
    }
    else
    {
        std::cerr << "ѧ����Ϣɾ��ʧ�ܣ�" << std::endl;
    }
}