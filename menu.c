#include "students.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define FILENAME "students.txt"
#define MAX_INPUT 100
static void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
static void press_enter_to_continue() {
    printf("\nPress Enter to continue...");
    clear_input_buffer();
    getchar();
}
static void display_main_menu() {
    printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
    printf("1) Add Student\n");
    printf("2) Delete Student\n");
    printf("3) Search Student\n");
    printf("4) Print Students\n");
    printf("5) Sort by Average Grade\n");
    printf("0) Exit\n");
    printf("====================================\n");
    printf("Enter your choice (0-5): ");
}
static void add_student(Student** head) {
    char name[50];
    int id, grades[5];
  
    printf("\n=== ADD NEW STUDENT ===\n");
  
    printf("Enter student name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
  
    printf("Enter student ID: ");
    while (scanf("%d", &id) != 1) {
        printf("Invalid ID. Please enter a number: ");
        clear_input_buffer();
    }
    clear_input_buffer();
  
    printf("Enter 5 grades (space separated): ");
    while (scanf("%d %d %d %d %d", &grades[0], &grades[1], &grades[2], 
&grades[3], &grades[4]) != 5) {
        printf("Invalid grades. Please enter 5 numbers: ");
        clear_input_buffer();
    }
    clear_input_buffer();
  
    if (create_student(head, name, id, grades)) {
        printf("Student added successfully!\n");
    } else {
        printf("Failed to add student.\n");
    }
}
static void delete_student(Student** head) {
    int id;
  
    printf("\n=== DELETE STUDENT ===\n");
    printf("Enter student ID to delete: ");
    scanf("%d", &id);
    clear_input_buffer();
  
    if (delete_student_by_id(head, id) == 0) {
        printf("Student deleted successfully.\n");
    } else {
        printf("Student not found.\n");
    }
}
static void search_student(Student* head) {
    int choice;
    char input[MAX_INPUT];
  
    printf("\n=== SEARCH STUDENT ===\n");
    printf("1) By Name\n");
    printf("2) By ID\n");
    printf("Enter choice (1-2): ");
    scanf("%d", &choice);
    clear_input_buffer();
  
    if (choice == 1) {
        printf("Enter student name: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
  
        Student* found = search_by_name(head, input);
        if (found) {
            print_student(found);
            printf("Average: %.2f\n", calculate_student_average(found));
        } else {
            printf("Student not found.\n");
        }
    } else if (choice == 2) {
        printf("Enter student ID: ");
        int id;
        scanf("%d", &id);
        clear_input_buffer();
  
        int pos = search_by_id(&head, id);
        if (pos != -1) {
            Student* current = head;
            for (int i = 0; i < pos && current; i++) current = current->next;
            if (current) {
                print_student(current);
                printf("Average: %.2f\n", calculate_student_average(current));
            }
        } else {
            printf("Student not found.\n");
        }
    } else {
        printf("Invalid choice.\n");
    }
}
static void print_students(Student* head) {
    int choice;
  
    printf("\n=== PRINT STUDENTS ===\n");
    printf("1) Single Student\n");
    printf("2) All Students\n");
    printf("Enter choice (1-2): ");
    scanf("%d", &choice);
    clear_input_buffer();
  
    if (choice == 1) {
        search_student(head);
    } else if (choice == 2) {
        print_all_students(head);
    } else {
        printf("Invalid choice.\n");
    }
}
void run_student_management_system() {
    Student* head = NULL;
    int choice;
  
    
    printf("Loading student data from %s...\n", FILENAME);
    int load_result = load_students_from_file(FILENAME, &head);
  
    if (load_result == 0) {
        printf("Data loaded successfully!\n");
    } else if (load_result == -1) {
        printf("Warning: Could not open file. Starting with empty list.\n");
    } else if (load_result == -2) {
        printf("Warning: File exists but no valid records found. Starting with empty list.\n");
    }
  
   
    if (head) {
        printf("\n=== INITIAL CLASS STATISTICS ===\n");
        show_class_statistics(head);
    } else {
        printf("No student data available. You can add students using the menu.\n");
    }
  
    
    while (1) {
        display_main_menu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clear_input_buffer();
            continue;
        }
        clear_input_buffer();
  
        switch (choice) {
            case 1: add_student(&head); break;
            case 2: delete_student(&head); break;
            case 3: search_student(head); break;
            case 4: print_students(head); break;
            case 5:
                if (head) {
                    bubble_sort_by_average(&head);
                    printf("Students sorted by average grade.\n");
                } else {
                    printf("No students to sort.\n");
                }
                break;
            case 0:
                printf("\nSaving data to %s...\n", FILENAME);
                if (export_students_to_file(FILENAME, head) == 0) {
                    printf("Data saved successfully.\n");
                } else {
                    printf("Warning: There was a problem saving the data.\n");
                }
  
                // Free memory
                while (head) {
                    Student* temp = head;
                    head = head->next;
                    free(temp);
                }
                printf("Goodbye!\n");
                return;
            default:
                printf("Invalid choice. Please enter a number between 0-5.\n");
        }
        press_enter_to_continue();
    }
}
