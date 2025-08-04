#include "students.h"
#include <stdlib.h>  
#include <string.h>  
#include <stdio.h>

Student* create_student(const char* name, int id, const int grades[5]) 
{
    Student* new_student = malloc(sizeof(Student));
    if (new_student == NULL) 
    {
        return NULL;
    }

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
    {
        new_student->grades[i] = grades[i];
    }

    new_student->next = NULL;
    return new_student;
}

void view_all_students() 
{
    FILE* file = fopen("students.txt", "r");
    if (!file) 
    {
        printf("Error opening students.txt\n");
        return;
    }

    printf("\n=== ALL STUDENTS ===\n");
    printf("NAME           ID    GRADES\n");
    printf("--------------------------------\n");

    char line[256];
    while (fgets(line, sizeof(line), file)) 
    {
        line[strcspn(line, "\n")] = '\0';
        printf("%s\n", line);
    }

    fclose(file);
    printf("--------------------------------\n");
}

float calculate_average(const Student* student) 
{
    if (student == NULL) 
    {
        return 0.0f;
    }

    int sum = 0;
    for (int i = 0; i < 5; i++) 
    {
        sum += student->grades[i];
    }

    return (float)sum / 5.0f;
}

void save_student_to_file(const Student* student)
 {
    if (student == NULL) 
    {
        printf("Error: Cannot save NULL student\n");
        return;
    }

    FILE* file = fopen("students.txt", "a");
    if (file == NULL) 
    {
        printf("Error opening students.txt\n");
        return;
    }

    
    fprintf(file, "%s,%d,%d,%d,%d,%d,%d\n",
            student->name,
            student->id,
            student->grades[0],
            student->grades[1],
            student->grades[2],
            student->grades[3],
            student->grades[4]);

    fclose(file);
    printf("Student saved to file successfully!\n");
}


