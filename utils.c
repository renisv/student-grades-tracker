#include "students.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




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


/**
 * Counts students in three grade average categories
 * @param head Pointer to head pointer of student list
 * @return Dynamically allocated array with counts:
 *         [0] = count with average <5
 *         [1] = count with 5<=average<=8 
 *         [2] = count with average>8
 *         Caller must free() the returned array
 */
int* gradeCount(Student **head)
{
    
    int countLow = 0, countMid = 0, countHigh = 0;
    
    int *results = malloc(3 * sizeof(int));
    if (!results) {
        perror("Memory allocation failed");
        return NULL;
    }
    
    Student *current = *head;
    while (current != NULL) {
        char *name = current->name;
        float avg = calculate_student_average(current, name);
        
        if (avg < 5.0f) {
            countLow++;
        } 
        else if (avg <= 8.0f) {
            countMid++;
        } 
        else {
            countHigh++;
        }
        
        current = current->next;
    }
    
    results[0] = countLow;
    results[1] = countMid;
    results[2] = countHigh;
    
    return results;
}


/**
 * show_class_statistics - Displays comprehensive class statistics
 * @head: Pointer to the head of the student list
 *
 * Shows:
 * 1. Total number of students
 * 2. Class average grade
 * 3. Distribution of students by average grade ranges
 */
void show_class_statistics(Student *head) {
    // 1. Total number of students
    int total = get_student_count(head);
    printf("\nCLASS STATISTICS\n");
    printf("--------------------------------\n");
    printf("Total students: %d\n", total);
    
    // 2. Class average
    float class_avg = calculate_class_average(head);
    if (class_avg >= 0) {
        printf("Class average: %.2f\n", class_avg);
    } else {
        printf("Class average: N/A (no students)\n");
    }
    
    // 3. Grade distribution
    int *counts = gradeCount(&head);
    if (counts) {
        printf("Grade distribution:\n");
        printf("   - Low performing: %d students\n", counts[0]);
        printf("   - Average perfoming: %d students\n", counts[1]);
        printf("   - High performing: %d students\n", counts[2]);
        free(counts);
    } else {
        printf("Grade distribution: Unable to calculate\n");
    }
    printf("--------------------------------\n\n");
}


