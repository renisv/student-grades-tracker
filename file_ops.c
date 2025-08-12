#include "students.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int load_students_from_file(const char* filename, Student** head) {
    if (!filename || !head) return -1;
    
    FILE* file = fopen(filename, "r");
    if (!file) return -1;
    
    char line[256];
    int records = 0;
    Student *tail = NULL;  // Track the end of the list
    
    while (fgets(line, sizeof(line), file)) {  // Fixed this line - added closing parenthesis
        line[strcspn(line, "\n")] = '\0';
        if (!line[0]) continue;
        
        char name[50];
        int id, grades[5];
        if (sscanf(line, "%49[^,],%d,%d,%d,%d,%d,%d", 
                  name, &id, &grades[0], &grades[1], &grades[2], 
                  &grades[3], &grades[4]) == 7) {
            
            Student *new_student = malloc(sizeof(Student));
            if (!new_student) continue;
            
            strncpy(new_student->name, name, 49);
            new_student->name[49] = '\0';
            new_student->id = id;
            memcpy(new_student->grades, grades, sizeof(grades));
            new_student->next = NULL;
            
            if (!*head) {
                *head = new_student;
            } else {
                tail->next = new_student;
            }
            tail = new_student;
            records++;
        }
    }
    fclose(file);
    return records ? 0 : -2;
}

int export_students_to_file(const char* filename, const Student* head) {
    if (!filename) return -1;
    
    FILE* file = fopen(filename, "w");
    if (!file) return -1;
    
    int records = 0;
    for (const Student* current = head; current; current = current->next) {
        fprintf(file, "%s,%d,%d,%d,%d,%d,%d\n", 
                current->name, current->id,
                current->grades[0], current->grades[1],
                current->grades[2], current->grades[3],
                current->grades[4]);
        records++;
    }
    fclose(file);
    return records ? 0 : -1;
}