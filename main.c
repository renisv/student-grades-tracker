#include "students.h"
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    Student* head = NULL;
    
    
    if (load_students_from_file("students.txt", &head) != 0) {
        fprintf(stderr, "Failed to load students from file\n");
        return 1;
    }
    
	// find_student(head,"Robert Clark");

	// show_student_average(head, "John Smith");

	float avg = calculate_student_average(head, "John Smith");
	printf("Average grade for the student is %.2f\n", avg);

	float clsavg = calculate_class_average(head);
	printf("Average grade for the class is %.2f\n", clsavg);


    if (export_students_to_file("students_updated.txt", head) != 0) {
        fprintf(stderr, "Failed to export students to file\n");
        return 1;
    }
    
	

    return 0;
}