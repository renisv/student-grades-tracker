#include "students.h"
#include <stdlib.h>  
#include <string.h>  
#include <stdio.h>

Student* create_student(Student **head, const char* name, int id, const int grades[5]) 
{
    Student* new_student = malloc(sizeof(Student));

    if (new_student == NULL) 
        return NULL;
    

    if (name != NULL) 
    {
        strncpy(new_student->name, name, 49);
        new_student->name[49] = '\0';
    } 
    else 
        new_student->name[0] = '\0';
    
    new_student->id = id;

    for (int i = 0; i < 5; i++) 
        new_student->grades[i] = grades[i];

    new_student->next = *head;
	*head = new_student;

    return new_student;
}

void load_students_file(char* filename) 
{
    FILE* file = fopen(filename, "r");
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

void save_new_students(char* filename, Student* head) 
{
    
    FILE* file = fopen(filename, "a");
    if (!file) {
        perror("Error opening student file");
        return;
    }

    
    Student* current = head;
    while (current != NULL) {
    
        fprintf(file, "%s,%d,%d,%d,%d,%d,%d\n", 
                current->name,
                current->id,
                current->grades[0],
                current->grades[1],
                current->grades[2],
                current->grades[3],
                current->grades[4]);
        
        current = current->next;
    }

    fclose(file);
    printf("New students saved to %s\n", filename);
}

void print_all_students(Student *head)
{
	Student *ptr = head;

	if(ptr == NULL)
		printf("No students available");
	
	while(ptr != NULL)
	{
		print_student(ptr);	
		ptr = ptr->next;
	}

}


void print_student(Student *student)
{	
	printf("Student name: %s\n", student->name);
	printf("Student ID: %d\n", student->id);
	printf("Student grades: ");
	for (int i = 0; i < 5 ; i++)
		printf("%d ", student->grades[i]);
	printf("\n\n");
}