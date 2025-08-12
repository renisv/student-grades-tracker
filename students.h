#ifndef STUDENT_H
#define STUDENT_H

typedef struct Student 
{
    char name[50];
    int id;
    int grades[5];
    struct Student* next;
} Student;

Student* create_student(Student **head, const char* name, int id, const int grades[5]);
void print_student(const Student *student);
void print_all_students(Student *head);

int load_students_from_file(const char* filename, Student** head);
int export_students_to_file(const char* filename, const Student* head);

Student* search_by_name(Student *head, const char *name);
int search_by_id(Student **head, int id);
int delete_student_by_id(Student **head, int id);

int get_student_count(Student *head);
float calculate_student_average(const Student *student);
float calculate_class_average(Student *head);
int* get_grade_distribution(Student *head);
void show_class_statistics(Student *head);
void bubble_sort_by_average(Student **head);


#endif