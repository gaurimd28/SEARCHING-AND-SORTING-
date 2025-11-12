# 🎓 Student Database Management System (C++ Project)

This project is a **menu-driven C++ console application** designed to manage student records efficiently using **dynamic memory allocation**, **sorting algorithms**, and **searching techniques**.  
It allows users to **add, display, sort, and search** student information while also performing **performance analysis** between **Linear Search** and **Binary Search**.

This project serves as an educational tool to understand **Data Structures**, **Algorithm efficiency**, and **manual memory management** in C++.

---

## 🧭 Project Overview

The **Student Database Management System** enables users to store and manage data for multiple students. Each student record includes:
- **Student ID**
- **Student Name**
- **CGPA**

The program uses **structures**, **pointers**, and **dynamic memory allocation (malloc, realloc, free)** to handle data.  
It supports various sorting and searching algorithms and displays their **relative performance** in execution time.

---

## 🚀 Key Features

✅ Add new student records dynamically (no fixed array size)  
✅ Display all existing student records in a clean format  
✅ Sort student data by:
   - **Name** (Bubble Sort)
   - **CGPA (Ascending/Descending)** (Selection Sort)  
✅ Search student by **ID** using:
   - **Linear Search** (unsorted data)
   - **Binary Search** (sorted data)  
✅ Measure and compare execution time of both searches  
✅ Demonstrates **manual memory handling** (`malloc`, `realloc`, `free`) in C++  
✅ Structured and user-friendly **menu-driven interface**

---

## 🧩 Data Structure Used

```cpp
struct Student {
    int id;
    char name[15];
    float cgpa;
};
