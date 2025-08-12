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

/**
 * find_student - Finds a student by name
 * @head: Pointer to head of list
 * @name: Name to search for
 * Return: Pointer to student if found, NULL otherwise
 */
Student* find_student(Student *head, const char *name)
{
    if (name == NULL || head == NULL) {
        return NULL;
    }

    Student *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) 
		{
            return current;
        }
        current = current->next;
    }
    return NULL;
}


/**
 * search_by_id - Searches for a student by ID in the linked list
 * @head: Pointer to the head pointer of the student list
 * @id: Student ID to search for
 * @return: Position index (0-based) if found, -1 if not found
 */
int search_by_id(Student **head, int id) 
{
    int pos = 0;
    Student *current = *head;  // Better to use a local pointer
    
    while (current != NULL) {
        if (current->id == id) {
            return pos;
        }
        pos++;
        current = current->next;
    }
    return -1;
}


/**
 * delete_student_by_id - Deletes a student by their ID
 * @head: Pointer to the head pointer of the student list
 * @id: Student ID to delete
 * @return: 0 on success, -1 if student not found
 */
int delete_student_by_id(Student **head, int id) {
    if (head == NULL || *head == NULL) {
        return -1;
    }

    
    int position = search_by_id(head, id);
    if (position == -1) {
        return -1; 
    }

    Student *current = *head;
    Student *prev = NULL;
    int current_pos = 0;

    
    if (position == 0) {
        *head = current->next;
        free(current);
        return 0;
    }

    
    while (current != NULL && current_pos < position) {
        prev = current;
        current = current->next;
        current_pos++;
    }

    
    if (current != NULL) {
        prev->next = current->next;
        free(current);
        return 0;
    }

    return -1; 
}


void bubble_sort_by_average(Student **head) {
    if (!head || !*head || !(*head)->next) return;

    int swapped;
    Student *current;
    Student *last_sorted = NULL;

    do {
        swapped = 0;
        current = *head;

        while (current->next != last_sorted) {
            
            float avg1 = calculate_student_average(current, current->name);
            float avg2 = calculate_student_average(current->next, current->next->name);

            if (avg1 > avg2) 
			{
                
                Student *next = current->next;
                current->next = next->next;
                next->next = current;
                
                if (current == *head) {
                    *head = next;
                } else {
                    
                    Student *prev = *head;
                    while (prev->next != current) {
                        prev = prev->next;
                    }
                    prev->next = next;
                }
                
                swapped = 1;
                current = next; 
            }
            
            current = current->next;
        }
        last_sorted = current; 
    } while (swapped);
}