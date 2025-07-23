# PortfolioProject.md
# Student Grades Tracker - Project Proposal  

## **1. Application Overview**  
The **Student Grades Tracker** is an application designed to help instructors manage student records, including names, ID numbers, and grades. The program allows users to add, view, search, sort, and save student data efficiently.  

### **Purpose**  
- Track and manage student grades in a structured way.  
- Calculate average grades for performance analysis.  
- Store and retrieve student records from a file for persistence.  

## **2. Data Representation & Structure**  

### **Structs Used**  
1. **`GradeList`** – Stores a dynamic list of grades (as `float` or `int`).  
2. **`Student`** – Contains:  
   - `name` (string)  
   - `ID` (integer)  
   - `grades` (instance of `GradeList`)  
   - `average_grade` (float, calculated from grades)  

### **Data Structure**  
- A **dynamic array** (or **linked list**) of `Student` structs to store all student records.  
- Enables efficient addition, searching, and sorting.  

## **3. Main Features & Menu Options**  

The program will present a **menu-driven interface** with the following options:  

1. **Add a New Student**  
   - Input: Name, ID, and list of grades.  
   - Automatically calculates the average grade.  

2. **View All Students**  
   - Displays each student’s name, ID, and average grade.  

3. **Search for a Student by ID**  
   - Input: Student ID.  
   - Output: Student details (name, grades, average).  

4. **Sort Students**  
   - Options:  
     - By **name** (alphabetical order).  
     - By **average grade** (highest to lowest).  

5. **Save Records to File**  
   - Stores student data in a `.txt` or `.csv` file for future use.  

6. **Load Records from File**  
   - Retrieves previously saved student data.  

7. **Exit Program**  

## **4. Technical Implementation**  
- **File Handling**: Read/write student records using text file operations.  
- **Sorting Algorithms**: Implement **bubble sort** or **selection sort** for ranking students.  
- **Dynamic Memory**: Manage student records efficiently using resizable arrays or linked lists.  

## **5. Expected Outcome**  
A functional, user-friendly program that simplifies grade tracking for educators while demonstrating core C programming concepts (structs, file I/O, sorting, and dynamic memory).  
