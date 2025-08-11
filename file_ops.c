#include "students.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * Loads student data from a file into the linked list
 * 
 * @param filename The name of the file to load from
 * @param head Pointer to the head of the student list
 * @return int 0 on success, -1 on file error, -2 on format error
 */
int load_students_from_file(const char* filename, Student** head)
{
    if (filename == NULL || head == NULL) {
        return -1; // Invalid parameters
    }

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    char line[256];
    int line_number = 0;
    int records_loaded = 0;

    while (fgets(line, sizeof(line), file)) {
        line_number++;
        
        // Remove newline character if present
        line[strcspn(line, "\n")] = '\0';
        
        // Skip empty lines
        if (strlen(line) == 0) {
            continue;
        }

        // Parse the line
        char name[50];
        int id;
        int grades[5];
        int parsed_items;

        // Try to parse the line
        parsed_items = sscanf(line, "%49[^,],%d,%d,%d,%d,%d,%d", 
                             name, &id, 
                             &grades[0], &grades[1], &grades[2], 
                             &grades[3], &grades[4]);

        if (parsed_items != 7) {
            fprintf(stderr, "Invalid format on line %d: %s\n", line_number, line);
            continue; // Skip this line but continue with next
        }

        // Create the student using your existing function
        Student* new_student = create_student(head, name, id, grades);
        if (new_student == NULL) {
            fprintf(stderr, "Failed to create student from line %d\n", line_number);
            continue;
        }

        records_loaded++;
    }

    fclose(file);
    
    if (records_loaded == 0) {
        fprintf(stderr, "Warning: No valid student records loaded from file\n");
    }

    return 0;
}

/**
 * Exports student data to a file
 * 
 * @param filename The name of the file to write to
 * @param head Pointer to the head of the student list
 * @return int 0 on success, -1 on error
 */
int export_students_to_file(const char* filename, const Student* head) {
    if (filename == NULL) {
        return -1;
    }

    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return -1;
    }

    const Student* current = head;
    int records_written = 0;

    while (current != NULL) {
        // Write student data in the same format as input
        fprintf(file, "%s,%d,%d,%d,%d,%d,%d\n", 
                current->name, 
                current->id,
                current->grades[0],
                current->grades[1],
                current->grades[2],
                current->grades[3],
                current->grades[4]);

        records_written++;
        current = current->next;
    }

    fclose(file);
    
    if (records_written == 0) {
        fprintf(stderr, "Warning: No student records were written to file\n");
    }

    return 0;
}