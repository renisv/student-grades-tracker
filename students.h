#ifndef STUDENT_H
#define STUDENT_H
typedef struct Student
{
    char name[50];       // Student name
    int id;              // Unique student ID
    int grades[5];       // Array of 5 grades
    struct Student* next;// Pointer to next student in list
} Student;
Student* create_student(const char* name, int id, const int grades[5]);
void view_all_students();
float calculate_average(const Student* student);
void save_student_to_file(const Student* student);
#endif
