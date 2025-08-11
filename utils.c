#include "students.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
			print_student(current);
            return current;
			
        }
        current = current->next;
    }
    return NULL;
}

/**
 * show_student_average - Shows student's average grade
 * @head: Pointer to student list
 * @name: Name to search for
 */
void show_student_average(Student *head, const char *name)
{
    Student *found = find_student(head, name);
    if (found == NULL) {
        printf("Student '%s' not found\n", name);
        return;
    }
  
    float sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += found->grades[i];
    }
    float average = sum / 5.0f;
    
    printf("Average Grade: %.2f\n", average);
    
}


/**
 * show_class_average - Calculates and displays class average
 * @head: Pointer to student list
 *
 * Description: Handles all calculations and output internally
 *              No return value needed
 */
void show_class_average(Student *head)
{
    if (head == NULL) {
        printf("No students in class\n");
        return;
    }

    Student *current = head;
    float total_sum = 0.0f;
    int student_count = 0;

    while (current != NULL) {
        float student_sum = 0.0f;
        for (int i = 0; i < 5; i++) {
            student_sum += current->grades[i];
        }
        total_sum += student_sum / 5.0f;
        student_count++;
        current = current->next;
    }

    float class_avg = total_sum / student_count;
    printf("Class average for %d students: %.2f\n", student_count, class_avg);

}