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

    return 0;
}