# **Student Grades Tracker**

## **1. Application Overview** 
**A simple menu-based application to manage student grades using linked lists**  
The **Student Grades Tracker** is an application designed to help instructors manage student records, including names, ID numbers, and grades. The program allows users to add, view, search, sort, save and delete student data efficiently.  
<img width="720" height="358" alt="diagram png" src="https://github.com/user-attachments/assets/b42e7519-8397-4a4d-b58a-c40531d2ab76" />


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


## **3. Technical implementation**

  
 ### Key Features
- **Linked List Storage**: Uses a singly linked list for O(1) insertions and dynamic sizing. Each node stores student data and a next pointer, avoiding fixed-size limitations while maintaining memory efficiency.

- **File Handling**: Automatically loads/saves to `students.txt` in CSV format. Robust error handling covers missing files and corrupt data, with human-readable Name,ID,Grade1-5 formatting.

- **Search**: Supports both ID (direct comparison) and name (`strcmp()` searches). Handles edge cases like empty lists and NULL pointers gracefully.

- **Sorting**: Optimized bubble sort organizes by average grade. Swaps node pointers instead of data, with early termination for efficiency on nearly-sorted lists.

- **Averages**: Computes individual averages and class statistics. Categorizes students into performance tiers (low/medium/high) using floating-point precision.
---
## **4. How to Use the Program**  
### **Main Menu Options**  
```
1. ADD STUDENT
2.  DELETE STUDENT
3. SEARCH STUDENT
4. PRINT STUDENT
5. SORT BY AVERAGE GRADE
6. EXIT
```


---



## **5. Compilation**  


```c

    Clone the repository    git clone https://github.com/renisv/student-grades-tracker.git
    Navigate to project     cd student-grades-tracker
    Compile                 gcc -o student_manager main.c students.c utils.c file_ops.c menu.c
    Run the program         ./student_manager

```



---




## **6. Developers**
 
- **[Renis Vukaj](https://github.com/renisv)**  
- **[Kevin Voka](https://github.com/kevin10v)**  
