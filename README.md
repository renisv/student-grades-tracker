# **Student Grades Tracker**

## **1. Application Overview** 
**📝 A simple menu-based application to manage student grades using linked lists**  
The **Student Grades Tracker** is an application designed to help instructors manage student records, including names, ID numbers, and grades. The program allows users to add, view, search, sort, save and delete student data efficiently.  

### **🎯 Project Overview**  
This is a **C program** that helps teachers or administrators keep track of student grades. You can:  
✅ Add new students with their grades  
✅ View all student records  
✅ Search for specific students  
✅ Update grades when needed  
✅ Sort students by name, ID, or average score  
✅ Save all data to a file (grades won't be lost when program closes)  



### **Purpose**  
- Track and manage student grades in a structured way.  
- Calculate average grades for performance analysis.  
- Store and retrieve student records.  
---
---
## **2. Data Representation & Structure**  


### **Data Structure**  
- A **linked list** of `Student` structs to store all student records.  
- Enables efficient addition, searching,viewing and sorting.  
### **How Student Data is Stored**  
```c
struct Student {
    char name[50];         // Student name
    int id;                // Student ID 
    int grades[5];         // Array of 5 grades
    struct Student* next;  // Link to next student
};
```
- Uses **linked lists** (flexible size, no wasted memory)  
- Fixed **5 grades per student** (simple to manage)  
---
---
## **3. How to Use the Program**  

### **Main Menu Options**  
```
1. ADD STUDENT
2. VIEW ALL STUDENTS
3. SEARCH STUDENT
4. UPDATE GRADES
5. CALCULATE AVERAGE
6. SORT STUDENTS
7. SAVE TO FILE
8. LOAD FROM FILE
9. EXIT
```

---
---

## **4. Technical implementation**

  
 ### Key Features
- **Linked List Storage**: Students stored as nodes (flexible size, no wasted memory).

- **File Handling**: Auto-saves/loads data to students.txt (plain text format).

- **Search & Update**: Finds students by ID/name and edits grades.

- **Sorting**: Uses selection sort (by name, ID, or average grade).

- **Averages**: Calculates and displays each student’s mean score.

### How It Works
- **Adding Students**: New entries go to the end of the linked list.

- **Saving/Loading**: Reads/writes to a file to keep data after closing.

- **Sorting**: Rearranges nodes by comparing names, IDs, or grades.

- **Memory**: Uses malloc/free to manage dynamic data.

---
---
## **5. Expected Outcome**  
A functional, user-friendly program that simplifies grade tracking for educators while demonstrating core C programming concepts (structs, file I/O, sorting, and dynamic memory).

#### For Teachers:

✅ Add/view/edit grades easily.

✅ Sort students by performance.

✅ Data saved automatically.

#### For Developers:

✅ Demonstrates structs, pointers, file I/O, sorting.

✅ Simple but functional (no GUI).

✅  Easy to expand (e.g., add more subjects).

## 

---

---

## **6. Developers**
 
- **[Renis Vukaj](https://github.com/renisv)**  
- **[Kevin Voka](https://github.com/kevin10v)**  
