#include "students.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int grades[5] = {8, 7, 9, 10, 8};
    Student *head;
    head = NULL;
    Student* s1 = create_student(&head, "sahasj", 1003, grades);
    Student* s2 = create_student(&head, "ewg435gr", 1004, grades);
    sync_students_with_file("students.txt", head);
    // print_all_students(head);
    // save_new_students("students.txt", head);
    load_students_file("students.txt");
 return 0;
}