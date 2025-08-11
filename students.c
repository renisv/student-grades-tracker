#include "students.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * create_student - Creates a new student and adds it to the linked list
 * @head: Pointer to the head of the student list
 * @name: Name of the student
 * @id: Unique student ID
 * @grades: Array of 5 grades
 *
 * Return: Pointer to the new student, or NULL on failure
 */
Student *create_student(Student **head, const char *name, int id, const int grades[5])
{
    Student *new_student = malloc(sizeof(Student));

    if (new_student == NULL)
        return (NULL);

    if (name != NULL)
    {
        strncpy(new_student->name, name, 49);
        new_student->name[49] = '\0';
    }
    else
    {
        new_student->name[0] = '\0';
    }

    new_student->id = id;

    for (int i = 0; i < 5; i++)
        new_student->grades[i] = grades[i];

    new_student->next = *head;
    *head = new_student;

    return (new_student);
}


/**
 * print_student - Prints student information
 * @student: Pointer to student to print (can be NULL)
 *
 * Description: Safe to call with NULL, prints nothing in that case
 */
void print_student(const Student *student)
{
    if (student == NULL) {
        return;
    }

    printf("\nStudent Details:\n");
    printf("Name: %s\n", student->name);
    printf("ID: %d\n", student->id);
    printf("Grades: ");
    
    for (int i = 0; i < 5; i++) {
        printf("%d", student->grades[i]);
        if (i < 4) printf(", ");
    }
    printf("\n");
}

/**
 * print_all_students - Prints all students in the linked list
 * @head: Pointer to the head of the student list
 *
 * Description: Uses the const-correct print_student function
 */
void print_all_students(Student *head)
{
    const Student *current = head;  // Use const pointer for iteration

    if (current == NULL)
    {
        printf("No students available\n");  // Added newline
        return;
    }

    printf("=== Student List ===\n");  // Added header for clarity
    
    while (current != NULL)
    {
        print_student(current);  // Uses the const version
        current = current->next;
    }
    
    printf("===================\n");  // Added footer
}