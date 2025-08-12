#include "students.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float calculate_student_average(const Student *student) {
    if (!student) return -1.0f;
    
    float sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += student->grades[i];
    }
    return sum / 5.0f;
}

int get_student_count(Student *head) {
    int count = 0;
    for (Student *current = head; current; current = current->next) {
        count++;
    }
    return count;
}

float calculate_class_average(Student *head) {
    int count = 0;
    float total = 0;
    
    for (Student *current = head; current; current = current->next) {
        float avg = calculate_student_average(current);
        if (avg >= 0) {
            total += avg;
            count++;
        }
    }
    return count ? total / count : -1.0f;
}

int* get_grade_distribution(Student *head) {
    int *results = calloc(3, sizeof(int));
    if (!results) return NULL;
    
    for (Student *current = head; current; current = current->next) {
        float avg = calculate_student_average(current);
        if (avg < 5.0f) results[0]++;
        else if (avg <= 8.0f) results[1]++;
        else results[2]++;
    }
    return results;
}

void show_class_statistics(Student *head) {
    printf("\nCLASS STATISTICS\n--------------------------------\n");
    int total = get_student_count(head);
    printf("Total students: %d\n", total);
    
    float class_avg = calculate_class_average(head);
    printf("Class average: %.2f\n", class_avg >= 0 ? class_avg : 0.0f);
    
    int *counts = get_grade_distribution(head);
    if (counts) {
        printf("Grade distribution:\n");
        printf("   - Low performing: %d\n   - Average: %d\n   - High performing: %d\n",
               counts[0], counts[1], counts[2]);
        free(counts);
    }
    printf("--------------------------------\n\n");
}

void bubble_sort_by_average(Student **head) {
    if (!head || !*head || !(*head)->next) return;
    
    int swapped;
    Student **h;
    do {
        swapped = 0;
        h = head;
        while ((*h)->next) {
            float avg1 = calculate_student_average(*h);
            float avg2 = calculate_student_average((*h)->next);
            
            if (avg1 > avg2) {
                Student *tmp = *h;
                *h = (*h)->next;
                tmp->next = (*h)->next;
                (*h)->next = tmp;
                swapped = 1;
            }
            h = &(*h)->next;
        }
    } while (swapped);
}