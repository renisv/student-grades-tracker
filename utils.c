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
            return current;
        }
        current = current->next;
    }
    return NULL;
}

/**
 * calculate_student_average - finds average grade for a student
 * @head: Pointer to student list
 * @name: Name of student to find
 *
 * Return: Average grade if found, -1.0 if not found
 * Description: Uses existing find_student function
 */
float calculate_student_average(Student *head, const char *name)
{
    
    Student *found = find_student(head, name);
    
    if (found == NULL) {
        return -1.0f;  
    }

    
    float sum = 0.0f;
    for (int i = 0; i < 5; i++) {
        sum += found->grades[i];
    }
    
    return sum / 5.0f;
}

/**
 * get_student_count - Counts the number of students in the list
 * @head: Pointer to the head of the student list
 *
 * Return: Number of students (0 if list is empty)
 */
int get_student_count(Student *head)
{
    int count = 0;
    Student *current = head;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    return count;
}

/**
 * calculate_class_average - Calculates average grade for entire class
 * @head: Pointer to student list
 *
 * Return: Class average, or -1.0 if no students
 * Description: Uses get_student_count() for student count
 */
float calculate_class_average(Student *head)
{
    int student_count = get_student_count(head);
    if (student_count == 0) {
        return -1.0f;  
    }

    Student *current = head;
    float total_sum = 0.0f;

    while (current != NULL) {
        float student_avg = calculate_student_average(head, current->name);
        if (student_avg >= 0.0f) {  
            total_sum += student_avg;
        }
        current = current->next;
    }

    return total_sum / student_count;
}



