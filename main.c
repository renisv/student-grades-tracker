#include "students.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    // 1. Create student
    int grades[5] = {8, 7, 9, 6, 8};
    Student* student = create_student("Anna Kowalski", 1002, grades);
  
    if (student == NULL) {
        printf("Failed to create student\n");
        return 1;
    }
    // 2. Display student info
    printf("\n=== STUDENT CREATED ===\n");
    printf("Name: %s\n", student->name);
    printf("ID: %d\n", student->id);
    printf("Grades: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", student->grades[i]);
    }
  
    // 3. Calculate and display average
    float avg = calculate_average(student);
    printf("\nAverage grade: %.1f\n", avg);