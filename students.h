#ifndef STUDENT_H
#define STUDENT_H

typedef struct Student
{
    char name[50];       // Student name
    int id;              // Unique student ID
    int grades[5];       // Array of 5 grades
    struct Student* next;// Pointer to next student in list
} Student;

Student* create_student(Student **head, const char* name, int id, const int grades[5]);
void load_students_file(char* filename);
void save_new_students(char* filename, Student* head);
float calculate_average(const Student* student);
void print_all_students(Student *head);
void print_student(Student *head);

#endif
