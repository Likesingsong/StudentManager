# 学生信息管理系统

这是一个基于C++开发的学生信息管理系统，使用双向链表实现数据存储，支持文件持久化。该系统提供了完整的学生信息管理功能，适合C++初学者学习和实践。

## 功能特性

- 学生信息管理
  - 添加学生信息
  - 查询学生信息（按学号）
  - 修改学生信息
  - 删除学生信息
  - 显示所有学生信息
- 成绩管理
  - 修改学生成绩
  - 按成绩排序（支持升序和降序）
- 数据持久化
  - 自动保存数据到文件
  - 程序启动时自动加载数据

## 环境要求

- C++11或更高版本
- CMake 3.10或更高版本
- MinGW（Windows环境）或其他C++编译器

## 项目结构

```
StudentManager/
  ├── build_and_run.bat       # Windows环境下的快速构建运行脚本
  ├── CMakeLists.txt          # CMake配置文件
  ├── include/                # 头文件目录
  │   ├── data_structure.h    # 数据结构定义（双向链表）
  │   ├── node.h              # 链表节点定义
  │   ├── student.h           # 学生类定义
  │   ├── student_manager.h   # 学生管理类定义
  │   └── student_test.h      # 测试函数声明
  ├── src/                    # 源文件目录
  │   ├── main.cpp            # 主程序入口
  │   ├── student.cpp         # 学生类实现
  │   ├── student_manager.cpp # 学生管理类实现
  │   └── student_test.cpp    # 测试函数实现
  └── students.txt            # 学生数据存储文件
```

## 快速开始

### Windows环境

1. 确保已安装MinGW和CMake，并添加到系统环境变量
2. 克隆或下载本项目
3. 双击运行`build_and_run.bat`脚本
   - 脚本会自动创建build目录
   - 使用CMake生成Makefile
   - 编译项目
   - 运行程序

### 手动构建

```bash
# 创建并进入构建目录
mkdir build
cd build

# 生成Makefile
cmake -G "MinGW Makefiles" ..  # Windows环境
# 或
cmake ..  # Linux/Mac环境

# 编译
mingw32-make  # Windows环境
# 或
make  # Linux/Mac环境

# 运行
./StudentManager  # Linux/Mac环境
# 或
StudentManager.exe  # Windows环境
```

## 使用说明

程序运行后会显示主菜单，提供以下操作选项：

1. 添加学生信息
   - 按提示输入学号、姓名、年龄、学校、班级、成绩
2. 查询学生信息
   - 输入学号查询指定学生信息
3. 修改学生信息
   - 输入学号，然后可以修改该学生的所有信息
4. 删除学生信息
   - 输入学号删除指定学生
5. 显示所有学生
   - 显示系统中所有学生的完整信息
6. 修改学生成绩
   - 输入学号修改指定学生的成绩
7. 按成绩排序
   - 对所有学生按成绩进行排序（默认升序）
0. 退出系统

## 数据存储

- 学生数据存储在`students.txt`文件中
- 每次程序启动时自动加载数据
- 添加、修改、删除操作后自动保存数据
- 数据格式：学号 姓名 年龄 学校 班级 成绩

## 开发说明

### 核心类

1. `Student`类
   - 存储学生基本信息
   - 提供信息的获取和修改方法

2. `StudentManager`类
   - 管理学生信息的核心类
   - 实现增删改查等功能
   - 处理文件读写操作

3. `DoublyLinkedList`类
   - 模板类实现的双向链表
   - 提供基本的链表操作

### 扩展开发

如果要添加新功能，建议按以下步骤：

1. 在`student.h`中添加新的学生属性（如需要）
2. 在`student_manager.h`中声明新的管理方法
3. 在`student_manager.cpp`中实现新方法
4. 在`main.cpp`中添加对应的菜单项和处理函数

## 注意事项

1. 学号必须唯一，添加学生时会检查重复
2. 输入数据时请按照提示的格式输入
3. 成绩输入请使用数字（可以是小数）
4. 文件操作可能因权限问题失败，请确保程序对`students.txt`有读写权限

## 作者

[Gavin]

## 许可证

MIT License