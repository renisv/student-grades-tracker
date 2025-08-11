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
void print_student(const Student *student);
void print_all_students(Student *head);

float calculate_average(const Student* student);

int load_students_from_file(const char* filename, Student** head);
int export_students_to_file(const char* filename, const Student* head);

Student* find_student(Student *head, const char *name);
void show_student_average(Student *head, const char *name);
void show_class_average(Student *head);

#endif
