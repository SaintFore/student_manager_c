# 🎓 STUDENT MANAGER C

```text
   _____ __             __             __     __  ___                                  
  / ___// /___  _______/ /__  ____  / /_   /  |/  /___ _____  ____ _____ ____  _____ 
  \__ \/ __/ / / / __  / _ \/ __ \/ __/  / /|_/ / __ `/ __ \/ __ `/ __ `/ _ \/ ___/ 
 ___/ / /_/ /_/ / /_/ /  __/ / / / /_   / /  / / /_/ / / / / /_/ / /_/ /  __/ /     
/____/\__/\__,_/\__,_/\___/_/ /_/\__/  /_/  /_/\__,_/_/ /_/\__,_/\__, /\___/_/      
                                                                /____/              
   ______                                                                           
  / ____/                                                                           
 / /                                                                                
/ /___                                                                              
\____/                                                                              
                                                                                    
```

<div align="center">

[![C](https://img.shields.io/badge/Language-C-A8B9CC?style=for-the-badge&logo=c&logoColor=white)](https://en.cppreference.com/w/c)
[![GCC](https://img.shields.io/badge/Compiler-GCC-FFD11A?style=for-the-badge&logo=gnu)](https://gcc.gnu.org/)
[![Platform](https://img.shields.io/badge/Platform-Cross_Platform-blue?style=for-the-badge)](https://github.com/SaintFore/student_manager_c)
[![License](https://img.shields.io/badge/License-MIT-green.svg?style=for-the-badge)](LICENSE)

**"A robust, low-level student management core written in pure C."**
纯 C 打造，稳健且高效的学生管理系统内核。

[Building](#building) • [Usage](#usage) • [Features](#features) • [License](#license)

</div>

---

## ⚡ What is Student Manager C?

**Student Manager C** 是一个经典的教学级管理系统。它完全采用原生 C 语言开发，展示了结构体、链表（或数组管理）以及文件 I/O 的深度结合。它不仅是一个管理工具，更是学习 C 语言底层数据操作的绝佳范例。

**回归底层，掌握数据的本质。**

## 🚀 Features

- **📚 Robust Student Records**: 支持详尽的学生档案管理（增删改查）。
- **💾 File-Based Persistence**: 内置二进制或文本存档机制，确保数据永不丢失。
- **🗂️ Intelligent Sorting**: 集成了按学号或成绩排序的高效算法。
- **🖥️ Classic CLI Experience**: 提供极其直观、响应迅速的终端交互菜单。

## 📦 Building

### 1. 克隆仓库
```bash
git clone https://github.com/SaintFore/student_manager_c.git
cd student_manager_c
```

### 2. 编译源码
使用 GCC 进行极速编译：
```bash
gcc main.c student.c -o student_manager
```

## 💻 Usage

运行编译好的二进制文件：
```bash
./student_manager
```

在主菜单中，你可以通过数字键进行操作：
- `1`: 录入新面孔
- `5/6`: 存档与读档
- `7/8`: 快速排序

## 📄 License

Based on the MIT License. See [LICENSE](LICENSE) for details.

---

<div align="center">
Created with 🎓 by <a href="https://github.com/SaintFore">SaintFore</a>
</div>
