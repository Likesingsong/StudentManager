# 学生信息管理系统

本项目是一个基于 C++ 的学生信息管理系统，适合 C++ 初学者学习链表、类、文件操作等基础知识。系统支持学生信息的增删查改、成绩排序等功能。

---

## 功能简介

- 添加学生信息（学号、姓名、年龄、学校、班级、成绩）
- 按学号查询学生信息
- 修改学生信息
- 删除学生信息
- 显示所有学生信息
- 按学号修改学生成绩
- 按成绩排序学生信息（升序/降序）

---

## 快速开始

### 1. 环境准备

- 推荐操作系统：Windows
- 编译器：支持 C++11 或以上（如 MinGW、g++、Visual Studio）
- 构建工具：CMake

### 2. 编译与运行

#### 方法一：使用批处理脚本（推荐）

在项目根目录下，双击或在命令行运行：

```bat
build_and_run.bat
```

脚本会自动清理旧的 build 目录，重新编译并运行程序。

#### 方法二：手动编译

1. 进入 `StudentManager` 目录
2. 创建并进入 `build` 目录：

   ```sh
   mkdir build
   cd build
   ```

3. 运行 CMake 和 make：

   ```sh
   cmake -G "MinGW Makefiles" ..
   mingw32-make
   ```

4. 运行生成的可执行文件：

   ```sh
   StudentManager.exe
   ```

---

## 使用说明

- 程序启动后，按菜单提示输入对应数字选择功能。
- 学生数据默认保存在 `students.txt` 文件中，支持自动读写。
- 输入数据时请按提示格式输入，避免输入错误导致程序异常。

---

## 主要文件说明

- `src/main.cpp`：程序入口，菜单交互
- `include/student_manager.h`、`src/student_manager.cpp`：学生管理类，核心逻辑
- `include/student.h`、`src/student.cpp`：学生类，封装学生信息
- `include/data_structure.h`、`include/node.h`：双向链表模板实现
- `students.txt`：学生数据文件（自动生成）

---

## 常见问题

- **编译报错 undefined reference**：请确保所有模板类实现都在头文件中。
- **找不到 students.txt**：程序会自动创建，无需手动生成。
- **中文乱码**：请使用支持 UTF-8 的终端或编辑器。

---

## 进阶学习建议

- 阅读 `include/data_structure.h` 和 `include/node.h`，理解链表实现。
- 修改或扩展学生信息字段，体验面向对象设计。
- 尝试添加更多功能，如按姓名查找、导出成绩单等。

---

## 联系方式

如有问题或建议，欢迎 issue 或 PR。感谢您的使用与支持！
