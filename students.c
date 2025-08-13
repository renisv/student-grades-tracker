#include "students.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
Student *create_student(Student **head, const char *name, int id, const int 
grades[5]) {
    Student *new_student = malloc(sizeof(Student));
    if (!new_student) return NULL;
    strncpy(new_student->name, name ? name : "", 49);
    new_student->name[49] = '\0';
    new_student->id = id;
    memcpy(new_student->grades, grades, sizeof(int) * 5);
    new_student->next = *head;
    *head = new_student;
    return new_student;
}
void print_student(const Student *student) {
    if (!student) return;
  
    printf("\nStudent Details:\nName: %s\nID: %d\nGrades: ", student->name, student->id);
    for (int i = 0; i < 5; i++) {
        printf("%d%s", student->grades[i], i < 4 ? ", " : "");
    }
    printf("\n");
}
void print_all_students(Student *head) {
    if (!head) {
        printf("No students available\n");
        return;
    }
  
    printf("=== Student List ===\n");
    for (const Student *current = head; current; current = current->next) {
        print_student(current);
    }
    printf("===================\n");
}
Student* search_by_name(Student *head, const char *name) {
    if (!name || !head) return NULL;
  
    for (Student *current = head; current; current = current->next) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
    }
    return NULL;
}
int search_by_id(Student **head, int id) {
    if (!head) return -1;
  
    int pos = 0;
    for (Student *current = *head; current; current = current->next, pos++) 
{
        if (current->id == id) return pos;
    }
    return -1;
}
int delete_student_by_id(Student **head, int id) {
    if (!head || !*head) return -1;
  
    Student *prev = NULL, *current = *head;
    while (current && current->id != id) {
        prev = current;
        current = current->next;
    }
  
    if (!current) return -1;
  
    if (prev) {
        prev->next = current->next;
    } else {
        *head = current->next;
    }
    free(current);
    return 0;
}