#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "student.h"

int main() {
    struct ListStudents studentList;
    make_list(&studentList);

    // Opening file
    FILE* file = fopen("../data/students.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening students.txt\n");
        exit(EXIT_FAILURE);
    }

    struct Students student;
    char str[50];
    int roll;

    // Reading file and assigning
    while (fgets(str, sizeof(str), file) != NULL) {
        sscanf(str, "%s", student.name);

        if (fgets(str, sizeof(str), file) != NULL) {
            sscanf(str, "%d", &student.rollNumber);
        }
        else {
            fprintf(stderr, "Error reading roll number\n");
            exit(EXIT_FAILURE);
        }

        insert_stu(&studentList, &student);
    }

    fclose(file);

    printf("Student List:\n");
    display(&studentList);

    int choice;    
    while(1) {
        printf("\n\nMenu:\n1. Search the detail using Roll no.\n2. Delete the detail using Roll no.\n3. Display the data\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the student's roll no. you want to search: ");
                int n;
                scanf("%d", &n);
                printf("\nStudent data found: ");
                search_stu(&studentList, n);
            break;

            case 2: 
                printf("Enter the student's roll no. whose details you want to delete: ");
                scanf("%d", &n);
                printf("\nDeleted student details: ");
                search_stu(&studentList, n);
                delete_stu(&studentList, n);
                printf("\nStudent List:\n");
                display(&studentList);
            break;

            case 3:
                printf("\nStudent details: \n");
                display(&studentList);
            break;

            case 4:
                return 0;
            break;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}