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


	bubble_sort_by_average(&head);
	
	


    if (export_students_to_file("students.txt", head) != 0) {
        fprintf(stderr, "Failed to export students to file\n");
        return 1;
    }
    
	

    return 0;
}