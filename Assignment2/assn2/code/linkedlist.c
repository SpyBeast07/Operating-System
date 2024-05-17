#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void make_list(struct ListStudents* list) {
    list->head = NULL;
}

void insert_stu(struct ListStudents* list, const struct Students* student) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    strncpy(newNode->data.name, student->name, sizeof(student->name));
    newNode->data.rollNumber = student->rollNumber;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        return;
    }
    else {
        struct Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void display(const struct ListStudents* list) {
    const struct Node* current = list->head;

    // Traverse the list and display each student
    while (current != NULL) {
        printf("Name: %s, Roll Number: %d\n", current->data.name, current->data.rollNumber);
        current = current->next;
    }
}

void search_stu(const struct ListStudents* list, int rollNumber) {
    const struct Node* current = list->head;

    while (current != NULL) {
        if (current->data.rollNumber == rollNumber) {
            break;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("Data not found.\n");
    }
    else {
        printf("\nName - %s and roll - %d\n", current->data.name, current->data.rollNumber);
    }
}

void delete_stu(struct ListStudents* list, int rollNumber) {
    struct Node* current = list->head;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current->data.rollNumber == rollNumber) {
            if (prev == NULL) {
                list->head = current->next;
            }
            else {
                prev->next = current->next;
            }

            free(current);
            return;
        }

        prev = current;
        current = current->next;
    }
    // if (current == NULL) {
    //     printf("Data not found.\n");
    // }
}